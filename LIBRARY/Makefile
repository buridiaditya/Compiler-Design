CC=gcc
CFLAGS=-I.
DEPS=myl.h
OBJ=ass2_15CS30008.o main.o
%.o: %.c $(DEPS) 
	$(CC) -c -o $@ $< $(CFLAGS)
run: $(OBJ) 
	$(CC) -o $@ $^ $(CFLAGS)
clean: 
	rm -rf *.o *~

