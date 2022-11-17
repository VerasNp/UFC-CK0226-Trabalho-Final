#include "ListaPassageiros.h" 
#include <stdio.h>
#include <stdlib.h> 

struct no_passageiro{ 
    Passageiro *passageiro; 
    No *proximo; 
}; 

struct lista_passageiro{ 
    No *primeiro; 
}; 

/*Cria uma nova lista com nó cabeça*/
Lista *cria_lista(){ 
    Lista *listaNova = (Lista *)malloc(sizeof(Lista)); 
    listaNova->primeiro = (No *)malloc(sizeof(No)); 
    listaNova->primeiro->passageiro = NULL; 
    listaNova->primeiro->proximo = NULL; 
    return listaNova; 
} 

/*Inclui novo passageiro na lista. Retorna 1 se foi possivel incluir e 0 se não foi possível*/
int incluir_lista(Lista *lista,Passageiro *novoPassageiro){ 
    if (lista != NULL && novoPassageiro != NULL){
        No *novoNo = (No *)malloc(sizeof(No));
        if (novoNo == NULL)
            return  0;  
        novoNo->passageiro = novoPassageiro; 
        novoNo->proximo = lista->primeiro->proximo; 
        lista->primeiro->proximo = novoNo;  
        return 1; 
    }
    return 0; 
}

/*Remove um passageiro da lista. Retorna o passageiro se foi possível remover e retorna NULL se não foi possível*/
Passageiro *remover_passageiro(Lista *lista,int id){ 
    No *aux = lista->primeiro->proximo; 
    No *aux2 = lista->primeiro; 

    int idConsulta;
    char *nome = (char*)malloc(sizeof(char)*100);
    char *endereço = (char*)malloc(sizeof(char)*300);

    while(aux != NULL){ 
        passageiro_acessa(aux->passageiro,&idConsulta,nome,endereço); 
        if (idConsulta == id){ 
            Passageiro *passageiro = aux->passageiro; 
            aux2->proximo = aux->proximo; 
            return passageiro;    
        }
        aux2 = aux2->proximo; 
        aux = aux->proximo;
    }
    return NULL; 

}

/*Dado um id, busca um passageiro com esse id*/
Passageiro *lista_busca(int id,Lista *lista){ 
    No *aux = lista->primeiro->proximo;

    int idConsulta; 
    char *nome = (char*)malloc(sizeof(char)*100);  
    char *endereço = (char *)malloc(sizeof(char)*300);

    while(aux != NULL){ 
        passageiro_acessa(aux->passageiro, &idConsulta,nome,endereço);
        if(idConsulta == id)
            return aux->passageiro; 
        aux = aux->proximo;
    }
    return NULL; 
}

/*Libera toda lista. Retorna 1 se foi possível liberar e 0 se não foi possível*/
int libera_lista(Lista *lista){ 
    if (lista != NULL){ 
        No *aux = lista->primeiro->proximo; 
        No *aux2 = lista->primeiro;  
        while(aux2 != NULL){ 
            libera_passageiro(aux2->passageiro);
            free(aux2);  
            aux2 = aux; 
            aux = aux->proximo; 
        }
        free(lista); 
        lista = NULL; 
        return 1; 
    }
    return 0; 
}

/*Retorna o número de passageiros da lista. Se a lista for nula retorna -1*/
int lista_quantidade(Lista *lista){ 
    if (lista == NULL)
        return -1; 
    No *aux = lista->primeiro->proximo; 
    int cont; 
    while(aux != NULL){ 
        cont++; 
        aux = aux->proximo; 
    }
    return cont; 
}
