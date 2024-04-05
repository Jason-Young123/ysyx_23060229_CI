//import "DPI-C" function int pmem_read_(input int raddr);
//import "DPI-C" function void pmem_write_(input int waddr, input int wdata, input byte wmask);
//import "DPI-C" function void hit_good_trap();
//import "DPI-C" function void hit_bad_trap();

`include "ysyx_23060229_arith_shifter.v"
`include "ysyx_23060229_scomp.v"
`include "macro.v"

//combinational circuit, depending on the latest state
module ysyx_23060229_EXU(
	input rst,
	input [31:0] pc,//to top module
	input [5:0] typ,
	input [31:0] src1,
	input [31:0] src2,
	input [31:0] imm,
	input [31:0] mem_rdata,
	output reg[31:0] mem_wdata,
	output reg[31:0] reg_din,
	output reg[31:0] pcout
);
	
	//some sub-module for specific operations
	wire [31:0] arith_shifter_out;
	ysyx_23060229_arith_shifter myarith_shifter(src1, src2[4:0], arith_shifter_out);
	wire [31:0] arith_shifter_out1;
	ysyx_23060229_arith_shifter myarith_shifter1(src1, imm[4:0], arith_shifter_out1);

	wire [31:0] scomp_out;
	ysyx_23060229_scomp myscomp(src1, src2, scomp_out);
	wire [31:0] scomp_out1;
	ysyx_23060229_scomp myscomp1(src1, imm, scomp_out1);


	always@(*) begin
		if(rst) begin
			//$display("Reset ..."); 
			mem_wdata = 0; reg_din = 0; pcout = pc;
		end
		else
			case(typ)

				//U-type
				`ysyx_23060229_U_AUIPC: begin reg_din = pc + imm; 	mem_wdata = 0; 		pcout = pc + 4; end
				`ysyx_23060229_U_LUI:	begin reg_din = imm;		mem_wdata = 0;		pcout = pc + 4; end

				//S-type
				`ysyx_23060229_S_SB:    begin reg_din = 0;			mem_wdata = src2; 		pcout = pc + 4; end
                `ysyx_23060229_S_SH:    begin reg_din = 0;			mem_wdata = src2;		pcout = pc + 4; end
                `ysyx_23060229_S_SW:    begin reg_din = 0;			mem_wdata = src2;		pcout = pc + 4; end

				//B-type
				`ysyx_23060229_B_BEQ:	begin reg_din = 0;	mem_wdata = 0;		pcout = (src1==src2 ? pc+imm : pc+4); end
				`ysyx_23060229_B_BNE:   begin reg_din = 0;  mem_wdata = 0;    	pcout = (src1!=src2 ? pc+imm : pc+4); end
				`ysyx_23060229_B_BLT:   begin reg_din = 0;  mem_wdata = 0;		pcout = (scomp_out[0] ? pc+imm : pc+4); end//!
				`ysyx_23060229_B_BLTU:  begin reg_din = 0;  mem_wdata = 0;   	pcout = (src1<src2 ? pc+imm : pc+4); end
				`ysyx_23060229_B_BGE:   begin reg_din = 0;  mem_wdata = 0;    	pcout = (~scomp_out[0] ? pc+imm : pc+4); end//!
				`ysyx_23060229_B_BGEU:  begin reg_din = 0;  mem_wdata = 0;    	pcout = (src1>=src2 ? pc+imm : pc+4); end

				//R-type
				/* verilator lint_off WIDTHEXPAND */
				`ysyx_23060229_R_ADD:	begin reg_din = src1 + src2;		mem_wdata = 0;		pcout = pc + 4; end
				`ysyx_23060229_R_SUB:   begin reg_din = src1 - src2;    	mem_wdata = 0;    	pcout = pc + 4; end
				`ysyx_23060229_R_XOR:   begin reg_din = src1 ^ src2;    	mem_wdata = 0;    	pcout = pc + 4; end
				`ysyx_23060229_R_OR:    begin reg_din = src1 | src2;    	mem_wdata = 0;    	pcout = pc + 4; end
				`ysyx_23060229_R_AND:   begin reg_din = src1 & src2;    	mem_wdata = 0;    	pcout = pc + 4; end
				`ysyx_23060229_R_SLT:   begin reg_din = scomp_out; 			mem_wdata = 0;    	pcout = pc + 4; end
				`ysyx_23060229_R_SLTU:  begin reg_din = src1 < src2;    	mem_wdata = 0;    	pcout = pc + 4; end
				`ysyx_23060229_R_SLL:   begin reg_din = src1 << src2[4:0];	mem_wdata = 0;    	pcout = pc + 4; end//!
				`ysyx_23060229_R_SRL:   begin reg_din = src1 >> src2[4:0];  mem_wdata = 0;    	pcout = pc + 4; end
				`ysyx_23060229_R_SRA:   begin reg_din = arith_shifter_out;	mem_wdata = 0;		pcout = pc + 4; end//!
				/* verilator lint_on WIDTHEXPAND */

				//M-type
				`ysyx_23060229_M_MUL:	begin reg_din = 0; 				mem_wdata = 0;	pcout = pc + 4;	end//!
				`ysyx_23060229_M_MULH:	begin reg_din = 0; 				mem_wdata = 0;	pcout = pc + 4;	end//!
				`ysyx_23060229_M_MULHSU:begin reg_din = 0; 				mem_wdata = 0;	pcout = pc + 4;	end//!
				`ysyx_23060229_M_MULHU:	begin reg_din = 0; 				mem_wdata = 0;	pcout = pc + 4;	end//!
				`ysyx_23060229_M_DIV:	begin reg_din = 0; 				mem_wdata = 0;	pcout = pc + 4;	end//!
				`ysyx_23060229_M_DIVU:	begin reg_din = 0; 				mem_wdata = 0;	pcout = pc + 4;	end//!
				`ysyx_23060229_M_REM:	begin reg_din = 0; 				mem_wdata = 0;	pcout = pc + 4;	end//!
				`ysyx_23060229_M_REMU:	begin reg_din = 0; 				mem_wdata = 0;	pcout = pc + 4;	end//!


				//I-type
				//type 2: read mem + write reg
                `ysyx_23060229_I_LB:    begin reg_din = {{24{mem_rdata[7]}}, mem_rdata[7:0]};	mem_wdata = 0; 	pcout = pc + 4; end
                `ysyx_23060229_I_LH:    begin reg_din = {{16{mem_rdata[15]}},mem_rdata[15:0]}; 	mem_wdata = 0;	pcout = pc + 4; end
                `ysyx_23060229_I_LW:    begin reg_din = mem_rdata; 								mem_wdata = 0; 	pcout = pc + 4; end
                `ysyx_23060229_I_LBU:   begin reg_din = {24'b0, mem_rdata[7:0]}; 				mem_wdata = 0;	pcout = pc + 4; end
                `ysyx_23060229_I_LHU:   begin reg_din = {16'b0, mem_rdata[15:0]}; 				mem_wdata = 0;	pcout = pc + 4; end
				
				//type 1: read reg + write reg
				/* verilator lint_off WIDTHEXPAND */
				`ysyx_23060229_I_ADDI:	begin reg_din = src1 + imm; 			mem_wdata = 0;	pcout = pc + 4; end
				`ysyx_23060229_I_ANDI:	begin reg_din = src1 & imm; 			mem_wdata = 0;	pcout = pc + 4; end
				`ysyx_23060229_I_ORI:	begin reg_din = src1 | imm; 			mem_wdata = 0;	pcout = pc + 4; end
				`ysyx_23060229_I_XORI:	begin reg_din = src1 ^ imm; 			mem_wdata = 0;	pcout = pc + 4; end
				`ysyx_23060229_I_SLTI:	begin reg_din = scomp_out1;				mem_wdata = 0; 	pcout = pc + 4; end
				`ysyx_23060229_I_SLTIU:	begin reg_din = src1 < imm; 			mem_wdata = 0;	pcout = pc + 4; end
				
				`ysyx_23060229_I_SLLI:	begin reg_din = src1 << imm[4:0];		mem_wdata = 0; 	pcout = pc + 4; end//!
				`ysyx_23060229_I_SRLI:	begin reg_din = src1 >> imm[4:0]; 		mem_wdata = 0;	pcout = pc + 4; end
				`ysyx_23060229_I_SRAI:	begin reg_din = arith_shifter_out1;		mem_wdata = 0;	pcout = pc + 4; end//!

				`ysyx_23060229_I_JALR:	begin reg_din = pc + 4;					mem_wdata = 0;	pcout = (src1 + imm)&(32'hffff_fffe); end
				/* verilator lint_on WIDTHEXPAND */

				//J-type
				`ysyx_23060229_J_JAL:	begin reg_din = pc + 4;			mem_wdata = 0;	pcout = pc + imm; end

				//type 4: others
				`ysyx_23060229_EBREAK:	begin mem_wdata = 0; reg_din = 0; pcout = pc; hit_good_trap(); end
				`ysyx_23060229_NONE:	begin mem_wdata = 0; reg_din = 0; pcout = pc; hit_bad_trap(); end
				default:				begin mem_wdata = 0; reg_din = 0; pcout = pc; hit_bad_trap(); end

			endcase
	
	end



endmodule

