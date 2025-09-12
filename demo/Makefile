TOP=.
CC=/opt/fcc/bin/fcc
AS=/opt/fcc/bin/asz80
LD=/opt/fcc/bin/ldz80

CFLAGS=-O2 -mz80 -I $(TOP)/../include -I /opt/fcc/lib/z80/include
LDFLAGS=-b -C0x100 -m $@.map
LIBS=\
		 $(TOP)/../cpmlib.a \
		 /opt/fcc/lib/z80/libz80.a \
		 /opt/fcc/lib/z80/libc.a

CRT=$(TOP)/../crt0.o
APPNAME=demo

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
