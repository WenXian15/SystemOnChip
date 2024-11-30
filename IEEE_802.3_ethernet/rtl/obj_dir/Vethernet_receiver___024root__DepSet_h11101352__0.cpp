// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vethernet_receiver.h for the primary calling header

#include "verilated.h"

#include "Vethernet_receiver___024root.h"

void Vethernet_receiver___024root___eval_act(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vethernet_receiver___024root___nba_sequent__TOP__0(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*1:0*/ __Vdly__ethernet_uart_debug__DOT__state;
    __Vdly__ethernet_uart_debug__DOT__state = 0;
    CData/*2:0*/ __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__state;
    __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__state = 0;
    SData/*8:0*/ __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count;
    __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count = 0;
    CData/*0:0*/ __Vdly__tx_busy;
    __Vdly__tx_busy = 0;
    // Body
    __Vdly__ethernet_uart_debug__DOT__state = vlSelf->ethernet_uart_debug__DOT__state;
    __Vdly__tx_busy = vlSelf->tx_busy;
    __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count 
        = vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count;
    __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__state 
        = vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__state;
    if (vlSelf->ethernet_uart_debug__02Erst_n) {
        if ((4U & (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__state))) {
            __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__state = 0U;
        } else if ((2U & (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__state))) {
            if ((1U & (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__state))) {
                vlSelf->uart_tx = 1U;
                if ((0x35U > (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count))) {
                    __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count)));
                } else {
                    __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__state = 0U;
                    __Vdly__tx_busy = 0U;
                }
            } else {
                vlSelf->uart_tx = (1U & ((IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__data_reg) 
                                         >> (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__bit_index)));
                if ((0x35U > (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count))) {
                    __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count 
                        = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count)));
                } else {
                    __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count = 0U;
                    if ((7U > (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__bit_index))) {
                        vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__bit_index 
                            = (7U & ((IData)(1U) + (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__bit_index)));
                    } else {
                        __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__state = 3U;
                    }
                }
            }
        } else if ((1U & (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__state))) {
            vlSelf->uart_tx = 0U;
            if ((0x35U > (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count))) {
                __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count 
                    = (0x1ffU & ((IData)(1U) + (IData)(vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count)));
            } else {
                __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count = 0U;
                __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__state = 2U;
            }
        } else {
            __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count = 0U;
            vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__bit_index = 0U;
            vlSelf->uart_tx = 1U;
            if (vlSelf->ethernet_uart_debug__DOT__send_byte) {
                __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__state = 1U;
                __Vdly__tx_busy = 1U;
                vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__data_reg 
                    = vlSelf->ethernet_uart_debug__DOT__byte_to_send;
            } else {
                __Vdly__tx_busy = 0U;
            }
        }
        if ((0U == (IData)(vlSelf->ethernet_uart_debug__DOT__state))) {
            vlSelf->ethernet_uart_debug__DOT__send_byte = 0U;
            if (((IData)(vlSelf->ethernet_uart_debug__02Eframe_start) 
                 & (~ (IData)(vlSelf->tx_busy)))) {
                vlSelf->ethernet_uart_debug__DOT__byte_to_send = 0xf8U;
                vlSelf->ethernet_uart_debug__DOT__send_byte = 1U;
                __Vdly__ethernet_uart_debug__DOT__state = 1U;
            } else if (((IData)(vlSelf->ethernet_uart_debug__02Erx_data_valid) 
                        & (~ (IData)(vlSelf->tx_busy)))) {
                vlSelf->ethernet_uart_debug__DOT__byte_to_send 
                    = vlSelf->ethernet_uart_debug__02Erx_data;
                vlSelf->ethernet_uart_debug__DOT__send_byte = 1U;
                __Vdly__ethernet_uart_debug__DOT__state = 2U;
            } else if (((IData)(vlSelf->ethernet_uart_debug__02Eframe_end) 
                        & (~ (IData)(vlSelf->tx_busy)))) {
                vlSelf->ethernet_uart_debug__DOT__byte_to_send = 0xf9U;
                vlSelf->ethernet_uart_debug__DOT__send_byte = 1U;
                __Vdly__ethernet_uart_debug__DOT__state = 1U;
            }
        } else if (((1U == (IData)(vlSelf->ethernet_uart_debug__DOT__state)) 
                    | (2U == (IData)(vlSelf->ethernet_uart_debug__DOT__state)))) {
            vlSelf->ethernet_uart_debug__DOT__send_byte = 0U;
            if ((1U & (~ (IData)(vlSelf->tx_busy)))) {
                __Vdly__ethernet_uart_debug__DOT__state = 0U;
            }
        } else {
            __Vdly__ethernet_uart_debug__DOT__state = 0U;
        }
    } else {
        __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count = 0U;
        vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__bit_index = 0U;
        __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__state = 0U;
        vlSelf->uart_tx = 1U;
        __Vdly__tx_busy = 0U;
        vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__data_reg = 0U;
        __Vdly__ethernet_uart_debug__DOT__state = 0U;
        vlSelf->ethernet_uart_debug__DOT__send_byte = 0U;
        vlSelf->ethernet_uart_debug__DOT__byte_to_send = 0U;
    }
    vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__state 
        = __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__state;
    vlSelf->ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count 
        = __Vdly__ethernet_uart_debug__DOT__uart_tx_inst__DOT__clock_count;
    vlSelf->tx_busy = __Vdly__tx_busy;
    vlSelf->ethernet_uart_debug__DOT__state = __Vdly__ethernet_uart_debug__DOT__state;
}

VL_INLINE_OPT void Vethernet_receiver___024root___nba_sequent__TOP__1(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___nba_sequent__TOP__1\n"); );
    // Init
    IData/*31:0*/ __Vfunc_ethernet_receiver__DOT__calc_crc__0__Vfuncout;
    __Vfunc_ethernet_receiver__DOT__calc_crc__0__Vfuncout = 0;
    CData/*7:0*/ __Vfunc_ethernet_receiver__DOT__calc_crc__0__data;
    __Vfunc_ethernet_receiver__DOT__calc_crc__0__data = 0;
    IData/*31:0*/ __Vfunc_ethernet_receiver__DOT__calc_crc__0__crc;
    __Vfunc_ethernet_receiver__DOT__calc_crc__0__crc = 0;
    IData/*31:0*/ __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc;
    __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc = 0;
    CData/*3:0*/ __Vdly__ethernet_receiver__DOT__state;
    __Vdly__ethernet_receiver__DOT__state = 0;
    SData/*15:0*/ __Vdly__ethernet_receiver__DOT__byte_count;
    __Vdly__ethernet_receiver__DOT__byte_count = 0;
    IData/*31:0*/ __Vdly__ethernet_receiver__DOT__crc_reg;
    __Vdly__ethernet_receiver__DOT__crc_reg = 0;
    // Body
    __Vdly__ethernet_receiver__DOT__byte_count = vlSelf->ethernet_receiver__DOT__byte_count;
    __Vdly__ethernet_receiver__DOT__state = vlSelf->ethernet_receiver__DOT__state;
    __Vdly__ethernet_receiver__DOT__crc_reg = vlSelf->ethernet_receiver__DOT__crc_reg;
    if (vlSelf->ethernet_receiver__02Erst_n) {
        if (vlSelf->ethernet_receiver__DOT__crc_init) {
            __Vdly__ethernet_receiver__DOT__crc_reg = 0xffffffffU;
        } else if (vlSelf->ethernet_receiver__DOT__crc_calc) {
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__crc 
                = vlSelf->ethernet_receiver__DOT__crc_reg;
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__data 
                = vlSelf->rxd;
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                = __Vfunc_ethernet_receiver__DOT__calc_crc__0__crc;
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                = ((1U & ((IData)(__Vfunc_ethernet_receiver__DOT__calc_crc__0__data) 
                          ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                             >> 0x1fU))) ? (0x4c11db7U 
                                            ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                               << 1U))
                    : (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                       << 1U));
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                = ((1U & (((IData)(__Vfunc_ethernet_receiver__DOT__calc_crc__0__data) 
                           >> 1U) ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                     >> 0x1fU))) ? 
                   (0x4c11db7U ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                  << 1U)) : (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                             << 1U));
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                = ((1U & (((IData)(__Vfunc_ethernet_receiver__DOT__calc_crc__0__data) 
                           >> 2U) ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                     >> 0x1fU))) ? 
                   (0x4c11db7U ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                  << 1U)) : (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                             << 1U));
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                = ((1U & (((IData)(__Vfunc_ethernet_receiver__DOT__calc_crc__0__data) 
                           >> 3U) ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                     >> 0x1fU))) ? 
                   (0x4c11db7U ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                  << 1U)) : (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                             << 1U));
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                = ((1U & (((IData)(__Vfunc_ethernet_receiver__DOT__calc_crc__0__data) 
                           >> 4U) ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                     >> 0x1fU))) ? 
                   (0x4c11db7U ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                  << 1U)) : (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                             << 1U));
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                = ((1U & (((IData)(__Vfunc_ethernet_receiver__DOT__calc_crc__0__data) 
                           >> 5U) ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                     >> 0x1fU))) ? 
                   (0x4c11db7U ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                  << 1U)) : (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                             << 1U));
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                = ((1U & (((IData)(__Vfunc_ethernet_receiver__DOT__calc_crc__0__data) 
                           >> 6U) ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                     >> 0x1fU))) ? 
                   (0x4c11db7U ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                  << 1U)) : (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                             << 1U));
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                = ((IData)((((IData)(__Vfunc_ethernet_receiver__DOT__calc_crc__0__data) 
                             >> 7U) ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                       >> 0x1fU))) ? 
                   (0x4c11db7U ^ (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                  << 1U)) : (__Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc 
                                             << 1U));
            __Vfunc_ethernet_receiver__DOT__calc_crc__0__Vfuncout 
                = __Vfunc_ethernet_receiver__DOT__calc_crc__0__new_crc;
            __Vdly__ethernet_receiver__DOT__crc_reg 
                = __Vfunc_ethernet_receiver__DOT__calc_crc__0__Vfuncout;
        }
        vlSelf->ethernet_receiver__02Erx_data_valid = 0U;
        vlSelf->ethernet_receiver__02Eframe_start = 0U;
        vlSelf->ethernet_receiver__02Eframe_end = 0U;
        vlSelf->ethernet_receiver__DOT__crc_init = 0U;
        if ((8U & (IData)(vlSelf->ethernet_receiver__DOT__state))) {
            __Vdly__ethernet_receiver__DOT__state = 0U;
        } else if ((4U & (IData)(vlSelf->ethernet_receiver__DOT__state))) {
            if ((2U & (IData)(vlSelf->ethernet_receiver__DOT__state))) {
                __Vdly__ethernet_receiver__DOT__state = 0U;
            } else if ((1U & (IData)(vlSelf->ethernet_receiver__DOT__state))) {
                if ((1U & (~ (IData)(vlSelf->rx_dv)))) {
                    __Vdly__ethernet_receiver__DOT__state = 0U;
                }
            } else {
                vlSelf->frame_valid = (0x2144df1cU 
                                       == vlSelf->ethernet_receiver__DOT__crc_reg);
                __Vdly__ethernet_receiver__DOT__state = 0U;
                vlSelf->frame_length = (0xffffU & ((IData)(vlSelf->ethernet_receiver__DOT__byte_count) 
                                                   - (IData)(4U)));
            }
        } else if ((2U & (IData)(vlSelf->ethernet_receiver__DOT__state))) {
            if ((1U & (IData)(vlSelf->ethernet_receiver__DOT__state))) {
                if (vlSelf->rx_dv) {
                    if ((0x5eaU <= (IData)(vlSelf->ethernet_receiver__DOT__byte_count))) {
                        __Vdly__ethernet_receiver__DOT__state = 5U;
                        vlSelf->frame_error = 1U;
                    } else {
                        __Vdly__ethernet_receiver__DOT__byte_count 
                            = (0xffffU & ((IData)(1U) 
                                          + (IData)(vlSelf->ethernet_receiver__DOT__byte_count)));
                        vlSelf->ethernet_receiver__02Erx_data 
                            = vlSelf->rxd;
                        vlSelf->ethernet_receiver__02Erx_data_valid = 1U;
                        vlSelf->ethernet_receiver__DOT__crc_calc = 1U;
                    }
                } else if ((0x40U > (IData)(vlSelf->ethernet_receiver__DOT__byte_count))) {
                    __Vdly__ethernet_receiver__DOT__state = 0U;
                    vlSelf->frame_error = 1U;
                } else {
                    __Vdly__ethernet_receiver__DOT__state = 4U;
                    vlSelf->ethernet_receiver__02Eframe_end = 1U;
                }
            } else if (vlSelf->rx_dv) {
                if ((0xd5U == (IData)(vlSelf->rxd))) {
                    __Vdly__ethernet_receiver__DOT__state = 3U;
                    vlSelf->ethernet_receiver__02Eframe_start = 1U;
                    vlSelf->ethernet_receiver__DOT__crc_init = 1U;
                } else {
                    __Vdly__ethernet_receiver__DOT__state = 0U;
                    vlSelf->frame_error = 1U;
                }
            } else {
                __Vdly__ethernet_receiver__DOT__state = 0U;
                vlSelf->frame_error = 1U;
            }
        } else if ((1U & (IData)(vlSelf->ethernet_receiver__DOT__state))) {
            if (vlSelf->rx_dv) {
                if ((0x55U == (IData)(vlSelf->rxd))) {
                    if ((6U == (IData)(vlSelf->ethernet_receiver__DOT__preamble_count))) {
                        __Vdly__ethernet_receiver__DOT__state = 2U;
                    } else {
                        vlSelf->ethernet_receiver__DOT__preamble_count 
                            = (7U & ((IData)(1U) + (IData)(vlSelf->ethernet_receiver__DOT__preamble_count)));
                    }
                } else if ((0xd5U == (IData)(vlSelf->rxd))) {
                    __Vdly__ethernet_receiver__DOT__state = 3U;
                    vlSelf->ethernet_receiver__02Eframe_start = 1U;
                    vlSelf->ethernet_receiver__DOT__crc_init = 1U;
                } else {
                    __Vdly__ethernet_receiver__DOT__state = 0U;
                    vlSelf->frame_error = 1U;
                }
            } else {
                __Vdly__ethernet_receiver__DOT__state = 0U;
                vlSelf->frame_error = 1U;
            }
        } else if (((IData)(vlSelf->rx_dv) & (0x55U 
                                              == (IData)(vlSelf->rxd)))) {
            __Vdly__ethernet_receiver__DOT__byte_count = 0U;
            __Vdly__ethernet_receiver__DOT__state = 1U;
            vlSelf->ethernet_receiver__DOT__preamble_count = 1U;
            vlSelf->frame_valid = 0U;
            vlSelf->frame_error = 0U;
        }
    } else {
        __Vdly__ethernet_receiver__DOT__crc_reg = 0xffffffffU;
        __Vdly__ethernet_receiver__DOT__byte_count = 0U;
        __Vdly__ethernet_receiver__DOT__state = 0U;
        vlSelf->ethernet_receiver__02Erx_data = 0U;
        vlSelf->ethernet_receiver__02Erx_data_valid = 0U;
        vlSelf->ethernet_receiver__02Eframe_start = 0U;
        vlSelf->ethernet_receiver__02Eframe_end = 0U;
        vlSelf->frame_length = 0U;
        vlSelf->frame_valid = 0U;
        vlSelf->frame_error = 0U;
        vlSelf->ethernet_receiver__DOT__preamble_count = 0U;
        vlSelf->ethernet_receiver__DOT__crc_init = 0U;
        vlSelf->ethernet_receiver__DOT__crc_calc = 0U;
    }
    vlSelf->ethernet_receiver__DOT__state = __Vdly__ethernet_receiver__DOT__state;
    vlSelf->ethernet_receiver__DOT__crc_reg = __Vdly__ethernet_receiver__DOT__crc_reg;
    vlSelf->ethernet_receiver__DOT__byte_count = __Vdly__ethernet_receiver__DOT__byte_count;
}

void Vethernet_receiver___024root___eval_nba(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(1U)) {
        Vethernet_receiver___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vethernet_receiver___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void Vethernet_receiver___024root___eval_triggers__act(Vethernet_receiver___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vethernet_receiver___024root___dump_triggers__act(Vethernet_receiver___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vethernet_receiver___024root___dump_triggers__nba(Vethernet_receiver___024root* vlSelf);
#endif  // VL_DEBUG

void Vethernet_receiver___024root___eval(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___eval\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vethernet_receiver___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vethernet_receiver___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("ethernet_receiver.sv", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vethernet_receiver___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vethernet_receiver___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("ethernet_receiver.sv", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vethernet_receiver___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vethernet_receiver___024root___eval_debug_assertions(Vethernet_receiver___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vethernet_receiver___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->ethernet_receiver__02Eclk 
                     & 0xfeU))) {
        Verilated::overWidthError("ethernet_receiver.clk");}
    if (VL_UNLIKELY((vlSelf->ethernet_receiver__02Erst_n 
                     & 0xfeU))) {
        Verilated::overWidthError("ethernet_receiver.rst_n");}
    if (VL_UNLIKELY((vlSelf->rx_dv & 0xfeU))) {
        Verilated::overWidthError("rx_dv");}
    if (VL_UNLIKELY((vlSelf->ethernet_uart_debug__02Eclk 
                     & 0xfeU))) {
        Verilated::overWidthError("ethernet_uart_debug.clk");}
    if (VL_UNLIKELY((vlSelf->ethernet_uart_debug__02Erst_n 
                     & 0xfeU))) {
        Verilated::overWidthError("ethernet_uart_debug.rst_n");}
    if (VL_UNLIKELY((vlSelf->ethernet_uart_debug__02Erx_data_valid 
                     & 0xfeU))) {
        Verilated::overWidthError("ethernet_uart_debug.rx_data_valid");}
    if (VL_UNLIKELY((vlSelf->ethernet_uart_debug__02Eframe_start 
                     & 0xfeU))) {
        Verilated::overWidthError("ethernet_uart_debug.frame_start");}
    if (VL_UNLIKELY((vlSelf->ethernet_uart_debug__02Eframe_end 
                     & 0xfeU))) {
        Verilated::overWidthError("ethernet_uart_debug.frame_end");}
}
#endif  // VL_DEBUG
