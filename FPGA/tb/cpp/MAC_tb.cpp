// tb_mac_unit.cpp
#include <verilated.h>
#include "VMAC.h"
#include "verilated_vcd_c.h"
#include <cstdint>
#include <iostream>

// simulation time (in “time steps”)
static vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

// toggle clock, eval DUT, dump if TRACE enabled
void tick(VMAC* dut, VerilatedVcdC* tfp) {
    // falling edge
    dut->clk = 0;
    dut->eval();
    if (tfp) tfp->dump(main_time++);
    // rising edge
    dut->clk = 1;
    dut->eval();
    if (tfp) tfp->dump(main_time++);
}

// helpers for Q5.10 conversion
static constexpr int Q = 10;
int16_t to_fixed(double v)   { return int16_t(v * (1<<Q)); }
double  from_fixed(int32_t v){ return double(v) / (1<<Q); }

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    // instantiate DUT
    VMAC* dut = new VMAC;

    // set up VCD tracing
    VerilatedVcdC* tfp = nullptr;
    Verilated::traceEverOn(true);
    tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("sim/vcd/MAC_tb.vcd");

    // ---- Reset sequence ----
    dut->rst     = 1;
    dut->start   = 0;
    dut->a       = 0;
    dut->b       = 0;
    dut->acc_in  = 0;
    tick(dut, tfp);
    tick(dut, tfp);
    // release reset
    dut->rst = 0;
    tick(dut, tfp);

    // ---- Test cases ----
    struct Test { double a,b,acc; };
    Test tests[] = {
        {  1.5,  2.0, 0.0 },
        { -0.5,  4.0, 0.0 },
        {  1.0,  1.0, 3.5 }
    };
    const int N = sizeof(tests)/sizeof(Test);

    // feed them back‐to‐back
    for (int i = 0; i < N; i++) {
        dut->a      = to_fixed(tests[i].a);
        dut->b      = to_fixed(tests[i].b);
        dut->acc_in = int32_t(to_fixed(tests[i].acc));
        dut->start  = 1;
        tick(dut, tfp);
        dut->start  = 0;
        tick(dut, tfp);
    }

    // give it a few more cycles to flush the pipeline
    for (int i = 0; i < N + 5; i++) {
        if (dut->valid) {
            int32_t raw = dut->acc_out;
            double real = from_fixed(raw);
            std::cout 
              << "["<< main_time <<"] "
              << "acc_out=0x"<< std::hex<< raw << std::dec
              << " ("<< real <<")\n";
        }
        tick(dut, tfp);
    }

    // cleanup
    tfp->close();
    delete dut;
    delete tfp;
    return 0;
}