#include <stdio.h>

int main()
{
    FILE *p;
    if((p = fopen("timeBubble.txt", "r")) == NULL)
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo\n");
    else
    {
        double timeBubble;
        fscanf(p, "Tempo: %lf segundos", &timeBubble);
        fclose(p);
        if((p = fopen("timeInsert.txt", "r")) == NULL)
            fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo\n");
        else
        {
            double timeInsert;
            fscanf(p, "Tempo: %lf segundos", &timeInsert);
            fclose(p);
            if((p = fopen("timeQuick.txt", "r")) == NULL)
                fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo\n");
            else
            {
                double timeQuick;
                fscanf(p, "Tempo: %lf segundos", &timeQuick);
                fclose(p);
                if((p = fopen("timeSelection.txt", "r")) == NULL)
                    fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo\n");
                else
                {
                    double timeSelection;
                    fscanf(p, "Tempo: %lf segundos", &timeSelection);
                    fclose(p);
                    fprintf(stdout, "Tempo do BubbleSort: %lf segundos\nTempo do InsertSort: %lf segundos\nTempo do SelectionSort: %lf segundos\nTempo do QuickSort: %lf segundos\n", timeBubble, timeInsert, timeSelection, timeQuick);
                    return 0;
                }
            }
        }
    }
}
