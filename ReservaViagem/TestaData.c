#include "Data.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Renderiza resultado do teste
 * @param r
 * @param texto
 */
static void print_teste(int r, char texto[]) {
    if (r) printf("   [SUCESSO] %s\n", texto);
    else printf("   [ERRO] %s\n", texto);
}

/**
 * Testa a criaçao de uma data de forma separada
 */
static void test_cria_data() {
    print_teste(cria_data(20, 10, 2022) != NULL, "test_cria_data()");
}

/**
 * Teste de liberaçao de espaço ocupado por data
 */
static void test_libera_data() {
    Data *p_data = cria_data(rand() % 30 + 1, rand() % 11 + 1, rand() % 2019 + 1);
    print_teste(libera_data(&p_data) == 1, "test_libera_data()");
}

/**
 * Testa funçao de acessar valores de uma data
 */
static void test_acessa_data() {
    int dia;
    int mes;
    int ano;

    Data *p_data = cria_data(20, 10, 2022);

    acessa_data(p_data, &dia, &mes, &ano);

    if (
            dia != 20 ||
            mes != 10 ||
            ano != 2022
            )
        print_teste(0, "test_acessa_data()");
    else
        print_teste(1, "test_acessa_data()");
}

/**
 * Testa a funçao que compara duas datas e retorna se a primeira e maior que a segunda ou igual
 */
static void test_comparar_datas() {
    Data *p_data1 = cria_data(20, 10, 2022);
    Data *p_data2 = cria_data(20, 11, 2022);

    print_teste(comparar_datas(p_data1, p_data2) < 0, "test_acessa_data()");
}

int main() {
    test_cria_data();
    test_acessa_data();
    test_libera_data();
    test_comparar_datas();
}