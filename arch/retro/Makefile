TOP=../..


INCLUDES := $(TOP)/include/targets/retro

include $(TOP)/Make.rules

all: libcpm.a

libcpm.a: $(OBJ) $(CRT)
	mkdir -pv $(TOP)/build/arch/retro
	$(AR) qc $(TOP)/build/arch/retro/$@ `$(LORDER) $(OBJ) | tsort`
	cp $(TOP)/asm/crt0.o $(TOP)/build/arch/retro/

