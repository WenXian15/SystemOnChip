.PHONY: all
.DELETE_ON_ERROR:
## }}}
all:	test
## {{{
YYMMDD=`date +%Y%m%d`
CXX   := g++
FBDIR := .
VDIRFB:= $(FBDIR)/obj_dir
RTLDR := ../../rtl
VERILATOR := verilator
VFLAGS := -Wall --MMD --trace -y $(RTLDR) -cc --timing --timescale 1ns/1ps -sv +systemverilogext+sv -Wno-lint
# --timescale 1ns/1ps		: Add timescale
# -sv +systemverilogext=sv 	: Support systemverilog parsing
# --waiver-output waiver.txt 	: Export a lint waiver file

.PHONY: helloworld
## }}}
test: helloworld
## Dependencies
## {{{
helloworld:       $(VDIRFB)/Vhelloworld__ALL.a

$(VDIRFB)/Vlinetest__ALL.a:       $(VDIRFB)/Vhelloworld.cpp
## }}}

## Verilate build instructions
## {{{
$(VDIRFB)/V%.mk:  $(VDIRFB)/V%.h
$(VDIRFB)/V%.h:   $(VDIRFB)/V%.cpp
$(VDIRFB)/V%.cpp: $(FBDIR)/%.v
	$(VERILATOR) $(VFLAGS) $*.v

$(VDIRFB)/Vhelloworld.cpp: $(FBDIR)/helloworld.sv
	$(VERILATOR) $(VFLAGS) -DUSE_UART_LITE --prefix Vhelloworld helloworld.sv
## }}}

## Turn C++ to libraries
## {{{
$(VDIRFB)/V%__ALL.a: $(VDIRFB)/V%.cpp
	cd $(VDIRFB); make -f V$*.mk
## }}}

## TAGS
## {{{
tags: $(wildcard *.v) $(wildcard $(RTLDR)/*.v)
	ctags *.v $(RTLDR)/*.v
## }}}

## Clean
## {{{
.PHONY: clean
clean:
	rm -rf tags $(VDIRFB)/
## }}}

## Automatic dependency handling
## {{{
DEPS := $(wildcard $(VDIRFB)/*.d)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(DEPS),)
include $(DEPS)
endif
endif
## }}}
