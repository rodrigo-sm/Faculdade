/*
2. Escreva uma função de protótipo void init_vetor(int a[], int n, int val);
que inicialize o vetor a com n elementos com o valor de val.
*/
#include <stdio.h>

void init_vetor(int a[], int n, int val);

int main()
{
    int n,val,i;
    printf("Informe a quantidade de elementos: ");
    scanf("%d", &n);
    printf("Informe o vetor:\n");
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d", &a[i]);
    printf("Informe o valor: ");
    scanf("%d", &val);
    init_vetor(a,n,val);
    for(i=0;i<n;i++) printf("%d\n", a[n]);
}

 void init_vetor(int a[], int n, int val)
 {
     int i;
    for(i=0;i<n;i++)
    {
        a[i] = val;
    }
 }
