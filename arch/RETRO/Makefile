TOP=../..


ARCH=RETRO
INCLUDES := $(TOP)/include/arch/$(ARCH)

include $(TOP)/Make.rules

all:: libcpm.a

libcpm.a: $(OBJS)
	mkdir -pv $(TOP)/build/arch/$(ARCH)
	$(AR) qc $(TOP)/build/arch/$(ARCH)/$@ `$(LORDER) $(OBJS) | tsort`

clean:
	rm -fr $(TOP)/build/arch/RETRO/*
