#include "Validacoes.h"
#include "string.h"
#include "stdlib.h"

int valida_string_nulo(char *string) {
    if (string == NULL)
        return 1;
    return 0;
}

int valida_tamanho_string(char *string, int tamanho, char *comparador) {
    if (strcmp(comparador, "==") == 0) {
        if (strlen(string) == tamanho)
            return 1;
        else
            return 0;
    } else if (strcmp(comparador, "<=") == 0) {
        if (strlen(string) <= tamanho)
            return 1;
        else
            return 0;
    } else if (strcmp(comparador, "<") == 0) {
        if (strlen(string) < tamanho)
            return 1;
        else
            return 0;
    } else if (strcmp(comparador, ">=") == 0) {
        if (strlen(string) >= tamanho)
            return 1;
        else
            return 0;
    } else if (strcmp(comparador, ">") == 0) {
        if (strlen(string) > tamanho)
            return 1;
        else
            return 0;
    } else {
        exit(EXIT_FAILURE);
    }
}
