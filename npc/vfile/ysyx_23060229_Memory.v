`include "macro.v"


module ysyx_23060229_Memory #(ADDR_WIDTH = 32, DATA_WIDTH = 8)(
	input clk,
	input rst,
	input ren,
	input wen,
	input [7:0] wmask,
	input [4*DATA_WIDTH-1:0] wdata,
	input [ADDR_WIDTH-1:0] waddr,
    input [ADDR_WIDTH-1:0] pc,raddr,
    output [4*DATA_WIDTH-1:0] inst,
    output reg[4*DATA_WIDTH-1:0] rdata

);

	assign inst = pmem_read_(pc, 1'b1);
	assign rdata = pmem_read_(raddr, ren);

	
	///* verilator lint_off BLKSEQ */
	/*always @(raddr) begin
		if(ren) begin
			rdata = pmem_read_(raddr);
		end
		else
			rdata = 0;
	end*/
	///* verilator lint_on BLKSEQ */


	always @(posedge clk) begin
		if(rst) begin
			$display("Memory resetting ...");
		end
		else begin
			if(wen)
				pmem_write_(waddr, wdata, wmask);
		end
	end


endmodule


