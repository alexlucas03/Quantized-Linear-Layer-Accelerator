#include "Vverilator_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>
#include <vector>
#include <iomanip>

#define MAX_SIM_TIME 5000
vluint64_t sim_time = 0;

void toggle_clock(Vverilator_top* dut, VerilatedVcdC* tfp) {
    dut->clk = !dut->clk;
    dut->eval();
    tfp->dump(sim_time++);
}

void spi_write_byte(Vverilator_top* dut, VerilatedVcdC* tfp, uint8_t data, const std::string& label = "") {
    if (!label.empty()) std::cout << "[SPI] Sending: 0x" << std::hex << std::setw(2) << std::setfill('0') << (int)data << " (" << label << ")\n";
    dut->spi_cs_n = 0;
    for (int i = 7; i >= 0; --i) {
        dut->spi_mosi = (data >> i) & 1;
        toggle_clock(dut, tfp);
        dut->spi_sclk = 1;
        toggle_clock(dut, tfp);
        dut->spi_sclk = 0;
    }
    dut->spi_cs_n = 1;
    toggle_clock(dut, tfp);
}

void apply_reset(Vverilator_top* dut, VerilatedVcdC* tfp) {
    dut->rst = 1;
    for (int i = 0; i < 10; ++i)
        toggle_clock(dut, tfp);
    dut->rst = 0;
    std::cout << "[INFO] Reset complete\n";
}

// Runs a matrix test with given tokens and weights
void run_test(Vverilator_top* dut, VerilatedVcdC* tfp,
              const std::vector<uint8_t>& tokens,
              const std::vector<uint8_t>& weights,
              const std::string& test_name) {
    std::cout << "\n=== Running test: " << test_name << " ===\n";

    spi_write_byte(dut, tfp, 0x01, "Write Tokens");
    for (auto val : tokens)
        spi_write_byte(dut, tfp, val);

    spi_write_byte(dut, tfp, 0x02, "Write Weights");
    for (auto val : weights)
        spi_write_byte(dut, tfp, val);

    spi_write_byte(dut, tfp, 0x03, "Trigger Matmul");

    // Wait for matmul_done
    int timeout = 1000;
    bool done = false;
    while (timeout-- > 0) {
        toggle_clock(dut, tfp);
        if (dut->matmul_done) {
            std::cout << "✅ [PASS] Matrix multiplication complete at time " << sim_time << "\n";
            done = true;
            break;
        }
    }

    if (!done) {
        std::cerr << "❌ [FAIL] Timeout waiting for matmul_done\n";
    }
}

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    Vverilator_top* dut = new Vverilator_top;
    VerilatedVcdC* tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("dump.vcd");

    // Init inputs
    dut->clk = 0;
    dut->rst = 0;
    dut->spi_sclk = 0;
    dut->spi_mosi = 0;
    dut->spi_cs_n = 1;

    apply_reset(dut, tfp);

    // Test 1: basic vector
    run_test(dut, tfp, {10, 20, 30, 40}, {1, 2, 3, 4}, "Basic dot product");

    // Test 2: all zeros
    run_test(dut, tfp, {0, 0, 0, 0}, {0, 0, 0, 0}, "All zeros");

    // Test 3: alternating bits
    run_test(dut, tfp, {0xFF, 0x00, 0xAA, 0x55}, {0x01, 0x02, 0x03, 0x04}, "Pattern test");

    tfp->close();
    delete tfp;
    delete dut;
    return 0;
}