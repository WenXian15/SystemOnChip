

module axim2wbsp #(
		// {{{
		parameter C_AXI_ID_WIDTH = 2, // The AXI id width used for R&W
                                             // This is an int between 1-16
		parameter  C_AXI_DATA_WIDTH  = 32,// Width of the AXI R&W data
		parameter  C_AXI_ADDR_WIDTH	= 28,	// AXI Address width
		localparam AXI_LSBS		= $clog2(C_AXI_DATA_WIDTH)-3,
		localparam DW			= C_AXI_DATA_WIDTH,
		localparam AW			= C_AXI_ADDR_WIDTH - AXI_LSBS,
		parameter  LGFIFO		= 5,
		parameter [0:0]	OPT_SWAP_ENDIANNESS = 1'b0,
		parameter [0:0]	OPT_READONLY	= 1'b0,
		parameter [0:0]	OPT_WRITEONLY	= 1'b0
		// }}}
	) (
		// {{{
		//
		input	wire			S_AXI_ACLK,	// System clock
		input	wire			S_AXI_ARESETN,

		// AXI write address channel signals
		// {{{
		input	wire			S_AXI_AWVALID,
		output	wire			S_AXI_AWREADY,
		input	wire	[C_AXI_ID_WIDTH-1:0]	S_AXI_AWID,
		input	wire	[C_AXI_ADDR_WIDTH-1:0]	S_AXI_AWADDR,
		input	wire	[7:0]		S_AXI_AWLEN,
		input	wire	[2:0]		S_AXI_AWSIZE,
		input	wire	[1:0]		S_AXI_AWBURST,
		input	wire	[0:0]		S_AXI_AWLOCK,
		input	wire	[3:0]		S_AXI_AWCACHE,
		input	wire	[2:0]		S_AXI_AWPROT,
		input	wire	[3:0]		S_AXI_AWQOS,
		// }}}
		// AXI write data channel signals
		// {{{
		input	wire			S_AXI_WVALID,
		output	wire			S_AXI_WREADY, 
		input	wire [C_AXI_DATA_WIDTH-1:0]   S_AXI_WDATA,
		input	wire [C_AXI_DATA_WIDTH/8-1:0] S_AXI_WSTRB,
		input	wire			S_AXI_WLAST,
		// }}}
		// AXI write response channel signals
		// {{{
		output	wire 			S_AXI_BVALID, 
		input	wire			S_AXI_BREADY,
		output	wire [C_AXI_ID_WIDTH-1:0] S_AXI_BID,
		output	wire [1:0]		S_AXI_BRESP,
		// }}}
		// AXI read address channel signals
		// {{{
		input	wire			S_AXI_ARVALID,
		output	wire			S_AXI_ARREADY,
		input	wire [C_AXI_ID_WIDTH-1:0]   S_AXI_ARID,
		input	wire [C_AXI_ADDR_WIDTH-1:0] S_AXI_ARADDR,
		input	wire	[7:0]		S_AXI_ARLEN,
		input	wire	[2:0]		S_AXI_ARSIZE,
		input	wire	[1:0]		S_AXI_ARBURST,
		input	wire	[0:0]		S_AXI_ARLOCK,
		input	wire	[3:0]		S_AXI_ARCACHE,
		input	wire	[2:0]		S_AXI_ARPROT,
		input	wire	[3:0]		S_AXI_ARQOS,
		// }}}
		// AXI read data channel signals
		// {{{
		output	wire			S_AXI_RVALID,  // Rd rslt valid
		input	wire			S_AXI_RREADY,  // Rd rslt ready
		output	wire [C_AXI_ID_WIDTH-1:0]   S_AXI_RID, // Response ID
		output	wire [C_AXI_DATA_WIDTH-1:0] S_AXI_RDATA,// Read data
		output	wire			S_AXI_RLAST,   // Read last
		output	wire [1:0]		S_AXI_RRESP,   // Read response
		// }}}
	);

	localparam	AW = C_S_AXI_ADDR_WIDTH;
	localparam	DW = C_S_AXI_DATA_WIDTH;
	localparam	IW = C_S_AXI_ID_WIDTH;
	localparam	LSB = $clog2(C_S_AXI_DATA_WIDTH)-3;


// skid buffer 


// Write Channel




// Read Channel
