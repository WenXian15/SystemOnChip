// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vethernet_receiver.h for the primary calling header

#include "verilated.h"

#include "Vethernet_receiver__Syms.h"
#include "Vethernet_receiver___024root.h"

void Vethernet_receiver___024root___ctor_var_reset(Vethernet_receiver___024root* vlSelf);

Vethernet_receiver___024root::Vethernet_receiver___024root(Vethernet_receiver__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vethernet_receiver___024root___ctor_var_reset(this);
}

void Vethernet_receiver___024root::__Vconfigure(bool first) {
    if (false && first) {}  // Prevent unused
}

Vethernet_receiver___024root::~Vethernet_receiver___024root() {
}
