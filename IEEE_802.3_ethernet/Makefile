all: rtl bench test

.PHONY: rtl
rtl:
	cd rtl; $(MAKE) --no-print-directory

.PHONY: bench
bench: rtl
	cd bench ; $(MAKE) --no-print-directory

.PHONY: test
test: bench
	bench/cpp/uart

.PHONY: clean
clean:
	cd rtl ; $(MAKE) --no-print-directory clean
	cd bench/verilog ; $(MAKE) -no-print-directory clean
	cd bench/cpp ; $(MAKE) --no-pirnt-directory clean
