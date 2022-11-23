#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaVoos.h"

void testa_insere_voo_nulo(void){ 
    if (insere_voo(NULL,NULL) == 0)
        printf("testa_insere_voo_nulo: SUCESSO\n");
    else printf("testa_insere_voo_nulo: ERRO\n"); 

}
void testa_insere_voo_valido(void){ 
    Voo *p_voo = cria_voo("Fortaleza","Natal"); 
    ListaVoo *p_lista = cria_lista();
    if (insere_voo(p_voo,p_lista) == 1)
        printf("testa_insere_voo_valido: SUCESSO\n"); 
    else printf("testa_insere_voo_valido: ERRO\n");
    libera_lista(p_lista);
}
void testa_retira_voo_nulo(){ 
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
    if (retira_voo(NULL,1) == NULL && retira_voo(p_lista,codigo+1) == NULL){
        printf("teste_retira_voo_nulo: SUCESSO\n"); 
    }
    else printf("teste_retira_voo_nulo: ERRO\n");
    libera_lista(p_lista); 
    free(p_origem); free(p_destino); 
}
void testa_retira_voo_valido(void){ 
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
    if (retira_voo(p_lista,codigo3) == p_voo3 && retira_voo(p_lista,codigo) == p_voo && retira_voo(p_lista,codigo2) == p_voo2)
        printf("testa_retira_voo_valido: SUCESSO\n");
    else printf("testa_retira_voo_valido: ERRO\n");
    libera_lista(p_lista); 
    libera_voo(p_voo); libera_voo(p_voo2); libera_voo(p_voo3); 
    free(p_origem); free(p_destino);
}

void testa_busca_voo_nulo(void){ 
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
    if (busca_voo(NULL,10) == NULL && busca_voo(p_lista,codigo + 1) == NULL)
        printf("teste_busca_voo_nulo: SUCESSO\n"); 
    else printf("teste_busca_voo_nulo: ERRO\n");
    libera_lista(p_lista); 
    free(p_origem); free(p_destino); 
}
void testa_busca_voo_valido(void){ 
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
    if (busca_voo(p_lista,codigo3) == p_voo3 && busca_voo(p_lista,codigo) == p_voo && busca_voo(p_lista,codigo2) == p_voo2)
        printf("teste_busca_voo_valido: SUCESSO\n"); 
    else printf("teste_busca_valido: ERRO\n");
    libera_lista(p_lista); 
    free(p_origem); free(p_destino); 
}
void testa_tamanho_lista_nulo(void){ 
    if (tamanho_lista(NULL) == -1)
        printf("teste_tamanho_lista_nulo: SUCESSO\n"); 
    else printf("teste_tamanho_lista_nulo: ERRO\n");
}

void testa_tamanho_lista_valido(void){ 
    Voo *p_voo = cria_voo("Fortaleza","Natal");
    Voo *p_voo2 = cria_voo("A","B");
    Voo *p_voo3 = cria_voo("C","D");
    ListaVoo *p_lista = cria_lista(); 
    insere_voo(p_voo,p_lista); 
    insere_voo(p_voo2,p_lista); 
    insere_voo(p_voo3,p_lista);
    if (tamanho_lista(p_lista) == 3 && tamanho_lista(p_lista) == 3)
        printf("teste_tamanho_fila_valido: SUCESSO\n");
    else printf("tete_tamanho_fila_valido: ERRO\n");
    libera_lista(p_lista); 
}

void testa_unicidade_de_codigos(void) {
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

    for (int i=1; i <= 5; i++) {
        printf("%d\n", i);
        Voo *p_voo = retira_voo(p_lista, i);
        leitura_voo(p_voo, &codigo, NULL, NULL);
        if (codigo != i) boolReturn = 0;
    }
    if (boolReturn) printf("teste_unicidade_de_codigos: SUCESSO\n");
    else printf("teste_unicidade_de_codigos: ERRO\n");

}

int main(){ 
    testa_unicidade_de_codigos();
    testa_insere_voo_nulo(); 
    testa_insere_voo_valido(); 
    testa_retira_voo_nulo(); 
    testa_retira_voo_valido(); 
    testa_busca_voo_nulo(); 
    testa_busca_voo_valido();
    testa_tamanho_lista_nulo(); 
    testa_tamanho_lista_valido();
    return 0; 
}