#include "Passageiro.h"

typedef struct no_passageiro No; 

typedef struct lista_passageiro ListaPassageiro; 

/*Cria uma nova lista com nó cabeça*/
ListaPassageiro *cria_lista_passageiro(); 

/*Inclui novo passageiro na lista. Retorna 1 se foi possivel incluir e 0 se não foi possível*/
int incluir_passageiro(ListaPassageiro *p_lista,Passageiro *p_novoPassageiro); 

/*Remove um passageiro da lista. Retorna o passageiro se foi possível remover e retorna NULL se não foi possível*/
Passageiro *remover_passageiro(ListaPassageiro *p_lista,int id); 

/*Dado um id, busca um passageiro com esse id*/
Passageiro *lista_busca_passageiro(int id,ListaPassageiro *p_lista); 

/*Libera toda lista. Retorna 1 se foi possível liberar e 0 se não foi possível*/
int libera_lista_passageiro(ListaPassageiro *p_lista); 

/*Retorna o número de passageiros da lista. Se a lista for nula retorna -1*/
int lista_passageiro_quantidade(ListaPassageiro *p_lista);

