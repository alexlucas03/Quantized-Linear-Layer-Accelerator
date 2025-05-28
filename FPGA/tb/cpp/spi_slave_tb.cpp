#include "Vspi_slave.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <vector>
#include <iomanip>

vluint64_t sim_time = 0;

// Simulate a clock cycle on the `clk` signal
void tick(Vspi_slave* dut, VerilatedVcdC* tfp) {
    dut->clk = 0;
    dut->eval();
    tfp->dump(sim_time++);

    dut->clk = 1;
    dut->eval();
    tfp->dump(sim_time++);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);

    Vspi_slave* dut = new Vspi_slave;
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("spi_slave.vcd");

    // Initialize inputs
    dut->clk = 0;
    dut->rst = 1;
    dut->sclk = 0;
    dut->mosi = 0;
    dut->cs_n = 1;

    // Apply reset
    for (int i = 0; i < 5; ++i)
        tick(dut, tfp);
    dut->rst = 0;

    // Start SPI transmission
    dut->cs_n = 0;

    // Send byte 0x (10100101)
    uint8_t data = 0xA5;
    for (int i = 7; i >= 0; --i) {
        dut->mosi = (data >> i) & 1;

        // Simulate rising edge of SCLK
        dut->sclk = 0; tick(dut, tfp);
        dut->sclk = 1; tick(dut, tfp);
    }

    // Hold SCLK low and release CS
    dut->sclk = 0;
    dut->cs_n = 1;
    tick(dut, tfp);

    // Let output settle
    for (int i = 0; i < 5; ++i)
        tick(dut, tfp);

    // Check result
    if (dut->byte_ready)
        std::cout << "✅ Received: 0x" << std::hex << (int)dut->data_out << "\n";
    else
        std::cerr << "❌ Byte not received!\n";

    tfp->close();
    delete dut;
    delete tfp;
    return 0;
}
