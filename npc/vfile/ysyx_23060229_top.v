`include "ysyx_23060229_IDU.v"
`include "ysyx_23060229_EXU.v"
`include "ysyx_23060229_Register.v"
`include "ysyx_23060229_CSRegister.v"


module ysyx_23060229_top(
	input clk,
	input rst,
	//output [31:0] src1,//mem-related for addr
	//output [31:0] imm,//mem-related for addr
	output [31:0] inst,// mem-related
	//input [31:0] data_from_mem,//mem-related
	//output [31:0] data_to_mem,//mem-related
	output [31:0] pc,//mem-related
	//output [2:0] mem_rd_quest,//mem-related
	//output [1:0] mem_wr_quest,//mem-related
	output [31:0] regs [31:0]
);
	wire [5:0] typ;
	wire [4:0] rs1,rs2;
	wire [4:0] rd;
	wire [31:0] imm;
	wire reg_wen;
	wire [31:0] reg_din;
	wire [31:0] src1,src2;
	
	wire [1:0] csreg_wen; //对于一般csr指令取值为2'b01,对于ecall指令取值为2'b10
	wire [11:0] csreg_waddr;
	wire [11:0] csreg_raddr;
	wire [31:0] csreg_din;
	wire [31:0] csreg_dout;
	
	wire mem_ren;
	wire mem_wen;
	wire [7:0] mem_wmask;
	wire [31:0] mem_waddr;
	wire [31:0] mem_raddr;
	wire [31:0] mem_wdata;
	wire [31:0] mem_rdata;

	wire [31:0] pc_tmp;


	assign mem_raddr = src1 + imm;
	assign mem_waddr = src1 + imm;
	
	assign csreg_raddr = imm[31:20];
	assign csreg_waddr = imm[31:20];


	ysyx_23060229_IDU myidu (inst, typ, rs1, rs2, rd, imm, reg_wen, csreg_wen, mem_ren, mem_wen, mem_wmask);

	ysyx_23060229_CSRegister mycsreg (clk, rst, csreg_wen, pc, csreg_din, csreg_waddr, csreg_raddr, csreg_dout);

	ysyx_23060229_Register myreg (clk, rst, reg_wen, reg_din, pc_tmp, rd, rs1, rs2, src1, src2, pc, regs);

	ysyx_23060229_Memory mymem(clk, rst, mem_ren, mem_wen, mem_wmask, mem_wdata, mem_waddr, pc, mem_raddr, inst, mem_rdata);

	ysyx_23060229_EXU muexu (rst, pc, typ, src1, src2, imm, mem_rdata, csreg_dout, mem_wdata, reg_din, pc_tmp, csreg_din);



endmodule
