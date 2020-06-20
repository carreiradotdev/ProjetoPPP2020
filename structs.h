//
// Created by Francisco on 02/06/2020.
//

#ifndef PPPCARREIRA_STRUCTS_H
#define PPPCARREIRA_STRUCTS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRSIZE 50
#define QUOTA 50
typedef struct socio{
    char nome[STRSIZE];
    char apelido[STRSIZE];
    int id;
    int saldo;
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

void print_pagamentos(lista_pagamentos lp);

lista_socios inserir_lista_socios(lista_socios lista, socio* s);

lista_pagamentos inserir_lista_paga(lista_pagamentos lista, pagamento* p);

lista_socios remove_lista_socios(lista_socios lista, int id_to_remove);

lista_socios menu_add_socio(lista_socios ls);

void menu_edit_socio(lista_socios ls);

lista_socios menu_remove_socio(lista_socios ls);

lista_pagamentos menu_add_paga(lista_pagamentos lp);

void menu_edit_paga(lista_pagamentos lp);

lista_pagamentos remove_lista_paga(lista_pagamentos lista, int id_to_remove);

lista_pagamentos menu_remove_paga(lista_pagamentos lp);

void write_to_file_socios(lista_socios lista);

lista_socios read_from_file_socios();

void write_to_file_paga(lista_pagamentos lista);

lista_pagamentos read_from_file_paga();

void output(lista_socios listasoc, lista_pagamentos listapag);

#endif //PPPCARREIRA_STRUCTS_H
