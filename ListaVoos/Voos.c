#include "Voos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*TAD voos*/
struct voo { 
    int codigo; 
    char *origem; 
    char *destino; 
};

Voo *cria_voo(char *p_origem, char *p_destino)
{
  if (p_origem == NULL || p_destino == NULL|| strlen(p_origem) > 300 || strlen(p_destino) > 300)
    return NULL;
  static int codigo; 
  Voo *p_novoVoo = (Voo *)malloc(sizeof(Voo));
  p_novoVoo->codigo = ++codigo;
  p_novoVoo->origem = (char *)malloc(sizeof(char)*300); 
  p_novoVoo->destino = (char*)malloc(sizeof(char)*300); 
  strcpy(p_novoVoo->origem,p_origem); 
  strcpy(p_novoVoo->destino,p_destino); 
  return p_novoVoo;
}

int edita_voo(Voo *p_voo,char *p_novaOrigem, char *p_novoDestino)
{
  if (p_voo == NULL || p_novaOrigem == NULL || p_novoDestino == NULL|| strlen(p_novaOrigem) > 300 || strlen(p_novoDestino) > 300)
    return 0;

  strcpy(p_voo->origem,p_novaOrigem);
  strcpy(p_voo->destino,p_novoDestino);
  return 1;
}

void leitura_voo(Voo *p_voo, int *p_codigo, char *p_origem, char *p_destino)
{
  if (p_voo == NULL)
    return;

  *p_codigo = p_voo->codigo;
  strcpy(p_origem,p_voo->origem);
  strcpy(p_destino,p_voo->destino);
}

void libera_voo(Voo *p_voo){ 
    if (p_voo == NULL)
        return; 
    free(p_voo->origem); 
    free(p_voo->destino); 
    free(p_voo); 
    p_voo = NULL; 
}