#include <stdio.h>

void imprimirNum2Bin(int);

int main()
{
    int n;
    scanf("%d", &n);
    printf("Numero binario: ");
    imprimirNum2Bin(n);
}

void imprimirNum2Bin(int n)
{
    if(n/2 != 0) imprimirNum2Bin(n/2);
    printf("%d", n%2);
}
