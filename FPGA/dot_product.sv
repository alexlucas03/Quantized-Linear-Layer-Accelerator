module dot_product #(
    parameter ADDR_WIDTH = 10,
    parameter DATA_WIDTH = 16
)(
    input  logic clk,
    input  logic rst,
    input  logic start,  // trigger MAC process
    output logic [2*DATA_WIDTH-1:0] result, // output result of dot product
    output logic done,   // pulse high when one dot product is done

    // Token memory interface
    output logic                   token_rd_en,
    output logic [ADDR_WIDTH-1:0] token_rd_addr,
    input  logic [DATA_WIDTH-1:0] token_rd_data,

    // Weight memory interface
    output logic                   weight_rd_en,
    output logic [ADDR_WIDTH-1:0] weight_rd_addr,
    input  logic [DATA_WIDTH-1:0] weight_rd_data,
    input logic [ADDR_WIDTH-1:0] weight_rd_base_addr, // CORRECT

    // MAC unit interface
    output logic                        mac_start,
    output logic signed [DATA_WIDTH-1:0] mac_a,
    output logic signed [DATA_WIDTH-1:0] mac_b,
    output logic signed [2*DATA_WIDTH-1:0] mac_acc_in,
    input  logic signed [2*DATA_WIDTH-1:0] mac_acc_out,
    input  logic                         mac_valid
);

    typedef enum logic [1:0] {
        IDLE,
        READ,
        FEED_MAC,
        WAIT_MAC
    } state_t;

    state_t state;

    logic signed [2*DATA_WIDTH-1:0] accumulator;
    logic [ADDR_WIDTH-1:0] index;
    logic [ADDR_WIDTH-1:0] VECTOR_LEN = 10'd8; // example: token & weight vectors are 8 elements

    // Default outputs
    assign token_rd_en = (state == READ);
    assign weight_rd_en = (state == READ);
    assign token_rd_addr = index;
    assign weight_rd_addr = weight_rd_base_addr + index;

    assign mac_a = token_rd_data;
    assign mac_b = weight_rd_data;
    assign mac_acc_in = accumulator;


    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state       <= IDLE;
            mac_start   <= 0;
            index       <= 0;
            accumulator <= 0;
            done        <= 0;
        end else begin
            mac_start <= 0;
            done <= 0;

            case (state)
                IDLE: begin
                    if (start) begin
                        index       <= 0;
                        accumulator <= 0;
                        state       <= READ;
                    end
                end

                READ: begin
                    // Memory read in this cycle; will be available next
                    state <= FEED_MAC;
                end

                FEED_MAC: begin
                    mac_start <= 1;
                    state <= WAIT_MAC;
                end

                WAIT_MAC: begin
                    if (mac_valid) begin
                        accumulator <= mac_acc_out;
                        index <= index + 1;
                        if (index == VECTOR_LEN - 1) begin
                            result <= accumulator; // Store final result
                            done <= 1;
                            state <= IDLE;
                        end else begin
                            state <= READ;
                        end
                    end
                end
            endcase
        end
    end

endmodule
