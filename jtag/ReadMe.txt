Reading:
1. https://medium.com/@aliaksandr.kavalchuk/diving-into-jtag-protocol-part-1-overview-fbdc428d3a16
2. https://piolabs.com/blog/engineering/diving-into-arm-debug-access-port.html

Background:
JTAG was initially developed for testing integrated circuits and printed circuit boards.  Nowadays it is commonly used as stnadard protocol for microcontroller debugging.

Interface
- TMS, TDI, TDO, TCK

Instruction Registers
- Each tap consists of register decoded that is device dependent.  So what is written to the instruction register
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


# Understand how to write config file for openocd

1. How irscan Selects the DR:
Instruction Codes: Each JTAG device has a defined set of instruction codes. These codes are specific binary patterns that, when loaded into the IR, instruct the JTAG device to perform a particular action or select a specific Data Register.
Instruction Decoding: When you use irscan to load an instruction code (like 0x2 or 0xF in your example), the JTAG device's internal logic decodes this instruction.

DR Mapping: Based on the decoded instruction, the JTAG device internally connects the JTAG data port (TDI/TDO) to a specific Data Register within the device. This Data Register could be:
- Bypass Register (Standard Instruction 0xF): A 1-bit register that allows JTAG data to pass through the device with minimal delay, effectively bypassing its internal logic for data scans. This is selected by the BYPASS instruction (often code 0xF).
- IDCODE Register (Standard Instruction 0x1): A register that contains the device's identification code. Selected by the IDCODE instruction (often code 0x1).
- Boundary Scan Register (Mandatory for Boundary Scan Devices): A register connected to the device's pins, allowing you to observe and control pin states. Selected by the EXTEST instruction (often code 0x0).
- Device-Specific Data Registers: Many JTAG devices also implement custom Data Registers for specific purposes, such as:
  - Control Registers: To configure internal device settings.
  - Status Registers: To read device status information.
  - Memory Access Registers: To access internal memory or peripherals.
  - Debug Registers: For debugging features. These device-specific DRs are selected by device-specific instruction codes, which are defined by the chip manufacturer and documented in the device's JTAG documentation or boundary-scan description language (BSDL) files.
