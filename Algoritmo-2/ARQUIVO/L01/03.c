/*
3.	Faça um programa em C com duas funções: uma para gravar em um arquivo e outra para escrever. O programa principal deve conter um menu com as opções:
1- Gravar Pessoa; 2- Exibir Listagem; 3- Sair. Ao escolher Gravar Pessoa, a função void gravar(void) deve ser chamada;
ao escolher Exibir Listagem, o programa deve exibir o conteúdo do arquivo manipulado em Gravar Pessoa; O nome do arquivo deve ser parametrizado em uma variável global.

void gravarPessoa(void):

A função permite o usuário informar o nome de uma pessoa e o ano de nascimento. Deve ser criada uma linha no arquivo com a seguinte característica:

[nome                                                                ][anonascimento]\n

Onde deve ser preenchido com espaços após o nome até que se atinja um total de 50 caracteres para nome, seguido de 4 caracteres para o ano de nascimento. Exemplo:

Fernando..........................................1977

(Na linha acima cada ponto corresponde a um espaço. Neste caso como a string Fernando possui 8 caracteres, são concatenados 42 espaços para que atinja 50)

void exibirListagem(void):

A função deverá ler o arquivo de entrada e imprimir na tela cada linha. O programa deve calcular a idade a partir do ano de nascimento,
e colocar ao lado do nascimento uma mensagem conforme a regra a seguir:

Se a idade for menor do que 18 anos, escrever:  <18
Se a idade for maior ou igual que 18 anos, escrever  OK

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
        //VAI SELECIONAR  COMANDO ESCOLHIDO
        switch(n)
        {
        case 1:
            gravarPessoa();
            break;
        case 2:
            exibirListagem();
            break;
        case 3:
            return 0;
        }
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
    printf("s\n");
    for(; t < 50; t++)
        n[t] = ' ';
    //VAI COLOCAR JUNTA O ANO NA VARIAVEL N QUE CONTEM O NOME PARA FORMAR A STRRING FINAL
    n[t] = '\0';
    printf("%s%d\n",n,a);
    if((p = fopen(arquivo,"a")) == NULL)
    {
        printf("\n\nO arquivo %s nao pode ser aberto\n",arquivo);
    }
    else
    {
        //VAI COLOCAR A STRING N NO ARQUIVO
        printf("s\n");
        fprintf(p,"%s%d\n",n,a);
        printf("s\n");
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
        while((fscanf(p,"%s%d\n", nome, &a)) != EOF)
        {
            tam = strlen(nome);
            //VAI PRENCHER O QUE FALTA DOS 50 CARACTERES PARA O NOME COM ESPACO
            for(; tam < 50; tam++)
                nome[tam] = ' ';
            nome[tam] = '\0';
            if((ANO- a) >= 18)
                printf("%s%d OK\n",nome,a);
            else
                printf("%s%d <18", nome,a);
        }
    }
    fclose(p);
}
