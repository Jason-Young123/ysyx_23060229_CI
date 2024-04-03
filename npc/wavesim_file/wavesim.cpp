#include <assert.h>
#include <stdint.h>
#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vysyx_23060229_top.h"
//#include "./register/register.h"
#include <memory/memory.h>
#include <engine/engine.h>
#include <sdb/sdb.h>
#include <difftest/difftest.h>

using namespace std;


#define MAX_SIM_TIME 50
uint64_t sim_time = 0;
bool is_simulating = false;
bool wp_triggered = false;
bool difftest_to_skip = false;
bool difftest_skipping = false;


const char* ref_so_file = "/home/jason/Desktop/ysyx-workbench/nemu/build/riscv32-nemu-interpreter-so";

Vysyx_23060229_top* top = new Vysyx_23060229_top;
VerilatedVcdC* m_trace = new VerilatedVcdC;



int main(int argc, char *argv[]){
	long size = init_mem(argv[1]);
	
	printf("Checking Devices:\n");
	init_devices();


	printf("Checking Options:\n");
#ifdef CONFIG_WAVEREC
	printf("\033[36mWave Record is ON\033[0m\n");
    // to enable wave tracing
    Verilated::traceEverOn(true);
    //VerilatedVcdC* m_trace = new VerilatedVcdC;
    top -> trace(m_trace, 5);
    m_trace -> open("./wavesim_file/wave.vcd");
#else
	printf("\033[36mWave Record is OFF\033[0m\n");
#endif

#ifdef CONFIG_WP
	printf("\033[36mWatchpoint is ON\033[0m\n");
#else
	printf("\033[36mWatchpoint is OFF\033[0m\n");
#endif

#ifdef CONFIG_DIFFTEST
	printf("\033[36mDifftest is ON\033[0m\n");
	printf("\033[36mPath of reference file:\n%s\033[0m\n",ref_so_file);
#else
	printf("\033[36mDifftest is OFF\033[0m\n");
#endif



	init_engine(top, m_trace, &sim_time);
#ifdef CONFIG_DIFFTEST
	init_difftest(ref_so_file, size, 0);//如果开启difftest这条指令必须在init_engine后执行
#endif
	is_simulating = true;
	init_sdb();
	

	//循环主体
	sdb_mainloop(&sim_time);

	m_trace -> close();
    
	if(top)
		delete top;
	if(m_trace)
		delete m_trace;	


    return 0;
}

