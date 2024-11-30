// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vethernet_receiver__Syms.h"


VL_ATTR_COLD void Vethernet_receiver___024root__trace_init_sub__TOP__0(Vethernet_receiver___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+14,"ethernet_receiver.clk", false,-1);
    tracep->declBit(c+15,"ethernet_receiver.rst_n", false,-1);
    tracep->declBit(c+16,"rx_dv", false,-1);
    tracep->declBus(c+17,"rxd", false,-1, 7,0);
    tracep->declBus(c+18,"ethernet_receiver.rx_data", false,-1, 7,0);
    tracep->declBit(c+19,"ethernet_receiver.rx_data_valid", false,-1);
    tracep->declBit(c+20,"ethernet_receiver.frame_start", false,-1);
    tracep->declBit(c+21,"ethernet_receiver.frame_end", false,-1);
    tracep->declBus(c+22,"frame_length", false,-1, 15,0);
    tracep->declBit(c+23,"frame_valid", false,-1);
    tracep->declBit(c+24,"frame_error", false,-1);
    tracep->declBit(c+25,"ethernet_uart_debug.clk", false,-1);
    tracep->declBit(c+26,"ethernet_uart_debug.rst_n", false,-1);
    tracep->declBit(c+27,"ethernet_uart_debug.rx_data_valid", false,-1);
    tracep->declBus(c+28,"ethernet_uart_debug.rx_data", false,-1, 7,0);
    tracep->declBit(c+29,"ethernet_uart_debug.frame_start", false,-1);
    tracep->declBit(c+30,"ethernet_uart_debug.frame_end", false,-1);
    tracep->declBit(c+31,"uart_tx", false,-1);
    tracep->declBit(c+32,"tx_busy", false,-1);
    tracep->pushNamePrefix("ethernet_receiver ");
    tracep->declBus(c+33,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBus(c+34,"ENABLE_CRC", false,-1, 31,0);
    tracep->declBus(c+35,"MIN_FRAME_LEN", false,-1, 31,0);
    tracep->declBus(c+36,"MAX_FRAME_LEN", false,-1, 31,0);
    tracep->declBit(c+14,"clk", false,-1);
    tracep->declBit(c+15,"rst_n", false,-1);
    tracep->declBit(c+16,"rx_dv", false,-1);
    tracep->declBus(c+17,"rxd", false,-1, 7,0);
    tracep->declBus(c+18,"rx_data", false,-1, 7,0);
    tracep->declBit(c+19,"rx_data_valid", false,-1);
    tracep->declBit(c+20,"frame_start", false,-1);
    tracep->declBit(c+21,"frame_end", false,-1);
    tracep->declBus(c+22,"frame_length", false,-1, 15,0);
    tracep->declBit(c+23,"frame_valid", false,-1);
    tracep->declBit(c+24,"frame_error", false,-1);
    tracep->declBus(c+37,"IDLE", false,-1, 3,0);
    tracep->declBus(c+38,"PREAMBLE", false,-1, 3,0);
    tracep->declBus(c+39,"SFD", false,-1, 3,0);
    tracep->declBus(c+40,"DATA", false,-1, 3,0);
    tracep->declBus(c+41,"CHECK_CRC", false,-1, 3,0);
    tracep->declBus(c+42,"WAIT_END", false,-1, 3,0);
    tracep->declBus(c+43,"PREAMBLE_BYTE", false,-1, 7,0);
    tracep->declBus(c+44,"SFD_BYTE", false,-1, 7,0);
    tracep->declBus(c+8,"crc_reg", false,-1, 31,0);
    tracep->declBus(c+45,"crc_next", false,-1, 31,0);
    tracep->declBit(c+9,"crc_init", false,-1);
    tracep->declBit(c+10,"crc_calc", false,-1);
    tracep->declBus(c+11,"state", false,-1, 3,0);
    tracep->declBus(c+12,"byte_count", false,-1, 15,0);
    tracep->declBus(c+13,"preamble_count", false,-1, 2,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("ethernet_uart_debug ");
    tracep->declBit(c+25,"clk", false,-1);
    tracep->declBit(c+26,"rst_n", false,-1);
    tracep->declBit(c+27,"rx_data_valid", false,-1);
    tracep->declBus(c+28,"rx_data", false,-1, 7,0);
    tracep->declBit(c+29,"frame_start", false,-1);
    tracep->declBit(c+30,"frame_end", false,-1);
    tracep->declBit(c+31,"uart_tx", false,-1);
    tracep->declBit(c+32,"tx_busy", false,-1);
    tracep->declBit(c+1,"send_byte", false,-1);
    tracep->declBus(c+2,"byte_to_send", false,-1, 7,0);
    tracep->declBus(c+46,"FRAME_START_MARKER", false,-1, 7,0);
    tracep->declBus(c+47,"FRAME_END_MARKER", false,-1, 7,0);
    tracep->declBus(c+48,"WAIT_DATA", false,-1, 1,0);
    tracep->declBus(c+49,"SEND_MARKER", false,-1, 1,0);
    tracep->declBus(c+50,"SEND_DATA", false,-1, 1,0);
    tracep->declBus(c+3,"state", false,-1, 1,0);
    tracep->pushNamePrefix("uart_tx_inst ");
    tracep->declBus(c+51,"CLKS_PER_BIT", false,-1, 31,0);
    tracep->declBit(c+25,"clk", false,-1);
    tracep->declBit(c+26,"rst_n", false,-1);
    tracep->declBus(c+2,"data_in", false,-1, 7,0);
    tracep->declBit(c+1,"data_valid", false,-1);
    tracep->declBit(c+32,"tx_busy", false,-1);
    tracep->declBit(c+31,"uart_tx", false,-1);
    tracep->declBus(c+48,"IDLE", false,-1, 1,0);
    tracep->declBus(c+49,"START_BIT", false,-1, 1,0);
    tracep->declBus(c+50,"DATA_BITS", false,-1, 1,0);
    tracep->declBus(c+52,"STOP_BIT", false,-1, 1,0);
    tracep->declBus(c+4,"state", false,-1, 2,0);
    tracep->declBus(c+5,"clock_count", false,-1, 8,0);
    tracep->declBus(c+6,"bit_index", false,-1, 2,0);
    tracep->declBus(c+7,"data_reg", false,-1, 7,0);
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vethernet_receiver___024root__trace_init_top(Vethernet_receiver___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root__trace_init_top\n"); );
    // Body
    Vethernet_receiver___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vethernet_receiver___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vethernet_receiver___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vethernet_receiver___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vethernet_receiver___024root__trace_register(Vethernet_receiver___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vethernet_receiver___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vethernet_receiver___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vethernet_receiver___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vethernet_receiver___024root__trace_full_sub_0(Vethernet_receiver___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vethernet_receiver___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root__trace_full_top_0\n"); );
    // Init
    Vethernet_receiver___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vethernet_receiver___024root*>(voidSelf);
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vethernet_receiver___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vethernet_receiver___024root__trace_full_sub_0(Vethernet_receiver___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->ethernet_uart_debug__DOT__send_byte));
    bufp->fullCData(oldp+2,(vlSelf->ethernet_uart_debug__DOT__byte_to_send),8);
    bufp->fullCData(oldp+3,(vlSelf->ethernet_uart_debug__DOT__state),2);
    bufp->fullCData(oldp+4,(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__state),3);
    bufp->fullSData(oldp+5,(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count),9);
    bufp->fullCData(oldp+6,(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__bit_index),3);
    bufp->fullCData(oldp+7,(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__data_reg),8);
    bufp->fullIData(oldp+8,(vlSelf->ethernet_receiver__DOT__crc_reg),32);
    bufp->fullBit(oldp+9,(vlSelf->ethernet_receiver__DOT__crc_init));
    bufp->fullBit(oldp+10,(vlSelf->ethernet_receiver__DOT__crc_calc));
    bufp->fullCData(oldp+11,(vlSelf->ethernet_receiver__DOT__state),4);
    bufp->fullSData(oldp+12,(vlSelf->ethernet_receiver__DOT__byte_count),16);
    bufp->fullCData(oldp+13,(vlSelf->ethernet_receiver__DOT__preamble_count),3);
    bufp->fullBit(oldp+14,(vlSelf->ethernet_receiver__02Eclk));
    bufp->fullBit(oldp+15,(vlSelf->ethernet_receiver__02Erst_n));
    bufp->fullBit(oldp+16,(vlSelf->rx_dv));
    bufp->fullCData(oldp+17,(vlSelf->rxd),8);
    bufp->fullCData(oldp+18,(vlSelf->ethernet_receiver__02Erx_data),8);
    bufp->fullBit(oldp+19,(vlSelf->ethernet_receiver__02Erx_data_valid));
    bufp->fullBit(oldp+20,(vlSelf->ethernet_receiver__02Eframe_start));
    bufp->fullBit(oldp+21,(vlSelf->ethernet_receiver__02Eframe_end));
    bufp->fullSData(oldp+22,(vlSelf->frame_length),16);
    bufp->fullBit(oldp+23,(vlSelf->frame_valid));
    bufp->fullBit(oldp+24,(vlSelf->frame_error));
    bufp->fullBit(oldp+25,(vlSelf->ethernet_uart_debug__02Eclk));
    bufp->fullBit(oldp+26,(vlSelf->ethernet_uart_debug__02Erst_n));
    bufp->fullBit(oldp+27,(vlSelf->ethernet_uart_debug__02Erx_data_valid));
    bufp->fullCData(oldp+28,(vlSelf->ethernet_uart_debug__02Erx_data),8);
    bufp->fullBit(oldp+29,(vlSelf->ethernet_uart_debug__02Eframe_start));
    bufp->fullBit(oldp+30,(vlSelf->ethernet_uart_debug__02Eframe_end));
    bufp->fullBit(oldp+31,(vlSelf->uart_tx));
    bufp->fullBit(oldp+32,(vlSelf->tx_busy));
    bufp->fullIData(oldp+33,(8U),32);
    bufp->fullIData(oldp+34,(1U),32);
    bufp->fullIData(oldp+35,(0x40U),32);
    bufp->fullIData(oldp+36,(0x5eeU),32);
    bufp->fullCData(oldp+37,(0U),4);
    bufp->fullCData(oldp+38,(1U),4);
    bufp->fullCData(oldp+39,(2U),4);
    bufp->fullCData(oldp+40,(3U),4);
    bufp->fullCData(oldp+41,(4U),4);
    bufp->fullCData(oldp+42,(5U),4);
    bufp->fullCData(oldp+43,(0x55U),8);
    bufp->fullCData(oldp+44,(0xd5U),8);
    bufp->fullIData(oldp+45,(vlSelf->ethernet_receiver__DOT__crc_next),32);
    bufp->fullCData(oldp+46,(0xf8U),8);
    bufp->fullCData(oldp+47,(0xf9U),8);
    bufp->fullCData(oldp+48,(0U),2);
    bufp->fullCData(oldp+49,(1U),2);
    bufp->fullCData(oldp+50,(2U),2);
    bufp->fullIData(oldp+51,(0x36U),32);
    bufp->fullCData(oldp+52,(3U),2);
}
