#include "structs.h"

static int id = 0;
lista_socios ls = NULL;
lista_pagamentos lp = NULL; // inicialização das listas como estando vazias

void print_socios() {
    lista_socios aux = ls;
    if (aux == NULL) return;
    do {
        printf("%s\t%s\t%d\n", aux->info_socio->nome, aux->info_socio->apelido, aux->info_socio->id);
        aux = aux->next;
    } while (aux != ls);
}

void print_pagamentos() {
    lista_pagamentos aux = lp;
    if (aux == NULL) return;
    do {
        printf("%d\t%d\n", aux->info_pagamento->montante, aux->info_pagamento->id);
        aux = aux->next;
    } while (aux != lp);
}

void inserir_lista_socios(socio *s) {
    lista_socios lista = ls;
    lista_socios novo_no = calloc(sizeof(struct _lista_socios), 1);
    novo_no->info_socio = s;
    if (lista == NULL) {
        novo_no->next = novo_no;
    } else {
        lista_socios aux = lista->next;
        lista->next = novo_no;
        novo_no->next = aux;
    }
    ls = novo_no;
}

void inserir_lista_paga(pagamento *p) {
    lista_pagamentos lista = lp;
    lista_pagamentos novo_no = calloc(sizeof(struct _lista_pagamentos), 1);
    novo_no->info_pagamento = p;
    if (lista == NULL) {
        novo_no->next = novo_no;
    } else {
        lista_pagamentos aux = lista->next;
        lista->next = novo_no;
        novo_no->next = aux;
    }
    lp = novo_no;
}

void remove_lista_socios(int id_to_remove) {
    lista_socios lista = ls;
    lista_socios inicial = lista;
    lista_socios aux;
    if (lista == NULL) return;//se lista vazia
    if (lista == lista->next &&
        lista->info_socio->id == id_to_remove) {//se lista apenas tem um elemento e ele deve ser removido
        free(lista);
        ls = NULL;
        return;
    }
    do {// percorrer lista ate voltar ao inicial
        if (lista->next->info_socio->id ==
            id_to_remove) {//se encontrar no a remover (->next) por o atual a apontar para 2 nos a frente
            aux = lista->next->next;
            free(lista->next);
            lista->next = aux;
            ls = aux;
            return;
        }
        lista = lista->next;
    } while (lista != inicial);
}

void menu_add_socio() {
    socio *s = calloc(sizeof(socio), 1);
    printf("nome:\n");
    scanf("%s", s->nome);
    printf("apelido:\n");
    scanf("%s", s->apelido);
    s->id = id++;
    inserir_lista_socios(s);
}

void menu_edit_socio() {
    lista_socios edit = ls;
    int id;
    char string[STRSIZE];
    printf("ID de sócio: ");
    scanf("%d^[\n]", &id);
    do {
        if (edit->info_socio->id == id) break;
        edit = edit->next;
    } while (edit != ls);
    if (edit->info_socio->id != id) {
        printf("not found\n");
        return;
    }
    printf("\nNome: %s\nApelido: %s\n", edit->info_socio->nome, edit->info_socio->apelido);
    printf("Novo nome: ");
    scanf("%s^[\n]", string);
    strcpy(edit->info_socio->nome, string);
    printf("Novo apelido: ");
    scanf("%s^[\n]", string);
    strcpy(edit->info_socio->apelido, string);
}

void menu_remove_socio() {
    int id;
    printf("id :");
    scanf("%d", &id);
    getchar();//limpar \n
    remove_lista_socios(id);
}

lista_pagamentos menu_add_paga() {
    pagamento *p = calloc(sizeof(pagamento), 1);
    printf("Montante Pago: ");
    scanf("%d", &(p->montante));
    printf("ID do sócio: ");
    scanf("%d", &(p->id));
    inserir_lista_paga(p);
    return lp;
}

void menu_edit_paga() {
    lista_pagamentos edit = lp;
    int valor;
    printf("ID de sócio: ");
    scanf("%d^[\n]", &id);
    do {
        if (edit->info_pagamento->id == id) break;
        edit = edit->next;
    } while (edit != lp);
    if (edit->info_pagamento->id != id) {
        printf("ID não encontrado.\n");
        return;
    }
    printf("\nMontante: %d\n", edit->info_pagamento->montante);
    printf("Novo Montante: ");
    scanf("%s^[\n]", valor);
    edit->info_pagamento->montante = valor; //estava strcpy aqui
}

void remove_lista_paga(int id_to_remove) {
    lista_pagamentos lista = lp;
    lista_pagamentos inicial = lista;
    lista_pagamentos aux;
    if (lista == NULL) return;//se lista vazia
    if (lista == lista->next &&
        lista->info_pagamento->id == id_to_remove) {//se lista apenas tem um elemento e ele deve ser removido
        free(lista);
        lp = NULL;
        return;
    }
    do {// percorrer lista ate voltar ao inicial
        if (lista->next->info_pagamento->id ==
            id_to_remove) {//se encontrar no a remover (->next) por o atual a apontar para 2 nos a frente
            aux = lista->next->next;
            free(lista->next);
            lista->next = aux;
            lp = aux;
            return;
        }
        lista = lista->next;
    } while (lista != inicial);
}

void menu_remove_paga() {
    int id;
    printf("Insere o ID que pretendes pagar: ");
    scanf("%d^[\n]", &id);
    remove_lista_paga(id);
}

void output() {
    lista_pagamentos listapag = lp;
    char nome[STRSIZE];
    printf("Qual o nome desejado para o ficheiro? ");
    scanf("%s^[\n]", nome);
    FILE *fp = fopen(strcat(nome, ".txt"), "w");
    fprintf(fp, "\n## Sócios com as quotas em dia ##\n");
    lista_socios aux_soc = ls;
    do {
        lista_pagamentos lp_aux = listapag;
        do {
            if (ls->info_socio->id == lp_aux->info_pagamento->id)
                ls->info_socio->saldo += lp_aux->info_pagamento->montante;
            lp_aux = lp_aux->next;
        } while (lp_aux != listapag);
        if (ls->info_socio->saldo >= QUOTA) {
            fprintf(fp, "%d # %s %s # PAGO # Montante pago a mais: %d\n", ls->info_socio->id, ls->info_socio->nome, ls->info_socio->apelido, (ls->info_socio->saldo - QUOTA));
        } else {
            fprintf(fp, "%d # %s %s # POR PAGAR # Dívida: %d\n", ls->info_socio->id, ls->info_socio->nome, ls->info_socio->apelido, (QUOTA - (ls->info_socio->saldo)));
        }
        ls = ls->next;
    } while (ls != aux_soc);
    fclose(fp);
}


void read_from_file_socios() {
    FILE *f = fopen("ficheiro_in_socios", "rb");
    socio s;
    while (fread(&s, 1, sizeof(socio), f)){
        socio *novo = calloc(1, sizeof(socio));
        *novo = s;
        inserir_lista_socios(novo);
    }
    fclose(f);
}

void write_to_file_socios() {
    lista_socios lista = ls;
    FILE *f = fopen("ficheiro_in_socios", "wb");
    do{
        fwrite(lista->info_socio, 1, sizeof(socio), f);
        lista = lista->next;
    }while(lista != ls);
    fclose(f);
}

void write_to_file_paga() {
    lista_pagamentos lista = lp;
    FILE *f = fopen("ficheiro_in_paga", "wb");
    do{
        fwrite(lista->info_pagamento, 1, sizeof(pagamento), f);
        lista = lista->next;
    }while(lista != lp);
    fclose(f);
}

void read_from_file_paga() {
    lista_pagamentos lista = NULL;
    FILE *f = fopen("ficheiro_in_paga", "rb");
    pagamento p;
    while (fread(&p, 1, sizeof(pagamento), f)){
        pagamento *novo = calloc(1, sizeof(pagamento));
        *novo = p;
        inserir_lista_paga(novo);
    }
    fclose(f);
}
