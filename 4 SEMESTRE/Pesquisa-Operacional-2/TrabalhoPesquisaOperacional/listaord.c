/* listaord.c
 *
 * Implementação das operações sobre o TAD lista encadeada ordenada adaptada
 * para um hash map.
 *
 * 30/outubro/2019
 *
 * Ciro C. Trindade */

#include "listaord.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void lst_init(map_ptr * l)
{
	*l = NULL;
}

int lst_size(map_ptr l)
{
	int cont = 0;
	while (l != NULL) {
		cont++;
		l = l->prox;
	}
	return cont;
}

bool lst_isempty(map_ptr l)
{
	return l == NULL;
}

void lst_ins(map_ptr * l, map_key key, map_value val)
{
	map_ptr n;
	if (*l == NULL || strcmp(key, (*l)->key) < 0) {
		if ((n = (map_ptr) malloc(sizeof(struct map_node))) == NULL) {
			fprintf(stderr, "Erro de alocacao de memoria!\n");
			exit(1);
		}
		strcpy(n->key, key);
		if ((n->value = (map_value *) malloc(sizeof(map_value))) == NULL) {
			fprintf(stderr, "Erro de alocacao de memoria!\n");
			exit(1);
		}
		*(n->value) = val;
		n->prox = *l;
		*l = n;
	}
	else {
		map_ptr p = *l;
		while (p->prox != NULL && strcmp(p->prox->key, key) < 0)
			p = p->prox;
		if (strcmp(p->key, key) != 0 && (p->prox == NULL || strcmp(p->prox->key, key) != 0)) {
			if ((n = (map_ptr) malloc(sizeof(struct map_node))) == NULL) {
				fprintf(stderr, "Erro de alocacao de memoria!\n");
				exit(1);
			}
			strcpy(n->key, key);
			if ((n->value = (map_value *) malloc(sizeof(map_value))) == NULL) {
				fprintf(stderr, "Erro de alocacao de memoria!\n");
				exit(1);
			}
			*(n->value) = val;
			n->prox = p->prox;
			p->prox = n;
		}
		else { // já existe na lista, atualiza seu valor
			*((*l)->value) = val;
		}
	}
}

void lst_print(map_ptr l)
{
	while (l != NULL) {
		printf("(%s, %s) ", l->key, l->value->nome);
		l = l->prox;
	}
}

map_value * lst_rem(map_ptr * l, map_key key)
{
	if (*l == NULL || strcmp(key, (*l)->key) < 0) {
		return NULL;
	}
	if (strcmp(key, (*l)->key) == 0) {
		map_ptr p = *l;
		map_value * val = (*l)->value;
		*l = (*l)->prox;
		free(p);
		return val;
	}
	map_ptr p = *l;
	while (p->prox != NULL && strcmp(p->prox->key, key) < 0) {
		p = p->prox;
	}
	if (p->prox != NULL && strcmp(p->prox->key, key) == 0) {
		map_ptr n = p->prox;
		map_value * val = p->prox->value;
		p->prox = n->prox;
		free(n);
		return val;
	}
	return NULL;
}

map_value * lst_find(map_ptr l, map_key key)
{
	if (l == NULL || strcmp(key, l->key) < 0) {
		return NULL;
	}
	if (strcmp(key, l->key) == 0) {
		return l->value;
	}
	while (l != NULL && strcmp(l->key, key) < 0) {
		l = l->prox;
	}
	if (l != NULL && strcmp(l->key, key) == 0) {
		return l->value;
	}
	return NULL;
}

void lst_kill(map_ptr * l)
{
	map_ptr p;
	while (*l != NULL)	{
		p = *l;
		*l = p->prox;
		free(p);
	}
}
