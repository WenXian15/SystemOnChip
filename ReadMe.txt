Arm Modern SoC

Processor, IP and Memory Blocks
SoC Interconnect

Mailbox
Watchdog timer


I2C, I3C, SPI
*************
Description:
1. Both I²C and SPI are typically used to support multiple sensors, but they both have drawbacks for sensor interconnections.
Effective Data Rate:
1. I3C : 10.6 Mbps at 12 MHz
2. I2C : 3 Mbps max at 3.4 MHz
3. SPI : 10 Mbps at 10 MHz
Reference:
1. https://2384176.fs1.hubspotusercontent-na1.net/hubfs/2384176/MIPI_Alliance_I3C_Whitepaper.pdf
2. https://www.ti.com/content/dam/videos/external-videos/en-us/9/3816841626001/6305803223112.mp4/subassets/i3c_technology_training_2.pdf
3. https://introspect.ca/blog/how-to-test-mctp-over-i3c/


eSPI
****
Description: 
1. LPC (Low Pin Count) bus has been used to connect various devices, such as an Embedded Controller (EC), Baseboard Management Controller (BMC), Super I/O (SIO) controller, system Flash storage that is used to store the BIOS code, and the Trusted Platform Module (TPM) to the system core logic.
2. eSPI is designed as an all-in-one bus to replace the LPC bus (Embedded Controller (EC), Baseboard Management Controller (BMC) and Super I/O (SIO)) as well as the SPI bus, SMbus and sideband signals.
3. Consists of 4 channels
    - Channel 0: Peripheral Channel (memory reads/writes)
                 The Peripheral channel is used to communicate with devices located in the EC, BMC and SIO that were formerly found on the LPC bus. They include UARTS, mailbox registers, port 80 registers, embedded memory interfaces and the keyboard                         controller. The Peripheral channel also includes support for a Bus Mastering channel. The Bus Master capability allows the EC to read/write data directly to/from the main system memory.
    - Channel 1: Virtual Wire Channel (sideband signals)
                 The Virtual Wire Channel is used to transmit the sideband signal information to/from the EC, BMC and SIO. Interrupts from peripheral devices, such as a UART, are also transmitted over the Virtual Wire channel. This channel greatly reduces                   the pin count and cost of the eSPI bus as compared to the LPC bus.
    - Channel 2: OOB Message Channel (SMBus tunneling)
                 The Out-Of-Band (OOB) Message Channel is used to tunnel SMBus traffic over eSPI. These messages can include system logic and processor temperature values or SMBus Management Component Transport Protocol (MCTP) packets.
    - Channel 3: Flash Access Channel (flash sharing or eSPI device attached flash-eDAF) 
                 The Flash Access Channel allows the system processor to share the system SPI Flash between the BIOS, Management Engine (ME) and the EC, BMC and SIO. This reduces system cost by reducing the number of SPI Flash chips in the system.
Reference : 
1. https://www.microchip.com/en-us/solutions/data-centers-and-computing/computing-solutions/technologies/espi
2. https://support.apple.com/en-my/guide/security/sec5d0fab7c6/web (Apple Intel based Mac fetches UEFI firmware through eSPI from T2 Chip)


SMBUS (System Management Bus)
*****************************
Description:
1. SMBus technology is used in Smart Battery Systems, or SBS, which is often implemented in portable devices such as laptop computers, mobile devices, and cameras for efficient battery management. Smart Battery Systems consist of a host, smart charger, and smart battery and use SMBus for these components to communicate with each other and the rest of the system.
Reference:
1. https://www.nxp.com/docs/en/application-note/AN4471.pdf
2. https://www.prodigytechno.com/smbus-protocol


LTPI
****
Description:
1. Replacement of two Serial GPIO (SGPIO) interfaces.  Provide higher bandwidth and scalability than the SGPIO interface.
2. The GPIO channel information is packed into frames as defined in TDM fashion to send across two ends over a reduced-wire solution.
Reference:
1. https://ww1.microchip.com/downloads/aemDocuments/documents/FPGA/ProductDocuments/UserGuides/coreltpi_ug.pdf


PECI (Platform Environment Control Interface)
*********************************************
Description:
1. PECI  is a communication interface between Intel processor and management controllers.  It provides an interface for external devices to read processor temperature, perform processor manageability functions, and manage processor interface tuning and diagnostics.
2. In server platforms, CPUs are the PECI slaves and BMC is the PECI master.
References:


Super I/O (SIO) - Still dont understand
***************
Description:
1. Super I/O combines legacy functions (serial port, parallel ports, PS2) into a single chip to reduce the number of chips required in your design.
2. SIO was connected to the chipset through the Low Pin Count (LPC) bus before eSPI.
References:
1. https://www.microchip.com/en-us/products/embedded-controllers-and-super-io


Storage
1. Non-volatile storage commanly used as boot source.

SD (Secure Digital) & eMMC/MMC (MultiMediaCard) & UFS (Universal Flash Storage)
*******************************************************************************
Description:
1. eMMC is an SD Card soldered to the board.  eMMC and SD are often be a same controller.
2. SD is a derivative standard from MMC (which started as slim 7 contacts memory modules), before they diverged, adding 4bits, 8bits, DDR protocols.  MMC and SD card have different initialisation sequences. 
3. eMMC is slower than UFS
References:
1. https://electronics.stackexchange.com/questions/537596/how-different-are-the-emmc-and-sd-card-protocols
2. https://news.ycombinator.com/item?id=25162213
3. https://docs.amd.com/r/en-US/am011-versal-acap-trm/SD_eMMC-Controller


NVMe (nonvolatile memory express)
*********************************
Description:
1. A protocol that allows for faster data transfer in solid-state drives (SSDs) and flash storage.
2. Uses the PCIe bus to connect SSDs to CPUs or servers.

==========
Components
==========
Debug
Security
Memory
Boot
Reset
Peripheral & GPIO
High-speed I/O

===
DMA
===
DMA addressing mode - linear, circular, step
EDMA (Enhanced DMA)

Design For Test
https://github.com/jxwleong/jtag-boundary-scan
