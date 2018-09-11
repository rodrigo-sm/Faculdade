/*
 Faça uma função contadigitos que dados como parâmetros um inteiro n e um inteiro d, 0
< d <= 9, devolve quantas vezes o dígito d aparece em n.
*/

#include <stdio.h>

int contadigitos(int n, int d);

int main()
{
    int n, d, r;
    scanf("%d %d", &n, &d);
    r = contadigitos( n, d);
    printf("O digito %d aparece %d vezes no numero %d\n", d, r, n);
    return 0;
}

int contadigitos(int n, int d)
{
    int r,c=0;
    do
    {
        r = n % 10;
        n = n / 10;
        if(r == d) c++;
    }while(n > 0);
    return c;
}
