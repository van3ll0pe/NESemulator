
CFLAGS=-I../include -I../src -g -O3
LIBADD += $(shell bash ../src/mos6502-config --libs)
EXEC=mos6502-disasm$(EXE_SUFFIX)

all: $(EXEC)

$(EXEC): mos6502-disasm.o ../src/libmos6502.a
	$(CC) $(CFLAGS) -o $@ $< $(LIBADD)

clean:
	rm -rf mos6502-disasm.o

distclean: clean
	rm -rf $(EXEC)
