/*
6. Escreva um programa que receba uma string de 0s e 1s, interprete essa string como um
número binário e informe o valor desse número na base decimal.
*/
#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char bin[81];
    printf("Informe o numero binario: ");
    scanf("%s", bin);
    int t = strlen(bin) - 1,i,dec = 0;
    for(i = 0;bin[i] != '\0';i++,t--)
    {
        if(bin[i] == '1')
        {
            dec += pow(2,t);
        }
    }
    printf("O numero decimal: %d\n", dec);
    return 0;
}
