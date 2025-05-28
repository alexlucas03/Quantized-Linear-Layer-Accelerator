// serial_top_tb.cpp
#include <verilated.h>
#include "Vserial_top.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <cstdint>

static vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

void tick(Vserial_top* dut, VerilatedVcdC* tfp) {
    // falling edge
    dut->clk = 0;
    dut->eval();
    if (tfp) tfp->dump(main_time++);
    // rising edge
    dut->clk = 1;
    dut->eval();
    if (tfp) tfp->dump(main_time++);
}

// Send one UART byte over rx line
void send_uart_byte(Vserial_top* dut, VerilatedVcdC* tfp, uint8_t byte) {
    const int BIT_TICKS = 434; // CLOCK_FREQ/BAUD = 50e6/115200 ≈ 434
    // start bit (low)
    dut->rx = 0;
    for (int i = 0; i < BIT_TICKS; ++i) tick(dut, tfp);
    // data bits LSB first
    for (int bit = 0; bit < 8; ++bit) {
        dut->rx = (byte >> bit) & 0x1;
        for (int i = 0; i < BIT_TICKS; ++i) tick(dut, tfp);
    }
    // stop bit (high)
    dut->rx = 1;
    for (int i = 0; i < BIT_TICKS; ++i) tick(dut, tfp);
    // inter-byte gap
    for (int i = 0; i < BIT_TICKS; ++i) tick(dut, tfp);
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vserial_top* dut = new Vserial_top;
    VerilatedVcdC* tfp = nullptr;
    Verilated::traceEverOn(true);
    tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("sim/vcd/serial_top_tb.vcd");

    // Initialize
    dut->clk = 0;
    dut->rst = 1;
    dut->rx = 1;
    dut->token_rd_en = 0;
    dut->token_rd_addr = 0;
    dut->weight_rd_en = 0;
    dut->weight_rd_addr = 0;
    tick(dut, tfp);
    dut->rst = 0;
    tick(dut, tfp);

    // Test 1: LOAD_TOKEN (0x01) at addr=5, data=0xABCD
    send_uart_byte(dut, tfp, 0x01);
    send_uart_byte(dut, tfp, 0x00);
    send_uart_byte(dut, tfp, 0x05);
    send_uart_byte(dut, tfp, 0x00);
    send_uart_byte(dut, tfp, 0x01);
    send_uart_byte(dut, tfp, 0xAB);
    send_uart_byte(dut, tfp, 0xCD);

    // Read from token RAM
    dut->token_rd_addr = 5;
    dut->token_rd_en = 1;
    tick(dut, tfp);
    tick(dut, tfp);
    dut->token_rd_en = 0;
    if (dut->token_rd_data != 0xABCD) {
        std::cerr << "[ERROR] Token mismatch: " << std::hex << dut->token_rd_data << std::endl;
        return 1;
    } else {
        std::cout << "[OK] Token RAM[5] = " << std::hex << dut->token_rd_data << std::endl;
    }

    // Test 2: LOAD_WEIGHT (0x02) at addr=7, data=0x1234
    send_uart_byte(dut, tfp, 0x02);
    send_uart_byte(dut, tfp, 0x00);
    send_uart_byte(dut, tfp, 0x07);
    send_uart_byte(dut, tfp, 0x00);
    send_uart_byte(dut, tfp, 0x01);
    send_uart_byte(dut, tfp, 0x12);
    send_uart_byte(dut, tfp, 0x34);

    // Read from weight RAM
    dut->weight_rd_addr = 7;
    dut->weight_rd_en = 1;
    tick(dut, tfp);
    tick(dut, tfp);
    dut->weight_rd_en = 0;
    if (dut->weight_rd_data != 0x1234) {
        std::cerr << "[ERROR] Weight mismatch: " << std::hex << dut->weight_rd_data << std::endl;
        return 1;
    } else {
        std::cout << "[OK] Weight RAM[7] = " << std::hex << dut->weight_rd_data << std::endl;
    }

    // Test 3: START_MATMUL (0x03)
    send_uart_byte(dut, tfp, 0x03);
    tick(dut, tfp);
    tick(dut, tfp);
    tick(dut, tfp);
    if (!dut->start_matmul) {
        std::cerr << "[ERROR] start_matmul not asserted" << std::endl;
        return 1;
    } else {
        std::cout << "[OK] start_matmul asserted" << std::endl;
    }

    tfp->close();
    delete dut;
    return 0;
}
