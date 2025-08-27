CC=/opt/fcc/bin/fcc
AS=/opt/fcc/bin/asz80
LORDER=/opt/fcc/bin/lorderz80
AR=/usr/bin/ar

CFLAGS=-mz80 -O2 $(CONFIG) -I include -I /opt/fcc/lib/z80/include

CRT=crt0.o
ASMSRC=$(wildcard asm/*.s)
ASMOBJ=$(ASMSRC:.s=.o)
CSRC=$(wildcard libsrc/*.c)
COBJ=$(CSRC:.c=.o)

OBJ=\
		$(ASMOBJ) \
		$(COBJ)

all: cpmlib.a

cpmlib.a: $(OBJ) $(CRT)
	$(AR) qc $@ `$(LORDER) $(OBJ) | tsort`

$(CRT): crt0.s
	$(AS) -o $@ $^

clean:
	find . -name "*.o" -exec rm -fv {} \;
	rm -fv cpmlib.a
	make -C test clean

world: clean all
	make -C test
