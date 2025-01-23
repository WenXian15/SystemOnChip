Reading:
1. https://medium.com/@aliaksandr.kavalchuk/diving-into-jtag-protocol-part-1-overview-fbdc428d3a16
2. https://piolabs.com/blog/engineering/diving-into-arm-debug-access-port.html

Background:
JTAG was initially developed for testing integrated circuits and printed circuit boards.  Nowadays it is commonly used as stnadard protocol for microcontroller debugging.

Interface
- TMS, TDI, TDO, TCK

Instruction Registers
- Instruction registers contains list of instruction value that allow switching between different Data Registers.
- If the Instruction registers hold the instruction for IDCODE, the Data registers will switch to IDCODE path.

Data Registers
- Different TAP has different sets of data registers.  For example Boundary Scan Tap and Debug Tap
a. Boundary Scan Tap
  1.  Boundary Scan Register (BSR)
  2.  Bypass Register (BR)
  3.  Device ID Register
  4.  User Data Register(s)

b. Debug Tap (STM32F407VG) - refer to Reading2 for more details
  1. DPACC (Debug Port Access Data Registers) - Set 0b1010 to IR register
  2. APACC (Access Port Access Data Registers)
  3. IDCODE 
  4. BYPASS
  5. ABORT


  
