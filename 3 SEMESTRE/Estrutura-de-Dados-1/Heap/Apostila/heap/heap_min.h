#ifndef HEAP_MIN_H_INCLUDED
#define HEAP_MIN_H_INCLUDED

/* função que cria um heap mínimo */
void make_heap_min(int [], int);

/* função que remove o menor elemento do heap mínimo e
   reconstrói o heap */
int rem_heap_min(int [], int *);

/* função que insere um novo elemento no heap mínimo */
void ins_heap_min(int [], int *, int);

#endif // HEAP_MIN_H_INCLUDED
