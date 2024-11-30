// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vethernet_receiver__Syms.h"


void Vethernet_receiver___024root__trace_chg_sub_0(Vethernet_receiver___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vethernet_receiver___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root__trace_chg_top_0\n"); );
    // Init
    Vethernet_receiver___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vethernet_receiver___024root*>(voidSelf);
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vethernet_receiver___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vethernet_receiver___024root__trace_chg_sub_0(Vethernet_receiver___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgBit(oldp+0,(vlSelf->ethernet_uart_debug__DOT__send_byte));
        bufp->chgCData(oldp+1,(vlSelf->ethernet_uart_debug__DOT__byte_to_send),8);
        bufp->chgCData(oldp+2,(vlSelf->ethernet_uart_debug__DOT__state),2);
        bufp->chgCData(oldp+3,(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__state),3);
        bufp->chgSData(oldp+4,(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count),9);
        bufp->chgCData(oldp+5,(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__bit_index),3);
        bufp->chgCData(oldp+6,(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__data_reg),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgIData(oldp+7,(vlSelf->ethernet_receiver__DOT__crc_reg),32);
        bufp->chgBit(oldp+8,(vlSelf->ethernet_receiver__DOT__crc_init));
        bufp->chgBit(oldp+9,(vlSelf->ethernet_receiver__DOT__crc_calc));
        bufp->chgCData(oldp+10,(vlSelf->ethernet_receiver__DOT__state),4);
        bufp->chgSData(oldp+11,(vlSelf->ethernet_receiver__DOT__byte_count),16);
        bufp->chgCData(oldp+12,(vlSelf->ethernet_receiver__DOT__preamble_count),3);
    }
    bufp->chgBit(oldp+13,(vlSelf->ethernet_receiver__02Eclk));
    bufp->chgBit(oldp+14,(vlSelf->ethernet_receiver__02Erst_n));
    bufp->chgBit(oldp+15,(vlSelf->rx_dv));
    bufp->chgCData(oldp+16,(vlSelf->rxd),8);
    bufp->chgCData(oldp+17,(vlSelf->ethernet_receiver__02Erx_data),8);
    bufp->chgBit(oldp+18,(vlSelf->ethernet_receiver__02Erx_data_valid));
    bufp->chgBit(oldp+19,(vlSelf->ethernet_receiver__02Eframe_start));
    bufp->chgBit(oldp+20,(vlSelf->ethernet_receiver__02Eframe_end));
    bufp->chgSData(oldp+21,(vlSelf->frame_length),16);
    bufp->chgBit(oldp+22,(vlSelf->frame_valid));
    bufp->chgBit(oldp+23,(vlSelf->frame_error));
    bufp->chgBit(oldp+24,(vlSelf->ethernet_uart_debug__02Eclk));
    bufp->chgBit(oldp+25,(vlSelf->ethernet_uart_debug__02Erst_n));
    bufp->chgBit(oldp+26,(vlSelf->ethernet_uart_debug__02Erx_data_valid));
    bufp->chgCData(oldp+27,(vlSelf->ethernet_uart_debug__02Erx_data),8);
    bufp->chgBit(oldp+28,(vlSelf->ethernet_uart_debug__02Eframe_start));
    bufp->chgBit(oldp+29,(vlSelf->ethernet_uart_debug__02Eframe_end));
    bufp->chgBit(oldp+30,(vlSelf->uart_tx));
    bufp->chgBit(oldp+31,(vlSelf->tx_busy));
}

void Vethernet_receiver___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root__trace_cleanup\n"); );
    // Init
    Vethernet_receiver___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vethernet_receiver___024root*>(voidSelf);
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
