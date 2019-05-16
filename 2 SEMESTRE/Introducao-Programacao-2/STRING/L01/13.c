/*
Verifica se as vogais sao lidas igualmente de trás para frente
https://www.urionlinejudge.com.br/judge/pt/problems/view/2242
*/

#include <stdio.h>

int main()
{
    char e[51],v[51];
    int x,y=0,r=1;
    scanf("%50[^\n]", e);
    for(x=0;e[x]!='\0';x++)
    {
        if(e[x] =='a'||e[x]=='e'||e[x]=='i'||e[x]=='o'||e[x]=='u')
        {
            v[y]=e[x];
            y++;
        }
    }
    for(x=0,y--;x<y;x++,y--)
    {
        if(v[x] != v[y])
        {
            r=0;
            break;
        }
    }
    if(r)
    {
        printf("S\n");
    }
    else
    {
        printf("N\n");
    }
    return 0;
}
