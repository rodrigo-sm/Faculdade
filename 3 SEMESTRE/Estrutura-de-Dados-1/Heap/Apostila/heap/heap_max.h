#ifndef HEAP_MAX_H_INCLUDED
#define HEAP_MAX_H_INCLUDED

/* função que cria um heap mínimo */
void make_heap_max(int [], int);

/* função que remove o menor elemento do heap mínimo e
   reconstrói o heap */
void ins_heap_max(int [], int *, int);

/* função que insere um novo elemento no heap mínimo */
int rem_heap_max(int [], int *);

#endif // HEAP_MAX_H_INCLUDED

