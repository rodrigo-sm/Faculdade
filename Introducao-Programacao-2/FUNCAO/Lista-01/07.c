/*
Considere a função do exercício anterior e escreva um programa que solicita dois números
naturais (n e k) ao usuário e calcula e imprime:
a) O número de permutação Pn
b) O número de arranjos An,k
c) O número de combinações Cn,k
*/
#include <stdio.h>

int fatorial(int fx);

int main()
{
    int n, k, fk, fn, fnk, ank, cnk,nk;
    scanf("%d %d", &n, &k);
    fk = fatorial(k);
    fn = fatorial(n);
    nk = n-k;
    fnk = fatorial(nk);
    printf("fk %d, fn %d, fnk %d\n", fk,fn,fnk);
    ank = fn / fnk;
    cnk = fn /(fk * fnk);
    printf("Permutacao = %d\n", fn);
    printf("Arranjo = %d\n", fnk);
    printf("Combinacao = %d\n", cnk);

}

int fatorial(int fx)
{
    int c,n1 = fx, n2 = fx;
    if(fx != 0)
        c=1;
    while(n1)
    {
        c *= n1;
        n1--;
    }
    return c;
}
