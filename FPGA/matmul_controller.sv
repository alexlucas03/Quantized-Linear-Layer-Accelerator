module matmul_controller #(
    parameter ADDR_WIDTH = 10,
    parameter DATA_WIDTH = 16,
    parameter OUT_SIZE   = 8,
    parameter VEC_LEN    = 8
)(
    input  logic clk,
    input  logic rst,
    input  logic start,
    output logic done,

    // Dot product engine
    output logic                   dp_start,
    input  logic                   dp_done,
    output logic [ADDR_WIDTH-1:0]  dp_weight_base_addr,
    input  logic signed [2*DATA_WIDTH-1:0] dp_result,

    // Result buffer (write-only)
    output logic                   result_wr_en,
    output logic [ADDR_WIDTH-1:0]  result_wr_addr,
    output logic [2*DATA_WIDTH-1:0] result_wr_data
);

    typedef enum logic [1:0] {
        IDLE,
        START_DOT,
        WAIT_DOT,
        WRITE_RESULT
    } state_t;

    state_t state;
    logic [ADDR_WIDTH-1:0] output_index;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state           <= IDLE;
            dp_start        <= 0;
            output_index    <= 0;
            result_wr_en    <= 0;
            result_wr_addr  <= 0;
            result_wr_data  <= 0;
            done            <= 0;
        end else begin
            dp_start     <= 0;
            result_wr_en <= 0;
            done         <= 0;

            case (state)
                IDLE: begin
                    if (start) begin
                        output_index <= 0;
                        state <= START_DOT;
                    end
                end

                START_DOT: begin
                    dp_start <= 1;
                    state <= WAIT_DOT;
                end

                WAIT_DOT: begin
                    if (dp_done) begin
                        result_wr_addr <= output_index;
                        result_wr_data <= dp_result;
                        result_wr_en   <= 1;
                        state <= WRITE_RESULT;
                    end
                end

                WRITE_RESULT: begin
                    if (output_index == OUT_SIZE - 1) begin
                        done <= 1;
                        state <= IDLE;
                    end else begin
                        output_index <= output_index + 1;
                        state <= START_DOT;
                    end
                end
            endcase
        end
    end

    // Compute weight base address for each output neuron
    assign dp_weight_base_addr = output_index * VEC_LEN;

endmodule
