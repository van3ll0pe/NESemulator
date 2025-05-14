
CFLAGS=-I../include -I../src -g -O3
LIBADD += $(shell bash ../src/avr-config --libs)
EXEC=avr-disasm$(EXE_SUFFIX)

all: $(EXEC)

$(EXEC): avr-disasm.o ../src/libavr.a
	$(CC) $(CFLAGS) -o $@ $< $(LIBADD)

clean:
	rm -rf avr-disasm.o

distclean: clean
	rm -rf $(EXEC)
