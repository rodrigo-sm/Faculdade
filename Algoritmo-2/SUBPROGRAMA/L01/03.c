/*
 Crie uma função que recebe uma string e um caractere, e apague todas as ocorrências desses caractere na string.
*/

#include <stdio.h>

void deleta(char *s1, char c);

int main()
{
    char s1[81],c;
    scanf(" %80[^\n]", s1);
    scanf(" %c", &c);
    deleta(s1,c);
}

void deleta(char *s1, char c)
{
    int x,j,y;
    for(x=0;s1[x] != '\0';x++)
    {
        if(s1[x] == c)
        {
            j=x;
            while(s1[j] == c)
            {
                j++;
            }
            for(y=x; s1[y] != '\0';y++,j++)
            {
                s1[y] = s1[j];
            }
            j++;
            s1[j]='\0';
        }
    }
    printf("%s\n", s1);
}
