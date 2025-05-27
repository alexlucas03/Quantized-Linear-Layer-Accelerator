// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "Vverilator_top__pch.h"
#include "Vverilator_top___024root.h"

VL_ATTR_COLD void Vverilator_top___024root___eval_static(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vverilator_top___024root___eval_final(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vverilator_top___024root___eval_settle(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__act(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @(posedge tb_mac_unit.clk)\n");
    }
    if ((8ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 3 is active: @(posedge tb_mac_unit.clk or posedge tb_mac_unit.rst)\n");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__nba(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk or posedge rst)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @(posedge tb_mac_unit.clk)\n");
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 3 is active: @(posedge tb_mac_unit.clk or posedge tb_mac_unit.rst)\n");
    }
    if ((0x10ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 4 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vverilator_top___024root___ctor_var_reset(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->spi_sclk = VL_RAND_RESET_I(1);
    vlSelf->spi_mosi = VL_RAND_RESET_I(1);
    vlSelf->spi_cs_n = VL_RAND_RESET_I(1);
    vlSelf->matmul_done = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->verilator_top__DOT__dut__DOT__spi_data = VL_RAND_RESET_I(8);
    vlSelf->verilator_top__DOT__dut__DOT__spi_byte_ready = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__token_wr_en = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__weight_wr_en = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__token_wr_addr = VL_RAND_RESET_I(10);
    vlSelf->verilator_top__DOT__dut__DOT__weight_wr_addr = VL_RAND_RESET_I(10);
    vlSelf->verilator_top__DOT__dut__DOT__token_wr_data = VL_RAND_RESET_I(16);
    vlSelf->verilator_top__DOT__dut__DOT__weight_wr_data = VL_RAND_RESET_I(16);
    vlSelf->verilator_top__DOT__dut__DOT__token_rd_data = VL_RAND_RESET_I(16);
    vlSelf->verilator_top__DOT__dut__DOT__weight_rd_data = VL_RAND_RESET_I(16);
    vlSelf->verilator_top__DOT__dut__DOT__result_wr_en = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__result_wr_addr = VL_RAND_RESET_I(10);
    vlSelf->verilator_top__DOT__dut__DOT__result_wr_data = VL_RAND_RESET_I(32);
    vlSelf->verilator_top__DOT__dut__DOT__dp_start = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__dp_done = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__dp_result = VL_RAND_RESET_I(32);
    vlSelf->verilator_top__DOT__dut__DOT__mac_start = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__mac_valid = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__mac_acc_out = VL_RAND_RESET_I(32);
    vlSelf->verilator_top__DOT__dut__DOT__start_matmul = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt = VL_RAND_RESET_I(3);
    vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg = VL_RAND_RESET_I(8);
    vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__sclk_prev = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command = VL_RAND_RESET_I(8);
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr = VL_RAND_RESET_I(10);
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr = VL_RAND_RESET_I(10);
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length = VL_RAND_RESET_I(16);
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining = VL_RAND_RESET_I(16);
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi = VL_RAND_RESET_I(8);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->verilator_top__DOT__dut__DOT__token_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->verilator_top__DOT__dut__DOT__weight_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__accumulator = VL_RAND_RESET_I(32);
    vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__index = VL_RAND_RESET_I(10);
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__a_reg = VL_RAND_RESET_I(16);
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__b_reg = VL_RAND_RESET_I(16);
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__acc_reg = VL_RAND_RESET_I(32);
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage1_valid = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__mult_result = VL_RAND_RESET_I(32);
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__acc_stage2 = VL_RAND_RESET_I(32);
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage2_valid = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__result = VL_RAND_RESET_I(32);
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage3_valid = VL_RAND_RESET_I(1);
    vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index = VL_RAND_RESET_I(10);
    vlSelf->tb_mac_unit__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_mac_unit__DOT__rst = VL_RAND_RESET_I(1);
    vlSelf->tb_mac_unit__DOT__start = VL_RAND_RESET_I(1);
    vlSelf->tb_mac_unit__DOT__a = VL_RAND_RESET_I(16);
    vlSelf->tb_mac_unit__DOT__b = VL_RAND_RESET_I(16);
    vlSelf->tb_mac_unit__DOT__acc_in = VL_RAND_RESET_I(32);
    vlSelf->tb_mac_unit__DOT__acc_out = VL_RAND_RESET_I(32);
    vlSelf->tb_mac_unit__DOT__valid = VL_RAND_RESET_I(1);
    vlSelf->tb_mac_unit__DOT__dut__DOT__a_reg = VL_RAND_RESET_I(16);
    vlSelf->tb_mac_unit__DOT__dut__DOT__b_reg = VL_RAND_RESET_I(16);
    vlSelf->tb_mac_unit__DOT__dut__DOT__acc_reg = VL_RAND_RESET_I(32);
    vlSelf->tb_mac_unit__DOT__dut__DOT__stage1_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_mac_unit__DOT__dut__DOT__mult_result = VL_RAND_RESET_I(32);
    vlSelf->tb_mac_unit__DOT__dut__DOT__acc_stage2 = VL_RAND_RESET_I(32);
    vlSelf->tb_mac_unit__DOT__dut__DOT__stage2_valid = VL_RAND_RESET_I(1);
    vlSelf->tb_mac_unit__DOT__dut__DOT__result = VL_RAND_RESET_I(32);
    vlSelf->tb_mac_unit__DOT__dut__DOT__stage3_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr = VL_RAND_RESET_I(10);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr = VL_RAND_RESET_I(10);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi = VL_RAND_RESET_I(8);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__index = VL_RAND_RESET_I(10);
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index = VL_RAND_RESET_I(10);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_mac_unit__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_mac_unit__DOT__rst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 6; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
