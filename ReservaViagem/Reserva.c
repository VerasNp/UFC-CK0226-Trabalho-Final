#include "Reserva.h"
#include "../Utils/Headers.h"
#include <stdio.h>
#include <stdlib.h>

struct reserva {
    int codigo;
    Data *p_data_viagem;
    Passageiro *p_passageiro;
    Voo *p_voo;
    CodigoAssento codigoAssento;
};

struct data {
    int dia;
    int mes;
    int ano;
};

Reserva *cria_reserva(Data *p_data_viagem,
                      Passageiro *p_passageiro,
                      Voo *p_voo,
                      CodigoAssento codigoAssento) {
    static int id;
    Reserva *p_reserva = (Reserva *) malloc(sizeof(Reserva));
    if (p_reserva == NULL)
        return NULL;

    p_reserva->codigo = ++id;
    p_reserva->p_data_viagem = p_data_viagem;
    p_reserva->p_passageiro = p_passageiro;
    p_reserva->p_voo = p_voo;
    p_reserva->codigoAssento = codigoAssento;

    return p_reserva;
}