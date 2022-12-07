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
    static int i;
    if (pp_agenda == NULL && i == 0)
        return 0;
    else if(*pp_agenda != NULL){
        i++; 
        libera_agenda(&((*pp_agenda)->p_esquerda)); 
        libera_agenda(&((*pp_agenda)->p_direita));
        libera_reserva(((*pp_agenda)->p_reserva), 0);
        free(*pp_agenda);
        pp_agenda = NULL;
        return 1;
    }

   return 1;
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

Agenda *minimo(Agenda *p_raizAgenda) {
    if ((*(p_raizAgenda)).p_esquerda == NULL) {
        return p_raizAgenda;
    } else {
        return minimo((*(p_raizAgenda)).p_esquerda);
    }
}

int remove_agenda(Agenda *p_raizAgenda,Agenda *p_raizAgendaPai, Reserva *p_reserva) { // p_raizAgendaPai na primeira chamada será NULL
    if (p_raizAgenda == NULL)
        return 0;

    int acessaIdReservaRaizAgenda;
    Data *p_acessaDataReservaRaizAgenda;
    Passageiro *p_acessaPassageiroReservaRaizAgenda;
    Voo *p_acessaVooReservaRaizAgenda;
    CodigoAssento acessaAssentoReservaRaizAgenda;
    acessa_reserva(
            (*(p_raizAgenda)).p_reserva,
            &acessaIdReservaRaizAgenda,
            &p_acessaDataReservaRaizAgenda,
            &p_acessaPassageiroReservaRaizAgenda,
            &p_acessaVooReservaRaizAgenda,
            &acessaAssentoReservaRaizAgenda);

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

    if (comparar_datas(p_acessaData, p_acessaDataReservaRaizAgenda) < 0)
        remove_agenda((*(p_raizAgenda)).p_esquerda,p_raizAgenda, p_reserva);

    else if (comparar_datas(p_acessaData, p_acessaDataReservaRaizAgenda) > 0)
        remove_agenda((*(p_raizAgenda)).p_direita,p_raizAgenda, p_reserva);

    else {
        if (acessaId == acessaIdReservaRaizAgenda) {
            if ((*(p_raizAgenda)).p_esquerda == NULL) {
                if((*(p_raizAgendaPai)).p_direita == p_raizAgenda){ 
                    p_raizAgendaPai->p_direita = p_raizAgenda->p_direita;
                }
                else{ 
                    p_raizAgendaPai->p_esquerda = p_raizAgenda->p_direita; 
                }
                p_raizAgenda->p_direita = NULL; 
                libera_agenda(&p_raizAgenda);
                return 1;
            } else if((*(p_raizAgenda)).p_direita == NULL) {
                if (p_raizAgendaPai->p_direita == p_raizAgenda){ 
                    p_raizAgendaPai->p_direita = p_raizAgenda->p_esquerda; 
                }
                else{ 
                    p_raizAgendaPai->p_esquerda = p_raizAgenda->p_direita; 
                }
                p_raizAgenda->p_esquerda = NULL; 
                libera_agenda(&p_raizAgenda);
                return 1;
            }
            else{ 
                Agenda *temp = p_raizAgenda->p_direita;
                Agenda *aux = NULL;
                while(temp->p_esquerda != NULL){ 
                    aux = temp; 
                    temp = temp->p_esquerda; 
                }
                if (p_raizAgenda->p_direita != temp){
                    aux->p_esquerda = temp->p_direita; 
                    temp->p_direita = p_raizAgenda->p_direita;
                }

                if (p_raizAgendaPai->p_direita == p_raizAgenda){ 
                    p_raizAgendaPai->p_direita = temp; 
                }
                else p_raizAgendaPai->p_esquerda = p_raizAgenda; {
                    p_raizAgendaPai->p_esquerda = temp; 
                }
                temp->p_esquerda = p_raizAgenda->p_esquerda; 
                p_raizAgenda->p_direita = NULL; 
                p_raizAgenda->p_esquerda = NULL; 
                libera_agenda(&p_raizAgenda);  
                return 1; 
            }
        }
        else remove_agenda((*(p_raizAgenda)).p_esquerda, p_raizAgenda,p_reserva);
    }
}