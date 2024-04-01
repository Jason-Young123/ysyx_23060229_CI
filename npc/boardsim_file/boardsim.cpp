#include <nvboard.h>
#include "Vmux.h"

static Vmux mux;

void nvboard_bind_all_pins(Vmux* mux);


int main(){

	nvboard_bind_all_pins(&mux);
	nvboard_init();

	mux.eval();
	mux.eval();

	while(true){
		nvboard_update();
		mux.eval();
	}

	return 0;
}
