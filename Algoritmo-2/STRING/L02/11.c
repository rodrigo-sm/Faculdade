/*
11. Escreva uma função que concatene duas strings dadas A e B numa nova string C (ex: se A = “Perdi as chaves ” e B = “do carro”, entao C = “Perdi as chaves do carro”): ˜
void ConcatenaString(char stringA[], char stringB[], char stringC[]);
*/
#include <stdio.h>

void ConcatenaString(char stringA[], char stringB[], char stringC[]);

int main()
{
    char a[81],b[81],c[161];
    printf("informe a string A: ");
    scanf("%80[^\n]", a);
    printf("informe a string B: ");
    scanf(" %80[^\n]", b);
    ConcatenaString(a,b,c);
    printf("String concatenada: %s\n",c);
    return 0;
}

void ConcatenaString(char stringA[], char stringB[], char stringC[])
{
    int i,j;
    for(i = 0;stringA[i] != '\0';i++)
        stringC[i] = stringA[i];
    for(j = 0;stringB[j] != '\0';i++,j++)
        stringC[i] = stringB[j];
    stringC[i] = '\0';
}
