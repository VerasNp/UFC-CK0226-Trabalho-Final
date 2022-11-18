#include "Agenda.h"
#include <stdio.h>

void print_teste(int r, char texto[]) {
    if (r) printf("   [SUCESSO] %s\n", texto);
    else printf("   [ERRO] %s\n", texto);
}

static void test_cria_agenda() {
    Agenda *p_agenda = cria_agenda();
    print_teste(p_agenda != NULL, "test_cria_agenda()");
}

int main(void){
    test_cria_agenda();
    return 0;
}