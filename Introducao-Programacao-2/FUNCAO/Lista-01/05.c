/*Escreva uma função de protótipo void  triangulo(int  n, char  ch); que desenha no
vídeo um triângulo invertido formado por n caracteres ch em sua base. Por exemplo, se for feita
seguinte chamada a função: triangulo(7, '#');
A função deve desenhar no vídeo o seguinte triângulo:
#######
 #####
  ###
   #*/

#include <stdio.h>

void  triangulo(int  n, char  ch);

int main()
{
    int n;
    char ch;
    scanf("%d %c", &n, &ch);
    triangulo(n,ch);
    return 0;
}

void  triangulo(int  n, char  ch)
{
    int x,y,c=0;
    while(n>0)
    {
        for(y=0;y<n; y++)
        {
            printf("%c", ch);
        }
        printf("\n");
        n -= 2;
        c++;
        for(x=0;x<c;x++)
        {
            printf(" ");
        }

    }

}
