#include <stdio.h>

void selection_sort(int *, int );
void imprimeBaralho(int *, int *, int *, int *, int);

int main()
{
    int copas[] = {2,6,7,1,8,9,14,11,10,3,5,12,6,13};
    int paus[] = {2,6,7,1,8,9,14,11,10,3,5,12,6,13};
    int espada[] = {2,6,7,1,8,9,14,11,10,3,5,12,6,13};
    int ouro[] = {2,6,7,1,8,9,14,11,10,3,5,12,6,13};
    fprintf(stdout, "\t\tBaralho nao ordenado\n");
    imprimeBaralho(copas, paus, espada, ouro, 14);
    selection_sort(copas, 14);
    selection_sort(paus, 14);
    selection_sort(paus, 14);
    selection_sort(paus, 14);
    fprintf(stdout, "\t\tBaralho ordenado\n");
    imprimeBaralho(copas, paus, espada, ouro, 14);

}

void selection_sort(int *num, int tam) {
  int i, j, min, aux;
  for (i = 0; i < (tam-1); i++)
  {
     min = i;
     for (j = (i+1); j < tam; j++) {
       if(num[j] < num[min])
         min = j;
     }
     if (num[i] != num[min]) {
       aux = num[i];
       num[i] = num[min];
       num[min] = aux;
     }
  }
}

void imprimeBaralho(int *copas, int *paus, int *espada, int *ouro, int tam)
{
    int i;
    fprintf(stdout, "---------------------------------------------------------------------\n");
    fprintf(stdout, "|     Copas[]    |     Ouro[]     |     Paus[]     |    Espada[]    |\n");
    fprintf(stdout, "| Carta | Indice | Carta | Indice | Carta | Indice | Carta | Indice |\n");
    for(i = 0; i < tam; i++)
    {
        if(v[i] > 0 && v[i] <= 11)
            fprintf(stdout, "|   %d   |   %d    |   %d   |   %d    |   %d   |   %d    |   %d   |    %d   |\n", copas[i], i, ouro[i], i, paus[i], i, espada[i],  i);
        else
        {
            switch(v[i])
            {
            case 1:
                fprintf(stdout, "|   A  |   %d   |   A  |   %d   |   A  |   %d   |   A  |   %d   |\n", i, i, i, i);
                break;
            case 12:
                fprintf(stdout, "|   J  |   %d   |   J  |   %d   |   J  |   %d   |   J  |   %d   |\n", i, i, i, i);
                break;
            case 13:
                fprintf(stdout, "|   Q  |   %d   |   Q  |   %d   |   Q  |   %d   |   Q  |   %d   |\n", i, i, i, i);
                break;
            case 14:
                fprintf(stdout, "|   K  |   %d   |   K  |   %d   |   K  |   %d   |   K  |   %d   |\n", i, i, i, i);
                break;

            }
        }
    }
    fprintf(stdout, "---------------------------------------------------------------------\n");
}
