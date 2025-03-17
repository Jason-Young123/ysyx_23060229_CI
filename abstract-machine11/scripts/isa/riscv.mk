CROSS_COMPILE := riscv64-linux-gnu-
#CROSS_COMPILE := riscv32-unknown-elf-
COMMON_CFLAGS := -fno-pic -march=rv64g -mcmodel=medany -mstrict-align
#COMMON_CFLAGS := -fno-pic -mcmodel=medany -mstrict-align
CFLAGS        += $(COMMON_CFLAGS) -static
ASFLAGS       += $(COMMON_CFLAGS) -O0
LDFLAGS       += -melf64lriscv

# overwrite ARCH_H defined in $(AM_HOME)/Makefile
ARCH_H := arch/riscv.h

#$(info #include out1--------------------)
