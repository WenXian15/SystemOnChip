// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vethernet_receiver.h for the primary calling header

#include "verilated.h"

#include "Vethernet_receiver___024root.h"

VL_ATTR_COLD void Vethernet_receiver___024root___eval_static(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vethernet_receiver___024root___eval_initial(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigrprev__TOP__ethernet_receiver__02Eclk 
        = vlSelf->ethernet_receiver__02Eclk;
    vlSelf->__Vtrigrprev__TOP__ethernet_receiver__02Erst_n 
        = vlSelf->ethernet_receiver__02Erst_n;
    vlSelf->__Vtrigrprev__TOP__ethernet_uart_debug__02Eclk 
        = vlSelf->ethernet_uart_debug__02Eclk;
    vlSelf->__Vtrigrprev__TOP__ethernet_uart_debug__02Erst_n 
        = vlSelf->ethernet_uart_debug__02Erst_n;
}

VL_ATTR_COLD void Vethernet_receiver___024root___eval_final(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vethernet_receiver___024root___eval_settle(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___eval_settle\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vethernet_receiver___024root___dump_triggers__act(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge ethernet_receiver.clk or negedge ethernet_receiver.rst_n)\n");
    }
    if (vlSelf->__VactTriggered.at(1U)) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge ethernet_uart_debug.clk or negedge ethernet_uart_debug.rst_n)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vethernet_receiver___024root___dump_triggers__nba(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge ethernet_receiver.clk or negedge ethernet_receiver.rst_n)\n");
    }
    if (vlSelf->__VnbaTriggered.at(1U)) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge ethernet_uart_debug.clk or negedge ethernet_uart_debug.rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vethernet_receiver___024root___ctor_var_reset(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->ethernet_receiver__02Eclk = VL_RAND_RESET_I(1);
    vlSelf->ethernet_receiver__02Erst_n = VL_RAND_RESET_I(1);
    vlSelf->rx_dv = VL_RAND_RESET_I(1);
    vlSelf->rxd = VL_RAND_RESET_I(8);
    vlSelf->ethernet_receiver__02Erx_data = VL_RAND_RESET_I(8);
    vlSelf->ethernet_receiver__02Erx_data_valid = VL_RAND_RESET_I(1);
    vlSelf->ethernet_receiver__02Eframe_start = VL_RAND_RESET_I(1);
    vlSelf->ethernet_receiver__02Eframe_end = VL_RAND_RESET_I(1);
    vlSelf->frame_length = VL_RAND_RESET_I(16);
    vlSelf->frame_valid = VL_RAND_RESET_I(1);
    vlSelf->frame_error = VL_RAND_RESET_I(1);
    vlSelf->ethernet_uart_debug__02Eclk = VL_RAND_RESET_I(1);
    vlSelf->ethernet_uart_debug__02Erst_n = VL_RAND_RESET_I(1);
    vlSelf->ethernet_uart_debug__02Erx_data_valid = VL_RAND_RESET_I(1);
    vlSelf->ethernet_uart_debug__02Erx_data = VL_RAND_RESET_I(8);
    vlSelf->ethernet_uart_debug__02Eframe_start = VL_RAND_RESET_I(1);
    vlSelf->ethernet_uart_debug__02Eframe_end = VL_RAND_RESET_I(1);
    vlSelf->uart_tx = VL_RAND_RESET_I(1);
    vlSelf->tx_busy = VL_RAND_RESET_I(1);
    vlSelf->ethernet_receiver__DOT__crc_reg = VL_RAND_RESET_I(32);
    vlSelf->ethernet_receiver__DOT__crc_next = VL_RAND_RESET_I(32);
    vlSelf->ethernet_receiver__DOT__crc_init = VL_RAND_RESET_I(1);
    vlSelf->ethernet_receiver__DOT__crc_calc = VL_RAND_RESET_I(1);
    vlSelf->ethernet_receiver__DOT__state = VL_RAND_RESET_I(4);
    vlSelf->ethernet_receiver__DOT__byte_count = VL_RAND_RESET_I(16);
    vlSelf->ethernet_receiver__DOT__preamble_count = VL_RAND_RESET_I(3);
    vlSelf->ethernet_uart_debug__DOT__send_byte = VL_RAND_RESET_I(1);
    vlSelf->ethernet_uart_debug__DOT__byte_to_send = VL_RAND_RESET_I(8);
    vlSelf->ethernet_uart_debug__DOT__state = VL_RAND_RESET_I(2);
    vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count = VL_RAND_RESET_I(9);
    vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__bit_index = VL_RAND_RESET_I(3);
    vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__data_reg = VL_RAND_RESET_I(8);
    vlSelf->__Vtrigrprev__TOP__ethernet_receiver__02Eclk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__ethernet_receiver__02Erst_n = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__ethernet_uart_debug__02Eclk = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigrprev__TOP__ethernet_uart_debug__02Erst_n = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
