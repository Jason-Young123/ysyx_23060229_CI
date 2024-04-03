// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vysyx_23060229_top__Syms.h"


VL_ATTR_COLD void Vysyx_23060229_top___024root__trace_init_sub__TOP__0(Vysyx_23060229_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060229_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060229_top___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+58,"clk", false,-1);
    tracep->declBit(c+59,"rst", false,-1);
    tracep->declBus(c+60,"inst", false,-1, 31,0);
    tracep->declBus(c+61,"pc", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+62+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->pushNamePrefix("ysyx_23060229_top ");
    tracep->declBit(c+58,"clk", false,-1);
    tracep->declBit(c+59,"rst", false,-1);
    tracep->declBus(c+60,"inst", false,-1, 31,0);
    tracep->declBus(c+61,"pc", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+62+i*1,"regs", true,(i+0), 31,0);
    }
    tracep->declBus(c+2,"typ", false,-1, 5,0);
    tracep->declBus(c+3,"rs1", false,-1, 4,0);
    tracep->declBus(c+4,"rs2", false,-1, 4,0);
    tracep->declBus(c+5,"rd", false,-1, 4,0);
    tracep->declBus(c+6,"imm", false,-1, 31,0);
    tracep->declBit(c+1,"reg_wen", false,-1);
    tracep->declBus(c+94,"reg_din", false,-1, 31,0);
    tracep->declBus(c+7,"src1", false,-1, 31,0);
    tracep->declBus(c+8,"src2", false,-1, 31,0);
    tracep->declBit(c+9,"mem_ren", false,-1);
    tracep->declBit(c+10,"mem_wen", false,-1);
    tracep->declBus(c+11,"mem_wmask", false,-1, 7,0);
    tracep->declBus(c+12,"mem_waddr", false,-1, 31,0);
    tracep->declBus(c+12,"mem_raddr", false,-1, 31,0);
    tracep->declBus(c+95,"mem_wdata", false,-1, 31,0);
    tracep->declBus(c+13,"mem_rdata", false,-1, 31,0);
    tracep->declBus(c+96,"pc_tmp", false,-1, 31,0);
    tracep->pushNamePrefix("muexu ");
    tracep->declBit(c+59,"rst", false,-1);
    tracep->declBus(c+61,"pc", false,-1, 31,0);
    tracep->declBus(c+2,"typ", false,-1, 5,0);
    tracep->declBus(c+7,"src1", false,-1, 31,0);
    tracep->declBus(c+8,"src2", false,-1, 31,0);
    tracep->declBus(c+6,"imm", false,-1, 31,0);
    tracep->declBus(c+13,"mem_rdata", false,-1, 31,0);
    tracep->declBus(c+95,"mem_wdata", false,-1, 31,0);
    tracep->declBus(c+94,"reg_din", false,-1, 31,0);
    tracep->declBus(c+96,"pcout", false,-1, 31,0);
    tracep->declBus(c+14,"arith_shifter_out", false,-1, 31,0);
    tracep->declBus(c+15,"arith_shifter_out1", false,-1, 31,0);
    tracep->declBus(c+16,"scomp_out", false,-1, 31,0);
    tracep->declBus(c+17,"scomp_out1", false,-1, 31,0);
    tracep->pushNamePrefix("myarith_shifter ");
    tracep->declBus(c+7,"src1", false,-1, 31,0);
    tracep->declBus(c+18,"src2", false,-1, 4,0);
    tracep->declBus(c+14,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("myarith_shifter1 ");
    tracep->declBus(c+7,"src1", false,-1, 31,0);
    tracep->declBus(c+19,"src2", false,-1, 4,0);
    tracep->declBus(c+15,"out", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("myscomp ");
    tracep->declBus(c+7,"src1", false,-1, 31,0);
    tracep->declBus(c+8,"src2", false,-1, 31,0);
    tracep->declBus(c+16,"out", false,-1, 31,0);
    tracep->declBit(c+20,"overflow", false,-1);
    tracep->declBit(c+21,"result", false,-1);
    tracep->declBus(c+22,"sub", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("myscomp1 ");
    tracep->declBus(c+7,"src1", false,-1, 31,0);
    tracep->declBus(c+6,"src2", false,-1, 31,0);
    tracep->declBus(c+17,"out", false,-1, 31,0);
    tracep->declBit(c+23,"overflow", false,-1);
    tracep->declBit(c+24,"result", false,-1);
    tracep->declBus(c+25,"sub", false,-1, 31,0);
    tracep->popNamePrefix(2);
    tracep->pushNamePrefix("myidu ");
    tracep->declBus(c+60,"inst", false,-1, 31,0);
    tracep->declBus(c+2,"typ", false,-1, 5,0);
    tracep->declBus(c+3,"rs1", false,-1, 4,0);
    tracep->declBus(c+4,"rs2", false,-1, 4,0);
    tracep->declBus(c+5,"rd", false,-1, 4,0);
    tracep->declBus(c+6,"imm", false,-1, 31,0);
    tracep->declBit(c+1,"reg_wen", false,-1);
    tracep->declBit(c+9,"mem_ren", false,-1);
    tracep->declBit(c+10,"mem_wen", false,-1);
    tracep->declBus(c+11,"mem_wmask", false,-1, 7,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("mymem ");
    tracep->declBus(c+97,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+98,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+58,"clk", false,-1);
    tracep->declBit(c+59,"rst", false,-1);
    tracep->declBit(c+9,"ren", false,-1);
    tracep->declBit(c+10,"wen", false,-1);
    tracep->declBus(c+11,"wmask", false,-1, 7,0);
    tracep->declBus(c+95,"wdata", false,-1, 31,0);
    tracep->declBus(c+12,"waddr", false,-1, 31,0);
    tracep->declBus(c+61,"pc", false,-1, 31,0);
    tracep->declBus(c+12,"raddr", false,-1, 31,0);
    tracep->declBus(c+60,"inst", false,-1, 31,0);
    tracep->declBus(c+13,"rdata", false,-1, 31,0);
    tracep->popNamePrefix(1);
    tracep->pushNamePrefix("myreg ");
    tracep->declBus(c+99,"ADDR_WIDTH", false,-1, 31,0);
    tracep->declBus(c+97,"DATA_WIDTH", false,-1, 31,0);
    tracep->declBit(c+58,"clk", false,-1);
    tracep->declBit(c+59,"rst", false,-1);
    tracep->declBit(c+1,"wen", false,-1);
    tracep->declBus(c+94,"din", false,-1, 31,0);
    tracep->declBus(c+96,"pcin", false,-1, 31,0);
    tracep->declBus(c+5,"addr_in", false,-1, 4,0);
    tracep->declBus(c+3,"addr_out1", false,-1, 4,0);
    tracep->declBus(c+4,"addr_out2", false,-1, 4,0);
    tracep->declBus(c+7,"dout1", false,-1, 31,0);
    tracep->declBus(c+8,"dout2", false,-1, 31,0);
    tracep->declBus(c+61,"pc", false,-1, 31,0);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+26+i*1,"Reg", true,(i+0), 31,0);
    }
    tracep->popNamePrefix(2);
}

VL_ATTR_COLD void Vysyx_23060229_top___024root__trace_init_top(Vysyx_23060229_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060229_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060229_top___024root__trace_init_top\n"); );
    // Body
    Vysyx_23060229_top___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vysyx_23060229_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_23060229_top___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vysyx_23060229_top___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vysyx_23060229_top___024root__trace_register(Vysyx_23060229_top___024root* vlSelf, VerilatedVcd* tracep) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060229_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060229_top___024root__trace_register\n"); );
    // Body
    tracep->addFullCb(&Vysyx_23060229_top___024root__trace_full_top_0, vlSelf);
    tracep->addChgCb(&Vysyx_23060229_top___024root__trace_chg_top_0, vlSelf);
    tracep->addCleanupCb(&Vysyx_23060229_top___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vysyx_23060229_top___024root__trace_full_sub_0(Vysyx_23060229_top___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vysyx_23060229_top___024root__trace_full_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060229_top___024root__trace_full_top_0\n"); );
    // Init
    Vysyx_23060229_top___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vysyx_23060229_top___024root*>(voidSelf);
    Vysyx_23060229_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vysyx_23060229_top___024root__trace_full_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vysyx_23060229_top___024root__trace_full_sub_0(Vysyx_23060229_top___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060229_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060229_top___024root__trace_full_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullBit(oldp+1,(vlSelf->ysyx_23060229_top__DOT__reg_wen));
    bufp->fullCData(oldp+2,(vlSelf->ysyx_23060229_top__DOT__typ),6);
    bufp->fullCData(oldp+3,(vlSelf->ysyx_23060229_top__DOT__rs1),5);
    bufp->fullCData(oldp+4,(vlSelf->ysyx_23060229_top__DOT__rs2),5);
    bufp->fullCData(oldp+5,(vlSelf->ysyx_23060229_top__DOT__rd),5);
    bufp->fullIData(oldp+6,(vlSelf->ysyx_23060229_top__DOT__imm),32);
    bufp->fullIData(oldp+7,(vlSelf->ysyx_23060229_top__DOT__src1),32);
    bufp->fullIData(oldp+8,(vlSelf->ysyx_23060229_top__DOT__src2),32);
    bufp->fullBit(oldp+9,(vlSelf->ysyx_23060229_top__DOT__mem_ren));
    bufp->fullBit(oldp+10,(vlSelf->ysyx_23060229_top__DOT__mem_wen));
    bufp->fullCData(oldp+11,(vlSelf->ysyx_23060229_top__DOT__mem_wmask),8);
    bufp->fullIData(oldp+12,((vlSelf->ysyx_23060229_top__DOT__imm 
                              + vlSelf->ysyx_23060229_top__DOT__src1)),32);
    bufp->fullIData(oldp+13,(vlSelf->ysyx_23060229_top__DOT__mem_rdata),32);
    bufp->fullIData(oldp+14,((((0x1fU >= ((IData)(0x20U) 
                                          - (0x1fU 
                                             & vlSelf->ysyx_23060229_top__DOT__src2)))
                                ? ((- (IData)((vlSelf->ysyx_23060229_top__DOT__src1 
                                               >> 0x1fU))) 
                                   << ((IData)(0x20U) 
                                       - (0x1fU & vlSelf->ysyx_23060229_top__DOT__src2)))
                                : 0U) | (vlSelf->ysyx_23060229_top__DOT__src1 
                                         >> (0x1fU 
                                             & vlSelf->ysyx_23060229_top__DOT__src2)))),32);
    bufp->fullIData(oldp+15,((((0x1fU >= ((IData)(0x20U) 
                                          - (0x1fU 
                                             & vlSelf->ysyx_23060229_top__DOT__imm)))
                                ? ((- (IData)((vlSelf->ysyx_23060229_top__DOT__src1 
                                               >> 0x1fU))) 
                                   << ((IData)(0x20U) 
                                       - (0x1fU & vlSelf->ysyx_23060229_top__DOT__imm)))
                                : 0U) | (vlSelf->ysyx_23060229_top__DOT__src1 
                                         >> (0x1fU 
                                             & vlSelf->ysyx_23060229_top__DOT__imm)))),32);
    bufp->fullIData(oldp+16,((1U & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub 
                                     >> 0x1fU) ^ ((
                                                   (vlSelf->ysyx_23060229_top__DOT__src1 
                                                    >> 0x1fU) 
                                                   != 
                                                   (vlSelf->ysyx_23060229_top__DOT__src2 
                                                    >> 0x1fU)) 
                                                  & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub 
                                                      >> 0x1fU) 
                                                     != 
                                                     (vlSelf->ysyx_23060229_top__DOT__src1 
                                                      >> 0x1fU)))))),32);
    bufp->fullIData(oldp+17,((1U & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub 
                                     >> 0x1fU) ^ ((
                                                   (vlSelf->ysyx_23060229_top__DOT__src1 
                                                    >> 0x1fU) 
                                                   != 
                                                   (vlSelf->ysyx_23060229_top__DOT__imm 
                                                    >> 0x1fU)) 
                                                  & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub 
                                                      >> 0x1fU) 
                                                     != 
                                                     (vlSelf->ysyx_23060229_top__DOT__src1 
                                                      >> 0x1fU)))))),32);
    bufp->fullCData(oldp+18,((0x1fU & vlSelf->ysyx_23060229_top__DOT__src2)),5);
    bufp->fullCData(oldp+19,((0x1fU & vlSelf->ysyx_23060229_top__DOT__imm)),5);
    bufp->fullBit(oldp+20,((((vlSelf->ysyx_23060229_top__DOT__src1 
                              >> 0x1fU) != (vlSelf->ysyx_23060229_top__DOT__src2 
                                            >> 0x1fU)) 
                            & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub 
                                >> 0x1fU) != (vlSelf->ysyx_23060229_top__DOT__src1 
                                              >> 0x1fU)))));
    bufp->fullBit(oldp+21,((1U & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub 
                                   >> 0x1fU) ^ (((vlSelf->ysyx_23060229_top__DOT__src1 
                                                  >> 0x1fU) 
                                                 != 
                                                 (vlSelf->ysyx_23060229_top__DOT__src2 
                                                  >> 0x1fU)) 
                                                & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub 
                                                    >> 0x1fU) 
                                                   != 
                                                   (vlSelf->ysyx_23060229_top__DOT__src1 
                                                    >> 0x1fU)))))));
    bufp->fullIData(oldp+22,(vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp__DOT__sub),32);
    bufp->fullBit(oldp+23,((((vlSelf->ysyx_23060229_top__DOT__src1 
                              >> 0x1fU) != (vlSelf->ysyx_23060229_top__DOT__imm 
                                            >> 0x1fU)) 
                            & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub 
                                >> 0x1fU) != (vlSelf->ysyx_23060229_top__DOT__src1 
                                              >> 0x1fU)))));
    bufp->fullBit(oldp+24,((1U & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub 
                                   >> 0x1fU) ^ (((vlSelf->ysyx_23060229_top__DOT__src1 
                                                  >> 0x1fU) 
                                                 != 
                                                 (vlSelf->ysyx_23060229_top__DOT__imm 
                                                  >> 0x1fU)) 
                                                & ((vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub 
                                                    >> 0x1fU) 
                                                   != 
                                                   (vlSelf->ysyx_23060229_top__DOT__src1 
                                                    >> 0x1fU)))))));
    bufp->fullIData(oldp+25,(vlSelf->ysyx_23060229_top__DOT__muexu__DOT__myscomp1__DOT__sub),32);
    bufp->fullIData(oldp+26,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[0]),32);
    bufp->fullIData(oldp+27,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[1]),32);
    bufp->fullIData(oldp+28,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[2]),32);
    bufp->fullIData(oldp+29,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[3]),32);
    bufp->fullIData(oldp+30,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[4]),32);
    bufp->fullIData(oldp+31,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[5]),32);
    bufp->fullIData(oldp+32,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[6]),32);
    bufp->fullIData(oldp+33,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[7]),32);
    bufp->fullIData(oldp+34,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[8]),32);
    bufp->fullIData(oldp+35,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[9]),32);
    bufp->fullIData(oldp+36,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[10]),32);
    bufp->fullIData(oldp+37,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[11]),32);
    bufp->fullIData(oldp+38,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[12]),32);
    bufp->fullIData(oldp+39,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[13]),32);
    bufp->fullIData(oldp+40,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[14]),32);
    bufp->fullIData(oldp+41,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[15]),32);
    bufp->fullIData(oldp+42,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[16]),32);
    bufp->fullIData(oldp+43,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[17]),32);
    bufp->fullIData(oldp+44,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[18]),32);
    bufp->fullIData(oldp+45,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[19]),32);
    bufp->fullIData(oldp+46,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[20]),32);
    bufp->fullIData(oldp+47,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[21]),32);
    bufp->fullIData(oldp+48,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[22]),32);
    bufp->fullIData(oldp+49,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[23]),32);
    bufp->fullIData(oldp+50,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[24]),32);
    bufp->fullIData(oldp+51,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[25]),32);
    bufp->fullIData(oldp+52,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[26]),32);
    bufp->fullIData(oldp+53,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[27]),32);
    bufp->fullIData(oldp+54,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[28]),32);
    bufp->fullIData(oldp+55,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[29]),32);
    bufp->fullIData(oldp+56,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[30]),32);
    bufp->fullIData(oldp+57,(vlSelf->ysyx_23060229_top__DOT____Vcellout__myreg____pinNumber12[31]),32);
    bufp->fullBit(oldp+58,(vlSelf->clk));
    bufp->fullBit(oldp+59,(vlSelf->rst));
    bufp->fullIData(oldp+60,(vlSelf->inst),32);
    bufp->fullIData(oldp+61,(vlSelf->pc),32);
    bufp->fullIData(oldp+62,(vlSelf->regs[0]),32);
    bufp->fullIData(oldp+63,(vlSelf->regs[1]),32);
    bufp->fullIData(oldp+64,(vlSelf->regs[2]),32);
    bufp->fullIData(oldp+65,(vlSelf->regs[3]),32);
    bufp->fullIData(oldp+66,(vlSelf->regs[4]),32);
    bufp->fullIData(oldp+67,(vlSelf->regs[5]),32);
    bufp->fullIData(oldp+68,(vlSelf->regs[6]),32);
    bufp->fullIData(oldp+69,(vlSelf->regs[7]),32);
    bufp->fullIData(oldp+70,(vlSelf->regs[8]),32);
    bufp->fullIData(oldp+71,(vlSelf->regs[9]),32);
    bufp->fullIData(oldp+72,(vlSelf->regs[10]),32);
    bufp->fullIData(oldp+73,(vlSelf->regs[11]),32);
    bufp->fullIData(oldp+74,(vlSelf->regs[12]),32);
    bufp->fullIData(oldp+75,(vlSelf->regs[13]),32);
    bufp->fullIData(oldp+76,(vlSelf->regs[14]),32);
    bufp->fullIData(oldp+77,(vlSelf->regs[15]),32);
    bufp->fullIData(oldp+78,(vlSelf->regs[16]),32);
    bufp->fullIData(oldp+79,(vlSelf->regs[17]),32);
    bufp->fullIData(oldp+80,(vlSelf->regs[18]),32);
    bufp->fullIData(oldp+81,(vlSelf->regs[19]),32);
    bufp->fullIData(oldp+82,(vlSelf->regs[20]),32);
    bufp->fullIData(oldp+83,(vlSelf->regs[21]),32);
    bufp->fullIData(oldp+84,(vlSelf->regs[22]),32);
    bufp->fullIData(oldp+85,(vlSelf->regs[23]),32);
    bufp->fullIData(oldp+86,(vlSelf->regs[24]),32);
    bufp->fullIData(oldp+87,(vlSelf->regs[25]),32);
    bufp->fullIData(oldp+88,(vlSelf->regs[26]),32);
    bufp->fullIData(oldp+89,(vlSelf->regs[27]),32);
    bufp->fullIData(oldp+90,(vlSelf->regs[28]),32);
    bufp->fullIData(oldp+91,(vlSelf->regs[29]),32);
    bufp->fullIData(oldp+92,(vlSelf->regs[30]),32);
    bufp->fullIData(oldp+93,(vlSelf->regs[31]),32);
    bufp->fullIData(oldp+94,(vlSelf->ysyx_23060229_top__DOT__reg_din),32);
    bufp->fullIData(oldp+95,(vlSelf->ysyx_23060229_top__DOT__mem_wdata),32);
    bufp->fullIData(oldp+96,(vlSelf->ysyx_23060229_top__DOT__pc_tmp),32);
    bufp->fullIData(oldp+97,(0x20U),32);
    bufp->fullIData(oldp+98,(8U),32);
    bufp->fullIData(oldp+99,(5U),32);
}
