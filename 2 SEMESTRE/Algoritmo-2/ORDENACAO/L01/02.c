/* 01.c
 *
 * Faça uma função que seja capaz de inserir um número N no vetor V na posição correta.
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Algoritmo-II
 *
 * 13/11/2018
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void criaVetor(int *, int);
void ordenaVetor(int *, int);
void posNum(int *, int, int);

int main()
{
    srand(time(NULL));
    int v[100], n;
    criaVetor(v, 100);
    fprintf(stdout, "Informe um numero:\n>>>> ");
    fscanf(stdin, " %d", &n);
    posNum(v, 100, n);
    return 0;
}

void criaVetor(int * v, int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        v[i] = rand() % 1001;
        printf("Cria: %d\n", v[i]);
    }
    ordenaVetor(v, tam);
}

void ordenaVetor(int * v, int tam)
{
    int i, j, aux;
    for(i = 0; i < tam; i++)
        for(j = i+1; j < tam; j++)
            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    for(i = 0; i < tam; i++)
        fprintf(stdout, "Ordena: %d\n", v[i]);
}

void posNum(int *v, int tam, int n)
{
    int i, j, aux, pos;
    for(i = tam; i > 0; i--)
    {
        if(v[i] <= n)
        {
            for(j = tam; j > i; j--)
             v[j] = v[j-1];
            v[i] = n;
        }
    }
    for(i = 0; i < tam; i++)
        fprintf(stdout, "Numero: %d\n", v[i]);
}
