/* 03.c
 *
 * Programa armazena dados de carros em uma struct e lista os dados
 * com base em uma condicao escolhida pelo usuario
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Introducao a computacao-II
 *
 * 09/10/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carro{
    char marca[15];
    int ano;
    char cor[10];
    float preco;
};

int main()
{
    int opcao, i = 0, x;
    char marca[15];
    float base;
    struct carro vetcarros[20];
    do{
        printf("Menu\n 0 - Sair\n 1 - Cadastrar um carro\n 2 - Listar os carros com base em um preco\n 3 - Listar os carros de uma determinada marca\n>>>> ");
        scanf(" %d", &opcao);
        switch(opcao)
        {
        case 1:
            if(i < 20)
            {
                system("cls");
                printf("Informe a marca do carro:\n>>>> ");
                scanf(" %[^\n]", vetcarros[i].marca);
                system("cls");
                printf("Informe o ano do carro:\n>>>> ");
                scanf(" %d", &vetcarros[i].ano);
                system("cls");
                printf("Informe a cor do carro:\n>>>> ");
                scanf(" %[^\n]", vetcarros[i].cor);
                system("cls");
                printf("Informe o preco do carro:\n>>>> ");
                scanf(" %f", &vetcarros[i].preco);
                system("cls");
                i++;
            }
            else
            {
                printf("\nNao tem espaco para armazenar carro\n");
                system("cls");
            }
            break;
        case 2:
            system("cls");
            printf("Informe o preco base:\n>>>> ");
            scanf(" %f", &base);
            for(x = 0; x < i; x++)
            {
                if(vetcarros[x].preco <= base)
                {
                    printf("Carro %s %d %s custa %.2f$\n", vetcarros[x].marca, vetcarros[x].ano, vetcarros[x].cor, vetcarros[x].preco);
                }
            }
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            printf("Escolha uma marca:\n>>>> ");
            scanf(" %[^\n]", marca);
            for(x = 0; x < i; x++)
            {
                if(!strcmp(vetcarros[x].marca, marca))
                {
                    printf("Carro %s %d %s custa %.2f$\n", vetcarros[x].marca, vetcarros[x].ano, vetcarros[x].cor, vetcarros[x].preco);
                }
            }
        }
    } while(opcao);
}
