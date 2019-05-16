/*
 O código de Cesar é uma das técnicas de criptografia mais simples e conhecidas.
É um tipo de substituição no qual cada letra do texto é substituída por outra,
que se apresenta n posições após ela no alfabeto. Por exemplo, com uma troca
de três posições a letra A seria substituída por D, B se tornaria E e assim
por diante. Escreva um programa que faça uso da função void cesar(char[], int
posicoes) . Entre com uma string, gere uma nova string e imprima uma string codificada.

Exemplo:

String: a ligeira raposa marrom saltou sobre o cachorro cansado

Nova String: d oljhlud udsrvd pduurp vdowrx vreuh r fdfkruur fdqvdgr
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cesar(char *str, int i);
int main()
{
    char frase[81];
    int i;
    scanf("%80[^\n]", frase);
    scanf("%d", &i);
    cesar(frase, i);
    return 0;
}

void cesar(char *str, int i)
{
        int y;
        for(y=0; str[y] != '\0'; y++)
        {
            if(str[y] != ' ')
            str[y] += i;
        }
        printf("%s\n", str);
}
