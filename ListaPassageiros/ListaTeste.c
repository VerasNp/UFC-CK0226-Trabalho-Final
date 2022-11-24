#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaPassageiros.h" 

void cria_lista_valido(){ 
    Lista *p_listaNova =  cria_lista();
    if (p_listaNova != NULL)
        printf("cria_lista_valido: SUCESSO\n"); 
    else printf("cria_lista_valido: ERRO\n"); 
    free(p_listaNova);
}
void incluir_lista_nulo(){  
    if(incluir_lista(NULL,NULL) == 0)
        printf("incluir_lista_nulo: SUCESSO\n"); 
    else printf("incluir_lista_nulo: ERRO\n");
}

void incluir_lista_valido(){ 
    Lista *p_listaNova = cria_lista(); 
    Passageiro *p_passageiroNovo = aloca_passageiro("Kal-El","Fortaleza da solidão"); 
    if(incluir_lista(p_listaNova,p_passageiroNovo))
        printf("incluir_lista_valido: SUCESSO\n"); 
    else printf("incluir_lista_valido: ERRO\n");
    free(p_listaNova); 
    free(p_passageiroNovo); 
}

void remover_passageiro_nulo(){ 
    if(remover_passageiro(NULL,10) == NULL)
        printf("remover_passageiro_nulo: SUCESSO\n"); 
    else printf("remover_passageiro_nulo: ERRO\n");
}

void remover_passageiro_valido(){
    Lista *p_listaNova = cria_lista(); 
    Passageiro *p_passageiroNovo = aloca_passageiro("Alan","Alemanha"); 
    Passageiro *p_passageiroNovo2 = aloca_passageiro("Borges","Rio"); 
    Passageiro *p_passageiroNovo3 = aloca_passageiro("Caio","Alagoas"); 
    int id, id2, id3; 
    char *nome = (char *)malloc(sizeof(char)*100); 
    char *endereco = (char *)malloc(sizeof(char)*300); 
    passageiro_acessa(p_passageiroNovo,&id,nome,endereco); 
    passageiro_acessa(p_passageiroNovo2,&id2,nome,endereco); 
    passageiro_acessa(p_passageiroNovo3,&id3,nome,endereco); 
    if (incluir_lista(p_listaNova,p_passageiroNovo) && incluir_lista(p_listaNova,p_passageiroNovo2) && incluir_lista(p_listaNova,p_passageiroNovo3)){
        if (p_passageiroNovo == remover_passageiro(p_listaNova,id) && p_passageiroNovo2 == remover_passageiro(p_listaNova,id2) && p_passageiroNovo3 == remover_passageiro(p_listaNova,id3))
            printf("remover_passageiro_valido: SUCESSO\n");
        else printf("remover_passageiro_valido: ERRO\n");    
    } 
    else printf("remover_passageiro_valido: ERRO\n"); 
    libera_lista(p_listaNova);
}

void lista_busca_valido(){ 
    Lista *p_listaNova = cria_lista();
    Passageiro *p_passageiroNovo = aloca_passageiro("Alan","Alemanha"); 
    Passageiro *p_passageiroNovo2 = aloca_passageiro("Borges","Rio"); 
    Passageiro *p_passageiroNovo3 = aloca_passageiro("Caio","Alagoas");
    incluir_lista(p_listaNova,p_passageiroNovo); 
    incluir_lista(p_listaNova,p_passageiroNovo2); 
    incluir_lista(p_listaNova,p_passageiroNovo3);
    int id, id2, id3; 
    char *nome = (char *)malloc(sizeof(char)*100); 
    char *endereco = (char *)malloc(sizeof(char)*300); 
    passageiro_acessa(p_passageiroNovo,&id,nome,endereco); 
    passageiro_acessa(p_passageiroNovo2,&id2,nome,endereco); 
    passageiro_acessa(p_passageiroNovo3,&id3,nome,endereco); 
    if (p_passageiroNovo == lista_busca(id,p_listaNova) && p_passageiroNovo3 == lista_busca(id3,p_listaNova) && p_passageiroNovo2 == lista_busca(id2,p_listaNova))
        printf("lista_busca_valido: SUCESSO\n");
    else printf("lista_busca_nulo: ERRO\n"); 
    libera_lista(p_listaNova);
}

void lista_busca_nulo(){ 
    if (lista_busca(4,NULL) == NULL) 
        printf("lista_busca_nulo: SUCESSO\n");
    else printf("lista_busca_nulo: ERRO\n"); 
}

void libera_lista_valido(){ 
    Lista *p_listaNova = cria_lista(); 
    Passageiro *p_passageiroNovo = aloca_passageiro("Alan","Alemanha"); 
    Passageiro *p_passageiroNovo2 = aloca_passageiro("Borges","Rio"); 
    Passageiro *p_passageiroNovo3 = aloca_passageiro("Caio","Alagoas");
    if (incluir_lista(p_listaNova,p_passageiroNovo) && incluir_lista(p_listaNova,p_passageiroNovo2) && incluir_lista(p_listaNova,p_passageiroNovo3)){
        if(libera_lista(p_listaNova)) printf("libera_lista_valido: SUCESSO\n"); 
        else printf("libera_lista_valido: ERRO\n");
    }   
    else printf("libera_lista_valido: ERRO\n"); 
}

void libera_lista_nulo(){ 
    if(libera_lista(NULL) == 0) printf("libera_lista_nulo: SUCESSO\n");
    else printf("lista_libera_nulo: ERRO\n");
}

void lista_quantidade_nulo(){ 
    if (lista_quantidade(NULL) == -1) printf("lista_quantidade_nulo: SUCESSO\n"); 
    else printf("lista_quantidade_nulo: ERRO\n"); 
}

void lista_quantidade_valido(){ 
    Lista *p_listaNova = cria_lista(); 
    Passageiro *p_passageiroNovo = aloca_passageiro("Alan","Alemanha"); 
    Passageiro *p_passageiroNovo2 = aloca_passageiro("Borges","Rio"); 
    Passageiro *p_passageiroNovo3 = aloca_passageiro("Caio","Alagoas");
    if (incluir_lista(p_listaNova,p_passageiroNovo) && incluir_lista(p_listaNova,p_passageiroNovo2) && incluir_lista(p_listaNova,p_passageiroNovo3)){
        if(lista_quantidade(p_listaNova) == 3 && lista_quantidade(p_listaNova) == 3 ) printf("lista_quantidade_valido: SUCESSO\n"); 
        else printf("lista_quantidae_valido: ERRO\n");
    }   
    else printf("lista_quantidade_valido: ERRO\n"); 
    libera_lista(p_listaNova);
}

void testa_lista(){ 
    cria_lista_valido(); 
    incluir_lista_nulo(); 
    incluir_lista_valido(); 
    remover_passageiro_nulo(); 
    remover_passageiro_valido(); 
    lista_busca_valido(); 
    lista_busca_nulo();
    libera_lista_valido(); 
    libera_lista_nulo(); 
    lista_quantidade_nulo(); 
    lista_quantidade_valido();  
}