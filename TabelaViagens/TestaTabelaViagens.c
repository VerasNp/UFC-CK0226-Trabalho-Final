#include <stdio.h>
#include "TabelaViagens.h"

void print_teste(int r, char texto[]) {
    if (r) printf("   [SUCESSO] %s\n", texto);
    else printf("   [ERRO] %s\n", texto);
}

void testa_tabela_cria() {
    printf("- Testando tabela_cria()...\n");
    TabelaViagens *p_tabela = tabela_cria();

    print_teste(p_tabela != NULL, "Tabela não nula.");
    int tamanho = get_tamanho_tabela(p_tabela);

    for (int i = 0; i < tamanho; i++) {
        NoViagem **pp_tabelaHash = get_tabela_hash(p_tabela);
        if (pp_tabelaHash[i] == NULL) {
            print_teste(0, "Elementos inicializados.");
            return;
        }
        Viagem *viagem = get_viagem(pp_tabelaHash[i]);
        if (viagem != NULL) {
            print_teste(0, "Elementos inicializados.");
            return;
        }
    }
    print_teste(1, "Elementos inicializados.");
}

void testa_cria_lista_codigos_reservas() {
    printf("- Testando vetor_cria_lista_codigos_reservas()\n");
    int a[3] = {1, 2, 3};
    CodigosReservas *p_codigos = vetor_cria_lista_codigos_reservas(a, 3);
    int *p_vetor_codigos = get_vetor_codigos_reservas(p_codigos);
    if (p_vetor_codigos[0] == 1) {
        if (p_vetor_codigos[1] == 2) {
            if (p_vetor_codigos[2] == 3) {
                print_teste(1, "CódigosReservas gerado por vetor");
                return;
            }
        }
    }
    print_teste(0, "CódigosReservas gerado por vetor");
}

void testa_viagem_cria() {
    TODO: "teste necessita das funções de Reserva";
}

void main(void) {
    testa_tabela_cria();
    testa_cria_lista_codigos_reservas();
}