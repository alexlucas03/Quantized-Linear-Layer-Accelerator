// uart_tx.sv
module uart_tx #(
    parameter integer CLOCK_FREQ = 50_000_000,  // system clock freq (Hz)
    parameter integer BAUD       = 115200       // UART baud rate
) (
    input  logic       clk,
    input  logic       rst,
    input  logic [7:0] data_in,    // byte to send
    input  logic       tx_start,   // pulse high for 1 clk to begin
    output logic       tx,         // serial output (idle=1)
    output logic       busy        // high while a frame is being sent
);

    localparam integer BIT_TICKS = CLOCK_FREQ / BAUD;
    typedef enum logic [1:0] {
        TX_IDLE,
        TX_START,
        TX_DATA,
        TX_STOP
    } state_t;

    state_t      state;
    integer      tick_cnt;
    logic [2:0]  bit_cnt;
    logic [7:0]  shift_reg;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state     <= TX_IDLE;
            tick_cnt  <= 0;
            bit_cnt   <= 0;
            shift_reg <= 8'd0;
            tx        <= 1'b1;
            busy      <= 1'b0;
        end else begin
            case (state)
                TX_IDLE: begin
                    tx   <= 1'b1;
                    busy <= 1'b0;
                    if (tx_start) begin
                        shift_reg <= data_in;
                        bit_cnt   <= 0;
                        tick_cnt  <= BIT_TICKS;
                        busy      <= 1'b1;
                        state     <= TX_START;
                    end
                end

                TX_START: begin
                    tx <= 1'b0;  // start bit
                    if (tick_cnt > 0)
                        tick_cnt <= tick_cnt - 1;
                    else begin
                        bit_cnt  <= 0;
                        tick_cnt <= BIT_TICKS;
                        state    <= TX_DATA;
                    end
                end

                TX_DATA: begin
                    tx <= shift_reg[bit_cnt];
                    if (tick_cnt > 0) begin
                        tick_cnt <= tick_cnt - 1;
                    end else begin
                        tick_cnt <= BIT_TICKS;
                        if (bit_cnt == 7)
                            state <= TX_STOP;
                        else
                            bit_cnt <= bit_cnt + 1;
                    end
                end

                TX_STOP: begin
                    tx <= 1'b1;  // stop bit
                    if (tick_cnt > 0)
                        tick_cnt <= tick_cnt - 1;
                    else
                        state <= TX_IDLE;
                end

                default: state <= TX_IDLE;
            endcase
        end
    end

endmodule