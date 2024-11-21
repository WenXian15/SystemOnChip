Arm Modern SoC

Processor, IP and Memory Blocks
SoC Interconnect

Mailbox
Watchdog timer

Peripheral Bus

I2C, I3C, SPI
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

SMBUS


LTPI
PECI
Super I/O (SIO)

eSPI
Description: 
1. All in one bus designed to replace the LPC bus (Embedded Controller (EC), Baseboard Management Controller (BMC) and Super I/O (SIO)) as well as the SPI bus, SMbus and sideband signals.
Reference : 
1. https://www.microchip.com/en-us/solutions/data-centers-and-computing/computing-solutions/technologies/espi



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
