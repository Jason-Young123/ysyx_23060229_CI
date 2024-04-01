#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <stdint.h>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vysyx_23060229_top.h"
#include "../memory/memory.h"
#include "../register/register.h"
#include "../sdb/sdb.h"
//sdb.h和engine.h陷入循环调用
//sdb.c需要调用engine.c中定义的exec_once，而engine.c需要调用watchpoint.c中定义的与监视点相关的函数
#include "../difftest/difftest.h"
#include "../include/auto.h"


void init_engine(Vysyx_23060229_top* top, VerilatedVcdC* m_trace, uint64_t* sim_time);
void exec_once(Vysyx_23060229_top* top, VerilatedVcdC* m_trace, uint64_t* sim_time);
void exec_engine(Vysyx_23060229_top* top, VerilatedVcdC* m_trace, uint64_t* sim_time, uint32_t no_inst);


#endif
