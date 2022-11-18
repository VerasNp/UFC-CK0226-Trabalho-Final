#include "Reserva.h"
#include <stdio.h>

void print_teste(int r, char texto[]) {
    if (r) printf("   [SUCESSO] %s\n", texto);
    else printf("   [ERRO] %s\n", texto);
}

static void test_cria_reserva() {
    Reserva *p_reserva = cria_reserva(2, );
    print_teste(p_reserva != NULL, "test_cria_reserva()");
}

int main(void){
    test_cria_reserva();
    return 0;
}
