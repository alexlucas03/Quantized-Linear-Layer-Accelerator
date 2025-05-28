// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vlayer_top__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vlayer_top::Vlayer_top(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vlayer_top__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , start{vlSymsp->TOP.start}
    , token_wr_en{vlSymsp->TOP.token_wr_en}
    , weight_wr_en{vlSymsp->TOP.weight_wr_en}
    , result_rd_en{vlSymsp->TOP.result_rd_en}
    , busy{vlSymsp->TOP.busy}
    , done{vlSymsp->TOP.done}
    , token_wr_addr{vlSymsp->TOP.token_wr_addr}
    , token_wr_data{vlSymsp->TOP.token_wr_data}
    , weight_wr_addr{vlSymsp->TOP.weight_wr_addr}
    , weight_wr_data{vlSymsp->TOP.weight_wr_data}
    , result_rd_addr{vlSymsp->TOP.result_rd_addr}
    , result_rd_data{vlSymsp->TOP.result_rd_data}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vlayer_top::Vlayer_top(const char* _vcname__)
    : Vlayer_top(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vlayer_top::~Vlayer_top() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vlayer_top___024root___eval_debug_assertions(Vlayer_top___024root* vlSelf);
#endif  // VL_DEBUG
void Vlayer_top___024root___eval_static(Vlayer_top___024root* vlSelf);
void Vlayer_top___024root___eval_initial(Vlayer_top___024root* vlSelf);
void Vlayer_top___024root___eval_settle(Vlayer_top___024root* vlSelf);
void Vlayer_top___024root___eval(Vlayer_top___024root* vlSelf);

void Vlayer_top::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlayer_top::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vlayer_top___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vlayer_top___024root___eval_static(&(vlSymsp->TOP));
        Vlayer_top___024root___eval_initial(&(vlSymsp->TOP));
        Vlayer_top___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vlayer_top___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vlayer_top::eventsPending() { return false; }

uint64_t Vlayer_top::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vlayer_top::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vlayer_top___024root___eval_final(Vlayer_top___024root* vlSelf);

VL_ATTR_COLD void Vlayer_top::final() {
    Vlayer_top___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vlayer_top::hierName() const { return vlSymsp->name(); }
const char* Vlayer_top::modelName() const { return "Vlayer_top"; }
unsigned Vlayer_top::threads() const { return 1; }
void Vlayer_top::prepareClone() const { contextp()->prepareClone(); }
void Vlayer_top::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vlayer_top::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vlayer_top___024root__trace_decl_types(VerilatedVcd* tracep);

void Vlayer_top___024root__trace_init_top(Vlayer_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vlayer_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlayer_top___024root*>(voidSelf);
    Vlayer_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vlayer_top___024root__trace_decl_types(tracep);
    Vlayer_top___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vlayer_top___024root__trace_register(Vlayer_top___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vlayer_top::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vlayer_top::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vlayer_top___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
