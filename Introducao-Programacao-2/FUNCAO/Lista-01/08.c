/*
Escreva uma função de protótipo double   hipotenusa(double   x,   double   y); que
calcula e devolve o comprimento da hipotenusa de um triângulo retângulo cujos catetos são
dados pelos parâmetros x e y. Lembre-se que hipotenusa= x
2y
2
. Dica: utilize a função
sqrt para obter a raiz quadrada.
*/

#include <stdio.h>
#include <math.h>

double   hipotenusa(double   x,   double   y);

int main()
{
    double h,x,y;
    scanf("%lf %lf", &x, &y);
    h = hipotenusa(x,y);
    printf("%.1f\n", h);
}

double   hipotenusa(double   x,   double   y)
{
    double h;
    h = sqrt(pow(x,2) + pow(y,2));
    return h;
}
