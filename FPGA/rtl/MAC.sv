module MAC #(
    parameter WIDTH = 16 // Q5.10 = 1 sign + 5 int + 10 frac
)(
    input  logic clk,
    input  logic rst,
    input  logic start,
    input  logic signed [WIDTH-1:0] a,
    input  logic signed [WIDTH-1:0] b,
    input  logic signed [2*WIDTH-1:0] acc_in,
    output logic signed [2*WIDTH-1:0] acc_out,
    output logic valid  // Indicates acc_out is valid
);

    // Stage 1: Latch inputs
    logic signed [WIDTH-1:0] a_reg, b_reg;
    logic signed [2*WIDTH-1:0] acc_reg;
    logic stage1_valid;

    // Stage 2: Multiply
    logic signed [2*WIDTH-1:0] mult_result;
    logic signed [2*WIDTH-1:0] acc_stage2;
    logic stage2_valid;

    // Stage 3: Add and shift
    logic signed [2*WIDTH-1:0] result;
    logic stage3_valid;

    // Pipeline registers
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            a_reg         <= '0;
            b_reg         <= '0;
            acc_reg       <= '0;
            stage1_valid  <= 0;

            mult_result   <= '0;
            acc_stage2    <= '0;
            stage2_valid  <= 0;
            stage3_valid  <= 0;

            result        <= '0;
            acc_out       <= '0;
            valid         <= 0;
        end else begin
            // Stage 1
            if (start) begin
                a_reg        <= a;
                b_reg        <= b;
                acc_reg      <= acc_in;
                stage1_valid <= 1;
            end else begin
                stage1_valid <= 0;
            end

            // Stage 2
            mult_result   <= a_reg * b_reg;
            acc_stage2    <= acc_reg;
            stage2_valid  <= stage1_valid;

            // Stage 3
            result        <= acc_stage2 + (mult_result >>> 10); // align Q5.10
            stage3_valid  <= stage2_valid;

            // Output
            acc_out <= result;
            valid   <= stage3_valid;
        end
    end

endmodule

