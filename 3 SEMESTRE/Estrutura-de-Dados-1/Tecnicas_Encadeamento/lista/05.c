/*  Escreva uma função void dlst_append(dlst_ptr lst1, dlst_ptr lst2); que
    acrescenta no final da lista lst1 os elementos da lista lst2. A lista lst2 deve ficar vazia após a
    execução desta função. Considere que as listas são representadas através do encadeamento
    circular duplo com nó cabeça  */

void dlst_append(dlst_ptr lst1, dlst_ptr lst2)
{
    lst1->ant->prox = lst2->ant;
    lst2->ant->ant = lst1->ant;
    lst1->prox->ant = lst2->prox;
    lst2->prox->prox = lst1->prox;
    lst2 = NULL;
}
