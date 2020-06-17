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

struct _lista_pagamentos{
    pagamento *info_pagamento;
    lista_pagamentos next;
};

int id = 0;

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

void menu_add_paga(){
    pagamento* p = calloc(sizeof(pagamento),1);
    printf("Montante Pago:\n");
    scanf("%d", p->montante);
    p->id = id++;
    inserir_lista_paga(lp, p);
}

void menu_edit_paga(lista_pagamentos lp){
    lista_pagamentos edit;
    int id;
    char string[STRSIZE];
    printf("ID de sócio: ");
    scanf("%d^[\n]", &id);
    for (edit = lp; edit != NULL && edit->info_pagamento->id != id;edit = edit->next);
    printf("\nMontante: %s\n", edit->info_pagamento->montante);
    printf("Novo montante: ");
    scanf("%s^[\n]", string);
    strcpy(edit->info_pagamento->montante, string);

/* void menu_remove_paga() {

}*/

void write_to_file_socios(lista_socios lista){
    FILE *f = fopen("ficheiro_in_socios", "wb");
    while(lista != NULL){
        fwrite(lista->info_socio, 1, sizeof(socio), f);
        lista = lista->next;
    }
    fclose(f);
}

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

int main(void) {
    int opcao = 0;
    lista_socios ls = NULL;
    lista_pagamentos lp = NULL;

    while (opcao != 4){
        printf("1 - adicionar socio\n");
        printf("2 - editar socio\n");
        printf("3 - remover socio\n");
        printf("4 - adicionar pagamento\n");
        printf("5 - editar pagamento\n");
        printf("6 - remover pagamento\n");
        printf("7 - imprimir socio\n");
        printf("8 - imprimir pagamentos")
        printf("9 - write socios to file\n");
        printf("10 - read socios from file\n");
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
                menu_edit_paga();
                break;
            case 6:
                menu_remove_paga();
                break;
            case 7:
                print_socios(ls);
                break;
            case 8:
                print_pagamentos(lp);
                break;
            case 9:
                write_to_file_socios(ls);
                break;
            case 10:
                ls = read_from_file_socios();
                break;
            default:
                break;
        }
    }
}