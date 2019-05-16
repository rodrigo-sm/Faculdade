/*
8)	Faça um programa capaz de contar a quantidade de vogais (maiúsculas e minúsculas) de uma string recebida pelo teclado.
*/
#include <stdio.h>
#include <ctype.h>
int main()
{
    int c = 0,i;
    char str[81];
    printf("Informe a string: ");
    scanf("%80[^\n]", str);
    for(i = 0;str[i] != '\0';i++)
    {
        str[i] = tolower(str[i]);
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            c++;
    }
    printf("A quantidade vogais e %d\n", c);
    return 0;
}
