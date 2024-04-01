
//33 registers in total, each of which contains 32 bits
module Register #(ADDR_WIDTH = 6, DATA_WIDTH = 32)(
	input clk,
	input [DATA_WIDTH-1:0] wdata,
	output reg[DATA_WIDTH-1:0] rdata,
	output [DATA_WIDTH-1:0] pc,
	input [ADDR_WIDTH-1:0] addr,
	input wen,
	input ren
);
	/* verilator lint_off UNUSEDSIGNAL */
	reg [DATA_WIDTH-1:0] Reg [2**ADDR_WIDTH-1:0];

	assign pc = Reg[32];
	//assign wdata = ren ? Reg[waddr] : 32'bz;

	always @(posedge clk) begin
		if(wen)
			Reg[addr] <= wdata;
		else if(ren)
			rdata <= Reg[addr];
	end

endmodule
