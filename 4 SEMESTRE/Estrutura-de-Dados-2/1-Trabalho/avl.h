#ifndef _AVL_H
#define _AVL_H

#include <stdbool.h>
#include "listaord.h"
#include <stdio.h>

typedef struct {
 char usuario[21]; // nome de usuário
 char nome_completo[51]; // nome completo
 char sexo;
 lst_ptr amigos; // lista encadeada ordenada dos amigos
} avl_info;

typedef struct avl_no * avl_tree;

struct avl_no {
 avl_info dado;
 avl_tree esq;
 avl_tree dir;
 int bal; // balanceamento do nó
};

/*
 * Imprime a árvore AVL t através de um percurso em ordem.
 */
void print_tree(avl_tree t);

/*
 * Imprime a informaçao de um no da arvore
 */
 void print_info(avl_tree t);

/*
 * Salva a arvore avl em arquivo .txt
 */
void save_tree(avl_tree t, FILE * arq);

/*
 * Verifica se a palavra x já ocorreu na árvore AVL t;
 * caso afirmativo, seu contador é incrementado; caso contrário,
 * x é inserida em t e h sinaliza que houve um aumento da
 * altura de t.
 */
bool avl_search(avl_tree * t, avl_info x, bool * h);


/*
 * Faz uma rotação para a direita na árvore AVL t.
 */
void rotacao_dir(avl_tree * t);


/*
 * Faz uma rotação para a esquerda na árvore AVL t.
 */
void rotacao_esq(avl_tree *);

/*
 * Se a palavra x está contida na árvore AVL t, x é
 * removida de t, h sinaliza uma diminuição da altura
 * de t e a função devolve verdadeiro; caso contrário,
 * nada é feito e a função devolve falso.
 */
bool delete_avl_no(avl_tree * t, avl_info * x, bool * h);


/*
 * Faz o balanceamento da árvore AVL t após uma remoção
 * em sua subárvore esquerda e sinaliza se houve uma
 * dimuição da altura dessa subárvore através de h.
 */
void balance_esq(avl_tree * t, bool * h);


/*
 * Faz o balanceamento da árvore AVL t após uma remoção
 * em sua subárvore direita e sinaliza se houve uma
 * dimuição da altura dessa subárvore através de h.
 */
void balance_dir(avl_tree *, bool *);

/*
 * Devolve um ponteiro para o nó que contém o menor
 * valor na árvore AVL t e sinaliza através de h se
 * houve uma diminuição da altura de t.
 */

/*
 * Vai procurar o no atraves de seu elemento chave e retornar true se existir
 * ou false se nao existir
 */
avl_tree avl_find(avl_tree t, char * chave);

avl_tree get_min(avl_tree * t, bool * h);

#endif
