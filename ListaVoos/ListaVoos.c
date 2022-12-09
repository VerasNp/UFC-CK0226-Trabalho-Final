#include "ListaVoos.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct no_voo
{
  Voo *voo;
  struct no_voo *proximo;
};

struct lista_voo
{
  struct no_voo *primeiro;
};

NoVoo *cria_no_voo()
{
  NoVoo *p_no = (NoVoo *)malloc(sizeof(NoVoo));
  p_no->proximo = NULL;
  p_no->voo = NULL;
  return p_no;
}

ListaVoo *cria_lista()
{
  ListaVoo *lista = (ListaVoo *)malloc(sizeof(ListaVoo));
  lista->primeiro = NULL;
  return lista;
}

int insere_voo(Voo *p_voo, ListaVoo *p_lista)
{
  if (p_voo == NULL || p_lista == NULL)
    return 0;

  if (p_lista->primeiro == NULL)
  {
    NoVoo *p_no = cria_no_voo();
    p_no->voo = p_voo;
    p_lista->primeiro = p_no;
    return 1;
  }
  NoVoo *p_aux = p_lista->primeiro;

  do
  {
    if (p_aux->proximo == NULL)
    {
      NoVoo *p_no = cria_no_voo();
      p_aux->proximo = p_no;
      p_no->voo = p_voo;
      return 1; 
    }
    p_aux = p_aux->proximo;
  } while (p_aux != NULL);
}

int lista_voo_esta_vazia(ListaVoo *p_lista) {
    return p_lista->primeiro == NULL;
}

Voo *pop_lista_voo(ListaVoo *p_lista) {
    if (p_lista->primeiro == NULL) return NULL;
    NoVoo *p_resultado = p_lista->primeiro;
    p_lista->primeiro = p_resultado->proximo;
    return p_resultado->voo;
}

Voo *retira_voo(ListaVoo *p_lista, int codigo)
{
  if (p_lista == NULL)
    return NULL;

  int codigoLeitura; 
  char *p_origem = (char *)malloc(sizeof(char)*300); 
  char *p_destino = (char *)malloc(sizeof(char)*300);
  leitura_voo(p_lista->primeiro->voo,&codigoLeitura,p_origem,p_destino);

  if (codigoLeitura == codigo)
  {
    Voo *p_voo = p_lista->primeiro->voo;
    p_lista->primeiro = p_lista->primeiro->proximo;
    free(p_origem); free(p_destino);
    return p_voo;
  }

  NoVoo *p_aux = p_lista->primeiro;

  while (p_aux != NULL)
  { 
    if (p_aux->proximo != NULL){
      leitura_voo(p_aux->proximo->voo,&codigoLeitura,p_origem,p_destino);
      if (codigoLeitura == codigo)
      {
        Voo *p_tmp = p_aux->proximo->voo; 
        p_aux->proximo = p_aux->proximo->proximo;
        free(p_origem); free(p_destino);
        return p_tmp;
      }
    }
    p_aux = p_aux->proximo;
  }
  free(p_origem); free(p_destino);
  return NULL;
}

ListaVoo *busca_voo_destino(ListaVoo *p_lista, char *destino) {
    if (p_lista == NULL || destino == NULL)
        return NULL;

    // Retorna todos os Vôos com destino igual.
    ListaVoo *p_voosRetorno = cria_lista();

    NoVoo *p_tmp = p_lista->primeiro;
    int codigoLeitura;
    char *p_origem = (char *)malloc(sizeof(char)*300);
    char *p_destino = (char *)malloc(sizeof(char)*300);
    while (p_tmp != NULL)
    {
        leitura_voo(p_tmp->voo,&codigoLeitura,p_origem,p_destino);
        if (strcmp(destino, p_destino) == 0){
            insere_voo(p_tmp->voo, p_voosRetorno);
        }
        p_tmp = p_tmp->proximo;
    }
    free(p_origem); free(p_destino);
    return p_voosRetorno;
}

ListaVoo *busca_voo_origem_e_destino(ListaVoo *p_lista, char *origem, char *destino) {
    if (p_lista == NULL || origem == NULL || destino == NULL)
        return NULL;

    // Retorna todos os Vôos com destino igual.
    ListaVoo *p_voosRetorno = cria_lista();

    NoVoo *p_tmp = p_lista->primeiro;
    int codigoLeitura;
    char *p_origem = (char *)malloc(sizeof(char)*300);
    char *p_destino = (char *)malloc(sizeof(char)*300);
    while (p_tmp != NULL)
    {
        leitura_voo(p_tmp->voo,&codigoLeitura,p_origem,p_destino);
        if (strcmp(origem, p_origem) == 0 && strcmp(destino, p_destino) == 0){
            insere_voo(p_tmp->voo, p_voosRetorno);
        }
        p_tmp = p_tmp->proximo;
    }
    free(p_origem); free(p_destino);
    return p_voosRetorno;
}

ListaVoo *busca_voo_origem(ListaVoo *p_lista, char *origem) {
    if (p_lista == NULL || origem == NULL)
        return NULL;

    // Retorna todos os Vôos com destino igual.
    ListaVoo *p_voosRetorno = cria_lista();

    NoVoo *p_tmp = p_lista->primeiro;
    int codigoLeitura;
    char *p_origem = (char *)malloc(sizeof(char)*300);
    char *p_destino = (char *)malloc(sizeof(char)*300);
    while (p_tmp != NULL)
    {
        leitura_voo(p_tmp->voo,&codigoLeitura,p_origem,p_destino);
        if (strcmp(origem, p_origem) == 0){
            insere_voo(p_tmp->voo, p_voosRetorno);
        }
        p_tmp = p_tmp->proximo;
    }
    free(p_origem); free(p_destino);
    return p_voosRetorno;
}

Voo *busca_voo_codigo(ListaVoo *p_lista, int codigo)
{
  if (p_lista == NULL)
    return NULL;

  NoVoo *p_tmp = p_lista->primeiro;
  int codigoLeitura; 
  char *p_origem = (char *)malloc(sizeof(char)*300); 
  char *p_destino = (char *)malloc(sizeof(char)*300);
  while (p_tmp != NULL)
  { 
    leitura_voo(p_tmp->voo,&codigoLeitura,p_origem,p_destino);
    if (codigoLeitura == codigo){
      free(p_origem); free(p_destino);
      return p_tmp->voo;
    }
    p_tmp = p_tmp->proximo;
  }
  free(p_origem); free(p_destino);
  return NULL;
}

void inverte_lista_voo(ListaVoo *p_lista) {
    if (p_lista == NULL) return;
    NoVoo *p_noVoo = NULL;

    while(p_lista->primeiro != NULL) {
        NoVoo *p_noVooProximo = p_lista->primeiro->proximo;
        p_lista->primeiro->proximo = p_noVoo;
        p_noVoo = p_lista->primeiro;
        p_lista->primeiro = p_noVooProximo;
    }
    if (p_noVoo != NULL) {
        p_lista->primeiro = p_noVoo;
    }
}

ListaVoo *cria_roteiro_voo(ListaVoo *p_lista, char *origem, char *destino) {
    ListaVoo *p_resultado = busca_voo_origem_e_destino(p_lista, origem, destino);
    if (p_resultado->primeiro != NULL) return p_resultado;

    p_resultado = busca_voo_destino(p_lista, destino);
    if (p_resultado->primeiro == NULL) return NULL;

    int codigoLeitura;
    char *p_origem = (char *)malloc(sizeof(char)*300);
    char *p_destino = (char *)malloc(sizeof(char)*300);

    p_resultado = busca_voo_origem(p_lista, origem);
    while (p_resultado->primeiro != NULL) {
        leitura_voo(p_resultado->primeiro->voo, &codigoLeitura, p_origem, p_destino);

        ListaVoo *p_resultado2 = cria_roteiro_voo(p_lista, p_destino, destino);
        if (p_resultado2->primeiro != NULL) {
            insere_voo(p_resultado->primeiro->voo, p_resultado2);
            return p_resultado2;
        }
        p_resultado->primeiro = p_resultado->primeiro->proximo;
    }
    return NULL;
}

void print_lista_voo(ListaVoo *p_lista)
{
  if (p_lista == NULL) {
      printf("Não foi encontrado nenhum vôo.\n");
      return;
  }
  NoVoo *p_tmp = p_lista->primeiro;
  int codigoLeitura; 
  char *p_origem = (char *)malloc(sizeof(char)*300); 
  char *p_destino = (char *)malloc(sizeof(char)*300); 

  while (p_tmp != NULL)
  {
    leitura_voo(p_tmp->voo,&codigoLeitura,p_origem,p_destino);
    printf("Vôo id: %d - %s -> %s\n", codigoLeitura, p_origem, p_destino);
    p_tmp = p_tmp->proximo;
  }
  printf("\n");
  free(p_origem); free(p_destino);
}

int tamanho_lista(ListaVoo *p_lista)
{

  if (p_lista == NULL)
    return -1;

  NoVoo *p_tmp = p_lista->primeiro;
  int tamanho = 0;

  while (p_tmp != NULL)
  {
    tamanho++;
    p_tmp = p_tmp->proximo;
  }
  return tamanho;
}

int libera_lista(ListaVoo *p_lista){ 
  if (p_lista == NULL)
    return 0; 
  NoVoo *p_tmp = p_lista->primeiro; 
  NoVoo *p_aux = NULL;
  while(p_tmp != NULL){ 
    p_aux = p_tmp;
    p_tmp = p_tmp->proximo; 
    libera_voo(p_aux->voo);
    free(p_aux); 
    p_aux = NULL;
  }
  free(p_lista); 
  p_lista = NULL; 
  return 1; 
}