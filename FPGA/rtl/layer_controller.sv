//------------------------------------------------------------------------------
// layer_controller.sv
// Fully-streaming layer inference with external accumulator and correct neuron count update
//------------------------------------------------------------------------------
module layer_controller #(
    parameter ADDR_WIDTH    = 10,
    parameter DATA_WIDTH    = 16,
    parameter VECTOR_LEN    = 16,
    parameter NUM_NEURONS   = 16,
    parameter BRAM_LATENCY  = 3,
    parameter MAC_LATENCY   = 4
)(
    input  logic                        clk,
    input  logic                        rst,
    input  logic                        start,
    output logic                        busy,
    output logic                        done,

    // Token BRAM read interface
    output logic                        token_rd_en,
    output logic [ADDR_WIDTH-1:0]       token_rd_addr,
    input  logic [DATA_WIDTH-1:0]       token_rd_data,

    // Weight BRAM read interface
    output logic                        weight_rd_en,
    output logic [ADDR_WIDTH-1:0]       weight_rd_addr,
    input  logic [DATA_WIDTH-1:0]       weight_rd_data,

    // Result BRAM write interface
    output logic                        result_wr_en,
    output logic [ADDR_WIDTH-1:0]       result_wr_addr,
    output logic signed [2*DATA_WIDTH-1:0] result_wr_data
);
    localparam VECTOR_AW     = $clog2(VECTOR_LEN);
    localparam NEURON_AW     = $clog2(NUM_NEURONS);
    localparam TOTAL_LATENCY = BRAM_LATENCY + MAC_LATENCY;

    // 'done' is asserted when not busy
    assign done = !busy;

    //------------------------------------------------------------------------------
    // Control signals
    logic                        running;
    logic [VECTOR_AW-1:0]        read_cnt;
    logic [NEURON_AW-1:0]        neuron_cnt;
    logic signed [2*DATA_WIDTH-1:0] sum_reg;

    //------------------------------------------------------------------------------
    // BRAM read enable/address and result write address
    assign token_rd_en    = running;
    assign token_rd_addr  = read_cnt;
    assign weight_rd_en   = running;
    assign weight_rd_addr = {neuron_cnt, read_cnt};
    assign result_wr_addr = neuron_cnt;

    //------------------------------------------------------------------------------
    // Running state, read counter, neuron counter, sum register
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            running    <= 1'b0;
            read_cnt   <= '0;
            neuron_cnt <= '0;
            busy       <= 1'b0;
            sum_reg    <= '0;
        end else if (start) begin
            running    <= 1'b1;
            read_cnt   <= '0;
            neuron_cnt <= '0;
            busy       <= 1'b1;
            sum_reg    <= '0;
        end else if (running) begin
            // Advance read counter
            if (read_cnt == VECTOR_LEN-1)
                read_cnt <= '0;
            else
                read_cnt <= read_cnt + 1;

            // On end-of-vector valid, bump neuron or stop
            if (eov_valid) begin
                if (neuron_cnt == NUM_NEURONS-1) begin
                    running <= 1'b0;
                    busy    <= 1'b0;
                end else begin
                    neuron_cnt <= neuron_cnt + 1;
                    sum_reg    <= '0;
                end
            end
        end
    end

    //------------------------------------------------------------------------------
    // Generate mac_start by delaying 'running' through BRAM latency
    logic [BRAM_LATENCY-1:0] start_pipe;
    logic                    mac_start;
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            start_pipe <= '0;
        else
            start_pipe <= {start_pipe[BRAM_LATENCY-2:0], running};
    end
    assign mac_start = start_pipe[BRAM_LATENCY-1];

    //------------------------------------------------------------------------------
    // Detect end-of-vector event when read_cnt wraps
    logic vector_end_event;
    always_comb begin
        vector_end_event = running && (read_cnt == VECTOR_LEN-1);
    end

    //------------------------------------------------------------------------------
    // Align vector_end_event through pipeline to match MAC.valid
    logic [TOTAL_LATENCY-1:0] eov_pipe;
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            eov_pipe <= '0;
        else
            eov_pipe <= {eov_pipe[TOTAL_LATENCY-2:0], vector_end_event};
    end
    logic eov_valid;
    assign eov_valid = eov_pipe[TOTAL_LATENCY-1] & mac_valid;

    //------------------------------------------------------------------------------
    // Pipe BRAM outputs directly into MAC inputs
    logic signed [DATA_WIDTH-1:0] token_pipe, weight_pipe;
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            token_pipe  <= '0;
            weight_pipe <= '0;
        end else begin
            token_pipe  <= token_rd_data;
            weight_pipe <= weight_rd_data;
        end
    end

    //------------------------------------------------------------------------------
    // Instantiate your MAC as a pure multiplier
    logic signed [2*DATA_WIDTH-1:0] mac_acc_out;
    logic                            mac_valid;
    MAC #(
        .WIDTH(DATA_WIDTH)
    ) mac_i (
        .clk    (clk),
        .rst    (rst),
        .start  (mac_start),
        .a      (token_pipe),
        .b      (weight_pipe),
        .acc_in (1'b0),  // always zero; we do external sum
        .acc_out(mac_acc_out),
        .valid  (mac_valid)
    );

    //------------------------------------------------------------------------------
    // External accumulation and result write
    always_ff @(posedge clk or posedge rst) begin
        if (rst)
            sum_reg <= '0;
        else if (mac_valid)
            sum_reg <= sum_reg + mac_acc_out;
    end

    assign result_wr_en   = eov_valid;
    assign result_wr_data = sum_reg + mac_acc_out;
endmodule