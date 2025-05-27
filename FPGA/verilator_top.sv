module verilator_top (
    input logic clk,
    input logic rst,
    input logic spi_sclk,
    input logic spi_mosi,
    input logic spi_cs_n,
    output logic matmul_done,
    output logic [31:0] result
);

    top_level dut (
        .clk(clk),
        .rst(rst),
        .spi_sclk(spi_sclk),
        .spi_mosi(spi_mosi),
        .spi_cs_n(spi_cs_n),
        .result(result), // Connect to result output
        .matmul_done(matmul_done)
    );

endmodule
