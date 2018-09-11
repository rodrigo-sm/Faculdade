/*
3. Escreva uma função que recebe uma string e um caractere como parâmetros e devolve a
posição da 1ª ocorrência do caractere na string. Caso o caractere não esteja contido na
string, a função deve devolver -1.
*/
#include <stdio.h>

int ocorrencia(const char * str, char c);

int main()
{
    int p;
    char str[81],c;
    printf("Informe a string: ");
    scanf("%80[^\n]", str);
    printf("Informe o caractere: ");
    scanf(" %c", &c);
    p = ocorrencia(str,c);
    if(p == -1)
        printf("O caractere nao aparece na string informada\n");
    else
        printf("O caractere aparece na %d posicao da string informada\n", p);
}

int ocorrencia(const char *str, char c)
{
    int i;
    for(i = 0;str[i] != '\0';i++)
    {
        if(str[i] == c)
            return ++i;
    }
    return -1;
}
