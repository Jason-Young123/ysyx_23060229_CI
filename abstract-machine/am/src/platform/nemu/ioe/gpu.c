#include <am.h>
#include <nemu.h>

#define SYNC_ADDR (VGACTL_ADDR + 4)

void __am_gpu_init() {
}

void __am_gpu_config(AM_GPU_CONFIG_T *cfg) {
  *cfg = (AM_GPU_CONFIG_T) {
    .present = true, .has_accel = false,
    .width = 400, .height = 300,
    .vmemsz = 0
  };
}


//ctl 有如下成员变量：int x, y, void* pixels, int w,h, bool sync
//其中x，y是画方块的起始位置（左上角坐标），pixel为方块的颜色，w和h为方块的尺寸，sync
//表示这个方块是否要被立刻显示
void __am_gpu_fbdraw(AM_GPU_FBDRAW_T *ctl) {
  	uint32_t* color_buf = (uint32_t*)ctl -> pixels;
	for(int x = 0; x < ctl -> w; x++){
		for(int y = 0; y < ctl -> h; y++){
			outl(FB_ADDR + (y + ctl -> y)*400 + (x + ctl -> x), color_buf[0]);
		}
	}
		
	if (ctl->sync)
    	outl(SYNC_ADDR, 1);
	else
		outl(SYNC_ADDR, 0);

}

void __am_gpu_status(AM_GPU_STATUS_T *status) {
  status->ready = true;
}
