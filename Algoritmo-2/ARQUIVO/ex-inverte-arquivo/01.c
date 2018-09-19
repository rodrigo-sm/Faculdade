/*
1) Faça um programa em C que recebe como entrada o nome de um arquivo de entrada e o nome de um arquivo de saída.
Cada linha do arquivo de entrada possui colunas de tamanho de 30 caracteres. No arquivo de saída deverá ser escrito o arquivo de entrada ´de forma inversa. Veja um exemplo:
*/
#include <stdio.h>
#include <string.h>
int main()
{
    int c = 0,i = 0,j = 0,k;
    FILE *pin,*pout;
    char in[81],out[81],ch;
    printf("Informe o arquivo de entrada e saida:\n");
    scanf("%80[^\n]", in);
    scanf(" %80[^\n]", out);
    if((pin = fopen(in,"r")) ==  NULL)
    {
        printf("O arquivo de entrada nao pode ser aberto\n");
        return 1;
    }
    if((pout = fopen(out,"w")) ==  NULL)
    {
        printf("O arquivo de saida nao pode ser aberto\n");
        return 2;
    }
    while((ch = fgetc(pin)) != EOF)
    {
        if(ch == '\n')
        {
            c++;
        }
    }
    rewind(pin);
    char text[c][32];
    //Vai armazenar o conteudo no vetor de caracteres text
    while((ch = fgetc(pin)) != EOF)
    {
        text[i][j] = ch;
        j++;
        if(ch == '\n')
        {
            text[i][j] = '\0';
            i++;
            j = 0;
        }
    }
    //Vai inverter as linhas
    for(i = 0;i < c + 1;i++)
    {
        k = strlen(text[i]);
        int t = k, f = k - 1;
        k-=2;
        printf("\n\nproxima\n\n");
        for(j = 0; j < t/2 ; j++,k--)
        {
            ch = text[i][j];
            text[i][j] = text[i][k];
            text[i][k] = ch;
        }
        text[i][f] ='\0';
    }
    printf("%d\n",c);
    //Vai armazenar a matriz text formatada no arquivo
    for(i = c;i >= 0;i--)
    {
        for(j = 0;text[i][j] != '\0'; j++)
        {
            fputc(text[i][j],pout);
        }
        fputc('\n',pout);
    }
    fclose(pin);
    fclose(pout);
    return 0;
}
