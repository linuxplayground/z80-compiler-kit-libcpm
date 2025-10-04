TOP=..
CC=/opt/fcc/bin/fcc
AS=/opt/fcc/bin/asz80
LD=/opt/fcc/bin/ldz80

CFLAGS=-O2 -mz80 -I /home/davelatham/dev/libcpm/include
LDFLAGS=-b -C0x100
LDLIBS=\
	/home/davelatham/dev/libcpm/lib/arch/retro/libcpm.a \
	/opt/fcc/lib/z80/libz80.a \
	/opt/fcc/lib/z80/libc.a

CRT0=/home/davelatham/dev/libcpm/lib/arch/retro/crt0.o

APPNAME=main

.INTERMEDIATE: $(APPNAME).o $(APPNAME).bin

all: clean $(APPNAME).com

$(APPNAME).bin: $(APPNAME).o $(CRT0)
	$(LD) $(LDFLAGS) -o $@ $< $(LDLIBS)

$(APPNAME).com: $(APPNAME).bin
	dd if=$^ of=$@ skip=1 bs=256

clean:
	rm -fv $(APPNAME).com

