/*
10. Escreva uma função que identiﬁque-se uma dada string A é ou nao um palíndromo (ex: “SOCORRAM ME EM MARROCOS” ´e um palíndromo).
void Palindromo(char str[], int n);
*/
#include <stdio.h>
#include <string.h>

void Palindromo(char str[], int n);

int main()
{
    int n;
    char str[81];
    scanf("%80[^\n]", str);
    n = strlen(str);
    Palindromo(str,n);
    return 0;
}

void Palindromo(char str[], int n)
{
    int r = 1,x;
    for(x = 0,n--; x < n; x++,n--)
    {
        if(str[x] != str[n])
            r = 0;
    }
    if(r)
        printf("S\n");
    else
        printf("N\n");
}
