CXX	:= g++
FLAGS	:= -Wall -Og -g
OBJDIR  := obj-pc
RTLD	:= ../verilog
VERILATOR_ROOT ?= $(shell bash -c 'verilator -V|grep VERILATOR_ROOT | head -1 | sed -e " s/^.*=\s*//"')
VROOT   := $(VERILATOR_ROOT)
INCS	:= -I$(RTLD)/obj_dir/ -I$(VROOT)/include
SOURCES := helloworld.cpp  uartsim.cpp uartsim.h
VOBJDR	:= $(RTLD)/obj_dir
SYSVDR	:= $(VROOT)/include

all:	$(OBJDIR)/ helloworld

define mk-objdir
	@echo "mk-objdir"
	@bash -c "if [ ! -e $(OBJDIR) ]; then mkdir -p $(OBJDIR); fi"
endef

# The "define" target, to know what files things depend upon.  The depends
# file itself is kept in $(OBJDIR)/depends.txt
# WenXian: Not sure how obj-pc is created.
define	build-depends
	$(mk-objdir)
	@echo "Building dependency file"
	@$(CXX) $(FLAGS) $(INCS) -MM $(SOURCES) > $(OBJDIR)/xdepends.txt
	@sed -e 's/^.*.o: /$(OBJDIR)\/&/' < $(OBJDIR)/xdepends.txt > $(OBJDIR)/depends.txt
	@rm $(OBJDIR)/xdepends.txt
endef

.PHONY: depends
depends:
	$(build-depends)

$(OBJDIR)/depends.txt: depends

# Not sure what is this 
ifneq ($(MAKECMDGOALS),clean)
-include $(OBJDIR)/depends.txt
endif

# Verilator's generated Makefile sets VM_*
VSRC	:= $(addsuffix .cpp, $(VM_GLOBAL_FAST) $(VM_GLOBAL_SLOW)) 
VLIB	:= $(addprefix $(OBJDIR)/,$(subst .cpp,.o,$(VSRC)))

$(OBJDIR)/uartsim.o: uartsim.cpp uartsim.h

$(OBJDIR)/%.o: %.cpp
	$(mk-objdir)
	$(CXX) $(FLAGS) $(INCS) -c $< -o $@

$(OBJDIR)/%.o: $(SYSVDR)/%.cpp
	$(mk-objdir)
	$(CXX) $(FLAGS) $(INCS) -c $< -o $@

# Sources dependencis necessary to build the main program
HLOSRCS := helloworld.cpp uartsim.cpp
HLOOBJ := $(subst .cpp,.o,$(HLOSRCS))
HLOOBJS := $(addprefix $(OBJDIR)/,$(HLOOBJ)) $(VLIB)
helloworld: $(HLOOBJS) $(VOBJDR)/Vhelloworld__ALL.a
	$(CXX) $(FLAGS) $(INCS) $^ -lpthread -o $@
	@echo "Run helloworld"

.PHONY: clean
clean:
	rm -f ./helloworld
	rm -rf $(OBJDIR)/
