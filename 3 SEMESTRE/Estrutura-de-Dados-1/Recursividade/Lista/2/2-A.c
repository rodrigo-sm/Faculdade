#include <stdio.h>

void imprimirLista(lst_ptr);

int main()
{

}

void imprimirLista(lst_ptr lst)
{
    if(lst->prox != NULL) imprimirLista(lst->prox);
    printf("%d ", lst->dado);
}
