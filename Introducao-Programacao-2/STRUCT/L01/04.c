/* 04.c
 *
 * Programa que cadastra n computadores e depois lista os dados
 * com base em algumas condicoes
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Introducao a Computacao-II
 *
 * 09/10/2018
 */

#include <stdio.h>
#include <stdlib.h>


 struct processador{
    int frequencia;
    char fabri[50];
 };

 struct monitor{
    int tam;
    char tipo[10];
    char fabri[50];
 };

 struct pc {
    struct processador proc;
    struct monitor mon;
    int hd;
    int ram;
 };

 int main()
 {
    int n, i = 0;
    printf("Quantos computadores deseja cadastrar:\n>>>> ");
    scanf(" %d", &n);
    struct pc vetpc[n];
    int n1 = n;
    while(n--)
    {
        i++;
        system("cls");
        printf("Informacoes do %d pc\n\n", i);
        printf("Informe a frequencia do processador:\n>>>> ");
        scanf(" %d", &vetpc[n].proc.frequencia);
        printf("\nInforme o fabricante do processador:\n>>>> ");
        scanf(" %[^\n]", vetpc[n].proc.fabri);
        printf("\nInforme o tamanho do monitor:\n>>>> ");
        scanf(" %d", &vetpc[n].mon.tam);
        printf("\nInforme o tipo do monitor:\n>>>> ");
        scanf(" %[^\n]", vetpc[n].mon.tipo);
        printf("\nInforme o fabricante do monitor:\n>>>> ");
        scanf(" %[^\n]", vetpc[n].mon.fabri);
        printf("\nInforme a capacidade de disco:\n>>>> ");
        scanf(" %d", &vetpc[n].hd);
        printf("\nInforme a memoria RAM\n>>>> ");
        scanf(" %d", &vetpc[n].ram);
        system("cls");
    }
    i = 1;
    while(n1--)
    {
        if((vetpc[n1].proc.frequencia > 2) && (vetpc[n1].mon.tam > 17) && (vetpc[n1].ram >= 5))
        {
            printf("%d PC\n\n", i);
            printf(" Processador\n  - Frequencia: %d\n  - Fabricante: %s\n", vetpc[n1].proc.frequencia, vetpc[n1].proc.fabri);
            printf(" Monitor\n  - Tamanho: %d\n  - Tipo: %s\n  - Fabricante: %s\n", vetpc[n1].mon.tam, vetpc[n1].mon.tipo, vetpc[n1].mon.fabri);
            printf(" Disco rigido: %d\n RAM: %d\n", vetpc[n1].hd, vetpc[n1].ram);
            printf("-------------------------------------------------------------\n");
            i++;
        }
    }
 }
