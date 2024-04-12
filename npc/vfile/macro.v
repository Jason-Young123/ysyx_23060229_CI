`ifndef MACRO_V
`define MACRO_V

	//type 1: write reg with reg
	//type 2: write reg with mem
	//type 3: write mem with reg
	
	import "DPI-C" function int pmem_read_(input int raddr, input bit ren);
	import "DPI-C" function void pmem_write_(input int waddr, input int wdata, input byte wmask);
	import "DPI-C" function void hit_good_trap();
	import "DPI-C" function void hit_bad_trap();

	
	`define MSTATUS		12'h300
	`define MTVEC		12'h305
	`define MEPC 		12'h341
	`define MCAUSE		12'h342


	`define ysyx_23060229_U_AUIPC 	6'b000001
	`define ysyx_23060229_U_LUI		6'b000010

	//type 1: write mem with reg
	`define ysyx_23060229_S_SB		6'b000011
	`define ysyx_23060229_S_SH		6'b000100
	`define ysyx_23060229_S_SW		6'b000101
	


	`define ysyx_23060229_B_BEQ		6'b000110
    `define ysyx_23060229_B_BNE     6'b000111
    `define ysyx_23060229_B_BLT     6'b001000
    `define ysyx_23060229_B_BLTU    6'b001001
    `define ysyx_23060229_B_BGE     6'b001010
    `define ysyx_23060229_B_BGEU    6'b001011



	`define ysyx_23060229_R_ADD		6'b001100
	`define ysyx_23060229_R_SUB     6'b001101
	`define ysyx_23060229_R_XOR     6'b001110
	`define ysyx_23060229_R_OR      6'b001111
	`define ysyx_23060229_R_AND     6'b010000
	`define ysyx_23060229_R_SLT     6'b010001
	`define ysyx_23060229_R_SLTU    6'b010010
	`define ysyx_23060229_R_SLL     6'b010011
	`define ysyx_23060229_R_SRL     6'b010100
	`define ysyx_23060229_R_SRA     6'b010101



	`define ysyx_23060229_M_MUL     6'b010110
	`define ysyx_23060229_M_MULH    6'b010111
	`define ysyx_23060229_M_MULHSU  6'b011000
	`define ysyx_23060229_M_MULHU   6'b011001
	`define ysyx_23060229_M_DIV     6'b011010
	`define ysyx_23060229_M_DIVU    6'b011011
	`define ysyx_23060229_M_REM     6'b011100
	`define ysyx_23060229_M_REMU    6'b011101
	


	//type 2 & 3: write reg with reg/mem
	`define ysyx_23060229_I_LB      6'b011110
	`define ysyx_23060229_I_LH      6'b011111
	`define ysyx_23060229_I_LW      6'b100000
	
	`define ysyx_23060229_I_LBU  	6'b100001
	`define ysyx_23060229_I_LHU   	6'b100010
	
	`define ysyx_23060229_I_ADDI    6'b100011
	`define ysyx_23060229_I_ANDI    6'b100100
	`define ysyx_23060229_I_ORI  	6'b100101
	`define ysyx_23060229_I_XORI  	6'b100110
	`define ysyx_23060229_I_SLTI    6'b100111
	`define ysyx_23060229_I_SLTIU   6'b101000
	
	`define ysyx_23060229_I_SLLI    6'b101001
	`define ysyx_23060229_I_SRLI 	6'b101010
	`define ysyx_23060229_I_SRAI    6'b101011
	
	//CSR
	`define ysyx_23060229_I_CSRRW	6'b101100
	`define ysyx_23060229_I_CSRRWI	6'b101101
	`define ysyx_23060229_I_CSRRS	6'b101110
	`define ysyx_23060229_I_CSRRSI	6'b101111
	`define ysyx_23060229_I_CSRRC	6'b110000
	`define ysyx_23060229_I_CSRRCI	6'b110001
	
	`define ysyx_23060229_I_JALR    6'b110010


	`define ysyx_23060229_J_JAL     6'b110011


	`define ysyx_23060229_ECALL		6'b110100
	`define ysyx_23060229_MRET		6'b110101
	
	`define ysyx_23060229_EBREAK    6'b110110
	`define ysyx_23060229_NONE		6'b110111


`endif

