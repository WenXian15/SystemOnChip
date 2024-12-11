Arm Modern SoC

Processor, IP and Memory Blocks
SoC Interconnect

Mailbox
Watchdog timer



I2C, I3C, SPI, QSPI
*******************
Description:
1. Both I²C and SPI are typically used to support multiple sensors.  SPI is usually used for slave devices where speed matters e.g ADC peripherals, FLASH memories.  I2C is usually used for slave devices which are fine with I2C speed constraints or which is kind of slow like sensors which can take longer time to get the measure e.g. popular temperature and humidity sensors.  
Data Rate:
1. I3C : 10.6 Mbps at 12 MHz
2. I2C : 3 Mbps max at 3.4 MHz
3. SPI : 10 Mbps at 10 MHz
Eletrical Interface:
1. I3C/I2C : open-drain line (SDA) and push-pull clock line (SCL)
2. SPI : push-pull
Timing Requirement:
1. https://www.analog.com/en/resources/technical-articles/i2c-timing-definition-and-specification-guide-part-2.html
Reference:
1. https://stackoverflow.com/questions/43422092/when-i-should-use-i2c-and-when-i-should-use-spi
2. https://2384176.fs1.hubspotusercontent-na1.net/hubfs/2384176/MIPI_Alliance_I3C_Whitepaper.pdf
3. https://www.ti.com/content/dam/videos/external-videos/en-us/9/3816841626001/6305803223112.mp4/subassets/i3c_technology_training_2.pdf
4. https://introspect.ca/blog/how-to-test-mctp-over-i3c/


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
Data Rate:

Electrical Interface:
1. Open-drain
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


LTPI (LVDS Tunelling Protocol Interface)
****************************************
Description:
1. Replacement of two Serial GPIO (SGPIO) interfaces.  Provide higher bandwidth and scalability than the SGPIO interface.
2. An interface protocol designed fortunneling various low-speed signals between the Host Processor Module (HPM) and Secure Control Module(SCM).
3. The GPIO channel information is packed into frames as defined in TDM fashion to send across two ends over a reduced-wire solution.
Data Rate:
1. SDR mode: 2.5MHz - 20MHz
2. DDR mode: 5MHz - 40MHz
Electrical Interface:
1. LVDS
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


CSI-2/DSI
*********




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
