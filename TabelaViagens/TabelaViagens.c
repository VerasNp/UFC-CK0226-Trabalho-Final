#include "TabelaViagens.h"
#include <stdlib.h>
#include <stdio.h>

#define TAMANHO_TABELA 1000

struct reserva { // essa struct será importada de AgendaReservas.h ou Reservas.h (ATUALIZAR ISSO)
    int codigo;
};

struct trecho {
    Reserva *reserva;
    struct trecho *proximo;
};

struct viagem {
    struct trecho *trechos;
};

/* Necessário para lidar com conflitos na tabela de dispersão. */
struct no_viagem {
    Viagem *viagem;
    NoViagem *proximo;
};

/* Necessário para a função de hash, que retorna o respectivo índice de uma viagem. */
struct lista_codigos_reservas {
    int tamanho;
    int *codigos;
};

struct tabela_viagens {
    int tamanho;
    NoViagem **tabelaHash;
};


/* cria a tabela hash. */
TabelaViagens *tabela_cria(void) {
    TabelaViagens *p_tabela = malloc(sizeof(TabelaViagens));
    if (p_tabela == NULL) return NULL;

    NoViagem **pp_tabelaHash = malloc(sizeof(NoViagem *)* TAMANHO_TABELA);
    if (pp_tabelaHash == NULL) return NULL;

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        NoViagem *p_noViagem = malloc(sizeof(NoViagem));
        if (p_noViagem == NULL) return NULL;
        p_noViagem->proximo = NULL;
        p_noViagem->viagem = NULL;

        pp_tabelaHash[i] = p_noViagem;
    }

    p_tabela->tabelaHash = pp_tabelaHash;
    p_tabela->tamanho = TAMANHO_TABELA;

    return p_tabela;
}

/* Dada uma viagem, retorna a lista encadeada com todos os códigos de reserva associados à viagem.
Importante para a inserção na tabela hash.*/
CodigosReservas *viagem_cria_lista_codigos_reservas(Viagem *p_viagem) {
    CodigosReservas *p_codigosReservas = malloc(sizeof(CodigosReservas));
    if (p_codigosReservas == NULL) return NULL;

    int tamanho = 5;
    int *p_listaCodigos = malloc(sizeof(int)*tamanho);
    if (p_listaCodigos == NULL) return NULL;

    Trecho *p_trechoAux = p_viagem->trechos;

    int i = 0;
    // Itera até o fim da lista encadeada.
    while (p_trechoAux != NULL) {
        // vetor cheio.
        if (i == tamanho - 1) {
            tamanho = tamanho * 2;
            p_listaCodigos = realloc(p_listaCodigos, tamanho);
        }
        p_listaCodigos[i++] = p_trechoAux->reserva->codigo;
        p_trechoAux = p_trechoAux->proximo;
    }

    p_codigosReservas->codigos = p_listaCodigos;
    p_codigosReservas->tamanho = i;

    return p_codigosReservas;
}

/* Recebe, via teclado, todos os códigos de reserva associado a algum passageiro e retorna a 
lista de códigos de reserva. Importante para a leitura da tabela hash.*/
CodigosReservas *teclado_cria_lista_codigos_reservas(void) {
    CodigosReservas *p_codigosReservas = malloc(sizeof(CodigosReservas));
    if (p_codigosReservas == NULL) return NULL;

    int tamanho = 5;
    int *p_listaCodigos = malloc(sizeof(int)*tamanho);
    if (p_listaCodigos == NULL) return NULL;
    int codigo = 0;
    int i = 0;

    printf("Insira os códigos de reserva. insira qualquer número negativo para terminar.\n");
    while (codigo >= 0) {
        printf("reserva %d: \n", (i+1));
        scanf("%d", &codigo);
        if (i = tamanho + 1) {
            tamanho = tamanho * 2;
            p_listaCodigos = realloc(p_listaCodigos, tamanho);
        }
        p_listaCodigos[i++] = codigo;
    }
    p_codigosReservas->codigos = p_listaCodigos;
    p_codigosReservas->tamanho = i;

    return p_codigosReservas;
}

/* Recebe, via vetor, todos os códigos de reserva associado a algum passageiro e retorna a 
lista de códigos de reserva. Importante para a leitura da tabela hash.*/
CodigosReservas *vetor_cria_lista_codigos_reservas(int *p_codigos, int tamanho) {
    if (p_codigos == NULL || tamanho <= 0) return NULL;

    CodigosReservas *p_codigosReservas = malloc(sizeof(CodigosReservas));
    if (p_codigosReservas == NULL) return NULL;

    p_codigosReservas->codigos = p_codigos;
    p_codigosReservas->tamanho = tamanho;

    return p_codigosReservas;
}

int get_tamanho_tabela(TabelaViagens *p_tabela) {
    if (p_tabela == NULL) return -1;
    return p_tabela->tamanho;
}

NoViagem **get_tabela_hash(TabelaViagens *p_tabela) {
    if (p_tabela == NULL) return NULL;
    return p_tabela->tabelaHash;
}

int get_tamanho_codigos_reservas(CodigosReservas *p_codigos) {
    if (p_codigos == NULL) return -1;
    return p_codigos->tamanho;
}

int *get_vetor_codigos_reservas(CodigosReservas *p_codigos) {
    if (p_codigos == NULL) return NULL;
    return p_codigos->codigos;
}

Trecho *get_trecho_viagem(Viagem *p_viagem) {
    if (p_viagem == NULL) return NULL;
    return p_viagem->trechos;
}

Reserva *get_reserva_trecho(Trecho *p_trecho) {
    if (p_trecho == NULL) return NULL;
    return p_trecho->reserva;
}

Trecho *get_proximo_trecho(Trecho *p_trecho) {
    if (p_trecho == NULL) return NULL;
    return p_trecho->proximo;
}

Viagem *get_viagem(NoViagem *p_noViagem) {
    if (p_noViagem == NULL) return NULL;
    return p_noViagem->viagem;
}

NoViagem *get_proximo_no_viagem(NoViagem *p_noViagem) {
    if (p_noViagem == NULL) return NULL;
    return p_noViagem->proximo;
}
