#include "stdio.h"
#include "stdlib.h"
#include "../ListaPassageiros/ListaPassageiros.h"
#include "../Utils/Utils.h"


void passageiro_menu(ListaPassageiro *p_listaPassageiros) {
    char *opcao = (char *) malloc(sizeof(char));
    printf("\n\t");
    printf("-----PASSAGEIROS------");
    printf("\n\t 1. Listar");
    printf("\n\t 2. Editar");
    printf("\n\t 3. Buscar por nome");
    printf("\n\t 4. Remover");
    printf("\n\t");
    scanf("Digite uma opção: %c%*c", opcao);
    while(1){
    int id;
    Passageiro *p_passageiro = NULL; 
    switch (*opcao) {
        case '1':
            listar_passageiros(p_listaPassageiros); 
            break;
        case '2': 
            listar_passageiros(p_listaPassageiros); 
            printf("Digite o id do passageiro que deseja alterar: ");scanf("%d",&id);
            p_passageiro = lista_busca_passageiro(id,p_listaPassageiros);
            if (p_passageiro){ 
                char *p_nome = (char *)malloc(sizeof(char)*100); 
                char *p_endereco = (char *)malloc(sizeof(char)*300); 
                printf("Preencha os dados: \n");
                printf("Novo nome: "); 
                scanf("%s",p_nome);
                printf("Novo endereço: ");
                scanf("%s",p_endereco); 
                passageiro_atribui(p_passageiro,p_nome,p_endereco); 
                free(p_nome); free(p_endereco); 
            }
            else erro("Id não existe");
            break; 
        case '3': 
            printf("Digite o nome: "); 
            char *p_nome = (char *)malloc(sizeof(char)*100); 
            scanf("%s",p_nome);
            p_passageiro = busca_nome_passageiro(p_listaPassageiros,p_nome); 
            if (p_listaPassageiros == NULL) erro("Lista de passageiros vazia");
            else if (p_passageiro == NULL) erro("Passageiro não encontrado");
            else print_passageiro(p_passageiro); 
            break; 
        case '4':
            listar_passageiros(p_listaPassageiros); 
            printf("Digite o id do passageiro que deseja remover: ");scanf("%d",&id);
            if (!lista_busca_passageiro(id,p_listaPassageiros)) erro("Passageiro não encontrado"); 
            else remover_passageiro(p_listaPassageiros,id); 
            break;
        default: 
            return; 
    }
    }
}