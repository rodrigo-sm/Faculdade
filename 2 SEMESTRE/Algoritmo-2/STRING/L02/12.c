/*
12. Escreva uma função que conte quantas letras maiúsculas existem numa string:
void ContaMaiusculas(char string[]);
*/
#include <stdio.h>

void ContaMaiusculas(char string[]);

int main()
{
    char str[81];
    printf("Informe a string: ");
    scanf("%80[^\n]", str);
    ContaMaiusculas(str);
    return 0;
}

void ContaMaiusculas(char string[])
{
    int i,c = 0;
    for(i = 0;string[i] != '\0';i++)
        if(string[i] >= 'A' && string[i] <= 'Z')
            c++;
    printf("A string (%s) tem %d letra(s) maiuscula(s)\n",string, c);
}
