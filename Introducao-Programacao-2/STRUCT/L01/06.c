/* 06.c
 *
 * Sistema de banco de dados de um hospital
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Introducao a Computacao-II
 *
 * 10/10/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_MED 20
#define NUM_PAC 20
#define NUM_CONS 20

struct medicos
{
    int codMed;
    char nome[100];
    char especialidade[100];
};
typedef struct medicos tmedico;

struct pacientes
{
    int codPac;
    char nome[100];
    char sexo;
    int idade;
};
typedef struct pacientes tpaciente;

struct consultas
{
    int numPront;
    char data[15];
    char horario[15];
    int cod_med;
    int cod_pac;
};
typedef struct consultas tconsulta;

void cadastrarMedico(tmedico *);
void cadastrarPaciente(tpaciente *);
void listaMedico(tmedico *);
void listaPaciente(tpaciente *);
void cadastrarConsulta(tmedico *,tpaciente *,tconsulta *);
void listaConsulta(tmedico *,tconsulta *);

int main()
{
    int opcao, i;

    tmedico med[NUM_MED];
    for(i = 0; i < NUM_MED; i++)
        med[i].codMed = -1;

    tpaciente pac[NUM_PAC];
    for(i = 0; i < NUM_PAC; i++)
        pac[i].codPac = -1;

    tconsulta cons[NUM_CONS];
    for(i = 0; i < NUM_CONS; i++)
    {
        cons[i].numPront = -1;
        cons[i].cod_med = -1;
        cons[i].cod_pac = -1;
    }

    do
    {
        system("cls");
        printf(" MENU\n");
        printf("  0 - Sair\n");
        printf("  1 - Cadastrar medico\n");
        printf("  2 - Cadastrar paciente\n");
        printf("  3 - Listar medico(s)\n");
        printf("  4 - Listar paciente(s)\n");
        printf("  5 - Cadastrar consulta\n");
        printf("  6 - Listar consulta\n");
        printf(">>>> ");
        scanf(" %d", &opcao);
        printf("-----------------------------------------\n\n");
        switch(opcao)
        {
        case 0:
            break;
        case 1:
            cadastrarMedico(med);
            break;
        case 2:
            cadastrarPaciente(pac);
            break;
        case 3:
            listaMedico(med);
            break;
        case 4:
            listaPaciente(pac);
            break;
        case 5:
            cadastrarConsulta(med, pac, cons);
            break;
        case 6:
            listaConsulta(med, cons);
            break;
        default:
            printf("Opcao invalida\n");
            system("pause");
        }
    }
    while(opcao);
}

void cadastrarMedico(tmedico * med)
{
    int i, r = 1;
    for(i = 0; i < NUM_MED; i++)
    {
        if(i != med[i].codMed)
        {
            med[i].codMed = i;
            printf("Informe o nome do medico:\n>>>> ");
            scanf(" %[^\n]", med[i].nome);
            printf("\nInforme a especialidade dele:\n>>>> ");
            scanf(" %[^\n]", med[i].especialidade);
            printf("\nMedico cadastrado com sucesso!!\n");
            r = 0;
            system("pause");
            break;
        }
    }
    if(r)
    {
        printf("A tabela medico nao tem espaco para armazenar dados\n");
        system("pause");
    }
}

void cadastrarPaciente(tpaciente * pac)
{
    int i, r = 1;
    for(i = 0; i < NUM_PAC; i++)
    {
        if(i != pac[i].codPac)
        {
            pac[i].codPac = i;
            printf("Informe o nome do paciente:\n>>>> ");
            scanf(" %[^\n]", pac[i].nome);
            printf("\nInforme o sexo dele: (M ou F)\n>>>> ");
            scanf(" %c", &pac[i].sexo);
            printf("\nInforme a idade dele:\n>>>> ");
            scanf(" %d", &pac[i].idade);
            printf("\nPaciente cadastrado com sucesso!!\n");
            r = 0;
            system("pause");
            break;
        }
    }
    if(r)
    {
        printf("A tabela paciente nao tem espaco para armazenar dados\n");
        system("pause");
    }
}

void listaMedico(tmedico * med)
{
    int i, c = 0;
    printf(" Medico(s):\n\n");
    for(i = 0; i < NUM_MED; i++)
    {
        if(i == med[i].codMed)
        {
            printf("-----------------------------------------\n");
            printf("  Codigo: %d\n", med[i].codMed);
            printf("  nome: %s\n", med[i].nome);
            printf("  Especialidade: %s\n", med[i].especialidade);
            printf("-----------------------------------------\n");
            c++;
        }
    }
    if(c == 0)
        printf("  Nenhum medico foi cadastrado\n");
    system("pause");
}

void listaPaciente(tpaciente * pac)
{
    int i, c = 0;
    printf(" Paciente(s):\n\n");
    for(i = 0; i < NUM_PAC; i++)
    {
        if(i == pac[i].codPac)
        {
            printf("-----------------------------------------\n");
            printf("  Codigo: %d\n", pac[i].codPac);
            printf("  nome: %s\n", pac[i].nome);
            printf("  Sexo: %c\n", pac[i].sexo);
            printf("  Idade: %d\n", pac[i].idade);
            printf("-----------------------------------------\n");
            c++;
        }
    }
    if(c == 0)
        printf("  Nenhum paciente foi cadastrado\n");
    system("pause");
}

void cadastrarConsulta(tmedico *med,tpaciente * pac,tconsulta * cons)
{
    int i, n, d, h, j,r = 1;
    for(i = 0; i < NUM_CONS; i++)
    {
        if(i != cons[i].numPront)
        {
            cons[i].numPront = i;
            printf("Informe o codigo do paciente:\n>>>> ");
            scanf(" %d", &cons[i].cod_pac);
            n = cons[i].cod_pac;
            if(pac[n].codPac != n)
            {
                printf("\nPaciente nao cadastrado\n");
                system("pause");
                break;
            }
            printf("\nInforme o codigo do medico:\n>>>> ");
            scanf(" %d", &cons[i].cod_med);
            n = cons[i].cod_med;
            if(med[n].codMed != n)
            {
                printf("\nMedico nao cadastrado\n");
                system("pause");
                break;
            }
            do
            {
                d = 0;
                h = 0;
                printf("\nInforme a data da consulta: (dd/mm/aaaa):\n>>>> ");
                scanf(" %s", cons[i].data);
                for(j = 0; j < NUM_CONS; j++)
                    if(!strcmp(cons[i].data, cons[j].data))
                        d++;
                printf("\nInforme o horario da consulta: (hh:mm)\n>>>> ");
                scanf(" %s", cons[i].horario);
                for(j = 0; j < NUM_CONS; j++)
                    if(!strcmp(cons[i].horario, cons[j].horario))
                        h++;
                if(d > 1 && h > 1)
                {
                    printf("\nErro: Existe uma consulta para essa data e horario\n");
                }
            }
            while(d > 1 && h > 1);
            printf("\nConsulta cadastrado com sucesso!!\n");
            r = 0;
            system("pause");
            break;
        }
    }
    if(r)
    {
        printf("A tabela consulta nao tem espaco para armazenar dados\n");
        system("pause");
    }
}

void listaConsulta(tmedico * med,tconsulta * cons)
{
    int i, j, r = 1, cod, cs = 0;
    char nomeMed[100], data[20];
    printf("Informe o nome do medico:\n>>>> ");
    scanf(" %[^\n]", nomeMed);
    for(i = 0; i < NUM_MED; i++)
    {
        if(!strcmp(nomeMed, med[i].nome))
        {
            cod = med[i].codMed;
            r = 0;
            break;
        }
    }
    if(r)
    {
        printf("\nMedico nao cadastrado\n");
        system("pause");
    }
    else
    {
        r = 1;
        for(i = 0; i < NUM_CONS; i++)
        {
            if(cod == cons[i].cod_med)
            {
                r = 0;
                break;
            }
        }
        if(r)
        {
            printf("\nMedico nao tem consulta cadastrada\n");
            system("pause");
        }
        else
        {
            printf("\nInforme a data: (dd/mm/aaaa)\n>>>> ");
            scanf(" %s", data);
            for(i = 0; i < NUM_CONS; i++)
            {
                if((strcmp(cons[i].data, data) < 0) && (cons[i].cod_med == cod))
                {
                    printf("-----------------------------------------\n");
                    printf("  Numero do prontuario: %d\n", cons[i].numPront);
                    printf("  Data: %s\n", cons[i].data);
                    printf("  Horario: %s\n", cons[i].horario);
                    printf("  Codigo Medico: %d\n", cons[i].cod_med);
                    printf("  Codigo Paciente: %d\n", cons[i].cod_pac);
                    printf("-----------------------------------------\n");
                    cs++;
                }
            }
            if(cs == 0)
                printf("\nMedico nao tem consulta anterior a data\n");
            system("pause");
        }
    }
}
