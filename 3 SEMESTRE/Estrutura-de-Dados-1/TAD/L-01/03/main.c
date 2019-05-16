/*
3. Implemente uma aplicação que use os módulos my_io e my_math. Esta aplicação
deve usar as funções do módulo my_io para deixar o usuário entrar com um número
inteiro e outro real. Depois a aplicação deve usar as funções do módulo my_math
para calcular o fatorial do número inteiro e arredondar para um inteiro o número
real e exibir os resultados no vídeo. Forneça o makefile da aplicação.
*/

#include <stdio.h>
#include "my_io.h"
#include "my_math.h"

int main()
{
	int x;
	double y;

	printf("Informe um número natural: ");
	while (!read_int(&x) || x < 0) {
		printf("Você não informou um número natural (>=0)!\nInforme um número natural: ");
	}

	printf("Informe um número real: ");
	while (!read_double(&y)) {
		printf("Você não informou um número real!\nInforme um número real: ");
	}

	printf("\nFatorial de %d = %Ld\n", x, fatorial(x));
	printf("%lf arredondado para o inteiro mais próxino: %d\n",
	       y, arredondarParaInt(y));
	return 0;
}

