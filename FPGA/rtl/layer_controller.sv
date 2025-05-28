//------------------------------------------------------------------------------
// layer_controller_external_accum.sv
// Performs layer inference by streaming products from a pipelined MAC
// and summing them externally into a simple accumulator register.
//------------------------------------------------------------------------------
module layer_controller #(
    parameter ADDR_WIDTH    = 10,
    parameter DATA_WIDTH    = 16,
    parameter VECTOR_LEN    = 16,
    parameter NUM_NEURONS   = 8,
    parameter BRAM_LATENCY  = 3,
    parameter MAC_LATENCY   = 4
)(
    input  logic                        clk,
    input  logic                        rst,
    input  logic                        start,
    output logic                        busy,
    output logic                        done,

    // Token & Weight BRAM interfaces
    output logic                        token_rd_en,
    output logic [ADDR_WIDTH-1:0]       token_rd_addr,
    input  logic [DATA_WIDTH-1:0]       token_rd_data,
    output logic                        weight_rd_en,
    output logic [ADDR_WIDTH-1:0]       weight_rd_addr,
    input  logic [DATA_WIDTH-1:0]       weight_rd_data,

    // Result BRAM interface
    output logic                        result_wr_en,
    output logic [ADDR_WIDTH-1:0]       result_wr_addr,
    output logic signed [2*DATA_WIDTH-1:0] result_wr_data
);

    localparam VECTOR_AW    = $clog2(VECTOR_LEN);
    localparam NEURON_AW    = $clog2(NUM_NEURONS);
    localparam TOTAL_LATENCY = BRAM_LATENCY + MAC_LATENCY;
    assign done = (state==DONE);
    
    typedef enum logic [1:0] {IDLE, COMPUTE, WRITE, DONE} state_t;
    state_t state;

    logic [VECTOR_AW-1:0] vec_cnt;
    logic [NEURON_AW-1:0] neuron_cnt;
    logic [VECTOR_AW-1:0] rd_addr_reg;

    logic [BRAM_LATENCY-1:0] compute_pipe;
    logic [TOTAL_LATENCY-1:0] eov_pipe;
    logic mac_start, eov_valid;

    logic signed [DATA_WIDTH-1:0] token_pipe, weight_pipe;
    logic signed [2*DATA_WIDTH-1:0] mac_acc_out;
    logic mac_valid;

    // external sum
    logic signed [2*DATA_WIDTH-1:0] sum_reg;

    // Delay COMPUTE -> MAC.start
    always_ff @(posedge clk or posedge rst) begin
        if (rst) compute_pipe <= 0;
        else compute_pipe <= {compute_pipe[BRAM_LATENCY-2:0], state==COMPUTE};
    end
    assign mac_start = compute_pipe[BRAM_LATENCY-1];

    // Delay end-of-vector -> align with mac_valid
    always_ff @(posedge clk or posedge rst) begin
        if (rst) eov_pipe <= 0;
        else eov_pipe <= {eov_pipe[TOTAL_LATENCY-2:0], (state==COMPUTE && vec_cnt==VECTOR_LEN-1)};
    end
    assign eov_valid = eov_pipe[TOTAL_LATENCY-1] & mac_valid;

    // Pipe BRAM outputs to MAC inputs
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin token_pipe<=0; weight_pipe<=0; end
        else if (state==COMPUTE) begin token_pipe<=token_rd_data; weight_pipe<=weight_rd_data; end
    end

    // MAC as pure multiplier
    MAC #(.WIDTH(DATA_WIDTH)) mac_i (
        .clk(clk), .rst(rst), .start(mac_start),
        .a(token_pipe), .b(weight_pipe), .acc_in(0),
        .acc_out(mac_acc_out), .valid(mac_valid)
    );

    assign token_rd_addr = rd_addr_reg;
    assign weight_rd_addr = {neuron_cnt, rd_addr_reg};
    assign result_wr_addr = neuron_cnt;

    // Main FSM
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state<=IDLE; busy<=0; vec_cnt<=0; neuron_cnt<=0;
            rd_addr_reg<=0; token_rd_en<=0; weight_rd_en<=0; result_wr_en<=0;
            sum_reg<=0;
        end else begin
            case(state)
                IDLE: begin
                    busy<=0;
                    if (start) begin
                        busy<=1; state<=COMPUTE;
                        vec_cnt<=0; neuron_cnt<=0; rd_addr_reg<=0; sum_reg<=0;
                    end
                end

                COMPUTE: begin
                    token_rd_en<=1; weight_rd_en<=1;
                    rd_addr_reg<=vec_cnt;
                    vec_cnt<= (vec_cnt==VECTOR_LEN-1)?0:vec_cnt+1;

                    if (mac_valid) begin
                        if (eov_pipe[TOTAL_LATENCY-1]) begin
                            result_wr_en <= 1;
                            result_wr_data <= sum_reg + mac_acc_out;
                            sum_reg <= 0;
                            state <= WRITE;
                        end else begin
                            sum_reg <= sum_reg + mac_acc_out;
                        end
                    end
                end

                WRITE: begin
                    token_rd_en<=0; weight_rd_en<=0; result_wr_en<=0;
                    if (neuron_cnt==NUM_NEURONS-1)
                        state<=DONE;
                    else begin
                        neuron_cnt<=neuron_cnt+1;
                        state<=COMPUTE;
                        vec_cnt<=0; rd_addr_reg<=0; sum_reg<=0;
                    end
                end

                DONE: begin
                    busy<=0;
                    if (!start) state<=IDLE;
                end
            endcase
        end
    end
endmodule