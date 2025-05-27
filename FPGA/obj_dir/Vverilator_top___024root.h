// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vverilator_top.h for the primary calling header

#ifndef VERILATED_VVERILATOR_TOP___024ROOT_H_
#define VERILATED_VVERILATOR_TOP___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vverilator_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vverilator_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        VL_IN8(clk,0,0);
        VL_IN8(rst,0,0);
        CData/*0:0*/ tb_mac_unit__DOT__clk;
        CData/*0:0*/ tb_mac_unit__DOT__rst;
        VL_IN8(spi_sclk,0,0);
        VL_IN8(spi_mosi,0,0);
        VL_IN8(spi_cs_n,0,0);
        VL_OUT8(matmul_done,0,0);
        CData/*7:0*/ verilator_top__DOT__dut__DOT__spi_data;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__spi_byte_ready;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__token_wr_en;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__weight_wr_en;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__result_wr_en;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__dp_start;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__dp_done;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__mac_start;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__mac_valid;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__start_matmul;
        CData/*2:0*/ verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt;
        CData/*7:0*/ verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__sclk_prev;
        CData/*2:0*/ verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state;
        CData/*7:0*/ verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command;
        CData/*7:0*/ verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi;
        CData/*1:0*/ verilator_top__DOT__dut__DOT__dp__DOT__state;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__mac__DOT__stage1_valid;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__mac__DOT__stage2_valid;
        CData/*0:0*/ verilator_top__DOT__dut__DOT__mac__DOT__stage3_valid;
        CData/*1:0*/ verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state;
        CData/*0:0*/ tb_mac_unit__DOT__start;
        CData/*0:0*/ tb_mac_unit__DOT__valid;
        CData/*0:0*/ tb_mac_unit__DOT__dut__DOT__stage1_valid;
        CData/*0:0*/ tb_mac_unit__DOT__dut__DOT__stage2_valid;
        CData/*0:0*/ tb_mac_unit__DOT__dut__DOT__stage3_valid;
        CData/*7:0*/ __Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg;
        CData/*2:0*/ __Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt;
        CData/*2:0*/ __Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state;
        CData/*7:0*/ __Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command;
        CData/*7:0*/ __Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi;
        CData/*1:0*/ __Vdly__verilator_top__DOT__dut__DOT__dp__DOT__state;
        CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_mac_unit__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_mac_unit__DOT__rst__0;
        CData/*0:0*/ __VactContinue;
        SData/*9:0*/ verilator_top__DOT__dut__DOT__token_wr_addr;
        SData/*9:0*/ verilator_top__DOT__dut__DOT__weight_wr_addr;
        SData/*15:0*/ verilator_top__DOT__dut__DOT__token_wr_data;
        SData/*15:0*/ verilator_top__DOT__dut__DOT__weight_wr_data;
        SData/*15:0*/ verilator_top__DOT__dut__DOT__token_rd_data;
        SData/*15:0*/ verilator_top__DOT__dut__DOT__weight_rd_data;
        SData/*9:0*/ verilator_top__DOT__dut__DOT__result_wr_addr;
        SData/*9:0*/ verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr;
        SData/*9:0*/ verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr;
        SData/*15:0*/ verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length;
        SData/*15:0*/ verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining;
        SData/*9:0*/ verilator_top__DOT__dut__DOT__dp__DOT__index;
        SData/*15:0*/ verilator_top__DOT__dut__DOT__mac__DOT__a_reg;
        SData/*15:0*/ verilator_top__DOT__dut__DOT__mac__DOT__b_reg;
        SData/*9:0*/ verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index;
        SData/*15:0*/ tb_mac_unit__DOT__a;
        SData/*15:0*/ tb_mac_unit__DOT__b;
        SData/*15:0*/ tb_mac_unit__DOT__dut__DOT__a_reg;
        SData/*15:0*/ tb_mac_unit__DOT__dut__DOT__b_reg;
    };
    struct {
        SData/*9:0*/ __Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr;
        SData/*9:0*/ __Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr;
        SData/*15:0*/ __Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length;
        SData/*15:0*/ __Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining;
        SData/*9:0*/ __Vdly__verilator_top__DOT__dut__DOT__dp__DOT__index;
        SData/*9:0*/ __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index;
        VL_OUT(result,31,0);
        IData/*31:0*/ verilator_top__DOT__dut__DOT__result_wr_data;
        IData/*31:0*/ verilator_top__DOT__dut__DOT__dp_result;
        IData/*31:0*/ verilator_top__DOT__dut__DOT__mac_acc_out;
        IData/*31:0*/ verilator_top__DOT__dut__DOT__dp__DOT__accumulator;
        IData/*31:0*/ verilator_top__DOT__dut__DOT__mac__DOT__acc_reg;
        IData/*31:0*/ verilator_top__DOT__dut__DOT__mac__DOT__mult_result;
        IData/*31:0*/ verilator_top__DOT__dut__DOT__mac__DOT__acc_stage2;
        IData/*31:0*/ verilator_top__DOT__dut__DOT__mac__DOT__result;
        IData/*31:0*/ tb_mac_unit__DOT__acc_in;
        IData/*31:0*/ tb_mac_unit__DOT__acc_out;
        IData/*31:0*/ tb_mac_unit__DOT__dut__DOT__acc_reg;
        IData/*31:0*/ tb_mac_unit__DOT__dut__DOT__mult_result;
        IData/*31:0*/ tb_mac_unit__DOT__dut__DOT__acc_stage2;
        IData/*31:0*/ tb_mac_unit__DOT__dut__DOT__result;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<SData/*15:0*/, 1024> verilator_top__DOT__dut__DOT__token_mem__DOT__mem;
        VlUnpacked<SData/*15:0*/, 1024> verilator_top__DOT__dut__DOT__weight_mem__DOT__mem;
        VlUnpacked<CData/*0:0*/, 6> __Vm_traceActivity;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_hbdffd63a__0;
    VlTriggerVec<5> __VactTriggered;
    VlTriggerVec<5> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vverilator_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vverilator_top___024root(Vverilator_top__Syms* symsp, const char* v__name);
    ~Vverilator_top___024root();
    VL_UNCOPYABLE(Vverilator_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
