#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Voos.h"

void testa_cria_voo_nulo(void){ 
    if (cria_voo(NULL,NULL) == NULL){ 
        printf("testa_cria_voo_nulo: SUCESSO\n"); 
    }
    else{ 
        printf("testa_cria_voo_nulo: ERRO\n");
    }
}

void testa_cria_voo_valido(void){ 
    Voo *p_vooTeste = cria_voo("Fortaleza","Natal");
    if (p_vooTeste != NULL){
        int codigo; 
        char *p_origem = (char *)malloc(sizeof(char)*300); 
        char *p_destino = (char *)malloc(sizeof(char)*300); 
        leitura_voo(p_vooTeste,&codigo,p_origem,p_destino); 
        if (strcmp(p_origem,"Fortaleza") == 0 && strcmp(p_destino,"Natal") == 0){  
            printf("testa_cria_voo_valido: SUCESSO\n");
        }
        else{  
            printf("testa_cria_voo_valido: ERRO\n");
        }
        free(p_origem); free(p_destino);
    }
    else{ 
        printf("testa_cria_valido: ERRO\n"); 
    }
    libera_voo(p_vooTeste);
}

void testa_edita_voo_nulo(void){ 
    Voo *p_voo = cria_voo("Fortaleza","Natal");
    if (edita_voo(NULL,"São Paulo","Rio de Janeiro") == 0 && edita_voo(p_voo,NULL,NULL) == 0){ 
        printf("testa_edita_voo_nulo: SUCESSO\n"); 
    } 
    else{ 
        printf("testa_edita_voo_nulo: ERRO\n");
    }
    libera_voo(p_voo);
}

void testa_edita_voo_valido(void){ 
    Voo *p_voo = cria_voo("Fortaleza","Natal"); 
    if (edita_voo(p_voo,"São Paulo","Rio de Janeiro") == 1){ 
        int codigo; 
        char *p_origem = (char *)malloc(sizeof(char)*300); 
        char *p_destino = (char *)malloc(sizeof(char)*300); 
        leitura_voo(p_voo,&codigo,p_origem,p_destino);
        if (strcmp(p_origem,"São Paulo") == 0 && strcmp(p_destino,"Rio de Janeiro") == 0)
            printf("testa_edita_voo_valido: SUCESSO\n");
        else printf("testa_edita_voo_valido: ERRO\n");
        free(p_origem); free(p_destino); 
    }
    else{ 
        printf("testa_edita_voo_valido: ERRO\n");
    }
    libera_voo(p_voo);
}

int main(){
    testa_cria_voo_nulo();
    testa_cria_voo_valido(); 
    testa_edita_voo_nulo(); 
    testa_edita_voo_valido(); 
    return 0;
}