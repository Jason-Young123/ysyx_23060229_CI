`timescale 10ns/1ns
`include "IFU.v"
`include "IDU.v"
`include "EXU.v"
`include "Memory.v"
`include "Register.v"
`include "Mux.v"
//`include "macro.v"

module Controller(
	input clk,
	input rst
);
    reg rst_mem,rst_reg;
	reg IFU_en,IDU_en;
	reg[2:0] EXU_en;
	reg halt,ebreak;

	wire reg_ren,reg_wen;
	wire [5:0] reg_addr;
	wire [31:0] reg_rdata, reg_wdata;
	wire [31:0] pc;

	wire mem_ren_IFU,mem_ren_EXU,mem_ren,mem_wen;
	wire [31:0] mem_addr_IFU,mem_addr_EXU,mem_addr;
	wire [31:0] mem_rdata, mem_wdata;
	wire [1:0] mem_wbyte;

	wire [31:0] inst;
	wire [6:0] tp;
	wire [4:0] rs1,rs2,rd;
	wire [31:0] imm;

	Mux #(1) mymux_mem_ren (IFU_en,mem_ren_IFU,mem_ren_EXU,mem_ren);

	Mux #(32) mymux_mem_addr (IFU_en,mem_addr_IFU,mem_addr_EXU,mem_addr);

	Register myreg (clk,rst_reg,reg_wdata,reg_rdata,pc,reg_addr,reg_wen,reg_ren);

	Memory mymem (clk,rst_mem,mem_wdata,mem_rdata,mem_addr,mem_wen,mem_ren,mem_wbyte);

	IFU myifu (clk,IFU_en,pc,mem_rdata,mem_ren_IFU,mem_addr_IFU,inst);

	IDU myidu (clk,IDU_en,inst,tp,rs1,rs2,rd,imm);

	EXU myexu (clk,EXU_en,tp,rs1,rs2,rd,imm,reg_wen,reg_ren,reg_addr,reg_wdata,reg_rdata,
				mem_wen,mem_ren_EXU,mem_addr_EXU,mem_wdata,mem_rdata,mem_wbyte,halt,ebreak,pc);

	//FSM
	parameter Initial = 4'b0000,
			  IF_1 = 4'b0001,
			  IF_2 = 4'b0010,
			  ID_1 = 4'b0011,
			  ID_2 = 4'b0100,
			  EX_1 = 4'b0101,
			  EX_2 = 4'b0110,
			  EX_3 = 4'b0111,
			  EX_4 = 4'b1000,
			  EX_5 = 4'b1001,
			  EX_6 = 4'b1010,
			  Stop_U = 4'b1011,//unsuccessfully
			  Stop_S = 4'b1100;//successfully
	
	reg [3:0] state;

	always @(posedge clk) begin
		if(rst) begin
			state <= Initial; rst_mem <= 1; rst_reg <= 1; 
			IFU_en <= 0; IDU_en <= 0; EXU_en <= 3'b101;
			$display("system reset");
		end
		else begin
			if(~halt && ~ebreak) begin
				case(state)
					Initial: begin IFU_en <= 1; EXU_en <= 3'b101; state <= IF_1; 
								   rst_mem <= 0; rst_reg <= 0; $display("Initial"); end
					IF_1: begin state <= IF_2; $display("IF_1"); end
					// here IFU_en = 0 releases control of reg_ren and reg_addr
					IF_2: begin IFU_en <= 0; IDU_en <= 1; state <= ID_1; $display("IF_2"); end
					ID_1: begin IDU_en <= 0; EXU_en <= 3'b000; state <= ID_2; $display("ID_1"); end
					ID_2: begin EXU_en <= 3'b001; state <= EX_1; $display("ID_2"); end
					EX_1: begin EXU_en <= 3'b010; state <= EX_2; $display("EX_1"); end
					EX_2: begin EXU_en <= 3'b011; state <= EX_3; $display("EX_2"); end
					EX_3: begin EXU_en <= 3'b011; state <= EX_4; $display("EX_3"); end
					EX_4: begin EXU_en <= 3'b100; state <= EX_5; $display("EX_4"); end
					EX_5: begin EXU_en <= 3'b100; state <= EX_6; $display("EX_5"); end
					EX_6: begin EXU_en <= 3'b101; state <= Initial; $display("EX_6"); end
					default: begin state <= Stop_U; $display("Hit bad trap"); end
				endcase
			end
			
			else if(ebreak)
				begin state <= Stop_S; $display("hit good trap"); end
			else
				begin state <= Stop_U; $display("hit bad trap"); end

		end	
	end

endmodule
