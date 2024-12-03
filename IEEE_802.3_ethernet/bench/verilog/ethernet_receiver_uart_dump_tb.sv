`timescale 1ns/1ps

module ethernet_receiver_uart_dump_tb;

    // Parameters
    parameter CLK_PERIOD = 8;  // 125MHz for GMII
    parameter DATA_WIDTH = 8;
    
    // Signals
    input wire clk_125m;
    input wire clk_50m;
    input wire rst_n;

    reg fifo_rst_n;
    reg rx_dv;
    reg [DATA_WIDTH-1:0] rxd;
    
    wire [7:0] rx_data;
    wire rx_data_valid;
    wire frame_start;
    wire frame_end;
    wire [15:0] frame_length;
    wire frame_valid;
    wire frame_error;
    
    // Frame generation parameters
    reg [7:0] test_frame[$];  // Queue to store frame data
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
 


	ethernet_receiver_uart_dump #
	(.CLK_PERIOD(),
	 .DATA_WIDTH()
	) u0_ethernet_receiver_uart_dump (
	       .clk_125m(),
	       .clk_50m(),
	       .rst_n(),
	       rxd()
	);

    
    // CRC calculation function - same as in the main module for consistency
    function [31:0] calc_crc;
        input [7:0] data;
        input [31:0] crc;
        reg [31:0] new_crc;
        integer i;
        begin
            new_crc = crc;
            for (i = 0; i < 8; i = i + 1) begin
                if ((data[i] ^ new_crc[31]) == 1'b1)
                    new_crc = {new_crc[30:0], 1'b0} ^ 32'h04C11DB7;
                else
                    new_crc = {new_crc[30:0], 1'b0};
            end
            calc_crc = new_crc;
        end
    endfunction
    
    // Task to generate a frame with valid CRC
    task generate_frame;
        input [15:0] length;  // Length of payload
        integer i;
        reg [31:0] crc;
        reg [7:0] data;
        begin
            test_frame = {};  // Clear the frame queue
            
            // Add preamble
            repeat(7) test_frame.push_back(8'h55);
            test_frame.push_back(8'hD5);  // SFD
            
            // Generate payload with incrementing pattern
            crc = 32'hFFFFFFFF;
            for(i = 0; i < length; i++) begin
                data = i[7:0];
                test_frame.push_back(data);
                crc = calc_crc(data, crc);
            end
            
            // Append CRC (in little-endian)
            crc = ~crc;  // Final inversion
            test_frame.push_back(crc[7:0]);
            test_frame.push_back(crc[15:8]);
            test_frame.push_back(crc[23:16]);
            test_frame.push_back(crc[31:24]);
        end
    endtask
    
    // Task to send a frame
    task send_frame;
        begin
            rx_dv = 1;
            for(frame_idx = 0; frame_idx < test_frame.size(); frame_idx++) begin
                rxd = test_frame[frame_idx];
                @(posedge clk);
            end
            rx_dv = 0;
            rxd = 0;
            @(posedge clk);
        end
    endtask
    
    // Task to generate and send a corrupted frame
    task send_corrupted_frame;
        input [15:0] length;
        begin
            generate_frame(length);
            // Corrupt the last byte of payload
            test_frame[test_frame.size()-5] = test_frame[test_frame.size()-5] ^ 8'hFF;
            send_frame();
        end
    endtask
    
    // Task to introduce an error in the preamble
    task send_bad_preamble;
        begin
            generate_frame(64);  // Generate a minimum-size frame
            test_frame[3] = 8'hAA;  // Corrupt one preamble byte
            send_frame();
        end
    endtask
    
    // Monitor process
    initial begin
        $monitor("Time=%0t rx_dv=%b frame_start=%b frame_end=%b frame_valid=%b frame_error=%b length=%0d",
                 $time, rx_dv, frame_start, frame_end, frame_valid, frame_error, frame_length);
    end
    
    // Main test process
    initial begin
        // Initialize signals
        rst_n = 0;
        rx_dv = 0;
        rxd = 0;     
        
        // Reset the DUT
        #(CLK_PERIOD*150);
        rst_n = 1;
        #(CLK_PERIOD*10);
       
        
        // Test Case 1: Minimum size frame (64 bytes)
        $display("\nTest Case 1: Minimum size frame");
        generate_frame(60);  // 60 + 4 CRC = 64 bytes
        send_frame();
        #(CLK_PERIOD*20);
        
        // Test Case 2: Medium size frame (512 bytes)
        $display("\nTest Case 2: Medium size frame");
        generate_frame(508);  // 508 + 4 CRC = 512 bytes
        send_frame();
        #(CLK_PERIOD*20);
        
        // Test Case 3: Maximum size frame (1518 bytes)
        $display("\nTest Case 3: Maximum size frame");
        generate_frame(1514);  // 1514 + 4 CRC = 1518 bytes
        send_frame();
        #(CLK_PERIOD*20);
        
        // Test Case 4: Corrupted frame
        $display("\nTest Case 4: Corrupted frame");
        send_corrupted_frame(60);
        #(CLK_PERIOD*20);
        
        // Test Case 5: Bad preamble
        $display("\nTest Case 5: Bad preamble");
        send_bad_preamble();
        #(CLK_PERIOD*20);
        
        // Test Case 6: Undersized frame
        $display("\nTest Case 6: Undersized frame");
        generate_frame(46);  // 46 + 4 CRC = 50 bytes (too small)
        send_frame();
        #(CLK_PERIOD*20);
        
        // Test Case 7: Oversized frame
        $display("\nTest Case 7: Oversized frame");
        generate_frame(1515);  // 1515 + 4 CRC = 1519 bytes (too large)
        send_frame();
        #(CLK_PERIOD*20);
        
        // Test Case 8: Early termination
        $display("\nTest Case 8: Early termination");
        generate_frame(100);
        test_frame = test_frame[0:50];  // Truncate the frame
        send_frame();
        #(CLK_PERIOD*20);
        
        // Test complete
        $display("\nTest completed");
        #(CLK_PERIOD*100);
        $finish;
    end

endmodule
