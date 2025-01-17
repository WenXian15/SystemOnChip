Reading:
1. https://github.com/alexforencich/verilog-ethernet/tree/master
2. https://people.ece.cornell.edu/land/courses/ece5760/FinalProjects/f2011/mis47_ayg6/mis47_ayg6/
3. https://www.javatpoint.com/computer-network-tutorial
4. http://www.tcpipguide.com/free/t_TCPIPProtocols.htm#google_vignette

Learning from other's projects:
1. https://fpga.eetrend.com/blog/2024/100585665.html
2. https://www.cnblogs.com/yikoulinux/p/14232786.html

_______         __________                  ___________
 CPU  | PCI-E   |        |  MII/SGMII/RGMII |         |
 or   |<=======>| MAC    |<================>| PHY     |<====>physical interface 
 board| or else |        |                  |         |
_______         __________                  ___________

EMAC

PHY Interface
- Media-independent interface (MII) (100Mbps) (4-bit data paths, Clock speed: 25 MHz)
- Reduced media-independent interface (RMII) (2-bit data paths, Clock speed: 50 MHz)
- Gigabit media-independent interface (GMII) (8-bit data paths, Clock speed: 125 MHz)
- Reduced gigabit media-independent interface (RGMII) (4-bit data paths, Clock speed: 125MHz, DDR to achieve 1Gbps)
- Serial media-independent interface (SMII)[1]
- Serial gigabit media-independent interface (serial GMII, SGMII) (1Gbps, serial)
- High serial gigabit media-independent interface (HSGMII)
- Quad serial gigabit media-independent interface (QSGMII)
- Penta serial gigabit media-independent interface (PSGMII)
- 10-gigabit media-independent interface (XGMII - X stands for 10 in Roman) 

Interpacket gap
https://en.wikipedia.org/wiki/Interpacket_gap


Electrical Interface
- 10/100BASE-T

Constraints
set_input_delay 
set_output_delay 
