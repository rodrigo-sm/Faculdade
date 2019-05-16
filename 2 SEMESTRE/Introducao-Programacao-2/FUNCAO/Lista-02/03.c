/*
 Criar uma função em C que receba um número decimal e converta-o para binário.
Obs.: O parâmetro passado na chamada à função deve ser alterado para binário.
*/

#include <stdio.h>

void dec2bin(long long *);

int main()
{
	long long num;
	printf("Informe um número inteiro positivo na base decimal: ");
	scanf("%Ld", &num);
	dec2bin(&num);
	printf("Número na base binária: %Ld\n", num);
	return 0;
}

void dec2bin(long long * n)
{
	long long dec = *n, pot10 = 1;
	*n = 0;
	while (dec > 0) {
		*n += (dec % 2) * pot10;
		dec /= 2;
		pot10 *= 10;
	}
}
