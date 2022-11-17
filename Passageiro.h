/*TAD: perfis dos passageiros*/
typedef struct passageiro Passageiro;  

/*Cria novo passageiro. Retorna NULL se não foi possível criar*/
Passageiro *aloca_passageiro(char *nome,char *endereço); 

/*Acessa os atribudos do passageiro*/
void passageiro_acessa(Passageiro *passageiro,int *id, char *nome, char *endereço); 

/*Põe novos atributos no passageiro*/
void passageiro_atribui(Passageiro *passageiro, char *nome_novo, char *endereço_novo);

/*Retorna o tamanho do TAD Passageiro*/
int tamanho_passageiro(); 

/*Libera o espaço de memória do passageiro. Retorna 1 se foi possível liberar, 0 se não foi possível*/
int libera_passageiro(Passageiro *passageiro); 

