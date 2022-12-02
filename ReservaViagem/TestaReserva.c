#include "Reserva.h"
#include "Agenda.h"
#include "Data.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../ListaPassageiros/Passageiro.h"
#include "../ListaVoos/Voos.h"
#include <time.h>

// Temp structs =====
struct passageiro {
    int id;
    char *nome;
    char *endereco;
};

struct voo {
    int id;
    char *origem;
    char *destino;
};
// ==================

/**
 * Renderiza resultado do teste
 * @param r
 * @param texto
 */
static void print_teste(int r, char texto[], Reserva *p_reserva) {
//    libera_reserva(&p_reserva);
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

    srand(time(NULL));

    Data *p_data = cria_data(
            rand() % 30 + 1,
            rand() % 11 + 1,
            rand() % 2019 + 1);

//    Passageiro *p_passageiro = (Passageiro *) malloc(sizeof(Passageiro));
//    p_passageiro->id = id;
//    p_passageiro->nome = p_passageiroNome;
//    p_passageiro->endereco = p_passageiroEndereco;

//    Voo *p_voo = (Voo *) malloc(sizeof(Voo));
//    p_voo->id = id;
//    p_voo->origem = p_vooOrigem;
//    p_voo->destino = p_vooDestino;

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
    Reserva *p_reserva = gera_reserva();
    print_teste(p_reserva != NULL, "test_cria_reserva()", p_reserva);
}

/**
 * Teste para liberaçao de espaçod e uma determinada reserva.
 */
static void test_libera_reserva() {
    Reserva *p_reserva = gera_reserva();
    print_teste(libera_reserva(p_reserva), "test_libera_reserva()", NULL);
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
        print_teste(0, "test_acessa_reserva()", p_reserva);
    } else {
        print_teste(1, "test_acessa_reserva()", p_reserva);
    }
}

/**
 * Testa funçao de busca de reserva pelo codigo da reserva
 */
static void test_busca_reserva_na_agenda_cod_reserva() {
    Reserva *p_primeiraReserva = gera_reserva();

    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);

    if (insere_agenda(NULL, p_primeiraAgenda) == NULL)
        print_teste(0, "insere_agenda()", p_primeiraReserva);

    Reserva *p_segundaReserva = gera_reserva();

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()", p_segundaReserva);

    Reserva *p_terceiraReserva = gera_reserva();

    Agenda *p_terceiraAgenda = cria_agenda(p_terceiraReserva);

    if (insere_agenda(p_primeiraAgenda, p_terceiraAgenda) == NULL)
        print_teste(0, "insere_agenda()", p_terceiraReserva);

    print_teste(busca_reserva_na_agenda_cod_reserva(p_primeiraAgenda, 5) != NULL,
                "test_busca_reserva_na_agenda_cod_reserva()", p_primeiraReserva);
}

/**
 * Testa a inserçao de reservas em uma agenda
 */
static void test_insere_reserva(){
    Reserva *p_primeiraReserva = gera_reserva();
    Agenda *p_primeiraAgenda = cria_agenda(p_primeiraReserva);
    Reserva *p_segundaReserva = gera_reserva();
    print_teste(insere_reserva(p_primeiraAgenda, p_segundaReserva) != NULL,  "test_insere_reserva()", p_primeiraReserva);
}

int main(void) {
    test_cria_reserva();
    test_libera_reserva();
    test_acessa_reserva();
    test_busca_reserva_na_agenda_cod_reserva();
    test_insere_reserva();
    exit(EXIT_SUCCESS);
}
