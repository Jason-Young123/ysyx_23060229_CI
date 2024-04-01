
module ysyx_23060229_Memory #(ADDR_WIDTH = 32, DATA_WIDTH = 8)(
	input clk,
	input rst,
	input [1:0] wen_mem,
	input [1:0] ren_mem,
	input [4*DATA_WIDTH-1:0] din,
	input [ADDR_WIDTH-1:0] addr_in,
	input [ADDR_WIDTH-1:0] pc,addr_out,
	output [4*DATA_WIDTH-1:0] inst,
	output [4*DATA_WIDTH-1:0] dout
);
	
	reg [DATA_WIDTH-1:0] Mem [2**16-1:0];
	
	wire [4*DATA_WIDTH-1:0] tmp_out1,tmp_out2,tmp_out4;

	assign inst = {Mem[pc+3],Mem[pc+2],Mem[pc+1],Mem[pc]};//dout1

	assign tmp_out1 = {{24{Mem[addr_out][DATA_WIDTH-1]}},Mem[addr_out]};
	assign tmp_out2 = {{16{Mem[addr_out+1][DATA_WIDTH-1]}},Mem[addr_out+1],Mem[addr_out]};
	assign tmp_out4 = {Mem[addr_out+3],Mem[addr_out+2],Mem[addr_out+1],Mem[addr_out]};
	//dout2
	assign dout = ren_mem==2'b01 ? tmp_out1 : (ren_mem==2'b10 ? tmp_out2 : (ren_mem==2'b11 ? tmp_out4 : 0));
		


	always @(posedge clk) begin
		if(rst) begin
			$readmemh("resource/mem.hex",Mem);
			$display("Memory Reset ...");
		end	
		else
			case(wen_mem)
				2'b01: Mem[addr_in] <= din[DATA_WIDTH-1:0];
				2'b10: {Mem[addr_in+1],Mem[addr_in]} <= {din[2*DATA_WIDTH-1:DATA_WIDTH],din[DATA_WIDTH-1:0]};
				2'b11: {Mem[addr_in+3],Mem[addr_in+2],Mem[addr_in+1],Mem[addr_in]} <= 
						{din[4*DATA_WIDTH-1:3*DATA_WIDTH],din[3*DATA_WIDTH-1:2*DATA_WIDTH],
						din[2*DATA_WIDTH-1:DATA_WIDTH],din[DATA_WIDTH-1:0]};
				default: ;
			endcase
	end

endmodule

