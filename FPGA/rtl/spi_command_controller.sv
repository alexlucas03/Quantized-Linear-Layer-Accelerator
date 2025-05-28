// SPI Command Controller with Streaming Write Support
// Supports: LOAD_TOKEN (0x01), LOAD_WEIGHT (0x02), START_MATMUL (0x03)

module spi_command_controller #(
    parameter ADDR_WIDTH = 10,
    parameter DATA_WIDTH = 16
)(
    input  logic clk,
    input  logic rst,

    input  logic [7:0] spi_data,
    input  logic       spi_byte_ready,

    output logic                   token_wr_en,
    output logic [ADDR_WIDTH-1:0] token_wr_addr,
    output logic [DATA_WIDTH-1:0] token_wr_data,

    output logic                   weight_wr_en,
    output logic [ADDR_WIDTH-1:0] weight_wr_addr,
    output logic [DATA_WIDTH-1:0] weight_wr_data,

    output logic start_matmul
);

    typedef enum logic [2:0] {
        IDLE,
        READ_ADDR_H,
        READ_ADDR_L,
        READ_LEN_H,
        READ_LEN_L,
        WRITE_HI,
        WRITE_LO
    } state_t;

    state_t state;

    logic [7:0] command;
    logic [ADDR_WIDTH-1:0] base_addr;
    logic [ADDR_WIDTH-1:0] write_addr;
    logic [15:0] length;
    logic [15:0] remaining;
    logic [7:0] data_hi;

    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            state          <= IDLE;
            command        <= 8'h00;
            base_addr      <= 0;
            write_addr     <= 0;
            length         <= 0;
            remaining      <= 0;
            token_wr_en    <= 0;
            weight_wr_en   <= 0;
            start_matmul   <= 0;
        end else begin
            // Defaults
            token_wr_en  <= 0;
            weight_wr_en <= 0;
            start_matmul <= 0;

            if (spi_byte_ready) begin
                case (state)
                    IDLE: begin
                        command <= spi_data;
                        if (spi_data == 8'h01 || spi_data == 8'h02)
                            state <= READ_ADDR_H;
                        else if (spi_data == 8'h03)
                            start_matmul <= 1;
                    end

                    READ_ADDR_H: begin
                        base_addr[ADDR_WIDTH-1:8] <= spi_data;
                        state <= READ_ADDR_L;
                    end

                    READ_ADDR_L: begin
                        base_addr[7:0] <= spi_data;
                        state <= READ_LEN_H;
                    end

                    READ_LEN_H: begin
                        length[15:8] <= spi_data;
                        state <= READ_LEN_L;
                    end

                    READ_LEN_L: begin
                        length[7:0] <= spi_data;
                        write_addr <= base_addr;
                        remaining  <= {length[15:8], spi_data};
                        state <= WRITE_HI;
                    end

                    WRITE_HI: begin
                        data_hi <= spi_data;
                        state <= WRITE_LO;
                    end

                    WRITE_LO: begin
                        if (command == 8'h01) begin
                            token_wr_en   <= 1;
                            token_wr_addr <= write_addr;
                            token_wr_data <= {data_hi, spi_data};
                        end else if (command == 8'h02) begin
                            weight_wr_en   <= 1;
                            weight_wr_addr <= write_addr;
                            weight_wr_data <= {data_hi, spi_data};
                        end

                        write_addr <= write_addr + 1;
                        remaining  <= remaining - 1;

                        if (remaining == 16'd1)
                            state <= IDLE;
                        else
                            state <= WRITE_HI;
                    end
                endcase
            end
        end
    end

endmodule
