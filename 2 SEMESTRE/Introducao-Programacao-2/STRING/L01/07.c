/*
7. Escreva um programa para ler 10 nomes em um vetor de strings A. Depois formar um
vetor de strings B de tal forma que os elementos (nomes) estejam em ordem inversa a do
vetor A.
*/
#include <stdio.h>

int main()
{
    int i,j,x;
    char a[10][81],b[10][81];
    printf("Informe 10 nomes:\n");
    for(i = 0; i < 10; i++)
        scanf(" %80[^\n]", a[i]);
    for(i = 0,j = 9; i < 10; i++,j--)
    {
        for(x = 0; a[j][x] != '\0';x++)
        {
            b[i][x] = a[j][x];
        }
        b[i][x] = '\0';
    }
    printf("Ordem inversa:\n");
    for(i = 0; i < 10; i++)
        printf("%s\n", b[i]);
    return 0;
}
