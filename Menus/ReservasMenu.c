#include "ReservasMenu.h"
#include "../ListaPassageiros/Passageiro.h"
#include "../ListaPassageiros/ListaPassageiros.h"
#include "../ListaVoos/Voos.h"
#include "../ListaVoos/ListaVoos.h"
#include "../ReservaViagem/Data.h"
#include "../ReservaViagem/Agenda.h"
#include "../ReservaViagem/Reserva.h"
#include "../Utils/Validacoes.h"
#include "../Utils/Utils.h"
#include "stdio.h"
#include "stdlib.h"

void reservas_menu(Agenda *p_agenda, ListaPassageiro *p_listaPassageiros, ListaVoo *p_listaVoos) {
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
            criar_reservas_menu(p_agenda, p_listaPassageiros, p_listaVoos);
            break;
    }
}

void criar_reservas_menu(Agenda *p_agenda, ListaPassageiro *p_listaPassageiros, ListaVoo *p_listaVoos) {
    // Passageiro
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
    Passageiro *p_passageiro = busca_nome_passageiro(p_listaPassageiros, p_nome);

    if (p_passageiro == NULL) {
        p_passageiro = passageiro_cria(p_nome, p_endereco);
        incluir_passageiro(p_listaPassageiros, p_passageiro);
    }

    // Data da reserva
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
    Data *p_data = cria_data(dia, mes, ano);

    while (1) {
        if (busca_reserva_na_agenda_cod_passageiro_data_viagem(p_agenda, get_passageiro_codigo(p_passageiro), p_data) !=
            NULL) {
            erro("Um mesmo passageiro não pode viajar ao mesmo tempo para dois lugares!");
        } else break;
    }

    // Voo
    int codigoVoo;
    Voo *p_voo;
    if (tamanho_lista(p_listaVoos) == 0) {
        erro("Infelizmente ainda não temos voos disponíveis!");
        return;
    }
    printf("Escolha um voo: ");
    scanf("%d", &codigoVoo);
    p_voo = busca_voo(p_listaVoos, codigoVoo);


    // Assento
    printf("Escolha um assento: \n");
    CodigoAssento assento;
    scanf("%u", &assento);

    Reserva *p_reserva = cria_reserva(p_data, p_passageiro, p_voo, assento);
    Agenda *p_novaAgenda = cria_agenda(p_reserva);
    insere_agenda(p_agenda, p_novaAgenda);
}