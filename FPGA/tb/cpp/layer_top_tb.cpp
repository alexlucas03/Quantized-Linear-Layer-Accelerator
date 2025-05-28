#include <verilated.h>
#include "Vlayer_top.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

static vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

void tick(Vlayer_top* dut, VerilatedVcdC* tfp) {
    dut->clk = 0;
    dut->eval();
    if (tfp) tfp->dump(main_time++);
    dut->clk = 1;
    dut->eval();
    if (tfp) tfp->dump(main_time++);
}

std::vector<int16_t> read_values_file(const std::string& filename) {
    std::vector<int16_t> values;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line[0] != '#') {
            values.push_back(static_cast<int16_t>(std::stoi(line)));
        }
    }
    return values;
}

std::vector<int32_t> read_output_file(const std::string& filename) {
    std::vector<int32_t> values;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line[0] != '#') {
            values.push_back(static_cast<int32_t>(std::stol(line)));
        }
    }
    return values;
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vlayer_top* dut = new Vlayer_top;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 2);
    tfp->open("sim/vcd/layer_top_tb.vcd");

    auto tokens = read_values_file("token_vals.txt");
    auto weights = read_values_file("weight_vals.txt");
    auto expected_outputs = read_output_file("cpu_output.txt");

    int VECTOR_LEN = tokens.size();
    int NUM_NEURONS = weights.size() / VECTOR_LEN;

    dut->clk = 0;
    dut->rst = 1;
    dut->start = 0;
    dut->token_wr_en = 0;
    dut->weight_wr_en = 0;
    dut->result_rd_en = 0;

    for (int i = 0; i < 4; i++) tick(dut, tfp);
    dut->rst = 0;
    tick(dut, tfp);

    for (int addr = 0; addr < VECTOR_LEN; addr++) {
        dut->token_wr_en   = 1;
        dut->token_wr_addr = addr;
        dut->token_wr_data = tokens[addr];
        tick(dut, tfp);
    }
    dut->token_wr_en = 0;
    tick(dut, tfp);

    for (int addr = 0; addr < VECTOR_LEN * NUM_NEURONS; addr++) {
        dut->weight_wr_en   = 1;
        dut->weight_wr_addr = addr;
        dut->weight_wr_data = weights[addr];
        tick(dut, tfp);
    }
    dut->weight_wr_en = 0;
    tick(dut, tfp);

    dut->start = 1;
    tick(dut, tfp);
    dut->start = 0;

    int tick_count = 0;
    const int max_ticks = 50000;
    vluint64_t start_tick = main_time;
    while (!dut->done && tick_count < max_ticks) {
        tick(dut, tfp);
        tick_count++;
    }
    vluint64_t end_tick = main_time;
    std::cout << "Simulation ticks: " << (end_tick - start_tick) << "\\n";

    if (tick_count >= max_ticks) {
        std::cout << "ERROR: Simulation timed out.\\n";
    }

    bool all_ok = true;
    for (int n = 0; n < NUM_NEURONS; n++) {
        dut->result_rd_en   = 1;
        dut->result_rd_addr = n;
        tick(dut, tfp);
        int32_t result = dut->result_rd_data;
        if (result != expected_outputs[n]) {
            std::cout << "Mismatch at neuron " << n
                      << ": got " << result
                      << ", expected " << expected_outputs[n] << "\\n";
            all_ok = false;
        }
    }
    dut->result_rd_en = 0;
    tick(dut, tfp);

    if (all_ok)
        std::cout << "\\n*** TEST PASSED: All outputs match expected. ***\\n";
    else
        std::cout << "\\n*** TEST FAILED: Mismatches found. ***\\n";

    for (int i = 0; i < 2; i++) tick(dut, tfp);
    tfp->close();
    delete dut;
    delete tfp;
    return all_ok ? 0 : 1;
}
