/*
7. Escreva uma função que calcule a área e o volume de uma esfera de raio r. Essa função
deve obedecer ao protótipo:
void calc_esfera(float r, float * area, float * volume);
*/

#include <stdio.h>
#include <math.h>

void calc_esfera(float r, float * area, float * volume);

int main()
{
    float area, volume, r;
    printf("Informe o raio:\n");
    scanf("%f", &r);
    calc_esfera(r, &area, &volume);
    printf("Volume: %.2f\nArea: %.2f", volume, area);
    return 0;
}

void calc_esfera(float r, float * area, float * volume)
{
    *area = 4 * M_PI * pow(r,2);
    *volume= (4/3) * M_PI * pow(r,3);
}
