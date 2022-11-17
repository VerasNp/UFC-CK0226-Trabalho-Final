#include "Passageiro.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

struct passageiro{ 
    int id;
    char *nome;
    char *endereco;
};

int verif_param(char *nome,char *endereço){ 
    if (nome == NULL || endereço == NULL ||strlen(nome)>100 || strlen(endereço)>300)  
        return 0;
    return 1; 
}

/*Cria novo passageiro. Retorna NULL se não foi possível criar*/
Passageiro *aloca_passageiro(char *nome,char *endereço){ 
    static int id; 
    if (verif_param(nome, endereço)){
        Passageiro *novo_pass = (Passageiro *)malloc(sizeof(Passageiro)); 
        if (novo_pass == NULL) 
            return NULL; 
        int novo_id = ++id;
        novo_pass->id = novo_id; 
        novo_pass->endereco = endereço; 
        novo_pass->nome = nome; 
        return novo_pass; 
    }
    return NULL; 
}

/*Acessa os atribudos do passageiro*/
void passageiro_acessa(Passageiro *passageiro,int *id, char *nome, char *endereço){ 
    if (passageiro != NULL && verif_param(nome,endereço)){ 
        *id = passageiro->id;
        strcpy(nome,passageiro->nome); 
        strcpy(endereço,passageiro->endereco); 
    }
    else{ 
        *id = -1;
        nome = NULL;  
        endereço = NULL; 
    }
}

/*Põe novos atributos no passageiro*/
void passageiro_atribui(Passageiro *passageiro, char *nome_novo, char *endereço_novo){ 
    if (passageiro != NULL && verif_param(nome_novo,endereço_novo)){ 
        strcpy(passageiro->nome, nome_novo); 
        strcpy(passageiro->endereco, endereço_novo);
    }
}

/*Libera o espaço de memória do passageiro. Retorna 1 se foi possível liberar, 0 se não foi possível*/
int libera_passageiro(Passageiro *passageiro){ 
    if (passageiro != NULL){ 
        free(passageiro->endereco); 
        free(passageiro->nome); 
        free(passageiro); 
        passageiro = NULL; 
        return 1; 
    }
    return 0; 
}

/*Retorna o tamanho do TAD Passageiro*/
int tamanho_passageiro(){ 
    return sizeof(Passageiro); 
}
