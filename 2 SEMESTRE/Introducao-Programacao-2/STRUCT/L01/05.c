/* 05.c
 *
 * Sistema de cadastro cliente e compra
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Introducao a Computacao-II
 *
 * 09/10/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COMP 20
#define NUM_CLI 20

struct cliente{
    int cod_cli;
    char nome_cli[50];
};
typedef struct cliente tcli;

struct compra{
    int num_comp;
    int valor_comp;
    int cod_cli;
};

typedef struct compra tcomp;

void cadastraCliente(tcli *);
void cadastraCompra(tcli *, tcomp *);
void listaCli(tcli * );
void listaCompCli(tcli *, tcomp *);
void removerCli (tcli *, tcomp * );

int main()
{
    srand(time(NULL));
    int opcao, i = 0;
    tcli cli[NUM_CLI];
    for(i = 0;i < NUM_CLI; i++)
    {
        cli[i].cod_cli = -1;
    }
    tcomp comp[NUM_COMP];
    for(i = 0; i < NUM_COMP; i++)
    {
        comp[i].num_comp = -1;
        comp[i].valor_comp = -1;
        comp[i].cod_cli = -1;
    }

    do {
        system("cls");
        printf(" Menu\n  0 - Sair\n  1 - Cadastrar cliente\n  2 - Cadastra Compra\n  3 - Listar clientes cadastrados\n  4 - Listar as compras de um determinado cliente\n  5 - Remover um cliente\n>>>> ");
        scanf(" %d", &opcao);
        printf("----------------------------------------------------\n");
        switch(opcao)
        {
        case 0: break;
        case 1:
            cadastraCliente(cli);
            system("pause");
            break;
        case 2:
            cadastraCompra(cli, comp);
            system("pause");
            break;
        case 3:
            listaCli(cli);
            system("pause");
            break;
        case 4:
            listaCompCli(cli, comp);
            system("pause");
            break;
        case 5:
            removerCli(cli, comp);
            system("pause");
            break;
        default:
            printf("Opcao invalida\n");
            system("pause");
        }
    } while(opcao);
}

void cadastraCliente(struct cliente * cli)
{
    int tam, r = 1, i;
    for(i = 0; i < NUM_CLI; i++)
    {
        if(r && cli[i].cod_cli == -1)
        {
            cli[i].cod_cli = i ;
            printf("Informe o nome do cliente:\n>>>> ");
            scanf(" %s", cli[i].nome_cli);
            r = 0;
            printf("\nCliente Cadastrado com sucesso\n");
        }
    }
    if(r == 1)
        printf("\nNao tem espaco\n");
}


void cadastraCompra(tcli * cli, tcomp * comp)
{
    int r, i;
    int n;
    printf("Informe o codigo do cliente:\n>>>> ");
    scanf(" %d", &n);
    if(cli[n].cod_cli == -1)
    {
        printf("\nCliente nao cadastrado\n");
    }
    else
    {
        for(i = 0; i < NUM_COMP; i++)
        {
            if(r && comp[i].num_comp == -1)
            {
                comp[i].cod_cli = n;
                printf("\nInforme o valor da compra:\n>>>> ");
                scanf(" %d", &comp[i].valor_comp);
                comp[i].num_comp = rand() % 100;
                r = 0;
                printf("\nCompra Cadastrado com sucesso\n");
            }
        }
        if(r == 1)
        printf("\nNao tem espaco\n");
    }
}

void listaCli(tcli * cli)
{
    int i, c = 0;
    for(i = 0; i < NUM_CLI; i++)
    {
        if(cli[i].cod_cli != -1)
        {
            printf("Cod = %d\nNome = %s\n", cli[i].cod_cli, cli[i].nome_cli);
            printf("----------------------------------------------------\n");
            c++;
        }
    }
    if(c == 0)
        printf("\nNenhum cliente cadastrado\n");
}

void listaCompCli(tcli * cli, tcomp * comp)
{
    int n, i, c = 0;
    printf("Informe o codigo do cliente:\n>>>> ");
    scanf(" %d", &n);
    printf("----------------------------------------------------\n");
    for(i = 0; i < NUM_COMP; i++)
    {
        if(comp[i].cod_cli == n)
        {
            printf("Numero da compra = %d\nValor = %d", comp[i].num_comp, comp[i].valor_comp);
            printf("\n----------------------------------------------------\n");
            c++;
        }
    }
    if(c == 0)
        printf("\nNenhuma compra cadastrada\n");
}

void removerCli (tcli * cli, tcomp * comp)
{
    int n, r = 1, i;
    printf("Informe o codigo do cliente:\n>>>> ");
    scanf(" %d", &n);
    for(i = 0; i < NUM_COMP; i++)
    {
        if(comp[i].cod_cli == n)
        {
            r = 0;
            break;
        }
    }
    if(r)
    {
        cli[n].cod_cli = -1;
        printf("\nCliente removido com sucesso\n");
    }
    else
        printf("\nCliente nao pode ser removido\n");
}
