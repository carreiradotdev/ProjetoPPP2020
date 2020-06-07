#include <stdio.h>
#include <stdlib.h>

typedef struct socio{
    char nome[50];
    char apelido[50];
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
    socio *info_pagamento;
    lista_socios next;
};

int id = 0;

void print_socios(lista_socios ls){
    for(;ls != NULL; ls=ls->next){
        printf("%s\t%s\t%d\n", ls->info_socio->nome, ls->info_socio->apelido, ls->info_socio->id);
    }
}

void inserir_lista_socios(lista_socios lista, socio* s){
    lista_socios novo_no = calloc(sizeof(struct _lista_socios), 1);
    novo_no->info_socio = s;
    //ciclo até encontrar posicao onde inserir
    //inserir (alterar os ponteiros next do novo_no e do no anterior)
}

void menu_add_socio(lista_socios ls){
    socio* s = calloc(sizeof(socio),1);
    printf("nome:\n");
    scanf("%s", s->nome);
    printf("apelido:\n");
    scanf("%s", s->apelido);
    s->id = id++;
    inserir_lista_socios(ls, s);
}

void menu_edit_socio(){

}

void menu_remove_socio(){

}

void menu_add_paga(){
    pagemento* s = calloc(sizeof(montante),1); // isto não faz sentido?
    printf("Montante Pago:\n");
    scanf("%s", s->montante);
    s->id = id++;
    inserir_lista_pagamentos(ls, s);
}

void menu_edit_paga(){

}

void menu_remove_paga(){

}

int main(int argc, char *argv[]) {
    int opcao = 0;
    lista_socios ls;

    while (opcao != 4){
        printf("1 - adicionar socio\n");
        printf("2 - editar socio\n");
        printf("3 - remover socio\n");
        printf("7 - imprimir socio\n");
        printf("4 - adicionar pagamento\n");
        printf("5 - editar pagamento\n");
        printf("6 - remover pagamento\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                menu_add_socio(ls);
                break;
            case 2:
                menu_edit_socio();
                break;
            case 3:
                menu_remove_socio();
                break;
            case 4:
                menu_add_paga();
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
            default:
                break;
        }
    }

}