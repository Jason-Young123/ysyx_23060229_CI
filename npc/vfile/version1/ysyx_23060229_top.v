`include "ysyx_23060229_IDU.v"
`include "ysyx_23060229_EXU.v"
`include "ysyx_23060229_Register.v"

module ysyx_23060229_top(
	input clk,
	input rst,
	output [31:0] src1,//mem-related for addr
	output [31:0] imm,//mem-related for addr
	input [31:0] inst,// mem-related
	input [31:0] data_from_mem,//mem-related
	output [31:0] data_to_mem,//mem-related
	output [31:0] pc,//mem-related
	output [1:0] mem_rd_quest,//mem-related
	output [1:0] mem_wr_quest//mem-related

);
	wire [6:0] typ;
	wire [4:0] rs1,rs2;
	wire [4:0] rd;
	//wire [31:0] imm;
	wire reg_wen;
	wire [31:0] reg_din;
	wire [31:0] src2;

	wire [31:0] pc_tmp;


	ysyx_23060229_IDU myidu (inst, typ, rs1, rs2, rd, imm, reg_wen, mem_wr_quest, mem_rd_quest);

	ysyx_23060229_Register myreg (clk, rst, reg_wen, reg_din, pc_tmp, rd, rs1, rs2, src1, src2, pc);

	ysyx_23060229_EXU muexu (rst, pc, typ, src1, src2, imm, data_from_mem, data_to_mem, reg_din, pc_tmp);


endmodule
