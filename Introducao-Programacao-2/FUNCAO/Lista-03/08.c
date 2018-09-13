/*
8. Escreva um programa que receba um número qualquer de valores reais via argumentos da
função main() e determine e exiba o maior desses valores.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int i = 1;
    double f,r = 0;
    for(i = 0;i < argc;i++)
    {
        f = atof(argv[i]);
        if(f > r)
            r = f;
    }
    printf("Maior numero %.1lf\n", f);
    return 0;
}
