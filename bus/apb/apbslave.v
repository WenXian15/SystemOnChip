`default_nettype	none
// }}}
module	apbslave #(
		// {{{
		parameter	C_APB_ADDR_WIDTH = 12,
		parameter	C_APB_DATA_WIDTH = 32,
		localparam	AW = C_APB_ADDR_WIDTH,
		localparam	DW = C_APB_DATA_WIDTH,
		localparam	APBLSB = $clog2(C_APB_DATA_WIDTH)-3
		// }}}
	) (
		// {{{
		input	wire			PCLK, PRESETn,
		input	wire			PSEL,
		input	wire			PENABLE,
		output	reg			PREADY,
		input	wire	[AW-1:0]	PADDR,
		input	wire			PWRITE,
		input	wire	[DW-1:0]	PWDATA,
		input	wire	[DW/8-1:0]	PWSTRB,
		input	wire	[2:0]		PPROT,
		output	reg	[DW-1:0]	PRDATA,
		output	wire			PSLVERR
		// }}}
	);

	// Register declarations
	// {{{
	// Just our demonstration "memory" here
	reg	[DW-1:0]	mem	[0:(1<<(AW-APBLSB))-1];
	integer			ik;
	// }}}

	// PREADY
	// {{{
	initial	PREADY = 1'b0;
	always @(posedge PCLK)
	if (!PRESETn)
		PREADY <= 1'b0;
	else if (PSEL && !PENABLE)
		PREADY <= 1'b1;
	else
		PREADY <= 1'b0;
	// }}}

	// mem writes
	// {{{
	always @(posedge PCLK)
	if (PRESETn && PSEL && !PENABLE && PWRITE)
	begin
		for(ik=0; ik<DW/8; ik=ik+1)
		if (PWSTRB[ik])
			mem[PADDR[AW-1:APBLSB]][8*ik +: 8] <= PWDATA[8*ik +: 8];
	end
	// }}}

	// PRDATA, memory reads
	// {{{
	always @(posedge PCLK)
	if (PSEL && !PENABLE && !PWRITE)
		PRDATA <= mem[PADDR[AW-1:APBLSB]];
	// }}}

	// PSLVERR -- unused in this design, and so kept at zero
	// {{{
	assign	PSLVERR = 1'b0;
	// }}}

	// Make Verilator happy
	// {{{
	// Verilator lint_off UNUSED
	wire	unused;
	assign	unused = &{ 1'b0, PADDR[APBLSB-1:0], PPROT };
	// Verilator lint_on  UNUSED
	// }}}
