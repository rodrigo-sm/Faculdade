/*Escreva uma função para calcular e devolver o fatorial de um número natural passado como
parâmetro.*/

#include <stdio.h>

void fatorial(int *x);

int main ()
{
    int x;
    scanf(" %d", &x);
    fatorial( &x);
    printf("%d\n", x);
    return 0;
}

void fatorial(int *x)
{
    int n1 = 1, n2 = *x,c=1;
    while(c < n2)
    {
        if((n2 % c) == 0)
        {
            n1 *= c;
            if(n1 == n2)
            {
                *x = c;
                break;
            }
        }
        c++;
    }
}
