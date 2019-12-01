/* lista_enc.h */

#ifndef _LISTA_ENC_H
#define _LISTA_ENC_H

#include <stdbool.h>


typedef struct {
    int custo;
    char origem[50];
    char destino[50];
} map_value;

typedef struct lst_no * lst_ptr;

struct lst_no{
	lst_info dado;
	lst_ptr prox;
};

/* função que inicializa a lista */
void lst_init(lst_ptr *);

/* função que acessa o k-ésimo nó da lista e sinaliza o
   sucesso ou falha da operação */
bool lst_acessar(lst_ptr, int, lst_info *);

/* função que altera o valor do k-ésimo nó da lista e
   sinaliza o sucesso ou falha da operação */
bool lst_alterar(lst_ptr, int, lst_info);

/* função que insere um novo nó na k-ésima posição da
   lista e sinaliza o sucesso ou falha da operação */
bool lst_inserir(lst_ptr *, int, lst_info);

/* função que remove o k-ésimo nó da lista e sinaliza
   o sucesso ou falha da operação */
bool lst_remover(lst_ptr *, int, lst_info *);

/* função que imprime o conteúdo da lista */
void lst_imprimir(lst_ptr);

/* função que devolve um ponteiro para nó que contémpum valor na lista,
   ou NULL, caso o valor não esteja contido na lista */
lst_ptr lst_procurar(lst_ptr, lst_info);

/* função que devolve o número de nós da lista */
int lst_tamanho(lst_ptr);

#endif
