module bram_buffer #(
    parameter ADDR_WIDTH = 10,  // 1024 words
    parameter DATA_WIDTH = 16
)(
    input  logic clk,
    input  logic rst,

    // Write port
    input  logic                  wr_en,
    input  logic [ADDR_WIDTH-1:0] wr_addr,
    input  logic [DATA_WIDTH-1:0] wr_data,

    // Read port
    input  logic                  rd_en,
    input  logic [ADDR_WIDTH-1:0] rd_addr,
    output logic [DATA_WIDTH-1:0] rd_data
);

    localparam DEPTH = 1 << ADDR_WIDTH;

    logic [DATA_WIDTH-1:0] mem [0:DEPTH-1];

    // Write logic
    always_ff @(posedge clk) begin
        if (wr_en)
            mem[wr_addr] <= wr_data;
    end

    // Read logic (synchronous read)
    always_ff @(posedge clk) begin
        if (rd_en)
            rd_data <= mem[rd_addr];
    end

endmodule
