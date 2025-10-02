TOP=../..


INCLUDES := $(TOP)/include/targets/retro

include $(TOP)/Make.rules

all: libcpm.a

libcpm.a: $(OBJ) $(CRT)
	$(AR) qc $@ `$(LORDER) $(OBJ) | tsort`
	cp $(TOP)/asm/crt0.o ./

