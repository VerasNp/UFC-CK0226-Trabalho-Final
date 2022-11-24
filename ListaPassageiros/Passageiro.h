/*TAD: perfis dos passageiros*/
typedef struct passageiro Passageiro;  

/*Cria novo passageiro. Retorna NULL se não foi possível criar*/
Passageiro *passageiro_cria(char *p_nome,char *p_endereco); 

/*Acessa os atribudos do passageiro*/
void passageiro_acessa(Passageiro *p_passageiro,int *p_id, char *p_nome, char *p_endereco); 

/*Põe novos atributos no passageiro*/
void passageiro_atribui(Passageiro *p_passageiro, char *p_nomeNovo, char *p_enderecoNovo);

/*Retorna o tamanho do TAD Passageiro*/
int passageiro_tamanho(); 

/*Libera o espaço de memória do passageiro. Retorna 1 se foi possível liberar, 0 se não foi possível*/
int passageiro_libera(Passageiro *p_passageiro); 

