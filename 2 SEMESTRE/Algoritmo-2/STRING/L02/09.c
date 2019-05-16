/*
9. Implemente uma função que receba duas strings como parâmetros e procure a primeira ocorrência da segunda string na primeira, retornando a posição da ocorrência,
ou -1 caso não haja nenhuma ocorrência. Por exemplo: str1 = “banana”, str2 = “ana” retorna 1. str1 = “Estruturas”, str2 = “tura” 1 retorna 5. str1 = “banana”, str2 = “ite” retorna -1.
Considere que caracteres maiúsculos e minúsculos são diferentes. ˜
int procura string (char* str1, char* str2);
*/
#include <stdio.h>

int ProcuraString (char* str1, char* str2);

int main()
{
    char str1[81],str2[81];
    printf("Informe a string 1: ");
    scanf("%80[^\n]", str1);
    printf("Informe a string 1: ");
    scanf(" %80[^\n]", str2);
    int p;
    p = ProcuraString(str1,str2);
    if(p == -1)
        printf("A string 2 nao aparece na string 1\n");
    else
        printf("A primeira ocorrencia da string 2 na string 1 e na posicao %d\n", p);
    return 0;

}

int ProcuraString (char* str1, char* str2)
{
    int i,j,k,p;
    for(i = 0,j = 0;str1[i] != '\0';i++)
    {
        if(str1[i] == str2[j])
        {
            p = i + 1;
            for(k = i;str2[j] != '\0';k++,j++)
            {
                if(str1[k] != str2[j])
                {
                    break;
                }
            }
            if(str2[j] == '\0')
                return p;
            j = 0;
        }
    }
    return -1;
}
