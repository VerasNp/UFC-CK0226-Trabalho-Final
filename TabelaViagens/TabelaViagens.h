// #include "AgendaReservas.h"

// Placeholder para a struct
typedef struct reserva Reserva;

typedef struct trecho Trecho;

typedef struct viagem Viagem;

/* Necessário para lidar com conflitos na tabela de dispersão. */
typedef struct no_viagem NoViagem;

/* Necessário para a função de hash, que retorna o respectivo índice de uma viagem. */
typedef struct lista_codigos_reservas CodigosReservas;

typedef struct tabela_viagens TabelaViagens;

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

/* Libera a tabela de dispersão da memória. 1 se sucedido, 0 caso contrário. */
int tabela_libera(TabelaViagens *p_tabela);

/* Dado um vetor de Reserva, ordenado em relação à data, retorna o objeto Viagem. */
Viagem *viagem_cria(Reserva **pp_reservas, int numeroReservas);

/* Printa o itinerário de uma viagem. */
void viagem_printa_itinerario(Viagem *p_viagem);

/* Recebe, via teclado, todos os códigos de reserva associado a algum passageiro e retorna a 
lista de códigos de reserva. Importante para a leitura da tabela hash.*/
CodigosReservas *teclado_cria_lista_codigos_reservas(void);

/* Recebe, via vetor, todos os códigos de reserva associado a algum passageiro e retorna a 
lista de códigos de reserva. Importante para a leitura da tabela hash.*/
CodigosReservas *vetor_cria_lista_codigos_reservas(int *p_codigos, int tamanho);

/* Dada uma viagem, retorna a lista encadeada com todos os códigos de reserva associados à viagem.
Importante para a inserção na tabela hash.*/
CodigosReservas *viagem_cria_lista_codigos_reservas(Viagem *p_viagem);

int get_tamanho_tabela(TabelaViagens *p_tabela);

NoViagem **get_tabela_hash(TabelaViagens *p_tabela);

int get_tamanho_codigos_reservas(CodigosReservas *p_codigos);
int *get_vetor_codigos_reservas(CodigosReservas *p_codigos);
Trecho *get_trecho_viagem(Viagem *p_viagem);
Reserva *get_reserva_trecho(Trecho *p_trecho);
Trecho *get_proximo_trecho(Trecho *p_trecho);
Viagem *get_viagem(NoViagem *p_noViagem);
NoViagem *get_proximo_no_viagem(NoViagem *p_noViagem);