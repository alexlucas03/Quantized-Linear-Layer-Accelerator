module spi_command_controller #(
    parameter ADDR_WIDTH = 10,
    parameter DATA_WIDTH = 16
)(
    input  logic clk,
    input  logic rst,

    // SPI interface
    input  logic [7:0] spi_data,
    input  logic       spi_byte_ready,

    // Token BRAM interface
    output logic                   token_wr_en,
    output logic [ADDR_WIDTH-1:0] token_wr_addr,
    output logic [DATA_WIDTH-1:0] token_wr_data,

    // Weight BRAM interface
    output logic                   weight_wr_en,
    output logic [ADDR_WIDTH-1:0] weight_wr_addr,
    output logic [DATA_WIDTH-1:0] weight_wr_data
);

    typedef enum logic [2:0] {
        IDLE,
        CMD,
        ADDR_H,
        ADDR_L,
        DATA_H,
        DATA_L
    } state_t;

    state_t state;
    logic [7:0]  command;
    logic [15:0] addr_buf;
    logic [15:0] data_buf;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state          <= IDLE;
            command        <= 0;
            addr_buf       <= 0;
            data_buf       <= 0;
            token_wr_en    <= 0;
            token_wr_addr  <= 0;
            token_wr_data  <= 0;
            weight_wr_en   <= 0;
            weight_wr_addr <= 0;
            weight_wr_data <= 0;
        end else begin
            // Clear write enables by default
            token_wr_en  <= 0;
            weight_wr_en <= 0;

            if (spi_byte_ready) begin
                case (state)
                    IDLE: begin
                        command <= spi_data;
                        state   <= CMD;
                    end

                    CMD: begin
                        // Expecting address high byte next
                        state <= ADDR_H;
                    end

                    ADDR_H: begin
                        addr_buf[15:8] <= spi_data;
                        state <= ADDR_L;
                    end

                    ADDR_L: begin
                        addr_buf[7:0] <= spi_data;
                        state <= DATA_H;
                    end

                    DATA_H: begin
                        data_buf[15:8] <= spi_data;
                        state <= DATA_L;
                    end

                    DATA_L: begin
                        data_buf[7:0] <= spi_data;
                        // Trigger write
                        if (command == 8'h01) begin  // Token
                            token_wr_addr <= addr_buf[ADDR_WIDTH-1:0];
                            token_wr_data <= data_buf;
                            token_wr_en   <= 1;
                        end else if (command == 8'h02) begin // Weight
                            weight_wr_addr <= addr_buf[ADDR_WIDTH-1:0];
                            weight_wr_data <= data_buf;
                            weight_wr_en   <= 1;
                        end
                        state <= ADDR_H;  // Expect next word
                    end
                endcase
            end
        end
    end

endmodule

`timescale 1ns/1ps

module tb_spi_command_controller;

    parameter ADDR_WIDTH = 10;
    parameter DATA_WIDTH = 16;

    logic clk, rst;
    logic [7:0] spi_data;
    logic spi_byte_ready;

    logic token_wr_en;
    logic [ADDR_WIDTH-1:0] token_wr_addr;
    logic [DATA_WIDTH-1:0] token_wr_data;

    logic weight_wr_en;
    logic [ADDR_WIDTH-1:0] weight_wr_addr;
    logic [DATA_WIDTH-1:0] weight_wr_data;

    spi_command_controller #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) dut (
        .clk(clk),
        .rst(rst),
        .spi_data(spi_data),
        .spi_byte_ready(spi_byte_ready),
        .token_wr_en(token_wr_en),
        .token_wr_addr(token_wr_addr),
        .token_wr_data(token_wr_data),
        .weight_wr_en(weight_wr_en),
        .weight_wr_addr(weight_wr_addr),
        .weight_wr_data(weight_wr_data)
    );

    // Clock
    always #5 clk = ~clk;

    initial begin
        $display("Starting SPI Command Controller test...");
        clk = 0;
        rst = 1;
        spi_data = 0;
        spi_byte_ready = 0;

        #20 rst = 0;

        // Simulate SPI packet: Load weight at 0x0010 = 0x03E8 (1000)
        send_spi_byte(8'h02);  // LOAD_WEIGHT
        send_spi_byte(8'h00);  // Addr high
        send_spi_byte(8'h10);  // Addr low
        send_spi_byte(8'h03);  // Data high
        send_spi_byte(8'hE8);  // Data low

        // Simulate SPI packet: Load token at 0x0011 = -20 = 0xFFEC
        send_spi_byte(8'h01);  // LOAD_TOKEN
        send_spi_byte(8'h00);  // Addr high
        send_spi_byte(8'h11);  // Addr low
        send_spi_byte(8'hFF);  // Data high
        send_spi_byte(8'hEC);  // Data low

        #50;
        $finish;
    end

    task send_spi_byte(input [7:0] b);
        begin
            @(posedge clk);
            spi_data <= b;
            spi_byte_ready <= 1;
            @(posedge clk);
            spi_byte_ready <= 0;
        end
    endtask

    // Monitor output
    always_ff @(posedge clk) begin
        if (token_wr_en)
            $display("[%0t ns] Token write: addr=0x%0h data=%0d", $time, token_wr_addr, $signed(token_wr_data));
        if (weight_wr_en)
            $display("[%0t ns] Weight write: addr=0x%0h data=%0d", $time, weight_wr_addr, $signed(weight_wr_data));
    end

endmodule