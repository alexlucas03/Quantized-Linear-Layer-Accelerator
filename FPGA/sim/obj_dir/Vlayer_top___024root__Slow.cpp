// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlayer_top.h for the primary calling header

#include "Vlayer_top__pch.h"
#include "Vlayer_top__Syms.h"
#include "Vlayer_top___024root.h"

void Vlayer_top___024root___ctor_var_reset(Vlayer_top___024root* vlSelf);

Vlayer_top___024root::Vlayer_top___024root(Vlayer_top__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vlayer_top___024root___ctor_var_reset(this);
}

void Vlayer_top___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vlayer_top___024root::~Vlayer_top___024root() {
}
