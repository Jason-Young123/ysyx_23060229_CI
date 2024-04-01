//`timescale 10ns/1ns

module Mux #(WIDTH = 1)(
	input en,
	input [WIDTH-1:0] in1,
	input [WIDTH-1:0] in2,
	output [WIDTH-1:0] out
);
	
	assign out = en ? in1 : in2;

endmodule
