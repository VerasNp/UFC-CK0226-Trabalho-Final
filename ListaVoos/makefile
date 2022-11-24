CC=gcc
CFLAGS=-I.
DEPS = ListaVoos.h Voos.h
OBJ = TestaVoos.o ListaVoos.o Voos.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TestaVoos: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)