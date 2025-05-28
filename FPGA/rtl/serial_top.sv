// serial_top.sv
// Top-level wrapper connecting UART receiver, SPI command controller, and dual BRAM buffers
module serial_top #(
    parameter integer CLOCK_FREQ = 50_000_000,
    parameter integer BAUD       = 115200,
    parameter integer ADDR_WIDTH = 10,
    parameter integer DATA_WIDTH = 16
)(
    input  logic                       clk,
    input  logic                       rst,
    input  logic                       rx,

    // Token RAM read interface
    input  logic                       token_rd_en,
    input  logic [ADDR_WIDTH-1:0]      token_rd_addr,
    output logic [DATA_WIDTH-1:0]      token_rd_data,

    // Weight RAM read interface
    input  logic                       weight_rd_en,
    input  logic [ADDR_WIDTH-1:0]      weight_rd_addr,
    output logic [DATA_WIDTH-1:0]      weight_rd_data,

    // Start matrix-multiply pulse
    output logic                       start_matmul
);

    // Internal UART-to-SPI signals
    logic [7:0] spi_data;
    logic       spi_byte_ready;

    // Internal write signals for BRAMs
    logic                   token_wr_en;
    logic [ADDR_WIDTH-1:0]  token_wr_addr;
    logic [DATA_WIDTH-1:0]  token_wr_data;
    logic                   weight_wr_en;
    logic [ADDR_WIDTH-1:0]  weight_wr_addr;
    logic [DATA_WIDTH-1:0]  weight_wr_data;

    // UART receiver instance
    uart_rx #(
        .CLOCK_FREQ(CLOCK_FREQ),
        .BAUD(BAUD)
    ) uart_inst (
        .clk(clk),
        .rst(rst),
        .rx(rx),
        .data_out(spi_data),
        .byte_ready(spi_byte_ready)
    );

    // SPI command controller instance
    spi_command_controller #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) cmd_ctrl (
        .clk(clk),
        .rst(rst),
        .spi_data(spi_data),
        .spi_byte_ready(spi_byte_ready),
        .token_wr_en(token_wr_en),
        .token_wr_addr(token_wr_addr),
        .token_wr_data(token_wr_data),
        .weight_wr_en(weight_wr_en),
        .weight_wr_addr(weight_wr_addr),
        .weight_wr_data(weight_wr_data),
        .start_matmul(start_matmul)
    );

    // Token BRAM buffer
    bram_buffer #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) token_ram (
        .clk(clk),
        .rst(rst),
        .wr_en(token_wr_en),
        .wr_addr(token_wr_addr),
        .wr_data(token_wr_data),
        .rd_en(token_rd_en),
        .rd_addr(token_rd_addr),
        .rd_data(token_rd_data)
    );

    // Weight BRAM buffer
    bram_buffer #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) weight_ram (
        .clk(clk),
        .rst(rst),
        .wr_en(weight_wr_en),
        .wr_addr(weight_wr_addr),
        .wr_data(weight_wr_data),
        .rd_en(weight_rd_en),
        .rd_addr(weight_rd_addr),
        .rd_data(weight_rd_data)
    );

endmodule