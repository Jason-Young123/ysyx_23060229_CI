#ifndef MEMORY_H
#define MEMORY_H

#include <iostream>
#include <stdint.h>
#include <cassert>

#define MEM_SIZE  0xfffffff

long init_mem(const char* img_file);
uint32_t pmem_read(uint32_t addr, uint8_t byte);
void pmem_write(uint32_t addr, uint8_t byte, uint32_t data);
extern "C" int pmem_read_(uint32_t raddr, bool ren);
extern "C" void pmem_write_(uint32_t waddr, int wdata, char wmask);


uint64_t get_time(); //in timer.cpp


#endif
