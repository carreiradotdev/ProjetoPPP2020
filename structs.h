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

void print_socios();

void print_pagamentos();

void inserir_lista_socios(socio *s);

void inserir_lista_paga(pagamento *p);

void remove_lista_socios(int id_to_remove);

void menu_add_socio();

void menu_edit_socio();

void menu_remove_socio();

lista_pagamentos menu_add_paga();

void menu_edit_paga();

void remove_lista_paga(int id_to_remove);

void menu_remove_paga();

void write_to_file_socios();

void read_from_file_socios();

void write_to_file_paga();

void read_from_file_paga();

void output();

#endif //PPPCARREIRA_STRUCTS_H
