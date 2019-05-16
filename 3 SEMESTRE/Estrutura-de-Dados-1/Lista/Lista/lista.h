/* lista.h */

#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

#define LST_MAX 100 // número de elementos do vetor
typedef int lst_info; // tipo de dado da lista
typedef struct {
	lst_info itens[LST_MAX]; // vetor p/ os nós da lista
	int n; // número de nós da lista
} lista;

/* função que inicializa a lista */
void lst_init(lista *);

/* função que acessa o k-ésimo nó da lista e sinaliza o
   sucesso ou falha da operação */
bool lst_acessar(lista, int, lst_info *);

/* função que altera o valor do k-ésimo nó da lista e
   sinaliza o sucesso ou falha da operação */
bool lst_alterar(lista *, int, lst_info);

/* função que insere um novo nó na k-ésima posição da
   lista e sinaliza o sucesso ou falha da operação */
bool lst_inserir(lista *, int, lst_info);

/* função que remove o k-ésimo nó da lista e sinaliza
   o sucesso ou falha da operação */
bool lst_remover(lista *, int, lst_info *);

/* função que imprime o conteúdo da lista */
void lst_imprimir(lista);

/* função que devolve a posição de um valor na lista,
   ou -1, caso o valor não esteja contido na lista */
int lst_procurar(lista, lst_info);

/* função que insere um novo nó em uma lista ordenada */
bool lst_ins_ordenado(lista *, lst_info);

/* função que concatena duas listas ordenadas e gera uma
   terceira lista também ordenada */
bool lst_concatenar(lista, lista, lista *);

/* função que insere a variavel x no final da lista l */
bool lst_inserir_final(lista *, lst_info);

/* função que insere a variavel x no inicio da lista l*/
bool lst_inserir_inicio(lista *, lst_info);

/* função que remove o ultimo valor da lista l e insere
   na variavel x */
bool lst_remover_final(lista *, lst_info *);

/* função que remove o primeiro valor da lista l e insere
   na variavel x */
bool lst_remover_inicio(lista *, lst_info *);

/* função que gera uma lista de n nós com valores aleatórios
   no intervalo de 1 ao 3º argumento da função */
bool lst_gerar(lista *, int, int);

/* função que verifica se uma lista l esta em ordem crescente */
bool lst_ordena(lista);

/* função que remove todos os nós com valores menores que
   um determinado valor e devolve o número de remoções */
int lst_remover_menores(lista *, lst_info);

#endif
