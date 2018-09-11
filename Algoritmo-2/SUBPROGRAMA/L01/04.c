/*
 Crie uma função que retira todas os caracteres repetidos de uma string.
*/

#include <stdio.h>

void retira(char * s1);

int main()
{
    char s1[81];
    scanf(" %80[^\n]", s1);
    retira(s1);
    return 0;
}

void retira(char * s1)
{
    int x,j,y;
    for(x=0; s1[x] != '\0'; x++)
    {
        j = x+1;
        if(s1[x] == s1[j])
        {
            while(s1[x] == s1[j])
            {
                j++;
            }
            for(y=x+1; s1[y] != '\0';y++,j++)
            {
                s1[y] = s1[j];
            }
            j++;
            s1[j]='\0';
        }
    }
    printf("%s\n", s1);

}
