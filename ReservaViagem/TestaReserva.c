#include "Reserva.h"
#include "Agenda.h"
#include "Data.h"
#include "../ListaPassageiros/Passageiro.h"
#include "../ListaVoos/Voos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../ListaPassageiros/Passageiro.h"
#include "../ListaVoos/Voos.h"
#include <time.h>

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
Reserva *gera_reserva(Data *p_data) {
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

    if (p_data == NULL) {
        p_data = cria_data(
                rand() % 30 + 1,
                rand() % 11 + 1,
                rand() % 2019 + 1);
    }

    Data *p_data = cria_data(
            rand() % 30 + 1,
            rand() % 11 + 1,
            rand() % 2019 + 1);

    Passageiro *p_passageiro = passageiro_cria(p_passageiroNome, p_passageiroEndereco);

    Voo *p_voo = cria_voo(p_vooOrigem, p_vooDestino);

    return cria_reserva(
            p_data,
            p_passageiro,
            p_voo,
            rand() % 30 + 1);
}

/**
 * Teste para criaçao de uma reserva de maneira separada.
 */
static void test_cria_reserva() {
    Reserva *p_reserva = gera_reserva(NULL);
    print_teste(p_reserva != NULL, "test_cria_reserva()");
}

/**
 * Teste para liberaçao de espaçod e uma determinada reserva.
 */
static void test_libera_reserva() {
    Reserva *p_reserva = gera_reserva(NULL);
    print_teste(libera_reserva(&p_reserva), "test_libera_reserva()");
}

/**
 * Testa acessar dados da reserva armazenados em dado canto da memoria
 */
static void test_acessa_reserva() {
    int id = 1;
    char p_passageiroNome[100] = "Teste Nome";
    char p_passageiroEndereco[100] = "Teste Endereco";
    char p_vooOrigem[100] = "Teste Origem";
    char p_vooDestino[100] = "Teste Destino";

    Data *p_data = cria_data(1, 1, 1);

    Passageiro *p_passageiro = (Passageiro *) malloc(sizeof(Passageiro));
    p_passageiro->id = id;
    p_passageiro->nome = p_passageiroNome;
    p_passageiro->endereco = p_passageiroEndereco;

    Voo *p_voo = (Voo *) malloc(sizeof(Voo));
    p_voo->id = id;
    p_voo->origem = p_vooOrigem;
    p_voo->destino = p_vooDestino;

    Reserva *p_reserva = cria_reserva(
            p_data,
            p_passageiro,
            p_voo,
            A0);

    int acessaId;
    Data *p_acessaData;
    Passageiro *p_acessaPassageiro;
    Voo *p_acessaVoo;
    CodigoAssento acessaAssento;

    acessa_reserva(
            p_reserva,
            &acessaId,
            &p_acessaData,
            &p_acessaPassageiro,
            &p_acessaVoo,
            &acessaAssento);

    int acessaDataDia;
    int acessaDataMes;
    int acessaDataAno;

    acessa_data(
            p_acessaData,
            &acessaDataDia,
            &acessaDataMes,
            &acessaDataAno);

    if (acessaDataDia != 1 ||
        acessaDataMes != 1 ||
        acessaDataAno != 1 ||
        strcmp(p_acessaPassageiro->nome, "Teste Nome") != 0 ||
        strcmp(p_acessaPassageiro->endereco, "Teste Endereco") != 0 ||
        strcmp(p_acessaVoo->origem, "Teste Origem") != 0 ||
        strcmp(p_acessaVoo->destino, "Teste Destino") != 0 ||
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
    Data *p_primeiraData = cria_data(12,3,2022);
    Reserva *p_primeiraReserva = gera_reserva(p_primeiraData);

    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_segundaData = cria_data(12,2,2022);
    Reserva *p_segundaReserva = gera_reserva(p_segundaData);

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_terceiraData = cria_data(12,4,2022);
    Reserva *p_terceiraReserva = gera_reserva(p_terceiraData);

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
    Data *p_primeiraData = cria_data(12,3,2022);
    Reserva *p_primeiraReserva = gera_reserva(p_primeiraData);

    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_segundaData = cria_data(12,2,2022);
    Reserva *p_segundaReserva = gera_reserva(p_segundaData);

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_terceiraData = cria_data(12,4,2022);
    Reserva *p_terceiraReserva = gera_reserva(p_terceiraData);

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
    Data *p_primeiraData = cria_data(12,3,2022);
    Reserva *p_primeiraReserva = gera_reserva(p_primeiraData);

    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_segundaData = cria_data(12,2,2022);
    Reserva *p_segundaReserva = gera_reserva(p_segundaData);

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_terceiraData = cria_data(12,4,2022);
    Reserva *p_terceiraReserva = gera_reserva(p_terceiraData);

    Agenda *p_terceiraAgenda = cria_agenda(p_terceiraReserva);

    if (insere_agenda(p_primeiraAgenda, p_terceiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Data *p_dataProcurar = cria_data(12, 4, 2022);

    print_teste(
            busca_reserva_na_agenda_cod_passageiro_data_viagem(p_primeiraAgenda, 11, p_dataProcurar) != NULL,
            "test_busca_reserva_na_agenda_cod_passageiro_data_viagem()");
}

/**
 * Testa a inserçao de reservas em uma agenda
 */
static void test_insere_reserva(){
    Reserva *p_primeiraReserva = gera_reserva(NULL);
    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);
    Reserva *p_segundaReserva = gera_reserva(NULL);
    print_teste(insere_reserva(p_primeiraAgenda, p_segundaReserva) != NULL,  "test_insere_reserva()");
}

/**
 * Testa edição de dados de uma reserva
 */
static void test_edita_reserva() {
    Reserva *p_reserva = gera_reserva(NULL);

    int acessaId;
    Data *p_acessaData;
    Passageiro *p_acessaPassageiro;
    Voo *p_acessaVoo;
    CodigoAssento acessaAssento;
    acessa_reserva(
            p_reserva,
            &acessaId,
            &p_acessaData,
            &p_acessaPassageiro,
            &p_acessaVoo,
            &acessaAssento);

    Data *p_novaData = cria_data(11,11,2011);

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
            edita_reserva(p_reserva, p_novaData, assendo) != NULL,
            "test_edita_reserva()");
}

/**
 * Testa leitura dos dados de reserva e assim exeibição dos mesmos
 */
static void test_ler_reserva(){
    Reserva *p_reserva = gera_reserva(NULL);

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
