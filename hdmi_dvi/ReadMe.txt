https://github.com/ultraembedded/core_dvi_framebuffer/blob/master/src_v/dvi_framebuffer.v
https://web.mit.edu/6.111/www/f2017/handouts/L05_4.pdf



Configuration Registers:
- config_x2_mode_q: (1-bit)      : Internal configuration for X2 mode. This likely controls pixel doubling or some form of horizontal scaling.
- config_int_en_sof_q: (1-bit)   : Internal configuration to enable an interrupt at the Start of Frame (SOF).
- config_enable_q: (1-bit)       : Internal configuration to globally enable or disable the video output of the framebuffer.

Status Registers:
- status_y_pos_in_w / status_y_pos_out_w: (16-bit) :  Although status_y_pos_in_w is a wire assigned from v_pos_q, and status_y_pos_out_w is a wire assigned from wr_data_q, the code implies a status register named STATUS that includes vertical position information. 
                                                      This likely reflects the current vertical position of the video raster scan.
- status_h_pos_in_w / status_h_pos_out_w: (16-bit) :  Similar to status_y_pos, these signals represent the horizontal position status, likely reflecting the current horizontal position of the video raster scan.

pixel_fetch_fifo
- ram with 10-bit address [9:0], and each address holds 32-bits data.  Therefore 1024x32 

//-----------------//
// fifo allocation //
//-----------------//
- allocated_q[15:0] keep tracks of the number of 32-bits written to the pixel_fetch_fifo
- data is written to the fifo when (outport_arvalid_o == 1 && outport_arready_i == 1).  In addition when (pixel_valid_w == 1 && pixel_pop_w == 1), 
    allocated_q <= allocated_q + {6'b0, outport_arlen_o, 2'b0} aka increment by 28
    else
    allocated_q <= allocated_q + {6'b0, (outport_arlen_o + 8'd1), 2'b0} aka increment by 32

    outport_arlen_o = (BURST_LEN/4) - 1 where BURST_LEN=32

    allocated_q has the unit of Byte, so increment by 32 means 32 * 32, increment by 28 means that ?

//-------------//
// axi request //
//-------------//
fifo_space_w = (allocated_q <= (BUFFER_SIZE - BURST_LEN));
- BUFFER_SIZE - BURST_LEN = 1024-32 (Why -32? To leave some space?)
