#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 100000

int main()
{
    int i, v[TAM];
    srand(time(NULL));
    for(i = 0; i < TAM; i++)
        v[i] = rand() % TAM;
    FILE *p;
    if((p = fopen("vetor.bin", "wb")) == NULL)
        fprintf(stderr, "Erro: Nao foi possivel gerar o arquivo binario do vetor (vetor.bin)\n");
    else
    {
        fwrite(v, sizeof(int), TAM, p);
        fclose(p);
        fprintf(stdout, "Arquivo criado com sucesso!\n");
    }
    return 0;
}
