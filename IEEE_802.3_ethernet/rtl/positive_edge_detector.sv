module positive_edge_detector(
        input wire clk,
        input wire rst_n,
        input wire portA,
        output wire edge_detect
    );
 
    reg temp_reg;
    
    assign edge_detect = portA & ~temp_reg;
    
    always @(posedge clk) begin
        if (!rst_n) begin
            temp_reg <= 1'b0;
        end else begin
            temp_reg <= portA;
        end
    end  // <-- This end was missing
    
endmodule
