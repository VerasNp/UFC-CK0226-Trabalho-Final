CC=gcc
CFLAGS=-I.
DEPS = TabelaViagens.h
OBJ = TestaTabelaViagens.o TabelaViagens.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TestaVoos: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)