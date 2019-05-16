/* 01.c
 *
 * Programa gera um vetor de 10000 posicoes preenchidos por numeros 99999 < n < 0, e realiza uma busca ordena e outra nao ordenada
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
void buscaNum(int *, int, int);

int main()
{
    srand(time(NULL));
    int v[1000], n;
    criaVetor(v, 1000);
    fprintf(stdout, "Informe um numero:\n>>>> ");
    fscanf(stdin, " %d", &n);
    system("cls");
    fprintf(stdout, "Numero-Alvo: %d\n\n", n);
    fprintf(stdout, "Busca nao ordenada ======\n", n);
    buscaNum(v, 1000, n);
    ordenaVetor(v, 1000);
    fprintf(stdout, "\nBusca ordenada ======\n", n);
    buscaNum(v, 1000, n);
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
}

void buscaNum(int * v, int tam, int n)
{
    clock_t tempo;
    tempo = clock();
    int  i;
    for(i = 0; i < tam; i++)
        if(v[i] == n)
        {
            fprintf(stdout, "Posicao: %d\nTotal de iteracoes: %d\nTempo de execucao: %lf\n", i, i, (double) (clock() - tempo)  / CLOCKS_PER_SEC);
            break;
        }
    if(v[i] != n)
        fprintf(stdout, "Numero nao encontrado\nTempo de execucao: %lf\n", (double) (clock() - tempo)  / CLOCKS_PER_SEC);
}

