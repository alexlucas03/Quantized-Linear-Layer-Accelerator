// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlayer_top.h for the primary calling header

#include "Vlayer_top__pch.h"
#include "Vlayer_top___024root.h"

void Vlayer_top___024root___eval_act(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vlayer_top___024root___nba_sequent__TOP__0(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___nba_sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vdlyvdim0__layer_top__DOT__token_mem__DOT__mem__v0;
    __Vdlyvdim0__layer_top__DOT__token_mem__DOT__mem__v0 = 0;
    SData/*15:0*/ __Vdlyvval__layer_top__DOT__token_mem__DOT__mem__v0;
    __Vdlyvval__layer_top__DOT__token_mem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__layer_top__DOT__token_mem__DOT__mem__v0;
    __Vdlyvset__layer_top__DOT__token_mem__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__layer_top__DOT__weight_mem__DOT__mem__v0;
    __Vdlyvdim0__layer_top__DOT__weight_mem__DOT__mem__v0 = 0;
    SData/*15:0*/ __Vdlyvval__layer_top__DOT__weight_mem__DOT__mem__v0;
    __Vdlyvval__layer_top__DOT__weight_mem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__layer_top__DOT__weight_mem__DOT__mem__v0;
    __Vdlyvset__layer_top__DOT__weight_mem__DOT__mem__v0 = 0;
    SData/*9:0*/ __Vdlyvdim0__layer_top__DOT__result_mem__DOT__mem__v0;
    __Vdlyvdim0__layer_top__DOT__result_mem__DOT__mem__v0 = 0;
    IData/*31:0*/ __Vdlyvval__layer_top__DOT__result_mem__DOT__mem__v0;
    __Vdlyvval__layer_top__DOT__result_mem__DOT__mem__v0 = 0;
    CData/*0:0*/ __Vdlyvset__layer_top__DOT__result_mem__DOT__mem__v0;
    __Vdlyvset__layer_top__DOT__result_mem__DOT__mem__v0 = 0;
    // Body
    __Vdlyvset__layer_top__DOT__weight_mem__DOT__mem__v0 = 0U;
    __Vdlyvset__layer_top__DOT__token_mem__DOT__mem__v0 = 0U;
    vlSelf->__Vdly__layer_top__DOT__tok_rd_data = vlSelf->layer_top__DOT__tok_rd_data;
    vlSelf->__Vdly__layer_top__DOT__wgt_rd_data = vlSelf->layer_top__DOT__wgt_rd_data;
    __Vdlyvset__layer_top__DOT__result_mem__DOT__mem__v0 = 0U;
    if (vlSelf->weight_wr_en) {
        __Vdlyvval__layer_top__DOT__weight_mem__DOT__mem__v0 
            = vlSelf->weight_wr_data;
        __Vdlyvset__layer_top__DOT__weight_mem__DOT__mem__v0 = 1U;
        __Vdlyvdim0__layer_top__DOT__weight_mem__DOT__mem__v0 
            = vlSelf->weight_wr_addr;
    }
    if (vlSelf->token_wr_en) {
        __Vdlyvval__layer_top__DOT__token_mem__DOT__mem__v0 
            = vlSelf->token_wr_data;
        __Vdlyvset__layer_top__DOT__token_mem__DOT__mem__v0 = 1U;
        __Vdlyvdim0__layer_top__DOT__token_mem__DOT__mem__v0 
            = vlSelf->token_wr_addr;
    }
    if (vlSelf->layer_top__DOT__tok_rd_en) {
        vlSelf->__Vdly__layer_top__DOT__tok_rd_data 
            = vlSelf->layer_top__DOT__token_mem__DOT__mem
            [vlSelf->layer_top__DOT__u_layer_ctrl__DOT__rd_addr_reg];
    }
    if (vlSelf->layer_top__DOT__wgt_rd_en) {
        vlSelf->__Vdly__layer_top__DOT__wgt_rd_data 
            = vlSelf->layer_top__DOT__weight_mem__DOT__mem
            [(((IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt) 
               << 4U) | (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__rd_addr_reg))];
    }
    if (vlSelf->layer_top__DOT__res_wr_en) {
        __Vdlyvval__layer_top__DOT__result_mem__DOT__mem__v0 
            = vlSelf->layer_top__DOT__res_wr_data;
        __Vdlyvset__layer_top__DOT__result_mem__DOT__mem__v0 = 1U;
        __Vdlyvdim0__layer_top__DOT__result_mem__DOT__mem__v0 
            = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt;
    }
    if (vlSelf->result_rd_en) {
        vlSelf->result_rd_data = vlSelf->layer_top__DOT__result_mem__DOT__mem
            [vlSelf->result_rd_addr];
    }
    if (__Vdlyvset__layer_top__DOT__token_mem__DOT__mem__v0) {
        vlSelf->layer_top__DOT__token_mem__DOT__mem[__Vdlyvdim0__layer_top__DOT__token_mem__DOT__mem__v0] 
            = __Vdlyvval__layer_top__DOT__token_mem__DOT__mem__v0;
    }
    if (__Vdlyvset__layer_top__DOT__weight_mem__DOT__mem__v0) {
        vlSelf->layer_top__DOT__weight_mem__DOT__mem[__Vdlyvdim0__layer_top__DOT__weight_mem__DOT__mem__v0] 
            = __Vdlyvval__layer_top__DOT__weight_mem__DOT__mem__v0;
    }
    if (__Vdlyvset__layer_top__DOT__result_mem__DOT__mem__v0) {
        vlSelf->layer_top__DOT__result_mem__DOT__mem[__Vdlyvdim0__layer_top__DOT__result_mem__DOT__mem__v0] 
            = __Vdlyvval__layer_top__DOT__result_mem__DOT__mem__v0;
    }
}

VL_INLINE_OPT void Vlayer_top___024root___nba_sequent__TOP__1(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*2:0*/ __Vdly__layer_top__DOT__u_layer_ctrl__DOT__compute_pipe;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__compute_pipe = 0;
    CData/*6:0*/ __Vdly__layer_top__DOT__u_layer_ctrl__DOT__eov_pipe;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__eov_pipe = 0;
    CData/*1:0*/ __Vdly__layer_top__DOT__u_layer_ctrl__DOT__state;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__state = 0;
    CData/*3:0*/ __Vdly__layer_top__DOT__u_layer_ctrl__DOT__vec_cnt;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__vec_cnt = 0;
    CData/*2:0*/ __Vdly__layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt = 0;
    IData/*31:0*/ __Vdly__layer_top__DOT__u_layer_ctrl__DOT__sum_reg;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__sum_reg = 0;
    // Body
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__compute_pipe 
        = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__compute_pipe;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__eov_pipe 
        = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__eov_pipe;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__sum_reg 
        = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__sum_reg;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt 
        = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__vec_cnt 
        = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__vec_cnt;
    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__state 
        = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state;
    if (vlSelf->rst) {
        __Vdly__layer_top__DOT__u_layer_ctrl__DOT__compute_pipe = 0U;
        __Vdly__layer_top__DOT__u_layer_ctrl__DOT__eov_pipe = 0U;
        __Vdly__layer_top__DOT__u_layer_ctrl__DOT__state = 0U;
        vlSelf->busy = 0U;
        __Vdly__layer_top__DOT__u_layer_ctrl__DOT__vec_cnt = 0U;
        __Vdly__layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt = 0U;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__rd_addr_reg = 0U;
        vlSelf->layer_top__DOT__tok_rd_en = 0U;
        vlSelf->layer_top__DOT__wgt_rd_en = 0U;
        vlSelf->layer_top__DOT__res_wr_en = 0U;
        __Vdly__layer_top__DOT__u_layer_ctrl__DOT__sum_reg = 0U;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_acc_out = 0U;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__result = 0U;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_stage2 = 0U;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__mult_result = 0U;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_reg = 0U;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__a_reg = 0U;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__b_reg = 0U;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__token_pipe = 0U;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__weight_pipe = 0U;
    } else {
        __Vdly__layer_top__DOT__u_layer_ctrl__DOT__compute_pipe 
            = ((6U & ((IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__compute_pipe) 
                      << 1U)) | (1U == (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state)));
        __Vdly__layer_top__DOT__u_layer_ctrl__DOT__eov_pipe 
            = ((0x7eU & ((IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__eov_pipe) 
                         << 1U)) | ((1U == (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state)) 
                                    & (0xfU == (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__vec_cnt))));
        if ((2U & (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state))) {
            if ((1U & (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state))) {
                vlSelf->busy = 0U;
                if ((1U & (~ (IData)(vlSelf->start)))) {
                    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__state = 0U;
                }
            } else {
                vlSelf->layer_top__DOT__tok_rd_en = 0U;
                vlSelf->layer_top__DOT__wgt_rd_en = 0U;
                vlSelf->layer_top__DOT__res_wr_en = 0U;
                if ((7U == (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt))) {
                    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__state = 3U;
                } else {
                    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt 
                        = (7U & ((IData)(1U) + (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt)));
                    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__state = 1U;
                    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__vec_cnt = 0U;
                    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__rd_addr_reg = 0U;
                    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__sum_reg = 0U;
                }
            }
        } else if ((1U & (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state))) {
            vlSelf->layer_top__DOT__tok_rd_en = 1U;
            vlSelf->layer_top__DOT__wgt_rd_en = 1U;
            vlSelf->layer_top__DOT__u_layer_ctrl__DOT__rd_addr_reg 
                = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__vec_cnt;
            if (vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_valid) {
                if ((0x40U & (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__eov_pipe))) {
                    vlSelf->layer_top__DOT__res_wr_en = 1U;
                    vlSelf->layer_top__DOT__res_wr_data 
                        = (vlSelf->layer_top__DOT__u_layer_ctrl__DOT__sum_reg 
                           + vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_acc_out);
                    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__state = 2U;
                    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__sum_reg = 0U;
                } else {
                    __Vdly__layer_top__DOT__u_layer_ctrl__DOT__sum_reg 
                        = (vlSelf->layer_top__DOT__u_layer_ctrl__DOT__sum_reg 
                           + vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_acc_out);
                }
            }
            __Vdly__layer_top__DOT__u_layer_ctrl__DOT__vec_cnt 
                = ((0xfU == (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__vec_cnt))
                    ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__vec_cnt))));
        } else {
            vlSelf->busy = 0U;
            if (vlSelf->start) {
                vlSelf->busy = 1U;
                __Vdly__layer_top__DOT__u_layer_ctrl__DOT__state = 1U;
                __Vdly__layer_top__DOT__u_layer_ctrl__DOT__vec_cnt = 0U;
                __Vdly__layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt = 0U;
                vlSelf->layer_top__DOT__u_layer_ctrl__DOT__rd_addr_reg = 0U;
                __Vdly__layer_top__DOT__u_layer_ctrl__DOT__sum_reg = 0U;
            }
        }
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_acc_out 
            = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__result;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__result 
            = (vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_stage2 
               + VL_SHIFTRS_III(32,32,32, vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__mult_result, 0xaU));
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_stage2 
            = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_reg;
        vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__mult_result 
            = VL_MULS_III(32, VL_EXTENDS_II(32,16, (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__a_reg)), 
                          VL_EXTENDS_II(32,16, (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__b_reg)));
        if ((4U & (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__compute_pipe))) {
            vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_reg = 0U;
            vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__a_reg 
                = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__token_pipe;
            vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__b_reg 
                = vlSelf->layer_top__DOT__u_layer_ctrl__DOT__weight_pipe;
        }
        if ((1U == (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state))) {
            vlSelf->layer_top__DOT__u_layer_ctrl__DOT__token_pipe 
                = vlSelf->layer_top__DOT__tok_rd_data;
            vlSelf->layer_top__DOT__u_layer_ctrl__DOT__weight_pipe 
                = vlSelf->layer_top__DOT__wgt_rd_data;
        }
    }
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__sum_reg 
        = __Vdly__layer_top__DOT__u_layer_ctrl__DOT__sum_reg;
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__vec_cnt 
        = __Vdly__layer_top__DOT__u_layer_ctrl__DOT__vec_cnt;
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__eov_pipe 
        = __Vdly__layer_top__DOT__u_layer_ctrl__DOT__eov_pipe;
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt 
        = __Vdly__layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt;
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_valid 
        = ((1U & (~ (IData)(vlSelf->rst))) && (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage3_valid));
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage3_valid 
        = ((1U & (~ (IData)(vlSelf->rst))) && (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage2_valid));
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage2_valid 
        = ((1U & (~ (IData)(vlSelf->rst))) && (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage1_valid));
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage1_valid 
        = ((1U & (~ (IData)(vlSelf->rst))) && (1U & 
                                               ((IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__compute_pipe) 
                                                >> 2U)));
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__compute_pipe 
        = __Vdly__layer_top__DOT__u_layer_ctrl__DOT__compute_pipe;
    vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state 
        = __Vdly__layer_top__DOT__u_layer_ctrl__DOT__state;
    vlSelf->done = (3U == (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state));
}

VL_INLINE_OPT void Vlayer_top___024root___nba_sequent__TOP__2(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->layer_top__DOT__tok_rd_data = vlSelf->__Vdly__layer_top__DOT__tok_rd_data;
    vlSelf->layer_top__DOT__wgt_rd_data = vlSelf->__Vdly__layer_top__DOT__wgt_rd_data;
}

void Vlayer_top___024root___eval_nba(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vlayer_top___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vlayer_top___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vlayer_top___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vlayer_top___024root___eval_triggers__act(Vlayer_top___024root* vlSelf);

bool Vlayer_top___024root___eval_phase__act(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vlayer_top___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vlayer_top___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vlayer_top___024root___eval_phase__nba(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vlayer_top___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlayer_top___024root___dump_triggers__nba(Vlayer_top___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vlayer_top___024root___dump_triggers__act(Vlayer_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vlayer_top___024root___eval(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vlayer_top___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/layer_top.sv", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vlayer_top___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/layer_top.sv", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vlayer_top___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vlayer_top___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vlayer_top___024root___eval_debug_assertions(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->start & 0xfeU))) {
        Verilated::overWidthError("start");}
    if (VL_UNLIKELY((vlSelf->token_wr_en & 0xfeU))) {
        Verilated::overWidthError("token_wr_en");}
    if (VL_UNLIKELY((vlSelf->token_wr_addr & 0xfc00U))) {
        Verilated::overWidthError("token_wr_addr");}
    if (VL_UNLIKELY((vlSelf->weight_wr_en & 0xfeU))) {
        Verilated::overWidthError("weight_wr_en");}
    if (VL_UNLIKELY((vlSelf->weight_wr_addr & 0xfc00U))) {
        Verilated::overWidthError("weight_wr_addr");}
    if (VL_UNLIKELY((vlSelf->result_rd_en & 0xfeU))) {
        Verilated::overWidthError("result_rd_en");}
    if (VL_UNLIKELY((vlSelf->result_rd_addr & 0xfc00U))) {
        Verilated::overWidthError("result_rd_addr");}
}
#endif  // VL_DEBUG
