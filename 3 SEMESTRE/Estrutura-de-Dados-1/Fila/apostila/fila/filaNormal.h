#ifndef FILANORMAL_H_INCLUDED
#define FILANORMAL_H_INCLUDED

#include <stdbool.h>

#define QUEUE_MAX 50   // tamanho máximo da fila
typedef int queue_info;
typedef struct {
    queue_info itens[QUEUE_MAX]; // itens da fila
    int comeco, // índice para o início da fila
        final;  // índice para o final da fila
} fila;

/* função que inicializa uma fila */
void queue_init(fila *);

/* função que verifica se a fila está vazia, eetorna verdadeiro, se a
 * fila está vazia, ou falso, caso contrário. */
bool queue_isempty(fila);

/* função que verifica se a fila está cheia, retorna verdadeiro, se a
 * fila está cheia ou falso, caso contrário. */
bool queue_isfull(fila);

/* função para inserir um novo elemento no final da fila */
void enqueue(fila *, queue_info);

/* função para remover o elemento do começo da fila */
queue_info dequeue(fila *);

#endif // _FILA_H
