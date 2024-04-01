// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060229_top.h for the primary calling header

#include "verilated.h"
#include "verilated_dpi.h"

#include "Vysyx_23060229_top__Syms.h"
#include "Vysyx_23060229_top___024unit.h"

extern "C" int pmem_read_(int raddr, svBit ren);

VL_INLINE_OPT void Vysyx_23060229_top___024unit____Vdpiimwrap_pmem_read__TOP____024unit(IData/*31:0*/ raddr, CData/*0:0*/ ren, IData/*31:0*/ &pmem_read___Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_23060229_top___024unit____Vdpiimwrap_pmem_read__TOP____024unit\n"); );
    // Body
    int raddr__Vcvt;
    for (size_t raddr__Vidx = 0; raddr__Vidx < 1; ++raddr__Vidx) raddr__Vcvt = raddr;
    svBit ren__Vcvt;
    for (size_t ren__Vidx = 0; ren__Vidx < 1; ++ren__Vidx) ren__Vcvt = ren;
    int pmem_read___Vfuncrtn__Vcvt;
    pmem_read___Vfuncrtn__Vcvt = pmem_read_(raddr__Vcvt, ren__Vcvt);
    pmem_read___Vfuncrtn = pmem_read___Vfuncrtn__Vcvt;
}

extern "C" void pmem_write_(int waddr, int wdata, char wmask);

VL_INLINE_OPT void Vysyx_23060229_top___024unit____Vdpiimwrap_pmem_write__TOP____024unit(IData/*31:0*/ waddr, IData/*31:0*/ wdata, CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_23060229_top___024unit____Vdpiimwrap_pmem_write__TOP____024unit\n"); );
    // Body
    int waddr__Vcvt;
    for (size_t waddr__Vidx = 0; waddr__Vidx < 1; ++waddr__Vidx) waddr__Vcvt = waddr;
    int wdata__Vcvt;
    for (size_t wdata__Vidx = 0; wdata__Vidx < 1; ++wdata__Vidx) wdata__Vcvt = wdata;
    char wmask__Vcvt;
    for (size_t wmask__Vidx = 0; wmask__Vidx < 1; ++wmask__Vidx) wmask__Vcvt = wmask;
    pmem_write_(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

extern "C" void hit_good_trap();

VL_INLINE_OPT void Vysyx_23060229_top___024unit____Vdpiimwrap_hit_good_trap_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_23060229_top___024unit____Vdpiimwrap_hit_good_trap_TOP____024unit\n"); );
    // Body
    hit_good_trap();
}

extern "C" void hit_bad_trap();

VL_INLINE_OPT void Vysyx_23060229_top___024unit____Vdpiimwrap_hit_bad_trap_TOP____024unit() {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vysyx_23060229_top___024unit____Vdpiimwrap_hit_bad_trap_TOP____024unit\n"); );
    // Body
    hit_bad_trap();
}
