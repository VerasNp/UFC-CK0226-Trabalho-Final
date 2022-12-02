#include "Data.h"
#include <stdio.h>
#include <stdlib.h>

struct data {
    int dia;
    int mes;
    int ano;
};

/**
 * Criaçao de data. Caso dia, mes ou ano seja menor ou igual a 0 retorna nulo, caso contrario retorna a data cadastrada
 * @param dia
 * @param mes
 * @param ano
 * @return NULL
 * @return p_data
 */
Data *cria_data(int dia, int mes, int ano) {
    if (
            (dia <= 0) ||
            (mes <= 0) ||
            (ano <= 0)
            ) {
        return NULL;
    }

    Data *p_data = (Data *) malloc(sizeof(Data));
    p_data->dia = dia;
    p_data->mes = mes;
    p_data->ano = ano;

    return p_data;
}

/**
 * Acessa valores de um ponto da memoria que armazena informaçoes de data
 * @param p_data
 * @param dia
 * @param mes
 * @param ano
 */
void acessa_data(Data *p_data, int *dia, int *mes, int *ano) {
    if (p_data == NULL) {
        *dia = -1;
        *mes = -1;
        *ano = -1;
    } else {
        *dia = p_data->dia;
        *mes = p_data->mes;
        *ano = p_data->ano;
    }
}

/**
 * Libera espaço de memoria ocupado por parte que armazenava um valor relacionado a data.
 * Retorna 0 para quando nao e possivel se liberar o espaço e 1 quando e possivel fazer a liberaçao
 * @param p_data
 * @return 0
 * @return 1
 */
int libera_data(Data **p_data) {
    if (p_data == NULL) {
        return 0;
    }
    if (*p_data == NULL) printf("sabia\n");
    free(*p_data);
    *p_data = NULL;

    return 1;
}

/**
 * Compara duas datas e retorna 0 se as duas datas sao iguais, -1 caso a primeira data seja menor que a segunda e 1 caso a primeira data seja maior que a segunda
 * @param p_data1
 * @param p_data2
 * @return -1, 0, 1
 */
int comparar_datas(Data *p_data1, Data *p_data2) {
    if (p_data1 == NULL || p_data2 == NULL) {
        exit(EXIT_FAILURE);
    }

    if (
            p_data1->dia == p_data2->dia &&
            p_data1->mes == p_data2->mes &&
            p_data1->ano == p_data2->ano)
        return 0;
    else if (
            p_data1->ano > p_data2->ano ||
            p_data1->ano == p_data2->ano && p_data1->mes > p_data2->mes ||
            p_data1->ano == p_data2->ano && p_data1->mes == p_data2->mes && p_data1->dia > p_data2->dia)
        return 1;
    else return -1;
}

/* Retorna o tamanho da Data. */
int tamanho_data() {
    return sizeof(Data);
}
