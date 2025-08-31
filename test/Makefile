TOP=.
CC=/opt/fcc/bin/fcc
AS=/opt/fcc/bin/asz80
LD=/opt/fcc/bin/ldz80

CFLAGS=-O2 -mz80 -I $(TOP)/../include -I /opt/fcc/lib/z80/include
LDFLAGS=-b -C0x100 -m console.map
LIBS=\
		 $(TOP)/../cpmlib.a \
		 /opt/fcc/lib/z80/libz80.a \
		 /opt/fcc/lib/z80/libc.a

CRT=$(TOP)/../crt0.o

all: clean console.com copy

malloc.bin: malloc.o
	$(LD) $(LDFLAGS) -o $@ $(CRT) $^ $(LIBS)

malloc.com: malloc.bin
	dd if=$^ of=$@ skip=1 bs=256

clean:
	rm -fv malloc.bin malloc.com
	find . -name "*.o" -exec rm -fv {} \;

copy: malloc.com
	cpmrm -f z80-retro-8k-8m /dev/loop0p1 0:malloc.com
	cpmcp -f z80-retro-8k-8m /dev/loop0p1 malloc.com 0:
