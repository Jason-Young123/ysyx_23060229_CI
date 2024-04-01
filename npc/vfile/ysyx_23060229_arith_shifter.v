
module ysyx_23060229_arith_shifter(
	input [31:0] src1,
	input [4:0] src2,
	output reg [31:0] out
);
	//wire [4:0] shifter;
	//assign shifter = src2[4:0];

	//assign out = ({32{src1[31]}} << (32 - src2[4:0])) | (src1 >> src2[4:0]);

	always @(*) begin
		//if(src2 > 31)
		//	out = src1[31] ? 32'hffffffff : 32'h00000000;
		//else
			out = ({32{src1[31]}} << (32 - src2)) | (src1 >> src2);
	end

endmodule
