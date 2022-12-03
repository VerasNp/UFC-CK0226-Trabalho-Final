#include "../Utils/Enums.h"

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
int libera_reserva(Reserva *p_reserva, int passageiroJaLiberado);

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
 * @return p_acessaReserva
 */
Reserva *busca_reserva_na_agenda_cod_reserva(
        Agenda *p_raizAgenda,
        int idReserva);

/**
 * Busca uma reserva baseado nos dados de código do passageiro e voo. Retorna NULL caso não encontre e a reserva caso a encontre
 * @param p_raizAgenda
 * @param idPassageiro
 * @param idVoo
 * @return NULL
 * @return p_reservaEncontradaAgendaEsq
 * @return p_reservaEncontradaAgendaDir
 * @return p_acessaReserva
 */
Reserva *busca_reserva_na_agenda_cod_passageiro_cod_voo(
        Agenda *p_raizAgenda,
        int idPassageiro,
        int idVoo);

/**
 * Busca reserva baseando-se no código do passageiro e data da reserva, retorna NULL caso não seja encontrado e a reserva caso seja achado
 * @param p_raizAgenda
 * @param idPassageiro
 * @param p_data
 * @return NULL
 * @return p_reservaEncontradaAgendaEsq
 * @return p_reservaEncontradaAgendaDir
 * @return p_acessaReserva
 */
Reserva *busca_reserva_na_agenda_cod_passageiro_data_viagem(
        Agenda *p_raizAgenda,
        int idPassageiro,
        Data *p_data);

/**
 * Insere uma reserva na agenda retornando NULL caso a inserção nao seja concluída e retornando a reserva inserida caso seja inserida na agenda com sucesso
 * @param p_raizAgenda
 * @param p_reserva
 * @return p_reserva
 * @return NULL
 */
Reserva *insere_reserva(Agenda *p_raizAgenda, Reserva *p_reserva);

/**
 * Edita valores de data e assento da reserva.
 * Retorna NULL caso ou a reserva ou data ou código do assento tenha valor nulo e retorna o valor novo da reserva com os valores atualizados caso tudo ocorra corretamente
 * @param p_reserva
 * @param p_dataViagem
 * @param codigoAssento
 * @return NULL
 * @return p_reserva
 */
Reserva *edita_reserva(
        Reserva *p_reserva,
        Data *p_dataViagem,
        CodigoAssento codigoAssento);

/**
 * Lê dados de uma reserva e os exibe na tela
 * @param p_reserva
 * @return NULL
 */
char* ler_reserva(Reserva *p_reserva);

/* Retorna o id da reserva. */
int get_reserva_codigo(Reserva *p_reserva);

/* Retorna o id do passageiro. */
int get_reserva_codigo_passageiro(Reserva *p_reserva);