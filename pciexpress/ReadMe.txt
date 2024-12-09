Docs to refer
1. PCIe Base Specification - https://picture.iczhiku.com/resource/eetop/SYkDTqhOLhpUTnMx.pdf
2. https://www.mindshare.com/files/resources/mindshare_intro_to_pipe_spec.pdf
3. Mindshare
4. SNIA PCI Express IO Virtualization Specifications - https://www.snia.org/sites/default/education/tutorials/2012/fall/networking/RonEmerick_PCI%20Express_%20IO_Virtualization_Overview-r2.pdf
5. Shane Colton - https://scolton.blogspot.com/2024/01/pcie-deep-dive-part-4-ltssm.html
6. Simon Southwell
7. PIG-SIG - https://pcisig.com
8. https://sci-hub.se/https://ieeexplore.ieee.org/document/7478337

PCIe Debug Techniques
1. https://xilinx.github.io/pcie-debug-kmap/pciedebug/build/html/docs/PCIe_Debug_General_Techniques/index.html

==========
Background
==========

Part 1 : Big Picture

- Serial Transport
PCIe Bandwidth Calculation, Differential Signals, No Common Clock, Packet-based Protocol

- Links and Lanes
Scalable Performance, Flexible Topology Options

- Some Definitions
Topology Characteristics, Root Complex, Switches and Bridges, Naive PCIe Endpoitns and Legacy PCIe Endpoints, Software Compatibility Characteristics

- Device Layer
Device core and interface to Transaction Layer, Transaction Layer, Data Link Layer, Physical Layer


Bus, Device and Function (BDF)
- Up to 256 Bus Numbers can be assigned by configuration software.
- Up to 32 device attachments on a single PCI bus
- Each device is designed with a function and function has its own configuration address space.

Configuration Register Space (256 bytes per function)
- 64-Bytes PCI Configuration Header Space + 192-Bytes Capability Structures
- Extended Configuration Space are introduced due to the limitation in the original 256-bytes configuration region.  Therefore the configuration is extended from 256 bytes per function to 4KB.  The 960-dword Extended Configuration area is accessible using the Enhanced configuration mechanism and is "not visible to legacy PCI software".
- List of capabilities can be found at https://pcisig.com/sites/default/files/files/PCI_Code-ID_r_1_11__v24_Jan_2019.pdf

---------------------------------------------------- Offset 000h
PCI Config Hdr (Contains Device ID, Vendor ID, Base Address)
---------------------------------------------------- Offset 040h
PCI Device-specific & New Capability register sets
Device capabilities are listed after 040h
---------------------------------------------------- Offset 100h
PCIe Extended Configuration Register Space
----------------------------------------------------- Offse FFFh

Address Space & Transaction Routing
- Configuration, Memory and IO Space
- Prefetchable vs Non-prefetchable Memory Space.
- BAR0 (10h), BAR1 (14h), BAR2 (18h), BAR3 (1Ch), BAR4 (20h), BAR5 (24h)
- Upper BAR address is programmed by OS and BIOS of host PC for address space allocation.  The designer decides the memory space needed by the device by setting the lower bits of the address.

- Base and Limit Registers (Switch)
- IO Range


Part 2 : Transaction Layer

Part 3 : Data Link Layer


1. LTSSM 
- Based on Section 4.2.4 Link Initialization and Training, LTSSM is performed by Physical Layer Logic Block aka PCS
- MAC serve as the middle man between the Data Link Layer and PHY Layer.  Not sure if MAC should be considered as part of PHY but definitely not Data link Layer.

Discovered and determined
  -> Link width, Link data rate, Lane reversal, Lane  polarity
Training does
  -> Link data rate negotiation
  -> Bit lock per lane
  -> Lane polarity
  -> Symbol lock or Block alignment per Lane
  -> Lane ordering within a link
  -> Link width negotiation
  -> Lane-to-Lane de-skew within a multi-Lane Link

2. Transaction Layer
Four Address Spaces defined : Memory, I/O, Configuration, Message

3. Data Link Layer
4. Physical Layer

PCI Express IO Virtualization Specifications
-> Allowing multiple operating systems running simultaneously within a single computer system to natively share PCI Express Devices.
