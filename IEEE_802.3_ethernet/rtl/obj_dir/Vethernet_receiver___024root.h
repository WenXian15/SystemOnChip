// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vethernet_receiver.h for the primary calling header

#ifndef VERILATED_VETHERNET_RECEIVER___024ROOT_H_
#define VERILATED_VETHERNET_RECEIVER___024ROOT_H_  // guard

#include "verilated.h"

class Vethernet_receiver__Syms;

class Vethernet_receiver___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(ethernet_receiver__02Eclk,0,0);
    VL_IN8(ethernet_receiver__02Erst_n,0,0);
    VL_IN8(ethernet_uart_debug__02Eclk,0,0);
    VL_IN8(ethernet_uart_debug__02Erst_n,0,0);
    VL_IN8(rx_dv,0,0);
    VL_IN8(rxd,7,0);
    VL_OUT8(ethernet_receiver__02Erx_data,7,0);
    VL_OUT8(ethernet_receiver__02Erx_data_valid,0,0);
    VL_OUT8(ethernet_receiver__02Eframe_start,0,0);
    VL_OUT8(ethernet_receiver__02Eframe_end,0,0);
    VL_OUT8(frame_valid,0,0);
    VL_OUT8(frame_error,0,0);
    VL_IN8(ethernet_uart_debug__02Erx_data_valid,0,0);
    VL_IN8(ethernet_uart_debug__02Erx_data,7,0);
    VL_IN8(ethernet_uart_debug__02Eframe_start,0,0);
    VL_IN8(ethernet_uart_debug__02Eframe_end,0,0);
    VL_OUT8(uart_tx,0,0);
    VL_OUT8(tx_busy,0,0);
    CData/*0:0*/ ethernet_receiver__DOT__crc_init;
    CData/*0:0*/ ethernet_receiver__DOT__crc_calc;
    CData/*3:0*/ ethernet_receiver__DOT__state;
    CData/*2:0*/ ethernet_receiver__DOT__preamble_count;
    CData/*0:0*/ ethernet_uart_debug__DOT__send_byte;
    CData/*7:0*/ ethernet_uart_debug__DOT__byte_to_send;
    CData/*1:0*/ ethernet_uart_debug__DOT__state;
    CData/*2:0*/ ethernet_uart_debug__DOT__uart_tx_inst__DOT__state;
    CData/*2:0*/ ethernet_uart_debug__DOT__uart_tx_inst__DOT__bit_index;
    CData/*7:0*/ ethernet_uart_debug__DOT__uart_tx_inst__DOT__data_reg;
    CData/*0:0*/ __Vtrigrprev__TOP__ethernet_receiver__02Eclk;
    CData/*0:0*/ __Vtrigrprev__TOP__ethernet_receiver__02Erst_n;
    CData/*0:0*/ __Vtrigrprev__TOP__ethernet_uart_debug__02Eclk;
    CData/*0:0*/ __Vtrigrprev__TOP__ethernet_uart_debug__02Erst_n;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(frame_length,15,0);
    SData/*15:0*/ ethernet_receiver__DOT__byte_count;
    SData/*8:0*/ ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count;
    IData/*31:0*/ ethernet_receiver__DOT__crc_reg;
    IData/*31:0*/ ethernet_receiver__DOT__crc_next;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vethernet_receiver__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vethernet_receiver___024root(Vethernet_receiver__Syms* symsp, const char* v__name);
    ~Vethernet_receiver___024root();
    VL_UNCOPYABLE(Vethernet_receiver___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
