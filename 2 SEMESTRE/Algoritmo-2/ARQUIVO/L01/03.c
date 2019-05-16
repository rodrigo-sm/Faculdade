/* Programa que grava nome e idade e depois exibe o conteudo e mostra se a pessoa e maior de idade ou nao
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Algoritmo-II
 *
 * 18/09/2018
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//VAI DEFINIR O ANO ATUAL
#define ANO 2018
char arquivo[] = "lista.txt";

void gravarPessoa(void);
void exibirListagem(void);

int main()
{
    int n;
    while(1)
    {

        printf("\n*---------------------*\n");
        printf("*Escolha a sua opcao: *\n");
        printf("* 1- Gravar Pessoa    *\n");
        printf("* 2- Exibir listagem  *\n");
        printf("* 3- Sair             *\n");
        printf("*---------------------*\n");
        scanf("%d", &n);
        system("cls");
        //VAI SELECIONAR  COMANDO ESCOLHIDO
        switch(n)
        {
        case 1:
            gravarPessoa();
            break;
        case 2:
            exibirListagem();
            system("pause");
            break;
        case 3:
            return 0;
        }
        system("cls");
    }
    return 0;
}

void gravarPessoa(void)
{
    int t,i,a;
    char n[60];
    FILE *p;
    printf("\nDigite o nome: ");
    scanf(" %51[^\n]", n);
    printf("\nDigite o ano: ");
    scanf(" %d", &a);
    t = strlen(n);
    //VAI PRENCHER O QUE FALTA DOS 50 CARACTERES PARA O NOME COM ESPACO
    for(; t < 50; t++)
        n[t] = ' ';
    //VAI COLOCAR JUNTA O ANO NA VARIAVEL N QUE CONTEM O NOME PARA FORMAR A STRRING FINAL
    n[t] = '\0';
    if((p = fopen(arquivo,"a")) == NULL)
    {
        printf("\n\nO arquivo %s nao pode ser aberto\n",arquivo);
    }
    else
    {
        //VAI COLOCAR A STRING N NO ARQUIVO
        fprintf(p,"%s%d\n",n,a);
        fclose(p);
    }
}

void exibirListagem(void)
{
    int i = 0,t;
    char ch,str[60],a[4];
    FILE *p;
    if((p = fopen(arquivo,"r")) == NULL)
    {
        printf("\n\nO arquivo %s nao pode ser aberto\n",arquivo);
    }
    else
    {
        printf("\n\nConteudo:\n\n");
        char nome[51];
        int a,tam;
        while((fgets(nome, 50, p)) != NULL)
        {
            fscanf(p, "%d\n", &a);
            if((ANO - a) >= 18)
                printf("%s%d OK\n",nome,a);
            else
                printf("%s%d <18\n", nome,a);
        }
    }
    fclose(p);
}
