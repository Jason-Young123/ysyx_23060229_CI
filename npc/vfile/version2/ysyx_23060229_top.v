`include "ysyx_23060229_IDU.v"
`include "ysyx_23060229_EXU.v"
`include "ysyx_23060229_Register.v"
`include "ysyx_23060229_Memory.v"


module ysyx_23060229_top(
	input clk,
	input rst,
	output [31:0] inst,
	output [31:0] pc
);

	wire [6:0] typ;
	wire [4:0] rs1,rs2;
	wire [4:0] rd;
	wire [31:0] imm;
	wire reg_wen;
	wire [1:0] mem_wen,mem_ren;
	wire [31:0] reg_din;
	wire [31:0] src1,src2;

	wire [31:0] pc_tmp;
	
	wire [31:0] mem_addr_in, mem_addr_out;
	wire [31:0] mem_din, mem_dout;


	assign mem_addr_in = src1 + imm;
	assign mem_addr_out = src1 + imm;

	ysyx_23060229_IDU myidu (inst, typ, rs1, rs2, rd, imm, reg_wen, mem_wen, mem_ren);

	ysyx_23060229_Register myreg (clk, rst, reg_wen, reg_din, pc_tmp, rd, rs1, rs2, src1, src2, pc);

	ysyx_23060229_Memory mymem (clk, rst, mem_wen, mem_ren, mem_din, mem_addr_in, pc, mem_addr_out, inst, mem_dout);

	ysyx_23060229_EXU muexu (rst, pc, typ, src1, src2, imm, mem_dout, mem_din, reg_din, pc_tmp);


endmodule
