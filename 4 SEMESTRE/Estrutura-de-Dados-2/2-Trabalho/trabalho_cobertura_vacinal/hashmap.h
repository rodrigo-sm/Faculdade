/* hashmap.h
 *
 * Defenição do TAD hash_map e protótipos de suas operações
 *
 * 30/out/2019
 *
 * Ciro C. Trindade */

#ifndef _HASHMAP_H
#define _HASHMAP_H

#include <stdbool.h>

#include "dados_cobertura_vacinal.h"

#define M 1024  // número de encaixes da tabela de hashing
#define NUM_BITS 16

typedef int map_key;

typedef struct map_node * map_ptr;

typedef struct {
    cobertura_vacinal_info info;
} map_value;

struct map_node {
    map_key key;
    map_value * value;
    map_ptr prox;
};

typedef map_ptr hash_map[M];

/* função que inicializa o hash map */
void map_init(hash_map);

/* função que devolve o número de elementos do hash mapa */
int map_size(hash_map);

/* função que devolve verdadeiro se o hash map estiver vazio */
bool map_isempty(hash_map);

/* função que devolve o endereço do valor associado a chave no mapa,
   caso a chave esteja contida no mapa, ou NULL, caso contrário */
map_value * map_get(hash_map, map_key);

/* função que insere a entrada (chave, valor) no mapa se mapa não possuir
   um entrada para a chave */
void map_put(hash_map, map_key, map_value);

/* função que remove a entrada (chave, valor) do mapa e devolve o endereço
   do valor, caso a chave esteja contido no mapa, ou NULL, caso contrário */
map_value * map_remove(hash_map, map_key);

/* função de hashing que utiliza o método do meio do quadrado */
int h(map_key);

/* função que imprime todas as entradas do hash map */
void map_print(hash_map);

/* função que destrói o hash_map */
void map_kill(hash_map);

#endif // _HASHMAP_H
