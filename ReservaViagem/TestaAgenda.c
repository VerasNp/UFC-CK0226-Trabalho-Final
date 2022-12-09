#include "Agenda.h"
#include "Reserva.h"
#include "Data.h"
#include "../ListaPassageiros/Passageiro.h"
#include "../ListaVoos/Voos.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Validacoes.h"

/**
 * Renderiza resultado do teste
 * @param r
 * @param texto
 */
static void print_teste(int r, char texto[]) {
    if (r) printf("   [SUCESSO] %s\n", texto);
    else printf("   [ERRO] %s\n", texto);
}

/**
 * Cria uma reserva com valores randomicos
 * @return NULL
 * @return p_reserva
 */
Reserva *gera_reserva() {
    int id = 0;
    char idText[12];
    char p_passageiroNome[100] = "Teste Nome";
    char p_passageiroEndereco[100] = "Teste Endereco";
    char p_vooOrigem[100] = "Teste Origem";
    char p_vooDestino[100] = "Teste Destino";

    sprintf(idText, "%d", ++id);
    strcat(p_passageiroNome, idText);
    strcat(p_passageiroEndereco, idText);
    strcat(p_vooOrigem, idText);
    strcat(p_vooDestino, idText);

    Data *p_dataPartida = cria_data(
            rand() % 28 + 1,
            rand() % 9 + 1,
            rand() % 2018 + 1);

    int diaPartida;
    int mesPartida;
    int anoPartida;
    acessa_data(p_dataPartida,
                &diaPartida,
                &mesPartida,
                &anoPartida);

    Data *p_dataChegada = cria_data(
            diaPartida + 1,
            mesPartida + 1,
            anoPartida + 1);

    Passageiro *p_passageiro = passageiro_cria(p_passageiroNome, p_passageiroEndereco);

    Voo *p_voo = cria_voo(p_vooOrigem, p_vooDestino);

    return cria_reserva(
            p_dataPartida,
            p_dataChegada,
            p_passageiro,
            p_voo,
            rand() % 30 + 1);
}

/**
 * Teste para criaçao de uma agenda preenchida com uma reserva de forma separada
 */
static void test_cria_agenda() {
    Agenda *p_agenda = cria_agenda(NULL);
    print_teste(p_agenda != NULL, "test_cria_agenda()");
}

/**
 * Testa funçao para acessar atributos da agenda em dado ponto da memoria
 */
static void test_acessa_agenda() {
    Reserva *p_primeiraReserva = gera_reserva();
    Agenda *p_agenda = cria_agenda(p_primeiraReserva);

    Reserva *p_acessaReserva;
    Agenda *p_acessaAgendaEsquerda;
    Agenda *p_acessaAgendaDireita;

    acessa_agenda(
            p_agenda,
            &p_acessaReserva,
            &p_acessaAgendaEsquerda,
            &p_acessaAgendaDireita);

    print_teste(p_acessaReserva == p_primeiraReserva, "test_acessa_agenda()");
}

/**
 * Teste para liberaçao de espaçco de memoria ocupado por agenda
 */
static void test_libera_agenda() {
    Reserva *p_reserva = gera_reserva();
    Agenda *p_agenda = cria_agenda(p_reserva);

    print_teste(libera_agenda(&p_agenda) == 1, "test_libera_agenda()");
}


/**
 * Teste de inserir uma nova agenda com uma reserva dentro da mesma
 */
static void test_insere_agenda() {
    Reserva *p_primeiraReserva = gera_reserva();

    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Reserva *p_segundaReserva = gera_reserva();

    if (!valida_intervalo_datas(p_primeiraAgenda, p_segundaReserva))
        print_teste(0, "insere_agenda()");

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Reserva *p_terceiraReserva = gera_reserva();

    if (!valida_intervalo_datas(p_primeiraAgenda, p_terceiraReserva))
        print_teste(0, "insere_agenda()");

    Agenda *p_terceiraAgenda = cria_agenda(p_terceiraReserva);

    if (insere_agenda(p_primeiraAgenda, p_terceiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    print_teste(1, "insere_agenda()");
}

static void test_remove_agenda() {
    Reserva *p_primeiraReserva = gera_reserva();

    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Reserva *p_segundaReserva = gera_reserva();

    if (!valida_intervalo_datas(p_primeiraAgenda, p_segundaReserva))
        print_teste(0, "insere_agenda()");

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Reserva *p_terceiraReserva = gera_reserva();

    if (!valida_intervalo_datas(p_primeiraAgenda, p_terceiraReserva))
        print_teste(0, "insere_agenda()");

    Agenda *p_terceiraAgenda = cria_agenda(p_terceiraReserva);

    if (insere_agenda(p_primeiraAgenda, p_terceiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    print_teste(remove_agenda(p_primeiraAgenda,NULL, p_segundaReserva),"test_remove_agenda()");
}

int main(void) {
    srand(time(0));
    test_cria_agenda();
    test_acessa_agenda();
    test_libera_agenda();
    test_insere_agenda();
    test_remove_agenda();
    exit(EXIT_SUCCESS);
}