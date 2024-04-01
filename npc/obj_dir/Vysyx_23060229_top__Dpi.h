// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VYSYX_23060229_TOP__DPI_H_
#define VERILATED_VYSYX_23060229_TOP__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at vfile/macro.v:11:31
    extern void hit_bad_trap();
    // DPI import at vfile/macro.v:10:31
    extern void hit_good_trap();
    // DPI import at vfile/macro.v:8:30
    extern int pmem_read_(int raddr, svBit ren);
    // DPI import at vfile/macro.v:9:31
    extern void pmem_write_(int waddr, int wdata, char wmask);

#ifdef __cplusplus
}
#endif

#endif  // guard
