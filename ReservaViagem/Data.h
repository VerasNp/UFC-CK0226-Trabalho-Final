#include "../Utils/Headers.h"

/**
 * Criaçao de data. Caso dia, mes ou ano seja menor ou igual a 0 retorna nulo, caso contrario retorna a data cadastrada
 * @param dia
 * @param mes
 * @param ano
 * @return NULL
 * @return p_data
 */
Data *cria_data(int dia, int mes, int ano);

/**
 * Acessa valores de um ponto da memoria que armazena informaçoes de data
 * @param p_data
 * @param dia
 * @param mes
 * @param ano
 */
void acessa_data(Data *p_data, int *dia, int *mes, int *ano);

/**
 * Libera espaço de memoria ocupado por parte que armazenava um valor relacionado a data.
 * Retorna 0 para quando nao e possivel se liberar o espaço e 1 quando e possivel fazer a liberaçao
 * @param p_data
 * @return 0
 * @return 1
 */
int libera_data(Data **p_data);

/**
 * Compara duas datas e retorna 0 se as duas datas sao iguais, -1 caso a primeira data seja menor que a segunda e 1 caso a primeira data seja maior que a segunda
 * @param p_data1
 * @param p_data2
 * @return -1
 * @return 0
 * @return 1
 */
int comparar_datas(Data *p_data1, Data *p_data2);
