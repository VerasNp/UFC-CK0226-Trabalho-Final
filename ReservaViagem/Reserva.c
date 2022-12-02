#include "../Utils/Headers.h"
#include "Data.h"
#include "Reserva.h"
#include "Agenda.h"
#include <stdio.h>
#include <stdlib.h>

struct reserva {
    int id;
    Data *p_data;
    Passageiro *p_passageiro;
    Voo *p_voo;
    CodigoAssento codigoAssento;
};

/**
 * Criaçao individual de uma reserva
 * @param p_data
 * @param p_passageiro
 * @param p_voo
 * @param codigoAssento
 * @return NULL
 * @return p_reserva
 */
Reserva *cria_reserva(
        Data *p_data,
        Passageiro *p_passageiro,
        Voo *p_voo,
        CodigoAssento codigoAssento) {
    static int id;

    if (
            p_data == NULL ||
            p_passageiro == NULL ||
            p_voo == NULL ||
            (codigoAssento < 0 || codigoAssento > C9)) {
        return NULL;
    }

    Reserva *p_reserva = (Reserva *) malloc(sizeof(Reserva));
    if (p_reserva == NULL)
        return NULL;

    p_reserva->id = ++id;
    p_reserva->p_data = p_data;
    p_reserva->p_passageiro = p_passageiro;
    p_reserva->p_voo = p_voo;
    p_reserva->codigoAssento = codigoAssento;

    return p_reserva;
}

/**
 * Acessa dados da reserva armazenados em dado lugar da memoria
 * @param p_reserva
 * @param p_id
 * @param pp_acessaData
 * @param pp_acessaPassageiro
 * @param pp_acessaVoo
 * @param p_acessaCodigoAssento
 */
void acessa_reserva(
        Reserva *p_reserva,
        int *p_id,
        Data **pp_acessaData,
        Passageiro **pp_acessaPassageiro,
        Voo **pp_acessaVoo,
        CodigoAssento *p_acessaCodigoAssento) {
    if (p_reserva == NULL) {
        *p_id = -1;
        *pp_acessaData = NULL;
        *pp_acessaPassageiro = NULL;
        *pp_acessaVoo = NULL;
        *p_acessaCodigoAssento = -1;
    } else {
        *p_id = p_reserva->id;
        *pp_acessaData = p_reserva->p_data;
        *pp_acessaPassageiro = p_reserva->p_passageiro;
        *pp_acessaVoo = p_reserva->p_voo;
        *p_acessaCodigoAssento = p_reserva->codigoAssento;
    }
};

/**
 * Libera espaço ocupado por determinada reserva
 * @param pp_reserva
 * @return 0
 * @return 1
 */
int libera_reserva(Reserva **pp_reserva) {
    if (pp_reserva == NULL)
        return 0;

    int id;
    Data *p_acessaData;
    Passageiro *p_acessaPassageiro;
    Voo *p_acessaVoo;
    CodigoAssento acessaAssento;

    acessa_reserva(
            *pp_reserva,
            &id,
            &p_acessaData,
            &p_acessaPassageiro,
            &p_acessaVoo,
            &acessaAssento);

    libera_data(&p_acessaData);

    free(p_acessaPassageiro);
    p_acessaPassageiro = NULL;

    free(p_acessaVoo);
    p_acessaVoo = NULL;

    free(*pp_reserva);
    *pp_reserva = NULL;

    return 1;
}

/**
 * Busca reserva a partir do codigo da reserva (idReserva)
 * @param p_raizAgenda
 * @param idReserva
 * @return NULL
 * @return p_reservaEncontradaAgendaEsq
 * @return p_reservaEncontradaAgendaDir
 */
Reserva *busca_reserva_na_agenda_cod_reserva(Agenda *p_raizAgenda, int idReserva) {
    if (p_raizAgenda == NULL)
        return NULL;

    Reserva *p_acessaReserva;
    Agenda *p_acessaAgendaEsquerda;
    Agenda *p_acessaAgendaDireita;

    acessa_agenda(
            p_raizAgenda,
            &p_acessaReserva,
            &p_acessaAgendaEsquerda,
            &p_acessaAgendaDireita);

    if (p_acessaReserva->id == idReserva)
        return p_acessaReserva;

    Reserva *p_reservaEncontradaAgendaEsq = busca_reserva_na_agenda_cod_reserva(
            p_acessaAgendaEsquerda,
            idReserva);
    if (p_reservaEncontradaAgendaEsq != NULL) {
        return p_reservaEncontradaAgendaEsq;
    };

    Reserva *p_reservaEncontradaAgendaDir = busca_reserva_na_agenda_cod_reserva(
            p_acessaAgendaDireita,
            idReserva);
    if (p_reservaEncontradaAgendaDir != NULL) {
        return p_reservaEncontradaAgendaDir;
    };
}

Reserva *busca_reserva_na_agenda_cod_passageiro_cod_voo(
        Agenda *p_raizAgenda,
        int idPassageiro,
        int idVoo) {
    if (p_raizAgenda == NULL)
        return NULL;

    Reserva *p_acessaReserva;
    Agenda *p_acessaAgendaEsquerda;
    Agenda *p_acessaAgendaDireita;

    acessa_agenda(
            p_raizAgenda,
            &p_acessaReserva,
            &p_acessaAgendaEsquerda,
            &p_acessaAgendaDireita);

    int acessaId;
    Data *p_acessaData;
    Passageiro *p_acessaPassageiro;
    Voo *p_acessaVoo;
    CodigoAssento acessaAssento;

    acessa_reserva(
            p_acessaReserva,
            &acessaId,
            &p_acessaData,
            &p_acessaPassageiro,
            &p_acessaVoo,
            &acessaAssento);

    // TODO: Necessario acessa passageiro e voo
}

Reserva *busca_reserva_na_agenda_cod_passageiro_data_viagem(
        Agenda *p_raiz_agenda,
        int cod_passageiro,
        Data *p_data) {
    // TODO: NMecessario acessa passageiro
    return NULL;
}

// TODO: Necessario implementar busca_reserva_na_agenda_cod_passageiro_cod_voo e  busca_reserva_na_agenda_cod_passageiro_data_viagem
Reserva *busca_reserva_na_agenda(
        Agenda *p_agenda,
        int modo_busca,
        int cod_reserva,
        int cod_passageiro,
        int cod_voo,
        Data *p_data) {
    switch (modo_busca) {
        case 0:
            return NULL;
        case 1:
            return busca_reserva_na_agenda_cod_reserva(p_agenda, cod_reserva);
        case 2:
            return busca_reserva_na_agenda_cod_passageiro_cod_voo(p_agenda, cod_passageiro, cod_voo);
        case 3:
            return busca_reserva_na_agenda_cod_passageiro_data_viagem(p_agenda, cod_passageiro, p_data);
        default:
            return NULL;
    }
}

/**
 * Insere uma reserva na agenda retornando NULL caso a inserção nao seja concluída e retornando a reserva inserida caso seja inserida na agenda com sucesso
 * @param p_raizAgenda
 * @param p_reserva
 * @return p_reserva
 * @return NULL
 */
Reserva *insere_reserva(Agenda *p_raizAgenda, Reserva *p_reserva) {
    if (p_raizAgenda == NULL || p_reserva == NULL)
        return NULL;

    if (insere_agenda(p_raizAgenda, cria_agenda(p_reserva)) != NULL) {
        return p_reserva;
    } else {
        return NULL;
    }
}

