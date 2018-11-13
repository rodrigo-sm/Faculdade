/* 01.c
 *
 * Programa cria uma banco de dados de apartamentos
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Algoritmo-II
 *
 * 13/11/2018
 */
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[20];
    int num;
    int area;
    int qntd;
    int valor;
} apartamento;

apartamento ap[40];
int ord = 1;

void cadastrar(int);
int areaTotal(int);
void calcValor(int);
void apMaior(int);
void lista(int);
void ordena(int);

int main()
{
    int n, i = 0;
    FILE *p;
    if((p = fopen("db_ap.dat", "rb")) == NULL)
    {
        fprintf(stderr, "-------------------------------------------\n|Alerta: Nenhum apartamento foi cadastrado|\n-------------------------------------------\n\n");
    }
    else
    {
        while(fread(&ap[i], sizeof(apartamento), 1, p) > 0) i++;
    }
    while(1)
    {
        printf("Menu:\n 1 - Cadastrar apartamento\n 2 - Informar a area total do condominio\n 3 - Calcular o valor a ser pago por mes de cada apartamento\n 4 - Exibir os apartamentos com o maior numero de morador\n 5 - Listar bandas\n 0 - Sair\n>>>> ");
        scanf(" %d", &n);
        switch(n)
        {
        case 0:
            return 0;
        case 1:
            cadastrar(i);
            i++;
            break;
        case 2:
            n = areaTotal(i);
            fprintf(stdout, "===============================================\n");
            fprintf(stdout, "Area total do condominio: %d\n", n);
            fprintf(stdout, "===============================================\n");
            break;
        case 3:
            calcValor(i);
            break;
        case 4:
            apMaior(i);
            break;
        case 5:
            lista(i);
            break;
        default:
            fprintf(stderr, "Erro: Opcao invalida!\n");
        }
    }
}

void cadastrar(int i)
{
    FILE *p;
    if((p = fopen("db_ap.dat", "ab")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo db_ap.dat(banco de dados)\n");
    }
    else
    {
        fprintf(stdout, "Informe o nome do responsavel:\n>>>> ");
        fscanf(stdin, " %[^\n]", ap[i].nome);
        fprintf(stdout, "Informe o numero do apartamento:\n>>>> ");
        fscanf(stdin, " %d", &ap[i].num);
        fprintf(stdout, "Informe a area do apartamento:\n>>>> ");
        fscanf(stdin, " %d", &ap[i].area);
        fprintf(stdout, "Informe a quantidade de moradores:\n>>>> ");
        fscanf(stdin, " %d", &ap[i].qntd);
        fwrite(&ap[i], sizeof(apartamento), 1, p);
        fclose(p);
        ord = 1;
        fprintf(stdout, "Cadastro bem sucedido!\n");
    }
}

int areaTotal(int max)
{
    int i = 0, soma = 0;
    for(i = 0; i < max; i++)
        soma += ap[i].area;
    return soma;
}

void calcValor(int max)
{
    FILE *p;
    fprintf(stdout, "===============================================\n");
    if((p = fopen("db_ap.dat", "wb")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo db_ap.dat(banco de dados)\n");
    }
    else
    {
        int areaCond = areaTotal(max), i;
        fprintf(stdout, "\t\t Valor\n===============================================\n");
        for(i = 0; i < max; i++)
        {
            ap[i].valor = areaCond / ap[i].area;
            fprintf(stdout, "Apartamento %d: %d $\n", ap[i].num, ap[i].valor);
            fwrite(&ap[i], sizeof(apartamento), 1, p);
        }
        fclose(p);
    }
    fprintf(stdout, "===============================================\n");
}

void apMaior(int max)
{
    int maior = 0, i;
    if(ord)
        ordena(max);
    for(i = 0; i < max; i++)
        if(maior < ap[i].qntd)
            maior = ap[i].qntd;
    fprintf(stdout, "===============================================\n");
    fprintf(stdout, "\tApartamento(s) com maior numero de moradores\n");
    for(i = 0; i < max; i++)
        if(maior == ap[i].qntd)
            fprintf(stdout, "| Nome: %s | Numero: %d | Area: %d | Moradores: %d | Valor: %d |\n", ap[i].nome, ap[i].num, ap[i].area, ap[i].qntd, ap[i].valor);
    fprintf(stdout, "===============================================\n");
}

void lista(int max)
{
    int i;
    if(ord)
        ordena(max);
    fprintf(stdout, "===============================================\n");
    fprintf(stdout, "\t\tApartamentos\n===============================================\n");
    for(i = 0; i < max; i++)
        fprintf(stdout, "| Nome: %s | Numero: %d | Area: %d | Moradores: %d | Valor: %d |\n", ap[i].nome, ap[i].num, ap[i].area, ap[i].qntd, ap[i].valor);
    fprintf(stdout, "===============================================\n");
}

void ordena(int max)
{
    int i, j, aux;
    for(i = 0; i < max; i++)
    {
        for(j = i+1; j < max; j++)
        {
            if(ap[i].valor < ap[j].valor)
            {
                aux = ap[i].valor;
                ap[i].valor = ap[j].valor;
                ap[j].valor = aux;
            }
        }
    }
}

