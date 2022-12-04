enum EnumCodigoAssento {
    A0, B0, C0,
    A1, B1, C1,
    A2, B2, C2,
    A3, B3, C3,
    A4, B4, C4,
    A5, B5, C5,
    A6, B6, C6,
    A7, B7, C7,
    A8, B8, C8,
    A9, B9, C9
};

typedef enum EnumCodigoAssento CodigoAssento;

char *codigo_assento_to_string(CodigoAssento codigo);