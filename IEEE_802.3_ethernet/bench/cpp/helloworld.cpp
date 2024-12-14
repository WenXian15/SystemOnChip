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

#include "uartsim.h"

int main(int argc, char **argv) {
	Verilated::commandArgs(argc, argv);
	SIMCLASS	tb;
	UARTSIM		*uart;
	int		port = 0;
	unsigned	setup = 868, clocks = 0, baudclocks;

	//tb.i_setup = setup;
	uart = new UARTSIM(port);
	baudclocks = 0xffffffff;

#define VCDTRACE
#ifdef	VCDTRACE
	Verilated::traceEverOn(true);
	VerilatedVcdC* tfp = new VerilatedVcdC;
	tb.trace(tfp, 99);
	tfp->open("helloworld.vcd");
#define TRACE_POSEDGE tfp->dump(10*clocks)
#define TRACE_NEGEDGE tfp->dump(10*clocks+5)
#define TRACE_CLOSE   tfp->close()
#else
#define TRACE_POSEDGE
#define TRACE_NEGEDGE
#define TRACE_CLOSE
#endif

	clocks = 0;
	while(clocks < 16*32*baudclocks) {
		tb.clk_125m = 1;
		tb.eval();
		TRACE_POSEDGE;
		tb.clk_125m = 0;
		tb.eval();
		TRACE_NEGEDGE;

		(*uart)(tb.o_uart_tx);
		clocks++;
	}

	TRACE_CLOSE;
	printf("\n\nSimulation complete\n");

}
