//`define I_ADDI 7'b0000000//type 1: write reg with reg
//`define I_LW 7'b0000001//type 2: write reg with mem
//`define S_SB 7'b0000010//type 3: write mem with reg
//`define S_SW 7'b0000011
//`define S_SH 7'b0000110
//`define EBREAK 7'b1111111

//`timescale 10ns/1ns
`include "macro.v"


/* verilator lint_off CASEX */
module IDU(
	input clk,
	input IDU_en,
	input [31:0] inst,
	output reg[6:0] tp,
	output reg[4:0] rs1,
	output reg[4:0] rs2,
	output reg[4:0] rd,
	output reg[31:0] imm
);
	
	always @(posedge clk) begin
		if(IDU_en) begin
			casez(inst)
				32'b???????_?????_?????_000_?????_0010011: begin
					tp <= `I_ADDI; imm <= {{20{inst[31]}},inst[31:20]};
					rs1 <= inst[19:15]; rd <= inst[11:7]; rs2 <= 0;
				end
				32'b???????_?????_?????_010_?????_0000011: begin
					tp <= `I_LW; imm <= {{20{inst[31]}},inst[31:20]};
                    rs1 <= inst[19:15]; rd <= inst[11:7]; rs2 <= 0;
				end
				32'b???????_?????_?????_000_?????_0100011: begin
                    tp <= `S_SB; imm <= {{20{inst[31]}},inst[31:25],inst[11:7]};
                    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                end
				32'b???????_?????_?????_001_?????_0100011: begin
                    tp <= `S_SH; imm <= {{20{inst[31]}},inst[31:25],inst[11:7]};
                    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                end
				32'b???????_?????_?????_010_?????_0100011: begin
                    tp <= `S_SW; imm <= {{20{inst[31]}},inst[31:25],inst[11:7]};
                    rs1 <= inst[19:15]; rs2 <= inst[24:20]; rd <= 0;
                end
				32'b0000000_00000_00000_000_00000_1110011: begin//break
					tp <= `EBREAK; imm <= 0; rs1 <= 0; rs2 <= 0; rd <= 0;
				end
				default: begin
					tp <= `NONE; imm <= 0; rs1 <= 0; rs2 <= 0; rd <= 0;
				end

			endcase
		end
	
	end

endmodule
