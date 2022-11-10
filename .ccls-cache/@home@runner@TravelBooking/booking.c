#include "booking.h"
#include <stdio.h>
#include <stdlib.h>

struct data {
  int dia;
  int mes;
  int ano;
};

struct voo {
  int codigo;
  char *origem;
  char *destino;
};

struct passageiro {
  int id;
  char *nome;
  char *endereco;
};

struct reserva {
  Data data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};

struct parte {
  Reserva *reserva;
  struct parte *proxima;
};

struct viagem {
  int codigo_hash;
  struct parte *trechos;
};

struct agenda {
  Reserva *reserva;
  Reserva *esq;
  Reserva *dir;
}