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
    Lista *p_listaNova = (Lista *)malloc(sizeof(Lista)); 
    p_listaNova->primeiro = (No *)malloc(sizeof(No)); 
    p_listaNova->primeiro->passageiro = NULL; 
    p_listaNova->primeiro->proximo = NULL; 
    return p_listaNova; 
} 

/*Inclui novo passageiro na lista. Retorna 1 se foi possivel incluir e 0 se não foi possível*/
int incluir_lista(Lista *p_lista,Passageiro *p_novoPassageiro){ 
    if (p_lista != NULL && p_novoPassageiro != NULL){
        No *p_novoNo = (No *)malloc(sizeof(No));
        if (p_novoNo == NULL)
            return  0;  
        p_novoNo->passageiro = p_novoPassageiro; 
        p_novoNo->proximo = p_lista->primeiro->proximo; 
        p_lista->primeiro->proximo = p_novoNo;  
        return 1; 
    }
    return 0; 
}

/*Remove um passageiro da lista. Retorna o passageiro se foi possível remover e retorna NULL se não foi possível*/
Passageiro *remover_passageiro(Lista *p_lista,int id){ 
    if (p_lista != NULL){
        No *p_aux = p_lista->primeiro->proximo; 
        No *p_aux2 = p_lista->primeiro; 

        int idConsulta;
        char *p_nome = (char*)malloc(sizeof(char)*100);
        char *p_endereço = (char*)malloc(sizeof(char)*300);

        while(p_aux != NULL){ 
            passageiro_acessa(p_aux->passageiro,&idConsulta,p_nome,p_endereço); 
            if (idConsulta == id){ 
                Passageiro *passageiro = p_aux->passageiro; 
                p_aux2->proximo = p_aux->proximo; 
                return passageiro;    
            }
            p_aux2 = p_aux2->proximo; 
            p_aux = p_aux->proximo;
        }
    }
    return NULL; 

}

/*Dado um id, busca um passageiro com esse id*/
Passageiro *lista_busca(int id,Lista *p_lista){ 
    if (p_lista != NULL && p_lista->primeiro->proximo != NULL){
        No *p_aux = p_lista->primeiro->proximo;

        int idConsulta; 
        char *p_nome = (char*)malloc(sizeof(char)*100);  
        char *p_endereço = (char *)malloc(sizeof(char)*300);

        while(p_aux != NULL){ 
            passageiro_acessa(p_aux->passageiro, &idConsulta,p_nome,p_endereço);
            if(idConsulta == id)
                return p_aux->passageiro; 
            p_aux = p_aux->proximo;
        }
    }
    return NULL; 
}

/*Libera toda lista. Retorna 1 se foi possível liberar e 0 se não foi possível*/
int libera_lista(Lista *p_lista){ 
    if (p_lista != NULL){ 
        No *p_aux = p_lista->primeiro->proximo; 
        No *p_aux2 = p_lista->primeiro;  
        while(p_aux != NULL){ 
            libera_passageiro(p_aux2->passageiro);
            free(p_aux2);  
            p_aux2 = p_aux; 
            p_aux = p_aux->proximo; 
        }
        libera_passageiro(p_aux2->passageiro); 
        free(p_aux2); 
        free(p_lista); 
        p_lista = NULL; 
        return 1; 
    }
    return 0; 
}

/*Retorna o número de passageiros da lista. Se a lista for nula retorna -1*/
int lista_quantidade(Lista *p_lista){ 
    if (p_lista == NULL)
        return -1; 
    No *p_aux = p_lista->primeiro->proximo; 
    int cont = 0; 
    while(p_aux != NULL){ 
        cont++; 
        p_aux = p_aux->proximo; 
    }
    return cont; 
}
