CFLAGS=-I../include -I../src -g -O3
LIBADD =  $(shell bash ../src/avr-config --libs)
EXEC=avr-sim$(EXE_SUFFIX)

all: $(EXEC)

$(EXEC): avr-sim.o  ../src/libavr.a
	$(CC) $(CFLAGS) -o $@ $< $(LIBADD)

clean:
	rm -f avr-sim.o

distclean: clean
	rm -f $(EXEC)
