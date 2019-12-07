#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaord.h"
#include "hashmap.h"

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
	if (*l == NULL || key < (*l)->key) {
		if ((n = (map_ptr) malloc(sizeof(struct map_node))) == NULL) {
			fprintf(stderr, "Erro de alocacao de memoria!\n");
			exit(1);
		}
		n->key = key;
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
		while (p->prox != NULL && p->prox->key < key)
			p = p->prox;
		if (p->key != key && (p->prox == NULL || p->prox->key != key)) {
			if ((n = (map_ptr) malloc(sizeof(struct map_node))) == NULL) {
				fprintf(stderr, "Erro de alocacao de memoria!\n");
				exit(1);
			}
			n->key = key;
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
		printf("[%d, %s, %f\n]\n ", l->key, l->value->info.nome_municipio, l->value->info.cobertura_vacinal);
		l = l->prox;
	}
}

map_value * lst_rem(map_ptr * l, map_key key)
{
	if (*l == NULL || key < (*l)->key) {
		return NULL;
	}
	if (key == (*l)->key) {
		map_ptr p = *l;
		map_value * val = (*l)->value;
		*l = (*l)->prox;
		free(p);
		return val;
	}
	map_ptr p = *l;
	while (p->prox != NULL && p->prox->key < key) {
		p = p->prox;
	}
	if (p->prox != NULL && p->prox->key == key) {
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
	if (l == NULL || key < l->key) {
		return NULL;
	}
	if (key == l->key) {
		return l->value;
	}
	while (l != NULL && l->key < key) {
		l = l->prox;
	}
	if (l != NULL && l->key == key) {
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
