//
// Created by verasnp on 11/15/22.
//
#include "TravelReservation.h"
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

static void test_cria_agenda() {
    if (cria_agenda() == NULL) {
        assert(true && "test_cria_agenda()");
    } else {
        assert(false && "test_cria_agenda()");
    }
}

int main(){
    test_cria_agenda();
}
