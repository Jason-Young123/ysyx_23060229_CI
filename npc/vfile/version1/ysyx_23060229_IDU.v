`include "macro.v"

//IDU (combinational)
module ysyx_23060229_IDU(
	//input en,
	//input rst,
	input [31:0] inst,
	output reg[6:0] typ,
	output reg[4:0] rs1,
	output reg[4:0] rs2,
	output reg[4:0] rd, //directly connected to reg::addr_in
	output reg[31:0] imm,
	output reg reg_wen, //directly connected to reg::wen
	//output reg reg_wr,//to write reg
	output reg[1:0] mem_wr_quest,
	output reg[1:0] mem_rd_quest//to write mem, to top module
	//output reg[31:0] pc
);

	always@(inst) begin
		/*if(rst) begin
			$display("rst");
			reg_wen = 0; mem_rd_quest = 0; pc = 32'h80000000;
			typ = 0; rs1 = 0; rs2 = 0; rd = 0;
		end*/

		//else
            casez(inst)
				//type 1: read reg + write reg
                32'b???????_?????_?????_000_?????_0010011: begin
					reg_wen = 1;//to write reg at next posedge
                    typ = `ysyx_23060229_I_ADDI; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rd = inst[11:7]; rs2 = 0;
					//pc = pc + 4;
					mem_wr_quest = 0;
					mem_rd_quest = 0;
                end

				//type 2: read mem + write reg
                32'b???????_?????_?????_010_?????_0000011: begin
					reg_wen = 1;//to write reg at next posegde
                    typ = `ysyx_23060229_I_LW; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rd = inst[11:7]; rs2 = 0;
					//pc = pc + 4;
					mem_wr_quest = 0;
					mem_rd_quest = 2'b11;//generate EXU::data_from_mem
                end

				//type 3: read reg + write mem
                32'b???????_?????_?????_000_?????_0100011: begin
					reg_wen = 0;
                    typ = `ysyx_23060229_S_SB; imm = {{20{inst[31]}},inst[31:25],inst[11:7]};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
					//pc = pc + 4;
					mem_wr_quest = 2'b01;
					mem_rd_quest = 0;
                end

                32'b???????_?????_?????_001_?????_0100011: begin
					reg_wen = 0;
                    typ = `ysyx_23060229_S_SH; imm = {{20{inst[31]}},inst[31:25],inst[11:7]};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
					//pc = pc + 4;
					mem_wr_quest = 2'b10;
					mem_rd_quest = 0;
                end

                32'b???????_?????_?????_010_?????_0100011: begin
                    reg_wen = 0;
					typ = `ysyx_23060229_S_SW; imm = {{20{inst[31]}},inst[31:25],inst[11:7]};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
					//pc = pc + 4;
					mem_wr_quest = 2'b11;
					mem_rd_quest = 0;
                end

				//type 4: others
                32'b0000000_00000_00000_000_00000_1110011: begin//break
					reg_wen = 0;
                    typ = `ysyx_23060229_EBREAK; imm = 0; rs1 = 0; rs2 = 0; rd = 0;
					mem_wr_quest = 0;
					mem_rd_quest = 0;
                end

                default: begin
					reg_wen = 0;
                    typ = `ysyx_23060229_NONE; imm = 0; rs1 = 0; rs2 = 0; rd = 0;
                	mem_wr_quest = 0;
					mem_rd_quest = 0;
				end

            endcase
    end


endmodule

