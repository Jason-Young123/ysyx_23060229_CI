`ifndef MACRO_V
`define MACRO_V

	`define I_ADDI 7'b0000000//type 1: write reg with reg
	`define I_LW 7'b0000001//type 2: write reg with mem
	`define S_SB 7'b0000010//type 3: write mem with reg
	`define S_SW 7'b0000011
	`define S_SH 7'b0000110
	`define EBREAK 7'b1111110
	`define NONE 7'b1111111


`endif

