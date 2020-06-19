#include "structs.h"
static int id = 0;

void print_socios(lista_socios ls){
    for(;ls != NULL; ls=ls->next){
        printf("%s\t%s\t%d\n", ls->info_socio->nome, ls->info_socio->apelido, ls->info_socio->id);
    }
}

void print_pagamentos(lista_pagamentos lp){
    for(;lp != NULL; lp=lp->next){
        printf("%d\t%d\n", lp->info_pagamento->montante, lp->info_pagamento->id);
    }
}

lista_socios inserir_lista_socios(lista_socios lista, socio* s){
    lista_socios inicio = lista;
    lista_socios novo_no = calloc(sizeof(struct _lista_socios), 1);
    novo_no->info_socio = s;
    if(lista == NULL){
        return novo_no;
    }else{
        while(lista->next != NULL)
            lista = lista->next;
        lista->next = novo_no;
        return inicio;
    }
}

lista_pagamentos inserir_lista_paga(lista_pagamentos lista, pagamento* p){
    lista_pagamentos inicio = lista;
    lista_pagamentos novo_no = calloc(sizeof(struct _lista_pagamentos), 1);
    novo_no->info_pagamento = p;
    if(lista == NULL){
        return novo_no;
    }else{
        while(lista->next != NULL)
            lista = lista->next;
        lista->next = novo_no;
        return inicio;
    }
}

lista_socios remove_lista_socios(lista_socios lista, int id_to_remove){
    lista_socios inicio = lista;
    lista_socios seguinte;
    //remover primeiro no
    if(lista != NULL && lista->info_socio->id == id_to_remove){
        seguinte = lista->next;
        free(lista->info_socio);
        free(lista);
        return seguinte;
    }
    //remover outro no
    while(lista->next != NULL && lista->next->info_socio->id != id_to_remove){
        lista = lista->next;
    }
    if(lista->next == NULL){
        fprintf(stderr, "Id nao encontrado\n");
    }else{
        seguinte = lista->next->next;
        free(lista->next->info_socio);
        free(lista->next);
        lista->next = seguinte;
    }
    return inicio;
}

lista_socios menu_add_socio(lista_socios ls){
    socio* s = calloc(sizeof(socio),1);
    printf("nome:\n");
    scanf("%s", s->nome);
    printf("apelido:\n");
    scanf("%s", s->apelido);
    s->id = id++;
    ls = inserir_lista_socios(ls, s);
    return ls;
}

void menu_edit_socio(lista_socios ls){
    lista_socios edit;
    int id;
    char string[STRSIZE];
    printf("ID de sócio: ");
    scanf("%d^[\n]", &id);
    for (edit = ls; edit != NULL && edit->info_socio->id != id;edit = edit->next);
    printf("\nNome: %s\nApelido: %s\n", edit->info_socio->nome, edit->info_socio->apelido);
    printf("Novo nome: ");
    scanf("%s^[\n]", string);
    strcpy(edit->info_socio->nome, string);
    printf("Novo apelido: ");
    scanf("%s^[\n]", string);
    strcpy(edit->info_socio->apelido, string);
}

lista_socios menu_remove_socio(lista_socios ls) {
    int id;
    printf("id :");
    scanf("%d\n",&id);
    ls = remove_lista_socios(ls, id);
    return ls;
}

lista_pagamentos menu_add_paga(lista_pagamentos lp){
    pagamento* p = calloc(sizeof(pagamento),1);
    printf("Montante Pago: ");
    scanf("%d", &(p->montante));
    printf("ID do sócio: ");
    scanf("%d", &(p->id));
    lp = inserir_lista_paga(lp, p);
    return lp;
}

void menu_edit_paga(lista_pagamentos lp) {
    lista_pagamentos edit;
    int id;
    printf("ID de sócio: ");
    scanf("%d^[\n]", &id);
    for (edit = lp; edit != NULL && edit->info_pagamento->id != id; edit = edit->next);
    printf("\nMontante: %d\n", edit->info_pagamento->montante);
    printf("Novo montante: ");
    scanf("%d^[\n]", &(edit->info_pagamento->montante));
    //TODO fgets + strtof/strtof instead
}

lista_pagamentos remove_lista_paga(lista_pagamentos lista, int id_to_remove) {
    lista_pagamentos inicio = lista;
    lista_pagamentos seguinte;
    //remover primeiro no
    if(lista != NULL && lista->info_pagamento->id == id_to_remove){
        seguinte = lista->next;
        free(lista->info_pagamento);
        free(lista);
        return seguinte;
    }
    while(lista->next != NULL && lista->next->info_pagamento->id != id_to_remove){
        lista = lista->next;
    }
    if(lista->next == NULL){
        fprintf(stderr, "Id nao encontrado\n");
    }else{
        seguinte = lista->next->next;
        free(lista->next->info_pagamento);
        free(lista->next);
        lista->next = seguinte;
    }
    return inicio;
}

lista_pagamentos menu_remove_paga(lista_pagamentos lp) {
    int id;
    printf("id :");
    scanf("%d^[\n]", &id);
    lp = remove_lista_paga(lp, id);
    return lp;
}

void output(lista_socios listasoc, lista_pagamentos listapag, int cap) {
    //fprintf(fp, "\n## Sócios com as quotas em dia ##\n");
    while(listasoc != NULL){
        lista_pagamentos lp = listapag;
        int soma = 0;
        while(lp != NULL){
            if(listasoc->info_socio->id == lp->info_pagamento->id)
                soma += lp->info_pagamento->montante;
            lp = lp->next;
        }
        //print para ficheiro de quanto pagou/desvio

        listasoc = listasoc->next;
    }
}