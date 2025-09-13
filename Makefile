#****************************************************************************
#
#    Copyright (C) 2025 David Latham
#
#    This library is free software; you can redistribute it and/or
#    modify it under the terms of the GNU Lesser General Public
#    License as published by the Free Software Foundation; either
#    version 2.1 of the License, or (at your option) any later version.
#
#    This library is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#    Lesser General Public License for more details.
#
#    You should have received a copy of the GNU Lesser General Public
#    License along with this library; if not, write to the Free Software
#    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
#    USA
#
# https://github.com/linuxplayground/z80-retro-cpmlib.git
#
#****************************************************************************

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
	make -C examples clean

world: clean all
	make -C examples all
