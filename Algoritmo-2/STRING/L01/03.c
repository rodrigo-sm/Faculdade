/*
3) Escreva um programa que receba um caractere c e devolve uma string cujo único caracter é c.
*/

#include <stdio.h>
#include <strings.h>

int main(){
    char caractere;
    char str[2];

    scanf("%c",&caractere);

    str[0]=caractere;
    str[1]='\0';

    puts(str);

    return 0;
}
