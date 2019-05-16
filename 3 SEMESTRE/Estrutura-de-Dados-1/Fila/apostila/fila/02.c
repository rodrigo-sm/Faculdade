#include "filaNormal.h"
#include <stdbool.h>

void dequeue_and_test(fila * f, queue_info * x, bool * und)
{
    if(!queue_isempty(*f)){
        *x = dequeue(f);
        *und = false;
    } else {
        *und = true;
    }
}
