/*
5.	Faça um programa no qual o usuário informa o nome do arquivo,
e uma palavra, e retorne o número de vezes que aquela palavra aparece no arquivo
*/
#include <stdio.h>

int main()
{
    int c = 0;
    FILE *p;
    char a[81],r,ch;
    printf("Informe o nome do arquivo: ");
    scanf("%80[^\n]", a);
    printf("Informe o nome do caractere a ser comparado: ");
    scanf(" %c", &ch);
    if((p = fopen(a,"r")) == NULL)
    {
        printf("O arquivo %s nao pode ser aberto\n", a);
        return 1;
    }
    while((r = fgetc(p)) != EOF)
    {
        if(r == ch)
            c++;
    }
    fclose(p);
    printf("O caractere aparece %d vezes no arquivo\n", c);
    return 0;
}
