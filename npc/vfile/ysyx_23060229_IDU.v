`include "macro.v"

//IDU (combinational)
module ysyx_23060229_IDU(
	//input en,
	//input rst,
	input [31:0] inst,
	output reg[5:0] typ,
	output reg[4:0] rs1,
	output reg[4:0] rs2,
	output reg[4:0] rd, //directly connected to reg::addr_in
	output reg[31:0] imm,
	output reg reg_wen, //directly connected to reg::wen
	//output reg reg_wr,//to write reg
	output reg mem_ren,
	output reg mem_wen,
	output reg[7:0] mem_wmask
	//output reg[2:0] mem_rd_quest//to write mem, to top module
	//output reg[31:0] pc
);

	always@(inst) begin
		/*if(rst) begin
			$display("rst");
			reg_wen = 1; mem_ren = 0; mem_rd_quest = 0; pc = 32'h80000000;
			typ = 0; rs1 = 0; rs2 = 0; rd = 0;
		end*/

		//else
            casez(inst)
				//U-type
				32'b???????_?????_?????_???_?????_0010111: begin
					reg_wen = 1; mem_ren = 0; mem_wen = 0; mem_wmask = 0;
					typ = `ysyx_23060229_U_AUIPC; imm = {inst[31:12],12'h0000};
					rs1 = 0; rs2 = 0; rd = inst[11:7];
				end

				32'b???????_?????_?????_???_?????_0110111: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_U_LUI; imm = {inst[31:12],12'h0000};
                    rs1 = 0; rs2 = 0; rd = inst[11:7];
                end

				//S-type
				//type 3: read reg + write mem
                32'b???????_?????_?????_000_?????_0100011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 1; mem_wmask = 8'b00000001;
                    typ = `ysyx_23060229_S_SB; imm = {{20{inst[31]}},inst[31:25],inst[11:7]};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
                end

                32'b???????_?????_?????_001_?????_0100011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 1; mem_wmask = 8'b00000011;
                    typ = `ysyx_23060229_S_SH; imm = {{20{inst[31]}},inst[31:25],inst[11:7]};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
                end

				32'b???????_?????_?????_010_?????_0100011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 1; mem_wmask = 8'b00001111;
                    typ = `ysyx_23060229_S_SW; imm = {{20{inst[31]}},inst[31:25],inst[11:7]};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
                end

				//B-type
				32'b???????_?????_?????_000_?????_1100011: begin
					reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
					typ = `ysyx_23060229_B_BEQ; imm = {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
					rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
				end

				32'b???????_?????_?????_001_?????_1100011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_B_BNE; imm = {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
                end

				32'b???????_?????_?????_100_?????_1100011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_B_BLT; imm = {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
                end

				32'b???????_?????_?????_110_?????_1100011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_B_BLTU; imm = {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
                end

				32'b???????_?????_?????_101_?????_1100011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_B_BGE; imm = {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
                end

				32'b???????_?????_?????_111_?????_1100011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_B_BGEU; imm = {{19{inst[31]}},inst[31],inst[7],inst[30:25],inst[11:8],1'b0};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = 0;
                end


				//R-type
				32'b0000000_?????_?????_000_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_R_ADD; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0100000_?????_?????_000_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_R_SUB; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000000_?????_?????_100_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_R_XOR; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000000_?????_?????_110_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_R_OR; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000000_?????_?????_111_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_R_AND; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000000_?????_?????_010_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_R_SLT; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000000_?????_?????_011_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_R_SLTU; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end
				
				32'b0000000_?????_?????_001_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_R_SLL; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000000_?????_?????_101_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_R_SRL; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0100000_?????_?????_101_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_R_SRA; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end


				//M-type
				32'b0000001_?????_?????_000_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_M_MUL; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000001_?????_?????_001_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_M_MULH; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000001_?????_?????_010_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_M_MULHSU; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000001_?????_?????_011_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_M_MULHU; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000001_?????_?????_100_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_M_DIV; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000001_?????_?????_101_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_M_DIVU; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000001_?????_?????_110_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_M_REM; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000001_?????_?????_111_?????_0110011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_M_REMU; imm = 0;
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end
			

				//I-type
				//type 2: read mem + write reg
                32'b???????_?????_?????_000_?????_0000011: begin
                    reg_wen = 1; mem_ren = 1;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_LB; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end

				32'b???????_?????_?????_001_?????_0000011: begin
                    reg_wen = 1; mem_ren = 1;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_LH; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end

				32'b???????_?????_?????_010_?????_0000011: begin
                    reg_wen = 1; mem_ren = 1;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_LW; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end
				
				32'b???????_?????_?????_100_?????_0000011: begin
                    reg_wen = 1; mem_ren = 1;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_LBU; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end

				32'b???????_?????_?????_101_?????_0000011: begin
                    reg_wen = 1; mem_ren = 1; mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_LHU; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end


				//type 1: read reg + write reg
                32'b???????_?????_?????_000_?????_0010011: begin
					reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_ADDI; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end

				32'b???????_?????_?????_111_?????_0010011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_ANDI; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end

				32'b???????_?????_?????_110_?????_0010011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_ORI; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end

				32'b???????_?????_?????_100_?????_0010011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_XORI; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end

				32'b???????_?????_?????_010_?????_0010011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_SLTI; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end

				32'b???????_?????_?????_011_?????_0010011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_SLTIU; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end

				//special
				32'b0000000_?????_?????_001_?????_0010011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_SLLI; imm = {27'b0, inst[24:20]};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0000000_?????_?????_101_?????_0010011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_SRLI; imm = {27'b0, inst[24:20]};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b0100000_?????_?????_101_?????_0010011: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_SRAI; imm = {27'b0, inst[24:20]};
                    rs1 = inst[19:15]; rs2 = inst[24:20]; rd = inst[11:7];
                end

				32'b???????_?????_?????_000_?????_1100111: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_I_JALR; imm = {{20{inst[31]}},inst[31:20]};
                    rs1 = inst[19:15]; rs2 = 0; rd = inst[11:7];
                end

			
				//J-type
				32'b???????_?????_?????_???_?????_1101111: begin
                    reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_J_JAL; imm = {{11{inst[31]}},inst[31],inst[19:12],inst[20],inst[30:21],1'b0};
                    rs1 = 0; rs2 = 0; rd = inst[11:7];
                end



				//type 4: others
                32'b0000000_00001_00000_000_00000_1110011: begin//break
					reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_EBREAK; imm = 0; rs1 = 0; rs2 = 0; rd = 0;
                end

				//None
                default: begin
					reg_wen = 1; mem_ren = 0;  mem_wen = 0; mem_wmask = 0;
                    typ = `ysyx_23060229_NONE; imm = 0; rs1 = 0; rs2 = 0; rd = 0;
				end

            endcase
	end


endmodule

