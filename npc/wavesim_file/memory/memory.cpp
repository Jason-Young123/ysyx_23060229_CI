#include "memory.h"



uint8_t memory[MEM_SIZE] = { 0x93,0x80,0x10,0x00,//addi,R(1) += 1, R(1) = 1
                                    0x93,0x83,0x20,0x00,//addi,R(7) = R(1) + 2 = 3
                                    0x93,0x83,0xf3,0xff,//addi,R(7) = R(7) - 1 = 2
                                    0x03,0xaf,0x8f,0x01,//lw, R(30) = Mem(R(31) + 24) = Mem(0x80000024) = 0x15141312
                                    0x23,0xae,0xef,0x01,//sw, Mem(0x80000028) = R(30) = 0x15141312
                                    0x73,0x00,0x10,0x00,//ebreak
                                    0x12,0x13,0x14,0x15,//data for reading
                                    0x88,0x77,0x66,0x55 //data for rewriting
                                    };

uint8_t serial_port[8] = {0,0,0,0,0,0,0,0};
uint32_t timer_addr[2] = {0};

extern bool difftest_to_skip;
extern bool difftest_skipping;

long init_mem(const char* file){
    printf("---------------------------------init_mem----------------------------------\n");
    FILE *fp = fopen(file, "rb");
    if(fp == NULL){
		printf("\033[31mFailed to locate file:\n%s\n",file);
        printf("Reading image file failure. Using built-in memory ...\033[0m\n");
		printf("\033[32mSize of image file = 32\n\033[0m");
        printf("--------------------------------init_mem done------------------------------\n");
		return 40;
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    printf("\033[32mImage file found in:\n%s\nSize of image file = %ld\033[0m\n",file, size);

    fseek(fp, 0, SEEK_SET);
    int ret = fread(memory, size, 1, fp);
    if(ret != 1)
        printf("Fread error. Using built-in memory ...\n");
    else
		;
        //printf("Image file successfully loaded!\n");

    fclose(fp);

    printf("--------------------------------init_mem done------------------------------\n");
	return size;

}




uint32_t pmem_read(uint32_t addr, uint8_t byte){
    if(addr < 0x80000000 || addr > 0x8fffffff){
        printf("\033[31maddr %#8.8x is not valid for reading\033[0m\n",addr);
        return 0;
    }
    addr = addr - 0x80000000;
    if(byte == 0b001)//unsigned 1 byte
        return (uint32_t)memory[addr];

    else if(byte == 0b010)//unsigned 2 bytes
        return (uint32_t)((memory[addr+1]<<8)|memory[addr]);

    else if(byte == 0b100)//4 bytes
        return (memory[addr] | (uint32_t)memory[addr+1] << 8
                | (uint32_t)memory[addr+2] << 16
                | (uint32_t)memory[addr+3] << 24);

    else if(byte == 0b101)//signed 1 byte
        return memory[addr] >> 7 ? (0xffffff00|memory[addr]) : (uint32_t)memory[addr];

    else if(byte == 0b110)//signed 2 bytes
        return memory[addr+1] >> 7 ? (0xffff0000|(memory[addr+1]<<8)|memory[addr]) :
                                    (uint32_t)((memory[addr+1]<<8)|memory[addr]);

    else
        return 0;
}



void pmem_write(uint32_t addr, uint8_t byte, uint32_t data){
    //printf("in pmem_write, addr = %#8.8x\n",addr);
    if(addr < 0x80000000 || addr > 0x8fffffff){
        printf("\033[31maddr %#8.8x is not valid for writing\033[0m\n",addr);
        return;
    }
    addr = addr - 0x80000000;
    if(byte == 0b01)
        memory[addr] = (uint8_t)data;
    else if(byte == 0b10){
        memory[addr] = (uint8_t)data;
        memory[addr+1] = (uint8_t)(data >> 8);
    }
    else if(byte == 0b11){
        memory[addr] = (uint8_t)data;
        memory[addr+1] = (uint8_t)(data >> 8);
        memory[addr+2] = (uint8_t)(data >> 16);
        memory[addr+3] = (uint8_t)(data >> 24);
    }
}




extern "C" int pmem_read_(uint32_t raddr, bool ren){
	//printf("in pmem_read_, %x\n",raddr);
	if(!ren)
		return 0;

	//有关时钟
	if(raddr >= RTC_ADDR && raddr <= RTC_ADDR + 7){
		//printf("%x\n",raddr);
		difftest_to_skip = true;
		if(raddr == RTC_ADDR){
			timer_addr[0] = (uint32_t)get_time();
			return timer_addr[0];
		}
		else if(raddr == RTC_ADDR + 4){
			timer_addr[1] = (uint32_t)(get_time() >> 32);
			return timer_addr[1];
		}
		return 0;
	}

	difftest_to_skip = false;

	if(raddr < 0x80000000 || raddr > 0x8fffffff){
        printf("\033[31maddr %#8.8x is not valid for reading\033[0m\n",raddr);
        return 0;
    }
	raddr = raddr - 0x80000000;
	return (memory[raddr] | (uint32_t)memory[raddr+1] << 8
                | (uint32_t)memory[raddr+2] << 16
                | (uint32_t)memory[raddr+3] << 24);
}



//这边需要模拟 outl、inl等函数的功能
//0xa00003f8 - 0xa00003ff 串口
//0xa0000100 - 0xa0000103 GPU屏幕尺寸
//0xa0000104 - 0xa0000107 GPU的同步寄存器
//0xa1000000 - 0xa1000000 + 300*400*4 - 1  帧缓冲寄存器


extern "C" void pmem_write_(uint32_t waddr, int wdata, char wmask){
    //写串口
	if(waddr >= SERIAL_PORT && waddr <= SERIAL_PORT + 7){
		assert(wmask == 0b00000001);
		serial_port[0] = (uint8_t)wdata;
		putc((uint8_t)wdata, stderr);
		return;
	}

	//写VGA控制寄存器
	if(waddr >= VGACTL_ADDR && waddr <= VGACTL_ADDR + 7){
		update_vgactl_addr(waddr, wdata, wmask);
		return;
	}

	//写帧缓冲寄存器
	if(waddr >= FB_ADDR && waddr <= FB_ADDR + SCREEN_SIZE - 1){
		update_fb_addr(waddr, wdata, wmask);
		return;
	}


	//非法地址
	if(waddr < 0x80000000 || waddr > 0x8fffffff){
        printf("\033[31maddr %#8.8x is not valid for writing\033[0m\n", waddr);
        return;
    }
    waddr = waddr - 0x80000000;
    if(wmask == 0b00000001)
        memory[waddr] = (uint8_t)wdata;
    else if(wmask == 0b00000011){
        memory[waddr] = (uint8_t)wdata;
        memory[waddr+1] = (uint8_t)(wdata >> 8);
    }
    else if(wmask == 0b00001111){
        memory[waddr] = (uint8_t)wdata;
        memory[waddr+1] = (uint8_t)(wdata >> 8);
        memory[waddr+2] = (uint8_t)(wdata >> 16);
        memory[waddr+3] = (uint8_t)(wdata >> 24);
    }
}



void update_devices(){
	update_vga_screen();

}

