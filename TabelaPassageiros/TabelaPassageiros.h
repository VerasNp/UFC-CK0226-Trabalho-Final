#include "../ListaPassageiros/Passageiro.h"

typedef struct no_passageiro NoPassageiro;
typedef struct tabela_passageiros TabelaPassageiros;

TabelaPassageiros *cria_tabela_passageiros();

int tabela_passageiros_indice(Passageiro *p_passageiro);

int compara_no_passageiro(NoPassageiro *p_noPassageiro1, NoPassageiro *p_noPassageiro2);
NoPassageiro *pesquisa_tabela_passageiros(TabelaPassageiros *p_tabela, Passageiro *p_passageiro);

int insere_tabela_passageiros(TabelaPassageiros *p_tabela, Passageiro *p_passageiro);

int no_passageiro_libera(NoPassageiro *p_noPassageiro);

int remove_tabela_passageiro(TabelaPassageiros *p_tabela, Passageiro *p_passageiro);

int tabela_passageiros_libera(TabelaPassageiros *p_tabela);

int get_no_passageiro_numero_viagens(NoPassageiro *p_noPassageiro);

