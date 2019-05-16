/*
 Escreva uma função de protótipo double arredondar(double n, int c); que arredonda
o valor de n para um número com precisão de c casas decimais. Por exemplo,
arredondar(5.78351,1) devolve 5.8, arredondar(5.78351,2) devolve 5.78,
2
arredondar(5.78351,3) devolve 5.784. Dica: utilize a função arredondarParaInt
passando seu argumento multiplicado por 10c
, e depois divida o valor de retorno da função por
10c
*/

#include <stdio.h>
#include <math.h>

double arredondar(double n, int c);

int main()
{
    double n,a;
    int c;
    scanf("%lf", &n);
    scanf("%d", &c);
    a = arredondar(n,c);
    printf("%g\n", a);
}

double arredondar(double n, int c)
{
    double a;
    n *= pow(10,c);
    a = floor(n) / pow(10,c);
    return a;
}
