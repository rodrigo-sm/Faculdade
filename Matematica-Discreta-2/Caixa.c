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

// Imprime a logo "CAIXA"
void logo();

// Imprime o menu inicial
void menu();

//Imprime um alerta caso a opcao escolhida seja invalida
void erroMenu();

// Imprime texto do saque
void textSaque();

// Imprime um alerta caso o saque informado seja menor que 7
void textErroSaque();

// A função retorna o valor do saque
int saque();
// Imprime o texto cedula
void textCed(int i, int c1);

// Imprime  um alerta caso a cedula seja invalida
void textErroCed();

// Imprime um alerta caso a cedula ja foi escolhida
void textErroRepCed();

// Recebe o vetor v que contem as cedulas validas e as escolhidas e o inteiro i que representa o numero da cedula escolhida
// e devolve o valor da cedula
int ced(int *v, int i, int c1);

// Ordena c1 e c2 de forma descrecente
void orderna(int *c1,int *c2);

// Imprime a quantidade de cedulas
void imprimiQntdCed(int qtd_c1,int qtd_c2,int c1,int c2,int saque);

int main()
{
    int v[101] = {0}, c1, c2, saq, qtd_c1, qtd_c2, opcao = 1;
    do{
        //Seleciona o saque e verifica se e valido
        system ("cls");
        v[2] = 1; v[5] = 1; v[10] = 1; v[20] = 1; v[50] = 1; v[100] = 1;
        if(opcao != 1)
        {
            logo();
            erroMenu();
        }
        logo();
        menu();
        scanf(" %d", &opcao);
        switch(opcao) {
            case 0: break;
            case 1:
                saq = saque();
                c1 = ced(v, 1, c1);
                c2 = ced(v, 2, c1);
                orderna( &c1, &c2);
                imprimiQntdCed( qtd_c1, qtd_c2, c1, c2, saq);
                break;
        }
    } while(opcao);
    return 0;
}

void logo()
{
    printf("+--------------------------------------+\n");
    printf("| $$$$$$  $$$$$$  $$  $$    $$  $$$$$$ |\n");
    printf("| $$      $$  $$  $$   $$  $$   $$  $$ |\n");
    printf("| $$      $$  $$  $$    $$$$    $$  $$ |\n");
    printf("| $$      $$$$$$  $$     $$     $$$$$$ |\n");
    printf("| $$      $$  $$  $$    $$$$    $$  $$ |\n");
    printf("| $$      $$  $$  $$   $$  $$   $$  $$ |\n");
    printf("| $$$$$$  $$  $$  $$  $$    $$  $$  $$ |\n");
    printf("+--------------------------------------+\n");
}
void menu()
{
    printf("|             Bem Vindo!!!             |\n");
    printf("+--------------------------------------+\n");
    printf("| Menu                                 |");
    printf("\n| 1 - Saque                            |");
    printf("\n| 0 - Sair                             |\n");
    printf("+--------------------------------------+");
    printf("\n>>>> ");
}

void erroMenu()
{
    printf("|\tErro: Opcao invalida           |");
    printf("\n+--------------------------------------+\n");
    system("pause");
    system("cls");

}

void textSaque()
{
    printf("| Saque minimo = 7 $                   |\n");
    printf("+--------------------------------------+\n");
    printf("| Informe o saque:                     |");
    printf("\n+--------------------------------------+");
    printf("\n>>>> ");
}

void textErroSaque()
{
    printf("|\tErro: Saque menor que 7        |");
    printf("\n+--------------------------------------+\n");
    system("pause");
    system("cls");
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
        logo();
        textSaque();
        scanf(" %d", &saque);
    }
    system ("cls");
    return saque;
}

void textCed(int i, int c1)
{
    printf("| Cedulas = ");
    if(i == 2)
    {
        if(c1 != 2)
            printf("|2");
        if(c1 != 5)
            printf("|5");
        if(c1 != 10)
            printf("|10");
        if(c1 != 25)
            printf("|20");
        if(c1 != 50)
            printf("|50");
        if(c1 != 100)
            printf("|100");
        printf("|          ");
        switch(c1)
        {
        case 100: printf(" ");
        case 50:
        case 20:
        case 10: printf(" ");
        case 5:
        case 2: printf(" ");
        }
        printf("|");
    }
    else
        printf("|2|5|10|20|50|100          |");
    printf("\n+--------------------------------------+");
    printf("\n| Escolha a %d cedula:                  |", i);
    printf("\n+--------------------------------------+");
    printf("\n>>>> ");
}

void textErroCed()
{
    printf("|\tErro: Cedula invalida          |");
    printf("\n+--------------------------------------+\n");
    system("pause");
    system("cls");
}

void textErroRepCed()
{
    printf("|\tErro: Cedula ja informada      |");
    printf("\n+--------------------------------------+\n");
    system("pause");
    system("cls");
}

int ced(int *v, int i, int c1)
{
    int ced;
    system ("cls");
    logo();
    textCed(i, c1);
    scanf(" %d", &ced);
    while(v[ced] == 0 || v[ced] == -1)
    {
        system ("cls");
        if(v[ced] == -1)
        {
            logo();
            textErroRepCed();
        }
        else
        {
            logo();
            textErroCed();
        }
        logo();
        textCed(i, c1);
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

void imprimiQntdCed(int qtd_c1, int qtd_c2, int c1, int c2, int saque)
{
    int r = 1,i,j;
    qtd_c1 = saque / c1;
    saque %= c1;
    system("cls");
    logo();
    if (saque == 0)
    {
        printf("| Quantidade de cedulas de %d = %d", c1, qtd_c1);
        //Vai imprimir a quantidade de espaços para nao extrapolar a caixa
        j = 0;
        for(i = 1; i <= c1; i*=10, j++);
        for(i = 1; i <= qtd_c1; i*=10, j++);
        for(; j < 9; j++)
        {
            printf(" ");
        }
        printf("|");
        printf("\n| Quantidade de cedulas de %d = 0", c2);
        //Vai imprimir a quantidade de espaços para nao extrapolar a caixa
        j = 1;
        for(i = 1; i <= c2; i*=10, j++);
        for(; j < 9; j++)
        {
            printf(" ");
        }
        printf("|");
        r = 0;
        qtd_c1--;
        saque += c1;
    }
    qtd_c2 = saque / c2;
    saque %= c2;
    if(qtd_c1 != 0 && saque == 0)
    {
        if(r == 0)
        printf("\n+---------------- OU ------------------+\n");
        printf("| Quantidade de cedulas de %d = %d", c1, qtd_c1);
        //Vai imprimir a quantidade de espaços para nao extrapolar a caixa
        j = 0;
        for(i = 1; i <= c1; i*=10, j++);
        for(i = 1; i <= qtd_c1; i*=10, j++);
        for(; j < 9; j++)
        {
            printf(" ");
        }
        printf("|");
        printf("\n| Quantidade de cedulas de %d = %d", c2, qtd_c2);
        //Vai imprimir a quantidade de espaços para nao extrapolar a caixa
        j = 0;
        for(i = 1; i <= c2; i*=10, j++);
        for(i = 1; i <= qtd_c2; i*=10, j++);
        for(; j < 9; j++)
        {
            printf(" ");
        }
        printf("|");
    }
    else if(r)
    {
        printf("|\tErro: Saque invalido           |");
    }
    printf("\n+--------------------------------------+\n");
    system("pause");
    system("cls");
}

