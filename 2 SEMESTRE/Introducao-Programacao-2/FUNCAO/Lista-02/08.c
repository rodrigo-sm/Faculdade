/*
8. Escreva uma função de protótipo void somabit(int b1, int b2, int * vaium,
int * soma); que recebe três bits (inteiros entre 0 e 1) b1, b2 e vaium e devolve um
bit soma representando a soma dos três e um novo bit “vai-um” em vaium.
*/

#include <stdio.h>

void somabit(int *b1, int *b2, int *vaium, int *soma);

int main()
{
    int b1, b2, vaium, soma;
    scanf("%d %d %d",&b1, &b2, &vaium);
    somabit(b1, b2, *vaium, *soma);
    printf("soma = %d e vaium = %d\n",soma,vaium);
    return 0;
}

void somabit(int *b1, int *b2, int * vaium, int * soma)
{
    int sum;
   sum = b1 + b2 + *vaium;
   switch(sum){
     case 0:
       *soma = 0;
       *vaium = 0;
       break;
     case 1:
       *soma = 1;
       *vaium = 0;
       break;
     case 2:
       *soma = 0;
       *vaium = 1;
       break;
     default:
       *soma = 1;
       *vaium = 1;
   }
}
