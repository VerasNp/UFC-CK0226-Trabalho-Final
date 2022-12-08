#include "../Utils/Headers.h"
#include "Data.h"
#include "Reserva.h"
#include "Agenda.h"
#include "../ListaPassageiros/Passageiro.h"
#include "../ListaVoos/Voos.h"
#include "../TabelaViagens/TabelaViagens.h"
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
int libera_reserva(Reserva *p_reserva, int podeLiberarPassageiro) {
    if (p_reserva == NULL)
        return 1;

//     É preciso saber se existe outras reservas ativas com o passageiro para decidir se libera ou não o passageiro.
    if (podeLiberarPassageiro) {
        if(!passageiro_libera(p_reserva->p_passageiro)) return 0;
    }

    if(!libera_data(p_reserva->p_data)) return 0;
    if(!libera_voo(p_reserva->p_voo)) return 0;
    free(p_reserva);
    p_reserva = NULL;
    return 1;
}

/**
 * Busca reserva a partir do codigo da reserva (idReserva)
 * @param p_raizAgenda
 * @param idReserva
 * @return NULL
 * @return p_reservaEncontradaAgendaEsq
 * @return p_reservaEncontradaAgendaDir
 * @return p_acessaReserva
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

    int p_acessaIdVoo;
    char *p_acessaOrigemVoo = (char *)malloc(sizeof(char)*300);
    char *p_acessaDestinoVoo = (char *)malloc(sizeof(char)*300);
    leitura_voo(
            p_acessaVoo,
            &p_acessaIdVoo,
            p_acessaOrigemVoo,
            p_acessaDestinoVoo);

    int p_acessaIdPassageiro;
    char *p_acessaNomePassageiro = (char *)malloc(sizeof(char)*300);
    char *p_acessaEnderecoPassageiro = (char *)malloc(sizeof(char)*300);
    passageiro_acessa(
            p_acessaPassageiro,
            &p_acessaIdPassageiro,
            p_acessaNomePassageiro,
            p_acessaEnderecoPassageiro);

    if (p_acessaIdPassageiro == idPassageiro && p_acessaIdVoo == idVoo)
        return p_acessaReserva;

    Reserva *p_reservaEncontradaAgendaEsq = busca_reserva_na_agenda_cod_passageiro_cod_voo(
            p_acessaAgendaEsquerda,
            idPassageiro,
            idVoo);
    if (p_reservaEncontradaAgendaEsq != NULL) {
        return p_reservaEncontradaAgendaEsq;
    };

    Reserva *p_reservaEncontradaAgendaDir = busca_reserva_na_agenda_cod_passageiro_cod_voo(
            p_acessaAgendaDireita,
            idPassageiro,
            idVoo);
    if (p_reservaEncontradaAgendaDir != NULL) {
        return p_reservaEncontradaAgendaDir;
    };
}

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
        Data *p_data) {
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

    int p_acessaIdPassageiro;
    char *p_acessaNomePassageiro = (char *)malloc(sizeof(char)*300);
    char *p_acessaEnderecoPassageiro = (char *)malloc(sizeof(char)*300);
    passageiro_acessa(
            p_acessaPassageiro,
            &p_acessaIdPassageiro,
            p_acessaNomePassageiro,
            p_acessaEnderecoPassageiro);

    if (p_acessaIdPassageiro == idPassageiro && comparar_datas(p_acessaData, p_data) == 0)
        return p_acessaReserva;

    Reserva *p_reservaEncontradaAgendaEsq = busca_reserva_na_agenda_cod_passageiro_data_viagem(
            p_acessaAgendaEsquerda,
            idPassageiro,
            p_data);
    if (p_reservaEncontradaAgendaEsq != NULL) {
        return p_reservaEncontradaAgendaEsq;
    };

    Reserva *p_reservaEncontradaAgendaDir = busca_reserva_na_agenda_cod_passageiro_data_viagem(
            p_acessaAgendaDireita,
            idPassageiro,
            p_data);
    if (p_reservaEncontradaAgendaDir != NULL) {
        return p_reservaEncontradaAgendaDir;
    };
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
        CodigoAssento codigoAssento) {
    if (p_reserva == NULL || p_dataViagem == NULL || (codigoAssento < 0 || codigoAssento > C9))
        return NULL;

    (*(p_reserva)).p_data = p_dataViagem;
    (*(p_reserva)).codigoAssento = codigoAssento;

    return p_reserva;
}

/**
 * Lê dados de uma reserva e os exibe na tela
 * @param p_reserva
 * @return NULL
 */
char* ler_reserva(Reserva *p_reserva) {
    if (p_reserva == NULL)
        return NULL;

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

    int p_acessaIdVoo;
    char *p_acessaOrigemVoo = (char *)malloc(sizeof(char)*300);
    char *p_acessaDestinoVoo = (char *)malloc(sizeof(char)*300);
    leitura_voo(
            p_acessaVoo,
            &p_acessaIdVoo,
            p_acessaOrigemVoo,
            p_acessaDestinoVoo);

    int p_acessaIdPassageiro;
    char *p_acessaNomePassageiro = (char *)malloc(sizeof(char)*300);
    char *p_acessaEnderecoPassageiro = (char *)malloc(sizeof(char)*300);
    passageiro_acessa(
            p_acessaPassageiro,
            &p_acessaIdPassageiro,
            p_acessaNomePassageiro,
            p_acessaEnderecoPassageiro);

    int dia;
    int mes;
    int ano;
    acessa_data(
            p_acessaData,
            &dia,
            &mes,
            &ano);

    printf("Código da reserva: %d \n", acessaId);
    printf("Data da reserva: %d/%d/%d \n", dia, mes, ano);
    printf("Dados do passageiro:\n");
    printf("\tCódigo: %d\n", p_acessaIdPassageiro);
    printf("\tNome: %s\n", p_acessaNomePassageiro);
    printf("\tEndereço: %s\n", p_acessaEnderecoPassageiro);
    printf("Dados do voo:\n");
    printf("\tCódigo: %d\n", p_acessaIdVoo);
    printf("\tOrigem: %s\n", p_acessaOrigemVoo);
    printf("\tDestino: %s\n", p_acessaDestinoVoo);
}

/* Retorna o id da reserva. */
int get_reserva_codigo(Reserva *p_reserva) {
    return p_reserva->id;
}

/* Retorna o id do passageiro. */
int get_reserva_codigo_passageiro(Reserva *p_reserva) {
    return get_passageiro_codigo(p_reserva->p_passageiro);
}

Passageiro *get_reserva_passageiro(Reserva *p_reserva) {
    return p_reserva->p_passageiro;
}

int cria_roteiro_viagem(ListaVoo *p_listaVoo, TabelaViagens *p_tabelaViagens);