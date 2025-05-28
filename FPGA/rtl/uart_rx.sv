// uart_rx.sv
module uart_rx #(
    parameter integer CLOCK_FREQ = 50_000_000,  // system clock freq (Hz)
    parameter integer BAUD       = 115200       // UART baud rate
) (
    input  logic       clk,
    input  logic       rst,
    input  logic       rx,           // serial input (idle=1)
    output logic [7:0] data_out,     // received byte
    output logic       byte_ready    // pulses high one clk when data_out is valid
);

    localparam integer BIT_TICKS = CLOCK_FREQ / BAUD;
    typedef enum logic [1:0] {
        RX_IDLE,
        RX_START,
        RX_DATA,
        RX_STOP
    } state_t;

    state_t       state;
    integer       tick_cnt;
    logic [2:0]   bit_cnt;
    logic [7:0]   shift_reg;
    // simple 2-flop sync
    logic         rx_sync1, rx_sync2;

    // synchronize async RX
    always_ff @(posedge clk) begin
        rx_sync1 <= rx;
        rx_sync2 <= rx_sync1;
    end

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state      <= RX_IDLE;
            tick_cnt   <= 0;
            bit_cnt    <= 0;
            shift_reg  <= 8'd0;
            data_out   <= 8'd0;
            byte_ready <= 1'b0;
        end else begin
            byte_ready <= 1'b0;  // default

            case (state)
                RX_IDLE: begin
                    if (!rx_sync2) begin         // start bit detected (line went low)
                        state    <= RX_START;
                        tick_cnt <= BIT_TICKS/2;  // wait half-bit to sample center
                    end
                end

                RX_START: begin
                    if (tick_cnt > 0)
                        tick_cnt <= tick_cnt - 1;
                    else if (!rx_sync2) begin     // still low at bit center
                        state    <= RX_DATA;
                        tick_cnt <= BIT_TICKS;
                        bit_cnt  <= 0;
                    end else
                        state <= RX_IDLE;        // false start
                end

                RX_DATA: begin
                    if (tick_cnt > 0) begin
                        tick_cnt <= tick_cnt - 1;
                    end else begin
                        shift_reg[bit_cnt] <= rx_sync2;
                        bit_cnt            <= bit_cnt + 1;
                        tick_cnt           <= BIT_TICKS;
                        if (bit_cnt == 7)
                            state <= RX_STOP;
                    end
                end

                RX_STOP: begin
                    if (tick_cnt > 0) begin
                        tick_cnt <= tick_cnt - 1;
                    end else begin
                        // if stop bit is high, accept byte
                        if (rx_sync2) begin
                            data_out   <= shift_reg;
                            byte_ready <= 1'b1;
                        end
                        state <= RX_IDLE;
                    end
                end

                default: state <= RX_IDLE;
            endcase
        end
    end

endmodule