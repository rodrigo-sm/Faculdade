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
        int v[TAM], aux, i, j;
        fread(v, sizeof(int), TAM, p);
        fclose(p);
        double t;
        clock_t tempo;
        tempo = clock();
        // Ordena por Bubble sort
        for(i = 0; i < TAM; i++)
        {
            for(j = i+1; j < TAM; j++)
            {
                if(v[i] < v[j])
                {
                    aux = v[i];
                    v[i] = v[j];
                    v[j] = aux;
                }
            }
        }
        t = (double) (clock() - tempo)  / CLOCKS_PER_SEC;
        if((p = fopen("timeBubble.txt", "w")) == NULL)
            fprintf(stderr, "Erro: Nao foi possivel criar o arquivo timeBubble.txt\n");
        else
        {
            fprintf(p, "Tempo: %lf segundos", t);
            fclose(p);
            if((p = fopen("BubbleSort.bin", "wb")) == NULL)
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
