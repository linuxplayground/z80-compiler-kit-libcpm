CC=/opt/fcc/bin/fcc
AS=/opt/fcc/bin/asz80
LORDER=/opt/fcc/bin/lorderz80
AR=/usr/bin/ar
CFLAGS=-mz80 -O2 -I include -I /opt/fcc/lib/z80/include

CRT=crt0.o
OBJ=\
		asm/conout.o \
		asm/conin.o \
		asm/writestr.o \
		asm/readstr.o \
		asm/constat.o \
		asm/sio.o \
		libsrc/printstr.o

all: cpmlib.a

cpmlib.a: $(OBJ) $(CRT)
	$(AR) qc $@ `$(LORDER) $(OBJ) | tsort`

$(CRT): asm/crt0.s
	$(AS) -o $@ $^

clean:
	find . -name "*.o" -exec rm -fv {} \;
	rm -fv cpmlib.a
	make -C test clean

world: clean all
	make -C test
