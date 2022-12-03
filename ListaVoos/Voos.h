/*TAD voos*/
typedef struct voo Voo;

/**
 * @brief aloca a memória ocupada pelo voo
 * 
 * @param origem origem do voo a ser criado 
 * @param destino destino do voo a ser criado
 * @return Voo* - voo com codigo gerado e com a origem e com o destino dados
 */
Voo *cria_voo(char *p_origem, char *p_destino);

/**
 * @brief Muda os atributos do voo
 * 
 * @param voo voo que será mudado
 * @param p_novaOrigem nova string demarcando a nova origem
 * @param p_novoDestino nova string demarcando o novo destino 
 * @return 1 se foi possível editar, 0 se não foi possível
 */
int edita_voo(Voo *p_voo, char *p_novaOrigem, char *p_novoDestino);

/**
 * @brief copia os atributos do voo
 * 
 * @param p_voo voo no qual serão extraídos os atributos
 * @param p_codigo recebe a cópia do codigo
 * @param p_origem recebe a cópia da origem do voo
 * @param p_destino recebe a cópia do destino do voo
 */
void leitura_voo(Voo *p_voo, int *p_codigo, char *p_origem, char *p_destino);

/**
 * @brief libera o espaço de memória ocupado pelo voo
 * 
 * @param p_voo voo a ser liberado
 */
int libera_voo(Voo *p_voo);

/* retorna o tamanho do vôo. */
int tamanho_voo();