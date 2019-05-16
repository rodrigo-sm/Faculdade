#include <stdio.h>
#include "filaNormal.h"

void queue_print(fila f)
{
    int i;
    for(i = f.comeco; i % QUEUE_MAX != f.final % QUEUE_MAX; i++)
    {
        fprintf(stdout, "Elemento %d: %d\n", i, f.itens[i % QUEUE_MAX]);
    }
}
