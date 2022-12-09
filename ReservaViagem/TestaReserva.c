#include "Reserva.h"
#include "Agenda.h"
#include "Data.h"
#include "../ListaPassageiros/Passageiro.h"
#include "../ListaVoos/Voos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../Utils/Validacoes.h"

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
Reserva *gera_reserva(Data *p_dataPartida, Data *p_dataChegada) {
    static int id;
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

    if (p_dataPartida == NULL && p_dataChegada == NULL) {
        p_dataPartida = cria_data(
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

        p_dataChegada = cria_data(
                diaPartida + 1,
                mesPartida + 1,
                anoPartida + 1);
    }

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
 * Teste para criaçao de uma reserva de maneira separada.
 */
static void test_cria_reserva() {
    Reserva *p_reserva = gera_reserva(NULL, NULL);
    print_teste(p_reserva != NULL, "test_cria_reserva()");
}

/**
 * Teste para liberaçao de espaçod e uma determinada reserva.
 */
static void test_libera_reserva() {
    Reserva *p_reserva = gera_reserva(NULL, NULL);
    print_teste(libera_reserva(p_reserva, 0), "test_libera_reserva()");
}

/**
 * Testa acessar dados da reserva armazenados em dado canto da memoria
 */
static void test_acessa_reserva() {
    char p_passageiroNome[100] = "Teste Nome";
    char p_passageiroEndereco[100] = "Teste Endereco";
    char p_vooOrigem[100] = "Teste Origem";
    char p_vooDestino[100] = "Teste Destino";

    Data *p_dataPartida = cria_data(1, 1, 1);
    Data *p_dataChegada = cria_data(2, 2, 2);

    Passageiro *p_passageiro = passageiro_cria(p_passageiroNome, p_passageiroEndereco);

    Voo *p_voo = cria_voo(p_vooOrigem, p_vooDestino);

    Reserva *p_reserva = cria_reserva(
            p_dataPartida,
            p_dataChegada,
            p_passageiro,
            p_voo,
            A0);

    int acessaId;
    Data *p_acessaDataPartida;
    Data *p_acessaDataChegada;
    Passageiro *p_acessaPassageiro;
    Voo *p_acessaVoo;
    CodigoAssento acessaAssento;
    acessa_reserva(
            p_reserva,
            &acessaId,
            &p_acessaDataPartida,
            &p_acessaDataChegada,
            &p_acessaPassageiro,
            &p_acessaVoo,
            &acessaAssento);

    int acessaDataPartidaDia;
    int acessaDataPartidaMes;
    int acessaDataPartidaAno;
    acessa_data(
            p_acessaDataPartida,
            &acessaDataPartidaDia,
            &acessaDataPartidaMes,
            &acessaDataPartidaAno);

    int acessaDataChegadaDia;
    int acessaDataChegadaMes;
    int acessaDataChegadaAno;
    acessa_data(
            p_acessaDataChegada,
            &acessaDataChegadaDia,
            &acessaDataChegadaMes,
            &acessaDataChegadaAno);

    int acessaPassageiroId;
    char *p_acessaPassageiroNome = (char *)malloc(sizeof(char)*100);
    char *p_acessaPassageiroEndereco = (char *)malloc(sizeof(char)*300);
    passageiro_acessa(
            p_acessaPassageiro,
            &acessaPassageiroId,
            p_acessaPassageiroNome,
            p_acessaPassageiroEndereco);

    int acessaVooId;
    char *p_acessaPassageiroOrigem = (char *)malloc(sizeof(char)*300);
    char *p_acessaPassageiroDestino = (char *)malloc(sizeof(char)*300);
    leitura_voo(
            p_acessaVoo,
            &acessaVooId,
            p_acessaPassageiroOrigem,
            p_acessaPassageiroDestino);

    if (acessaDataPartidaDia != 1 ||
        acessaDataPartidaMes != 1 ||
        acessaDataPartidaAno != 1 ||
            acessaDataChegadaDia != 2 ||
            acessaDataChegadaMes != 2 ||
            acessaDataChegadaAno != 2 ||
        strcmp(p_acessaPassageiroNome, "Teste Nome") != 0 ||
        strcmp(p_acessaPassageiroEndereco, "Teste Endereco") != 0 ||
        strcmp(p_acessaPassageiroOrigem, "Teste Origem") != 0 ||
        strcmp(p_acessaPassageiroDestino, "Teste Destino") != 0 ||
        acessaAssento != A0) {
        print_teste(0, "test_acessa_reserva()");
    } else {
        print_teste(1, "test_acessa_reserva()");
    }
}

/**
 * Testa funçao de busca de reserva pelo codigo da reserva
 */
static void test_busca_reserva_na_agenda_cod_reserva() {
    Data *p_primeiraDataPartida = cria_data(12,3,2022);
    Data *p_primeiraDataChegada = cria_data(13,3,2022);
    Reserva *p_primeiraReserva = gera_reserva(p_primeiraDataPartida, p_primeiraDataChegada);
    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_segundaDataPartida = cria_data(12,2,2022);
    Data *p_segundaDataChegada = cria_data(13,2,2022);
    Reserva *p_segundaReserva = gera_reserva(p_segundaDataPartida, p_segundaDataChegada);

    if (!valida_intervalo_datas(p_primeiraAgenda, p_segundaReserva))
        print_teste(0, "insere_agenda()");

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_terceiraDataPartida = cria_data(12,4,2022);
    Data *p_terceiraDataChegada = cria_data(13,4,2022);
    Reserva *p_terceiraReserva = gera_reserva(p_terceiraDataPartida, p_terceiraDataChegada);

    if (!valida_intervalo_datas(p_primeiraAgenda, p_terceiraReserva))
        print_teste(0, "insere_agenda()");

    Agenda *p_terceiraAgenda = cria_agenda(p_terceiraReserva);

    if (insere_agenda(p_primeiraAgenda, p_terceiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    print_teste(busca_reserva_na_agenda_cod_reserva(p_primeiraAgenda, 5) != NULL,
                "test_busca_reserva_na_agenda_cod_reserva()");
}

/**
 * Testa a busca de reservas a partir de um dado código do passageiro e voo
 */
static void test_busca_reserva_na_agenda_cod_passageiro_cod_voo() {
    Data *p_primeiraDataPartida = cria_data(12,3,2022);
    Data *p_primeiraDataChegada = cria_data(13,3,2022);
    Reserva *p_primeiraReserva = gera_reserva(p_primeiraDataPartida, p_primeiraDataChegada);
    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_segundaDataPartida = cria_data(12,2,2022);
    Data *p_segundaDataChegada = cria_data(13,2,2022);
    Reserva *p_segundaReserva = gera_reserva(p_segundaDataPartida,p_segundaDataChegada );

    if (!valida_intervalo_datas(p_primeiraAgenda, p_segundaReserva))
        print_teste(0, "insere_agenda()");

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_terceiraDataPartida = cria_data(12,4,2022);
    Data *p_terceiraDataChegada = cria_data(13,4,2022);
    Reserva *p_terceiraReserva = gera_reserva(p_terceiraDataPartida, p_terceiraDataChegada);

    if (!valida_intervalo_datas(p_primeiraAgenda, p_terceiraReserva))
        print_teste(0, "insere_agenda()");

    Agenda *p_terceiraAgenda = cria_agenda(p_terceiraReserva);

    if (insere_agenda(p_primeiraAgenda, p_terceiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    print_teste(
            busca_reserva_na_agenda_cod_passageiro_cod_voo(p_primeiraAgenda, 7, 7) != NULL,
            "test_busca_reserva_na_agenda_cod_passageiro_cod_voo()");
}

/**
 * Testa a busca de reservas baseado em código do passageiro e data da viagem
 */
static void test_busca_reserva_na_agenda_cod_passageiro_data_viagem() {
    Data *p_primeiraDataPartida = cria_data(12,2,2022);
    Data *p_primeiraDataChegada = cria_data(22,2,2022);
    Reserva *p_primeiraReserva = gera_reserva(p_primeiraDataPartida, p_primeiraDataChegada);
    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_segundaDataPartida = cria_data(11,2,2022);
    Data *p_segundaDataChegada = cria_data(13,2,2022);
    Reserva *p_segundaReserva = gera_reserva(p_segundaDataPartida, p_segundaDataChegada);

    if (valida_intervalo_datas(p_primeiraAgenda, p_segundaReserva) == 1)
        print_teste(0, "insere_agenda()");

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_terceiraDataPartida = cria_data(12,4,2022);
    Data *p_terceiraDataChegada = cria_data(13,4,2022);
    Reserva *p_terceiraReserva = gera_reserva(p_terceiraDataPartida, p_terceiraDataChegada);

    if (!valida_intervalo_datas(p_primeiraAgenda, p_terceiraReserva))
        print_teste(0, "insere_agenda()4");

    Agenda *p_terceiraAgenda = cria_agenda(p_terceiraReserva);

    if (insere_agenda(p_primeiraAgenda, p_terceiraAgenda) == NULL)
        print_teste(0, "insere_agenda()5");

    Data *p_dataPartida = cria_data(10, 2, 2022);
    Data *p_dataChegada = cria_data(15, 2, 2022);

    print_teste(
            busca_reserva_na_agenda_cod_passageiro_data_viagem(p_primeiraAgenda, 11, p_dataPartida, p_dataChegada) != NULL,
            "test_busca_reserva_na_agenda_cod_passageiro_data_viagem()");
}

/**
 * Testa a inserçao de reservas em uma agenda
 */
static void test_insere_reserva(){
    Reserva *p_primeiraReserva = gera_reserva(NULL, NULL);
    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);
    Reserva *p_segundaReserva = gera_reserva(NULL, NULL);
    print_teste(insere_reserva(p_primeiraAgenda, p_segundaReserva) != NULL,  "test_insere_reserva()");
}

/**
 * Testa edição de dados de uma reserva
 */
static void test_edita_reserva() {
    Reserva *p_reserva = gera_reserva(NULL, NULL);

    int acessaId;
    Data *p_acessaDataPartida;
    Data *p_acessaDataChegada;
    Passageiro *p_acessaPassageiro;
    Voo *p_acessaVoo;
    CodigoAssento acessaAssento;
    acessa_reserva(
            p_reserva,
            &acessaId,
            &p_acessaDataPartida,
            &p_acessaDataChegada,
            &p_acessaPassageiro,
            &p_acessaVoo,
            &acessaAssento);

    Data *p_novaDataPartida = cria_data(11,11,2011);
    Data *p_novaDataChegada = cria_data(12,11,2011);

    char *p_novoNome = "Teste novo Nome";
    char *p_novoEndereco = "Teste novo Endereco";
    passageiro_atribui(
            p_acessaPassageiro,
            p_novoNome,
            p_novoEndereco);

    char *p_novaOrigem = "Teste nova origem";
    char *p_novoDestino = "Teste novo destino";
    edita_voo(
            p_acessaVoo,
            p_novaOrigem,
            p_novoDestino);

    CodigoAssento assendo = A0;

    print_teste(
            edita_reserva(p_reserva, p_novaDataPartida, p_novaDataChegada, assendo) != NULL,
            "test_edita_reserva()");
}

/**
 * Testa leitura dos dados de reserva e assim exeibição dos mesmos
 */
static void test_ler_reserva(){
    Reserva *p_reserva = gera_reserva(NULL, NULL);

    print_teste(ler_reserva(p_reserva) != NULL, "test_ler_reserva()");
}

int main(void) {
    srand(time(0));
    test_cria_reserva();
    test_libera_reserva();
    test_acessa_reserva();
    test_busca_reserva_na_agenda_cod_reserva();
    test_busca_reserva_na_agenda_cod_passageiro_cod_voo();
    test_busca_reserva_na_agenda_cod_passageiro_data_viagem();
    test_insere_reserva();
    test_edita_reserva();
    test_ler_reserva();
    exit(EXIT_SUCCESS);
}
