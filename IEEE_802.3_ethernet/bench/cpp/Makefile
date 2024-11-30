
CXX	:= g++
FLAGS	:= -Wall -Og -g
OBJDIR  := obj-pc
RTLD	:= ../verilog
VERILATOR_ROOT ?= $(shell bash -c 'verilator -V|grep VERILATOR_ROOT | head -1 | sed -e " s/^.*=\s*//"')
VROOT   := $(VERILATOR_ROOT)
INCS	:= -I$(RTLD)/obj_dir/ -I$(VROOT)/include
SOURCES := helloworld.cpp linetest.cpp uartsim.cpp uartsim.h
VOBJDR	:= $(RTLD)/obj_dir
SYSVDR	:= $(VROOT)/include

all : $(OBJDIR)/ uart

# Verilator's generated Makefile sets VM_*
VSRC	:= (addsuffix .cpp $(VM_GLOBAL_FAST) $(VM_GLOBAL_SLOW)) 
VLIB	:= $(addprefix $(OBJDIR)/,$(subst .cpp,.o,$(VSRC)))

$(OBJDIR)/uartsim.o uartsim.cpp uartsim.h


uart: uart.cpp
		$(CXX) uart.cpp -o $@
