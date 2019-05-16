/*
8. Escreva um programa para ler 8 nomes em cada um dos vetores de strings A e B.
Construir um vetor de strings C, que será formada por um elemento do vetor A e por um
elemento do vetor B, intercaladamente.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char a[8][81],b[8][81],c[16][81];
    int x,y;
    printf("Informe a matriz A:\n");
    for(x=0; x<8; x++)
    {
        scanf(" %80[^\n]", a[x]);
    }
    printf("\n");
    printf("Informe a matriz B:\n");
    for(x=0; x<8; x++)
    {
        scanf(" %80[^\n]", b[x]);
    }
    printf("\n");
    for(x=0,y=0; x<16; x++,y++)
    {
        strcpy(c[x], a[y]);
        x++;
        strcpy(c[x], b[y]);
    }
    printf("Matriz C:\n\n");
    for(x=0; x<16; x++)
    {
        printf("%s\n", c[x]);
    }
    return 0;
}
