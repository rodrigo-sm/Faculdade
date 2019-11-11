#ifndef COBERTURA_VACINAL_H_INCLUDED
#define COBERTURA_VACINAL_H_INCLUDED

#include <stdio.h>

#include "hashmap.h"
#include "avl.h"

void load_dados_cobertura_vacinal(hash_map, avl_tree *);
void exibe_dados_cobertura_vacinal_pelo_codigo_municipio(hash_map, int);
int print_n_dados_ordenado_ascendente(avl_tree, int);
int print_n_dados_ordenado_decrescente(avl_tree, int);
cobertura_vacinal_info configura_vacinal_info(char *);
FILE * abre_para_leitura_cobertura_vacinal_file();
map_value cria_map_value(cobertura_vacinal_info);
avl_info cria_avl_info(cobertura_vacinal_info);
void print_cobertura_vacinal_info(cobertura_vacinal_info);
bool seAcabou(int);
int diferenca(int, int);
bool valida_quantidade_de_cidades(int quantidade);

#endif // COBERTURA_VACINAL_H_INCLUDED
