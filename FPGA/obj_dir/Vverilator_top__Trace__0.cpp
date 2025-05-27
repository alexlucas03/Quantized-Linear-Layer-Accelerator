// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vverilator_top__Syms.h"


void Vverilator_top___024root__trace_chg_0_sub_0(Vverilator_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vverilator_top___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_chg_0\n"); );
    // Init
    Vverilator_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_top___024root*>(voidSelf);
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vverilator_top___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vverilator_top___024root__trace_chg_0_sub_0(Vverilator_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgBit(oldp+0,(vlSelf->tb_mac_unit__DOT__rst));
        bufp->chgBit(oldp+1,(vlSelf->tb_mac_unit__DOT__start));
        bufp->chgSData(oldp+2,(vlSelf->tb_mac_unit__DOT__a),16);
        bufp->chgSData(oldp+3,(vlSelf->tb_mac_unit__DOT__b),16);
        bufp->chgIData(oldp+4,(vlSelf->tb_mac_unit__DOT__acc_in),32);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+5,(vlSelf->verilator_top__DOT__dut__DOT__result_wr_en));
        bufp->chgSData(oldp+6,(vlSelf->verilator_top__DOT__dut__DOT__result_wr_addr),10);
        bufp->chgIData(oldp+7,(vlSelf->verilator_top__DOT__dut__DOT__result_wr_data),32);
        bufp->chgBit(oldp+8,(vlSelf->verilator_top__DOT__dut__DOT__dp_start));
        bufp->chgBit(oldp+9,(vlSelf->verilator_top__DOT__dut__DOT__dp_done));
        bufp->chgIData(oldp+10,(vlSelf->verilator_top__DOT__dut__DOT__dp_result),32);
        bufp->chgBit(oldp+11,(vlSelf->verilator_top__DOT__dut__DOT__mac_start));
        bufp->chgBit(oldp+12,(vlSelf->verilator_top__DOT__dut__DOT__mac_valid));
        bufp->chgIData(oldp+13,(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__accumulator),32);
        bufp->chgIData(oldp+14,(vlSelf->verilator_top__DOT__dut__DOT__mac_acc_out),32);
        bufp->chgSData(oldp+15,(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__a_reg),16);
        bufp->chgSData(oldp+16,(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__b_reg),16);
        bufp->chgIData(oldp+17,(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__acc_reg),32);
        bufp->chgBit(oldp+18,(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage1_valid));
        bufp->chgIData(oldp+19,(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__mult_result),32);
        bufp->chgIData(oldp+20,(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__acc_stage2),32);
        bufp->chgBit(oldp+21,(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage2_valid));
        bufp->chgIData(oldp+22,(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__result),32);
        bufp->chgBit(oldp+23,(vlSelf->verilator_top__DOT__dut__DOT__mac__DOT__stage3_valid));
        bufp->chgCData(oldp+24,(vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__state),2);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgIData(oldp+25,(vlSelf->tb_mac_unit__DOT__acc_out),32);
        bufp->chgBit(oldp+26,(vlSelf->tb_mac_unit__DOT__valid));
        bufp->chgSData(oldp+27,(vlSelf->tb_mac_unit__DOT__dut__DOT__a_reg),16);
        bufp->chgSData(oldp+28,(vlSelf->tb_mac_unit__DOT__dut__DOT__b_reg),16);
        bufp->chgIData(oldp+29,(vlSelf->tb_mac_unit__DOT__dut__DOT__acc_reg),32);
        bufp->chgBit(oldp+30,(vlSelf->tb_mac_unit__DOT__dut__DOT__stage1_valid));
        bufp->chgIData(oldp+31,(vlSelf->tb_mac_unit__DOT__dut__DOT__mult_result),32);
        bufp->chgIData(oldp+32,(vlSelf->tb_mac_unit__DOT__dut__DOT__acc_stage2),32);
        bufp->chgBit(oldp+33,(vlSelf->tb_mac_unit__DOT__dut__DOT__stage2_valid));
        bufp->chgIData(oldp+34,(vlSelf->tb_mac_unit__DOT__dut__DOT__result),32);
        bufp->chgBit(oldp+35,(vlSelf->tb_mac_unit__DOT__dut__DOT__stage3_valid));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[5U])) {
        bufp->chgCData(oldp+36,(vlSelf->verilator_top__DOT__dut__DOT__spi_data),8);
        bufp->chgBit(oldp+37,(vlSelf->verilator_top__DOT__dut__DOT__spi_byte_ready));
        bufp->chgBit(oldp+38,(vlSelf->verilator_top__DOT__dut__DOT__token_wr_en));
        bufp->chgBit(oldp+39,(vlSelf->verilator_top__DOT__dut__DOT__weight_wr_en));
        bufp->chgSData(oldp+40,(vlSelf->verilator_top__DOT__dut__DOT__token_wr_addr),10);
        bufp->chgSData(oldp+41,(vlSelf->verilator_top__DOT__dut__DOT__weight_wr_addr),10);
        bufp->chgSData(oldp+42,(vlSelf->verilator_top__DOT__dut__DOT__token_wr_data),16);
        bufp->chgSData(oldp+43,(vlSelf->verilator_top__DOT__dut__DOT__weight_wr_data),16);
        bufp->chgBit(oldp+44,((1U == (IData)(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__state))));
        bufp->chgSData(oldp+45,(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__index),10);
        bufp->chgSData(oldp+46,((0x3ffU & ((IData)(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__index) 
                                           + VL_SHIFTL_III(10,10,32, (IData)(vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index), 3U)))),10);
        bufp->chgSData(oldp+47,((0x3ffU & VL_SHIFTL_III(10,10,32, (IData)(vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index), 3U))),10);
        bufp->chgBit(oldp+48,(vlSelf->verilator_top__DOT__dut__DOT__start_matmul));
        bufp->chgCData(oldp+49,(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__state),3);
        bufp->chgCData(oldp+50,(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__command),8);
        bufp->chgSData(oldp+51,(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__base_addr),10);
        bufp->chgSData(oldp+52,(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__write_addr),10);
        bufp->chgSData(oldp+53,(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__length),16);
        bufp->chgSData(oldp+54,(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__remaining),16);
        bufp->chgCData(oldp+55,(vlSelf->verilator_top__DOT__dut__DOT__cmd_ctrl__DOT__data_hi),8);
        bufp->chgCData(oldp+56,(vlSelf->verilator_top__DOT__dut__DOT__dp__DOT__state),2);
        bufp->chgSData(oldp+57,(vlSelf->verilator_top__DOT__dut__DOT__mm_ctrl__DOT__output_index),10);
        bufp->chgCData(oldp+58,(vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__bit_cnt),3);
        bufp->chgCData(oldp+59,(vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__shift_reg),8);
        bufp->chgBit(oldp+60,(vlSelf->verilator_top__DOT__dut__DOT__spi_slave_inst__DOT__sclk_prev));
    }
    bufp->chgBit(oldp+61,(vlSelf->clk));
    bufp->chgBit(oldp+62,(vlSelf->rst));
    bufp->chgBit(oldp+63,(vlSelf->spi_sclk));
    bufp->chgBit(oldp+64,(vlSelf->spi_mosi));
    bufp->chgBit(oldp+65,(vlSelf->spi_cs_n));
    bufp->chgBit(oldp+66,(vlSelf->matmul_done));
    bufp->chgIData(oldp+67,(vlSelf->result),32);
    bufp->chgBit(oldp+68,(vlSelf->tb_mac_unit__DOT__clk));
    bufp->chgSData(oldp+69,(vlSelf->verilator_top__DOT__dut__DOT__token_rd_data),16);
    bufp->chgSData(oldp+70,(vlSelf->verilator_top__DOT__dut__DOT__weight_rd_data),16);
}

void Vverilator_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vverilator_top___024root__trace_cleanup\n"); );
    // Init
    Vverilator_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vverilator_top___024root*>(voidSelf);
    Vverilator_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[5U] = 0U;
}
