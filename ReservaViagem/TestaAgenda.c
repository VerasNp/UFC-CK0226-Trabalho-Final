#include "Agenda.h"
#include "Reserva.h"
#include "Data.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


// Structs temp =============
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
// ===========================

// TODO: Apoes a funcao de liberar agenda for implementada esta sera a nova funcao para exibir o resultado de testes
///**
// * Renderiza resultado do teste
// * @param r
// * @param texto
// */
//static void print_teste(int r, char texto[], Agenda *p_agenda) {
//    libera_agenda(&p_agenda);
//    if (r) printf("   [SUCESSO] %s\n", texto);
//    else printf("   [ERRO] %s\n", texto);
//}

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

    Data *p_data = cria_data(
            rand() % 30 + 1,
            rand() % 11 + 1,
            rand() % 2019 + 1);

    Passageiro *p_passageiro = (Passageiro *) malloc(sizeof(Passageiro));
    p_passageiro->id = id;
    p_passageiro->nome = p_passageiroNome;
    p_passageiro->endereco = p_passageiroEndereco;

    Voo *p_voo = (Voo *) malloc(sizeof(Voo));
    p_voo->id = id;
    p_voo->origem = p_vooOrigem;
    p_voo->destino = p_vooDestino;

    return cria_reserva(
            p_data,
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
    // TODO: Teste para uma arvore maior
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

    Agenda *p_segundaAgenda = cria_agenda(p_segundaReserva);

    if (insere_agenda(p_primeiraAgenda, p_segundaAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    Reserva *p_terceiraReserva = gera_reserva();

    Agenda *p_terceiraAgenda = cria_agenda(p_terceiraReserva);

    if (insere_agenda(p_primeiraAgenda, p_terceiraAgenda) == NULL)
        print_teste(0, "insere_agenda()");

    print_teste(1, "insere_agenda()");
}

int main(void) {
    srand(time(NULL));
    test_cria_agenda();
    test_acessa_agenda();
    test_libera_agenda();
    test_insere_agenda();
    exit(EXIT_SUCCESS);
}