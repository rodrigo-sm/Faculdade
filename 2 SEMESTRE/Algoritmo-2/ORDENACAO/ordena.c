#include <stdio.h>
#include <time.h>

void criaVetor(int *, int);
void ordenaVetor(int *, int);
void buscaNum(int *, int);

int main()
{
    srand(time(NULL));
    int v[1000];
    criaVetor(v, 1000);
    ordenaVetor(v, 1000);
    buscaNum(v, 1000);
    return 0;
}

void criaVetor(int * v, int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    {
        v[i] = rand() % 1001;
        printf("Cria: %d\n", v[i]);
    }
}

void ordenaVetor(int * v, int tam)
{
    int i, j, aux;
    for(i = 0; i < tam; i++)
        for(j = i+1; j < tam; j++)
            if(v[i] > v[j])
            {
                aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
    for(i = 0; i < tam; i++)
        printf("Ordena: %d\n", v[i]);
}

void buscaNum(int * v, int tam)
{
    printf("Informe o numero: ");
    int n, ite = 0;
    scanf(" %d", &n);
    int i = n;
    if(v[i] != n)
        if(v[i] > n)
            while(v[i--] != n && v[i] > n)ite++;
        else
            while(v[i++] != n && v[i] < n)ite++;
    if(v[i] == n)
    {
       printf("Indice: %d\n", i);
       printf("Numero %d\n", v[i]);
    }
    else
        printf("Numero nao encontrado\n");
    printf("Iteracoes: %d\n", ite);

}
