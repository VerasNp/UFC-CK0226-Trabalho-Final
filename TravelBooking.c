#include <stdio.h>
#include <stdlib.h>
#include "Menus/PassageirosMenu.h"
#include "Menus/VoosMenu.h"
#include "ListaVoos/ListaVoos.h"
#include "../Utils/Headers.h"
#include "../ListaPassageiros/ListaPassageiros.h"
#include "../ReservaViagem/Agenda.h"

void limpar_tela();

int main(void) {
    char *opcao = (char *) malloc(sizeof(char));
    ListaPassageiro *p_listaPassageiros = cria_lista_passageiro();
    ListaVoo *p_listaVoo = cria_lista();

    do {
        limpar_tela();
        printf("\nMENU PRINCIPAL");
        printf("\n\t 1. Passageiros");
        printf("\n\t 2. Voos");
        printf("\n\t 3. Reservas");
        printf("\n\t 4. Roteiros de viagem");
        printf("\n\t");
        scanf(" %c%*c", opcao);

        switch (*opcao) {
            case '1':
                limpar_tela();
                passageiro_menu(p_listaPassageiros);
                break;
            case '2':
                limpar_tela();
                voos_menu(p_listaVoo);
                break;
            case '3':
                limpar_tela();
                printf("\n\t");
                printf("-----RESERVAS------");
                printf("\n\t 1. Criar");
                printf("\n\t 2. Listar");
                printf("\n\t 3. Editar");
                printf("\n\t 4. Filtrar por código do voo");
                printf("\n\t 5. Filtrar por data");
                printf("\n\t 6. Remover");
                printf("\n\t");
                scanf(" %c%*c", opcao);
                break;
            case '4':
                limpar_tela();
                printf("\n\t");
                printf("-----ROTEIROS DE VIAGENS------");
                printf("\n\t 1. Criar");
                printf("\n\t 2. Listar");
                printf("\n\t 3. Editar");
                printf("\n\t 4. Remover");
                printf("\n\t");
                scanf(" %c%*c", opcao);
                break;
        }
    } while (*opcao != 'X');

    exit(EXIT_SUCCESS);
}

void limpar_tela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif // _WIN32
}