TOP_MODULE = top

CONSTR = ./constr
VFILE = ./vfile
BOARDSIM_FILE = ./boardsim_file
WAVESIM_FILE = ./wavesim_file

VERILATOR_CFLAGS += -MMD --build -cc -O3 --x-assign fast \
					--x-initial fast --noassert


include $(NVBOARD_HOME)/scripts/nvboard.mk
include ../../Makefile


# to convert .v/.sv files into .c files
convert:
	verilator -cc $(VFILE)/$(TOP_MODULE).v -I$(VFILE)


constrgen:
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py  $(CONSTR)/$(TOP_MODULE).nxdc  $(CONSTR)/auto_bind.cpp

constrclean:
	rm $(CONSTR)/auto_bind.cpp


boardsim:
	$(call git_commit, "boardsim in exp2")
	verilator $(VERILATOR_CFLAGS) \
	--top-module $(TOP_MODULE) $(VFILE)/$(TOP_MODULE).v  $(CONSTR)/auto_bind.cpp  $(BOARDSIM_FILE)/boardsim.cpp  $(NVBOARD_HOME)/build/nvboard.a \
    -CFLAGS -MMD -CFLAGS -O3 -CFLAGS -I/usr/include/SDL2 -CFLAGS -D_REENTRANT -CFLAGS -I/home/jason/nvboard-master/usr/include -CFLAGS -DTOP_NAME="\"V$(TOP_MODULE)\"" -LDFLAGS -lSDL2 -LDFLAGS -lSDL2_image -LDFLAGS -lSDL2_ttf \
	--Mdir obj_dir --exe -o $(TOP_MODULE) -I$(VFILE)
	cp obj_dir/$(TOP_MODULE) $(BOARDSIM_FILE)/$(TOP_MODULE)_board

board:
	$(BOARDSIM_FILE)/$(TOP_MODULE)_board

boardclean:
	rm $(BOARDSIM_FILE)/$(TOP_MODULE)_board


wavesim:
	$(call git_commit, "wavesim in exp2")
	verilator -Wall --trace -cc $(VFILE)/$(TOP_MODULE).v --exe $(WAVESIM_FILE)/wavesim.cpp -I$(VFILE)
	make -C obj_dir -f V$(TOP_MODULE).mk V$(TOP_MODULE)
	cp obj_dir/V$(TOP_MODULE) $(WAVESIM_FILE)/$(TOP_MODULE)_wave

wave:
	$(WAVESIM_FILE)/$(TOP_MODULE)_wave
	gtkwave $(WAVESIM_FILE)/wave.vcd

waveclean:
	rm $(WAVESIM_FILE)/$(TOP_MODULE)_wave
	rm $(WAVESIM_FILE)/wave.vcd


clean:
	rm ./obj_dir/*
	make constrclean
	make boardclean
	make waveclean



