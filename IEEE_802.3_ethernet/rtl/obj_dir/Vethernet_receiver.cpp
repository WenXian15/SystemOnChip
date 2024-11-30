// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vethernet_receiver.h"
#include "Vethernet_receiver__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vethernet_receiver::Vethernet_receiver(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vethernet_receiver__Syms(contextp(), _vcname__, this)}
    , ethernet_receiver__02Eclk{vlSymsp->TOP.ethernet_receiver__02Eclk}
    , ethernet_receiver__02Erst_n{vlSymsp->TOP.ethernet_receiver__02Erst_n}
    , ethernet_uart_debug__02Eclk{vlSymsp->TOP.ethernet_uart_debug__02Eclk}
    , ethernet_uart_debug__02Erst_n{vlSymsp->TOP.ethernet_uart_debug__02Erst_n}
    , rx_dv{vlSymsp->TOP.rx_dv}
    , rxd{vlSymsp->TOP.rxd}
    , ethernet_receiver__02Erx_data{vlSymsp->TOP.ethernet_receiver__02Erx_data}
    , ethernet_receiver__02Erx_data_valid{vlSymsp->TOP.ethernet_receiver__02Erx_data_valid}
    , ethernet_receiver__02Eframe_start{vlSymsp->TOP.ethernet_receiver__02Eframe_start}
    , ethernet_receiver__02Eframe_end{vlSymsp->TOP.ethernet_receiver__02Eframe_end}
    , frame_valid{vlSymsp->TOP.frame_valid}
    , frame_error{vlSymsp->TOP.frame_error}
    , ethernet_uart_debug__02Erx_data_valid{vlSymsp->TOP.ethernet_uart_debug__02Erx_data_valid}
    , ethernet_uart_debug__02Erx_data{vlSymsp->TOP.ethernet_uart_debug__02Erx_data}
    , ethernet_uart_debug__02Eframe_start{vlSymsp->TOP.ethernet_uart_debug__02Eframe_start}
    , ethernet_uart_debug__02Eframe_end{vlSymsp->TOP.ethernet_uart_debug__02Eframe_end}
    , uart_tx{vlSymsp->TOP.uart_tx}
    , tx_busy{vlSymsp->TOP.tx_busy}
    , frame_length{vlSymsp->TOP.frame_length}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vethernet_receiver::Vethernet_receiver(const char* _vcname__)
    : Vethernet_receiver(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vethernet_receiver::~Vethernet_receiver() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vethernet_receiver___024root___eval_debug_assertions(Vethernet_receiver___024root* vlSelf);
#endif  // VL_DEBUG
void Vethernet_receiver___024root___eval_static(Vethernet_receiver___024root* vlSelf);
void Vethernet_receiver___024root___eval_initial(Vethernet_receiver___024root* vlSelf);
void Vethernet_receiver___024root___eval_settle(Vethernet_receiver___024root* vlSelf);
void Vethernet_receiver___024root___eval(Vethernet_receiver___024root* vlSelf);

void Vethernet_receiver::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vethernet_receiver::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vethernet_receiver___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vethernet_receiver___024root___eval_static(&(vlSymsp->TOP));
        Vethernet_receiver___024root___eval_initial(&(vlSymsp->TOP));
        Vethernet_receiver___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vethernet_receiver___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vethernet_receiver::eventsPending() { return false; }

uint64_t Vethernet_receiver::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vethernet_receiver::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vethernet_receiver___024root___eval_final(Vethernet_receiver___024root* vlSelf);

VL_ATTR_COLD void Vethernet_receiver::final() {
    Vethernet_receiver___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vethernet_receiver::hierName() const { return vlSymsp->name(); }
const char* Vethernet_receiver::modelName() const { return "Vethernet_receiver"; }
unsigned Vethernet_receiver::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vethernet_receiver::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vethernet_receiver___024root__trace_init_top(Vethernet_receiver___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vethernet_receiver___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vethernet_receiver___024root*>(voidSelf);
    Vethernet_receiver__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vethernet_receiver___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vethernet_receiver___024root__trace_register(Vethernet_receiver___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vethernet_receiver::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vethernet_receiver::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vethernet_receiver___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
