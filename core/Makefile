# configuration
ARCH=mos6502
HOST_ENDIAN		= little	# change to big if required
TARGET_ENDIAN	= little	# change to big if required

-include config.mk

MEMORY=vfast_mem			# select here the memory module
LOADER=old_elf				# select here the loaded module

# goals definition
GOALS		=
SUBDIRS		=	src
CLEAN		=	$(ARCH).irg
DISTCLEAN	=	include src
GFLAGS		=

ifdef WITH_DISASM
GOALS		+=	$(ARCH)-disasm
SUBDIRS		+= 	disasm
DISTCLEAN	+= 	disasm
GFLAGS		+=	-a disasm.c
endif

ifdef WITH_SIM
GOALS		+=	$(ARCH)-sim
SUBDIRS		+=	sim
DISTCLEAN	+=	sim config.mk
GFLAGS		+=	-S
endif

ifdef WITH_DYNLIB
REC_FLAGS = WITH_DYNLIB=1
endif

GFLAGS += -D \
	-m mem:$(MEMORY) \
	-m loader:$(LOADER) \
	-m env:void_env \
	-m code:code \
	-config extern/config.tpl

NMP_MAIN = $(ARCH).nmp
NMP = $(NMP_MAIN)

# targets
all: config.mk lib $(GOALS)

$(ARCH).irg: $(NMP)
	$(GLISS_PREFIX)/irg/mkirg $(NMP_MAIN) $@

$(ARCH).nml: $(NMP)
	$(GLISS_PREFIX)/gep/gliss-nmp2nml.pl $(NMP_MAIN) $@

src include: $(ARCH).irg
	$(GLISS_PREFIX)/gep/gep $(GFLAGS) $< -S

check: $(ARCH).irg
	$(GLISS_PREFIX)/gep/gep $(GFLAGS) $< -S -c

lib: src include include/$(ARCH)/config.h src/disasm.c
	(cd src; make -j $(REC_FLAGS))

$(ARCH)-disasm:
	cd disasm; make -j3

$(ARCH)-sim:
	cd sim; make -j3

src/disasm.c: $(ARCH).irg
	$(GLISS_PREFIX)/gep/gliss-disasm -switch $< -o $@ -c

distclean: clean
	-for d in $(SUBDIRS); do test -d $$d && (cd $$d; make distclean || exit 0); done
	-rm -rf $(DISTCLEAN)

clean: only-clean
	-for d in $(SUBDIRS); do test -d $$d && (cd $$d; make clean || exit 0); done

only-clean:
	-rm -rf $(CLEAN)

HOST_ENDIAN = $(shell python3 -c "import sys; print(sys.byteorder)")

#include/$(ARCH)/config.h: extern/config.tpl
#	test -d include/$(ARCH) || mkdir include/$(ARCH)
#	cp extern/config.tpl $@
#	echo "#define TARGET_ENDIANNESS $(TARGET_ENDIAN)" >> $@
#	echo "#define HOST_ENDIANNESS $(HOST_ENDIAN)" >> $@

config: config.mk

config.mk: config.tpl
	cp $< $@