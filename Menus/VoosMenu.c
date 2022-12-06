#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaVoos/Voos.h"
#include "ListaVoos/ListaVoos.h"

void print_erro(int r, char *mensagem) {
    if (r) {
        printf("ERRO: %s", mensagem);
    } else {
        printf("ERRO: Algo ocorreu como inesperado, tente novamente.\n");
    }
}

int registrar_voo(ListaVoo *p_listaVoo) {
    char *p_origem = malloc(sizeof(char)*300);
    char *p_destino = malloc(sizeof(char)*300);
    if (p_destino == NULL || p_origem == NULL) return 0;

    do {
        printf("Origem do vôo: ");
        scanf("%s", p_origem);
        printf("\n");
    } while (strlen(p_origem) > 300);

    do {
        printf("Destino do vôo: ");
        scanf("%s", p_destino);
        printf("\n");
    } while (strlen(p_destino) > 300);

    Voo *p_voo = cria_voo(p_origem, p_destino);

    if (p_voo == NULL) return 0;
    if (!insere_voo(p_voo, p_listaVoo)) return 0;

    return 1;
}

void listar_voos(ListaVoo *p_listaVoo) {
    print_fila(p_listaVoo);
}

int excluir_voo(ListaVoo *p_listaVoo) {
    int codigoVoo;

    printf("Código do vôo a remover: ");
    scanf("%d", &codigoVoo);

    if (retira_voo(p_listaVoo, codigoVoo) == NULL) return 0;
    return 1;
}

int editar_voo(ListaVoo *p_listaVoo) {
    int codigoVoo;

    printf("Código do vôo a editar: ");
    scanf("%d", &codigoVoo);

    Voo *p_voo = busca_voo(p_listaVoo, codigoVoo);

    char *p_origem = malloc(sizeof(char)*300);
    char *p_destino = malloc(sizeof(char)*300);
    if (p_destino == NULL || p_origem == NULL) return 0;

    do {
        printf("Nova origem do vôo: ");
        scanf("%s", p_origem);
        printf("\n");
    } while (strlen(p_origem) > 300);

    do {
        printf("Novo destino do vôo: ");
        scanf("%s", p_destino);
        printf("\n");
    } while (strlen(p_destino) > 300);

    return edita_voo(p_voo, p_origem, p_destino);
}

void voos_menu(ListaVoo *p_listaVoo) {
    char *p_opcao = malloc(sizeof(char) *100);
    if (p_opcao == NULL) {
        print_erro(0, "");
        return;
    }

    while (1) {
        printf("------ Menu de Vôos ------\n");
        printf("1 - Registrar Vôo.\n");
        printf("2 - Listar Vôos.\n");
        printf("3 - Remover Vôo.\n");
        printf("4 - Alterar Vôo.\n");
        printf("O que deseja fazer? ");
        scanf("%s", p_opcao);

        if (strcmp(p_opcao, "1")) {
            if (!registrar_voo(p_listaVoo)) print_erro(0, "");
        } else if (strcmp(p_opcao, "2")) {
            listar_voos(p_listaVoo);
        } else if (strcmp(p_opcao, "3")) {
            if (!excluir_voo(p_listaVoo)) print_erro(0, "");
        } else if (strcmp(p_opcao, "4")) {
            if (!editar_voo(p_listaVoo)) print_erro(0, "");
        } else {
            printf("Saindo do Menu de Vôos...\n");
            return;
        }
    }
}