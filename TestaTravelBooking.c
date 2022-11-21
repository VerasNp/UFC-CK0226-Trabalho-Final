#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef enum cod_assento Assento;
typedef struct data Data;
typedef struct voo Voo;
typedef struct lista_voo ListaVoo;
typedef struct passageiro Passageiro;
typedef struct lista_passageiro ListaPassageiro;
typedef struct reserva Reserva;
typedef struct agenda Agenda;
typedef struct viagem Viagem;
typedef struct tabela_viagem TabelaViagem;

struct voo
{
  int codigo;
  char *origem;
  char *destino;
};

struct no_voo
{
  Voo *voo;
  struct no_voo *proximo;
};

struct lista_voo
{
  struct no_voo *primeiro;
};

int gerador_codigo();
Voo *cria_voo(int codigo, char *origem, char *destino);
Voo *edita_voo(Voo *voo, int novo_codigo, char *nova_origem, char *novo_destino);
struct no_voo *cria_no_voo();
ListaVoo *cria_lista();
int conferir_codigo(Voo *voo, ListaVoo *lista);
void insere_voo(Voo *voo, ListaVoo *lista);
void retira_voo(ListaVoo *lista, int codigo);
struct no_voo *busca_voo(ListaVoo *lista, int codigo);

int gerador_codigo()
{

  static int codigo = 0;
  codigo++;
  return codigo;
}

Voo *cria_voo(int codigo, char *origem, char *destino)
{
  Voo *novo_voo = (Voo *)malloc(sizeof(Voo));
  novo_voo->codigo = codigo;
  novo_voo->origem = origem;
  novo_voo->destino = destino;

  return novo_voo;
}

Voo *edita_voo(Voo *voo, int novo_codigo, char *nova_origem, char *novo_destino)
{
  if (voo == NULL)
    return NULL;

  voo->codigo = novo_codigo;
  voo->origem = nova_origem;
  voo->destino = novo_destino;
  return voo;
}

// caso voo seja NULL retorna NULL
void leitura_voo(Voo *voo, int codigo, char *origem, char *destino)
{
  if (voo == NULL)
    return;

  voo->codigo = codigo;
  voo->origem = origem;
  voo->destino = destino;
}

struct no_voo *cria_no_voo()
{
  struct no_voo *no = (struct no_voo *)malloc(sizeof(struct no_voo));
  no->proximo = NULL;
  no->voo = NULL;
  return no;
}

ListaVoo *cria_lista()
{
  ListaVoo *lista = (ListaVoo *)malloc(sizeof(ListaVoo));
  lista->primeiro = NULL;
}

// caso *lista e o voo sejam NULL retorna -1, caso contrario retorna 0
int conferir_codigo(Voo *voo, ListaVoo *lista)
{
  if (voo == NULL || lista == NULL)
    return -1;

  struct no_voo *no_tmp = lista->primeiro;
  while (no_tmp == NULL)
  {
    if (no_tmp->voo->codigo == voo->codigo)
      return 1;
    no_tmp = no_tmp->proximo;
  }
  return 0;
}

// caso *lista seja NULL ou voo seja NULL,retorna NULL.
void insere_voo(Voo *voo, ListaVoo *lista)
{
  if (voo == NULL || lista == NULL)
    return;

  if (lista->primeiro == NULL)
  {
    struct no_voo *no = cria_no_voo();
    no->voo = voo;
    lista->primeiro = no;
    return;
  }
  else if (conferir_codigo(voo, lista) != 0)
  {
    printf("Codigo fornecidado ja registrado!\n");
    return;
  }

  struct no_voo *no_tmp = lista->primeiro;

  do
  {
    if (no_tmp->proximo == NULL)
    {
      struct no_voo *no_novo = cria_no_voo();
      no_tmp->proximo = no_novo;
      no_novo->voo = voo;
      break; // mto importante
    }
    no_tmp = no_tmp->proximo;
  } while (no_tmp != NULL);
}

// caso *lista seja NULL ou o cogido ja pertence a lista retorna NULL
void retira_voo(ListaVoo *lista, int codigo)
{
  if (lista == NULL)
    return;
  if (lista->primeiro->voo->codigo == codigo)
  {
    lista->primeiro = lista->primeiro->proximo;
    return;
  }

  struct no_voo *no_tmp = lista->primeiro;

  while (no_tmp != NULL)
  {
    if ((no_tmp->proximo != NULL) && (no_tmp->proximo->voo->codigo == codigo))
    {
      no_tmp->proximo = no_tmp->proximo->proximo;
      break;
    }
    no_tmp = no_tmp->proximo;
  }
  return;
}

// caso *lista seja NULL ou o cogido não pertence a lista retorna NULL, caso contrário retorna o no
struct no_voo *busca_voo(ListaVoo *lista, int codigo)
{
  if (lista == NULL)
    return NULL;

  struct no_voo *no_tmp = lista->primeiro;
  while (no_tmp != NULL)
  {
    if (no_tmp->voo->codigo == codigo)
      return no_tmp;

    no_tmp = no_tmp->proximo;
  }
  return NULL;
}

void print_fila(ListaVoo *lista)
{

  struct no_voo *no_tmp = lista->primeiro;

  while (no_tmp != NULL)
  {
    printf("%d\t", no_tmp->voo->codigo);
    no_tmp = no_tmp->proximo;
  }
}

// caso *lista seja NULL retorna -1, caso contrário retorna o tamanho
int lista_tamanho(ListaVoo *lista)
{

  if (lista == NULL)
    return -1;

  struct no_voo *no_tmp = lista->primeiro;
  int tamanho = 0;

  while (no_tmp != NULL)
  {
    tamanho++;
    no_tmp = no_tmp->proximo;
  }
  return tamanho;
}

int main()
{
  Voo *voo1 = cria_voo(gerador_codigo(), "a", "b");
  Voo *voo2 = cria_voo(gerador_codigo(), "c", "d");
  Voo *voo3 = cria_voo(gerador_codigo(), "e", "f");
  Voo *voo4 = cria_voo(gerador_codigo(), "g", "h");
  Voo *voo5 = cria_voo(gerador_codigo(), "i", "j");

  ListaVoo *lista = cria_lista();

  insere_voo(voo1, lista);
  insere_voo(voo2, lista);
  insere_voo(voo3, lista);
  insere_voo(voo4, lista);
  insere_voo(voo5, lista);
  retira_voo(lista, voo5->codigo);
  print_fila(lista);
  printf("\n");
  printf("%d", busca_voo(lista, voo5->codigo));
  printf("\n");
  printf("%d", busca_voo(lista, voo3->codigo));
  printf("\n");
  printf("%d", lista_tamanho(lista));
  return 0;
}