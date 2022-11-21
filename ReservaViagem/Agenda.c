#include "Agenda.h"
#include "Reserva.h"
#include "Data.h"
#include <stdio.h>
#include <stdlib.h>

struct agenda {
    Reserva *p_reserva;
    Agenda *p_esquerda;
    Agenda *p_direita;
};

/**
 * Cria uma agenda vazia (caso nao tenha nenhuma reserva) ou com uma reserva cadastrada (caso receba uma reserva como parametro).
 * @param p_reserva
 * @return p_agenda
 */
Agenda *cria_agenda(Reserva *p_reserva) {
    Agenda *p_agenda = (Agenda *) malloc(sizeof(Agenda));
    if (p_agenda == NULL)
        return NULL;

    p_agenda->p_reserva = p_reserva;
    p_agenda->p_esquerda = NULL;
    p_agenda->p_direita = NULL;

    return p_agenda;
}

/**
 * Acessa valores dos atributos da agenda.
 * @param p_agenda
 * @param p_reserva
 * @param p_agendaEsquerda
 * @param p_agendaDireita
 */
void acessa_agenda(
        Agenda *p_agenda,
        Reserva **pp_acessaReserva,
        Agenda **pp_acessaAgendaEsquerda,
        Agenda **pp_acessaAgendaDireita) {
    if (p_agenda == NULL) {
        *pp_acessaReserva = NULL;
        *pp_acessaAgendaEsquerda = NULL;
        *pp_acessaAgendaDireita = NULL;
    } else {
        *pp_acessaReserva = p_agenda->p_reserva;
        *pp_acessaAgendaEsquerda = p_agenda->p_esquerda;
        *pp_acessaAgendaDireita = p_agenda->p_direita;
    }
}

/**
 * Libera espaço da memoria que uma dada agenda ocupava e assim suas agendas subsequentes.
 * Retorna 0 caso haja erro em fazer a liberaçao e 1 caso tenha sucesso.
 * @param pp_agenda
 * @return 0
 * @return 1
 */
int libera_agenda(Agenda **pp_agenda) {
    // TODO: Fazer logica da libera memoria da agenda
//    if (pp_agenda == NULL)
//        return 0;
//
//    Reserva *p_acessaReserva;
//    Agenda *p_acessaAgendaEsquerda;
//    Agenda *p_acessaAgendaDireita;
//
//    acessa_agenda(
//            *pp_agenda,
//            &p_acessaReserva,
//            &p_acessaAgendaEsquerda,
//            &p_acessaAgendaDireita);
//
//    while(p_agendaEsquerda != NULL) {
//        free(p_agendaEsquerda);
//        p_agendaEsquerda = NULL;
//        p_agendaEsquerda = (*(pp_agenda))->p_esquerda;
//    }
//
//    while(p_agendaDireita != NULL) {
//        free(p_agendaDireita);
//        p_agendaDireita = NULL;
//        p_agendaDireita = (*(pp_agenda))->p_esquerda;
//    }
//
//    free(*pp_agenda);
//    pp_agenda = NULL;
//    return 1;
};

/**
 * Insere uma agenda de forma que caso nao exista nenhuma agenda ainda cadastrada sera inserido a primeira e
 * dai pra frente serao inseridas novas agendas baseando-se sempre na data da reserva contida nesta agenda.
 * Retorna NULL caso nao seja possivel inserir a genda ou entao a raiz.
 * @param p_agenda
 * @param p_novaAgenda
 * @return NULL
 * @return p_agendaAnterior
 */
Agenda *insere_agenda(Agenda *p_agenda, Agenda *p_novaAgenda) {
    if (p_agenda == NULL) {
        return p_novaAgenda;
    } else if (p_novaAgenda == NULL)
        return NULL;

    Agenda *p_agendaAnterior;

    int acessaId;
    Data *p_acessaData;
    Passageiro *p_acessaPassageiro;
    Voo *p_acessaVoo;
    CodigoAssento acessaAssento;

    int acessaNovaAgendaId;
    Data *p_acessaNovaAgendaData;
    Passageiro *p_acessaNovaAgendaPassageiro;
    Voo *p_acessaNovaAgendaVoo;
    CodigoAssento acessaNovaAgendaAssento;

    acessa_reserva(
            p_novaAgenda->p_reserva,
            &acessaId,
            &p_acessaNovaAgendaData,
            &p_acessaNovaAgendaPassageiro,
            &p_acessaNovaAgendaVoo,
            &acessaNovaAgendaAssento);

    while (p_agenda != NULL) {
        p_agendaAnterior = p_agenda;

        acessa_reserva(
                p_agenda->p_reserva,
                &acessaNovaAgendaId,
                &p_acessaData,
                &p_acessaPassageiro,
                &p_acessaVoo,
                &acessaAssento);

        if (comparar_datas(p_acessaNovaAgendaData, p_acessaData) <= 0) {
            p_agenda = p_agenda->p_esquerda;
            if (p_agenda == NULL) {
                p_agendaAnterior->p_esquerda = p_novaAgenda;
                return p_agendaAnterior;
            }
        } else {
            p_agenda = p_agenda->p_direita;
            if (p_agenda == NULL) {
                p_agendaAnterior->p_direita = p_novaAgenda;
                return p_agendaAnterior;
            }
        }
    }
}
