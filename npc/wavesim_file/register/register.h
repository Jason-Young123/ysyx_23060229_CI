#ifndef REGISTER_H
#define REGISTER_H

#include <iostream>
#include <stdint.h>
#include "Vysyx_23060229_top.h"


#define NO_REG 32


void update_reg(Vysyx_23060229_top* top);
void display_reg();
uint32_t str2val_reg(const char *s, bool *success);

#endif

