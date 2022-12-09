#include "Passageiro.h"
#include "ListaPassageiros.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/* Testes ListaPassageiros. */
void testa_cria_lista_valida(){ 
    printf("- Testando cria_lista_passageiro()...\n");
    ListaPassageiro *p_listaNova = cria_lista_passageiro();
    print_teste(p_listaNova != NULL, "cria_lista_passageiro() - teste 1: lista válida");
    free(p_listaNova);
}

void testa_incluir_passageiro_nulo(){  
    print_teste(incluir_passageiro(NULL,NULL) == 0, "incluir_passageiro() - teste 1: lista nula");
}

void testa_incluir_passageiro_valido(){ 
    ListaPassageiro *p_listaNova = cria_lista_passageiro(); 
    Passageiro *p_passageiroNovo = passageiro_cria("Kal-El","Fortaleza da solidão"); 
    print_teste(incluir_passageiro(p_listaNova, p_passageiroNovo), "incluir_passageiro() - teste 2: lista válida");
    free(p_listaNova); 
    free(p_passageiroNovo); 
}

void testa_incluir_lista() {
    printf("- Testando incluir_passageiro()...\n");
    testa_incluir_passageiro_nulo();
    testa_incluir_passageiro_valido();
}

void testa_remover_passageiro_nulo(){ 
    print_teste(remover_passageiro(NULL, 10) == NULL, "remover_passageiro() - teste 1: passageiro nulo");
}

void testa_remover_passageiro_valido(){
    ListaPassageiro *p_listaNova = cria_lista_passageiro(); 
    Passageiro *p_passageiroNovo = passageiro_cria("Alan","Alemanha"); 
    Passageiro *p_passageiroNovo2 = passageiro_cria("Borges","Rio"); 
    Passageiro *p_passageiroNovo3 = passageiro_cria("Caio","Alagoas"); 
    int id, id2, id3; 
    char *nome = (char *)malloc(sizeof(char)*100); 
    char *endereco = (char *)malloc(sizeof(char)*300); 
    passageiro_acessa(p_passageiroNovo,&id,nome,endereco); 
    passageiro_acessa(p_passageiroNovo2,&id2,nome,endereco); 
    passageiro_acessa(p_passageiroNovo3,&id3,nome,endereco); 
    if (incluir_passageiro(p_listaNova,p_passageiroNovo) && incluir_passageiro(p_listaNova,p_passageiroNovo2) && incluir_passageiro(p_listaNova,p_passageiroNovo3)){
        int teste = p_passageiroNovo == remover_passageiro(p_listaNova,id) && p_passageiroNovo2 == remover_passageiro(p_listaNova,id2) && p_passageiroNovo3 == remover_passageiro(p_listaNova,id3);
        print_teste(teste, "remover_passageiro() - teste 2: passageiro válido");   
    } else print_teste(0, "remover_passageiro() - teste 2: passageiro válido");   
    libera_lista_passageiro(p_listaNova);
}

void testa_remover_passageiro() {
    printf("- Testando remover_passageiro()...\n");
    testa_remover_passageiro_nulo();
    testa_remover_passageiro_valido();
}

void testa_lista_busca_passageiro_valido(){ 
    ListaPassageiro *p_listaNova = cria_lista_passageiro();
    Passageiro *p_passageiroNovo = passageiro_cria("Alan","Alemanha"); 
    Passageiro *p_passageiroNovo2 = passageiro_cria("Borges","Rio"); 
    Passageiro *p_passageiroNovo3 = passageiro_cria("Caio","Alagoas");
    incluir_passageiro(p_listaNova,p_passageiroNovo); 
    incluir_passageiro(p_listaNova,p_passageiroNovo2); 
    incluir_passageiro(p_listaNova,p_passageiroNovo3);
    int id, id2, id3; 
    char *nome = (char *)malloc(sizeof(char)*100); 
    char *endereco = (char *)malloc(sizeof(char)*300); 
    passageiro_acessa(p_passageiroNovo,&id,nome,endereco); 
    passageiro_acessa(p_passageiroNovo2,&id2,nome,endereco); 
    passageiro_acessa(p_passageiroNovo3,&id3,nome,endereco); 
    int teste = p_passageiroNovo == lista_busca_passageiro(id,p_listaNova) && p_passageiroNovo3 == lista_busca_passageiro(id3,p_listaNova) && p_passageiroNovo2 == lista_busca_passageiro(id2,p_listaNova);
    print_teste(teste, "lista_busca_passageiro() - teste 2: passageiro válido");
    libera_lista_passageiro(p_listaNova);
}

void testa_lista_busca_passageiro_nulo(){ 
    print_teste(lista_busca_passageiro(4,NULL) == NULL, "lista_busca_passageiro - teste 1: passageiro nulo");
}

void testa_lista_busca_passageiro() {
    printf("- Testando lista_busca_passageiro()...\n");
    testa_lista_busca_passageiro_nulo();
    testa_lista_busca_passageiro_valido();
}

void testa_libera_lista_passageiro_nulo(){ 
    print_teste(libera_lista_passageiro(NULL) == 0, "libera_lista_passageiro() - teste 1: lista nula");
}

void testa_libera_lista_passageiros_validos(){ 
    ListaPassageiro *p_listaNova = cria_lista_passageiro(); 
    Passageiro *p_passageiroNovo = passageiro_cria("Alan","Alemanha"); 
    Passageiro *p_passageiroNovo2 = passageiro_cria("Borges","Rio"); 
    Passageiro *p_passageiroNovo3 = passageiro_cria("Caio","Alagoas");
    if (incluir_passageiro(p_listaNova,p_passageiroNovo) && incluir_passageiro(p_listaNova,p_passageiroNovo2) && incluir_passageiro(p_listaNova,p_passageiroNovo3)){
        print_teste(libera_lista_passageiro(p_listaNova), "libera_lista_passageiro() - teste 2: passageiros válidos");
    }   
    else print_teste(0, "libera_lista_passageiro() - teste 2: passageiros válidos");
}

void testa_libera_lista_passageiro() {
    printf("- Testando libera_lista_passageiro()...\n");
    testa_libera_lista_passageiro_nulo();
    testa_libera_lista_passageiros_validos();
}

void testa_lista_passageiro_quantidade_nulo(){
    print_teste(lista_passageiro_quantidade(NULL) == -1, "lista_passageiro_quantidade() - teste 1: lista nula");
}

void testa_lista_passageiro_quantidade_valido(){ 
    ListaPassageiro *p_listaNova = cria_lista_passageiro(); 
    print_teste(lista_passageiro_quantidade(p_listaNova) == 0, "lista_passageiro_quantidade() - teste 1: lista vazia");
    
    Passageiro *p_passageiroNovo1 = passageiro_cria("Alan","Alemanha");
    incluir_passageiro(p_listaNova, p_passageiroNovo1);
    print_teste(lista_passageiro_quantidade(p_listaNova) == 1, "lista_passageiro_quantidade() - teste 2: 1 passageiro");

    Passageiro *p_passageiroNovo2 = passageiro_cria("Borges","Rio"); 
    incluir_passageiro(p_listaNova, p_passageiroNovo2);
    print_teste(lista_passageiro_quantidade(p_listaNova) == 2, "lista_passageiro_quantidade() - teste 3: 2 passageiros");

    Passageiro *p_passageiroNovo3 = passageiro_cria("Caio","Alagoas");
    incluir_passageiro(p_listaNova, p_passageiroNovo3);
    print_teste(lista_passageiro_quantidade(p_listaNova) == 3, "lista_passageiro_quantidade() - teste 4: 3 passageiros");
    libera_lista_passageiro(p_listaNova);
}

void testa_lista_passageiro_quantidade() {
    printf("- Testando lista_passageiro_quantidade()...\n");
    testa_lista_passageiro_quantidade_nulo();
    testa_lista_passageiro_quantidade_valido();
}

void testa_lista(){ 
    testa_cria_lista_valida(); 
    testa_incluir_lista();
    testa_remover_passageiro();
    testa_lista_busca_passageiro();
    testa_libera_lista_passageiro();
    testa_lista_passageiro_quantidade();
}

void main() {
    testa_lista();
}