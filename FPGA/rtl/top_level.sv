// top_level.sv
// -----------------------------------------------------------------------------
// Top-level FPGA module wiring with UART TX to send all results when done
// -----------------------------------------------------------------------------
module top_level #(
    parameter ADDR_WIDTH   = 10,   // 1024 words
    parameter DATA_WIDTH   = 16,
    parameter VECTOR_LEN   = 16,
    parameter NUM_NEURONS  = 16,
    parameter BRAM_LATENCY = 3,
    parameter MAC_LATENCY  = 4
)(
    input  logic                         clk,          // system clock
    input  logic                         rst,          // active-high reset
    input  logic                         uart_rx_pin,  // UART RX GPIO (idle=1)
    output logic                         uart_tx_pin,  // UART TX GPIO (idle=1)
    output logic                         uart_tx_busy  // indicates TX in progress
);

    // Internal byte stream from UART RX
    logic [7:0]                     spi_data;
    logic                           spi_byte_ready;
    logic                           start_matmul;

    // --- UART RX -------------------------------------------------------------
    uart_rx #(
        .CLOCK_FREQ(50_000_000),
        .BAUD      (115200)
    ) uart_rx_inst (
        .clk        (clk),
        .rst        (rst),
        .rx         (uart_rx_pin),
        .data_out   (spi_data),
        .byte_ready (spi_byte_ready)
    );

    // --- SPI Command Controller ----------------------------------------------
    logic                   token_wr_en, weight_wr_en;
    logic [ADDR_WIDTH-1:0]  token_wr_addr, weight_wr_addr;
    logic [DATA_WIDTH-1:0]  token_wr_data, weight_wr_data;

    spi_command_controller #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) cmd_ctrl (
        .clk            (clk),
        .rst            (rst),
        .spi_data       (spi_data),
        .spi_byte_ready (spi_byte_ready),

        .token_wr_en    (token_wr_en),
        .token_wr_addr  (token_wr_addr),
        .token_wr_data  (token_wr_data),

        .weight_wr_en   (weight_wr_en),
        .weight_wr_addr (weight_wr_addr),
        .weight_wr_data (weight_wr_data),

        .start_matmul   (start_matmul)
    );

    // --- Token BRAM ----------------------------------------------------------
    logic                   token_rd_en;
    logic [ADDR_WIDTH-1:0]  token_rd_addr;
    logic [DATA_WIDTH-1:0]  token_rd_data;

    bram_buffer #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) token_mem (
        .clk      (clk),
        .rst      (rst),
        .wr_en    (token_wr_en),
        .wr_addr  (token_wr_addr),
        .wr_data  (token_wr_data),
        .rd_en    (token_rd_en),
        .rd_addr  (token_rd_addr),
        .rd_data  (token_rd_data)
    );

    // --- Weight BRAM ---------------------------------------------------------
    logic                   weight_rd_en;
    logic [ADDR_WIDTH-1:0]  weight_rd_addr;
    logic [DATA_WIDTH-1:0]  weight_rd_data;

    bram_buffer #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) weight_mem (
        .clk      (clk),
        .rst      (rst),
        .wr_en    (weight_wr_en),
        .wr_addr  (weight_wr_addr),
        .wr_data  (weight_wr_data),
        .rd_en    (weight_rd_en),
        .rd_addr  (weight_rd_addr),
        .rd_data  (weight_rd_data)
    );

    // --- Result BRAM ---------------------------------------------------------
    logic                          result_wr_en;
    logic [ADDR_WIDTH-1:0]         result_wr_addr;
    logic signed [2*DATA_WIDTH-1:0] result_wr_data_internal;

    // Read-back for TX
    logic                          result_read_en;
    logic [ADDR_WIDTH-1:0]         result_read_addr;
    logic signed [2*DATA_WIDTH-1:0] result_read_data;

    bram_buffer #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(2*DATA_WIDTH)
    ) result_mem (
        .clk      (clk),
        .rst      (rst),
        .wr_en    (result_wr_en),
        .wr_addr  (result_wr_addr),
        .wr_data  (result_wr_data_internal),
        .rd_en    (result_read_en),
        .rd_addr  (result_read_addr),
        .rd_data  (result_read_data)
    );

    // --- Layer Controller ---------------------------------------------------
    logic busy;
    logic done;

    layer_controller #(
        .ADDR_WIDTH   (ADDR_WIDTH),
        .DATA_WIDTH   (DATA_WIDTH),
        .VECTOR_LEN   (VECTOR_LEN),
        .NUM_NEURONS  (NUM_NEURONS),
        .BRAM_LATENCY (BRAM_LATENCY),
        .MAC_LATENCY  (MAC_LATENCY)
    ) layer_ctrl (
        .clk             (clk),
        .rst             (rst),
        .start           (start_matmul),
        .busy            (busy),
        .done            (done),

        .token_rd_en     (token_rd_en),
        .token_rd_addr   (token_rd_addr),
        .token_rd_data   (token_rd_data),

        .weight_rd_en    (weight_rd_en),
        .weight_rd_addr  (weight_rd_addr),
        .weight_rd_data  (weight_rd_data),

        .result_wr_en    (result_wr_en),
        .result_wr_addr  (result_wr_addr),
        .result_wr_data  (result_wr_data_internal)
    );

    // --- UART TX -------------------------------------------------------------
    // We'll drive uart_tx_start and data when sending; uart_tx_busy tracks activity
    logic        uart_tx_start;
    logic [7:0]  uart_tx_data;

    uart_tx #(
        .CLOCK_FREQ(50_000_000),
        .BAUD      (115200)
    ) uart_tx_inst (
        .clk      (clk),
        .rst      (rst),
        .data_in  (uart_tx_data),
        .tx_start (uart_tx_start),
        .tx       (uart_tx_pin),
        .busy     (uart_tx_busy)
    );

    // --- Send FSM ------------------------------------------------------------
    typedef enum logic [2:0] {
        S_IDLE,
        S_READ_REQ,
        S_WAIT_READ,
        S_SEND_BYTE,
        S_WAIT_TX,
        S_NEXT
    } send_state_t;

    send_state_t                    state, next_state;
    logic [$clog2(NUM_NEURONS)-1:0] neuron_idx, next_neuron_idx;
    logic [1:0]                     byte_idx, next_byte_idx;
    logic signed [2*DATA_WIDTH-1:0] buffer;

    // Sequential state, index, byte counters
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state       <= S_IDLE;
            neuron_idx  <= '0;
            byte_idx    <= '0;
        end else begin
            state       <= next_state;
            neuron_idx  <= next_neuron_idx;
            byte_idx    <= next_byte_idx;
        end
    end

    // Combinatorial next state logic and outputs
    always_comb begin
        // Default control signals
        result_read_en   = 1'b0;
        result_read_addr = neuron_idx;
        uart_tx_start    = 1'b0;
        uart_tx_data     = 8'd0;

        next_state       = state;
        next_neuron_idx  = neuron_idx;
        next_byte_idx    = byte_idx;

        case (state)
            S_IDLE: begin
                if (done) begin
                    next_state      = S_READ_REQ;
                    next_neuron_idx = '0;
                    next_byte_idx   = 2'd3;  // start with MSB
                end
            end

            S_READ_REQ: begin
                // Request read of result[neuron_idx]
                result_read_en   = 1'b1;
                next_state       = S_WAIT_READ;
            end

            S_WAIT_READ: begin
                // One-cycle wait for synchronous BRAM
                next_state = S_SEND_BYTE;
                buffer     = result_read_data;
            end

            S_SEND_BYTE: begin
                // Present byte and start transmission
                uart_tx_data  = buffer[8*byte_idx +: 8];
                uart_tx_start = 1'b1;
                next_state    = S_WAIT_TX;
            end

            S_WAIT_TX: begin
                if (!uart_tx_busy) begin
                    if (byte_idx == 2'd0) begin
                        // Finished 4 bytes of this neuron
                        next_state = S_NEXT;
                    end else begin
                        // Send next less-significant byte
                        next_byte_idx = byte_idx - 1;
                        next_state    = S_SEND_BYTE;
                    end
                end
            end

            S_NEXT: begin
                if (neuron_idx == NUM_NEURONS-1) begin
                    next_state = S_IDLE;  // all done
                end else begin
                    next_neuron_idx = neuron_idx + 1;
                    next_byte_idx   = 2'd3;
                    next_state      = S_READ_REQ;
                end
            end
        endcase
    end

endmodule