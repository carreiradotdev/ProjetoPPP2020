#include<stdio.h>
#include<stdlib.h>
#include "structs.h"

lista_socios read_from_file_socios() {
    lista_socios lista = NULL;
    FILE *f = fopen("ficheiro_in_socios", "rb");
    socio s;
    while (fread(&s, 1, sizeof(socio), f)){
        socio *novo = calloc(1, sizeof(socio));
        *novo = s;
        lista = inserir_lista_socios(lista, novo);
    }
    fclose(f);
    return lista;
}

void write_to_file_socios(lista_socios lista){
    FILE *f = fopen("ficheiro_in_socios", "wb");
    while(lista != NULL){
        fwrite(lista->info_socio, 1, sizeof(socio), f);
        lista = lista->next;
    }
    fclose(f);
}

void write_to_file_paga(lista_pagamentos lista){
    FILE *f = fopen("ficheiro_in_paga", "wb");
    while(lista != NULL){
        fwrite(lista->info_pagamento, 1, sizeof(pagamento), f);
        lista = lista->next;
    }
    fclose(f);
}

lista_pagamentos read_from_file_paga() {
    lista_pagamentos lista = NULL;
    FILE *f = fopen("ficheiro_in_paga", "rb");
    pagamento p;
    while (fread(&p, 1, sizeof(pagamento), f)){
        pagamento *novo = calloc(1, sizeof(pagamento));
        *novo = p;
        lista = inserir_lista_paga(lista, novo);
    }
    fclose(f);
    return lista;
}

// waiting for miranda's help in this one