#include "Passageiro.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void aloca_passageiro_nulo(){ 
    Passageiro *p_novoPassageiro; 
    p_novoPassageiro = aloca_passageiro(NULL,NULL);
    if (p_novoPassageiro != NULL){
        printf("aloca_passageiro_nulo: ERRO\n"); 
        return;  
    } 
    p_novoPassageiro = aloca_passageiro(NULL,"Rua altaneira"); 
    if (p_novoPassageiro != NULL){ 
        printf("aloca_passageiro_nulo: ERRO\n"); 
        return;  
    }
    p_novoPassageiro = aloca_passageiro("Ângela", NULL); 
    if(p_novoPassageiro != NULL){ 
        printf("aloca_passageiro_nulo: ERRO\n"); 
        return;  
    }
    printf("aloca_passageiro_nulo: SUCESSO\n"); 
}

void aloca_passageiro_valido(){ 
    Passageiro *p_novoPassageiro; 
    p_novoPassageiro = aloca_passageiro("Marcel Duchamp","Salvador"); 
    if (p_novoPassageiro != NULL){
        int id; 
        char *p_nome = (char *)malloc(sizeof(char)*100); 
        char *p_endereco = (char *)malloc(sizeof(char)*300); 
        passageiro_acessa(p_novoPassageiro,&id,p_nome,p_endereco); 
        if(strcmp(p_nome,"Marcel Duchamp") != 0 && strcmp(p_endereco,"Salvador") != 0){ 
            printf("aloca_passageiro_valido: ERRO\n"); 
            return; 
        }
        Passageiro *p_novoPassageiro2 = aloca_passageiro("Alex","Aldeota");
        Passageiro *p_novoPassageiro3 = aloca_passageiro("Fernando","Jardim Guanabara");
        Passageiro *p_novoPassageiro4 = aloca_passageiro("Júlio","Belo Horizonte"); 
        Passageiro *p_novoPassageiro5 = aloca_passageiro("Ricardo", "Manaus"); 
        int id2, id3, id4, id5; 
        passageiro_acessa(p_novoPassageiro2,&id2,p_nome,p_endereco);
        passageiro_acessa(p_novoPassageiro3,&id3,p_nome,p_endereco);
        passageiro_acessa(p_novoPassageiro4,&id4,p_nome,p_endereco);
        passageiro_acessa(p_novoPassageiro5,&id5,p_nome,p_endereco);

        if(id == id2 || id == id3 || id == id4 || id == id5 || id2 == id3 || id2 == id4 || id2 == id5 || id3 == id4 || id3 == id5 || id4 == id5){ 
            printf("aloca_passageiro_valido: ERRO\n"); 
            free(p_nome); 
            free(p_endereco); 
            free(p_novoPassageiro); 
            free(p_novoPassageiro2);
            free(p_novoPassageiro3);
            free(p_novoPassageiro4);
            free(p_novoPassageiro5);
            return; 
        }
        printf("aloca_passageiro_valido: SUCESSO\n");
        free(p_nome); 
        free(p_endereco); 
        free(p_novoPassageiro); 
        free(p_novoPassageiro2);
        free(p_novoPassageiro3);
        free(p_novoPassageiro4);
        free(p_novoPassageiro5);
        }
    else printf("aloca_passageiro_valido: ERRO\n");
}

void passageiro_acessa_nulo(){ 
    int id; 
    char *p_nome = (char*)malloc(sizeof(char)*100); 
    char *p_endereco = (char *)malloc(sizeof(char)*300); 
    passageiro_acessa(NULL,&id,p_nome,p_endereco);
    if(id == -1 && strcmp(p_nome,"NULL") == 0 && strcmp(p_endereco,"NULL") == 0){ 
        printf("passageiro_acessa_nulo: SUCESSO\n");
    }
    else printf("passageiro_acessa_nulo: ERRO\n");
    free(p_nome); 
    free(p_endereco);  
}

void passageiro_atribui_nulo(){ 
    Passageiro *p_passageiroNovo = aloca_passageiro("Leandro","Belém"); 
    passageiro_atribui(p_passageiroNovo,NULL,NULL);
    int id;
    char *p_nome = (char *)malloc(sizeof(char)*100); 
    char *p_endereco = (char *)malloc(sizeof(char)*300); 
    passageiro_acessa(p_passageiroNovo,&id,p_nome,p_endereco);
    if (strcmp(p_nome,"Leandro") == 0 && strcmp(p_endereco,"Belém") == 0)
        printf("passageiro_atribui_nulo: SUCESSO\n");  
    else printf("passageiro_atribui_nulo: ERRO\n");  
    free(p_nome); 
    free(p_endereco); 
    free(p_passageiroNovo); 
}

void passageiro_atribui_valido(){ 
    Passageiro *p_passageiroNovo = aloca_passageiro("Leandro","Belém"); 
    passageiro_atribui(p_passageiroNovo,"Lima","Fortaleza"); 
    int id; 
    char *p_nome = (char *)malloc(sizeof(char)*100);
    char *p_endereco = (char *)malloc(sizeof(char)*300); 
    passageiro_acessa(p_passageiroNovo,&id,p_nome,p_endereco); 
    if (strcmp(p_nome,"Lima") == 0  && strcmp(p_endereco,"Fortaleza") == 0)
        printf("passageiro_atribui_valido: SUCESSO\n"); 
    else printf("passageiro_atribui_valido: ERRO\n"); 
    free(p_nome); 
    free(p_endereco); 
    free(p_passageiroNovo); 
}

void libera_passageiro_nulo(){  
    if (libera_passageiro(NULL) == 0){ 
        printf("libera_passageiro_nulo: SUCESSO\n");
    } 
    else printf("libera_passageiro_nulo: ERRO\n"); 
}

void libera_passageiro_valido(){ 
    Passageiro *p_passageiroNovo = aloca_passageiro("Daniel","Miami");
    if (libera_passageiro(p_passageiroNovo) == 1)
        printf("libera_passageiro_valido: SUCESSO\n");
    else printf("libera_passageiro_valido: ERRO\n");  
}

int main(){ 
    aloca_passageiro_nulo(); 
    aloca_passageiro_valido(); 
    passageiro_acessa_nulo(); 
    passageiro_atribui_nulo(); 
    passageiro_atribui_valido(); 
    libera_passageiro_nulo(); 
    libera_passageiro_valido(); 
    return 0; 
}