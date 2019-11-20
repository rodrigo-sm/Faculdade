#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "cobertura_vacinal.h"
#include "hashmap.h"
#include "avl.h"
#include "dados_cobertura_vacinal.h"

void load_dados_cobertura_vacinal(hash_map map, avl_tree * tree) {
    FILE * arq = abre_para_leitura_cobertura_vacinal_file();
    char linha[MAX_LINE];

    cobertura_vacinal_info info;
    map_init(map);
    bool booleano;

    // leitura do arquivo
    while (fscanf(arq, "%[^\n]\n", linha) != EOF) {
        info = configura_vacinal_info(linha);
        map_put(map, info.codigo_munipicio, cria_map_value(info));
        avl_search(tree, cria_avl_info(info), &booleano);
    }

    fclose(arq);
}

FILE * abre_para_leitura_cobertura_vacinal_file() {
    FILE * retorno;
    if ((retorno = fopen(FILENAME_DADOS, "r")) == NULL) {
        fprintf(stderr, "\nErro na abertura do arquivo %s\n", FILENAME_DADOS);
        exit(1);
    }
    return retorno;
}

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

map_value cria_map_value(cobertura_vacinal_info info) {
    map_value retorno;
    retorno.info = info;
    return retorno;
}

avl_info cria_avl_info(cobertura_vacinal_info info) {
    avl_info retorno;
    retorno.info = info;
    return retorno;
}

void exibe_dados_cobertura_vacinal_pelo_codigo_municipio(hash_map map, int codigo_municipio) {
    map_value * dado;
    dado = map_get(map, codigo_municipio);
    printf("\n");
    if(dado == NULL) {
        printf("A base de dados nao contem a cobertura vacinal do municipio com codigo %d\n", codigo_municipio);
        return;
    }
    print_cobertura_vacinal_info(dado->info);
}

int print_n_dados_ordenado_ascendente(avl_tree tree, int quantidade_print) {
    if (tree != NULL) {

        quantidade_print -= quantidade_print -  print_n_dados_ordenado_ascendente(tree->esq,
                                                                               quantidade_print);

        if(seAcabou(quantidade_print)) return VAZIO;

        print_cobertura_vacinal_info(tree->dado.info);
        quantidade_print--;

        quantidade_print -= quantidade_print - print_n_dados_ordenado_ascendente(tree->dir,
                                                                               quantidade_print);

    }

    return quantidade_print;
}

int print_n_dados_ordenado_decrescente(avl_tree tree, int quantidade_print) {
    if (tree != NULL) {

        quantidade_print -= quantidade_print - print_n_dados_ordenado_decrescente(tree->dir,
                                                                            quantidade_print);

        if(seAcabou(quantidade_print)) return VAZIO;

        print_cobertura_vacinal_info(tree->dado.info);
        quantidade_print--;

        quantidade_print -= quantidade_print - print_n_dados_ordenado_decrescente(tree->esq,
                                                                            quantidade_print);

    }

    return quantidade_print;
}

bool seAcabou(int iteracoes) {
    return iteracoes <= 0;
}

void print_cobertura_vacinal_info(cobertura_vacinal_info info) {
    printf("A cobertura vacinal do municipio %s com codigo %d e igual a %.2f\n", info.nome_municipio
                                                                               , info.codigo_munipicio
                                                                               , info.cobertura_vacinal);
}

bool valida_quantidade_de_cidades(int quantidade) {
    if(quantidade > LIMITE_MAXIMO) {
        printf("\nA quantidade de municipios informada e maior que a quantidade total de cidades na base de dados\n");
        return false;
    }
    else if(quantidade < LIMITE_MINIMO) {
        printf("\nA quantidade de municipios informadas e menor que a quantidade minima de cidades na base de dados\n");
        return false;
    }
    return true;
}
