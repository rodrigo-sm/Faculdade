/*
4.	Faça um programa que receba dois arquivos do usuário,
e crie um terceiro arquivo com o conteúdo dos dois primeiros
juntos (o conteúdo do primeiro seguido do conteúdo do segundo).
*/
#include <stdio.h>

int main()
{
    FILE *p1,*p2,*p3;
    char ch,a1[81],a2[81],a3[] = "COMBINADO.txt";
    printf("Informe o nome dos dois arquivos a ser combinado:\n");
    scanf("%80[^\n]", a1);
    scanf(" %80[^\n]", a2);
    if((p1 = fopen(a1,"r")) == NULL)
    {
        printf("O arquivo %s nao consegue ser aberto\n", a1);
        return 1;
    }
    if((p3 = fopen(a3,"w")) == NULL)
    {
        printf("O arquivo %s nao consegue ser criado\n", a3);
        return 2;
    }
    while((ch = fgetc(p1)) != EOF)
        fputc(ch, p3);
    fclose(p1);
    fclose(p3);
    if((p2 = fopen(a2,"r")) == NULL)
    {
        printf("O arquivo %s nao consegue ser aberto\n", a2);
        return 3;
    }
    if((p3 = fopen(a3,"a")) == NULL)
    {
        printf("O arquivo %s nao consegue ser aberto\n", a3);
        return 4;
    }
    while((ch = fgetc(p2)) != EOF)
        fputc(ch, p3);
    fclose(p1);
    fclose(p3);
    return 0;
}
