#include <stdio.h>

int mdc_recursivo(int, int);
int mdc_iterativo(int, int);

int main()
{
    int x,y;
    scanf("%d %d", &x, &y);
    printf("MDC(%d,%d) = %d\n", x, y, mdc_iterativo(x,y));
    return 0;
}

int mdc_recursivo(int x, int y)
{
    if(y <= x && x%y == 0) return y;
    if(x < y) return (mdc_recursivo(y,x));
    return (mdc_recursivo(y, x%y));
}

int mdc_iterativo(int x, int y)
{
    int aux;
    if(x < y)
    {
        aux = x;
        x = y;
        y = aux;
    }
    while(x%y != 0)
    {
        aux = x;
        x = y;
        y = aux%x;
    }
    return y;
}
