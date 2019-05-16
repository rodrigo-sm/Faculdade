/*
5. Escreva uma função que receba como parâmetro uma matriz quadrada de ordem n de
inteiros e devolve verdadeiro se ela é uma matriz triangular superior, ou falso, caso
contrário. Matriz triangular superior é uma matriz onde todos os elementos de posições
acima da diagonal principal são diferentes de 0 e os demais elementos são iguais a 0.
*/
#include <stdio.h>

int triangular(int n,int v[n][n]);

int main()
{
    int r,i,j,n = 3,v[n][n];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf(" %d", &v[i][j]);
        }
    }
    r = triangular(n,v);
    if(r)
        printf("Matriz e triangular\n");
    else
        printf("Matriz nao e triangular\n");
    return 0;
}

int triangular(int n,int v[n][n])
{
    int i,j;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i < j) // elemento acima da diagonal principal
            {
                if(v[i][j] == 0)
                    return 0;
            }
            else if(v[i][j] != 0)
                return 0;
        }
    }
    return 1;
}
