.DELETE_ON_ERROR:

.PHONY: all
all:	test

.DELETE_ON_ERROR:
YYMMDD=`date +%Y%m%d`
CXX   := g++
FBDIR := .
VDIRFB:= $(FBDIR)/obj_dir
VERILATOR := verilator

.PHONY: test
## {{{
test: $(VDIRFB)/Vdual_clock_fifo__ALL.a
test: $(VDIRFB)/Vethernet_receiver__ALL.a
test: $(VDIRFB)/Vethernet_receiver_uart_dump__ALL.a
test: $(VDIRFB)/Vethernet_uart_debug__ALL.a
test: $(VDIRFB)/Vpositive_edge_detector__ALL.a
test: $(VDIRFB)/Vuart_transmitter__ALL.a
## }}}

# Verilator generated files
$(VDIRFB)/Vdual_clock_fifo__ALL.a:     $(VDIRFB)/Vdual_clock_fifo.cpp
$(VDIRFB)/Vethernet_receiver__ALL.a:     $(VDIRFB)/Vethernet_receiver.cpp
$(VDIRFB)/Vethernet_receiver_uart_dump__ALL.a: $(VDIRFB)/Vethernet_receiver_uart_dump.cpp
$(VDIRFB)/Vethernet_uart_debug__ALL.a: $(VDIRFB)/Vethernet_uart_debug.cpp
$(VDIRFB)/Vpositive_edge_detector__ALL.a:     $(VDIRFB)/Vpositive_edge_detector.cpp
$(VDIRFB)/Vuart_transmitter__ALL.a:     $(VDIRFB)/Vuart_transmitter.cpp

# Compile all the files
$(VDIRFB)/V%.mk:  $(VDIRFB)/%.h
$(VDIRFB)/V%.h:   $(VDIRFB)/%.cpp
$(VDIRFB)/V%.cpp: $(FBDIR)/%.sv
	$(VERILATOR) --trace -MMD -Wno-lint -cc $*.sv

$(VDIRFB)/V%__ALL.a: $(VDIRFB)/V%.mk
	cd $(VDIRFB); make -f V$*.mk

tags: $(wildcard *.sv)
	ctags *.sv

.PHONY: clean
clean:
	rm -rf tags $(VDIRFB)/

DEPS := $(wildcard $(VDIRFB)/*.d)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(DEPS),)
include $(DEPS)
endif
endif
