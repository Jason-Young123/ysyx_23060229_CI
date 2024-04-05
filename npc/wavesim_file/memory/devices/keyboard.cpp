#include <memory/memory.h>


extern bool difftest_to_skip;

uint32_t keyboard_addr[1] = {0};


static void update_keycode(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_KEYUP:
			case SDL_KEYDOWN:{
				uint8_t k = event.key.keysym.scancode;
				bool is_keydown = (event.key.type == SDL_KEYDOWN);
				keyboard_addr[0] = is_keydown ? (0x8000|k) : k;
			}
			default: break;
		}
	
	}

}

int fetch_timer_addr(uint32_t raddr){
    difftest_to_skip = true;
    if(raddr == KBD_ADDR){
        return keyboard_addr[0];
    }
    return 0;
}

