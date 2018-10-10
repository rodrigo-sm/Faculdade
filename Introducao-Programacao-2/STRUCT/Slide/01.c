/* 05.c
 *
 * Programa que dados dois circulos verifica se eles se sobrepoem.
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Introducao a Computacao-II
 *
 * 10/10/2018
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

 struct  ponto {
    float x;
    float y;
 };

 struct circulo {
    struct ponto centro;
    float raio;
 };

 int main()
 {
     int i;
     struct circulo circ[2];
     for(i = 0; i < 2; i++)
     {
         printf("Informe X do %d circulo:\n>>>> ", i+1);
         scanf(" %f", &circ[i].centro.x);
         printf("\nInforme Y do %d circulo:\n>>>> ", i+1);
         scanf(" %f", &circ[i].centro.y);
         printf("\nInforme o raio do %d circulo:\n>>>> ", i+1);
         scanf(" %f", &circ[i].raio);
         system("cls");
     }
     float somaRaio = circ[0].raio + circ[1].raio;
     float X = circ[0].centro.x - circ[1].centro.x;
     float Y = circ[0].centro.y - circ[1].centro.y;
     float dist = sqrt(pow(X, 2) + pow(Y, 2));
     if(dist < somaRaio)
        printf("Os circulos se sobrepoem\n");
     else
        printf("Os circulos nao se sobrepoem\n");
     return 0;
 }
