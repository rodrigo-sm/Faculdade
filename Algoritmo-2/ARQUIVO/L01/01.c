/*
1.	Faça um programa em Linguagem C que receba do usuário um arquivo texto,
e mostre na tela quantas linhas esse arquivo possui. Considere o ‘\n’ como terminador de linha;
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c = 0;
    char ch, str[81];
    FILE *p;
    printf("Informe o arquivo: ");
    scanf("%80[^\n]", str);
    if((p = fopen(str,"r")) == NULL)
    {
        printf("O arquivo %s nao pode ser aberto\n",str);
        return 1;
    }
    while((ch = fgetc(p)) != EOF)
    {
        if(ch == '\n')
            c++;
    }
    fclose(p);
    printf("O seu arquivo possui %d linha(s)\n",c);
    return 0;
}
