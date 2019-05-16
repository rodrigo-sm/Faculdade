/*
6. Escreva uma função que receba uma matriz A bidimensional de valores reais e um valor
real x, e multiplique todos os elementos de A por x.
*/
#include <stdio.h>

void multiplique(float m[2][2],float x);

int main()
{
    int i,j;
    float m[2][2],x;
    printf("Informe x: ");
    scanf("%f", &x);
    printf("Informe a matriz:\n");
    for(i = 0;i < 2;i++)
        for(j = 0;j < 2;j++)
            scanf(" %f", &m[i][j]);
    multiplique(m,x);
    for(i = 0;i < 2;i++)
    {
        for(j = 0;j < 2;j++)
        {
            printf("%.2f ", m[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void multiplique(float m[2][2],float x)
{
    int i,j;
    for(i = 0;i < 2;i++)
        for(j = 0;j < 2;j++)
            m[i][j] *= x;
}
