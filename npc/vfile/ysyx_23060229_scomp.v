
/* verilator lint_off UNUSEDSIGNAL */
//if src1 < src2, then out = 32'b00...1
module ysyx_23060229_scomp(
	input [31:0] src1,
	input [31:0] src2,
	output [31:0] out
);
	wire overflow,result;
	wire [31:0] sub;

	assign sub = src1 - src2;
	//always @(*) begin
	//	sub = src1 - src2;
	//end

	assign overflow = (src1[31] != src2[31]) && (sub[31] != src1[31]);
	assign result = sub[31] ^ overflow;
	assign out = {31'b0, result};


endmodule
/* verilator lint_on UNUSEDSIGNAL */

