TOP=..
APPNAME=main
TARGET=retro

include Make.rules

all: clean $(APPNAME).com

$(APPNAME).bin: $(APPNAME).o
	$(LD) $(LDFLAGS) -o $@ $(CRT0) $^ $(LDLIBS)

$(APPNAME).com: $(APPNAME).bin
	dd if=$^ of=$@ skip=1 bs=256

clean:
	rm -fv $(APPNAME).bin $(APPNAME).com

