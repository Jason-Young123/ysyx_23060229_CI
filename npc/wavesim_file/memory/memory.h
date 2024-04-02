#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <stdint.h>
#include <cassert>

#define MEM_SIZE  0xfffffff

#define DEVICE_BASE 0xa0000000
#define SERIAL_PORT     (DEVICE_BASE + 0x00003f8)
#define KBD_ADDR        (DEVICE_BASE + 0x0000060)
#define RTC_ADDR        (DEVICE_BASE + 0x0000048)
#define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)
#define AUDIO_ADDR      (DEVICE_BASE + 0x0000200)
#define DISK_ADDR       (DEVICE_BASE + 0x0000300)
#define FB_ADDR         (DEVICE_BASE + 0x1000000)
#define VGACTL_ADDR     (DEVICE_BASE + 0x0000100)


#define SCREEN_W 400
#define SCREEN_H 300
#define SCREEN_SIZE SCREEN_W * SCREEN_H * sizeof(int)


long init_mem(const char* img_file);
uint32_t pmem_read(uint32_t addr, uint8_t byte);
void pmem_write(uint32_t addr, uint8_t byte, uint32_t data);
extern "C" int pmem_read_(uint32_t raddr, bool ren);
extern "C" void pmem_write_(uint32_t waddr, int wdata, char wmask);

void update_devices();


uint64_t get_time(); //in timer.cpp


void init_vga();
void update_vga_screen();
void update_sync_addr(uint32_t waddr, int sync, char wmask);
void update_fb_addr(uint32_t waddr, int color, char wmask);


#endif
