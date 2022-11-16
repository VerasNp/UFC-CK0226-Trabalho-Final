//
// Created by verasnp on 11/15/22.
//

#ifndef UFC_CK0226_TRABALHO_FINAL_TRAVELRESERVATION_H
#define UFC_CK0226_TRABALHO_FINAL_TRAVELRESERVATION_H
enum cod_assento {
    A0, B0, C0,
    A1, B1, C1,
    A2, B2, C2,
    A3, B3, C3,
    A4, B4, C4,
    A5, B5, C5,
    A6, B6, C6,
    A7, B7, C7,
    A8, B8, C8,
    A9, B9, C9
};

typedef enum cod_assento Assento;
typedef struct data Data;
typedef struct voo Voo;
typedef struct passageiro Passageiro;
typedef struct reserva Reserva;
typedef struct agenda Agenda;

Agenda *cria_agenda();
#endif //UFC_CK0226_TRABALHO_FINAL_TRAVELRESERVATION_H
