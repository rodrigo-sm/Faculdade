#include <stdio.h>
#include <time.h>

#define TAM 100000

int main()
{
    FILE *p;
    if((p = fopen("vetor.bin", "rb")) == NULL)
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo do vetor binario (vetor.bin)\n");
    else
    {
        int v[TAM], aux, i, j, min;
        fread(v, sizeof(int), TAM, p);
        fclose(p);
        double t;
        clock_t tempo;
        tempo = clock();
        // Ordena por Selection Sort
        for (i = 0; i < (TAM-1); i++)
        {
            min = i;
            for (j = (i+1); j < TAM; j++)
            {
                if(v[j] < v[min])
                    min = j;
            }
            if (v[i] != v[min])
            {
                aux = v[i];
                v[i] = v[min];
                v[min] = aux;
            }
        }
        t = (double) (clock() - tempo)  / CLOCKS_PER_SEC;
        if((p = fopen("timeSelection.txt", "w")) == NULL)
            fprintf(stderr, "Erro: Nao foi possivel criar o arquivo timeBubble.txt\n");
        else
        {
            fprintf(p, "Tempo: %lf segundos", t);
            fclose(p);
            if((p = fopen("SortSelection.bin", "wb")) == NULL)
                fprintf(stderr, "Erro: Nao foi possivel criar o arquivo BubbleSort.bin\n");
            else
            {
                fwrite(v, sizeof(int), TAM, p);
                fclose(p);
                fprintf(stdout, "Programa executado com sucesso!\n");
                return 0;
            }
        }
    }
}
