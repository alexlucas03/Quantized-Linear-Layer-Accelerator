// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlayer_top.h for the primary calling header

#include "Vlayer_top__pch.h"
#include "Vlayer_top__Syms.h"
#include "Vlayer_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlayer_top___024root___dump_triggers__act(Vlayer_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vlayer_top___024root___eval_triggers__act(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__VactTriggered.set(1U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((IData)(vlSelf->rst) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__rst__0)))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vlayer_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
