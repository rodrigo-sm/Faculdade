/*
1. Escreva uma função que inverte uma dada string1 e guarda o resultado em string2: ˜
void InverteString(char string1[], char string2[], int n);
*/
#include <stdio.h>
#include <string.h>
void InverteString(char string1[], char string2[], int n);

int main()
{
    char string1[81],string2[81];
    printf("Informe a string1: ");
    scanf("%80[^\n]", string1);
    int n = strlen(string1);
    InverteString(string1,string2,n);
    printf("String2: %s\n",string2);
    return 0;
}

void InverteString(char string1[], char string2[], int n)
{
    int i;
    n--;
    for(i = 0;n >= 0 ;i++,n--)
    {
        string2[i] = string1[n];
    }
    string2[i] = '\0';
}
