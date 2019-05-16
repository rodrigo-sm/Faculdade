#include <stdio.h>

float calc(float);

int main()
{
    float n;
    scanf("%f", &n);
    printf("%f\n", calc(n));
    return 0;
}

float calc(float n)
{
    if(n != 0) return (((n*n + 1) / (n+3)) + calc(--n));
    return 0;
}

