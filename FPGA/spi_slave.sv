module spi_slave #(
    parameter DATA_WIDTH = 8
)(
    input  logic clk,       // system clock
    input  logic rst,       // system reset

    input  logic sclk,      // SPI clock from RPi
    input  logic mosi,      // Master-Out Slave-In
    input  logic cs_n,      // Chip select (active low)

    output logic [DATA_WIDTH-1:0] data_out,  // received byte
    output logic byte_ready                 // pulses high when new byte is ready
);

    logic [2:0] bit_cnt;
    logic [DATA_WIDTH-1:0] shift_reg;
    logic sclk_prev;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            shift_reg  <= 0;
            bit_cnt    <= 0;
            data_out   <= 0;
            byte_ready <= 0;
            sclk_prev  <= 0;
        end else begin
            byte_ready <= 0;

            sclk_prev <= sclk;

            // Detect rising edge of SCLK when CS is low (Mode 0)
            if (!cs_n && !sclk_prev && sclk) begin
                shift_reg <= {shift_reg[DATA_WIDTH-2:0], mosi};
                bit_cnt <= bit_cnt + 1;

                if (bit_cnt == (DATA_WIDTH - 1)) begin
                    data_out <= {shift_reg[DATA_WIDTH-2:0], mosi};
                    byte_ready <= 1;
                    bit_cnt <= 0;
                end
            end

            // Reset bit counter if CS_n goes high
            if (cs_n) begin
                bit_cnt <= 0;
            end
        end
    end

endmodule
