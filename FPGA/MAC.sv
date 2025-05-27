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

`timescale 1ns/1ps

module tb_mac_unit;

    parameter WIDTH = 16;

    logic clk;
    logic rst;
    logic start;
    logic signed [WIDTH-1:0] a, b;
    logic signed [2*WIDTH-1:0] acc_in;
    logic signed [2*WIDTH-1:0] acc_out;
    logic valid;

    // Instantiate the pipelined MAC unit
    MAC #(.WIDTH(WIDTH)) dut (
        .clk(clk),
        .rst(rst),
        .start(start),
        .a(a),
        .b(b),
        .acc_in(acc_in),
        .acc_out(acc_out),
        .valid(valid)
    );

    // Clock generation
    always #5 clk = ~clk;  // 100 MHz clock

    // Helper function: convert floating point to Q5.10 fixed point
    function automatic logic signed [WIDTH-1:0] to_fixed(input real r);
        return $rtoi(r * 1024.0);  // 2^10 = 1024
    endfunction

    // Helper function: convert Q5.10 fixed point to real
    function automatic real from_fixed(input logic signed [WIDTH-1:0] f);
        return f / 1024.0;
    endfunction

    initial begin
        $display("Starting pipelined MAC unit test...");
        clk = 0;
        rst = 1;
        start = 0;
        a = 0;
        b = 0;
        acc_in = 0;

        #20 rst = 0;

        // Input #1
        @(posedge clk);
        a = to_fixed(1.5);
        b = to_fixed(2.0);
        acc_in = 0;
        start = 1;

        @(posedge clk);
        start = 0;

        // Input #2 (back-to-back)
        @(posedge clk);
        a = to_fixed(-0.5);
        b = to_fixed(4.0);
        acc_in = 0;
        start = 1;

        @(posedge clk);
        start = 0;

        // Input #3 (accumulate)
        @(posedge clk);
        a = to_fixed(1.0);
        b = to_fixed(1.0);
        acc_in = to_fixed(3.5); // already in Q5.10
        start = 1;

        @(posedge clk);
        start = 0;

        // Wait for all results
        repeat (10) @(posedge clk);

        $finish;
    end

    // Monitor valid results
    always_ff @(posedge clk) begin
        if (valid) begin
            $display("[%0t ns] Output valid: acc_out = %0f", $time, acc_out / 1024.0);
        end
    end

endmodule
