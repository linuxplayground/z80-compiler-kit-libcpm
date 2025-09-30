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
# https://github.com/linuxplayground/z80-retro-libcpm.git
#
#****************************************************************************
TOP=.
CC=/opt/fcc/bin/fcc
AS=/opt/fcc/bin/asz80
LORDER=/opt/fcc/bin/lorderz80
AR=/usr/bin/ar
CPP=/usr/bin/cpp -undef -nostdinc

include Make.default
-include Make.local
include target/rules.$(TARGET)

CFLAGS=-mz80 -O2 -I include -I /opt/fcc/lib/z80/include
CPPFLAGS=-I$(INCLUDES)

CRT0=crt0.o

ASMPSRCS=$(wildcard asm/*.S)
ASMPSRC=$(ASMPSRCS:.S=.s)
ASMPOBJ=$(ASMPSRCS:.S=.o)

ASMSRC=$(wildcard asm/*.s)
ASMOBJ=$(ASMSRC:.s=.o)

CSRC=$(wildcard libsrc/*.c)
COBJ=$(CSRC:.c=.o)

OBJ=\
		$(ASMPOBJ) \
		$(ASMOBJ) \
		$(COBJ)


all: libcpm.a

libcpm.a: $(ASMPSRC) $(OBJ) $(CRT)
	$(AR) qc $@ `$(LORDER) $(OBJ) | tsort`

%.s: %.S
	$(CPP) $(CPPFLAGS) $^ > $@

clean:
	rm -fv $(OBJ)
	rm -fv $(ASMPSRC)

	rm -fv libcpm.a
	make -C examples clean
	make -C docs clean

docs:
	make -C docs

world: clean all
	make -C examples all
