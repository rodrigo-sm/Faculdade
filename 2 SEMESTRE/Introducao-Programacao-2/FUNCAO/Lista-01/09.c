/*
A função floor, definida no arquivo math.h, arredonda seu argumento (um número do tipo
double) para o maior inteiro que não seja maior que esse argumento, na prática, isso significa
devolver a parte inteira do argumento. Entretanto, o valor de retorno da função floor é um
double. Crie uma função de protótipo int   arredondarParaInt(double   n); que
arredonda seu parâmetro n para o inteiro mais próximo. Dica: some 0.5 a n e utilize a função
floor. Escreva um programa que leia vários números e use a função arredondarParaInt
para arredondar cada um desses números para o inteiro mais próximo.
*/

#include <stdio.h>
#include <math.h>

int   arredondarParaInt(double   n);

int main()
{
    int a;
    double n;
    scanf("%lf", &n);
    a = arredondarParaInt(n);
    printf("a = %d\n", a);
    return 0;
}

int   arredondarParaInt(double   n)
{
    n += 0.5;
    return floor(n);
}
