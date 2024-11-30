// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vethernet_receiver.h for the primary calling header

#include "verilated.h"

#include "Vethernet_receiver__Syms.h"
#include "Vethernet_receiver___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vethernet_receiver___024root___dump_triggers__act(Vethernet_receiver___024root* vlSelf);
#endif  // VL_DEBUG

void Vethernet_receiver___024root___eval_triggers__act(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.at(0U) = (((IData)(vlSelf->ethernet_receiver__02Eclk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__ethernet_receiver__02Eclk))) 
                                      | ((~ (IData)(vlSelf->ethernet_receiver__02Erst_n)) 
                                         & (IData)(vlSelf->__Vtrigrprev__TOP__ethernet_receiver__02Erst_n)));
    vlSelf->__VactTriggered.at(1U) = (((IData)(vlSelf->ethernet_uart_debug__02Eclk) 
                                       & (~ (IData)(vlSelf->__Vtrigrprev__TOP__ethernet_uart_debug__02Eclk))) 
                                      | ((~ (IData)(vlSelf->ethernet_uart_debug__02Erst_n)) 
                                         & (IData)(vlSelf->__Vtrigrprev__TOP__ethernet_uart_debug__02Erst_n)));
    vlSelf->__Vtrigrprev__TOP__ethernet_receiver__02Eclk 
        = vlSelf->ethernet_receiver__02Eclk;
    vlSelf->__Vtrigrprev__TOP__ethernet_receiver__02Erst_n 
        = vlSelf->ethernet_receiver__02Erst_n;
    vlSelf->__Vtrigrprev__TOP__ethernet_uart_debug__02Eclk 
        = vlSelf->ethernet_uart_debug__02Eclk;
    vlSelf->__Vtrigrprev__TOP__ethernet_uart_debug__02Erst_n 
        = vlSelf->ethernet_uart_debug__02Erst_n;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vethernet_receiver___024root___dump_triggers__act(vlSelf);
    }
#endif
}
