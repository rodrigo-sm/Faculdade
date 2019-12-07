/* listaord.h
 *
 * Definição do TAD para uma lista linear encadeada adaptada
 * para um hash map.
 *
 * 30/out/2019
 *
 * Ciro C. Trindade */

#ifndef _LISTAORD_H
#define _LISTAORD_H

#include <stdbool.h>

#include "hashmap.h"

/* função que inicializa a lista encadeada ordenada */
void lst_init(map_ptr *);

/* função que devolve o número de elementos da lista */
int lst_size(map_ptr);

/* função que devolve verdadeiro se a lista estiver vazia */
bool lst_isempty(map_ptr);

/* função que insere um novo par (chave, valor) na lista */
void lst_ins(map_ptr *, map_key, map_value);

/* função que imprime a lista */
void lst_print(map_ptr);

/* função que remove a entrada (chave, valor) e devolve o
   endereço do valor, caso sua chave esteja na lista, ou NULL,
   caso contrário */
map_value * lst_rem(map_ptr *, map_key);

/* função que e devolve o endereço do valor, caso sua chave
   esteja na lista, ou NULL, caso contrário */
map_value * lst_find(map_ptr, map_key);

/* função que desaloca a lista */
void lst_kill(map_ptr *);

#endif
