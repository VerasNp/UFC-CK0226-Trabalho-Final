CC=gcc
CFLAGS=-I.
DEPS = Passageiro.h ListaPassageiros.h PassageirosTeste.h ListaTeste.h
OBJ = TestesPassageiro.o Passageiro.o ListaPassageiros.o PassageirosTeste.o ListaTeste.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

TestesPassageiro: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)