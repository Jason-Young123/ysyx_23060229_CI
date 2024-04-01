

module ysyx_23060229_EXU(
	input rst,
	input [31:0] pc,//to top module
	input [6:0] typ,
	input [31:0] src1,
	input [31:0] src2,
	input [31:0] imm,
	input [31:0] data_from_mem,//to top module
	output reg[31:0] data_to_mem,//to top module
	output reg[31:0] reg_din,
	output reg[31:0] pcout
);

	always@(*) begin
		if(rst) begin
			$display("Reset ..."); data_to_mem = 0; reg_din = 0; pcout = pc;
		end
		else
			case(typ)
				//type 1: read reg + write reg
				`ysyx_23060229_I_ADDI:	begin data_to_mem = 0; reg_din = src1 + imm; pcout = pc + 4; end
				//type 2: read mem + write reg
				`ysyx_23060229_I_LW:	begin data_to_mem = 0; reg_din = data_from_mem; pcout = pc + 4; end
				//type 3: read reg + write mem
				`ysyx_23060229_S_SB:	begin data_to_mem = src2; reg_din = 0; pcout = pc + 4; end
				`ysyx_23060229_S_SH:	begin data_to_mem = src2; reg_din = 0; pcout = pc + 4; end
				`ysyx_23060229_S_SW:	begin data_to_mem = src2; reg_din = 0; pcout = pc + 4; end

				//type 4: others
				`ysyx_23060229_EBREAK:	begin $display("hit good trap !"); data_to_mem = 0; reg_din = 0; pcout = pc; end
				`ysyx_23060229_NONE:	begin $display("hit bad trap !"); data_to_mem = 0; reg_din = 0; pcout = pc; end
				default:				begin $display("hit bad trap"); data_to_mem = 0; reg_din = 0; pcout = pc; end

			endcase
	
	end



endmodule

