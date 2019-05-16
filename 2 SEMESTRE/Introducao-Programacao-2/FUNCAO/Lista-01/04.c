/*Escreva uma função de protótipo void retangulo(int a, int c); que desenha no
vídeo um retângulo formado por asteriscos (*) com a linhas de altura e c colunas de
comprimento. Por exemplo, se for feita a seguinte chamada a função: retangulo(5, 10);
A função deve desenhar no vídeo o seguinte retângulo:
**********
**********
**********
**********
**********/
#include <stdio.h>

void retangulo(int a, int c);

int main()
{
    int a,c;
    scanf("%d %d", &a, &c);
    retangulo(a,c);
}

void retangulo(int a, int c)
{
    int x,y;
    for(x=0;x < a; x++)
    {
        for(y=0;y<c; y++)
        {
            printf("*");
        }
        printf("\n");
    }
}
