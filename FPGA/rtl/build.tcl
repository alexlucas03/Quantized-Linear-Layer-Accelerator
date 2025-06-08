# build.tcl — headless build for LLM accelerator on GW1NR-LV9QN88PC6/I5

# 1) Create a new project
create_project -name llm_accel -dir ./llm_accel -pn GW1NR-LV9QN88PC6/I5

# 2) Import your RTL
import_files -file \
    MAC.sv \
    layer_controller.sv \
    bram_buffer.sv \
    uart_tx.sv \
    uart_rx.sv \
    spi_command_controller.sv \
    top_level.sv

# 3) Declare the top-level module
set_option -top_module top_level

# 4) (Optional) Change the base name of output files
set_option -output_base_name llm_accel

# 5) Run the full flow: synth → place & route → bitgen
run all

# 6) Close the project
run close