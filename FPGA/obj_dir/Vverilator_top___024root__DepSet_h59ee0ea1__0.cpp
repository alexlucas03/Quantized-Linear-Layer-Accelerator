// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "Vverilator_top__pch.h"
#include "Vverilator_top___024root.h"

VlCoroutine Vverilator_top___024root___eval_initial__TOP__Vtiming__0(Vverilator_top___024root* vlSelf);
VlCoroutine Vverilator_top___024root___eval_initial__TOP__Vtiming__1(Vverilator_top___024root* vlSelf);

void Vverilator_top___024root___eval_initial(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vverilator_top___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vverilator_top___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
    vlSelf->__Vtrigprevexpr___TOP__tb_mac_unit__DOT__clk__0 
        = vlSelf->tb_mac_unit__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_mac_unit__DOT__rst__0 
        = vlSelf->tb_mac_unit__DOT__rst;
}

VL_INLINE_OPT VlCoroutine Vverilator_top___024root___eval_initial__TOP__Vtiming__0(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Init
    SData/*15:0*/ __Vfunc_tb_mac_unit__DOT__to_fixed__0__Vfuncout;
    __Vfunc_tb_mac_unit__DOT__to_fixed__0__Vfuncout = 0;
    double __Vfunc_tb_mac_unit__DOT__to_fixed__0__r;
    __Vfunc_tb_mac_unit__DOT__to_fixed__0__r = 0;
    SData/*15:0*/ __Vfunc_tb_mac_unit__DOT__to_fixed__1__Vfuncout;
    __Vfunc_tb_mac_unit__DOT__to_fixed__1__Vfuncout = 0;
    double __Vfunc_tb_mac_unit__DOT__to_fixed__1__r;
    __Vfunc_tb_mac_unit__DOT__to_fixed__1__r = 0;
    SData/*15:0*/ __Vfunc_tb_mac_unit__DOT__to_fixed__2__Vfuncout;
    __Vfunc_tb_mac_unit__DOT__to_fixed__2__Vfuncout = 0;
    double __Vfunc_tb_mac_unit__DOT__to_fixed__2__r;
    __Vfunc_tb_mac_unit__DOT__to_fixed__2__r = 0;
    SData/*15:0*/ __Vfunc_tb_mac_unit__DOT__to_fixed__3__Vfuncout;
    __Vfunc_tb_mac_unit__DOT__to_fixed__3__Vfuncout = 0;
    double __Vfunc_tb_mac_unit__DOT__to_fixed__3__r;
    __Vfunc_tb_mac_unit__DOT__to_fixed__3__r = 0;
    SData/*15:0*/ __Vfunc_tb_mac_unit__DOT__to_fixed__4__Vfuncout;
    __Vfunc_tb_mac_unit__DOT__to_fixed__4__Vfuncout = 0;
    double __Vfunc_tb_mac_unit__DOT__to_fixed__4__r;
    __Vfunc_tb_mac_unit__DOT__to_fixed__4__r = 0;
    SData/*15:0*/ __Vfunc_tb_mac_unit__DOT__to_fixed__5__Vfuncout;
    __Vfunc_tb_mac_unit__DOT__to_fixed__5__Vfuncout = 0;
    double __Vfunc_tb_mac_unit__DOT__to_fixed__5__r;
    __Vfunc_tb_mac_unit__DOT__to_fixed__5__r = 0;
    SData/*15:0*/ __Vfunc_tb_mac_unit__DOT__to_fixed__6__Vfuncout;
    __Vfunc_tb_mac_unit__DOT__to_fixed__6__Vfuncout = 0;
    double __Vfunc_tb_mac_unit__DOT__to_fixed__6__r;
    __Vfunc_tb_mac_unit__DOT__to_fixed__6__r = 0;
    // Body
    VL_WRITEF("Starting pipelined MAC unit test...\n");
    vlSelf->tb_mac_unit__DOT__clk = 0U;
    vlSelf->tb_mac_unit__DOT__rst = 1U;
    vlSelf->tb_mac_unit__DOT__start = 0U;
    vlSelf->tb_mac_unit__DOT__a = 0U;
    vlSelf->tb_mac_unit__DOT__b = 0U;
    vlSelf->tb_mac_unit__DOT__acc_in = 0U;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "MAC.sv", 119);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_mac_unit__DOT__rst = 0U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       122);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vfunc_tb_mac_unit__DOT__to_fixed__0__r = 1.50000000000000000e+00;
    __Vfunc_tb_mac_unit__DOT__to_fixed__0__Vfuncout 
        = (0xffffU & VL_RTOI_I_D((1.02400000000000000e+03 
                                  * __Vfunc_tb_mac_unit__DOT__to_fixed__0__r)));
    vlSelf->tb_mac_unit__DOT__a = __Vfunc_tb_mac_unit__DOT__to_fixed__0__Vfuncout;
    __Vfunc_tb_mac_unit__DOT__to_fixed__1__r = 2.0;
    __Vfunc_tb_mac_unit__DOT__to_fixed__1__Vfuncout 
        = (0xffffU & VL_RTOI_I_D((1.02400000000000000e+03 
                                  * __Vfunc_tb_mac_unit__DOT__to_fixed__1__r)));
    vlSelf->tb_mac_unit__DOT__b = __Vfunc_tb_mac_unit__DOT__to_fixed__1__Vfuncout;
    vlSelf->tb_mac_unit__DOT__acc_in = 0U;
    vlSelf->tb_mac_unit__DOT__start = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       128);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_mac_unit__DOT__start = 0U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       132);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vfunc_tb_mac_unit__DOT__to_fixed__2__r = -5.00000000000000000e-01;
    __Vfunc_tb_mac_unit__DOT__to_fixed__2__Vfuncout 
        = (0xffffU & VL_RTOI_I_D((1.02400000000000000e+03 
                                  * __Vfunc_tb_mac_unit__DOT__to_fixed__2__r)));
    vlSelf->tb_mac_unit__DOT__a = __Vfunc_tb_mac_unit__DOT__to_fixed__2__Vfuncout;
    __Vfunc_tb_mac_unit__DOT__to_fixed__3__r = 4.0;
    __Vfunc_tb_mac_unit__DOT__to_fixed__3__Vfuncout 
        = (0xffffU & VL_RTOI_I_D((1.02400000000000000e+03 
                                  * __Vfunc_tb_mac_unit__DOT__to_fixed__3__r)));
    vlSelf->tb_mac_unit__DOT__b = __Vfunc_tb_mac_unit__DOT__to_fixed__3__Vfuncout;
    vlSelf->tb_mac_unit__DOT__acc_in = 0U;
    vlSelf->tb_mac_unit__DOT__start = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       138);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_mac_unit__DOT__start = 0U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       142);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    __Vfunc_tb_mac_unit__DOT__to_fixed__4__r = 1.0;
    __Vfunc_tb_mac_unit__DOT__to_fixed__4__Vfuncout 
        = (0xffffU & VL_RTOI_I_D((1.02400000000000000e+03 
                                  * __Vfunc_tb_mac_unit__DOT__to_fixed__4__r)));
    vlSelf->tb_mac_unit__DOT__a = __Vfunc_tb_mac_unit__DOT__to_fixed__4__Vfuncout;
    __Vfunc_tb_mac_unit__DOT__to_fixed__5__r = 1.0;
    __Vfunc_tb_mac_unit__DOT__to_fixed__5__Vfuncout 
        = (0xffffU & VL_RTOI_I_D((1.02400000000000000e+03 
                                  * __Vfunc_tb_mac_unit__DOT__to_fixed__5__r)));
    vlSelf->tb_mac_unit__DOT__b = __Vfunc_tb_mac_unit__DOT__to_fixed__5__Vfuncout;
    vlSelf->tb_mac_unit__DOT__acc_in = VL_EXTENDS_II(32,16, 
                                                     ([&]() {
                __Vfunc_tb_mac_unit__DOT__to_fixed__6__r = 3.50000000000000000e+00;
                __Vfunc_tb_mac_unit__DOT__to_fixed__6__Vfuncout 
                    = (0xffffU & VL_RTOI_I_D((1.02400000000000000e+03 
                                              * __Vfunc_tb_mac_unit__DOT__to_fixed__6__r)));
            }(), (IData)(__Vfunc_tb_mac_unit__DOT__to_fixed__6__Vfuncout)));
    vlSelf->tb_mac_unit__DOT__start = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       148);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    vlSelf->tb_mac_unit__DOT__start = 0U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       152);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       152);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       152);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       152);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       152);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       152);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       152);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       152);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       152);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    co_await vlSelf->__VtrigSched_hbdffd63a__0.trigger(0U, 
                                                       nullptr, 
                                                       "@(posedge tb_mac_unit.clk)", 
                                                       "MAC.sv", 
                                                       152);
    vlSelf->__Vm_traceActivity[2U] = 1U;
    VL_FINISH_MT("MAC.sv", 154, "");
    vlSelf->__Vm_traceActivity[2U] = 1U;
}

VL_INLINE_OPT VlCoroutine Vverilator_top___024root___eval_initial__TOP__Vtiming__1(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "MAC.sv", 
                                           98);
        vlSelf->tb_mac_unit__DOT__clk = (1U & (~ (IData)(vlSelf->tb_mac_unit__DOT__clk)));
    }
}

void Vverilator_top___024root___eval_act(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vverilator_top___024root___nba_sequent__TOP__0(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*0:0*/ __Vdly__verilator_top__DOT__dut__DOT__mac_start;
    __Vdly__verilator_top__DOT__dut__DOT__mac_start = 0;
    IData/*31:0*/ __Vdly__verilator_top__DOT__dut__DOT__dp__DOT__accumulator;
    __Vdly__verilator_top__DOT__dut__DOT__dp__DOT__accumulator = 0;
    CData/*1:0*/ __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state;
    __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state = 0;
    CData/*0:0*/ __Vdly__verilator_top__DOT__dut__DOT__dp_start;
    __Vdly__verilator_top__DOT__dut__DOT__dp_start = 0;
    // Body
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt 
        = vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg 
        = vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi 
        = vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining 
        = vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length 
        = vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr 
        = vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr 
        = vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command 
        = vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state 
        = vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state;
    __Vdly__verilator_top__DOT__dut__DOT__dp__DOT__accumulator 
        = vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__accumulator;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__index 
        = vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__index;
    __Vdly__verilator_top__DOT__dut__DOT__mac_start 
        = vlSelf->verilator_top__DOT__dut__DOT__mac_start;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__state 
        = vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__state;
    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index 
        = vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index;
    __Vdly__verilator_top__DOT__dut__DOT__dp_start 
        = vlSelf->verilator_top__DOT__dut__DOT__dp_start;
    __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state 
        = vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state;
    if (vlSelf->rst) {
        __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state = 0U;
        __Vdly__verilator_top__DOT__dut__DOT__dp_start = 0U;
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__result_wr_en = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__result_wr_addr = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__result_wr_data = 0U;
        vlSelf->matmul_done = 0U;
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__state = 0U;
        __Vdly__verilator_top__DOT__dut__DOT__mac_start = 0U;
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__index = 0U;
        __Vdly__verilator_top__DOT__dut__DOT__dp__DOT__accumulator = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__dp_done = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__mac_acc_out = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__result = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__acc_stage2 = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__mult_result = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__acc_reg = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__a_reg = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__b_reg = 0U;
    } else {
        __Vdly__verilator_top__DOT__dut__DOT__dp_start = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__result_wr_en = 0U;
        vlSelf->matmul_done = 0U;
        if ((2U & (IData)(vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state))) {
            if ((1U & (IData)(vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state))) {
                if ((7U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index))) {
                    vlSelf->matmul_done = 1U;
                    __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state = 0U;
                } else {
                    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index 
                        = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index)));
                    __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state = 1U;
                }
            } else if (vlSelf->verilator_top__DOT__dut__DOT__dp_done) {
                vlSelf->verilator_top__DOT__dut__DOT__result_wr_addr 
                    = vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index;
                vlSelf->verilator_top__DOT__dut__DOT__result_wr_data 
                    = vlSelf->verilator_top__DOT__dut__DOT__dp_result;
                vlSelf->verilator_top__DOT__dut__DOT__result_wr_en = 1U;
                __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state = 3U;
            }
        } else if ((1U & (IData)(vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state))) {
            __Vdly__verilator_top__DOT__dut__DOT__dp_start = 1U;
            __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state = 2U;
        } else if (vlSelf->verilator_top__DOT__dut__DOT__start_matmul) {
            vlSelf->__Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index = 0U;
            __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state = 1U;
        }
        __Vdly__verilator_top__DOT__dut__DOT__mac_start = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__dp_done = 0U;
        if ((2U & (IData)(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__state))) {
            if ((1U & (IData)(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__state))) {
                if (vlSelf->verilator_top__DOT__dut__DOT__mac_valid) {
                    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__index 
                        = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__index)));
                    if ((7U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__index))) {
                        vlSelf->verilator_top__DOT__dut__DOT__dp_result 
                            = vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__accumulator;
                        vlSelf->verilator_top__DOT__dut__DOT__dp_done = 1U;
                        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__state = 0U;
                    } else {
                        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__state = 1U;
                    }
                    __Vdly__verilator_top__DOT__dut__DOT__dp__DOT__accumulator 
                        = vlSelf->verilator_top__DOT__dut__DOT__mac_acc_out;
                }
            } else {
                __Vdly__verilator_top__DOT__dut__DOT__mac_start = 1U;
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__state = 3U;
            }
        } else if ((1U & (IData)(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__state))) {
            vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__state = 2U;
        } else if (vlSelf->verilator_top__DOT__dut__DOT__dp_start) {
            vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__index = 0U;
            __Vdly__verilator_top__DOT__dut__DOT__dp__DOT__accumulator = 0U;
            vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__state = 1U;
        }
        vlSelf->verilator_top__DOT__dut__DOT__mac_acc_out 
            = vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__result;
        vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__result 
            = (vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__acc_stage2 
               + VL_SHIFTRS_III(32,32,32, vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__mult_result, 0xaU));
        vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__acc_stage2 
            = vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__acc_reg;
        vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__mult_result 
            = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__a_reg)), 
                          VL_EXTENDS_II(32,16, (IData)(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__b_reg)));
        if (vlSelf->verilator_top__DOT__dut__DOT__mac_start) {
            vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__acc_reg 
                = vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__accumulator;
            vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__a_reg 
                = vlSelf->verilator_top__DOT__dut__DOT__token_rd_data;
            vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__b_reg 
                = vlSelf->verilator_top__DOT__dut__DOT__weight_rd_data;
        }
    }
    vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state 
        = __Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state;
    vlSelf->verilator_top__DOT__dut__DOT__dp_start 
        = __Vdly__verilator_top__DOT__dut__DOT__dp_start;
    vlSelf->verilator_top__DOT__dut__DOT__mac_valid 
        = ((1U & (~ (IData)(vlSelf->rst))) && (IData)(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage3_valid));
    if ((1U & (~ (IData)(vlSelf->rst)))) {
        vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage3_valid 
            = vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage2_valid;
    }
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage2_valid 
        = ((1U & (~ (IData)(vlSelf->rst))) && (IData)(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage1_valid));
    vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage1_valid 
        = ((1U & (~ (IData)(vlSelf->rst))) && (IData)(vlSelf->verilator_top__DOT__dut__DOT__mac_start));
    vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__accumulator 
        = __Vdly__verilator_top__DOT__dut__DOT__dp__DOT__accumulator;
    vlSelf->verilator_top__DOT__dut__DOT__mac_start 
        = __Vdly__verilator_top__DOT__dut__DOT__mac_start;
}

VL_INLINE_OPT void Vverilator_top___024root___nba_sequent__TOP__1(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___nba_sequent__TOP__1\n"); );
    // Body
    if (VL_UNLIKELY(vlSelf->tb_mac_unit__DOT__valid)) {
        VL_WRITEF("[%0t ns] Output valid: acc_out = %0f\n",
                  64,VL_TIME_UNITED_Q(1000),-9,64,(
                                                   VL_ISTOR_D_I(32, vlSelf->tb_mac_unit__DOT__acc_out) 
                                                   / 1.02400000000000000e+03));
    }
}

VL_INLINE_OPT void Vverilator_top___024root___nba_sequent__TOP__2(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___nba_sequent__TOP__2\n"); );
    // Init
    SData/*9:0*/ __Vdlyvdim0__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0;
    __Vdlyvdim0__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0 = 0;
    SData/*15:0*/ __Vdlyvval__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0;
    __Vdlyvval__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0;
    __Vdlyvset__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0;
    __Vdlyvdim0__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0 = 0;
    SData/*15:0*/ __Vdlyvval__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0;
    __Vdlyvval__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0;
    __Vdlyvset__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0 = 0U;
    __Vdlyvset__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0 = 0U;
    if (vlSelf->verilator_top__DOT__dut__DOT__weight_wr_en) {
        __Vdlyvval__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0 
            = vlSelf->verilator_top__DOT__dut__DOT__weight_wr_data;
        __Vdlyvset__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0 = 1U;
        __Vdlyvdim0__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0 
            = vlSelf->verilator_top__DOT__dut__DOT__weight_wr_addr;
    }
    if (vlSelf->verilator_top__DOT__dut__DOT__token_wr_en) {
        __Vdlyvval__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0 
            = vlSelf->verilator_top__DOT__dut__DOT__token_wr_data;
        __Vdlyvset__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0 = 1U;
        __Vdlyvdim0__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0 
            = vlSelf->verilator_top__DOT__dut__DOT__token_wr_addr;
    }
    if ((1U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__state))) {
        vlSelf->verilator_top__DOT__dut__DOT__token_rd_data 
            = vlSelf->verilator_top__DOT__dut__DOT__token_mem__DOT__mem
            [vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__index];
        vlSelf->verilator_top__DOT__dut__DOT__weight_rd_data 
            = vlSelf->verilator_top__DOT__dut__DOT__weight_mem__DOT__mem
            [(0x3ffU & ((IData)(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__index) 
                        + VL_SHIFTL_III(10,10,32, (IData)(vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index), 3U)))];
    }
    if (__Vdlyvset__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0) {
        vlSelf->verilator_top__DOT__dut__DOT__token_mem__DOT__mem[__Vdlyvdim0__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0] 
            = __Vdlyvval__verilator_top__DOT__dut__DOT__token_mem__DOT__mem__v0;
    }
    if (__Vdlyvset__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0) {
        vlSelf->verilator_top__DOT__dut__DOT__weight_mem__DOT__mem[__Vdlyvdim0__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0] 
            = __Vdlyvval__verilator_top__DOT__dut__DOT__weight_mem__DOT__mem__v0;
    }
}

VL_INLINE_OPT void Vverilator_top___024root___nba_sequent__TOP__3(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___nba_sequent__TOP__3\n"); );
    // Body
    vlSelf->tb_mac_unit__DOT__valid = ((1U & (~ (IData)(vlSelf->tb_mac_unit__DOT__rst))) 
                                       && (IData)(vlSelf->tb_mac_unit__DOT__dut__DOT__stage3_valid));
    if (vlSelf->tb_mac_unit__DOT__rst) {
        vlSelf->tb_mac_unit__DOT__acc_out = 0U;
        vlSelf->tb_mac_unit__DOT__dut__DOT__result = 0U;
        vlSelf->tb_mac_unit__DOT__dut__DOT__acc_stage2 = 0U;
        vlSelf->tb_mac_unit__DOT__dut__DOT__mult_result = 0U;
        vlSelf->tb_mac_unit__DOT__dut__DOT__acc_reg = 0U;
        vlSelf->tb_mac_unit__DOT__dut__DOT__a_reg = 0U;
        vlSelf->tb_mac_unit__DOT__dut__DOT__b_reg = 0U;
    } else {
        vlSelf->tb_mac_unit__DOT__acc_out = vlSelf->tb_mac_unit__DOT__dut__DOT__result;
        vlSelf->tb_mac_unit__DOT__dut__DOT__result 
            = (vlSelf->tb_mac_unit__DOT__dut__DOT__acc_stage2 
               + VL_SHIFTRS_III(32,32,32, vlSelf->tb_mac_unit__DOT__dut__DOT__mult_result, 0xaU));
        vlSelf->tb_mac_unit__DOT__dut__DOT__acc_stage2 
            = vlSelf->tb_mac_unit__DOT__dut__DOT__acc_reg;
        vlSelf->tb_mac_unit__DOT__dut__DOT__mult_result 
            = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_mac_unit__DOT__dut__DOT__a_reg)), 
                          VL_EXTENDS_II(32,16, (IData)(vlSelf->tb_mac_unit__DOT__dut__DOT__b_reg)));
        if (vlSelf->tb_mac_unit__DOT__start) {
            vlSelf->tb_mac_unit__DOT__dut__DOT__acc_reg 
                = vlSelf->tb_mac_unit__DOT__acc_in;
            vlSelf->tb_mac_unit__DOT__dut__DOT__a_reg 
                = vlSelf->tb_mac_unit__DOT__a;
            vlSelf->tb_mac_unit__DOT__dut__DOT__b_reg 
                = vlSelf->tb_mac_unit__DOT__b;
        }
    }
    if ((1U & (~ (IData)(vlSelf->tb_mac_unit__DOT__rst)))) {
        vlSelf->tb_mac_unit__DOT__dut__DOT__stage3_valid 
            = vlSelf->tb_mac_unit__DOT__dut__DOT__stage2_valid;
    }
    vlSelf->tb_mac_unit__DOT__dut__DOT__stage2_valid 
        = ((1U & (~ (IData)(vlSelf->tb_mac_unit__DOT__rst))) 
           && (IData)(vlSelf->tb_mac_unit__DOT__dut__DOT__stage1_valid));
    vlSelf->tb_mac_unit__DOT__dut__DOT__stage1_valid 
        = ((1U & (~ (IData)(vlSelf->tb_mac_unit__DOT__rst))) 
           && (IData)(vlSelf->tb_mac_unit__DOT__start));
}

VL_INLINE_OPT void Vverilator_top___024root___nba_sequent__TOP__4(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___nba_sequent__TOP__4\n"); );
    // Body
    vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index;
    vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__state 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__state;
    vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__index 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__dp__DOT__index;
    if (vlSelf->rst) {
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state = 0U;
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command = 0U;
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr = 0U;
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr = 0U;
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length = 0U;
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__token_wr_en = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__weight_wr_en = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__start_matmul = 0U;
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg = 0U;
        vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__spi_data = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__spi_byte_ready = 0U;
    } else {
        vlSelf->verilator_top__DOT__dut__DOT__token_wr_en = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__weight_wr_en = 0U;
        vlSelf->verilator_top__DOT__dut__DOT__start_matmul = 0U;
        if (vlSelf->verilator_top__DOT__dut__DOT__spi_byte_ready) {
            if ((0U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state))) {
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command 
                    = vlSelf->verilator_top__DOT__dut__DOT__spi_data;
                if (((1U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_data)) 
                     | (2U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_data)))) {
                    vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state = 1U;
                } else if ((3U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_data))) {
                    vlSelf->verilator_top__DOT__dut__DOT__start_matmul = 1U;
                }
            } else if ((1U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state))) {
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr 
                    = ((0xffU & (IData)(vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr)) 
                       | (0x300U & ((IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_data) 
                                    << 8U)));
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state = 2U;
            } else if ((2U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state))) {
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr 
                    = ((0x300U & (IData)(vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr)) 
                       | (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_data));
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state = 3U;
            } else if ((3U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state))) {
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length 
                    = ((0xffU & (IData)(vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length)) 
                       | ((IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_data) 
                          << 8U));
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state = 4U;
            } else if ((4U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state))) {
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr 
                    = vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr;
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining 
                    = ((0xff00U & (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length)) 
                       | (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_data));
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state = 5U;
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length 
                    = ((0xff00U & (IData)(vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length)) 
                       | (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_data));
            } else if ((5U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state))) {
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi 
                    = vlSelf->verilator_top__DOT__dut__DOT__spi_data;
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state = 6U;
            } else if ((6U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state))) {
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining 
                    = (0xffffU & ((IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining) 
                                  - (IData)(1U)));
                if ((1U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command))) {
                    vlSelf->verilator_top__DOT__dut__DOT__token_wr_en = 1U;
                    vlSelf->verilator_top__DOT__dut__DOT__token_wr_addr 
                        = vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr;
                    vlSelf->verilator_top__DOT__dut__DOT__token_wr_data 
                        = (((IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi) 
                            << 8U) | (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_data));
                } else if ((2U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command))) {
                    vlSelf->verilator_top__DOT__dut__DOT__weight_wr_en = 1U;
                    vlSelf->verilator_top__DOT__dut__DOT__weight_wr_addr 
                        = vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr;
                    vlSelf->verilator_top__DOT__dut__DOT__weight_wr_data 
                        = (((IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi) 
                            << 8U) | (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_data));
                }
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state 
                    = ((1U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining))
                        ? 0U : 5U);
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr 
                    = (0x3ffU & ((IData)(1U) + (IData)(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr)));
            }
        }
        vlSelf->verilator_top__DOT__dut__DOT__spi_byte_ready = 0U;
        if ((((~ (IData)(vlSelf->spi_cs_n)) & (~ (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__sclk_prev))) 
             & (IData)(vlSelf->spi_sclk))) {
            vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg 
                = ((0xfeU & ((IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg) 
                             << 1U)) | (IData)(vlSelf->spi_mosi));
            vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt 
                = (7U & ((IData)(1U) + (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt)));
            if ((7U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt))) {
                vlSelf->verilator_top__DOT__dut__DOT__spi_data 
                    = ((0xfeU & ((IData)(vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg) 
                                 << 1U)) | (IData)(vlSelf->spi_mosi));
                vlSelf->verilator_top__DOT__dut__DOT__spi_byte_ready = 1U;
                vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt = 0U;
            }
        }
        if (vlSelf->spi_cs_n) {
            vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt = 0U;
        }
    }
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state;
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command;
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr;
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr;
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length;
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining;
    vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi;
    vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg;
    vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt 
        = vlSelf->__Vdly__verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt;
    vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__sclk_prev 
        = ((1U & (~ (IData)(vlSelf->rst))) && (IData)(vlSelf->spi_sclk));
}

void Vverilator_top___024root___eval_nba(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vverilator_top___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vverilator_top___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vverilator_top___024root___nba_sequent__TOP__2(vlSelf);
    }
    if ((8ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vverilator_top___024root___nba_sequent__TOP__3(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vverilator_top___024root___nba_sequent__TOP__4(vlSelf);
        vlSelf->__Vm_traceActivity[5U] = 1U;
    }
}

void Vverilator_top___024root___timing_resume(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___timing_resume\n"); );
    // Body
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VtrigSched_hbdffd63a__0.resume("@(posedge tb_mac_unit.clk)");
    }
    if ((0x10ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vverilator_top___024root___timing_commit(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___timing_commit\n"); );
    // Body
    if ((! (4ULL & vlSelf->__VactTriggered.word(0U)))) {
        vlSelf->__VtrigSched_hbdffd63a__0.commit("@(posedge tb_mac_unit.clk)");
    }
}

void Vverilator_top___024root___eval_triggers__act(Vverilator_top___024root* vlSelf);

bool Vverilator_top___024root___eval_phase__act(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<5> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vverilator_top___024root___eval_triggers__act(vlSelf);
    Vverilator_top___024root___timing_commit(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vverilator_top___024root___timing_resume(vlSelf);
        Vverilator_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vverilator_top___024root___eval_phase__nba(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vverilator_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__nba(Vverilator_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__act(Vverilator_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vverilator_top___024root___eval(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vverilator_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("verilator_top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vverilator_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("verilator_top.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vverilator_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vverilator_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vverilator_top___024root___eval_debug_assertions(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->spi_sclk & 0xfeU))) {
        Verilated::overWidthError("spi_sclk");}
    if (VL_UNLIKELY((vlSelf->spi_mosi & 0xfeU))) {
        Verilated::overWidthError("spi_mosi");}
    if (VL_UNLIKELY((vlSelf->spi_cs_n & 0xfeU))) {
        Verilated::overWidthError("spi_cs_n");}
}
#endif  // VL_DEBUG
