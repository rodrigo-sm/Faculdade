/*
7. Implemente uma função para multiplicar uma matriz An x m por uma matriz Bm x k e resulta
em uma matriz Cn x k que tem o seguinte protótipo:
void mult_mat(int n, int m, int k, int a[][m],
 int b[][k], int c[][k]);
*/

#include <stdio.h>

void mult_mat(int n, int m, int k, int a[][m], int b[][k], int c[][k]);

int main()
{
    int n = 2,m = 2,k = 2;
    int a[n][m],b[n][k],c[n][k];
    int i,j;
    printf("Informe a matriz a:\n");
    for(i = 0;i < n;i++)
        for(j = 0;j < m;j++)
            scanf(" %d", &a[i][j]);
    printf("Informe a matriz a:\n");
    for(i = 0;i < n;i++)
        for(j = 0;j < k;j++)
            scanf(" %d", &b[i][j]);
    mult_mat(n,m,k,a,b,c);
    printf("Matriz c:\n");
    for(i = 0;i < n;i++)
    {
        for(j = 0;j < k;j++)
        {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void mult_mat(int n, int m, int k, int a[][m], int b[][k], int c[][k])
{
    int i,j;
    for(i = 0;i < n;i++)
        for(j = 0;j < k;j++)
            c[i][j] = a[i][j] * b[i][j];
}
