//`timescale 10ns/1ns

//read memory according to pc
module IFU(
	input clk,
	input IFU_en,
	input [31:0] pc,
	input [31:0] rdata,
	output reg mem_ren,
	output reg[31:0] mem_addr,
	output [31:0] inst

);

	assign inst = rdata;
	
	always @(posedge clk) begin
		if(IFU_en) begin
			mem_ren <= 1; mem_addr <= pc;
		end
		
		else begin //both IFU and EXU controls ren and addr
			mem_ren <= 0; mem_addr <= 32'b0;
		end
	end

endmodule
