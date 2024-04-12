`include "macro.v"

//4096 Control & Status registers
module ysyx_23060229_CSRegister #(ADDR_WIDTH = 12, DATA_WIDTH = 32)(
	input clk,
	input rst,
	input [1:0] wen,
	input [31:0] pc,
	input [DATA_WIDTH-1:0] din,
	input [ADDR_WIDTH-1:0] addr_in, addr_out,
	output [DATA_WIDTH-1:0] dout
);
	
	reg[DATA_WIDTH-1:0] CSReg [2**ADDR_WIDTH-1:0];
	
	assign dout = CSReg[addr_out];

	always @(posedge clk)begin
		if(rst) begin
			$display("CSRegister resetting ...");
			$readmemh("resource/csreg.hex",CSReg);
		end
		else begin
			if(wen == 2'b01)
				CSReg[addr_in] <= din;
			else if(wen == 2'b10) begin //代表是ecall
				CSReg[`MCAUSE] <= 32'h0000000b;
				CSReg[`MEPC] <= pc;
			end
			else
				;
		end
	end

endmodule
