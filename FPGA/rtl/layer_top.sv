module layer_top #(
    parameter ADDR_WIDTH   = 10,
    parameter DATA_WIDTH   = 16,
    parameter VECTOR_LEN   = 16,
    parameter NUM_NEURONS  = 16
)(
    input  logic                      clk,
    input  logic                      rst,
    input  logic                      start,

    // Token memory interface (host writes)
    input  logic                      token_wr_en,
    input  logic [ADDR_WIDTH-1:0]     token_wr_addr,
    input  logic [DATA_WIDTH-1:0]     token_wr_data,

    // Weight memory interface (host writes)
    input  logic                      weight_wr_en,
    input  logic [ADDR_WIDTH-1:0]     weight_wr_addr,
    input  logic [DATA_WIDTH-1:0]     weight_wr_data,

    // Result memory read interface (host reads)
    input  logic                      result_rd_en,
    input  logic [ADDR_WIDTH-1:0]     result_rd_addr,
    output logic [2*DATA_WIDTH-1:0]   result_rd_data,

    output logic busy,
    output logic done
);

    // Internal connections for layer_controller
    logic                            tok_rd_en;
    logic [ADDR_WIDTH-1:0]           tok_rd_addr;
    logic [DATA_WIDTH-1:0]           tok_rd_data;

    logic                            wgt_rd_en;
    logic [ADDR_WIDTH-1:0]           wgt_rd_addr;
    logic [DATA_WIDTH-1:0]           wgt_rd_data;

    logic                            res_wr_en;
    logic [ADDR_WIDTH-1:0]           res_wr_addr;
    logic signed [2*DATA_WIDTH-1:0]  res_wr_data;

    // Instantiate token BRAM
    bram_buffer #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) token_mem (
        .clk    (clk),
        .rst    (rst),
        .wr_en  (token_wr_en),
        .wr_addr(token_wr_addr),
        .wr_data(token_wr_data),
        .rd_en  (tok_rd_en),
        .rd_addr(tok_rd_addr),
        .rd_data(tok_rd_data)
    );

    // Instantiate weight BRAM
    bram_buffer #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) weight_mem (
        .clk    (clk),
        .rst    (rst),
        .wr_en  (weight_wr_en),
        .wr_addr(weight_wr_addr),
        .wr_data(weight_wr_data),
        .rd_en  (wgt_rd_en),
        .rd_addr(wgt_rd_addr),
        .rd_data(wgt_rd_data)
    );

    // Instantiate result BRAM
    bram_buffer #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(2*DATA_WIDTH)
    ) result_mem (
        .clk    (clk),
        .rst    (rst),
        .wr_en  (res_wr_en),
        .wr_addr(res_wr_addr),
        .wr_data(res_wr_data),
        .rd_en  (result_rd_en),
        .rd_addr(result_rd_addr),
        .rd_data(result_rd_data)
    );

    // Instantiate layer controller
    layer_controller #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH),
        .VECTOR_LEN(VECTOR_LEN),
        .NUM_NEURONS(NUM_NEURONS),
        .BRAM_LATENCY(),  // BRAM latency
        .MAC_LATENCY()     // MAC latency
    ) u_layer_ctrl (
        .clk           (clk),
        .rst           (rst),
        .start         (start),
        .busy          (busy),
        .token_rd_en     (tok_rd_en),
        .token_rd_addr   (tok_rd_addr),
        .token_rd_data   (tok_rd_data),
        .weight_rd_en     (wgt_rd_en),
        .weight_rd_addr   (wgt_rd_addr),
        .weight_rd_data   (wgt_rd_data),
        .result_wr_en     (res_wr_en),
        .result_wr_addr   (res_wr_addr),
        .result_wr_data   (res_wr_data),
        .done          (done)
    );

endmodule