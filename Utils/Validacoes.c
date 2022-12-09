//
// Created by verasnp on 11/20/22.
//

#include "stdio.h"
#include "Validacoes.h"
#include "Data.h"
#include "Reserva.h"

int valida_intervalo_datas(Agenda *p_agenda, Reserva *p_reserva) {
    Data *p_reservaDataPartida = get_reserva_data_partida(p_reserva);
    Data *p_reservaDataChegada = get_reserva_data_chegada(p_reserva);

    Reserva *p_reservaProcurada =
            busca_reserva_na_agenda_cod_passageiro_data_viagem(p_agenda, get_reserva_codigo_passageiro(p_reserva),
                                                               p_reservaDataPartida, p_reservaDataChegada);

    if (p_reservaProcurada == NULL) {
        return 1;
    } else {
        Data *p_reservaProcuradaDataPartida = get_reserva_data_partida(p_reservaProcurada);
        Data *p_reservaProcuradaDataChegada = get_reserva_data_chegada(p_reservaProcurada);

        if (
                comparar_datas(p_reservaDataPartida, p_reservaProcuradaDataPartida) < 0 &&
                comparar_datas(p_reservaProcuradaDataPartida, p_reservaDataChegada) < 0 &&
                comparar_datas(p_reservaProcuradaDataChegada, p_reservaDataChegada) > 0) {
            return 0;
        } else if (
                comparar_datas(p_reservaDataPartida, p_reservaProcuradaDataPartida) > 0 &&
                comparar_datas(p_reservaDataPartida, p_reservaProcuradaDataChegada) < 0 &&
                comparar_datas(p_reservaDataChegada, p_reservaProcuradaDataChegada) > 0) {
            return 0;
        } else if (
                comparar_datas(p_reservaDataPartida, p_reservaProcuradaDataPartida) < 0 &&
                comparar_datas(p_reservaDataChegada, p_reservaProcuradaDataChegada) > 0
                ) {
            return 0;
        } else if (
                comparar_datas(p_reservaDataPartida, p_reservaProcuradaDataPartida) > 0 &&
                comparar_datas(p_reservaDataChegada, p_reservaProcuradaDataChegada) < 0
                ) {
            return 0;
        } else if (comparar_datas(p_reservaDataPartida, p_reservaProcuradaDataPartida) == 0){
            return 0;
        } else return 1;
    }
}

