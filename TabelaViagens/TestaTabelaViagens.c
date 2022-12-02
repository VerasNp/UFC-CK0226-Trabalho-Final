#include <stdio.h>
#include "TabelaViagens.h"
#include "../ReservaViagem/Reserva.h"
#include "../ListaPassageiros/Passageiro.h"
#include "../ReservaViagem/Data.h"
#include "../ListaVoos/Voos.h"
#include "../Utils/Utils.h"
#include <stdlib.h>

/* Função auxiliar para os testes. */
Reserva *reserva_padrao_cria(Passageiro *p_passageiro) {
    if (p_passageiro == NULL) return NULL;
    Data *p_data = cria_data(13,2,2022);
    Voo *p_voo = cria_voo("Fortaleza", "Japão");
    return cria_reserva(p_data, p_passageiro, p_voo, A3);
}

void testa_tabela_cria() {
    printf("- Testando tabela_cria()...\n");
    TabelaViagens *p_tabela = tabela_cria();

    print_teste(p_tabela != NULL, "Tabela não nula.");
    int tamanho = get_tamanho_tabela(p_tabela);

    for (int i = 0; i < tamanho; i++) {
        NoViagem **pp_tabelaHash = get_tabela_hash(p_tabela);
        if (pp_tabelaHash[i] != NULL) {
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

// cria passageiros e libera para aumentar o id do próximo passageiro a ser criado.
void aumenta_o_indice_dos_passageiros(int aumento) {
    for (int i=0; i < aumento; i++) {
        Passageiro *p_tmpPassageiro = passageiro_cria("a", "a");
        passageiro_libera(p_tmpPassageiro);
    }
}

void testa_tabela_crud() {
    /* INSERÇÃO */
    printf("- Testando tabela_insere_viagem()...\n");
    int tabelaInsereBool = 1;

    Reserva **pp_reservas1 = malloc(sizeof(Reserva *)*3);
    Passageiro *p_passageiro1 = passageiro_cria("Benício", "Siqueira");
    pp_reservas1[0] = reserva_padrao_cria(p_passageiro1); // 1-1
    pp_reservas1[1] = reserva_padrao_cria(p_passageiro1); // 1-2
    pp_reservas1[2] = reserva_padrao_cria(p_passageiro1); // 1-3

    Reserva **pp_reservas2 = malloc(sizeof(Reserva *)*2);
    Passageiro *p_passageiro2 = passageiro_cria("Bruno", "Parangaba");
    pp_reservas2[0] = reserva_padrao_cria(p_passageiro2); // 2-4
    pp_reservas2[1] = reserva_padrao_cria(p_passageiro2); // 2-5

    Reserva **pp_reservas3 = malloc(sizeof(Reserva *)*4);
    aumenta_o_indice_dos_passageiros(67); // para fazer com que o próximo id seja o 70 e haja colisão na tabela.
    Passageiro *p_passageiro3 = passageiro_cria("Robinho", "Fortaleza"); // id = 70

    pp_reservas3[0] = reserva_padrao_cria(p_passageiro3); // 70-6
    pp_reservas3[1] = reserva_padrao_cria(p_passageiro3); // 70-7
    pp_reservas3[2] = reserva_padrao_cria(p_passageiro3); // 70-8
    pp_reservas3[3] = reserva_padrao_cria(p_passageiro3); // 70-9

    Reserva **pp_reservas4 = malloc(sizeof(Reserva *)*3);
    Passageiro *p_passageiro4 = passageiro_cria("Roberta", "Aldeota");
    pp_reservas4[0] = reserva_padrao_cria(p_passageiro4); // 71-10
    pp_reservas4[1] = reserva_padrao_cria(p_passageiro4); // 71-11
    pp_reservas4[2] = reserva_padrao_cria(p_passageiro4); // 71-12

    Viagem *p_viagem1 = viagem_cria(pp_reservas1, 3); // índice 410
    Viagem *p_viagem2 = viagem_cria(pp_reservas2, 2); // índice 115
    Viagem *p_viagem3 = viagem_cria(pp_reservas3, 4); // índice 115 colisão
    Viagem *p_viagem4 = viagem_cria(pp_reservas4, 3); // índice 821
    

    int codigoPassageiro = get_viagem_codigo_passageiro(p_viagem1);
    print_teste(codigoPassageiro == 1, "viagem_cria() codigoPassageiro");
    print_teste(!viagem_compara(p_viagem1, p_viagem2), "viagem_compara() - teste 1: viagens diferentes.");
    print_teste(viagem_compara(p_viagem3, p_viagem3), "viagem_compara() - teste 2: viagens iguais.");

    TabelaViagens *p_tabela = tabela_cria();
    if (!tabela_insere_viagem(p_tabela, p_viagem1)) tabelaInsereBool = 0;
    if (!tabela_insere_viagem(p_tabela, p_viagem2)) tabelaInsereBool = 0;
    if (!tabela_insere_viagem(p_tabela, p_viagem4)) tabelaInsereBool = 0;


    print_teste(tabelaInsereBool, "tabela_insere_viagem() - teste 1: 3 Viagens inseridas.");
    print_teste(!tabela_insere_viagem(p_tabela, p_viagem4), "tabela_insere_viagem() - teste 2: Não inserir viagens iguais. ");

    print_teste(tabela_insere_viagem(p_tabela, p_viagem3), "tabela_insere_viagem() - teste 3: Colisão. ");
    print_teste(tabela_tamanho_indice(p_tabela, 115) == 2, "tabela_insere_viagem() - teste 4: 2 viagens no índice 115. ");


    /* PESQUISA */
    printf("- Testando tabela_pesquisa_viagem()...\n");

    CodigosReservas *p_codigosReservas1 = viagem_cria_lista_codigos_reservas(p_viagem1);
    int codigoPassageiro1 = get_viagem_codigo_passageiro(p_viagem1);
    Viagem *p_viagemPesquisada1 = tabela_pesquisa_viagem(p_tabela, codigoPassageiro1, p_codigosReservas1);
    print_teste(viagem_compara(p_viagem1, p_viagemPesquisada1), "tabela_pesquisa_viagem() - teste 1 ");

    CodigosReservas *p_codigosReservas2 = viagem_cria_lista_codigos_reservas(p_viagem2);
    int codigoPassageiro2 = get_viagem_codigo_passageiro(p_viagem2);
    Viagem *p_viagemPesquisada2 = tabela_pesquisa_viagem(p_tabela, codigoPassageiro2, p_codigosReservas2);
    print_teste(viagem_compara(p_viagem2, p_viagemPesquisada2), "tabela_pesquisa_viagem() - teste 2: pesquisar viagem colidida. ");

    /* ESTATÍSTICAS */
    printf("Testando funções de estatística...\n");
    float percentual = tabela_percentual_indices(p_tabela); //0,002997
    int maiorColisao = tabela_maior_colisao(p_tabela);

    int valorPercentual = (percentual * 1000000); // 2997

    print_teste(valorPercentual == 2997, "tabela_percentual_indices()");
    print_teste(maiorColisao == 2, "tabela_maior_colisao");

    /* REMOÇÃO */
    printf("- Testando tabela_remove_viagem()...\n");
    
    CodigosReservas *p_codigosReservasRemovidas1 = viagem_cria_lista_codigos_reservas(p_viagem3);
    int codigoPassageiroRemovido1 = get_viagem_codigo_passageiro(p_viagem3);
    print_teste(tabela_remove_viagem(p_tabela, p_viagem3), "tabela_remove_viagem() - teste 1");
    Viagem *p_viagemRemovida1 = tabela_pesquisa_viagem(p_tabela, codigoPassageiroRemovido1, p_codigosReservasRemovidas1);
    print_teste(p_viagemRemovida1 == NULL, "tabela_remove_viagem() - teste 2: Viagem removida não se encontra na tabela. ");

    CodigosReservas *p_codigosReservasRemovidas2 = viagem_cria_lista_codigos_reservas(p_viagem2);
    int codigoPassageiroRemovido2 = get_viagem_codigo_passageiro(p_viagem2);
    print_teste(tabela_remove_viagem(p_tabela, p_viagem2), "tabela_remove_viagem() - teste 3: remoção de viagem em colisão.");
    Viagem *p_viagemRemovida2 = tabela_pesquisa_viagem(p_tabela, codigoPassageiroRemovido2, p_codigosReservasRemovidas2);
    print_teste(p_viagemRemovida2 == NULL, "tabela_remove_viagem() - teste 4: Viagem removida não se encontra na tabela. ");

    printf("Testando tabela_libera()...\n");

     print_teste(tabela_libera(p_tabela), "tabela_libera() - teste 1");
}

void main(void) {
    testa_tabela_cria();
    testa_cria_lista_codigos_reservas();
    testa_tabela_indice();
    testa_tabela_crud();
}