#include "../ListaPassageiros/Passageiro.h"
#include "TabelaPassageiros.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct no_passageiro {
    int codigoPassageiro;
    int numeroViagens;
    NoPassageiro *proximo;
    NoPassageiro *anterior;
};

struct tabela_passageiros {
    int tamanho;
    NoPassageiro **tabelaHash;
};

#define TAMANHO_TABELA_PASSAGEIROS 1001

TabelaPassageiros *cria_tabela_passageiros() {
    TabelaPassageiros *p_tabelaPassageiros = malloc(sizeof(TabelaPassageiros));
    if (p_tabelaPassageiros == NULL) return NULL;

    p_tabelaPassageiros->tamanho = TAMANHO_TABELA_PASSAGEIROS;
    NoPassageiro **pp_tabelaHash = malloc(sizeof(NoPassageiro *) * TAMANHO_TABELA_PASSAGEIROS);
    if (pp_tabelaHash == NULL) return NULL;

    for (int i=0; i < TAMANHO_TABELA_PASSAGEIROS; i++) {
        pp_tabelaHash[i] = NULL;
    }
    p_tabelaPassageiros->tabelaHash = pp_tabelaHash;
    return p_tabelaPassageiros;
}

int tabela_passageiros_indice(Passageiro *p_passageiro) {
    int codigo = get_passageiro_codigo(p_passageiro);
    int indice = codigo * (sqrt(5) - 1) * 1000;

    return indice % 1001;
}

int compara_no_passageiro(NoPassageiro *p_noPassageiro1, NoPassageiro *p_noPassageiro2) {
    return (p_noPassageiro1->codigoPassageiro == p_noPassageiro2->codigoPassageiro);
}

NoPassageiro *pesquisa_tabela_passageiros(TabelaPassageiros *p_tabela, Passageiro *p_passageiro) {
    int codigoPassageiro = get_passageiro_codigo(p_passageiro);
    int indice = tabela_passageiros_indice(p_passageiro);

    if (p_tabela->tabelaHash[indice] != NULL) {
        NoPassageiro *p_noPassageiroAux = p_tabela->tabelaHash[indice];
        while (p_noPassageiroAux != NULL) {
            if (p_noPassageiroAux->codigoPassageiro == codigoPassageiro) return p_noPassageiroAux;
            p_noPassageiroAux = p_noPassageiroAux->proximo;
        }
    }
    return NULL;
}

int insere_tabela_passageiros(TabelaPassageiros *p_tabela, Passageiro *p_passageiro) {
    if (p_passageiro == NULL || p_tabela == NULL) return 0;

    // Verifica se o passageiro já está na tabela e incrementa o número de viagens.
    NoPassageiro *p_noPassageiroResultado = pesquisa_tabela_passageiros(p_tabela, p_passageiro);

    if (p_noPassageiroResultado != NULL) {
        p_noPassageiroResultado->numeroViagens++;
        return 1;
    }

    NoPassageiro *p_noPassageiro = malloc(sizeof(NoPassageiro));
    p_noPassageiro->codigoPassageiro = get_passageiro_codigo(p_passageiro);
    p_noPassageiro->numeroViagens = 1;
    p_noPassageiro->anterior = NULL;
    int indice = tabela_passageiros_indice(p_passageiro);


    if (p_tabela->tabelaHash[indice] != NULL) {
        p_tabela->tabelaHash[indice]->anterior = p_noPassageiro;
        p_noPassageiro->proximo = p_tabela->tabelaHash[indice];
    } else {
        p_noPassageiro->proximo = NULL;
    }
    p_tabela->tabelaHash[indice] = p_noPassageiro;
    return 1;
}

int no_passageiro_libera(NoPassageiro *p_noPassageiro) {
    if (p_noPassageiro == NULL) return 1;

    no_passageiro_libera(p_noPassageiro->proximo);
    no_passageiro_libera(p_noPassageiro->anterior);
    free(p_noPassageiro);
    return 1;
}

int remove_tabela_passageiro(TabelaPassageiros *p_tabela, Passageiro *p_passageiro) {
    if (p_tabela == NULL || p_passageiro == NULL) return 0;

    NoPassageiro *p_noPassageiroResultado = pesquisa_tabela_passageiros(p_tabela, p_passageiro);

    if (p_noPassageiroResultado == NULL) return 0;

    if (p_noPassageiroResultado->numeroViagens == 1) {
        int indice = tabela_passageiros_indice(p_passageiro);

        p_tabela->tabelaHash[indice] = p_noPassageiroResultado->proximo;
        no_passageiro_libera(p_noPassageiroResultado);
        return 1;
    }


    p_noPassageiroResultado->numeroViagens--;
    return 1;
}

int tabela_passageiros_libera(TabelaPassageiros *p_tabela) {
    for (int i=0; i < TAMANHO_TABELA_PASSAGEIROS; i++) {
        if (!no_passageiro_libera(p_tabela->tabelaHash[i])) return 0;
    }
    free(p_tabela);
    return 1;
}

int get_no_passageiro_numero_viagens(NoPassageiro *p_noPassageiro) {
    if (p_noPassageiro == NULL) return -1;
    return p_noPassageiro->numeroViagens;
}