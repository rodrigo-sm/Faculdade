/*  Escreva uma função lst_info lst_delete_last(lst_ptr * lst); que dada uma
    lista encadeada simples não nula lst, remove e devolve o último elemento da lista lst. */


lst_info lst_delete_last(lst_ptr * lst)
{
    lst_info n;
    lst_ptr l;
    while(l->prox != NULL) l = l->prox;
    n = l->dado;
    free(l);
    return n;
}
