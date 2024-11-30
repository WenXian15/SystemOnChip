#include <stdio.h>
#include <string.h>
#include <time.h>


int main(int argc, char **argv) {
	Verilated::commandArgs(argc, argv);
	SIMCLASS tb;
	
	tb.i_setup = setup;


}
