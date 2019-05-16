#include <stdio.h>

void leVetor(int *, int);
void imprimeVetor(int *, int);
void ordenaVetor(int *, int);

int main()
{
    int n;
    fprintf(stdout, "Tamanho do vetor:\n>>>> ");
    fscanf(stdin, " %d", &n);
    int v[n];
    leVetor(v, n);
    ordenaVetor(v, n);
    imprimeVetor(v, n);
}

void leVetor(int *v, int max)
{
    int i;
    fprintf(stdout, "===================\nInforme %d numeros:\n===================\n", max);
    for(i = 0; i < max; i++)
    {
        fprintf(stdout, "Num %d >>> ", i);
        fscanf(stdin, " %d", &v[i]);
    }
}

void imprimeVetor(int *v, int max)
{
    int i;
    fprintf(stdout, "===================\n\tVetor:\n===================\n");
    for(i = 0; i < max; i++)
    {
        fprintf(stdout, "Num %d: %d\n", i, v[i]);
    }
}

void ordenaVetor(int *v, int max)
{
    int i, j, aux;
    for(i = 0; i < max; i++)
    {
        for(j = 0; j < max; j++)
        {
            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    }
}
