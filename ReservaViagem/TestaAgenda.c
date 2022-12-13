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
    printf("- Testando test_cria_agenda()...\n");
    Agenda *p_agenda = cria_agenda(NULL);
    print_teste(p_agenda != NULL, "test_cria_agenda()");
}

/**
 * Testa funçao para acessar atributos da agenda em dado ponto da memoria
 */
static void test_acessa_agenda() {
    printf("- Testando test_acessa_agenda()...\n");
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
    printf("- Testando test_libera_agenda()...\n");
    Reserva *p_reserva = gera_reserva();
    Agenda *p_agenda = cria_agenda(p_reserva);

    print_teste(libera_agenda(&p_agenda) == 1, "test_libera_agenda()");
}


/**
 * Teste de inserir uma nova agenda com uma reserva dentro da mesma
 */
static void test_insere_agenda() {
    printf("- Testando test_insere_agenda()...\n");
    Data *p_primeiraDataPartida = cria_data(12, 3, 2022);
    Data *p_primeiraDataChegada = cria_data(13, 3, 2022);
    Passageiro *p_passageiroPrimeiro = passageiro_cria("Passageiro teste 1", "Endereço teste 1");
    Voo *p_vooPrimeiro = cria_voo("Teste Origem 1", "Teste Destino 1");
    Reserva *p_primeiraReserva = cria_reserva(p_primeiraDataPartida, p_primeiraDataChegada, p_passageiroPrimeiro, p_vooPrimeiro, A0);
    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_segundaDataPartida = cria_data(12, 2, 2022);
    Data *p_segundaDataChegada = cria_data(13, 2, 2022);
    Passageiro *p_passageiroSegundo = passageiro_cria("Passageiro teste 2", "Endereço teste 2");
    Voo *p_vooSegundo = cria_voo("Teste Origem 2", "Teste Destino 2");
    Reserva *p_segundaReserva = cria_reserva(p_segundaDataPartida, p_segundaDataChegada, p_passageiroSegundo, p_vooSegundo, A1);

    if (!valida_intervalo_datas(p_primeiraAgenda, p_segundaReserva))
        print_teste(0, "test_insere_agenda()");

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_terceiraDataPartida = cria_data(12, 4, 2022);
    Data *p_terceiraDataChegada = cria_data(13, 4, 2022);
    Passageiro *p_passageiroTerceiro = passageiro_cria("Passageiro teste 3", "Endereço teste 3");
    Voo *p_vooTerceiro = cria_voo("Teste Origem 3", "Teste Destino 3");
    Reserva *p_terceiraReserva = cria_reserva(p_terceiraDataPartida, p_terceiraDataChegada, p_passageiroTerceiro, p_vooTerceiro, A1);

    if (!valida_intervalo_datas(p_primeiraAgenda, p_terceiraReserva))
        print_teste(0, "test_insere_agenda()");

    Agenda *p_terceiraAgenda = cria_agenda(p_terceiraReserva);

    if (insere_agenda(p_primeiraAgenda, p_terceiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    print_teste(1, "insere_agenda()");
}

static void test_remove_agenda() {
    printf("- Testando test_remove_agenda()...\n");
    Data *p_primeiraDataPartida = cria_data(12, 3, 2022);
    Data *p_primeiraDataChegada = cria_data(13, 3, 2022);
    Passageiro *p_passageiroPrimeiro = passageiro_cria("Passageiro teste 1", "Endereço teste 1");
    Voo *p_vooPrimeiro = cria_voo("Teste Origem 1", "Teste Destino 1");
    Reserva *p_primeiraReserva = cria_reserva(p_primeiraDataPartida, p_primeiraDataChegada, p_passageiroPrimeiro, p_vooPrimeiro, A0);
    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "test_remove_agenda()");

    Data *p_segundaDataPartida = cria_data(12, 2, 2022);
    Data *p_segundaDataChegada = cria_data(13, 2, 2022);
    Passageiro *p_passageiroSegundo = passageiro_cria("Passageiro teste 2", "Endereço teste 2");
    Voo *p_vooSegundo = cria_voo("Teste Origem 2", "Teste Destino 2");
    Reserva *p_segundaReserva = cria_reserva(p_segundaDataPartida, p_segundaDataChegada, p_passageiroSegundo, p_vooSegundo, A1);

    if (!valida_intervalo_datas(p_primeiraAgenda, p_segundaReserva))
        print_teste(0, "test_remove_agenda()");

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "test_remove_agenda()");

    Data *p_terceiraDataPartida = cria_data(12, 4, 2022);
    Data *p_terceiraDataChegada = cria_data(13, 4, 2022);
    Passageiro *p_passageiroTerceiro = passageiro_cria("Passageiro teste 3", "Endereço teste 3");
    Voo *p_vooTerceiro = cria_voo("Teste Origem 3", "Teste Destino 3");
    Reserva *p_terceiraReserva = cria_reserva(p_terceiraDataPartida, p_terceiraDataChegada, p_passageiroTerceiro, p_vooTerceiro, A1);

    if (!valida_intervalo_datas(p_primeiraAgenda, p_terceiraReserva))
        print_teste(0, "test_remove_agenda()");

    Agenda *p_terceiraAgenda = cria_agenda(p_terceiraReserva);

    if (insere_agenda(p_primeiraAgenda, p_terceiraAgenda) == NULL)
        print_teste(0, "test_remove_agenda()");

    print_teste(remove_agenda(p_primeiraAgenda,NULL, p_segundaReserva),"test_remove_agenda()");
}

void test_valida_intervalos_datas() {
    printf("- Testando test_valida_intervalos_datas()...\n");
    Passageiro *p_passageiro = passageiro_cria("Igor", "Aldeota");
    Voo *p_voo = cria_voo("Fortaleza", "Campinas");
        Data *p_partida1 = cria_data(15, 07, 2022);
        Data *p_chegada1 = cria_data(19, 07, 2022);


    Reserva *p_reserva = cria_reserva(p_partida1, p_chegada1, p_passageiro, p_voo, rand()%30);
    Agenda *p_primeiraAgenda = cria_agenda(p_reserva);

    Voo *p_voo2 = cria_voo("Fortaleza", "São Paulo");
    Data *p_partida2 = cria_data(19, 07, 2022);
    Data *p_chegada2 = cria_data(21, 07, 2022);
    Reserva *p_reserva2 = cria_reserva(p_partida2, p_chegada2, p_passageiro, p_voo2, rand()%30);

    print_teste(valida_intervalo_datas(p_primeiraAgenda, p_reserva2) == 1, "valida_intervalo_datas() - sem choque temporal: viagem começa assim que termina viagem já cadastrada." );

    Voo *p_voo3 = cria_voo("Fortaleza", "São Paulo");
    Data *p_partida3 = cria_data(14, 07, 2022);
    Data *p_chegada3 = cria_data(17, 07, 2022);
    Reserva *p_reserva3 = cria_reserva(p_partida3, p_chegada3, p_passageiro, p_voo3, rand()%30);
    print_teste(valida_intervalo_datas(p_primeiraAgenda, p_reserva3) == 0, "valida_intervalo_datas() - choque temporal: viagem começa antes e termina durante uma viagem já registrada." );

    Voo *p_voo4 = cria_voo("Fortaleza", "São Paulo");
    Data *p_partida4 = cria_data(16, 07, 2022);
    Data *p_chegada4 = cria_data(30, 07, 2022);
    Reserva *p_reserva4 = cria_reserva(p_partida4, p_chegada4, p_passageiro, p_voo4, rand()%30);
    print_teste(valida_intervalo_datas(p_primeiraAgenda, p_reserva4) == 0, "valida_intervalo_datas() - choque temporal: viagem começa durante uma viagem já registrada." );

    Voo *p_voo5 = cria_voo("Fortaleza", "São Paulo");
    Data *p_partida5 = cria_data(15, 07, 2022);
    Data *p_chegada5 = cria_data(16, 07, 2022);
    Reserva *p_reserva5 = cria_reserva(p_partida5, p_chegada5, p_passageiro, p_voo5, rand()%30);
    print_teste(valida_intervalo_datas(p_primeiraAgenda, p_reserva5) == 0, "valida_intervalo_datas() - choque temporal: viagem começa na partida de uma viagem já registrada." );

}

int main(void) {
    srand(time(0));
    test_cria_agenda();
    test_acessa_agenda();
    test_libera_agenda();
    test_insere_agenda();
    test_valida_intervalos_datas();
    test_remove_agenda();
    exit(EXIT_SUCCESS);
}