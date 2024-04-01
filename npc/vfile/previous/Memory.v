

//Memory
//read 4 byte, write 1/2/4 byte
module Memory #(ADDR_WIDTH = 32, DATA_WIDTH = 8)(
	input clk,
	input rst,
	input [4*DATA_WIDTH-1:0] wdata,
	output reg[4*DATA_WIDTH-1:0] rdata,
	input [ADDR_WIDTH-1:0] addr,
	input wen,
	input ren,
	input [1:0] wbyte
);



	reg [DATA_WIDTH-1:0] Mem [0:2**16-1];


	always @(posedge clk) begin
		//$display("%x", Mem[0]);
		//$display("%x", rdata);
		if(rst) begin// load the source code into memory
			$readmemh("resource/mem.hex",Mem);

		end	
		else if(wen) begin
			case(wbyte)
				2'b01:begin// write 2 bytes
					Mem[addr] <= wdata[DATA_WIDTH-1:0];
					Mem[addr+1] <= wdata[2*DATA_WIDTH-1:DATA_WIDTH];
				end
				2'b11:begin// write 4 bytes
					Mem[addr] <= wdata[DATA_WIDTH-1:0];
					Mem[addr+1] <= wdata[2*DATA_WIDTH-1:DATA_WIDTH];
					Mem[addr+2] <= wdata[3*DATA_WIDTH-1:2*DATA_WIDTH];
					Mem[addr+3] <= wdata[4*DATA_WIDTH-1:3*DATA_WIDTH];
				end
				default:// write 1 byte
					Mem[addr] <= wdata[DATA_WIDTH-1:0];
			endcase
		end

		else if(ren) begin
			//$display("%x", Mem[0]);
			rdata[DATA_WIDTH-1:0] <= Mem[addr];
			rdata[2*DATA_WIDTH-1:DATA_WIDTH] <= Mem[addr+1];
			rdata[3*DATA_WIDTH-1:2*DATA_WIDTH] <= Mem[addr+2];
			rdata[4*DATA_WIDTH-1:3*DATA_WIDTH] <= Mem[addr+3];
		end

	end

endmodule
