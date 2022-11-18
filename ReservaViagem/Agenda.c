#include "Agenda.h"
#include <stdio.h>
#include <stdlib.h>

struct agenda {
    Reserva *p_reserva;
    Agenda *p_esquerda;
    Agenda *p_direita;
};

Agenda *cria_agenda(){
    Agenda *p_agenda = (Agenda*) malloc(sizeof (Agenda));
    if (p_agenda == NULL)
        return NULL;

    p_agenda->p_reserva = NULL;
    p_agenda->p_esquerda = NULL;
    p_agenda->p_direita = NULL;

    return p_agenda;
}