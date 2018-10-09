/* Caixa.c
 *
 * Programa simulador de caixa eletronico
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Matematica Discreta-II
 *
 * 06/10/2018
 */

#include <stdio.h>
#include <stdlib.h>

void logo();
void menu();
void erroMenu();
void textSaque();
void textErroSaque();
int saque();
void textCed(int i);
void textErroCed();
void textErroRepCed();
int ced(int *v, int i);
void orderna(int *c1,int *c2);
void qntdCed(int *qtd_c1, int *qtd_c2, int c1, int c2, int *saque);
void imprimiQntdCed(int *qtd_c1,int *qtd_c2,int c1,int c2,int *saque);

int main()
{
    int v[101] = {0}, c1, c2, saq, qtd_c1, qtd_c2, opcao = 1;
    do{
        //Seleciona o saque e verifica se e valido
        system ("cls");
        v[2] = 1; v[5] = 1; v[10] = 1; v[20] = 1; v[50] = 1; v[100] = 1;
        logo();
        if(opcao != 1)
            erroMenu();
        menu();
        scanf(" %d", &opcao);
        switch(opcao) {
            case 0: break;
            case 1:
                saq = saque();
                c1 = ced(v, 1);
                c2 = ced(v, 2);
                orderna( &c1, &c2);
                qntdCed( &qtd_c1, &qtd_c2, c1, c2, &saq);
                imprimiQntdCed( &qtd_c1, &qtd_c2, c1, c2, &saq);
                break;
        }
    } while(opcao);
    return 0;
}

void logo()
{
    printf("/--------------------------------------\\\n");
    printf("/ $$$$$$  $$$$$$  $$  $$    $$  $$$$$$ \\\n");
    printf("/ $$      $$  $$  $$   $$  $$   $$  $$ \\\n");
    printf("/ $$      $$  $$  $$    $$$$    $$  $$ \\\n");
    printf("/ $$      $$$$$$  $$     $$     $$$$$$ \\\n");
    printf("/ $$      $$  $$  $$    $$$$    $$  $$ \\\n");
    printf("/ $$      $$  $$  $$   $$  $$   $$  $$ \\\n");
    printf("/ $$$$$$  $$  $$  $$  $$    $$  $$  $$ \\\n");
    printf("/--------------------------------------\\\n");
}
void menu()
{
    printf("\n Menu\n  1 - Saque\n  0 - Sair\n");
    printf("----------------------------------------");
    printf("\n>>>> ");
}

void erroMenu()
{
    printf("\tErro Opcao Invalida");
    printf("\n----------------------------------------\n");
}

void textSaque()
{
    printf("\n Informe o saque: ");
    printf("\n----------------------------------------");
    printf("\n>>>> ");
}

void textErroSaque()
{
    printf("\tErro Saque menor que 7");
    printf("\n----------------------------------------");
}

int saque()
{
    system ("cls");
    int saque;
    logo();
    textSaque();
    scanf(" %d", &saque);
    while(saque < 7)
    {
        system ("cls");
        logo();
        textErroSaque();
        textSaque();
        scanf(" %d", &saque);
    }
    system ("cls");
    return saque;
}

void textCed(int i)
{
    printf("\n   Cedulas = 2, 5, 10, 25, 50, 100");
    printf("\n----------------------------------------");
    printf("\n\n Escolha a %d cedula: ", i);
    printf("\n----------------------------------------");
    printf("\n>>>> ");
}

void textErroCed()
{
    printf("\tErro Cedula Invalida");
    printf("\n----------------------------------------");
}

void textErroRepCed()
{
    printf("\tErro Cedula Ja Informada");
    printf("\n----------------------------------------");
}

int ced(int *v, int i)
{
    int ced;
    system ("cls");
    logo();
    textCed(i);
    scanf(" %d", &ced);
    while(v[ced] == 0 || v[ced] == -1)
    {
        system ("cls");
        logo();
        if(v[ced] == -1)
            textErroRepCed();
        else
            textErroCed();
        textCed(i);
        scanf(" %d", &ced);
    }
    v[ced] = -1;
    system ("cls");
    return ced;
}

void orderna(int *c1, int *c2)
{
    int aux;
    if(*c1 < *c2)
    {
        aux = *c1;
        *c1 = *c2;
        *c2 = aux;
    }
}

void qntdCed(int *qtd_c1, int *qtd_c2, int c1, int c2, int *saque)
{
    *qtd_c1 = *saque / c1;
    *saque %= c1;
    if (*saque == 0)
    {
        *qtd_c1--;
        *saque += c1;
    }
    *qtd_c2 = *saque / c2;
    *saque %= c2;
}


void imprimiQntdCed(int *qtd_c1, int *qtd_c2, int c1, int c2, int *saque)
{
    system("cls");
    logo();
    if(*saque == 0)
    {
        printf("\n Quantidade de cedulas de %d = %d\n", c1, *qtd_c1);
        printf(" Quantidade de cedulas de %d = %d", c2, *qtd_c2);
        printf("\n----------------------------------------\n");
    }
    else
    {
        printf("\tErro Saque Invalido");
        printf("\n----------------------------------------\n");
    }
    system("pause");
    system("cls");
}
