#include <verilated.h>
#include "Vlayer_top.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <iostream>

// Simulation time in time steps
static vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

// Clock toggle and eval
void tick(Vlayer_top* dut, VerilatedVcdC* tfp) {
    // Falling edge
    dut->clk = 0;
    dut->eval();
    if (tfp) tfp->dump(main_time++);
    // Rising edge
    dut->clk = 1;
    dut->eval();
    if (tfp) tfp->dump(main_time++);
}

// Convert double to Q5.10 fixed
static constexpr int Q = 10;
static int32_t to_fixed(double v) {
    return int32_t(v * (1 << Q));
}

const int VECTOR_LEN = 16;  // Length of input vector
const int NUM_NEURONS = 16;   // Number of neurons in the layer

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vlayer_top* dut = new Vlayer_top;

    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 2);
    tfp->open("sim/vcd/layer_top_tb.vcd");

    // Initialize inputs
    dut->clk = 0;
    dut->rst = 1;
    dut->start = 0;
    dut->token_wr_en = 0;
    dut->weight_wr_en = 0;
    dut->result_rd_en = 0;

    // Reset sequence
    for (int i = 0; i < 4; i++) tick(dut, tfp);
    dut->rst = 0;
    tick(dut, tfp);

    // Write token memory: set all tokens to addr
    for (int addr = 0; addr < VECTOR_LEN; addr++) {
        dut->token_wr_en   = 1;
        dut->token_wr_addr = addr;
        dut->token_wr_data = to_fixed(addr);
        tick(dut, tfp);
    }
    dut->token_wr_en = 0;
    tick(dut, tfp);

    // Write weight memory: set all weights to 1.0
    for (int addr = 0; addr < VECTOR_LEN * NUM_NEURONS; addr++) {
        dut->weight_wr_en   = 1;
        dut->weight_wr_addr = addr;
        dut->weight_wr_data = to_fixed(4.0);
        tick(dut, tfp);
    }
    dut->weight_wr_en = 0;
    tick(dut, tfp);

    // Start layer processing
    dut->start = 1;
    tick(dut, tfp);
    dut->start = 0;

    // Wait until done
    int max_ticks = 1000;  // or another reasonable upper bound
    int tick_count = 0;
    while (!dut->done && !Verilated::gotFinish() && tick_count < max_ticks) {
        tick(dut, tfp);
        tick_count++;
    }
    if (tick_count >= max_ticks) {
        std::cout << "ERROR: Simulation timed out waiting for done signal.\n";
    }

    // Read and verify results for each neuron
    bool all_ok = true;
    const int32_t expected = (VECTOR_LEN * (VECTOR_LEN - 1))/2 * to_fixed(4.0);  // VECTOR_LEN * 1.0
    for (int n = 0; n < NUM_NEURONS; n++) {
        dut->result_rd_en   = 1;
        dut->result_rd_addr = n;
        tick(dut, tfp);
        int32_t result = dut->result_rd_data;
        if (result != expected) {
            std::cout << "Mismatch at neuron " << n
                      << ": got " << result
                      << ", expected " << expected << "\n";
            all_ok = false;
        }
    }
    dut->result_rd_en = 0;
    tick(dut, tfp);

    if (all_ok) std::cout << "\n*** TEST PASSED: All neuron outputs match expected. ***\n";
    else        std::cout << "\n*** TEST FAILED: See mismatches above. ***\n";

    // Final ticks
    for (int i = 0; i < 2; i++) tick(dut, tfp);

    tfp->close();
    delete dut;
    delete tfp;
    return all_ok ? 0 : 1;
}