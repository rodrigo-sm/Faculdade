/* my_math.c
 * Implementação das minhas funções matemáticas */

#include <math.h>

long long fatorial(int *n)
{
    long long fat = 1;
    while(n-- > 0)
    {
        fat *= n;
    }
    return fat;
}

int arredondarParaInt (double val)
{
	return (int) floor(val + 0.5);
}
