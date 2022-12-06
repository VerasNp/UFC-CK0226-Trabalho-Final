#include "ReservasMenu.h"
#include "../ListaPassageiros/Passageiro.h"
#include "../Utils/Validacoes.h"
#include "../Utils/Utils.h"
#include "stdio.h"
#include "stdlib.h"

void ReservasMenu() {
    char *opcao = (char *) malloc(sizeof(char));
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

    switch (*opcao) {
        case '1':
            CriarReservasMenu();
            break;
    }
}

void CriarReservasMenu() {
    char *p_nome = (char *) malloc(sizeof(char) * 1001);
    char *p_endereco = (char *) malloc(sizeof(char) * 1001);
    printf("Insira os dados do passageiro: \n");

    while (1) {
        printf("Nome: ");
        scanf("%s", p_nome);
        if (valida_string_nulo(p_nome) || valida_tamanho_string(p_nome, 100, ">"))
            erro("O nome deve ter no máximo 100 caractéries!\n");
        else
            break;
    }

    while (1) {
        printf("Endereço: ");
        scanf("%s", p_endereco);
        if (valida_string_nulo(p_endereco) || valida_tamanho_string(p_endereco, 300, ">"))
            erro("O Endereço deve ter no máximo 300 caractéries!\n");
        else
            break;
    }

    printf("Escolha uma data para a sua viagem: \n");
    int dia;
    int mes;
    int ano;

    while (1) {
        printf("Mês [1-12]: ");
        scanf("%2d", &mes);
        if (mes < 1 || mes > 12) erro("O mês deve estar no intervalo de 1 a 12!\n");
        else break;
    }

    while (1) {
        int aux;
        if (mes == 2) {
            aux = 1;
            printf("Dia [1-28]: ");
        } else if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 9 || mes == 12) {
            aux = 2;
            printf("Dia [1-31]: ");
        } else {
            aux = 3;
            printf("Dia [1-30]: ");
        }
        scanf("%2d", &dia);

        if (dia < 1)
            erro("O dia deve ter um valor válido!\n");
        else if ((aux == 1 && dia > 28) || (aux == 2 && dia > 31) || (aux == 3 && dia > 30))
            erro("O dia deve ter um valor válido!\n");
        else break;
    }

    while (1) {
        printf("Ano [2022-Adiante]: ");
        scanf("%4d", &ano);
        if (ano < 2022) erro("O ano deve ter um valor válido!\n");
        else break;
    }

    printf("Escolha um assento: \n");
}