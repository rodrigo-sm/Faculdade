#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

int main()
{
    ponto p;
    retangulo r;
    int alt, comp, count = 0, resp, n = 0;
    printf("Informe as coordenadas x e y do ponto que representa o vertice superior esquerdo do retangulo:\n>>>> ");
    scanf("%d %d", &p.x, &p.y);
    printf("\nInforme a altura do retangulo:\n>>>> ");
    scanf(" %d", &alt);
    printf("\nInforme o comprimento do retangulo:\n>>>> ");
    scanf(" %d", &comp);
    ret_init(&r, p.x, p.y, alt, comp);
    do
    {
        printf("\nInforme as coordenadas x e y do ponto para verificar se esta dentro do retangulo:\n>>>> ");
        scanf(" %d %d", &p.x, &p.y);
        if(ret_contains(r, p))
            count++;
        n++;
        printf("Deseja informa mais um ponto (0 - NAO \\ 1 - SIM) ?\n>>>> ");
        scanf(" %d", &resp);
    }while(resp != 0);
    printf("Dos %d pontos informados somente %d estao dentro do retangulo\n", n, count);
    return 0;
}
