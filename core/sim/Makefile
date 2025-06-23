CFLAGS=-I../include -I../src -g -O3
LIBADD =  $(shell bash ../src/mos6502-config --libs)
EXEC=mos6502-sim$(EXE_SUFFIX)

all: $(EXEC)

$(EXEC): mos6502-sim.o  ../src/libmos6502.a
	$(CC) $(CFLAGS) -o $@ $< $(LIBADD)

clean:
	rm -f mos6502-sim.o

distclean: clean
	rm -f $(EXEC)
