/*
1. Escreva uma função que receba um vetor de inteiros de n elementos e troque o 1º
elemento pelo último, o 2º pelo penúltimo, o 3º pelo antepenúltimo, e assim
sucessivamente. Escreva um programa que leia um vetor de inteiros de n elementos,
utilize a função para inverter a ordem dos elementos do vetor e depois mostre o vetor.
*/

#include <stdio.h>

void inverso(int *v);

int main()
{
    int v[10],i;
    printf("INFORME\n\n");
    for(i=0;i<10;i++) scanf("%d", &v[i]);
    inverso(v);
    printf("INVERSO\n\n");
    for(i=0;i<10;i++) printf("%d\n", v[i]);
    return 0;
}

void inverso(int *v)
{
    int i,j,aux;
    for(i=0,j=9;i < j;i++,j--)
    {
        aux = v[i];
        v[i] = v[j];
        v[j] = aux;
    }
}
