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
      if ((codigoLeitura == codigo))
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

Voo *busca_voo(ListaVoo *p_lista, int codigo)
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

void print_fila(ListaVoo *p_lista)
{
  if (p_lista == NULL)
    return; 
  NoVoo *p_tmp = p_lista->primeiro;
  int codigoLeitura; 
  char *p_origem = (char *)malloc(sizeof(char)*300); 
  char *p_destino = (char *)malloc(sizeof(char)*300); 

  while (p_tmp != NULL)
  {
    leitura_voo(p_tmp->voo,&codigoLeitura,p_origem,p_destino);
    printf("%d-", codigoLeitura);
    p_tmp = p_tmp->proximo;
  }
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