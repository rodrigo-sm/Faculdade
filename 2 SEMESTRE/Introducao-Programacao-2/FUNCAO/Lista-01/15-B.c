/*
     Usando a função do item anterior, faça um programa que lê dois inteiros positivos a e b e
    responda se a é permutação de b.
*/

#include <stdio.h>

void permutacao(int a, int b);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    permutacao( a , b);
    return 0;
}

void permutacao(int a, int b)
{
    int p = a;
    while(a-- != 1) p *= a;
    if(p == b) printf("TRUE\n");
    else       printf("FALSE\n");
}
