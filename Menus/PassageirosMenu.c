#include "stdio.h"
#include "stdlib.h"

void PassageiroMenu() {
    char *opcao = (char *) malloc(sizeof(char));
    printf("\n\t");
    printf("-----PASSAGEIROS------");
    printf("\n\t 1. Criar");
    printf("\n\t 2. Listar");
    printf("\n\t 3. Editar");
    printf("\n\t 4. Buscar por nome");
    printf("\n\t 5. Remover");
    printf("\n\t");
    scanf(" %c%*c", opcao);

    switch (*opcao) {
        case '1':
            printf("Criar");
            break;
    }
}