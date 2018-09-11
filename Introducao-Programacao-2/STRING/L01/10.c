#include <stdio.h>
#include <ctype.h>

int main()
{
    char s[51];
    int x;
    scanf("%50[^\n]", s);
    for(x=0; s[x] != '\0'; x+=2)
    {
        while(s[x] == ' ')
        {
            x++;
        }
        if(s[x]>='a' && s[x]<= 'z')
                    s[x] = s[x] - 32;
        while(s[x+1] == ' ')
        {
            x++;
        }
        if(s[x+1]>='A' && s[x+1]<= 'Z')
                    s[x+1] = s[x+1] + 32;
    }
    s[x+2] = '\0';
    printf("%s\n", s);
    return 0;
}
