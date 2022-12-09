#include "Enums.h"

char *codigo_assento_to_string(CodigoAssento codigo) {
    switch (codigo) {
        case 0: return "A0";
        case 1: return "B0";
        case 2: return "C0";
        case 3: return "A1";
        case 4: return "B1";
        case 5: return "C1";
        case 6: return "A2";
        case 7: return "B2";
        case 8: return "C2";
        case 9: return "A3";
        case 10: return "B3";
        case 11: return "C3";
        case 12: return "A4";
        case 13: return "B4";
        case 14: return "C4";
        case 15: return "A5";
        case 16: return "B5";
        case 17: return "C5";
        case 18: return "A6";
        case 19: return "B6";
        case 20: return "C6";
        case 21: return "A7";
        case 22: return "B7";
        case 23: return "C7";
        case 24: return "A8";
        case 25: return "B8";
        case 26: return "C8";
        case 27: return "A9";
        case 28: return "B9";
        case 29: return "C9";
        default: return "inválido";
    }
}