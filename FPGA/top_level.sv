// Top-level module for LLM Matrix Multiply Accelerator
// Integrates SPI, command parsing, BRAMs, matmul controller, and MAC engine

module top_level (
    input  logic clk,
    input  logic rst,

    // SPI interface from Raspberry Pi
    input  logic spi_sclk,
    input  logic spi_mosi,
    input  logic spi_cs_n,
    output logic [31:0] result,
    output logic matmul_done
);

    // SPI -> Command Controller
    logic [7:0] spi_data;
    logic      spi_byte_ready;

    // BRAM write ports (from command controller)
    logic token_wr_en, weight_wr_en;
    logic [9:0] token_wr_addr, weight_wr_addr;
    logic [15:0] token_wr_data, weight_wr_data;

    // BRAM read ports (for MAC streaming)
    logic token_rd_en, weight_rd_en;
    logic [9:0] token_rd_addr, weight_rd_addr;
    logic [15:0] token_rd_data, weight_rd_data;

    // Result writeback interface
    logic result_wr_en;
    logic [9:0] result_wr_addr;
    logic [31:0] result_wr_data;

    // Dot Product signals
    logic dp_start, dp_done;
    logic [31:0] dp_result;
    logic [9:0] dp_weight_base_addr;

    // MAC interface
    logic mac_start, mac_valid;
    logic signed [15:0] mac_a, mac_b;
    logic signed [31:0] mac_acc_in, mac_acc_out;

    // Trigger (from SPI or GPIO later)
    logic start_matmul;

    // SPI receiver
    spi_slave spi_slave_inst (
        .clk(clk), .rst(rst),
        .sclk(spi_sclk), .mosi(spi_mosi), .cs_n(spi_cs_n),
        .data_out(spi_data), .byte_ready(spi_byte_ready)
    );

    // Command parser
    spi_command_controller #(.ADDR_WIDTH(10), .DATA_WIDTH(16)) cmd_ctrl (
        .clk(clk), .rst(rst),
        .spi_data(spi_data), .spi_byte_ready(spi_byte_ready),
        .token_wr_en(token_wr_en), .token_wr_addr(token_wr_addr), .token_wr_data(token_wr_data),
        .weight_wr_en(weight_wr_en), .weight_wr_addr(weight_wr_addr), .weight_wr_data(weight_wr_data),
        .start_matmul(start_matmul)
    );

    // Token BRAM
    bram_buffer #(.ADDR_WIDTH(10), .DATA_WIDTH(16)) token_mem (
        .clk(clk), .rst(rst),
        .wr_en(token_wr_en), .wr_addr(token_wr_addr), .wr_data(token_wr_data),
        .rd_en(token_rd_en), .rd_addr(token_rd_addr), .rd_data(token_rd_data)
    );

    // Weight BRAM
    bram_buffer #(.ADDR_WIDTH(10), .DATA_WIDTH(16)) weight_mem (
        .clk(clk), .rst(rst),
        .wr_en(weight_wr_en), .wr_addr(weight_wr_addr), .wr_data(weight_wr_data),
        .rd_en(weight_rd_en), .rd_addr(weight_rd_addr), .rd_data(weight_rd_data)
    );

    // Result BRAM
    bram_buffer #(.ADDR_WIDTH(10), .DATA_WIDTH(32)) result_mem (
        .clk(clk), .rst(rst),
        .wr_en(result_wr_en), .wr_addr(result_wr_addr), .wr_data(result_wr_data),
        .rd_en(1'b0), .rd_addr('0), .rd_data(result)
    );

    // Dot Product Engine
    dot_product #(.ADDR_WIDTH(10), .DATA_WIDTH(16)) dp (
        .clk(clk), .rst(rst), .start(dp_start), .done(dp_done),
        .token_rd_en(token_rd_en), .token_rd_addr(token_rd_addr), .token_rd_data(token_rd_data),
        .weight_rd_base_addr(dp_weight_base_addr), .weight_rd_en(weight_rd_en), .weight_rd_addr(weight_rd_addr), .weight_rd_data(weight_rd_data),
        .mac_start(mac_start), .mac_a(mac_a), .mac_b(mac_b),
        .mac_acc_in(mac_acc_in), .mac_acc_out(mac_acc_out), .mac_valid(mac_valid),
        .result(dp_result)
    );

    // MAC Unit
    MAC #(.WIDTH(16)) mac (
        .clk(clk), .rst(rst), .start(mac_start),
        .a(mac_a), .b(mac_b), .acc_in(mac_acc_in),
        .acc_out(mac_acc_out), .valid(mac_valid)
    );

    // Matmul controller
    matmul_controller #(.ADDR_WIDTH(10), .DATA_WIDTH(16), .OUT_SIZE(8), .VEC_LEN(8)) mm_ctrl (
        .clk(clk), .rst(rst), .start(start_matmul), .done(matmul_done),
        .dp_start(dp_start), .dp_done(dp_done), .dp_weight_base_addr(dp_weight_base_addr), .dp_result(dp_result),
        .result_wr_en(result_wr_en), .result_wr_addr(result_wr_addr), .result_wr_data(result_wr_data)
    );

endmodule

