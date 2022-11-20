#include <stdio.h>
#include "TabelaViagens.h"
#include <stdlib.h>

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

    print_teste(indice == 643, "tabela_indice() - teste 1");

    int vetorCodigos2[3] = {10, 6, 9};
    int codigoPassageiro2 = 7;
    CodigosReservas *p_codigosReservas2 = vetor_cria_lista_codigos_reservas(vetorCodigos2, 3);
    int indice2 = tabela_indice(codigoPassageiro2, p_codigosReservas2);

    print_teste(indice2 == 878, "tabela_indice() - teste 2");

    int vetorCodigos3[3] = {1, 2, 3};
    int codigoPassageiro3 = 1;
    CodigosReservas *p_codigosReservas3 = vetor_cria_lista_codigos_reservas(vetorCodigos3, 3);
    int indice3 = tabela_indice(codigoPassageiro3, p_codigosReservas3);

    print_teste(indice3 == 410, "tabela_indice() - teste 3");

    int vetorCodigos4[3] = {53, 54, 55};
    int codigoPassageiro4 = 32;
    CodigosReservas *p_codigosReservas4 = vetor_cria_lista_codigos_reservas(vetorCodigos4, 3);
    int indice4 = tabela_indice(codigoPassageiro4, p_codigosReservas4);

    print_teste(indice4 == 75, "tabela_indice() - teste 2");
}

void testa_tabela_crud() {
    /* INSERÇÃO */
    printf("- Testando tabela_insere_viagem()...\n");
    int tabelaInsereBool = 1;

    Reserva **pp_reservas1 = malloc(sizeof(Reserva *)*3);
    pp_reservas1[0] = reserva_cria(1,1);
    pp_reservas1[1] = reserva_cria(2,1);
    pp_reservas1[2] = reserva_cria(3,1);

    Reserva **pp_reservas2 = malloc(sizeof(Reserva *)*2);
    pp_reservas2[0] = reserva_cria(4,2);
    pp_reservas2[1] = reserva_cria(5,2);

    Reserva **pp_reservas3 = malloc(sizeof(Reserva *)*4);
    pp_reservas3[0] = reserva_cria(6,3);
    pp_reservas3[1] = reserva_cria(7,3);
    pp_reservas3[2] = reserva_cria(8,3);
    pp_reservas3[3] = reserva_cria(9,3);

    Reserva **pp_reservas4 = malloc(sizeof(Reserva *)*3);
    pp_reservas4[0] = reserva_cria(1,707);
    pp_reservas4[1] = reserva_cria(2,707);
    pp_reservas4[2] = reserva_cria(3,707);

    Viagem *p_viagem1 = viagem_cria(pp_reservas1, 3);
    Viagem *p_viagem2 = viagem_cria(pp_reservas2, 2); // índice = 115
    Viagem *p_viagem3 = viagem_cria(pp_reservas3, 4);
    Viagem *p_viagem4 = viagem_cria(pp_reservas4, 3); // índice = 115
    

    int codigoPassageiro = get_viagem_codigo_passageiro(p_viagem1);
    print_teste(codigoPassageiro == 1, "viagem_cria() codigoPassageiro");
    print_teste(!viagem_compara(p_viagem1, p_viagem2), "viagem_compara() - teste 1");
    print_teste(viagem_compara(p_viagem3, p_viagem3), "viagem_compara() - teste 2");

    TabelaViagens *p_tabela = tabela_cria();
    if (!tabela_insere_viagem(p_tabela, p_viagem1)) tabelaInsereBool = 0;
    if (!tabela_insere_viagem(p_tabela, p_viagem2)) tabelaInsereBool = 0;
    if (!tabela_insere_viagem(p_tabela, p_viagem3)) tabelaInsereBool = 0;

    print_teste(tabelaInsereBool, "tabela_insere_viagem() - teste 1");
    print_teste(!tabela_insere_viagem(p_tabela, p_viagem3), "tabela_insere_viagem() - teste 2: Não inserir viagens iguais. ");

    print_teste(tabela_insere_viagem(p_tabela, p_viagem4), "tabela_insere_viagem() - teste 3: Colisão. ");
    print_teste(tabela_tamanho_indice(p_tabela, 115) == 2, "tabela_insere_viagem() - teste 4: 2 viagens no índice 115. ");

    /* PESQUISA */
    printf("- Testando tabela_pesquisa_viagem()...\n");

    CodigosReservas *p_codigosReservas1 = viagem_cria_lista_codigos_reservas(p_viagem2);
    int codigoPassageiro1 = get_viagem_codigo_passageiro(p_viagem2);
    Viagem *p_viagemPesquisada1 = tabela_pesquisa_viagem(p_tabela, codigoPassageiro1, p_codigosReservas1);
    print_teste(viagem_compara(p_viagem2, p_viagemPesquisada1), "tabela_pesquisa_viagem() - teste 1 ");

    CodigosReservas *p_codigosReservas2 = viagem_cria_lista_codigos_reservas(p_viagem4);
    int codigoPassageiro2 = get_viagem_codigo_passageiro(p_viagem4);
    Viagem *p_viagemPesquisada2 = tabela_pesquisa_viagem(p_tabela, codigoPassageiro2, p_codigosReservas2);
    print_teste(viagem_compara(p_viagem4, p_viagemPesquisada2), "tabela_pesquisa_viagem() - teste 2: pesquisar viagem colidida. ");

}

void main(void) {
    testa_tabela_cria();
    testa_cria_lista_codigos_reservas();
    testa_tabela_indice();
    testa_tabela_crud();
}