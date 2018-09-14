/*
2.	Faça um programa em Linguagem C que gere 100.000 caracteres aleatórios e grave em um arquivo texto.
Caracteres válidos: A-Z, a-z, 0-9;
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    srand((unsigned) time (NULL));
    int s,i;
    char ch, str[81];
    FILE *p;
    printf("Informe o nome do arquivo a ser criado: ");
    scanf("%80[^\n]", str);
    if((p = fopen(str,"w")) == NULL)
    {
        printf("O arquivo %s nao pode ser aberto\n",str);
        return 1;
    }
    for(i = 0;i < 100001;i++)
    {
        s = rand()%3;
        switch(s)
        {
            //GERA LETRA MAIUSCULA
            case 0: ch = (rand()%26) + 65; break;
            //GERA LETRA MINUSCULA
            case 1: ch = (rand()%26) + 97;
            //GERA NUMERO ALEATORIO
            case 2: ch = (rand()%10) + 48;
        }
        fputc(ch,p);
    }
    fclose(p);
    printf("Arquivo criado com sucesso\n");
    return 0;
}
