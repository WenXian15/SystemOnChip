
Storage
1. Non-volatile storage commanly used as boot source.

Flash Memory Controller

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
4. http://elm-chan.org/docs/mmc/mmc.html


NVMe (nonvolatile memory express)
*********************************
Description:
1. A protocol that allows for faster data transfer in solid-state drives (SSDs) and flash storage.
2. Uses the PCIe bus to connect SSDs to CPUs or servers.
