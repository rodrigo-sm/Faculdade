#include <stdio.h>

int main()
{
    int a,b,c,x,y,z,resultado=0;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &x, &y, &z);
    if(a <= x && b <= y && c <= z)
    {
        resultado = (x / a) * (y / b) * (z / c);
        if(resultado == 0) resultado++;
    }
    printf("%d\n", resultado);
    return 0;
}
