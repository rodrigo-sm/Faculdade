#include <stdio.h>

int Ackerman(int, int);

int main()
{
    int m, n;
    scanf("%d %d", &m , &n);
    printf("%d\n", Ackerman(m, n));
    return 0;
}

int Ackerman(int m, int n)
{
    if(m == 0) return n+1;
    if(m != 0 && n == 0) return Ackerman(m-1, 1);
    return Ackerman(m-1, Ackerman(m, n-1));
}
