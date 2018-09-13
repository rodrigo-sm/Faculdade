/*
2. Implemente uma função que receba uma string como parâmetro e retorne como resultado o número de vogais encontradas.
int conta vogais(char* str);

*/
#include <stdio.h>
#include <ctype.h>

int contavogais(char* str);

int main()
{
    int c = 0,i;
    char str[81];
    printf("Informe a string: ");
    scanf("%80[^\n]", str);
    c = contavogais(str);
    printf("A quantidade vogais e %d\n", c);
    return 0;
}

int contavogais(char* str)
{
    int c = 0,i;
    for(i = 0;str[i] != '\0';i++)
    {
        str[i] = tolower(str[i]);
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            c++;
    }
    return c;
}
