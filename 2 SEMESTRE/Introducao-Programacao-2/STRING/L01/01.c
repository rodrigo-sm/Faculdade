/* 
1. Escreva um programa que receba uma string do teclado e informe quantas 
letras maiúsculas ela possui.
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    char str[41];
    int i, cont = 0;
    
    printf("Informe uma string: ");
    scanf("%40[^\n]", str);
    
    for (i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            cont++;
        }
    }
    
    printf("A string possuir %d letra(s) maiúscula(s)\n", cont);
    return 0;
}
