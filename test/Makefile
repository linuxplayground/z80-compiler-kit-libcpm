TOP=.
CC=/opt/fcc/bin/fcc
AS=/opt/fcc/bin/asz80
LD=/opt/fcc/bin/ldz80

CFLAGS=-O3 -mz80 -I $(TOP)/../include -I /opt/fcc/lib/z80/include
LDFLAGS=-b -C0x100 -m console.map
LIBS=\
		 $(TOP)/../cpmlib.a \
		 /opt/fcc/lib/z80/libz80.a \
		 /opt/fcc/lib/z80/libc.a

OBJ=console.o
CRT=$(TOP)/../crt0.o

all: console.com

console.bin: $(OBJ)
	$(LD) $(LDFLAGS) -o $@ $(CRT) $^ $(LIBS)

console.com: console.bin
	dd if=$^ of=$@ skip=1 bs=256

clean:
	rm -fv console.bin console.com
	find . -name "*.o" -exec rm -fv {} \;

copy: console.com
	cpmrm -f z80-retro-8k-8m /dev/loop0p1 0:console.com
	cpmcp -f z80-retro-8k-8m /dev/loop0p1 console.com 0:
