#!/bin/bash
mkdir -p obj_dir
verilator -Wall --cc verilator_top.sv top_level.sv \
  spi_command_controller.sv spi_slave.sv bram_buffer.sv \
  dot_product.sv MAC.sv matmul_controller.sv \
  --exe main.cpp --trace --timing

make -C obj_dir -f Vverilator_top.mk Vverilator_top
./obj_dir/Vverilator_top