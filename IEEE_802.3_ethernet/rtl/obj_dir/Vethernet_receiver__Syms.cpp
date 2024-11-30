// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vethernet_receiver__Syms.h"
#include "Vethernet_receiver.h"
#include "Vethernet_receiver___024root.h"

// FUNCTIONS
Vethernet_receiver__Syms::~Vethernet_receiver__Syms()
{
}

Vethernet_receiver__Syms::Vethernet_receiver__Syms(VerilatedContext* contextp, const char* namep, Vethernet_receiver* modelp)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    // Setup module instances
    , TOP{this, namep}
{
    // Configure time unit / time precision
    _vm_contextp__->timeunit(-12);
    _vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOP.__Vconfigure(true);
}
