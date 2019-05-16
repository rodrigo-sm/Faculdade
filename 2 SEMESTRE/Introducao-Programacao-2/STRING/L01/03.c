/*
3. Escreva um programa que dada uma string, remove todos os espaços em branco dessa
string e depois a imprime no vídeo.
*/
#include <stdio.h>

int main()
{
    int x,y,z;
    char str[81];
    scanf("%80[^\n]", str);
    for(x = 0;str[x] != '\0';x++)
    {
        if(str[x] == ' ')
        {
            for(z = x, y = x + 1;str[y] != '\0';z++,y++)
                str[z] = str[y];
            str[z] = str[y];
        }
    }
    printf("%s\n", str);
    return 0;
}
