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
int main()
{
    int r, v[101] = {0}, c1, c2, saque, qtd_c1, qtd_c2,aux;
    v[2] = 1; v[5] = 1; v[10] = 1; v[20] = 1; v[50] = 1; v[100] = 1;
    do{
        //Seleciona o saque e verifica se e valido
        system ("cls");
        printf ("************************\n* Saque minimo 7 reais *\n************************\n Informe o saque: ");
        scanf (" %d", &saque);
        while (saque < 7)
        {
            system ("cls");
            printf ("***************************\n* Saque menor que 7 reais *\n***************************\n Informe o saque novamente: ");
            scanf (" %d", &saque);
        }
        system ("cls");
        //Seleciona a primeira cedula e verifica se e valido
        printf("***********************************\n* Cedulas = 2, 5, 10, 25, 50, 100 *\n***********************************\n Informe a primeira cedula: ");
        scanf (" %d", &c1);
        while (v[c1] == 0)
        {
            system ("cls");
            printf("*******************\n* Cedula invalida *\n*******************\n Informe a primeira cedula:  ");
            scanf (" %d", &c1);
        }
        v[c1] = 0;
        system ("cls");
        //Seleciona a primeira cedula e verifica se e valido
        printf("***********************************\n* Cedulas = 2, 5, 10, 25, 50, 100 *\n***********************************\n Informe a segunda cedula: ");
        scanf(" %d", &c2);
        while (v[c2] == 0)
        {
            system("cls");
            if(c2 == c1)
                printf("**********************\n* Cedula ja informada*\n**********************\n Informe a segunda cedula:  ");
            else
                printf("*******************\n* Cedula invalida*\n*******************\n Informe a segunda cedula:  ");
            scanf(" %d", &c2);
        }
        //Ordena as cedulas
        if(c1 < c2)
        {
            aux = c1;
            c1 = c2;
            c2 = aux;
        }
        //Calculo da quantidade de cedulas
        qtd_c1 = saque / c1;
        saque %= c1;
        if (saque == 0)
        {
            qtd_c1--;
            saque += c1;
        }
        qtd_c2 = saque / c2;
        saque %= c2;
        system("cls");
        //Verifica se o saque e valido
        if (saque == 0) {
            printf ("**********************************\n* Quantidade de cedulas de %d = %d *\n", c1,qtd_c1);
            printf ("* Quantidade de cedulas de %d = %d *\n**********************************\n", c2, qtd_c2);
        }
        else
            printf("******************\n* Saque invalido *\n******************");
            printf ("\n\n Quer realizar outro saque (1 - sim / 0 - nao): ");
            scanf (" %d", &r);
    }while(r);
}
