#include "structs.h"
// Programa para tratamento de quotas de um clube de montanhismo
// Francisco Manuel Bandeira Carreira (2019222462) - PPP - 2020

/*
    O programa lê dois ficheiros binários de entrada, que podem ser lidos autonomamente:
    "ficheiro_in_paga.txt": Ficheiro de texto com dois parametros (Montante pago e ID associado a cada transação de dinheiro.).
    "ficheiro_in_socios.txt": Ficheiro de texto com três parametros (nome próprio, apelido e ID generado para efeitos de catalogação).

    O programa escreve os dados tratados num ficheiro de texto com nome pedido ao utilizador.
*/

int main(void) {
    int opcao = 0; // inicialização do int opcao
    lista_socios ls = NULL;
    lista_pagamentos lp = NULL; // primeiro elemento da lista
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
                ls = menu_add_socio(ls); //structs.h
                break;
            case 2:
                menu_edit_socio(ls); //structs.h
                break;
            case 3:
                ls = menu_remove_socio(ls); //structs.h
                break;
            case 4:
                lp = menu_add_paga(lp); //structs.h
                break;
            case 5:
                menu_edit_paga(lp); //structs.h
                break;
            case 6:
                lp = menu_remove_paga(lp); //structs.h
                break;
            case 7:
                print_socios(ls); //structs.h
                break;
            case 8:
                print_pagamentos(lp); //structs.h
                break;
            case 9:
                write_to_file_socios(ls); //structs.h
                write_to_file_paga(lp); //structs.h
                break;
            case 10:
                ls = read_from_file_socios(); //structs.h
                lp = read_from_file_paga(); //structs.h
                break;
            case 11:
                output(ls, lp);
                break;
            default:
                break;
        }
    }
}