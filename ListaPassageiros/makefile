CC=gcc
CFLAGS=-I.
DEPS = Passageiro.h ListaPassageiros.h
OBJ = TestaPassageiro.o Passageiro.o ListaPassageiros.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TestesPassageiro: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)