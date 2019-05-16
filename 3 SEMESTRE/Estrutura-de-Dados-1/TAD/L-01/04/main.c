#include <stdio.h>
#include <stdlib.h>
#include "retangulo.h"

int main()
{
    ponto p;
    retangulo r;
    int alt, comp;
    printf("Informe as coordenadas x e y do ponto que representa o vertice superior esquerdo do retangulo:\n>>>> ");
    scanf("%d %d", &p.x, &p.y);
    printf("\nInforme a altura do retangulo:\n>>>> ");
    scanf(" %d", &alt);
    printf("\nInforme o comprimento do retangulo:\n>>>> ");
    scanf(" %d", &comp);
    ret_init(&r, p.x, p.y, alt, comp);
    printf("\nArea do retangulo: %d\n", ret_area(r));
    printf("\nInforme as coordenadas x e y de um ponto para verificar se esta dentro do retangulo:\n>>>> ");
    scanf("%d %d", &p.x, &p.y);
    if(ret_contains(r, p))
        printf("\nO ponto (%d, %d) esta dentro do retangulo\n", p.x, p.y);
    else
        printf("\nO ponto (%d, %d) nao esta dentro do retangulo\n", p.x, p.y);
    return 0;
}
