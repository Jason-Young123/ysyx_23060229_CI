// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_23060229_top__Syms.h"


void Vysyx_23060229_top___024root__trace_chg_sub_0(Vysyx_23060229_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vysyx_23060229_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060229_top___024root__trace_chg_top_0\n"); );
    // Init
    Vysyx_23060229_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060229_top___024root*>(voidSelf);
    Vysyx_23060229_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vysyx_23060229_top___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vysyx_23060229_top___024root__trace_chg_sub_0(Vysyx_23060229_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060229_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060229_top___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[0U])) {
        bufp->chgBit(oldp+0,(vlSelf->ysyx_23060229_top__DOT__reg_wen));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+1,(vlSelf->ysyx_23060229_top__DOT__typ),6);
        bufp->chgCData(oldp+2,(vlSelf->ysyx_23060229_top__DOT__rs1),5);
        bufp->chgCData(oldp+3,(vlSelf->ysyx_23060229_top__DOT__rs2),5);
        bufp->chgCData(oldp+4,(vlSelf->ysyx_23060229_top__DOT__rd),5);
        bufp->chgIData(oldp+5,(vlSelf->ysyx_23060229_top__DOT__imm),32);
        bufp->chgIData(oldp+6,(vlSelf->ysyx_23060229_top__DOT__src1),32);
        bufp->chgIData(oldp+7,(vlSelf->ysyx_23060229_top__DOT__src2),32);
        bufp->chgCData(oldp+8,(vlSelf->ysyx_23060229_top__DOT__csreg_wen),2);
        bufp->chgSData(oldp+9,((vlSelf->ysyx_23060229_top__DOT__imm 
                                >> 0x14U)),12);
        bufp->chgIData(oldp+10,(vlSelf->ysyx_23060229_top__DOT__csreg_dout),32);
        bufp->chgBit(oldp+11,(vlSelf->ysyx_23060229_top__DOT__mem_ren));
        bufp->chgBit(oldp+12,(vlSelf->ysyx_23060229_top__DOT__mem_wen));
        bufp->chgCData(oldp+13,(vlSelf->ysyx_23060229_top__DOT__mem_wmask),8);
        bufp->chgIData(oldp+14,((vlSelf->ysyx_23060229_top__DOT__imm 
                                 + vlSelf->ysyx_23060229_top__DOT__src1)),32);
        bufp->chgIData(oldp+15,(vlSelf->ysyx_23060229_top__DOT__mem_rdata),32);
        bufp->chgIData(oldp+16,((((0x1fU >= ((IData)(0x20U) 
                                             - (0x1fU 
                                                & vlSelf->ysyx_23060229_top__DOT__src2)))
                                   ? ((- (IData)((vlSelf->ysyx_23060229_top__DOT__src1 
                                                  >> 0x1fU))) 
                                      << ((IData)(0x20U) 
                                          - (0x1fU 
                                             & vlSelf->ysyx_23060229_top__DOT__src2)))
                                   : 0U) | (vlSelf->ysyx_23060229_top__DOT__src1 
                                            >> (0x1fU 
                                                & vlSelf->ysyx_23060229_top__DOT__src2)))),32);
        bufp->chgIData(oldp+17,((((0x1fU >= ((IData)(0x20U) 
                                             - (0x1fU 
                                                & vlSelf->ysyx_23060229_top__DOT__imm)))
                                   ? ((- (IData)((vlSelf->ysyx_23060229_top__DOT__src1 
                                                  >> 0x1fU))) 
                                      << ((IData)(0x20U) 
                                          - (0x1fU 
                                             & vlSelf->ysyx_23060229_top__DOT__imm)))
                                   : 0U) | (vlSelf->ysyx_23060229_top__DOT__src1 
                                            >> (0x1fU 
                                                & vlSelf->ysyx_23060229_top__DOT__imm)))),32);
        bufp->chgIData(oldp+18,((1U & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub 
                                        >> 0x1fU) ^ 
                                       (((vlSelf->ysyx_23060229_top__DOT__src1 
                                          >> 0x1fU) 
                                         != (vlSelf->ysyx_23060229_top__DOT__src2 
                                             >> 0x1fU)) 
                                        & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub 
                                            >> 0x1fU) 
                                           != (vlSelf->ysyx_23060229_top__DOT__src1 
                                               >> 0x1fU)))))),32);
        bufp->chgIData(oldp+19,((1U & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub 
                                        >> 0x1fU) ^ 
                                       (((vlSelf->ysyx_23060229_top__DOT__src1 
                                          >> 0x1fU) 
                                         != (vlSelf->ysyx_23060229_top__DOT__imm 
                                             >> 0x1fU)) 
                                        & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub 
                                            >> 0x1fU) 
                                           != (vlSelf->ysyx_23060229_top__DOT__src1 
                                               >> 0x1fU)))))),32);
        bufp->chgCData(oldp+20,((0x1fU & vlSelf->ysyx_23060229_top__DOT__src2)),5);
        bufp->chgCData(oldp+21,((0x1fU & vlSelf->ysyx_23060229_top__DOT__imm)),5);
        bufp->chgBit(oldp+22,((((vlSelf->ysyx_23060229_top__DOT__src1 
                                 >> 0x1fU) != (vlSelf->ysyx_23060229_top__DOT__src2 
                                               >> 0x1fU)) 
                               & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub 
                                   >> 0x1fU) != (vlSelf->ysyx_23060229_top__DOT__src1 
                                                 >> 0x1fU)))));
        bufp->chgBit(oldp+23,((1U & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub 
                                      >> 0x1fU) ^ (
                                                   ((vlSelf->ysyx_23060229_top__DOT__src1 
                                                     >> 0x1fU) 
                                                    != 
                                                    (vlSelf->ysyx_23060229_top__DOT__src2 
                                                     >> 0x1fU)) 
                                                   & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub 
                                                       >> 0x1fU) 
                                                      != 
                                                      (vlSelf->ysyx_23060229_top__DOT__src1 
                                                       >> 0x1fU)))))));
        bufp->chgIData(oldp+24,(vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub),32);
        bufp->chgBit(oldp+25,((((vlSelf->ysyx_23060229_top__DOT__src1 
                                 >> 0x1fU) != (vlSelf->ysyx_23060229_top__DOT__imm 
                                               >> 0x1fU)) 
                               & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub 
                                   >> 0x1fU) != (vlSelf->ysyx_23060229_top__DOT__src1 
                                                 >> 0x1fU)))));
        bufp->chgBit(oldp+26,((1U & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub 
                                      >> 0x1fU) ^ (
                                                   ((vlSelf->ysyx_23060229_top__DOT__src1 
                                                     >> 0x1fU) 
                                                    != 
                                                    (vlSelf->ysyx_23060229_top__DOT__imm 
                                                     >> 0x1fU)) 
                                                   & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub 
                                                       >> 0x1fU) 
                                                      != 
                                                      (vlSelf->ysyx_23060229_top__DOT__src1 
                                                       >> 0x1fU)))))));
        bufp->chgIData(oldp+27,(vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub),32);
        bufp->chgIData(oldp+28,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[0]),32);
        bufp->chgIData(oldp+29,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[1]),32);
        bufp->chgIData(oldp+30,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[2]),32);
        bufp->chgIData(oldp+31,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[3]),32);
        bufp->chgIData(oldp+32,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[4]),32);
        bufp->chgIData(oldp+33,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[5]),32);
        bufp->chgIData(oldp+34,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[6]),32);
        bufp->chgIData(oldp+35,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[7]),32);
        bufp->chgIData(oldp+36,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[8]),32);
        bufp->chgIData(oldp+37,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[9]),32);
        bufp->chgIData(oldp+38,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[10]),32);
        bufp->chgIData(oldp+39,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[11]),32);
        bufp->chgIData(oldp+40,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[12]),32);
        bufp->chgIData(oldp+41,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[13]),32);
        bufp->chgIData(oldp+42,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[14]),32);
        bufp->chgIData(oldp+43,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[15]),32);
        bufp->chgIData(oldp+44,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[16]),32);
        bufp->chgIData(oldp+45,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[17]),32);
        bufp->chgIData(oldp+46,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[18]),32);
        bufp->chgIData(oldp+47,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[19]),32);
        bufp->chgIData(oldp+48,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[20]),32);
        bufp->chgIData(oldp+49,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[21]),32);
        bufp->chgIData(oldp+50,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[22]),32);
        bufp->chgIData(oldp+51,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[23]),32);
        bufp->chgIData(oldp+52,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[24]),32);
        bufp->chgIData(oldp+53,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[25]),32);
        bufp->chgIData(oldp+54,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[26]),32);
        bufp->chgIData(oldp+55,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[27]),32);
        bufp->chgIData(oldp+56,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[28]),32);
        bufp->chgIData(oldp+57,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[29]),32);
        bufp->chgIData(oldp+58,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[30]),32);
        bufp->chgIData(oldp+59,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[31]),32);
    }
    bufp->chgBit(oldp+60,(vlSelf->clk));
    bufp->chgBit(oldp+61,(vlSelf->rst));
    bufp->chgIData(oldp+62,(vlSelf->inst),32);
    bufp->chgIData(oldp+63,(vlSelf->pc),32);
    bufp->chgIData(oldp+64,(vlSelf->regs[0]),32);
    bufp->chgIData(oldp+65,(vlSelf->regs[1]),32);
    bufp->chgIData(oldp+66,(vlSelf->regs[2]),32);
    bufp->chgIData(oldp+67,(vlSelf->regs[3]),32);
    bufp->chgIData(oldp+68,(vlSelf->regs[4]),32);
    bufp->chgIData(oldp+69,(vlSelf->regs[5]),32);
    bufp->chgIData(oldp+70,(vlSelf->regs[6]),32);
    bufp->chgIData(oldp+71,(vlSelf->regs[7]),32);
    bufp->chgIData(oldp+72,(vlSelf->regs[8]),32);
    bufp->chgIData(oldp+73,(vlSelf->regs[9]),32);
    bufp->chgIData(oldp+74,(vlSelf->regs[10]),32);
    bufp->chgIData(oldp+75,(vlSelf->regs[11]),32);
    bufp->chgIData(oldp+76,(vlSelf->regs[12]),32);
    bufp->chgIData(oldp+77,(vlSelf->regs[13]),32);
    bufp->chgIData(oldp+78,(vlSelf->regs[14]),32);
    bufp->chgIData(oldp+79,(vlSelf->regs[15]),32);
    bufp->chgIData(oldp+80,(vlSelf->regs[16]),32);
    bufp->chgIData(oldp+81,(vlSelf->regs[17]),32);
    bufp->chgIData(oldp+82,(vlSelf->regs[18]),32);
    bufp->chgIData(oldp+83,(vlSelf->regs[19]),32);
    bufp->chgIData(oldp+84,(vlSelf->regs[20]),32);
    bufp->chgIData(oldp+85,(vlSelf->regs[21]),32);
    bufp->chgIData(oldp+86,(vlSelf->regs[22]),32);
    bufp->chgIData(oldp+87,(vlSelf->regs[23]),32);
    bufp->chgIData(oldp+88,(vlSelf->regs[24]),32);
    bufp->chgIData(oldp+89,(vlSelf->regs[25]),32);
    bufp->chgIData(oldp+90,(vlSelf->regs[26]),32);
    bufp->chgIData(oldp+91,(vlSelf->regs[27]),32);
    bufp->chgIData(oldp+92,(vlSelf->regs[28]),32);
    bufp->chgIData(oldp+93,(vlSelf->regs[29]),32);
    bufp->chgIData(oldp+94,(vlSelf->regs[30]),32);
    bufp->chgIData(oldp+95,(vlSelf->regs[31]),32);
    bufp->chgIData(oldp+96,(vlSelf->ysyx_23060229_top__DOT__reg_din),32);
    bufp->chgIData(oldp+97,(vlSelf->ysyx_23060229_top__DOT__csreg_din),32);
    bufp->chgIData(oldp+98,(vlSelf->ysyx_23060229_top__DOT__mem_wdata),32);
    bufp->chgIData(oldp+99,(vlSelf->ysyx_23060229_top__DOT__pc_tmp),32);
}

void Vysyx_23060229_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060229_top___024root__trace_cleanup\n"); );
    // Init
    Vysyx_23060229_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060229_top___024root*>(voidSelf);
    Vysyx_23060229_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
