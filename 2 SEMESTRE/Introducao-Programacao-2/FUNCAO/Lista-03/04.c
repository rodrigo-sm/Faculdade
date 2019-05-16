/*
4. Escreva uma função que recebe um vetor de strings com até 20 caracteres cada e o número
de strings do vetor como parâmetros, e devolve verdadeiro se o vetor está em ordem
alfabética (crescente), ou falso, caso contrário. A função deve ter o seguinte protótipo:
bool esta_ordenado(char vetor[][21], int n);
*/
#include <stdio.h>

int esta_ordenado(char vetor[][21], int n);

int main()
{
    int n=5,r,i;
    char str[n][21];
    for(i=0;i<n;i++)
        scanf(" %20[^\n]", str[i ]);
    r = esta_ordenado(str,n);
    printf("%d\n", r);
    return 0;
}

int esta_ordenado(char vetor[][21], int n)
{
    int i,j,x;
    for(i = 0;i < n;i++)
    {
        for(j = i+1;j < n;j++)
        {
            for(x=0;vetor[i][x] == vetor[j][x];x++ );
            if(vetor[i][x] > vetor[j][x])
                return 0;
        }
    }
    return 1;
}
