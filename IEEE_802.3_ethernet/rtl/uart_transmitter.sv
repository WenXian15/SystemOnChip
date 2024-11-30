module uart_transmitter #(
    parameter CLKS_PER_BIT = 54  // For 115200 baud at 50MHz: 50000000/115200=434 | 50000000/921600=54
) (
    input wire clk,              // System clock (50MHz assumed)
    input wire rst_n,            // Active low reset
    
    // Data input interface
    input wire [7:0] data_in,    // Byte to transmit
    input wire data_valid,       // Signal to start transmission
    output reg tx_busy,          // High when transmitting
    
    // UART output
    output reg uart_tx           // UART TX line
);

    // State machine states
    localparam [1:0]
        IDLE = 2'd0,        // 00
        START_BIT = 2'd1,   // 01
        DATA_BITS = 2'd2,   // 10
        STOP_BIT = 2'd3;    // 11

    // Internal registers
    reg [2:0] state;
    reg [8:0] clock_count;  // Counter for bit timing
    reg [2:0] bit_index;    // Current bit being transmitted
    reg [7:0] data_reg;     // Register to hold the data being transmitted
    

    // State machine
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= IDLE;
            uart_tx <= 1'b1;     // UART line is high when idle
            tx_busy <= 1'b0;
            clock_count <= 9'd0;
            bit_index <= 3'd0;
            data_reg <= 8'd0;
        end else begin
            case (state)
                IDLE: begin
                    uart_tx <= 1'b1;         // Keep line high
                    clock_count <= 9'd0;
                    bit_index <= 3'd0;
                    
                    if (data_valid) begin
                        state <= START_BIT;
                        tx_busy <= 1'b1;
                        data_reg <= data_in;  // Latch the input data
                    end else begin
                        tx_busy <= 1'b0;
                    end
                end

                START_BIT: begin
                    uart_tx <= 1'b0;  // Start bit is low
                    
                    if (clock_count < CLKS_PER_BIT - 1) begin
                        clock_count <= clock_count + 1'b1;
                    end else begin
                        state <= DATA_BITS;
                        clock_count <= 9'd0;
                    end
                end

                DATA_BITS: begin
                    uart_tx <= data_reg[bit_index];  // Send each bit
                    
                    if (clock_count < CLKS_PER_BIT - 1) begin
                        clock_count <= clock_count + 1'b1;
                    end else begin
                        clock_count <= 9'd0;
                        
                        if (bit_index < 7) begin
                            bit_index <= bit_index + 1'b1;
                        end else begin
                            state <= STOP_BIT;
                        end
                    end
                end

                STOP_BIT: begin
                    uart_tx <= 1'b1;  // Stop bit is high
                    
                    if (clock_count < CLKS_PER_BIT - 1) begin
                        clock_count <= clock_count + 1'b1;
                    end else begin
                        state <= IDLE;
                        tx_busy <= 1'b0;
                    end
                end

                default: state <= IDLE;
            endcase
        end
    end

endmodule
