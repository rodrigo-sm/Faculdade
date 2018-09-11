#include <stdio.h>
#include <ctype.h>

int main()
{
    int vq[5] = {0};
    char nome[81],vogal[5]="aeiou";
    int x,y;
    scanf("%80[^\n]", nome);
    for(x=0 ; nome[x] != '\0' ; x++)
    {
        nome[x] = tolower(nome[x]);
        switch(nome[x])
        {
            case 'a': vq[0]++; break;
            case 'e': vq[1]++; break;
            case 'i': vq[2]++; break;
            case 'o': vq[3]++; break;
            case 'u': vq[4]++; break;
        }
    }
    for(x = 0 ;x <  5; x++)
    {
        printf("%c ", vogal[x]);
        for(y = 0;y < vq[x]; y++)
            printf("*");
        printf("(%d)\n", vq[x]);
    }
    return 0;
}
