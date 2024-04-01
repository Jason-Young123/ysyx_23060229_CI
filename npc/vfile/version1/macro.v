`ifndef MACRO_V
`define MACRO_V

	`define ysyx_23060229_I_ADDI 7'b0000000//type 1: write reg with reg
	`define ysyx_23060229_I_LW 7'b0000001//type 2: write reg with mem
	`define ysyx_23060229_S_SB 7'b0000010//type 3: write mem with reg
	`define ysyx_23060229_S_SW 7'b0000011
	`define ysyx_23060229_S_SH 7'b0000110
	`define ysyx_23060229_EBREAK 7'b1111110
	`define ysyx_23060229_NONE 7'b1111111


`endif

