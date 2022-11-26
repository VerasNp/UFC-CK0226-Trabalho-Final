#include "TabelaViagens.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define TAMANHO_TABELA 1001

struct reserva { // essa struct será importada de AgendaReservas.h ou Reservas.h (ATUALIZAR ISSO)
    int codigo;
    int codigoPassageiro;
};

/* Função quebra-galho, deve ser removida futuramente. */
int get_reserva_codigo_passageiro(Reserva *p_reserva) {
    if (p_reserva == NULL) return -1;
    return p_reserva->codigoPassageiro;
}

/* Função quebra-galho, deve ser removida futuramente. */
int get_reserva_codigo(Reserva *p_reserva) {
    if (p_reserva == NULL) return -1;
    return p_reserva->codigo;
}

/* Função quebra-galho, deve ser removida futuramente. */
Reserva *reserva_cria(int codigoReserva, int codigoPassageiro) {
    Reserva *p_reserva = malloc(sizeof(Reserva));
    if (p_reserva == NULL) return NULL;

    p_reserva->codigo = codigoReserva;
    p_reserva->codigoPassageiro = codigoPassageiro;
    return p_reserva;
}

/* Função quebra-galho, deve ser removida futuramente. */
int reserva_libera(Reserva *p_reserva) {
    if (p_reserva == NULL) return 0;
    free(p_reserva);
    return 1;
}


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
    NoViagem *anterior;
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

int viagem_libera(Viagem *p_viagem) {
    if (p_viagem == NULL) return 0;

    Trecho *p_trechos = p_viagem->trechos;

    while (p_trechos != NULL) {
        if (!reserva_libera(p_trechos->reserva)) return 0;
        Trecho *p_aux = p_trechos->proximo;
        free(p_trechos);
        p_trechos = p_aux;
    }
    
    free(p_viagem);
    return 1;
}

int no_viagem_libera(NoViagem *p_noViagem) {
    if (p_noViagem == NULL) return 1;

    while (p_noViagem != NULL) {
        if (!viagem_libera(p_noViagem->viagem)) {
            return 0;
        }
        NoViagem *p_aux = p_noViagem->proximo;
        free(p_noViagem);
        p_noViagem = p_aux;
    }
    return 1;
}

/* Libera a tabela de dispersão da memória. 1 se sucedido, 0 caso contrário. */
int tabela_libera(TabelaViagens *p_tabela) {
    for (int i=0; i < TAMANHO_TABELA; i++) {
        if (!no_viagem_libera(p_tabela->tabelaHash[i])) {
            return 0;
        }
    }

    free(p_tabela);
    return 1;
}

/* cria a tabela hash. */
TabelaViagens *tabela_cria(void) {
    TabelaViagens *p_tabela = malloc(sizeof(TabelaViagens));
    if (p_tabela == NULL) return NULL;

    NoViagem **pp_tabelaHash = malloc(sizeof(NoViagem *)* TAMANHO_TABELA);
    if (pp_tabelaHash == NULL) return NULL;

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        pp_tabelaHash[i] = NULL;
    }

    p_tabela->tabelaHash = pp_tabelaHash;
    p_tabela->tamanho = TAMANHO_TABELA;

    return p_tabela;
}

/* Recebe o código do passageiro e uma lista com todos os códigos de reserva de uma dada viagem e
retorna um índice da tabela no qual a Viagem foi/será armazenada. */
int tabela_indice(int codigoPassageiro, CodigosReservas *p_codigosReservas) {
    int indice = 0;
    int somatorioReservas = 0;
    int tamanhoCodigos = p_codigosReservas->tamanho;
    for (int i=0; i < tamanhoCodigos; i++) {
        int *p_codigos = p_codigosReservas->codigos;
        somatorioReservas += p_codigos[i];
    }
    somatorioReservas = somatorioReservas * (sqrt(5)-1) * 1000; //

    indice = (codigoPassageiro + somatorioReservas) % 1001;
    return indice;
}

/* Retorna o número de viagens acumulados em um índice. */
int tabela_tamanho_indice(TabelaViagens *p_tabela, int indice) {
    int tamanho = 0;
    NoViagem *p_noViagem = p_tabela->tabelaHash[indice];

    while (p_noViagem != NULL) {
        tamanho++;
        p_noViagem = p_noViagem->proximo;
    }
    return tamanho;
}

/* Insere a viagem no índice apropriado da tabela de dispersão. Retorna 1 se foi sucedida a 
inserção, 0 caso contrário. */
int tabela_insere_viagem(TabelaViagens *p_tabela, Viagem *p_viagem) {
    if (p_viagem == NULL) return 0;
    CodigosReservas *p_codigos = viagem_cria_lista_codigos_reservas(p_viagem);
    Reserva *p_reserva = p_viagem->trechos->reserva;
    if (p_reserva == NULL) return 0; // Retorna 0 em caso de erro.

    int codigoPassageiro = get_reserva_codigo_passageiro(p_reserva); // Essa função deve ser importada de AgendaReservas.h
    int indice = tabela_indice(codigoPassageiro, p_codigos);
    
    NoViagem *p_noAux = p_tabela->tabelaHash[indice];
    while (p_noAux != NULL) {
        if (viagem_compara(p_noAux->viagem, p_viagem)) return 0;
        p_noAux = p_noAux->proximo;
    }

    NoViagem *p_novoNoViagem = malloc(sizeof(NoViagem));
    if (p_novoNoViagem == NULL) return 0;

    p_novoNoViagem->proximo = p_tabela->tabelaHash[indice];
    p_novoNoViagem->viagem = p_viagem;
    p_novoNoViagem->anterior = NULL;

    if (p_novoNoViagem->proximo != NULL) {
        p_novoNoViagem->proximo->anterior = p_novoNoViagem;
    }
    p_tabela->tabelaHash[indice] = p_novoNoViagem;
    return 1;
}

/* Retorna o NoViagem caso a pesquisa seja sucedida, NULL se não encontrar uma Viagem com os códigos
especificados. */
NoViagem *tabela_pesquisa_no_viagem(TabelaViagens *p_tabela, int codigoPassageiro, CodigosReservas *p_codigosReservas) {
    if (p_tabela == NULL || codigoPassageiro < 0 || p_codigosReservas == NULL) return NULL;

    int indice = tabela_indice(codigoPassageiro, p_codigosReservas);
    NoViagem *p_noViagem = p_tabela->tabelaHash[indice];


    while (p_noViagem != NULL) {
        if (viagem_compara_codigo(p_noViagem->viagem, codigoPassageiro, p_codigosReservas)) return p_noViagem;
        p_noViagem = p_noViagem->proximo;
    }
    return NULL;
}

/* Retorna a Viagem caso a pesquisa seja sucedida, NULL se não encontrar uma Viagem com os códigos
especificados. */
Viagem *tabela_pesquisa_viagem(TabelaViagens *p_tabela, int codigoPassageiro, CodigosReservas *p_codigosReservas) {
    NoViagem *p_resultado = tabela_pesquisa_no_viagem(p_tabela, codigoPassageiro, p_codigosReservas);
    if (p_resultado == NULL) return NULL;

    return p_resultado->viagem;
}

/* Remove a viagem da tabela de dispersão. Retorna 1 se a remoção foi sucedida,, 0 caso contrário. */
int tabela_remove_viagem(TabelaViagens *p_tabela, Viagem *p_viagem) {
    int codigoPassageiro = get_viagem_codigo_passageiro(p_viagem);
    CodigosReservas *p_codigosReservas = viagem_cria_lista_codigos_reservas(p_viagem);

    NoViagem *p_noViagem = tabela_pesquisa_no_viagem(p_tabela, codigoPassageiro, p_codigosReservas);
    if (p_noViagem == NULL) return 0;

    if (p_noViagem->proximo != NULL) {
        p_noViagem->proximo->anterior = p_noViagem->anterior;
    }
    if (p_noViagem->anterior != NULL) {
        p_noViagem->anterior->proximo = p_noViagem->proximo;
        p_noViagem->anterior = NULL;
        p_noViagem->proximo = NULL;
        no_viagem_libera(p_noViagem);
        return 1;
    }

    // NoViagem era o primeiro nó da lista encadeada
    int indice = tabela_indice(codigoPassageiro, p_codigosReservas);

    if (p_noViagem->proximo == NULL) {
        p_tabela->tabelaHash[indice] = NULL;
        p_noViagem->anterior = NULL;
        p_noViagem->proximo = NULL;
        no_viagem_libera(p_noViagem);
        return 1;
    }

    p_tabela->tabelaHash[indice] = p_noViagem->proximo;
    p_noViagem->anterior = NULL;
    p_noViagem->proximo = NULL;
    no_viagem_libera(p_noViagem);
    return 1;
}

/* Função retorna o percentual de índices ocupados(com viagem) na tabela hash. */
float tabela_percentual_indices(TabelaViagens *p_tabela) {
    int contador = 0;
    for (int i=0; i < TAMANHO_TABELA; i++) {
        if (p_tabela->tabelaHash[i] != NULL) contador++;
    }
    return ((float) contador)/TAMANHO_TABELA;
}

/* Retorna o número da maior colisão/ocupação que ocorre na tabela. */
int tabela_maior_colisao(TabelaViagens *p_tabela) {
    int maior = 0;
    for (int i=0; i < TAMANHO_TABELA; i++) {
        int tmpMaior = 0;
        NoViagem *p_noViagem = p_tabela->tabelaHash[i];
        while (p_noViagem != NULL) {
            tmpMaior++;
            p_noViagem = p_noViagem->proximo;
        }
        if (tmpMaior > maior) maior = tmpMaior;
    }
    return maior;
}

/* Compara os códigos de passageiros e de cada reserva */
int viagem_compara(Viagem *p_viagem1, Viagem *p_viagem2) {
    if (p_viagem1 == NULL || p_viagem2 == NULL) return 0;

    Trecho *p_trecho1 = p_viagem1->trechos;
    Trecho *p_trecho2 = p_viagem2->trechos;

    while (p_trecho1 != NULL) {
        if (p_trecho2 == NULL) return 0; // Trecho2 é menor do que o trecho1. 
        Reserva *p_reserva1 = p_trecho1->reserva;
        Reserva *p_reserva2 = p_trecho2->reserva;
        
        int codigoReserva1 = get_reserva_codigo(p_reserva1);
        int codigoReserva2 = get_reserva_codigo(p_reserva2);
        int codigoPassageiro1 = get_reserva_codigo_passageiro(p_reserva1);
        int codigoPassageiro2 = get_reserva_codigo_passageiro(p_reserva2);

        if (codigoPassageiro1 != codigoPassageiro2 || codigoReserva1 != codigoReserva2) return 0;

        p_trecho1 = p_trecho1->proximo;
        p_trecho2 = p_trecho2->proximo;
    }
    if (p_trecho2 != NULL) return 0; // Trecho2 é maior do que o trecho1.  .
    return 1;
}

/* Compara os códigos de passageiros e de cada reserva */
int viagem_compara_codigo(Viagem *p_viagem, int codigoPassageiro, CodigosReservas *p_codigosReservas) {
    if (p_viagem == NULL || p_codigosReservas == NULL || codigoPassageiro < 0) return 0;

    Trecho *p_trecho = p_viagem->trechos;
    int tamanho = p_codigosReservas->tamanho;

    int i = 0;
    while (p_trecho != NULL) {
        if (i >= tamanho) return 0; // p_codigos é menor doq as reservas em viagem. 
        Reserva *p_reserva = p_trecho->reserva;
        
        int codigoReserva1 = get_reserva_codigo(p_reserva);
        int codigoReserva2 = p_codigosReservas->codigos[i];
        int codigoPassageiro1 = get_reserva_codigo_passageiro(p_reserva);
        int codigoPassageiro2 = codigoPassageiro;

        if (codigoPassageiro1 != codigoPassageiro2 || codigoReserva1 != codigoReserva2) return 0;

        p_trecho = p_trecho->proximo;
        i++;
    }
    if (i < tamanho) return 0; // Trecho2 é maior do que o trecho1.  .
    return 1;
}

/* Dado um vetor de Reserva, ordenado em relação à data, retorna o objeto Viagem. */
Viagem *viagem_cria(Reserva **pp_reservas, int numeroReservas) {

    if (pp_reservas == NULL || numeroReservas <= 0) return NULL;

    Viagem *p_viagem = malloc(sizeof(Viagem));
    Trecho *p_trecho = malloc(sizeof(Trecho));
    if (p_viagem == NULL || p_trecho == NULL) return NULL;

    // Mantém as reservas ordenadas em relação à data.
    p_viagem->trechos = NULL;
    for (int i=numeroReservas-1; i >= 0; i--) {
        Trecho *p_trecho = malloc(sizeof(Trecho));
        if (p_trecho == NULL) return NULL;

        p_trecho->proximo = p_viagem->trechos;
        p_trecho->reserva = pp_reservas[i];
        p_viagem->trechos = p_trecho;
    }
    return p_viagem;
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

/* Dada uma viagem, retorna o código do passageiro. */ 
int get_viagem_codigo_passageiro(Viagem *p_viagem) {
    Reserva *p_reserva = p_viagem->trechos->reserva;
    return get_reserva_codigo_passageiro(p_reserva);
}