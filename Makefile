ifndef TOPDIR
TOPDIR=..
endif
include $(TOPDIR)/Makefile.global

TARGETS = checkinput

build: $(TARGETS)

install:

clean-l:
	-rm -f $(TARGETS)
