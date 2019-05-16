#include <stdio.h>

int calc(int);

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", calc(n));
    return 0;
}

int calc(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 2;
    return (2*calc(n-1) + 3*calc(n-2));
}
