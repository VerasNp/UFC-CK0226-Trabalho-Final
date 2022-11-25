#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Voos.h"
#include "ListaVoos.h"
#include "Utils.h"

/* Testes da ListaVoos. */
void testa_insere_voo_nulo(void) { 
    print_teste(insere_voo(NULL,NULL) == 0, "insere_voo() - teste 1: vôo nulo");

}
void testa_insere_voo_valido(void) { 
    Voo *p_voo = cria_voo("Fortaleza","Natal"); 
    ListaVoo *p_lista = cria_lista();
    print_teste(insere_voo(p_voo, p_lista), "insere_voo() - teste 2: vôo válido");
    libera_lista(p_lista);
}

void testa_insere_voo(void) {
    printf("Testando insere_voo()...\n");
    testa_insere_voo_nulo();
    testa_insere_voo_valido();
}
void testa_retira_voo_nulo() { 
    Voo *p_voo = cria_voo("Fortaleza","Natal");
    Voo *p_voo2 = cria_voo("A","B");
    Voo *p_voo3 = cria_voo("C","D");
    ListaVoo *p_lista = cria_lista(); 
    insere_voo(p_voo,p_lista); 
    insere_voo(p_voo2,p_lista); 
    insere_voo(p_voo3,p_lista); 
    int codigo; 
    char *p_origem = (char *)malloc(sizeof(char)*300); 
    char *p_destino = (char *)malloc(sizeof(char)*300); 
    leitura_voo(p_voo3,&codigo,p_origem,p_destino); 
    print_teste(retira_voo(NULL,1) == NULL && retira_voo(p_lista,codigo+1) == NULL, "retira_voo() - teste 1: vôo nulo");
    libera_lista(p_lista); 
    free(p_origem); free(p_destino); 
}
void testa_retira_voo_valido(void) { 
    Voo *p_voo = cria_voo("Fortaleza","Natal");
    Voo *p_voo2 = cria_voo("A","B");
    Voo *p_voo3 = cria_voo("C","D");
    ListaVoo *p_lista = cria_lista(); 
    insere_voo(p_voo,p_lista); 
    insere_voo(p_voo2,p_lista); 
    insere_voo(p_voo3,p_lista); 
    int codigo, codigo2, codigo3; 
    char *p_origem = (char *)malloc(sizeof(char)*300); 
    char *p_destino = (char *)malloc(sizeof(char)*300); 
    leitura_voo(p_voo3,&codigo3,p_origem,p_destino);
    leitura_voo(p_voo2,&codigo2,p_origem,p_destino); 
    leitura_voo(p_voo,&codigo,p_origem,p_destino);
    print_teste(retira_voo(p_lista,codigo3) == p_voo3 && retira_voo(p_lista,codigo) == p_voo && retira_voo(p_lista,codigo2) == p_voo2, "retira_voo() - teste 2: vôo válido");
    libera_lista(p_lista); 
    libera_voo(p_voo); libera_voo(p_voo2); libera_voo(p_voo3); 
    free(p_origem); free(p_destino);
}

void testa_retira_voo(void) {
    printf("Testando retira_voo()...\n");
    testa_retira_voo_nulo();
    testa_retira_voo_valido();
}

void testa_busca_voo_nulo(void) { 
    Voo *p_voo = cria_voo("Fortaleza","Natal");
    Voo *p_voo2 = cria_voo("A","B");
    Voo *p_voo3 = cria_voo("C","D");
    ListaVoo *p_lista = cria_lista(); 
    insere_voo(p_voo,p_lista); 
    insere_voo(p_voo2,p_lista); 
    insere_voo(p_voo3,p_lista); 
    int codigo, codigo2, codigo3; 
    char *p_origem = (char *)malloc(sizeof(char)*300); 
    char *p_destino = (char *)malloc(sizeof(char)*300); 
    leitura_voo(p_voo3,&codigo,p_origem,p_destino);
    print_teste(busca_voo(NULL,10) == NULL && busca_voo(p_lista,codigo + 1) == NULL, "busca_voo() - teste 1: vôo nulo");
    libera_lista(p_lista); 
    free(p_origem); free(p_destino); 
}
void testa_busca_voo_valido(void) { 
    Voo *p_voo = cria_voo("Fortaleza","Natal");
    Voo *p_voo2 = cria_voo("A","B");
    Voo *p_voo3 = cria_voo("C","D");
    ListaVoo *p_lista = cria_lista(); 
    insere_voo(p_voo,p_lista); 
    insere_voo(p_voo2,p_lista); 
    insere_voo(p_voo3,p_lista); 
    int codigo, codigo2, codigo3; 
    char *p_origem = (char *)malloc(sizeof(char)*300); 
    char *p_destino = (char *)malloc(sizeof(char)*300); 
    leitura_voo(p_voo3,&codigo3,p_origem,p_destino);
    leitura_voo(p_voo2,&codigo2,p_origem,p_destino); 
    leitura_voo(p_voo,&codigo,p_origem,p_destino);
    print_teste(busca_voo(p_lista,codigo3) == p_voo3 && busca_voo(p_lista,codigo) == p_voo && busca_voo(p_lista,codigo2) == p_voo2, "busca_voo() - teste 2: vôo válido");
    libera_lista(p_lista); 
    free(p_origem); free(p_destino); 
}

void testa_busca_voo(void) {
    printf("Testando busca_voo()...\n");
    testa_busca_voo_nulo();
    testa_busca_voo_valido();
}

void testa_tamanho_lista_nula(void) { 
    print_teste(tamanho_lista(NULL) == -1, "tamanho_lista() - teste 1: lista nula");
}

void testa_tamanho_lista_valida(void) { 
    Voo *p_voo = cria_voo("Fortaleza","Natal");
    Voo *p_voo2 = cria_voo("A","B");
    Voo *p_voo3 = cria_voo("C","D");
    ListaVoo *p_lista = cria_lista(); 
    insere_voo(p_voo,p_lista); 
    insere_voo(p_voo2,p_lista); 
    insere_voo(p_voo3,p_lista);
    print_teste(tamanho_lista(p_lista) == 3 && tamanho_lista(p_lista) == 3, "tamanho_lista() - teste 2: lista válida");
    libera_lista(p_lista); 
}

void testa_tamanho_lista(void) {
    printf("Testando tamanho_lista()...\n");
    testa_tamanho_lista_nula();
    testa_tamanho_lista_valida();
}

void testa_unicidade_de_codigos(void) {
    printf("Testando unicidade dos códigos de vôo...\n");
    ListaVoo *p_lista = cria_lista(); 

    Voo *p_voo1 = cria_voo("Fortaleza","Natal");
    Voo *p_voo2 = cria_voo("Fortaleza","Salvador");
    Voo *p_voo3 = cria_voo("Campos de Jordão","Campinas");
    Voo *p_voo4 = cria_voo("Manaus","Recife");
    Voo *p_voo5 = cria_voo("Recife","Porto Alegre");

    insere_voo(p_voo1, p_lista);
    insere_voo(p_voo2, p_lista);
    insere_voo(p_voo3, p_lista);
    insere_voo(p_voo4, p_lista);
    insere_voo(p_voo5, p_lista);

    int codigo;
    int boolReturn = 1;

    for (int i=17; i < 22; i++) {
        Voo *p_voo = retira_voo(p_lista, i);
        leitura_voo(p_voo, &codigo, NULL, NULL);
        if (codigo != i) boolReturn = 0;
    }
    print_teste(boolReturn, "lista mantendo códigos únicos");
}

void main() {
    testa_insere_voo();
    testa_retira_voo();
    testa_busca_voo();
    testa_tamanho_lista();
    testa_unicidade_de_codigos();
}