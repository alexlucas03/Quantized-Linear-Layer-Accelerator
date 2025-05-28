# Top-level Makefile
VERILATOR      = verilator
RTL_DIR        = rtl
TB_CPP_DIR     = tb/cpp
TB_SV_DIR      = tb/sv
SIM_DIR        = sim

# Allow override of TOP from command line, default to tb_mac_unit
TOP            ?= MAC
TB_CPP         = $(TOP)_tb.cpp

# Source file lists
RTL_SRCS       := $(wildcard $(RTL_DIR)/*.v)  $(wildcard $(RTL_DIR)/*.sv)
TB_CPP_SRCS    := $(wildcard $(TB_CPP_DIR)/*.cpp)
TB_SV_SRCS     := $(wildcard $(TB_SV_DIR)/*.sv)

# Only include tb/sv if there are .sv benches
ifneq ($(strip $(TB_SV_SRCS)),)
SV_INCLUDE    = -I $(TB_SV_DIR)
else
SV_INCLUDE    =
endif

.PHONY: all sim clean
all: sim

sim: $(RTL_SRCS) $(TB_CPP_DIR)/$(TB_CPP) $(TB_SV_SRCS)
	mkdir -p $(SIM_DIR)/obj_dir
	mkdir -p $(SIM_DIR)/vcd
	$(VERILATOR) \
	  --cc $(RTL_SRCS) \
	  --exe $(abspath $(TB_CPP_DIR)/$(TB_CPP)) $(TB_SV_SRCS) \
	  --top-module $(TOP) \
	  --Mdir $(SIM_DIR)/obj_dir \
	  --trace \
	  --no-timing \
	  -Wno-fatal \
	  $(SV_INCLUDE)
	$(MAKE) -C $(SIM_DIR)/obj_dir -f V$(TOP).mk V$(TOP)
	./$(SIM_DIR)/obj_dir/V$(TOP)

clean:
	rm -rf $(SIM_DIR) obj_dir* *.o *.d