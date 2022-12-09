#include "Voos.h"
#include "Utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testa_cria_voo_nulo(void) { 
    print_teste(cria_voo(NULL, NULL) == NULL, "cria_voo() - teste 1: voo nulo");
}

void testa_cria_voo_valido(void) { 
    Voo *p_vooTeste = cria_voo("Fortaleza","Natal");
    if (p_vooTeste != NULL) {
        int codigo; 
        char *p_origem = (char *)malloc(sizeof(char)*300); 
        char *p_destino = (char *)malloc(sizeof(char)*300); 
        leitura_voo(p_vooTeste,&codigo,p_origem,p_destino); 
        print_teste(strcmp(p_origem,"Fortaleza") == 0 && strcmp(p_destino,"Natal") == 0, "cria_voo() - teste 2: voo valido");
        free(p_origem); free(p_destino);
    }
    else { 
        print_teste(0, "cria_voo() - teste 2: voo valido");
    }
    libera_voo(p_vooTeste);
}

void testa_cria_voo(void)  {
    printf("Testando cria_voo()...\n");
    testa_cria_voo_nulo();
    testa_cria_voo_valido();
}

void testa_edita_voo_nulo(void) { 
    Voo *p_voo = cria_voo("Fortaleza","Natal");
    print_teste(edita_voo(NULL,"São Paulo","Rio de Janeiro") == 0 && edita_voo(p_voo,NULL,NULL) == 0, "edita_voo() - teste 1: vôo nulo");
    libera_voo(p_voo);
}

void testa_edita_voo_valido(void) { 
    Voo *p_voo = cria_voo("Fortaleza","Natal"); 
    if (edita_voo(p_voo,"São Paulo","Rio de Janeiro") == 1) { 
        int codigo; 
        char *p_origem = (char *)malloc(sizeof(char)*300); 
        char *p_destino = (char *)malloc(sizeof(char)*300); 
        leitura_voo(p_voo,&codigo,p_origem,p_destino);
        print_teste(strcmp(p_origem,"São Paulo") == 0 && strcmp(p_destino,"Rio de Janeiro") == 0, "edita_voo() - teste 2: vôo válido");
        free(p_origem); free(p_destino); 
    }
    else { 
        print_teste(0, "edita_voo() - teste 2: vôo válido");
    }
    libera_voo(p_voo);
}

void testa_edita_voo(void) {
    printf("Testando edita_voo()...\n");
    testa_edita_voo_nulo();
    testa_edita_voo_valido();
}



void main() {
    testa_cria_voo();
    testa_edita_voo(); 
}