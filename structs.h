//
// Created by Francisco on 02/06/2020.
//

#ifndef PPPCARREIRA_STRUCTS_H
#define PPPCARREIRA_STRUCTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 50
typedef struct socio{
    char nome[STRSIZE];
    char apelido[STRSIZE];
    int id;
}socio;

typedef struct _lista_socios* lista_socios;

struct _lista_socios{
    socio *info_socio;
    lista_socios next;
};

typedef struct pagamento{
    int id;
    int montante;
}pagamento;

typedef struct _lista_pagamentos* lista_pagamentos;

struct _lista_pagamentos{ // Estrutura lista de pagamentos com ponteiro para o próximo node e pagamento
    pagamento *info_pagamento;
    lista_pagamentos next;
};

void print_socios(lista_socios ls);

#endif //PPPCARREIRA_STRUCTS_H
