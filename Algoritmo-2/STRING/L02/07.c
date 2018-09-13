/*
7. Implemente uma função que receba uma string como parâmetro e substitua as ocorrências de uma letra pelo seu oposto no alfabeto, isto e, ‘a’ para ‘z’, ‘b’ para ‘y’, ‘c’ para ‘x’, etc.
Caracteres que não forem letras devem permanecer inalterados.
void string oposta (char* str);
*/
#include <stdio.h>

void StringOposta (char* str);

int main()
{
    char str[81];
    printf("Informe a string: ");
    scanf("%80[^\n]", str);
    StringOposta(str);
    printf("String formatada: %s",str);
    return 0;
}

void StringOposta (char* str)
{
    int i;
    for(i = 0;str[i] != '\0';i++)
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = (122 - str[i]) + 97;
        }
        if(str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = (90 - str[i]) + 65;
        }
    }
}
