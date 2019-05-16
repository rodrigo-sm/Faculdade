#include <stdlib.h>
#include <stdio.h>
#include "04.h"
#include <stdbool.h>

void deque_init(fila * f) {
  f->comeco = f->final = 0;
}

bool deque_isempty(fila f) {
   return (f.final - f.comeco == QUEUE_MAX);
}

bool deque_isfull(fila f) {
   return (f.comeco == f.final);
}

void deque_ins_frente(fila * f, queue_info x) {
   if (!queue_isfull(*f)) {
      f->itens[f->comeco] = x;
      f->comeco++;
   }
   else {
      fprintf(stderr, "Estouro da Fila!\n");
      exit(1);
   }
}

void deque_ins_tras(fila * f, queue_info x) {
   if (!queue_isfull(*f)) {
      f->itens[f->final] = x;
      f->comeco--;
   }
   else {
      fprintf(stderr, "Estouro da Fila!\n");
      exit(1);
   }
}

queue_info deque_rem_frente(fila * f) {
   if (!queue_isempty(*f)) {
      queue_info x = f->itens[f->comeco];
      f->comeco--;
      return x;
   }
   else {
      fprintf(stderr, "Fila vazia!\n");
      exit(1);
   }
}

queue_info deque_rem_tras(fila * f) {
   if (!queue_isempty(*f)) {
      queue_info x = f->itens[f->final];
      f->final++;
      return x;
   }
   else {
      fprintf(stderr, "Fila vazia!\n");
      exit(1);
   }
}

void deque_print(fila f)
{
    printf("Conteudo da fila\n");
    for(i = f.comeco; i < f.final; i++)
        printf("Elemento %d: %d\n", i, f.itens[i]);
}
