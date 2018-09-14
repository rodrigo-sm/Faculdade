/*
14. Escreva um programa que use uma macro MINIMUM2 para determinar o menor entre dois
valores numéricos. Dica: utilize o operador condicional ternário.
*/
#include <stdio.h>
#define MINIMUM2(a,b) a < b? a : b

int main()
{
    int a,b;
    printf("Informe a e b: ");
    scanf("%d %d", &a, &b);
    printf("O menor numero e %d\n",MINIMUM2(a,b));
    return 0;
}
