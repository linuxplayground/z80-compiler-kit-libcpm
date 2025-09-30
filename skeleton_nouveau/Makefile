TOP=..
APPNAME=main

include Make.rules

all: clean $(APPNAME).com

$(APPNAME).bin: $(APPNAME).o
	$(LD) $(LDFLAGS) -o $@ $(CRT) $^ $(LIBS)

$(APPNAME).com: $(APPNAME).bin
	dd if=$^ of=$@ skip=1 bs=256

clean:
	rm -fv $(APPNAME).bin $(APPNAME).com

