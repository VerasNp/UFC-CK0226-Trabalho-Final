#include "ListaPassageiros.h" 
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

struct no_passageiro{ 
    Passageiro *passageiro; 
    No *proximo; 
}; 

struct lista_passageiro{ 
    No *primeiro; 
}; 

/*Cria uma nova lista com nó cabeça*/
ListaPassageiro *cria_lista_passageiro(){ 
    ListaPassageiro *p_listaNova = (ListaPassageiro *)malloc(sizeof(ListaPassageiro)); 
    p_listaNova->primeiro = (No *)malloc(sizeof(No)); 
    p_listaNova->primeiro->passageiro = NULL; 
    p_listaNova->primeiro->proximo = NULL; 
    return p_listaNova; 
} 

/*Inclui novo passageiro na lista. Retorna 1 se foi possivel incluir e 0 se não foi possível*/
int incluir_passageiro(ListaPassageiro *p_lista,Passageiro *p_novoPassageiro){ 
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
Passageiro *remover_passageiro(ListaPassageiro *p_lista,int id){ 
    if (p_lista != NULL){
        No *p_aux = p_lista->primeiro->proximo; 
        No *p_aux2 = p_lista->primeiro; 

        int idConsulta;
        char *p_nome = (char*)malloc(sizeof(char)*100);
        char *p_endereco = (char*)malloc(sizeof(char)*300);

        while(p_aux != NULL){ 
            passageiro_acessa(p_aux->passageiro,&idConsulta,p_nome,p_endereco); 
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
Passageiro *lista_busca_passageiro(int id,ListaPassageiro *p_lista){ 
    if (p_lista != NULL && p_lista->primeiro->proximo != NULL){
        No *p_aux = p_lista->primeiro->proximo;

        int idConsulta; 
        char *p_nome = (char*)malloc(sizeof(char)*100);  
        char *p_endereco = (char *)malloc(sizeof(char)*300);

        while(p_aux != NULL){ 
            passageiro_acessa(p_aux->passageiro, &idConsulta,p_nome,p_endereco);
            if(idConsulta == id)
                return p_aux->passageiro; 
            p_aux = p_aux->proximo;
        }
    }
    return NULL; 
}

/*Libera toda lista. Retorna 1 se foi possível liberar e 0 se não foi possível*/
int libera_lista_passageiro(ListaPassageiro *p_lista){ 
    if (p_lista != NULL){ 
        No *p_aux = p_lista->primeiro->proximo; 
        No *p_aux2 = p_lista->primeiro;  
        while(p_aux != NULL){ 
            passageiro_libera(p_aux2->passageiro);
            free(p_aux2);  
            p_aux2 = p_aux; 
            p_aux = p_aux->proximo; 
        }
        passageiro_libera(p_aux2->passageiro); 
        free(p_aux2); 
        free(p_lista); 
        p_lista = NULL; 
        return 1; 
    }
    return 0; 
}

/*Retorna o número de passageiros da lista. Se a lista for nula retorna -1*/
int lista_passageiro_quantidade(ListaPassageiro *p_lista){ 
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

/*Printa os atributos do passageiro*/
void print_passageiro(Passageiro *p_passageiro){ 
    if (p_passageiro != NULL){ 
        int id; 
        char *p_nome = (char *)malloc(sizeof(char)*100); 
        char *p_endereco = (char *)malloc(sizeof(char)*300);
        passageiro_acessa(p_passageiro,&id,p_nome,p_endereco);
        printf("Nome: %s \t Endereço: %s \t Id: %d\n",p_nome,p_endereco,id);
    }
}

/*printa as informações de cada passageiro em uma dada lista*/
void listar_passageiros(ListaPassageiro *p_lista){ 
    if (p_lista == NULL || p_lista->primeiro->proximo == NULL)
        printf("Lista vazia");
    else{
        No *p_aux = p_lista->primeiro->proximo; 
        printf("\tPassageiros:");
        while (p_aux != NULL){ 
            print_passageiro(p_aux->passageiro);
            p_aux = p_aux->proximo;
        }
    }
}

/*Dado um nome, busca o passageiro*/ 
Passageiro *busca_nome_passageiro(ListaPassageiro *p_lista,char *p_nome){ 
    if (p_lista == NULL || p_lista->primeiro->proximo == NULL){
        return NULL; 
    }
    int id; 
    char *p_nomeAcessa = (char *)malloc(sizeof(char)*100);
    char *p_enderecoAcessa = (char *)malloc(sizeof(char)*300); 
    No *p_aux = p_lista->primeiro->proximo; 
    while (p_aux != NULL){ 
        passageiro_acessa(p_aux->passageiro,&id,p_nomeAcessa,p_enderecoAcessa);
        if (strcmp(p_nomeAcessa,p_nome) == 0) return p_aux->passageiro; 
        p_aux = p_aux->proximo;  
    }
    return NULL;
}   