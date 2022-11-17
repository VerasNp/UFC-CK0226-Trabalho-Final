#include "Passageiro.h"

typedef struct no_passageiro No; 

typedef struct lista_passageiro Lista; 

/*Cria uma nova lista com nó cabeça*/
Lista *cria_lista(); 

/*Inclui novo passageiro na lista. Retorna 1 se foi possivel incluir e 0 se não foi possível*/
int incluir_lista(Lista *lista,Passageiro *novoPassageiro); 

/*Remove um passageiro da lista. Retorna o passageiro se foi possível remover e retorna NULL se não foi possível*/
Passageiro *remover_passageiro(Lista *lista,int id); 

/*Dado um id, busca um passageiro com esse id*/
Passageiro *lista_busca(int id,Lista *lista); 

/*Libera toda lista. Retorna 1 se foi possível liberar e 0 se não foi possível*/
int libera_lista(Lista *lista); 

/*Retorna o número de passageiros da lista. Se a lista for nula retorna -1*/
int lista_quantidade(Lista *lista);

