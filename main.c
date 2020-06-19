#include "structs.h"


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
    p->id = id++;
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

extern void write_to_file_socios(lista_socios lista);

extern lista_socios read_from_file_socios();

extern void write_to_file_paga(lista_pagamentos lista);

extern lista_pagamentos read_from_file_paga();

// cap é a quantia das quotas a serem pagas
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
int main(void) {
    int opcao = 0;
    lista_socios ls = NULL;
    lista_pagamentos lp = NULL;
    while (opcao != 11){
        printf("1 - adicionar socio\n");
        printf("2 - editar socio\n");
        printf("3 - remover socio\n");
        printf("4 - adicionar pagamento\n");
        printf("5 - editar pagamento\n");
        printf("6 - remover pagamento\n");
        printf("7 - imprimir socio\n");
        printf("8 - imprimir pagamentos\n");
        printf("9 - write socios to file\n");
        printf("10 - read socios from file\n");
        printf("11 - imprimir txt\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                ls = menu_add_socio(ls);
                break;
            case 2:
                menu_edit_socio(ls);
                break;
            case 3:
                ls = menu_remove_socio(ls);
                break;
            case 4:
                lp = menu_add_paga(lp);
                break;
            case 5:
                menu_edit_paga(lp);
                break;
            case 6:
                lp = menu_remove_paga(lp);
                break;
            case 7:
                print_socios(ls);
                break;
            case 8:
                print_pagamentos(lp);
                break;
            case 9:
                write_to_file_socios(ls);
                write_to_file_paga(lp);
                break;
            case 10:
                ls = read_from_file_socios();
                lp = read_from_file_paga();
                break;
            case 11:
                // output()
                break;
            default:
                break;
        }
    }
}