module spi_slave #(
    parameter DATA_WIDTH = 8
)(
    input  logic clk,       // system clock
    input  logic rst,       // system reset

    input  logic sclk,      // SPI clock from RPi
    input  logic mosi,      // Master-Out Slave-In
    input  logic cs_n,      // Chip select (active low)

    output logic [DATA_WIDTH-1:0] data_out,  // received byte
    output logic byte_ready                  // pulses high when new byte is ready
);

    // Synchronization registers
    logic [2:0] sclk_sync;
    logic [1:0] cs_n_sync;
    logic [1:0] mosi_sync;

    // Internal registers
    logic [2:0] bit_cnt;
    logic [DATA_WIDTH-1:0] shift_reg;

    // Synchronize inputs into clk domain
    always_ff @(posedge clk) begin
        sclk_sync  <= {sclk_sync[1:0], sclk};
        cs_n_sync  <= {cs_n_sync[0], cs_n};
        mosi_sync  <= {mosi_sync[0], mosi};
    end

    wire sclk_rising = (sclk_sync[2:1] == 2'b01);
    wire cs_active   = ~cs_n_sync[1];  // active low

    // SPI bit sampling logic
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            shift_reg  <= 0;
            bit_cnt    <= 0;
            data_out   <= 0;
            byte_ready <= 0;
        end else begin
            byte_ready <= 0;

            if (cs_active && sclk_rising) begin
                shift_reg <= {shift_reg[DATA_WIDTH-2:0], mosi_sync[1]};
                bit_cnt   <= bit_cnt + 1;

                if (bit_cnt == DATA_WIDTH - 1) begin
                    data_out   <= {shift_reg[DATA_WIDTH-2:0], mosi_sync[1]};
                    byte_ready <= 1;
                    bit_cnt    <= 0;
                end
            end

            if (!cs_active) begin
                bit_cnt <= 0;
            end
        end
    end

endmodule