// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlayer_top.h for the primary calling header

#include "Vlayer_top__pch.h"
#include "Vlayer_top__Syms.h"
#include "Vlayer_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlayer_top___024root___dump_triggers__stl(Vlayer_top___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vlayer_top___024root___eval_triggers__stl(Vlayer_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlayer_top___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vlayer_top___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
