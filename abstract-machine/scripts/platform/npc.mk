VERSION=V4

AM_SRCS := riscv/npc/start.S \
           riscv/npc/trm.c \
           riscv/npc/ioe/ioe.c \
           riscv/npc/ioe/timer.c \
           riscv/npc/ioe/input.c \
		   riscv/npc/ioe/audio.c \
		   riscv/npc/ioe/gpu.c \
           riscv/npc/cte.c \
           riscv/npc/trap.S \
           platform/dummy/vme.c \
           platform/dummy/mpe.c

CFLAGS    += -fdata-sections -ffunction-sections
LDFLAGS   += -T $(AM_HOME)/scripts/linker.ld \
						 --defsym=_pmem_start=0x80000000 --defsym=_entry_offset=0x0
LDFLAGS   += --gc-sections -e _start
CFLAGS += -DMAINARGS=\"$(mainargs)\"

CFLAGS += -I$(AM_HOME)/am/src/riscv/npc/include

.PHONY: $(AM_HOME)/am/src/riscv/npc/trm.c

$(info #include out2--------------------, $(IMAGE), $(NAME))


image: $(IMAGE).elf
	@echo $(OBJDUMP) -d $(IMAGE).elf > $(IMAGE).txt
	@echo + OBJCOPY "->" $(IMAGE_REL).bin
	@echo $(OBJCOPY) -S --set-section-flags .bss=alloc,contents -O binary $(IMAGE).elf $(IMAGE).bin


run: image
	$(MAKE) -C $(NPC_$(VERSION)_HOME) wave BIN=$(IMAGE).bin

