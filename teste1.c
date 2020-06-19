#include "structs.h"
static int id = 0;

void print_socios(lista_socios ls){
    for(;ls != NULL; ls=ls->next){
        printf("%s\t%s\t%d\n", ls->info_socio->nome, ls->info_socio->apelido, ls->info_socio->id);
    }
}