// Module to connect Ethernet receiver to UART transmitter
module ethernet_uart_debug (
    input wire clk,              // System clock
    input wire rst_n,            // Active low reset
    
    // Ethernet receiver interface
    input wire rx_data_valid,    // From ethernet_receiver
    input wire [7:0] rx_data,    // From ethernet_receiver
    input wire frame_start,      // From ethernet_receiver
    input wire frame_end,        // From ethernet_receiver
    
    // UART output
    output wire uart_tx,          // UART TX line
    output wire tx_busy           // FIFO Read Enable
);

    // Internal signals
    reg send_byte;
    reg [7:0] byte_to_send;

    // State to handle frame markers
    localparam [7:0] 
        FRAME_START_MARKER = 8'hF8,
        FRAME_END_MARKER = 8'hF9;

    // State machine states
    localparam [1:0]
        WAIT_DATA = 2'd0,
        SEND_MARKER = 2'd1,
        SEND_DATA = 2'd2;

    reg [1:0] state;

    // UART transmitter instance
    uart_transmitter #(
        .CLKS_PER_BIT(54)  // 115200 baud at 50MHz
    ) uart_tx_inst (
        .clk(clk),
        .rst_n(rst_n),
        .data_in(byte_to_send),
        .data_valid(send_byte),
        .tx_busy(tx_busy),
        .uart_tx(uart_tx)
    );

    // Control logic for sending bytes
    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            state <= WAIT_DATA;
            send_byte <= 1'b0;
            byte_to_send <= 8'h00;
        end else begin
            case (state)
                WAIT_DATA: begin
                    send_byte <= 1'b0;
                    if (frame_start && !tx_busy) begin
                        byte_to_send <= FRAME_START_MARKER;
                        send_byte <= 1'b1;
                        state <= SEND_MARKER;
                    end else if (rx_data_valid && !tx_busy) begin
                        byte_to_send <= rx_data;
                        send_byte <= 1'b1;
                        state <= SEND_DATA;
                    end else if (frame_end && !tx_busy) begin
                        byte_to_send <= FRAME_END_MARKER;
                        send_byte <= 1'b1;
                        state <= SEND_MARKER;
                    end
                end

                SEND_MARKER, SEND_DATA: begin
                    send_byte <= 1'b0;
                    if (!tx_busy) begin
                        state <= WAIT_DATA;
                    end
                end

                default: state <= WAIT_DATA;
            endcase
        end
    end

endmodule
