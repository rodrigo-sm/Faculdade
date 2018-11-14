#include <stdio.h>
#include <time.h>

#define TAM 100000

void insertion_sort(int *, int);

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
        // Ordena por Insercao Sort
        insertion_sort(v, TAM);
        t = (double) (clock() - tempo)  / CLOCKS_PER_SEC;
        if((p = fopen("timeInsert.txt", "w")) == NULL)
            fprintf(stderr, "Erro: Nao foi possivel criar o arquivo timeBubble.txt\n");
        else
        {
            fprintf(p, "Tempo: %lf segundos", t);
            fclose(p);
            if((p = fopen("SortInsertion.bin", "wb")) == NULL)
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

void insertion_sort(int *vetor, int tamanhoVetor) {

int escolhido, j;

    for (int i = 1; i < tamanhoVetor; i++) {
		escolhido = vetor[i];
		j = i - 1;

		while ((j >= 0) && (vetor[j] > escolhido)) {
			vetor[j + 1] = vetor[j];
			j--;
		}

		vetor[j + 1] = escolhido;
	}
}
