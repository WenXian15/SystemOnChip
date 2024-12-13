module ethernet_receiver_uart_dump #(
    // Parameters
    parameter CLK_PERIOD = 8,  // 125MHz for GMII
    parameter DATA_WIDTH = 8
 )(
    // Clocks
    input wire clk_125m,	// Ethernet clk
    input wire clk_50m,

    // Reset 
    input wire rst_n,
	
    // Ethernet signals
    output wire [DATA_WIDTH-1:0] rxd,	// Ethernet frame from tb

    // Uart signals
    output wire uart_tx

 );

    //wire [7:0] rx_data;
    //wire rx_data_valid;
    //wire frame_start;
    //wire frame_end;
    //wire [15:0] frame_length;
    //wire frame_valid;
    //wire frame_error;
    
    // Frame generation parameters
    reg [7:0] test_frame[$];  // Queue to store frame data
    reg rx_dv;
    integer frame_idx;

    wire [8+2-1:0] rx_data_fifo;
    wire is_empty_fifo;
    wire is_full_fifo;
    wire[10-1:0] WRCOUNT_fifo;
    wire[10-1:0] RDCOUNT_fifo;
    wire tx_busy;
    wire tx_busy_fifo;
    wire rd_en_fifo;
    
    assign rd_en_fifo = (WRCOUNT_fifo>2) & tx_busy_fifo;
    
    // Instantiate the ethernet_receiver
    ethernet_receiver #(
        .DATA_WIDTH(DATA_WIDTH),
        .ENABLE_CRC(1),
	.MIN_FRAME_LEN(),
	.MAX_FRAME_LEN()
    ) u0_ethernet_receiver (
        .clk(clk_125m),
        .rst_n(rst_n),
        .rx_dv(rx_dv),
        .rxd(rxd),
        .rx_data(rx_data),
        .rx_data_valid(rx_data_valid),
        .frame_start(frame_start),
        .frame_end(frame_end),
        .frame_length(frame_length),
        .frame_valid(frame_valid),
        .frame_error(frame_error)
    );
    
    wire [8+2-1:0] rx_data_fifo;
    wire is_empty_fifo;
    wire is_full_fifo;
    wire[10-1:0] WRCOUNT_fifo;
    wire[10-1:0] RDCOUNT_fifo;
    wire tx_busy;
    wire tx_busy_fifo;
    wire rd_en_fifo;
    
    assign rd_en_fifo = (WRCOUNT_fifo>2) & tx_busy_fifo;
    
    positive_edge_detector u0_positive_edge_detector (
        .clk(clk_50m),
        .rst_n(rst_n),
        .portA(tx_busy),
        .edge_detect(tx_busy_fifo)
        );
    
    ethernet_uart_debug u0_ethernet_uart_debug (
        .clk(clk_50m),
        .rst_n(rst_n),
        .rx_data_valid(~is_empty_fifo),
        .rx_data(rx_data_fifo[7:0]),
        .frame_start(rx_data_fifo[8]),
        .frame_end(rx_data_fifo[9]),
        .uart_tx(),
        .tx_busy(tx_busy)
    );
   
   dual_clock_fifo #(
	.ADDR_WIDTH(),
       	.DATA_WIDTH(10)	
	) u0_dual_clock_fifo (
	.wr_rst_i(~rst_n),
	.wr_clk_i(clk_125m),
	.wr_en_i(rx_data_valid),
	.wr_data_i({frame_start,frame_end,rx_data}),
	.rd_rst_i(~rst_n),
	.rd_clk_i(clk_50m),
	.rd_en_i(rd_en_fifo),
	.rd_data_o(rx_data_fifo),
	.full_o(),
	.empty_o()
	);
    
endmodule
