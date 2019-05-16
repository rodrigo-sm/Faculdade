/*
8. Implemente uma função que receba uma string como parâmetro e desloque os seus caracteres uma posição para a direita. Por exemplo, a string “casa” seria alterada para “acas”.
Repare que o ˜ ultimo caractere vai para o  ınicio da string.
void roda string (char* str);
*/
#include <stdio.h>

void RodaString (char* str);

int main()
{
    char str[81];
    printf("Informe a string: ");
    scanf("%80[^\n]", str);
    RodaString(str);
    printf("String formatada: %s\n",str);
    return 0;
}

void RodaString (char* str)
{
    int i,j = 1;
    char ch = str[0];
    for(i = 0,j = 1;str[j] != '\0';i++,j++)
    {
        str[i] = str[j];
    }
    str[i] = ch;
}
