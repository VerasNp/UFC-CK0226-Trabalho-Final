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
    printf("- Testando vetor_cria_lista_codigos_reservas()...\n");
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

void testa_tabela_indice() {
    printf("- Testando tabela_indice()...\n");
    int vetorCodigos[3] = {10, 5, 9};
    int codigoPassageiro = 7;
    CodigosReservas *p_codigosReservas = vetor_cria_lista_codigos_reservas(vetorCodigos, 3);
    int indice = tabela_indice(codigoPassageiro, p_codigosReservas);

    print_teste(indice == 643, "tabela_indice teste 1");

    int vetorCodigos2[3] = {10, 6, 9};
    int codigoPassageiro2 = 7;
    CodigosReservas *p_codigosReservas2 = vetor_cria_lista_codigos_reservas(vetorCodigos2, 3);
    int indice2 = tabela_indice(codigoPassageiro2, p_codigosReservas2);

    print_teste(indice2 == 878, "tabela_indice teste 2");

    int vetorCodigos3[3] = {1, 2, 3};
    int codigoPassageiro3 = 1;
    CodigosReservas *p_codigosReservas3 = vetor_cria_lista_codigos_reservas(vetorCodigos3, 3);
    int indice3 = tabela_indice(codigoPassageiro3, p_codigosReservas3);

    print_teste(indice3 == 410, "tabela_indice teste 3");

    int vetorCodigos4[3] = {53, 54, 55};
    int codigoPassageiro4 = 32;
    CodigosReservas *p_codigosReservas4 = vetor_cria_lista_codigos_reservas(vetorCodigos4, 3);
    int indice4 = tabela_indice(codigoPassageiro4, p_codigosReservas4);

    print_teste(indice4 == 75, "tabela_indice teste 2");
}

void main(void) {
    testa_tabela_cria();
    testa_cria_lista_codigos_reservas();
    testa_tabela_indice();
}