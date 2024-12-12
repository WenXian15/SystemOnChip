#include <verilatedos.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <signal.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vhelloworld.h"
#define SIMCLASS Vhelloworld

int main(int argc, char **argv) {
	Verilated::commandArgs(argc, argv);
	SIMCLASS tb;
	
	tb.i_setup = setup;


}
