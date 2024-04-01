//`timescale 10ns/1ns
`include "macro.v"

/* verilator lint_off WIDTHEXPAND */
module EXU(
	input clk,
	input [2:0] EXU_en,
	input [6:0] tp,
	input [4:0] rs1,
	input [4:0] rs2,
	input [4:0] rd,
	input [31:0] imm,
	output reg reg_wen,//write to reg
	output reg reg_ren,
	output reg[6:0] reg_addr,
	output reg[31:0] reg_wdata,
	input [31:0] reg_rdata,
	output reg mem_wen,//write to mem
	output reg mem_ren,
	output reg[31:0] mem_addr,
	output reg[31:0] mem_wdata,
	input [31:0] mem_rdata,
	output reg[1:0] mem_wbyte,
	output reg halt,//unknown inst met
	output reg ebreak,//program exit successfully
	input [31:0] pc
);

	reg [31:0] src1,src2;
	


	always @(posedge clk) begin
		case(EXU_en)
			3'b000: begin// prepare to read reg
				reg_ren <= 1; reg_wen <= 0; reg_addr <= {rs1};
			end
			3'b001: begin// read reg to get R(rs1)
				src1 <= reg_rdata; reg_addr <= rs2;
			end
			3'b010: begin// read reg to get R(rs2); prepare to read mem
				src2 <= reg_rdata; reg_ren <= 0;
			   	mem_ren <= 1; mem_wen <= 0; mem_addr <= src1 + imm;
			end
			3'b011: begin// write reg or write mem
				if(tp == `S_SW || tp == `S_SH || tp == `S_SB) begin//write mem
					mem_wen <= 1; mem_ren <= 0; 
					mem_addr <= src1 + imm; mem_wdata <= src2;
					case(tp)
						`S_SW: mem_wbyte <= 2'b11; //write 4 bytes to mem
						`S_SH: mem_wbyte <= 2'b01; //write 2 bytes to mem
						default: mem_wbyte <= 2'b00; //write 1 byte to mem
					endcase
				end

				else if(tp == `I_ADDI || tp == `I_LW) begin//write reg
					reg_wen <= 1; reg_ren <= 0; reg_addr <= rd;
					case(tp)
						`I_ADDI: reg_wdata <= src1 + imm;//write to reg with reg
						`I_LW: reg_wdata <= mem_rdata;//write to reg with mem
						default: reg_wdata <= 32'b0;
					endcase
				end

				else if(tp == `EBREAK) begin
					ebreak <= 1;
				end
				else
					halt <= 1;
			end
			3'b100: begin //write pc to reg
				reg_wen <= 1; reg_ren <= 0; reg_addr <= 6'b100000;
				reg_wdata <= pc + 4;  mem_wen <= 0;
			end

			default: begin//release control of reg and mem
				reg_ren <= 0; reg_wen <= 0; reg_addr <= 7'b0; reg_wdata <= 32'b0;
				mem_ren <= 0; mem_wen <= 0; mem_addr <= 32'b0; mem_wdata <= 32'b0;
				halt <= 0; ebreak <= 0;
			end


		endcase
	
	end



endmodule
