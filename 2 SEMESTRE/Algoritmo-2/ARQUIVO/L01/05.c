/*
5.	Faça um programa no qual o usuário informa o nome do arquivo,
e uma palavra, e retorne o número de vezes que aquela palavra aparece no arquivo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int c = 0, r = 0, i, j, k;
    FILE *p;
    char a[81],str[200],pal[200],ch;
    printf("Informe o nome do arquivo: ");
    scanf("%80[^\n]", a);
    printf("Informe o nome do caractere a ser comparado: ");
    scanf(" %s", pal);
    int tpal = strlen(pal);

    if((p = fopen(a,"r")) == NULL)
    {
        printf("O arquivo %s nao pode ser aberto\n", a);
        return 1;
    }
    while((fscanf(p, "%[^\n]", str)) != EOF)
    {
        int tstr = strlen(str), tf = tstr - tpal;
        for(i = 0; i <= tf; i++)
        {
            for(j = 0, k = i; pal[j] != '\0'; j++, k++)
            {
                if(str[k] == pal[j])
                {
                    c++;
                }
            }
            if(c == tpal)
                r++;
            c = 0;
        }
    }
    fclose(p);
    printf("O caractere aparece %d vezes no arquivo\n", r);
    return 0;
}
