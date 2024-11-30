module ethernet_receiver #(
    parameter DATA_WIDTH = 8,  // RMII = 4, GMII/MII = 8
    parameter ENABLE_CRC = 1,  // Enable CRC checking
    parameter MIN_FRAME_LEN = 64,
    parameter MAX_FRAME_LEN = 1518
) (
    input wire clk,                    // Input clock (25MHz for MII, 50MHz for RMII, 125MHz for GMII)
    input wire rst_n,                  // Active low reset
    input wire rx_dv,                  // Data valid signal
    input wire [DATA_WIDTH-1:0] rxd,   // Receive data
    
    // User interface signals
    output reg [7:0] rx_data,          // Received data byte
    output reg rx_data_valid,          // Data valid signal
    output reg frame_start,            // Start of frame indicator
    output reg frame_end,              // End of frame indicator
    output reg [15:0] frame_length,    // Length of received frame
    output reg frame_valid,            // Frame valid indicator (CRC check passed)
    output reg frame_error             // Frame error indicator
);

    // State machine states
    localparam [3:0] 
        IDLE = 4'd0,
        PREAMBLE = 4'd1,
        SFD = 4'd2,
        DATA = 4'd3,
        CHECK_CRC = 4'd4,
        WAIT_END = 4'd5;

    // Constants
    localparam [7:0] 
        PREAMBLE_BYTE = 8'h55,
        SFD_BYTE = 8'hD5;

    // CRC calculation
    reg [31:0] crc_reg;
    wire [31:0] crc_next;
    reg crc_init;
    reg crc_calc;

    // Internal registers
    reg [3:0] state;
    reg [15:0] byte_count;
    reg [2:0] preamble_count;
    
    // CRC-32 calculation function
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

    // State machine
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
            rx_data <= 8'h0;
            rx_data_valid <= 1'b0;
            frame_start <= 1'b0;
            frame_end <= 1'b0;
            frame_length <= 16'h0;
            frame_valid <= 1'b0;
            frame_error <= 1'b0;
            byte_count <= 16'h0;
            preamble_count <= 3'h0;
            crc_init <= 1'b0;
            crc_calc <= 1'b0;
        end else begin
            // Default assignments
            rx_data_valid <= 1'b0;
            frame_start <= 1'b0;
            frame_end <= 1'b0;
            crc_init <= 1'b0;
            
            case (state)
                IDLE: begin
                    if (rx_dv && rxd == PREAMBLE_BYTE) begin
                        state <= PREAMBLE;
                        preamble_count <= 3'h1;
                        byte_count <= 16'h0;
                        frame_valid <= 1'b0;
                        frame_error <= 1'b0;
                    end
                end

                PREAMBLE: begin
                    if (!rx_dv) begin
                        state <= IDLE;
                        frame_error <= 1'b1;
                    end else if (rxd == PREAMBLE_BYTE) begin
                        if (preamble_count == 3'h6)
                            state <= SFD;
                        else
                            preamble_count <= preamble_count + 1'b1;
                    end else if (rxd == SFD_BYTE) begin
                        state <= DATA;
                        frame_start <= 1'b1;
                        crc_init <= 1'b1;
                    end else begin
                        state <= IDLE;
                        frame_error <= 1'b1;
                    end
                end

                SFD: begin
                    if (!rx_dv) begin
                        state <= IDLE;
                        frame_error <= 1'b1;
                    end else if (rxd == SFD_BYTE) begin
                        state <= DATA;
                        frame_start <= 1'b1;
                        crc_init <= 1'b1;
                    end else begin
                        state <= IDLE;
                        frame_error <= 1'b1;
                    end
                end

                DATA: begin
                    if (!rx_dv) begin
                        if (byte_count < MIN_FRAME_LEN) begin
                            state <= IDLE;
                            frame_error <= 1'b1;
                        end else begin
                            state <= CHECK_CRC;
                            frame_end <= 1'b1;
                        end
                    end else if (byte_count >= MAX_FRAME_LEN - 4) begin
                        state <= WAIT_END;
                        frame_error <= 1'b1;
                    end else begin
                        rx_data <= rxd;
                        rx_data_valid <= 1'b1;
                        byte_count <= byte_count + 1'b1;
                        crc_calc <= 1'b1;
                    end
                end

                CHECK_CRC: begin
                    if (ENABLE_CRC) begin
                        frame_valid <= (crc_reg == 32'h2144DF1C); // CRC residue
                        state <= IDLE;
                    end else begin
                        frame_valid <= 1'b1;
                        state <= IDLE;
                    end
                    frame_length <= byte_count - 4; // Subtract CRC length
                end

                WAIT_END: begin
                    if (!rx_dv)
                        state <= IDLE;
                end

                default: state <= IDLE;
            endcase
        end
    end

    // CRC calculation
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            crc_reg <= 32'hFFFFFFFF;
        end else if (crc_init) begin
            crc_reg <= 32'hFFFFFFFF;
        end else if (crc_calc) begin
            crc_reg <= calc_crc(rxd, crc_reg);
        end
    end

endmodule
