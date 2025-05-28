module layer_controller #(
  parameter ADDR_WIDTH    = 10,
  parameter DATA_WIDTH    = 16,
  parameter VECTOR_LEN    = 512,
  parameter NUM_NEURONS   = 512,
  // Pipeline latency of MAC (cycles from .start to .valid)
  parameter PIPE_LATENCY  = 2
)(
  input  logic                            clk,
  input  logic                            rst,
  input  logic                            start,
  output logic                            busy,

  // Token BRAM read port
  output logic                            tok_rd_en,
  output logic [ADDR_WIDTH-1:0]           tok_rd_addr,
  input  logic [DATA_WIDTH-1:0]           tok_rd_data,

  // Weight BRAM read port
  output logic                            wgt_rd_en,
  output logic [ADDR_WIDTH-1:0]           wgt_rd_addr,
  input  logic [DATA_WIDTH-1:0]           wgt_rd_data,

  // Result write-back
  output logic                            res_wr_en,
  output logic [ADDR_WIDTH-1:0]           res_wr_addr,
  output logic signed [2*DATA_WIDTH-1:0]  res_wr_data,

  output logic                            done
);

  // Pointers
  logic [$clog2(VECTOR_LEN):0]  elem_idx;
  logic [$clog2(NUM_NEURONS):0] neuron_idx;

  // MAC interface
  logic                            mac_start;
  logic signed [DATA_WIDTH-1:0]    mac_a, mac_b;
  logic signed [2*DATA_WIDTH-1:0]  mac_acc_in, mac_acc_out;
  logic                            mac_valid;

  // Instantiate pipelined MAC
  MAC #(.WIDTH(DATA_WIDTH)) mac_inst (
    .clk    (clk),
    .rst    (rst),
    .start  (mac_start),
    .a      (mac_a),
    .b      (mac_b),
    .acc_in (mac_acc_in),
    .acc_out(mac_acc_out),
    .valid  (mac_valid)
  );

  // Shift registers to align start→valid and acc feedback
  logic [PIPE_LATENCY:0]                  start_pipe;
  logic [PIPE_LATENCY:0]                  valid_pipe;
  logic signed [2*DATA_WIDTH-1:0]        acc_pipe [0:PIPE_LATENCY];

  // Controls
  assign busy       = !done;
  assign res_wr_en  = valid_pipe[PIPE_LATENCY] && (elem_idx == VECTOR_LEN);
  assign res_wr_addr= neuron_idx;
  assign res_wr_data= acc_pipe[PIPE_LATENCY];

  // Drive BRAM & MAC inputs
  assign tok_rd_en  = start_pipe[0];
  assign tok_rd_addr= elem_idx;
  assign wgt_rd_en  = start_pipe[0];
  assign wgt_rd_addr= neuron_idx * VECTOR_LEN + elem_idx;
  assign mac_start  = start_pipe[0];
  assign mac_a      = tok_rd_data;
  assign mac_b      = wgt_rd_data;
  assign mac_acc_in = acc_pipe[PIPE_LATENCY];

  // Single-process sequential block
  always_ff @(posedge clk or posedge rst) begin
    if (rst) begin
      elem_idx    <= 0;
      neuron_idx  <= 0;
      done        <= 0;
      start_pipe  <= '0;
      valid_pipe  <= '0;
      // initialize acc feedback pipe
      for (int i = 0; i <= PIPE_LATENCY; i++)
        acc_pipe[i] <= '0;
    end else begin
      // kick off processing on "start"
      start_pipe[0] <= start && !busy;
      for (int i = 1; i <= PIPE_LATENCY; i++) begin
        start_pipe[i] <= start_pipe[i-1];
      end

      // shift the valid flag
      valid_pipe[0] <= mac_valid;
      for (int i = 1; i <= PIPE_LATENCY; i++) begin
        valid_pipe[i] <= valid_pipe[i-1];
      end

      // update accumulator feedback pipeline
      acc_pipe[0] <= (elem_idx == 0 && start_pipe[0]) ? '0 : mac_acc_out;
      for (int i = 1; i <= PIPE_LATENCY; i++) begin
        acc_pipe[i] <= acc_pipe[i-1];
      end

      // advance index when a valid result comes out
      if (valid_pipe[PIPE_LATENCY]) begin
        if (elem_idx + 1 < VECTOR_LEN) begin
          elem_idx <= elem_idx + 1;
        end else begin
          // finished one neuron
          if (neuron_idx + 1 < NUM_NEURONS) begin
            neuron_idx <= neuron_idx + 1;
            elem_idx   <= 0;
            // clear accumulator for next neuron
            acc_pipe[0] <= '0;
          end else begin
            done <= 1;
          end
        end
      end
    end
  end
endmodule