#include <stdio.h>

int prod_iterativo(int, int);

int prod_recursivo(int, int);

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    printf("%d %d\n", prod_recursivo(a,b), prod_iterativo(a, b));
    return 0;
}

int prod_iterativo(int a, int b)
{
    int aux;
    if(a < b) {
        aux = a;
        a = b;
        b = aux;
    }
    aux = 0;
    while(b--) {
      aux += a;
    }
    return aux;
}

int prod_recursivo(int a, int b)
{
    if(a < b) return prod_recursivo(b, a);
    if(b == 1) return a;
    return a + prod_recursivo(a,--b);
}
