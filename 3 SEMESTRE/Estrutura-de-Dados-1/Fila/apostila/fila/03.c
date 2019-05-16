#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "03.h"

#define QUEUE_MAX 50   // tamanho máximo da fila
typedef int queue_info;
typedef struct {
    queue_info itens[QUEUE_MAX]; // itens da fila
    int comeco, // índice para o início da fila
        final;  // índice para o final da fila
} fila;

void queue_init(fila * f) {
  f->comeco = f->final = 0;
}

bool queue_isempty(fila f) {
   return (f.comeco == f.final);
}

bool queue_isfull(fila f) {
   return (f.final >= QUEUE_MAX);
}

void enqueue(fila * f, queue_info x) {
   if (!queue_isfull(*f)) {
        if(f->final == QUEUE_MAX) {
            desloca_queue(f);
        }
      f->itens[f->final] = x;
      f->final++;
   }
   else {
      fprintf(stderr, "Estouro da Fila!\n");
      exit(1);
   }
}

queue_info dequeue(fila * f) {
   if (!queue_isempty(*f)) {
      queue_info x = f->itens[f->comeco];
      f->comeco++;
      return x;
   }
   else {
      fprintf(stderr, "Fila vazia!\n");
      exit(1);
   }
}

void desloca_queue(fila *f)
{
    int i, j;
    for(i = 0, j; f->comeco < f->final; f->comeco++)
        f->itens[i] = f->itens[f->comeco];
    f->final = i;
    f->comeco = 0;
}
