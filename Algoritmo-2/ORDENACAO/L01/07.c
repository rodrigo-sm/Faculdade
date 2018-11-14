#include <stdio.h>
#include <time.h>

#define TAM 100000

void quick_sort(int *, int, int);

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
        // Ordena por Quick Sort
        quick_sort(v, 0, TAM - 1);
        t = (double) (clock() - tempo)  / CLOCKS_PER_SEC;
        if((p = fopen("timeQuick.txt", "w")) == NULL)
            fprintf(stderr, "Erro: Nao foi possivel criar o arquivo timeBubble.txt\n");
        else
        {
            fprintf(p, "Tempo: %lf segundos", t);
            fclose(p);
            if((p = fopen("QuickSort.bin", "wb")) == NULL)
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

void quick_sort(int *a, int left, int right) {
    int i, j, x, y;

    i = left;
    j = right;
    x = a[(left + right) / 2];

    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }

    if(j > left) {
        quick_sort(a, left, j);
    }
    if(i < right) {
        quick_sort(a, i, right);
    }
}
