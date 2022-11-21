#include "TravelBooking.c"
#include <stdio.h>
#include <stdlib.h>

Voo *cria_voo(int codigo, char *origem, char *destino)
{
    Voo *novo_voo = (Voo *)malloc(sizeof(Voo));
    novo_voo->codigo = codigo;
    novo_voo->origem = origem;
    novo_voo->destino = destino;

    return novo_voo;
}

Voo *edita_voo(Voo *voo, int novo_codigo, char *nova_origem, char *novo_destino)
{

    voo->codigo = novo_codigo;
    voo->origem = nova_origem;
    voo->destino = novo_destino;
    return voo;
}

struct no_voo *cria_no_voo()
{
    struct no_voo *no = (struct no_voo *)malloc(sizeof(struct no_voo));
    no->proximo = NULL;
    no->voo = NULL;
    return no;
}

ListaVoo *cria_lista()
{
    ListaVoo *lista = (ListaVoo *)malloc(sizeof(ListaVoo));
    lista->primeiro = NULL;
}

int conferir_codigo(Voo *voo, ListaVoo *lista)
{
    struct no_voo *no_tmp = lista->primeiro;
    while (no_tmp == NULL)
    {
        if (no_tmp->voo->codigo == voo->codigo)
            return 1;
        no_tmp = no_tmp->proximo;
    }
    return 0;
}


// Criação das variáveis serão feitas fora da função
void insere_voo_em_fila(Voo *voo, ListaVoo *lista)
{
    if (lista->primeiro == NULL)
    {
        struct no_voo *no = cria_no_voo();
        no->voo = voo;
        lista->primeiro = no;
        return;
    }
    else if (conferir_codigo(voo, lista) != 0)
    {
        printf("Codigo fornecidado ja registrado!\n");
        return;
    }
    // Precisa conferir reserva!

    struct no_voo *no_tmp = lista->primeiro;

    do
    {
        if (no_tmp->proximo == NULL)
        {
            struct no_voo *no_novo = cria_no_voo();
            no_tmp->proximo = no_novo;
            no_novo->voo = voo;
            break; // mto importante
        }
        no_tmp = no_tmp->proximo;
    } while (no_tmp != NULL);
}

// retirar o voo indicado pelo parametro --- Voo *voo ou int codigo
void retira_voo_em_fila(ListaVoo *lista, int codigo)
{
    if (lista->primeiro->voo->codigo == codigo)
    {
        lista->primeiro = lista->primeiro->proximo;
        return;
    }

    struct no_voo *no_tmp = lista->primeiro;

    while (no_tmp != NULL)
    {
        if ((no_tmp->proximo != NULL) && (no_tmp->proximo->voo->codigo == codigo))
        {
            no_tmp->proximo = no_tmp->proximo->proximo;
            break;
        }
        no_tmp = no_tmp->proximo;
    }
    return;
}

struct no_voo *busca_voo_em_fila(ListaVoo *lista, int codigo)
{
    struct no_voo *no_tmp = lista->primeiro;
    while (no_tmp != NULL)
    {
        if (no_tmp->voo->codigo == codigo)
            return no_tmp;

        no_tmp = no_tmp->proximo;
    }
    printf("Codigo nao pertence a lista!\n");
    return NULL;
}