#include "Passageiro.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

struct passageiro{ 
    int id;
    char *nome;
    char *endereco;
};

int verif_param(char *p_nome,char *p_endereço){ 
    if (p_nome == NULL || p_endereço == NULL ||strlen(p_nome)>100 || strlen(p_endereço)>300)  
        return 0;
    return 1; 
}

/*Cria novo passageiro. Retorna NULL se não foi possível criar*/
Passageiro *aloca_passageiro(char *p_nome,char *p_endereco){ 
    static int id; 
    if (verif_param(p_nome, p_endereco)){
        Passageiro *p_novoPass = (Passageiro *)malloc(sizeof(Passageiro)); 
        if (p_novoPass == NULL) 
            return NULL; 
        int novoId = ++id;
        p_novoPass->id = novoId; 
        p_novoPass->endereco = p_endereco; 
        p_novoPass->nome = p_nome; 
        return p_novoPass; 
    }
    return NULL; 
}

/*Acessa os atribudos do passageiro*/
void passageiro_acessa(Passageiro *p_passageiro,int *p_id, char *p_nome, char *p_endereco){ 
    if (p_passageiro != NULL && verif_param(p_nome,p_endereco)){ 
        *p_id = p_passageiro->id;
        strcpy(p_nome,p_passageiro->nome); 
        strcpy(p_endereco,p_passageiro->endereco); 
    }
    else{ 
        *p_id = -1;
        p_nome = NULL;  
        p_endereco = NULL; 
    }
}

/*Põe novos atributos no passageiro*/
void passageiro_atribui(Passageiro *p_passageiro, char *p_nomeNovo, char *p_enderecoNovo){ 
    if (p_passageiro != NULL && verif_param(p_nomeNovo,p_enderecoNovo)){ 
        strcpy(p_passageiro->nome, p_nomeNovo); 
        strcpy(p_passageiro->endereco, p_enderecoNovo);
    }
}

/*Libera o espaço de memória do passageiro. Retorna 1 se foi possível liberar, 0 se não foi possível*/
int libera_passageiro(Passageiro *p_passageiro){ 
    if (p_passageiro != NULL){ 
        free(p_passageiro->endereco); 
        free(p_passageiro->nome); 
        free(p_passageiro); 
        p_passageiro = NULL; 
        return 1; 
    }
    return 0; 
}

/*Retorna o tamanho do TAD Passageiro*/
int tamanho_passageiro(){ 
    return sizeof(Passageiro); 
}
