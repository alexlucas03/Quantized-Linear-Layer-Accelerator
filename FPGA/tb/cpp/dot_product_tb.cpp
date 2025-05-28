// dot_product_tb.cpp
// Verilator C++ testbench for the dot_product SystemVerilog module with MAC mocking

#include <verilated.h>
#include "Vdot_product.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <cstdint>

// Simulation time
static vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

// Memories for token and weight data
static std::vector<int16_t> token_mem;
static std::vector<int16_t> weight_mem;

// MAC mock scheduling
static bool pending_valid = false;
static int64_t pending_acc = 0;

// Tick function: toggles clock, evaluates DUT, dumps VCD, drives memory and mocks MAC
void tick(Vdot_product* dut, VerilatedVcdC* tfp) {
    // Drive pending MAC outputs at start of cycle
    dut->mac_valid   = pending_valid;
    dut->mac_acc_out = pending_acc;
    pending_valid = false;

    // Falling edge
    dut->clk = 0;
    dut->eval();
    if (tfp) tfp->dump(main_time);
    main_time++;

    // Provide memory outputs for reads
    dut->token_rd_data  = token_mem[dut->token_rd_addr];
    dut->weight_rd_data = weight_mem[dut->weight_rd_addr];

    // Rising edge
    dut->clk = 1;
    dut->eval();
    if (tfp) tfp->dump(main_time);
    main_time++;

    // After rising edge, if dot_product asserted mac_start, schedule MAC result next
    if (dut->mac_start) {
        // compute accumulator + A*B
        pending_acc = int64_t(dut->mac_acc_in) + int64_t(dut->mac_a) * int64_t(dut->mac_b);
        pending_valid = true;
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    // Instantiate DUT
    Vdot_product* dut = new Vdot_product;
    VerilatedVcdC* tfp = nullptr;

    // Prepare VCD output
    system("mkdir -p sim/vcd");
    dut->trace(tfp = new VerilatedVcdC, 99);
    tfp->open("sim/vcd/dot_product_tb.vcd");

    // Initialize memories
    const int MEM_SIZE = 1 << 10;
    token_mem.resize(MEM_SIZE);
    weight_mem.resize(MEM_SIZE);
    srand(time(NULL));

    // Reset sequence
    dut->rst   = 1;
    dut->start = 0;
    for (int i = 0; i < 5; i++) tick(dut, tfp);
    dut->rst = 0;

    const int VECTOR_LEN = 8;
    bool success = true;

    // Run multiple random tests
    for (int test = 0; test < 3; test++) {
        // Generate random token data
        for (int i = 0; i < VECTOR_LEN; i++) {
            token_mem[i] = rand() % 200 - 100;
        }
        // Choose random base address for weights
        int base = rand() % (MEM_SIZE - VECTOR_LEN);
        for (int i = 0; i < VECTOR_LEN; i++) {
            weight_mem[base + i] = rand() % 200 - 100;
        }
        dut->weight_rd_base_addr = base;

        // Start the dot product operation
        dut->start = 1;
        tick(dut, tfp);
        dut->start = 0;

        // Wait for completion or timeout
        while (!dut->done && main_time < 100000) tick(dut, tfp);

        // Compute reference result
        int64_t golden = 0;
        for (int i = 0; i < VECTOR_LEN; i++) {
            golden += int64_t(token_mem[i]) * int64_t(weight_mem[base + i]);
        }
        int64_t result = dut->result;

        // Check and report
        if (result != golden) {
            std::cerr << "Test " << test << " failed: expected " << golden << ", got " << result << std::endl;
            success = false;
        } else {
            std::cout << "Test " << test << " passed: result = " << result << std::endl;
        }
    }

    if (success) std::cout << "All tests passed!" << std::endl;

    // Cleanup and exit
    if (tfp) tfp->close();
    delete dut;
    return success ? 0 : 1;
}
