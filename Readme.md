# Overview
This project demonstrates the implementation of a pre-trained color detection neural network on an FPGA using the ZedBoard (Zynq SoC). The neural network, originally written in Octave, was converted to C++ for hardware synthesis using Vivado HLS. The project covers the entire process from neural network conversion, synthesis, and optimization to hardware implementation on the Zynq SoC, including PS-PL communication.

# Project Description
## Steps Involved:
1) Neural Network Conversion: The color detection neural network was initially trained in Octave and converted to C++ for compatibility with Vivado HLS.
2) Vivado HLS Synthesis: The first synthesis yielded high BRAM utilization and latency issues. To overcome this, Vivado directives such as loop unrolling were applied to reduce latency, and AXI Stream protocols were used to handle the large BRAM utilization by processing the image in smaller chunks.
3) Optimization: The system was initially synthesized with a 10ns clock, resulting in negative slack. To address this, the clock period was changed to 15ns, which optimized the timing and reduced latency to process the image within 0.1 seconds.
4) Vivado Integration: The generated IP from Vivado HLS was exported to Vivado, where block connections were made between the Zynq Processing System (PS) and the custom IP (PL). To manage IPs running at different clock speeds (10ns and 15ns), AXI Data FIFO IP was used for smooth data transfer.
5) Hardware Implementation: After generating the HDL wrapper, the design was synthesized, implemented, and a bitstream was generated. The bitstream and code were then exported to Vivado SDK, where the remaining C++ code was written to handle data transfer between PS and PL.
6) Running the Design on ZedBoard: The bitstream was uploaded to the ZedBoard, followed by the First Stage Boot Loader (FSBL) code to initialize the Zynq registers and memory. Finally, the C++ code was run on the PS to process the image using the neural network implemented in the PL.

## Key Technologies
1) Vivado HLS: High-Level Synthesis to convert C++ code into HDL (Verilog/VHDL).
2) Vivado Design Suite: For generating the hardware block design and bitstream.
3) AXI Stream Protocol: Used to transfer data between the Processing System (PS) and Programmable Logic (PL) efficiently.
4) ZedBoard (Zynq SoC): The hardware platform used to implement the design.

## Project Structure
Codes folder contains the source code (for Vivado HLS synthesis) and the SDK_Code (to be run on Vivado SDK). The Block Design Floader contains the tcl script for the block design and lastly, the master branch contains the generated HLS IP (name nn_start).

# Results
The optimized neural network processes an image in less than 0.1 seconds. Efficient use of AXI Stream protocol and Vivado HLS optimizations led to reduced BRAM utilization and improved overall performance.

# Acknowledgments
This project was developed as part of my summer internship under the supervision of three professors.
