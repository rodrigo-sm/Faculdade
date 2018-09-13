/*
5)	Escreva uma função que receba uma string e substitua cada segmento de dois ou mais espaços em branco por um só caracter ' '.
*/
#include <stdio.h>

int main()
{
    int i,j,k;
    char str[81];
    printf("Informe a string: ");
    scanf("%80[^\n]", str);
    for(i = 0;str[i] != '\0';i++)
    {
        if(str[i] == ' ' && str[++i] == ' ')
        {
            j = i + 1;
            while(str[j] == ' ') j++;
            for(k = i;str[j] != '\0';j++,k++)
                str[k] = str[j];
            str[k] = '\0';
        }
    }
    printf("String formatada: %s\n", str);
    return 0;
}
