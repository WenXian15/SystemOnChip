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
test: $(VDIRFB)/Vtxuart__ALL.a
test: $(VDIRFB)/Vrxuart__ALL.a
test: $(VDIRFB)/Vwbuart__ALL.a
test: $(VDIRFB)/Vtxuartlite__ALL.a
test: $(VDIRFB)/Vrxuartlite__ALL.a
## }}}

$(VDIRFB)/Vrxuart__ALL.a:     $(VDIRFB)/Vrxuart.cpp
$(VDIRFB)/Vtxuart__ALL.a:     $(VDIRFB)/Vtxuart.cpp
$(VDIRFB)/Vrxuartlite__ALL.a: $(VDIRFB)/Vrxuartlite.cpp
$(VDIRFB)/Vtxuartlite__ALL.a: $(VDIRFB)/Vtxuartlite.cpp
$(VDIRFB)/Vwbuart__ALL.a:     $(VDIRFB)/Vwbuart.cpp

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
