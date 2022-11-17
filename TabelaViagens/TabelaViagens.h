// #include "AgendaReservas.h"

// Placeholder para a struct
typedef struct reserva { // essa struct será importada de AgendaReservas.h ou Reservas.h (ATUALIZAR ISSO)
    int codigo;
} Reserva;

typedef struct tabela_viagens {
    int tamanho;
    NoViagem **tabelaHash;
} TabelaViagens;

typedef struct trecho {
    Reserva *reserva;
    struct trecho *proximo;
} Trecho;

typedef struct viagem {
    struct trecho *trechos;
} Viagem;

/* Necessário para lidar com conflitos na tabela de dispersão. */
typedef struct no_viagem {
    Viagem *viagem;
    Viagem *proximo;
} NoViagem;

/* Necessário para a função de hash, que retorna o respectivo índice de uma viagem. */
typedef struct lista_codigos_reservas {
    int tamanho;
    int *codigos;
} CodigosReservas;


/* cria a tabela hash. */
TabelaViagens *tabela_cria(void);

/* Recebe o código do passageiro e uma lista com todos os códigos de reserva de uma dada viagem e
retorna um índice da tabela no qual a Viagem foi/será armazenada. */
int tabela_indice(int codigoPassageiro, CodigosReservas *p_codigosReservas);

/* Insere a viagem no índice apropriado da tabela de dispersão. Retorna 1 se foi sucedida a 
inserção, 0 caso contrário. */
int tabela_insere_viagem(TabelaViagens *p_tabela, Viagem *p_viagem);

/* Remove a viagem da tabela de dispersão. Retorna 1 se a remoção foi sucedida,, 0 caso contrário. */
int tabela_remove_viagem(TabelaViagens *p_tabela, Viagem *p_viagem);

/* Atualiza a viagem na tabela de dispersão, retorna 1 se update sucedido, 0 caso contrário. */
int tabela_atualiza_viagem(TabelaViagens *p_tabela, Viagem *p_viagem);

/* Retorna a Viagem caso a pesquisa for sucedida, NULL se não encontrar uma Viagem com os códigos
especificados. */
Viagem *tabela_pesquisa_viagem(TabelaViagens *p_tabela, int codigoPassageiro, CodigosReservas *p_codigosReservas);

/* Dado um vetor de Reserva, retorna o objeto Viagem. */
Viagem *viagem_cria(Reserva **pp_reservas, int numeroReservas);

/* Printa o itinerário de uma viagem. */
void viagem_printa_itinerario(Viagem *p_viagem);

/* Recebe, via teclado, todos os códigos de reserva associado a algum passageiro e retorna a 
lista de códigos de reserva. Importante para a leitura da tabela hash.*/
CodigosReservas *cria_lista_codigos_reservas(void);

/* Dada uma viagem, retorna a lista encadeada com todos os códigos de reserva associados à viagem.
Importante para a inserção na tabela hash.*/
CodigosReservas *gera_lista_codigos_reservas(Viagem *p_viagem);