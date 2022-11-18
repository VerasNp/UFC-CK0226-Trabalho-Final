#ifndef UFC_CK0226_TRABALHO_FINAL_RESERVA_H
#define UFC_CK0226_TRABALHO_FINAL_RESERVA_H
#include "../Utils/Enums.h"

typedef struct reserva Reserva;
typedef struct passageiro Passageiro;
typedef struct voo Voo;

/**
 *
 * @param p_data_viagem
 * @param p_passageiro
 * @param p_voo
 * @param codigoAssento
 * @return
 */
Reserva *cria_reserva(
        Passageiro *p_passageiro,
        Voo *p_voo,
        CodigoAssento codigoAssento);

//Reserva *insere_reserva(
//        int codigo,
//        Data *p_data_viagem,
//        Passageiro *p_passageiro,
//        Voo *p_voo,
//        Assento assento);

#endif //UFC_CK0226_TRABALHO_FINAL_RESERVA_H
