KERNINC = /usr/src/linux-2.4/include
PERFCTR ?= ./perfctr-2.6.x
PERFCTR_LIB_PATH = $(PERFCTR)/usr.lib

#
# GNU G77 section
#
F77   = g77
FFLAGS        = -Dlinux
FOPTFLAGS= $(OPTFLAGS)
FTOPTFLAGS= $(TOPTFLAGS)
# #
# #  Portland Group PGF77 section
# #
# F77       = pgf77
# FFLAGS    = -Dlinux
# FOPTFLAGS = -O3 -tp p6
# FTOPTFLAGS= $(FOPTFLAGS)
# #
# #  Intel Corp. Fortran compiler
# #
# F77      = ifc
# FFLAGS   = -Dlinux
# LDFLAGS  = -lPEPCF90 -lIEPCF90 -lF90 -lintrins # Intel portability library (getarg_)
# FOPTFLAGS= -O3 -tpp6
# FTOPTFLAGS= $(FOPTFLAGS)

#
# DO NOT TOUCH BELOW HERE UNLESS YOU KNOW WHAT YOU ARE DOING
#

LIBRARY = libpapi.a
SHLIB   = libpapi.so
SUBSTR  = perfctr-$(CPU)
MSUBSTR = linux-perfctr-$(CPU)
MEMSUBSTR= linux
DESCR   = "Linux with PerfCtr 2.6.x patch"
LIBS    = static shared
TARGETS = serial multiplex_and_pthreads

CC_R    = $(CC) -pthread
CFLAGS  = -I$(PERFCTR)/usr.lib -I$(PERFCTR)/linux/include -I$(KERNINC) -I. -DPERFCTR26
#-DDEBUG -DMPX_DEBUG -DMPX_DEBUG_TIMER
MISCSRCS= linux.c $(CPU)_events.c
MISCOBJS= linux.o $(CPU)_events.o marshal.o global.o misc.o virtual.o x86.o
MISCHDRS= perfctr-$(CPU).h
SHLIBDEPS = -L$(PERFCTR_LIB_PATH) -lperfctr
ARCH := $(shell uname -m | sed -e s/i.86/i386/ -e s/sun4u/sparc64/ -e s/arm.*/arm/ -e s/sa110/arm/)

include Makefile.inc

linux.o: linux.c
	rm -f $(PERFCTR)/linux/include/asm
	ln -s asm-${ARCH} $(PERFCTR)/linux/include/asm
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c linux.c -o $@

$(CPU)_events.o: $(CPU)_events.c
	$(CC) $(LIBCFLAGS) $(OPTFLAGS) -c $(CPU)_events.c -o $@

marshal.o global.o misc.o virtual.o x86.o: $(PERFCTR)/usr.lib/libperfctr.a
	ar x $(PERFCTR)/usr.lib/libperfctr.a

$(PERFCTR)/usr.lib/libperfctr.a:
	$(MAKE) -C $(PERFCTR)

native_clean:
	$(MAKE) -C $(PERFCTR) clean

native_install:
	-cp -p $(PERFCTR)/usr.lib/libperfctr.so $(DESTDIR)/lib
	-cp -p $(PERFCTR)/usr.lib/perfctr_event_codes.h $(DESTDIR)/include
	-cp -p $(PERFCTR)/usr.lib/libperfctr.h  $(DESTDIR)/include