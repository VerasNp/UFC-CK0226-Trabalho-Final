#include "../Utils/Enums.h"
#include "../Utils/Headers.h"

/**
 * Criaçao individual de uma reserva.
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
        CodigoAssento codigoAssento);

/**
 * Libera espaço ocupado por determinada reserva.
 * @param pp_reserva
 * @return 0
 * @return 1
 */
int libera_reserva(Reserva **pp_reserva);

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
        CodigoAssento *p_acessaCodigoAssento);

/**
 * Busca reserva a partir do codigo da reserva (idReserva)
 * @param p_raizAgenda
 * @param idReserva
 * @return NULL
 * @return p_reservaEncontradaAgendaEsq
 * @return p_reservaEncontradaAgendaDir
 */
Reserva *busca_reserva_na_agenda_cod_reserva(
        Agenda *p_raizAgenda,
        int idReserva);

Reserva *busca_reserva_na_agenda(
        Agenda *p_agenda,
        int modo_busca,
        int cod_reserva,
        int cod_passageiro,
        int cod_voo,
        Data *p_data);

Reserva *busca_reserva_na_agenda_cod_passageiro_cod_voo(
        Agenda *p_raizAgenda,
        int idPassageiro,
        int idVoo);

Reserva *busca_reserva_na_agenda_cod_passageiro_data_viagem(
        Agenda *p_raiz_agenda,
        int cod_passageiro,
        Data *p_data);

Reserva *insere_reserva(Agenda *p_primeira_agenda, Reserva *p_reserva);

Reserva *remove_reserva(Reserva *p_reserva);

Reserva *edita_reserva(
        Reserva *p_reserva,
        Data *p_data_viagem,
        Passageiro **pp_passageiro,
        Voo **pp_voo,
        CodigoAssento *p_codigoAssento);

void ler_reserva(Reserva *p_reserva);


