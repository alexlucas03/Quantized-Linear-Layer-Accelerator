// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vverilator_top.h for the primary calling header

#include "Vverilator_top__pch.h"
#include "Vverilator_top__Syms.h"
#include "Vverilator_top___024root.h"

void Vverilator_top___024root___ctor_var_reset(Vverilator_top___024root* vlSelf);

Vverilator_top___024root::Vverilator_top___024root(Vverilator_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vverilator_top___024root___ctor_var_reset(this);
}

void Vverilator_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vverilator_top___024root::~Vverilator_top___024root() {
}
