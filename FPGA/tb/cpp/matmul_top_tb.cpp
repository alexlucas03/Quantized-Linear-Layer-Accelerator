// matmul_top_tb.cpp
// Verilator C++ testbench for matmul_top

#include <verilated.h>
#include "Vmatmul_top.h"
#include "verilated_vcd_c.h"
#include <iostream>

// Simulation time
static vluint64_t main_time = 0;
// Called by $time in Verilog
double sc_time_stamp() { return main_time; }

// Clock tick helper
void tick(Vmatmul_top* dut, VerilatedVcdC* tfp) {
    // Falling edge
    dut->clk = 0;
    dut->eval();
    if (tfp) tfp->dump(main_time++);
    // Rising edge
    dut->clk = 1;
    dut->eval();
    if (tfp) tfp->dump(main_time++);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    // Instantiate DUT
    Vmatmul_top* dut = new Vmatmul_top;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 5);
    tfp->open("sim/vcd/matmul_top_tb.vcd");

    // Constants matching matmul_top parameters
    const int VEC_LEN = 8;
    const int OUT_SIZE = 8;

    // Initialize inputs
    dut->clk           = 0;
    dut->rst           = 1;
    dut->start         = 0;
    dut->token_wr_en   = 0;
    dut->weight_wr_en  = 0;
    dut->result_rd_en  = 0;

    // Apply reset for a few cycles
    for (int i = 0; i < 4; ++i) tick(dut, tfp);
    dut->rst = 0;
    tick(dut, tfp);

    int errors = 0;

    // Test 1: Identity weight matrix -> result should equal token vector
    std::cout << "Test 1: Identity matrix...\n";
    // Load token vector
    for (int i = 0; i < VEC_LEN; ++i) {
        dut->token_wr_en = 1;
        dut->token_wr_addr = i;
        dut->token_wr_data = (i + 1) * 10;
        tick(dut, tfp);
    }
    dut->token_wr_en = 0;
    tick(dut, tfp);

    // Load identity weights
    for (int row = 0; row < OUT_SIZE; ++row) {
        for (int col = 0; col < VEC_LEN; ++col) {
            dut->weight_wr_en  = 1;
            dut->weight_wr_addr= row * VEC_LEN + col;
            dut->weight_wr_data= (row == col) ? 1 : 0;
            tick(dut, tfp);
        }
    }
    dut->weight_wr_en = 0;
    tick(dut, tfp);

    // Start matmul
    dut->start = 1;
    tick(dut, tfp);
    dut->start = 0;
    tick(dut, tfp);

    // Wait for completion
    while (!dut->done) tick(dut, tfp);
    tick(dut, tfp);

    // Read and verify results
    for (int i = 0; i < OUT_SIZE; ++i) {
        dut->result_rd_en  = 1;
        dut->result_rd_addr= i;
        tick(dut, tfp);
        auto val = dut->result_rd_data;
        auto expect = (i + 1) * 10;
        if (val != expect) {
            std::cerr << "  [ERROR] idx=" << i << " got=" << val << " exp=" << expect << "\n";
            errors++;
        }
    }
    dut->result_rd_en = 0;
    tick(dut, tfp);

    // Test 2: Zero weight matrix -> result should be zero
    std::cout << "Test 2: Zero matrix...\n";
    // Reload zero weights
    for (int addr = 0; addr < OUT_SIZE * VEC_LEN; ++addr) {
        dut->weight_wr_en   = 1;
        dut->weight_wr_addr = addr;
        dut->weight_wr_data = 0;
        tick(dut, tfp);
    }
    dut->weight_wr_en = 0;
    tick(dut, tfp);

    // Start matmul again
    dut->start = 1;
    tick(dut, tfp);
    dut->start = 0;
    tick(dut, tfp);

    // Wait for completion
    while (!dut->done) tick(dut, tfp);
    tick(dut, tfp);

    // Read and verify zero results
    for (int i = 0; i < OUT_SIZE; ++i) {
        dut->result_rd_en   = 1;
        dut->result_rd_addr = i;
        tick(dut, tfp);
        auto val = dut->result_rd_data;
        if (val != 0) {
            std::cerr << "  [ERROR] idx=" << i << " got=" << val << " exp=0\n";
            errors++;
        }
    }
    dut->result_rd_en = 0;
    tick(dut, tfp);

    // Summary
    if (errors == 0) {
        std::cout << "ALL TESTS PASSED!\n";
    } else {
        std::cerr << errors << " ERRORS DETECTED!\n";
    }

    // Final tick and cleanup
    tick(dut, tfp);
    tfp->close();
    delete dut;
    delete tfp;

    return errors ? 1 : 0;
}