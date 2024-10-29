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
- What is address alignment?  
- The AXI and AHB protocols handle transaction address differently, so the AXI to AHB bridge must perform address alignment.  The AHB protocol does not support unaligned transfer.

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
