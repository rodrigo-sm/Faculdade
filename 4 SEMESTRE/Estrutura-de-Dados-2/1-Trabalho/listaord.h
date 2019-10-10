#ifndef _LISTAORD_H
#define _LISTAORD_H
#include <stdbool.h>
#include <stdio.h>


typedef struct {
 char usuario[21]; // nome de usuário
} lst_info;

typedef struct lst_no * lst_ptr;
struct lst_no {
    lst_info dado;
    lst_ptr prox;
};

/* inicializa a lista ordenada */
void lst_init(lst_ptr *);

/* insere um novo elemento na lista ordenada */
void lst_ins(lst_ptr *, lst_info);

/* remove um elemento da lista ordenada */
bool lst_rem(lst_ptr *, lst_info);

/* imprime os elementos da lista ordenada */
void lst_print(lst_ptr);

/* salva os elementos da lista ordenada em um arquivo .txt */
void lst_save(lst_ptr l, FILE * arq);

#endif
