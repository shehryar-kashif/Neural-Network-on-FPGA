// Copyright 1986-2019 Xilinx, Inc. All Rights Reserved.
// --------------------------------------------------------------------------------
// Tool Version: Vivado v.2019.1 (win64) Build 2552052 Fri May 24 14:49:42 MDT 2019
// Date        : Sun Sep  1 12:47:14 2024
// Host        : Shehryar-FBV6TNB running 64-bit major release  (build 9200)
// Command     : write_verilog -force -mode synth_stub
//               C:/Xilinx/Projects/NN_ColourDetection_v2_Viv/NN_ColourDetection_v2_Viv.srcs/sources_1/bd/design_1/ip/design_1_nn_start_0_0/design_1_nn_start_0_0_stub.v
// Design      : design_1_nn_start_0_0
// Purpose     : Stub declaration of top-level module interface
// Device      : xc7z020clg400-2
// --------------------------------------------------------------------------------

// This empty module with port declaration file causes synthesis tools to infer a black box for IP.
// The synthesis directives are for Synopsys Synplify support to prevent IO buffer insertion.
// Please paste the declaration into a Verilog source file or add the file as an additional source.
(* X_CORE_INFO = "nn_start,Vivado 2019.1" *)
module design_1_nn_start_0_0(ap_clk, ap_rst_n, ap_start, ap_done, ap_idle, 
  ap_ready, input_r_TVALID, input_r_TREADY, input_r_TDATA, output_r_TVALID, output_r_TREADY, 
  output_r_TDATA)
/* synthesis syn_black_box black_box_pad_pin="ap_clk,ap_rst_n,ap_start,ap_done,ap_idle,ap_ready,input_r_TVALID,input_r_TREADY,input_r_TDATA[31:0],output_r_TVALID,output_r_TREADY,output_r_TDATA[31:0]" */;
  input ap_clk;
  input ap_rst_n;
  input ap_start;
  output ap_done;
  output ap_idle;
  output ap_ready;
  input input_r_TVALID;
  output input_r_TREADY;
  input [31:0]input_r_TDATA;
  output output_r_TVALID;
  input output_r_TREADY;
  output [31:0]output_r_TDATA;
endmodule
