#include <stdio.h>
#include <stdlib.h>
#include "Utils/Enums.h"
#include "Utils/Headers.h"

struct voo {
  int codigo;
  char *origem;
  char *destino;
};

struct no_voo {
  Voo *voo;
  struct no_voo *proximo;
};

struct lista_voo {
  struct no_voo *primeiro;
};

struct passageiro {
  int id;
  char *nome;
  char *endereco;
};

struct no_passageiro {
  Passageiro *passageiro;
  struct no_passageiro *proximo;
};

struct lista_passageiro {
  struct no_passageiro *primeiro;
};

struct reserva {
  int codigo;
  Data *data_viagem;
  Passageiro *passageiro;
  Voo *voo;
  Assento assento;
};

struct agenda {
  Reserva *reserva;
  Agenda *esq;
  Agenda *dir;
};

struct trecho {
  Reserva *reserva;
  struct trecho *proximo;
};

struct viagem {
  struct trecho *trechos;
};

struct tabela_viagem {
  int tamanho;
  Viagem *tabela_hash;
};