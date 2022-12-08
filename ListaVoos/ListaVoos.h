#include "Voos.h" 

/**
 * @brief Aloca memória para um novo nó
 * 
 * @return NoVoo* - Nó com atributos NULL
 */
NoVoo *cria_no_voo();

/**
 * @brief Aloca memória para uma nova lista
 * 
 * @return ListaVoo* - Lista encadeada de voos com atributos NULL
 */
ListaVoo *cria_lista();

/**
 * @brief Insere um voo em uma lista
 * 
 * @param p_voo Voo que será incluído 
 * @param p_lista Lista que terá o novo voo
 * @return 1 se foi possível adicionar -- 0 se os parâmetros são NULL
 */
int insere_voo(Voo *p_voo, ListaVoo *p_lista);

/**
 * @brief Remove um voo da lista
 * 
 * @param p_lista Lista que terá voo removido
 * @param codigo Código do voo que será removido
 * @return Voo* 
 */
Voo *retira_voo(ListaVoo *p_lista, int codigo);
/**
 * @brief Busca por um voo
 * 
 * @param p_lista Lista que será percorrida
 * @param codigo Codigo que será procurado
 * @return O voo com o codigo dado ou NULL se não foi possível encontrar
 */
Voo *busca_voo_origem_e_destino(ListaVoo *p_lista, char *origem, char *destino);
Voo *busca_voo_origem(ListaVoo *p_lista, char *origem);
Voo *busca_voo_destino(ListaVoo *p_lista, char *destino);
Voo *busca_voo_codigo(ListaVoo *p_lista, int codigo);
/**
 * @brief Imprime os codigos dos voos da lista
 * 
 * @param p_lista Lista que terá os codigos imprimidos
 */
void print_fila(ListaVoo *p_lista);
/**
 * @brief 
 * 
 * @param p_lista Lista que será verificado o tamanho
 * @return Tamanho da lista ou -1 se p_lista for NULL
 */
int tamanho_lista(ListaVoo *p_lista); 
/**
 * @brief Libera a lista toda
 * @param p_lista lista que terá o espaço liberado
 */
int libera_lista(ListaVoo *p_lista);