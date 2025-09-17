TOP=..
APPNAME=args

include ../Make.rules

all: clean $(APPNAME).com

$(APPNAME).bin: $(APPNAME).o
	$(LD) $(LDFLAGS) -o $@ $(CRT) $^ $(LIBS)

$(APPNAME).com: $(APPNAME).bin
	dd if=$^ of=$@ skip=1 bs=256

clean:
	rm -fv $(APPNAME).bin $(APPNAME).com
	find . -name "*.o" -exec rm -fv {} \;

copy: $(APPNAME).com
	cpmrm -f z80-retro-8k-8m /dev/loop0p1 0:$(APPNAME).com
	cpmcp -f z80-retro-8k-8m /dev/loop0p1 $(APPNAME).com 0:
