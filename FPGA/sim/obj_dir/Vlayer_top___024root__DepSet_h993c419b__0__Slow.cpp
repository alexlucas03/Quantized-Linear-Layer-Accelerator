// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlayer_top.h for the primary calling header

#include "Vlayer_top__pch.h"
#include "Vlayer_top___024root.h"

VL_ATTR_COLD void Vlayer_top___024root___eval_static(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vlayer_top___024root___eval_initial(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
}

VL_ATTR_COLD void Vlayer_top___024root___eval_final(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlayer_top___024root___dump_triggers__stl(Vlayer_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vlayer_top___024root___eval_phase__stl(Vlayer_top___024root* vlSelf);

VL_ATTR_COLD void Vlayer_top___024root___eval_settle(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vlayer_top___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/layer_top.sv", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vlayer_top___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlayer_top___024root___dump_triggers__stl(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vlayer_top___024root___stl_sequent__TOP__0(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___stl_sequent__TOP__0\n"); );
    // Body
    vlSelf->done = (3U == (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state));
}

VL_ATTR_COLD void Vlayer_top___024root___eval_stl(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vlayer_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vlayer_top___024root___eval_triggers__stl(Vlayer_top___024root* vlSelf);

VL_ATTR_COLD bool Vlayer_top___024root___eval_phase__stl(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vlayer_top___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vlayer_top___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlayer_top___024root___dump_triggers__act(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlayer_top___024root___dump_triggers__nba(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge clk or posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vlayer_top___024root___ctor_var_reset(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->start = VL_RAND_RESET_I(1);
    vlSelf->token_wr_en = VL_RAND_RESET_I(1);
    vlSelf->token_wr_addr = VL_RAND_RESET_I(10);
    vlSelf->token_wr_data = VL_RAND_RESET_I(16);
    vlSelf->weight_wr_en = VL_RAND_RESET_I(1);
    vlSelf->weight_wr_addr = VL_RAND_RESET_I(10);
    vlSelf->weight_wr_data = VL_RAND_RESET_I(16);
    vlSelf->result_rd_en = VL_RAND_RESET_I(1);
    vlSelf->result_rd_addr = VL_RAND_RESET_I(10);
    vlSelf->result_rd_data = VL_RAND_RESET_I(32);
    vlSelf->busy = VL_RAND_RESET_I(1);
    vlSelf->done = VL_RAND_RESET_I(1);
    vlSelf->layer_top__DOT__tok_rd_en = VL_RAND_RESET_I(1);
    vlSelf->layer_top__DOT__tok_rd_data = VL_RAND_RESET_I(16);
    vlSelf->layer_top__DOT__wgt_rd_en = VL_RAND_RESET_I(1);
    vlSelf->layer_top__DOT__wgt_rd_data = VL_RAND_RESET_I(16);
    vlSelf->layer_top__DOT__res_wr_en = VL_RAND_RESET_I(1);
    vlSelf->layer_top__DOT__res_wr_data = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->layer_top__DOT__token_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->layer_top__DOT__weight_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(16);
    }
    for (int __Vi0 = 0; __Vi0 < 1024; ++__Vi0) {
        vlSelf->layer_top__DOT__result_mem__DOT__mem[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__vec_cnt = VL_RAND_RESET_I(4);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt = VL_RAND_RESET_I(3);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__rd_addr_reg = VL_RAND_RESET_I(4);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__compute_pipe = VL_RAND_RESET_I(3);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__eov_pipe = VL_RAND_RESET_I(7);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__token_pipe = VL_RAND_RESET_I(16);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__weight_pipe = VL_RAND_RESET_I(16);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_acc_out = VL_RAND_RESET_I(32);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_valid = VL_RAND_RESET_I(1);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__sum_reg = VL_RAND_RESET_I(32);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__a_reg = VL_RAND_RESET_I(16);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__b_reg = VL_RAND_RESET_I(16);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_reg = VL_RAND_RESET_I(32);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage1_valid = VL_RAND_RESET_I(1);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__mult_result = VL_RAND_RESET_I(32);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_stage2 = VL_RAND_RESET_I(32);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage2_valid = VL_RAND_RESET_I(1);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__result = VL_RAND_RESET_I(32);
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage3_valid = VL_RAND_RESET_I(1);
    vlSelf->__Vdly__layer_top__DOT__tok_rd_data = VL_RAND_RESET_I(16);
    vlSelf->__Vdly__layer_top__DOT__wgt_rd_data = VL_RAND_RESET_I(16);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
