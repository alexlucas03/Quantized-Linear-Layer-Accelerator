// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vlayer_top__Syms.h"


void Vlayer_top___024root__trace_chg_0_sub_0(Vlayer_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vlayer_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root__trace_chg_0\n"); );
    // Init
    Vlayer_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlayer_top___024root*>(voidSelf);
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vlayer_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vlayer_top___024root__trace_chg_0_sub_0(Vlayer_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->layer_top__DOT__tok_rd_en));
        bufp->chgSData(oldp+1,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__rd_addr_reg),10);
        bufp->chgBit(oldp+2,(vlSelf->layer_top__DOT__wgt_rd_en));
        bufp->chgSData(oldp+3,((((IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt) 
                                 << 4U) | (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__rd_addr_reg))),10);
        bufp->chgBit(oldp+4,(vlSelf->layer_top__DOT__res_wr_en));
        bufp->chgSData(oldp+5,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt),10);
        bufp->chgIData(oldp+6,(vlSelf->layer_top__DOT__res_wr_data),32);
        bufp->chgCData(oldp+7,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__state),2);
        bufp->chgCData(oldp+8,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__vec_cnt),4);
        bufp->chgCData(oldp+9,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt),3);
        bufp->chgCData(oldp+10,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__rd_addr_reg),4);
        bufp->chgCData(oldp+11,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__compute_pipe),3);
        bufp->chgCData(oldp+12,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__eov_pipe),7);
        bufp->chgBit(oldp+13,((1U & ((IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__compute_pipe) 
                                     >> 2U))));
        bufp->chgBit(oldp+14,((((IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__eov_pipe) 
                                >> 6U) & (IData)(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_valid))));
        bufp->chgSData(oldp+15,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__token_pipe),16);
        bufp->chgSData(oldp+16,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__weight_pipe),16);
        bufp->chgIData(oldp+17,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_acc_out),32);
        bufp->chgBit(oldp+18,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_valid));
        bufp->chgIData(oldp+19,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__sum_reg),32);
        bufp->chgSData(oldp+20,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__a_reg),16);
        bufp->chgSData(oldp+21,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__b_reg),16);
        bufp->chgIData(oldp+22,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_reg),32);
        bufp->chgBit(oldp+23,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage1_valid));
        bufp->chgIData(oldp+24,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__mult_result),32);
        bufp->chgIData(oldp+25,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_stage2),32);
        bufp->chgBit(oldp+26,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage2_valid));
        bufp->chgIData(oldp+27,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__result),32);
        bufp->chgBit(oldp+28,(vlSelf->layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage3_valid));
    }
    bufp->chgBit(oldp+29,(vlSelf->clk));
    bufp->chgBit(oldp+30,(vlSelf->rst));
    bufp->chgBit(oldp+31,(vlSelf->start));
    bufp->chgBit(oldp+32,(vlSelf->token_wr_en));
    bufp->chgSData(oldp+33,(vlSelf->token_wr_addr),10);
    bufp->chgSData(oldp+34,(vlSelf->token_wr_data),16);
    bufp->chgBit(oldp+35,(vlSelf->weight_wr_en));
    bufp->chgSData(oldp+36,(vlSelf->weight_wr_addr),10);
    bufp->chgSData(oldp+37,(vlSelf->weight_wr_data),16);
    bufp->chgBit(oldp+38,(vlSelf->result_rd_en));
    bufp->chgSData(oldp+39,(vlSelf->result_rd_addr),10);
    bufp->chgIData(oldp+40,(vlSelf->result_rd_data),32);
    bufp->chgBit(oldp+41,(vlSelf->busy));
    bufp->chgBit(oldp+42,(vlSelf->done));
    bufp->chgSData(oldp+43,(vlSelf->layer_top__DOT__tok_rd_data),16);
    bufp->chgSData(oldp+44,(vlSelf->layer_top__DOT__wgt_rd_data),16);
}

void Vlayer_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root__trace_cleanup\n"); );
    // Init
    Vlayer_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlayer_top___024root*>(voidSelf);
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
