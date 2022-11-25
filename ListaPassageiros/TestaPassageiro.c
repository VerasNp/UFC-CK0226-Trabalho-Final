#include "Passageiro.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/* Testes Passageiros. */
void testa_passageiro_cria_nulo(){ 
    Passageiro *p_novoPassageiro; 
    p_novoPassageiro = passageiro_cria(NULL,NULL);
    print_teste(p_novoPassageiro == NULL, "passageiro_cria() - teste 1: nome e endereço nulo");

    p_novoPassageiro = passageiro_cria(NULL,"Rua altaneira"); 
    print_teste(p_novoPassageiro == NULL, "passageiro_cria() - teste 2: nome nulo, endereço válido");
    
    p_novoPassageiro = passageiro_cria("Ângela", NULL); 
    print_teste(p_novoPassageiro == NULL, "passageiro_cria() - teste 3: nome válido, endereço nulo");
}

void testa_passageiro_cria_valido(){ 
    Passageiro *p_novoPassageiro; 
    p_novoPassageiro = passageiro_cria("Marcel Duchamp","Salvador"); 
    if (p_novoPassageiro != NULL){
        int id; 
        char *p_nome = (char *)malloc(sizeof(char)*100); 
        char *p_endereco = (char *)malloc(sizeof(char)*300); 
        passageiro_acessa(p_novoPassageiro,&id,p_nome,p_endereco);
        print_teste(strcmp(p_nome,"Marcel Duchamp") == 0 && strcmp(p_endereco,"Salvador") == 0, "passageiro_cria() - teste 1: passageiro válido");
    
        Passageiro *p_novoPassageiro2 = passageiro_cria("Alex","Aldeota");
        Passageiro *p_novoPassageiro3 = passageiro_cria("Fernando","Jardim Guanabara");
        Passageiro *p_novoPassageiro4 = passageiro_cria("Júlio","Belo Horizonte"); 
        Passageiro *p_novoPassageiro5 = passageiro_cria("Ricardo", "Manaus"); 
        int id2, id3, id4, id5; 
        passageiro_acessa(p_novoPassageiro2,&id2,p_nome,p_endereco);
        passageiro_acessa(p_novoPassageiro3,&id3,p_nome,p_endereco);
        passageiro_acessa(p_novoPassageiro4,&id4,p_nome,p_endereco);
        passageiro_acessa(p_novoPassageiro5,&id5,p_nome,p_endereco);

        int teste = !(id == id2 || id == id3 || id == id4 || id == id5 || id2 == id3 || id2 == id4 || id2 == id5 || id3 == id4 || id3 == id5 || id4 == id5);
        print_teste(teste, "passageiro_cria() - teste 2: ids diferentes");

        free(p_nome); 
        free(p_endereco); 
        free(p_novoPassageiro); 
        free(p_novoPassageiro2);
        free(p_novoPassageiro3);
        free(p_novoPassageiro4);
        free(p_novoPassageiro5);
        }
    else print_teste(0, "passageiro_cria() - passageiro passou como nulo.");
}

void testa_passageiro_cria() {
    printf("- Testando passageiro_cria()...\n");
    testa_passageiro_cria_nulo();
    testa_passageiro_cria_valido();
}

void testa_passageiro_acessa(){
    printf("- Testando passageiro_cria()...\n");

    int id; 
    char *p_nome = (char*)malloc(sizeof(char)*100); 
    char *p_endereco = (char *)malloc(sizeof(char)*300); 
    passageiro_acessa(NULL,&id,p_nome,p_endereco);
    print_teste(id == -1 && strcmp(p_nome,"NULL") == 0 && strcmp(p_endereco,"NULL") == 0, "passageiro_acessa() - teste 1: passageiro nulo");

    Passageiro *p_passageiro = passageiro_cria("João", "Meireles");
    passageiro_acessa(p_passageiro,&id,p_nome,p_endereco);
    print_teste(strcmp(p_nome, "João") == 0 && strcmp(p_endereco, "Meireles") == 0, "passageiro_cria() - teste 2: passageiro válido");
    
    passageiro_libera(p_passageiro);
}

void testa_passageiro_atribui(){ 
    printf("- Testando passageiro_atribui()...\n");
    Passageiro *p_passageiroNovo = passageiro_cria("Leandro","Belém"); 
    passageiro_atribui(p_passageiroNovo,NULL,NULL);
    int id;
    char *p_nome = (char *)malloc(sizeof(char)*100); 
    char *p_endereco = (char *)malloc(sizeof(char)*300); 
    passageiro_acessa(p_passageiroNovo,&id,p_nome,p_endereco);
    print_teste(strcmp(p_nome,"Leandro") == 0 && strcmp(p_endereco,"Belém") == 0, "passageiro_atribui() - teste 1: dados nulos");

    passageiro_atribui(p_passageiroNovo,"Lima","Fortaleza");
    passageiro_acessa(p_passageiroNovo,&id,p_nome,p_endereco);
    print_teste(strcmp(p_nome,"Lima") == 0  && strcmp(p_endereco,"Fortaleza") == 0, "passageiro_atribui() - teste 2: dados válidos");


    passageiro_libera(p_passageiroNovo);
}

void testa_passageiro_libera(){
    printf("- Testando passageiro_libera()...\n");
    print_teste(passageiro_libera(NULL) == 0, "passageiro_libera() - teste 1: passageiro nulo");

    Passageiro *p_passageiroNovo = passageiro_cria("Daniel","Miami");
    print_teste(passageiro_libera(p_passageiroNovo) == 1, "passageiro_libera() - teste 2: passageiro válido");

}

void testa_passageiros() { 
    testa_passageiro_cria();
    testa_passageiro_acessa();
    testa_passageiro_atribui();
    testa_passageiro_libera();
}


void main() {
    testa_passageiros();
}