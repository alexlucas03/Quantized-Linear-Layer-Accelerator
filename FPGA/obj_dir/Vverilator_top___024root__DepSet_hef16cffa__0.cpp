// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "Vverilator_top__pch.h"
#include "Vverilator_top__Syms.h"
#include "Vverilator_top___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vverilator_top___024root___dump_triggers__act(Vverilator_top___024root* vlSelf);
#endif  // VL_DEBUG

void Vverilator_top___024root___eval_triggers__act(Vverilator_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((IData)(vlSelf->rst) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__rst__0)))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__VactTriggered.set(2U, ((IData)(vlSelf->tb_mac_unit__DOT__clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_mac_unit__DOT__clk__0))));
    vlSelf->__VactTriggered.set(3U, (((IData)(vlSelf->tb_mac_unit__DOT__clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_mac_unit__DOT__clk__0))) 
                                     | ((IData)(vlSelf->tb_mac_unit__DOT__rst) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__tb_mac_unit__DOT__rst__0)))));
    vlSelf->__VactTriggered.set(4U, vlSelf->__VdlySched.awaitingCurrentTime());
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = vlSelf->rst;
    vlSelf->__Vtrigprevexpr___TOP__tb_mac_unit__DOT__clk__0 
        = vlSelf->tb_mac_unit__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_mac_unit__DOT__rst__0 
        = vlSelf->tb_mac_unit__DOT__rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vverilator_top___024root___dump_triggers__act(vlSelf);
    }
#endif
}
