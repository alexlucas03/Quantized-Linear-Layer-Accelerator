// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlayer_top.h for the primary calling header

#ifndef VERILATED_VLAYER_TOP___024ROOT_H_
#define VERILATED_VLAYER_TOP___024ROOT_H_  // guard

#include "verilated.h"


class Vlayer_top__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vlayer_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(start,0,0);
    VL_IN8(token_wr_en,0,0);
    VL_IN8(weight_wr_en,0,0);
    VL_IN8(result_rd_en,0,0);
    VL_OUT8(busy,0,0);
    VL_OUT8(done,0,0);
    CData/*0:0*/ layer_top__DOT__u_layer_ctrl__DOT__running;
    CData/*3:0*/ layer_top__DOT__u_layer_ctrl__DOT__read_cnt;
    CData/*3:0*/ layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt;
    CData/*2:0*/ layer_top__DOT__u_layer_ctrl__DOT__start_pipe;
    CData/*6:0*/ layer_top__DOT__u_layer_ctrl__DOT__eov_pipe;
    CData/*0:0*/ layer_top__DOT__u_layer_ctrl__DOT__eov_valid;
    CData/*0:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_valid;
    CData/*0:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage1_valid;
    CData/*0:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage2_valid;
    CData/*0:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__stage3_valid;
    CData/*0:0*/ __Vdlyvset__layer_top__DOT__token_mem__DOT__mem__v0;
    CData/*0:0*/ __Vdlyvset__layer_top__DOT__weight_mem__DOT__mem__v0;
    CData/*0:0*/ __Vdly__layer_top__DOT__u_layer_ctrl__DOT__running;
    CData/*3:0*/ __Vdly__layer_top__DOT__u_layer_ctrl__DOT__read_cnt;
    CData/*3:0*/ __Vdly__layer_top__DOT__u_layer_ctrl__DOT__neuron_cnt;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN16(token_wr_addr,9,0);
    VL_IN16(token_wr_data,15,0);
    VL_IN16(weight_wr_addr,9,0);
    VL_IN16(weight_wr_data,15,0);
    VL_IN16(result_rd_addr,9,0);
    SData/*15:0*/ layer_top__DOT__tok_rd_data;
    SData/*15:0*/ layer_top__DOT__wgt_rd_data;
    SData/*15:0*/ layer_top__DOT__u_layer_ctrl__DOT__token_pipe;
    SData/*15:0*/ layer_top__DOT__u_layer_ctrl__DOT__weight_pipe;
    SData/*15:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__a_reg;
    SData/*15:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__b_reg;
    SData/*9:0*/ __Vdlyvdim0__layer_top__DOT__token_mem__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__layer_top__DOT__token_mem__DOT__mem__v0;
    SData/*9:0*/ __Vdlyvdim0__layer_top__DOT__weight_mem__DOT__mem__v0;
    SData/*15:0*/ __Vdlyvval__layer_top__DOT__weight_mem__DOT__mem__v0;
    VL_OUT(result_rd_data,31,0);
    IData/*31:0*/ layer_top__DOT__u_layer_ctrl__DOT__sum_reg;
    IData/*31:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_acc_out;
    IData/*31:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_reg;
    IData/*31:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__mult_result;
    IData/*31:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__acc_stage2;
    IData/*31:0*/ layer_top__DOT__u_layer_ctrl__DOT__mac_i__DOT__result;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<SData/*15:0*/, 1024> layer_top__DOT__token_mem__DOT__mem;
    VlUnpacked<SData/*15:0*/, 1024> layer_top__DOT__weight_mem__DOT__mem;
    VlUnpacked<IData/*31:0*/, 1024> layer_top__DOT__result_mem__DOT__mem;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vlayer_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vlayer_top___024root(Vlayer_top__Syms* symsp, const char* v__name);
    ~Vlayer_top___024root();
    VL_UNCOPYABLE(Vlayer_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
