TOP=../..


INCLUDES := $(TOP)/include/targets/retro

include $(TOP)/Make.rules

all: libcpm.a

libcpm.a: $(OBJ) $(CRT)
	mkdir -pv $(TOP)/build/arch/nouveau
	$(AR) qc $(TOP)/build/arch/nouveau/$@ `$(LORDER) $(OBJ) | tsort`
	cp $(TOP)/asm/crt0.o $(TOP)/build/arch/nouveau/

