#include "../ListaPassageiros/Passageiro.h"
#include "TabelaPassageiros.h"
#include "../Utils/Utils.h"
#include <stdio.h>

void testa_insere_tabela_passageiro() {
    printf("Testando insere_tabela_passageiro()...\n");
    TabelaPassageiros *p_tabela = cria_tabela_passageiros();

    Passageiro *p_passageiro1 = passageiro_cria("Bruno", "Caucaia");

    print_teste(insere_tabela_passageiros(p_tabela, p_passageiro1), "insere_tabela_passageiro() - teste 1: insere corretamente.");

    int numeroViagensP1 = get_no_passageiro_numero_viagens(pesquisa_tabela_passageiros(p_tabela, p_passageiro1));
    print_teste(numeroViagensP1 == 1, "insere_tabela_passageiro() - teste 2: passageiro 1 com 1 viagem.");

    insere_tabela_passageiros(p_tabela, p_passageiro1);
    insere_tabela_passageiros(p_tabela, p_passageiro1);
    NoPassageiro *p_noPassageiro = pesquisa_tabela_passageiros(p_tabela, p_passageiro1);

    numeroViagensP1 = get_no_passageiro_numero_viagens(pesquisa_tabela_passageiros(p_tabela, p_passageiro1));
    print_teste(numeroViagensP1 == 3, "insere_tabela_passageiro() - teste 3: passageiro 1 com 3 viagens.");

    insere_tabela_passageiros(p_tabela, p_passageiro1);

    /* REMOÇÃO */
    printf("Testando remove_tabela_passageiro()...\n");
    print_teste(remove_tabela_passageiro(p_tabela, p_passageiro1), "remove_tabela_passageiro() - teste 1: remove passageiro com sucesso");

    print_teste(get_no_passageiro_numero_viagens(p_noPassageiro) == 3, "remove_tabela_passageiro() - teste 2: Número de viagens decrementado corretamente.");
    print_teste(remove_tabela_passageiro(p_tabela, p_passageiro1), "remove_tabela_passageiro() - teste 3: remove passageiro com sucesso");
    print_teste(remove_tabela_passageiro(p_tabela, p_passageiro1), "remove_tabela_passageiro() - teste 4: remove passageiro com sucesso");
    print_teste(remove_tabela_passageiro(p_tabela, p_passageiro1), "remove_tabela_passageiro() - teste 5: remove o último passageiro");
    print_teste(pesquisa_tabela_passageiros(p_tabela, p_passageiro1) == NULL, "remove_tabela_passageiro() - teste 6: passageiro removido não encontrado.");

    /* Libera */
    printf("Testando tabela_passageiros_libera()...\n");
    Passageiro *p_passageiro2 = passageiro_cria("Bruno", "Caucaia");
    Passageiro *p_passageiro3 = passageiro_cria("Jota", "Caucaia");
    Passageiro *p_passageiro4 = passageiro_cria("Carto", "Caucaia");
    Passageiro *p_passageiro5 = passageiro_cria("Gabriela", "Caucaia");

    insere_tabela_passageiros(p_tabela, p_passageiro2);
    insere_tabela_passageiros(p_tabela, p_passageiro3);
    insere_tabela_passageiros(p_tabela, p_passageiro4);
    insere_tabela_passageiros(p_tabela, p_passageiro5);

    print_teste(tabela_passageiros_libera(p_tabela), "tabela_passageiros_libera()");
}





void main() {
    testa_insere_tabela_passageiro();
}