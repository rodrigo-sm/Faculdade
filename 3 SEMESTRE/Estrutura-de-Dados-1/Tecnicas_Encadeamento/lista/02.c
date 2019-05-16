/*  Uma forma de minimizar o problema do subdimensionamento ou superdimensionamento da
    implementação sequencial das estruturas de dados dados pilha, fila e lista, seria alocar o
    vetor responsável por armazenar os elementos dessas estruturas em tempo de execução.
    Redefina os TAD’s pilha, fila e lista para que a memória disponível para esses tipos seja
    definida em tempo de execução. */

// LISTA
typedef int lst_info; // tipo de dado da lista
typedef struct lst_no * lst_ptr;
struct lst_no{
 lst_info dado; // vetor para armazenar os nós da lista
 lst_ptr prox; // número de nós da lista
};

void lst_append(lst_ptr * lst1, lst_ptr * lst2)
{
    lst_no l;
    while(l->prox != NULL) l = l->prox;
    l->prox = lst2;
    lst2 = NULL;
}
