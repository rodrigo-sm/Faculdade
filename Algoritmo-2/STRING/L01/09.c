/*
9)	Faça um programa capaz de receber uma string e copiar seu conteúdo para outra.
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char lida[81],final[81];
    printf("Informe a string lida: ");
    scanf("%80[^\n]", lida);
    strcpy(final,lida);
    printf("String final: %s\n", final);
    return 0;
}
