#include "engine.h"


extern bool is_simulating;
extern bool wp_triggered;
extern bool difftest_to_skip;
extern bool difftest_skipping;


void init_engine(Vysyx_23060229_top* top, VerilatedVcdC* m_trace, uint64_t* sim_time){
    printf("---------------------------------init_engine---------------------------------\n");
    printf("Engine resetting ...\n");
	top -> clk = 0; top -> rst = 1;

    while(*sim_time <= 3){
        //printf("sim_time: %ld\n",*sim_time);
        top -> clk = !top -> clk;
        if(*sim_time == 3)
            top -> rst = 0;
        top -> eval();
#ifdef CONFIG_WAVEREC
		m_trace -> dump(*sim_time);
#endif
        (*sim_time)++;
    }
	update_reg(top);
    printf("-------------------------------init_engine done------------------------------\n");
}







void exec_once(Vysyx_23060229_top* top, VerilatedVcdC* m_trace, uint64_t* sim_time){

    //print the previous inst having been decoded
    //printf("pc: %#8.8x  inst: %#8.8x\n", top->pc,top->inst);
	
	if(difftest_to_skip)
		difftest_skipping = true;
	
	top -> clk = 1;//这里会触发hit_good/bad_trap，从而导致is_simulating = 0
    top -> eval(); 
#ifdef CONFIG_WAVEREC
	m_trace -> dump(*sim_time); 
#endif
	(*sim_time)++;

    top -> clk = 0;
    top -> eval(); 
#ifdef CONFIG_WAVEREC
	m_trace -> dump(*sim_time); 
#endif
	(*sim_time)++;
	update_reg(top);

#ifdef CONFIG_WP
	scan_watchpoints();//这里可能导致wp_triggered = 1
#endif

#ifdef CONFIG_DIFFTEST
	difftest_step();
#endif
}



//只有exec_engine是向sdb提供的调用接口，exec_once并不是
void exec_engine(Vysyx_23060229_top* top, VerilatedVcdC* m_trace, uint64_t* sim_time, uint32_t no_inst){
	for(uint32_t i = 0; i < no_inst; i++){
		if(!wp_triggered && is_simulating)
			exec_once(top, m_trace, sim_time);
		else{
			//if(!is_simulating)
			//	printf("Simulation has ended...\n");
			return;
		}
	}
}


extern "C" void hit_good_trap(){
	extern Vysyx_23060229_top* top;
    printf("pc: %#8.8x  inst: %#8.8x\n", top->pc,top->inst);
    printf("\033[32mhit good trap! Simulation has ended.\033[0m\n");
    is_simulating = false;

}


extern "C" void hit_bad_trap(){
	extern Vysyx_23060229_top* top;
    printf("pc: %#8.8x  inst: %#8.8x\n", top->pc,top->inst);
	printf("\033[31mhit bad trap! Simulation has ended.\033[0m\n");
    is_simulating = false;
}


