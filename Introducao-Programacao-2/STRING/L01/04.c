/*
4. Escreva um programa que receba uma string do teclado e informe se ela é palíndromo ou
não. Uma string é palíndromo quando pode ser lida tanto de trás para frente quanto de
frente para trás e possui exatamente a mesma sequência de caracteres. Por exemplo:
“ASA”, “SUBI NO ONIBUS”. Desconsidere os espaços.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char str[81];
    int y,x,r=1,z;
    scanf("%80[^\n]", str);
    for(x = 0;str[x] != '\0';x++)
    {
        if(str[x] == ' ')
        {
            for(z = x, y = x + 1;str[y] != '\0';z++,y++)
                str[z] = str[y];
            str[z] = str[y];
        }
    }
    y = strlen(str);
    for(x = 0,y--; x < y; x++,y--)
    {
        if(str[x] != str[y])
            r = 0;
    }
    if(r)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
