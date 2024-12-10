Reading:
1. https://github.com/pulp-platform/axi?tab=readme-ov-file

Terminology 
Incremental/Wrap Burst Support
Narrow Transactions 
Unaligned Transactions
Refer to for some idea with block memory generator https://docs.amd.com/v/u/en-US/blk_mem_gen_ds512

===
AHB
===
IHI0033C_amba_ahb_protocol_spec-1.pdf

Transfer Type
IDLE, BUSY, NONSEQ, SEQ

Transfer Size
Byte, Halfword, Word, DoubleWord, 4-word line, 8-word line

Burst Operation
SINGLE, INCR, WRAP4, INCR4, WRAP8, INCR8, WRAP16, INCR16




Important concepts 

Address Alignment
- What is address alignment?  The address can be divided by n where is the number of byte of data.
- For example 32-bit or 4 byte can start from address 0x00, 0x04, 0x08, 0xc0 where the last 2 bits of the address are always zero.
- The AHB protocol does not support unaligned transfer.

Address Boundaries (burst operation)
- The AHB protocol is constrainted to have burst not crossing a 1KB address boundary.
- Start by asking yourself what is 1KB or 4KB boundary.  What is the address range for 1kB and 4kB.
1KB = 0x000 (0000_0000_0000) - 0x400 (0100_0000_0000)
https://developer.arm.com/documentation/ka001348/latest/
- The minimum address space for a single slave is 1KB
https://mapl.cs.nycu.edu.tw/course/ESL/files/Lecture10.pdf


===
AXI
===
Minimal Implementation
AWID, AWLEN, AWSIZE, AWBURST


Import Concepts

Address Boundaries (burst operation)
- From AHB, we learn that there is a 10KB address boundaries.  For AXI, there is a 4K boundary.  Meaning from 0x000-0xFFF, 0x1000-0x1FFF, 0x2000-0x2FFF.  Each are considered a 4KB boundary.
- Boundaries are used because of some 4k page thing.  PCIe is also not allowed to cross the 4K boundary.
https://www.reddit.com/r/FPGA/comments/1cxukto/do_i_understand_4k_boundary_correctly/
https://www.linkedin.com/pulse/constraint-axi-4kb-boundary-mohamed-irsath-i-auunc

Example from Claude
*******************
// AXI4 signals
logic [7:0]  AWLEN;    // Burst length (1-256)
logic [2:0]  AWSIZE;   // Size of each transfer (2^SIZE bytes)
logic [1:0]  AWBURST;  // Burst type (FIXED, INCR, WRAP)
logic [31:0] AWADDR;   // Starting address

// AWSIZE Value
AWSIZE  Transfer Size
'b000   1 byte
'b001   2 bytes
'b010   4 bytes
'b011   8 bytes
'b100   16 bytes
'b101   32 bytes
'b110   64 bytes
'b111   128 bytes

// AWBURST Type
FIXED (00): All transfers use same address
INCR (01): Address increments with each transfer
WRAP (10): Like INCR but wraps at boundary

// 4KB Boundary Calculations
// Maximum allowed burst length calculation
function automatic [7:0] max_burst_length;
    input [31:0] address;
    input [2:0]  size;
    
    logic [11:0] offset = address[11:0];
    logic [12:0] bytes_to_boundary = 13'h1000 - offset;
    logic [7:0]  max_beats;
    
    max_beats = bytes_to_boundary >> size;  // Divide by transfer size
    return (max_beats == 0) ? 8'h1 : max_beats;
endfunction

// Examples:
Example 1:
AWADDR = 0xFF0
AWSIZE = 2 (4 bytes)
4KB Boundary = 0x1000
Max beats = (0x1000 - 0xFF0)/4 = 4 beats

Example 2:
AWADDR = 0x100
AWSIZE = 3 (8 bytes)
4KB Boundary = 0x1000
Max beats = (0x1000 - 0x100)/8 = 238 beats
Limited by AXI4 max of 256

Key Points:
1. AWSIZE affects maximum allowed length
2. Never cross 4KB boundary with INCR



