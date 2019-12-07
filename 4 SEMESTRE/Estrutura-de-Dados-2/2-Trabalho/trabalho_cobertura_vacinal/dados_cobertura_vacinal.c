#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dados_cobertura_vacinal.h"

cobertura_vacinal_info configura_vacinal_info(char * linha) {
    cobertura_vacinal_info retorno;

    char *token = strtok(linha, SEPARADOR);
    retorno.codigo_munipicio = atoi(token);

    token = strtok(NULL, SEPARADOR);
    strcpy(retorno.nome_municipio, token);

    token = strtok(NULL, SEPARADOR);
    retorno.cobertura_vacinal = atof(token);

    return retorno;
}

void print_cobertura_vacinal_info(cobertura_vacinal_info info) {
    printf("A cobertura vacinal do municipio %s com codigo %d e igual a %.2f\n", info.nome_municipio
                                                                               , info.codigo_munipicio
                                                                               , info.cobertura_vacinal);
}
