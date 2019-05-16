/* lista.c */

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

void lst_init(lista * l)
{
	l->n = 0;
}

bool lst_acessar(lista l, int k, lst_info * val)
{
	if (k >= 0 && k < l.n) {
		*val = l.itens[k];
		return true;
	}
	return false;
}

bool lst_alterar(lista * l, int k, lst_info val)
{
	if (k >= 0 && k < l->n) {
		l->itens[k] = val;
		return true;
	}
	return false;
}

bool lst_inserir(lista * l, int k, lst_info val) {
	if (l->n < LST_MAX && k >= 0 && k <= l->n) {
		int i;
		for (i = l->n - 1; i >= k; i--) {
			l->itens[i + 1] = l->itens[i];
		}
		l->itens[k] = val;
		l->n++;
		return true;
	}
	return false;
}

bool lst_remover(lista * l, int k, lst_info * val)
{
	if (k >= 0 && k < l->n) {
		int i;
		*val = l->itens[k];
		for (i = k + 1; i < l->n; i++)
			l->itens[i - 1] = l->itens[i];
		l->n--;
		return true;
	}
	return false;
}

void lst_imprimir(lista l)
{
    if (l.n > 0) {
        printf("Elementos da lista: ");
        int i;
        for (i = 0; i < l.n; i++)
            printf("|%d| ", l.itens[i]);
        printf("\n");
    } else
        printf("Lista esta vazia\n");
}

int lst_procurar(lista l, lst_info val)
{
    if (l.n < 0) {
        int i;
        for (i = 0; i < l.n; i++) {
            if (l.itens[i] == val)
                return i;
        }
    }
    return -1;
}

bool lst_ins_ordenado(lista * l, lst_info val)
{
	if (l->n < LST_MAX) {
		int i, j;
		for (i = 0; i < l->n; i++) {
			if (l->itens[i] > val) {
				break;
			}
		}
		for (j = l->n-1; j >= i; j--) {
			l->itens[j + 1] = l->itens[j];
		}
		l->itens[i] = val;
		l->n++;
		return true;
	}
	return false;
}

bool lst_concatenar(lista lst1, lista lst2, lista * lst3)
{
	if (lst1.n + lst2.n <= LST_MAX) {
		int i;
		lst_init(lst3);

		// copia os nós da lista lst1 para a lista lst3
		for (i = 0; i < lst1.n; i++) {
			lst3->itens[i] = lst1.itens[i];
			lst3->n++;
		}
		// insere os nós da lista lst2 na lista lst3
		for (i = 0; i < lst2.n; i++) {
			lst_ins_ordenado(lst3, lst2.itens[i]);
		}
		return true;
	}
	return false;
}

bool lst_inserir_final(lista * l, lst_info x)
{
    if (l->n <= LST_MAX) {
        l->itens[l->n++] = x;
        return true;
    }
    return false;
}

bool lst_inserir_inicio(lista * l, lst_info x)
{
    if (l->n <= LST_MAX) {
        int i;
        for(i = l->n; i > 0; i--)
            l->itens[i] = l->itens[i-1];
        l->itens[0] = x;
        l->n++;
        return true;
    }
    return false;
}

bool lst_remover_final(lista * l, lst_info * x)
{
    if (l->n > 0) {
        *x = l->itens[l->n--];
        return true;
    }
    return false;
}

bool lst_remover_inicio(lista * l, lst_info * x)
{
    if (l->n > 0) {
        int i;
        for(i = l->n; i > 0; i--)
            l->itens[i] = l->itens[i-1];
        *x = l->itens[0];
        l->n--;
        return true;
    }
    return false;
}

bool lst_gerar(lista * l, int n, int max)
{
    if (n <= LST_MAX) {
        lst_init(l);
        while (l->n <= n) {
            l->itens[l->n++] = rand() % (max) + 1;
        }
        return true;
    }
    return false;
}

bool lst_ordena(lista l)
{
    int i;
    for(i = 1; i < l.n; i++)
        if (l.itens[i] < l.itens[i-1])
            return false;
    return true;
}

int lst_remover_menores(lista * l, lst_info x)
{
	int i, j, k, cont = 0;
	for (i = 0; i < l->n; i++) {
		if (l->itens[i] < x) {
			cont++;
			k = i;
			for (j = i + 1; j < l->n; j++) {
				if (l->itens[j] >= x) {
					l->itens[k++] = l->itens[j];
				}
				else {
					cont++;
				}
			}
			break;
		}
	}
	l->n -= cont;
	return cont;
}
