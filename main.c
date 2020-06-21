#include "structs.h"
// Programa para tratamento de quotas de um clube de montanhismo
// Francisco Manuel Bandeira Carreira (2019222462) - PPP - 2020

/*
    O programa lê e escreve dois ficheiros binários de entrada, que podem ser lidos autonomamente:
    "ficheiro_in_paga": Ficheiro de texto com dois parametros (Montante pago e ID associado a cada transação de dinheiro.).
    "ficheiro_in_socios": Ficheiro de texto com três parametros (nome próprio, apelido e ID generado para efeitos de catalogação).

    O programa escreve os dados tratados num ficheiro de texto com nome pedido ao utilizador.
*/

int main(void) {
    int opcao = 0; // inicialização do int opcao
    while (opcao != 11){
        printf("1 - Adicionar Sócio.\n");
        printf("2 - Editar Sócio.\n");
        printf("3 - Remover Sócio.\n");
        printf("4 - Adicionar Pagamento.\n");
        printf("5 - Editar Pagamento.\n");
        printf("6 - Remover Pagamento.\n");
        printf("7 - Imprimir Sócios.\n");
        printf("8 - Imprimir Pagamentos.\n");
        printf("9 - Salvar ficheiros para propósitos de entrada.\n");
        printf("10 - Abrir ficheiros para propósitos de entrada.\n");
        printf("11 - Imprimir Output em ficheiro .txt\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                menu_add_socio(); //funcoes.c
                break;
            case 2:
                menu_edit_socio(); //funcoes.c
                break;
            case 3:
                menu_remove_socio(); //funcoes.c
                break;
            case 4:
                menu_add_paga(); //funcoes.c
                break;
            case 5:
                menu_edit_paga(); //funcoes.c
                break;
            case 6:
                menu_remove_paga(); //funcoes.c
                break;
            case 7:
                print_socios(); //funcoes.c
                break;
            case 8:
                print_pagamentos(); //funcoes.c
                break;
            case 9:
                write_to_file_socios(); //funcoes.c
                write_to_file_paga(); //funcoes.c
                break;
            case 10:
                read_from_file_socios(); //funcoes.c
                read_from_file_paga(); //funcoes.c
                break;
            case 11:
                output(); //funcoes.c
                break;
            default:
                break;
        }
    }
}