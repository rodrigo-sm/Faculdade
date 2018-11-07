/* 04.c
 *
 * Programa que cria um arquivo 'chuvas.dat' com os indices pluviometricos diarios do ano de 2010-2020
 * e cria o arquivo 'dias_chuvosos.txt' com os indices pluviometricos diario de um determinado ano maior que 60 mm
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Introdução a Computação-II
 *
 * 05/1/2018
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
    int dia;
    int mes;
    int ano;
} data;

typedef struct
{
    data dt;
    int ind_pluviometrico;
} chuva;

void gerarChuva(void);
void exibirChuva(void);
void gerarDia(void);
void exibirDia(void);

int main()
{
    int n;
    while(1)
    {
        system("cls");
        fprintf(stdout, "Escolha uma opcao:\n 1 - Gerar arquivo chuvas.dat\n 2 - Exibir arquivo chuvas.dat\n 3 - Gerar arquivo dias_chuvosos.txt\n 4 - Exibir arquivo dias_chuvosos.txt\n 0 - Sair\n>>>> ");
        fscanf(stdin, " %d", &n);
        switch(n)
        {
        case 1:
            gerarChuva();
            break;
        case 2:
            exibirChuva();
            break;
        case 3:
            gerarDia();
            break;
        case 4:
            exibirDia();
            break;
        case 0:
            return 0;
            break;
        default:
            fprintf(stderr, "Erro: Opcao invalida!\n");
        }
        system("pause");
    }
    return 0;
}

void gerarChuva()
{
    FILE *p;
    if((p = fopen("chuvas.dat", "wb")) == NULL)
        fprintf(stderr, "Erro: Nao foi possivel criar o arquivo chuvas.dat\n");
    else
    {
        int i, j, k;
        chuva info;
        srand(time(NULL));
        for(i = 2010; i < 2021; i++)
        {
            for(j  = 1; j < 12; j++)
            {
                for(k = 1; k < 30; k++)
                {
                    info.ind_pluviometrico = rand() / 101;
                    info.dt.dia = k;
                    info.dt.mes = j;
                    info.dt.ano = i;
                    fwrite(&info, sizeof(chuva), 1, p);
                }
            }
        }
        fprintf(stdout, "O arquivo chuvas.dat foi criado com sucesso!\n");
        fclose(p);
    }
}

void exibirChuva()
{
    FILE *p;
    if((p = fopen("chuvas.dat", "rb")) == NULL)
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo chuvas.dat\n");
    else
    {
        chuva info;
        fprintf(stdout, "\t\tArquivo chuvas.dat\n");
        fprintf(stdout, "-----------------------------------------------------------------\n");
        while(fread(&info, sizeof(info), 1, p) > 0)
        {
            fprintf(stdout, "Data: %02d/%d/%d Indice: %d\n", info.dt.dia, info.dt.mes, info.dt.ano, info.ind_pluviometrico);
        }
        fprintf(stdout, "-----------------------------------------------------------------\n");
        fclose(p);
    }
}

void gerarDia()
{
    FILE *in, *out;
    if((in = fopen("chuvas.dat", "rb")) == NULL)
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo chuvas.dat\n");
    else
    {
        if((out = fopen("dias_chuvosos.txt", "w")) == NULL) {
            fprintf(stderr, "Erro: Nao foi possivel criar o arquivo dias_chuvosos.txt\n");
            fclose(in);
        }
        else
        {
            chuva info;
            int ano;
            fprintf(stdout, "Informe o ano:\n>>>> ");
            fscanf(stdin, " %d", &ano);
            while(fread(&info, sizeof(info), 1, in) > 0)
            {
                if(info.ind_pluviometrico > 60 && info.dt.ano == ano)
                    fprintf(out, "%02d/%d/%d %d\n", info.dt.dia, info.dt.mes, info.dt.ano, info.ind_pluviometrico);
            }
            fprintf(stdout, "Arquivo dias_chuvosos.txt criado com sucesso\n");
            fclose(in);
            fclose(out);
        }
    }
}

void exibirDia()
{
    FILE *p;
    if((p = fopen("dias_chuvosos.txt", "r")) == NULL)
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo dias_chuvosos.txt\n");
    else
    {
        chuva info;
        fprintf(stdout, "\t\tArquivo dias_chuvosos.txt\n");
        fprintf(stdout, "-----------------------------------------------------------------\n");
        while(fscanf(p, "%d/%d/%d %d\n", &info.dt.dia, &info.dt.mes, &info.dt.ano, &info.ind_pluviometrico) > 0)
        {
            fprintf(stdout, "Data: %02d/%d/%d Indice: %d\n", info.dt.dia, info.dt.mes, info.dt.ano, info.ind_pluviometrico);
        }
        fprintf(stdout, "-----------------------------------------------------------------\n");
    }
}
