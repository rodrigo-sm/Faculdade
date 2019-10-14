#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "listaord.h"

void lst_init(lst_ptr * l)
{
    *l = NULL;
}

void lst_ins(lst_ptr * l, lst_info val)
{
    lst_ptr n;
    if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) {
        fprintf(stderr, "Erro de alocacao de memoria!\n");
        exit(1);
    }
    strcpy(n->dado.usuario, val.usuario);
    if (*l == NULL || strcasecmp(val.usuario, (*l)->dado.usuario) <= 0) {
       n->prox = *l;
       *l = n;
    }
    else {
        lst_ptr p = *l;
        while (p->prox != NULL && strcasecmp(val.usuario, p->prox->dado.usuario) > 0) {
            p = p->prox;
        }
        n->prox = p->prox;
        p->prox = n;
    }
}

bool lst_rem(lst_ptr * l, lst_info x)
{
    if (*l == NULL || strcasecmp(x.usuario, (*l)->dado.usuario) < 0) {
        return false;
    }
    else {
        lst_ptr p = *l;
        if (strcasecmp(x.usuario, (*l)->dado.usuario) == 0) {
            *l = p->prox;
            free(p);
            return true;
        }
        else {
            while (p->prox != NULL && strcasecmp(x.usuario, p->prox->dado.usuario) > 0) {
                p = p->prox;
            }
            if (p->prox != NULL && strcasecmp(x.usuario, p->prox->dado.usuario) == 0) {
                lst_ptr n = p->prox;
                p->prox = n->prox;
                free(n);
                return true;
            }
        }
        return false;
    }
}

void lst_print(lst_ptr l)
{
    printf("[ ");
    while (l != NULL) {
        printf("%s,", l->dado.usuario);
        l = l->prox;
    }
    printf("\b ]\n");
}

/*  Esta função receberá a lista encadeada (amigos) e um ponteiro de arquivo.
*   Seu propósito é salvar esta lista no arquivo correspondente.
*/
void lst_save(lst_ptr l, FILE * arq) {
    fprintf(arq, "%s", l->dado.usuario);
    l = l->prox;
    while (l != NULL) {
        fprintf(arq, ";%s", l->dado.usuario);
        l = l->prox;
    }
    fprintf(arq, "\n");
}

