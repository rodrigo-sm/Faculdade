#ifndef 04_H_INCLUDED
#define 04_H_INCLUDED

#include <stdbool.h>

#define QUEUE_MAX 50   // tamanho máximo da fila
typedef int queue_info;
typedef struct {
    queue_info itens[QUEUE_MAX]; // itens da fila
    int comeco, // índice para o início da fila
        final;  // índice para o final da fila
} fila;

/* função que inicializa uma fila */
void deque_init(fila *);

/* função que verifica se a fila está vazia, eetorna verdadeiro, se a
 * fila está vazia, ou falso, caso contrário. */
bool deque_isempty(fila);

/* função que verifica se a fila está cheia, retorna verdadeiro, se a
 * fila está cheia ou falso, caso contrário. */
bool deque_isfull(fila);

/* função para inserir um novo elemento no começo da fila */
void deque_ins_frente(fila *, queue_info);

/* função para inserir um novo elemento no final da fila */
void deque_ins_tras(fila *, queue_info);

/* função para remover o elemento do começo da fila */
void deque_rem_frente(fila *);

/* função para remover o elemento do final da fila */
void deque_rem_tras(fila *);

/* função para imprimir o conteudo da fila */
void deque_print(fila f);

#endif // 04_H_INCLUDED
