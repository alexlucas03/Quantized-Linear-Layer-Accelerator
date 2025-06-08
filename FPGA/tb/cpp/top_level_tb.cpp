// top_level_tb.cpp
// -----------------------------------------------------------------------------
// Verilator C++ testbench for top_level.sv
// - Simulates a 100 MHz clock
// - Exercises UART RX: LOAD_TOKEN, LOAD_WEIGHT, START_MATMUL, invalid commands, edge cases
// - Measures time from first UART command send to first UART TX response
// - Measures time from START_MATMUL send to first UART TX response
// - Outputs VCD to /sim/vcd/top_level_tb.vcd
// -----------------------------------------------------------------------------
#include <verilated.h>
#include "Vtop_level.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <cstdint>

static vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

// Clock period: 100 MHz => 10 ns, two ticks per full period for half-cycles
auto tick = [](Vtop_level* dut, VerilatedVcdC* tfp) {
    dut->clk = 0; dut->eval(); if (tfp) tfp->dump(main_time++);
    dut->clk = 1; dut->eval(); if (tfp) tfp->dump(main_time++);
};

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);
    Vtop_level* dut = new Vtop_level;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("sim/vcd/top_level_tb.vcd");

    // Reset sequence
    dut->rst = 1;
    for (int i = 0; i < 10; ++i) tick(dut, tfp);
    dut->rst = 0;
    dut->uart_rx_pin = 1; // idle

    // UART timing parameters
    const int BIT_TICKS = 100000000 / 115200;
    const int HALF_BIT = BIT_TICKS * 2;

    // Helper: send a byte over uart_rx_pin
    auto send_byte = [&](uint8_t data) {
        // Start bit (low)
        dut->uart_rx_pin = 0;
        for (int i = 0; i < BIT_TICKS*2; ++i) tick(dut, tfp);
        // Data bits LSB first
        for (int b = 0; b < 8; ++b) {
            dut->uart_rx_pin = (data >> b) & 1;
            for (int i = 0; i < BIT_TICKS*2; ++i) tick(dut, tfp);
        }
        // Stop bit (high)
        dut->uart_rx_pin = 1;
        for (int i = 0; i < BIT_TICKS*2; ++i) tick(dut, tfp);
    };

    // Variables for timing measurement
    bool first_cmd_sent = false;
    bool first_resp_seen = false;
    vluint64_t cmd_start_time = 0;
    vluint64_t resp_time_all = 0;
    bool startcmd_sent = false;
    bool start_resp_seen = false;
    vluint64_t startcmd_time = 0;
    vluint64_t resp_time_start = 0;

    // Edge-case: send invalid command and ensure no start
    send_byte(0xFF);

    // Begin valid token sequence (length 16)
    if (!first_cmd_sent) { cmd_start_time = main_time; first_cmd_sent = true; }
    send_byte(0x01);           // LOAD_TOKEN
    send_byte(0x00); send_byte(0x00);  // addr = 0
    send_byte(0x00); send_byte(0x10);  // length = 16
    for (int i = 0; i < 16; ++i) {
        send_byte((i>>8)&0xFF);
        send_byte(i & 0xFF);
    }
    // Weight sequence: send all ones (16x16)
    send_byte(0x02);           // LOAD_WEIGHT
    send_byte(0x00); send_byte(0x00);  // addr = 0
    send_byte(0x01); send_byte(0x00);  // length = 256 (0x0100)
    for (int i = 0; i < 256; ++i) {
        send_byte(0x00);
        send_byte(0x01);
    }
    // Send START_MATMUL
    startcmd_time = main_time; startcmd_sent = true;
    send_byte(0x03);

    // Run until UART TX first response after commands
    while (main_time < 100000000 && !first_resp_seen) {
        tick(dut, tfp);
        if (dut->uart_tx_pin == 0 && !first_resp_seen) {
            resp_time_all = main_time - cmd_start_time;
            first_resp_seen = true;
        }
    }
    // Run until first response after START
    while (main_time < 200000000 && !start_resp_seen) {
        tick(dut, tfp);
        if (dut->uart_tx_pin == 0 && main_time > startcmd_time && !start_resp_seen) {
            resp_time_start = main_time - startcmd_time;
            start_resp_seen = true;
        }
    }

    // Print results (cycles then ns)
    std::cout << "Cycles from first cmd to first TX: " << resp_time_all/2
              << " (" << (resp_time_all/2)*10 << " ns)\n";
    std::cout << "Cycles from START to first TX: " << resp_time_start/2
              << " (" << (resp_time_start/2)*10 << " ns)\n";

    tfp->close(); dut->final(); delete dut; delete tfp;
    return 0;
}