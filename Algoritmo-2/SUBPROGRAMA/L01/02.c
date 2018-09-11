/*
 Crie uma função que recebe uma string e transforma alguns dos caracteres em maiúsculos e outros em minúsculos.
Faça sorteios com a função rand() para gerar números aleatórios em C, que serão usados para escolher os índices
dos caracteres que serão alterados. Como parâmetro deve ser recebida a quantidade de sorteios que devem ser executados

void transforma(char [], int qtde_sorteios);
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void transforma(char *str, int qt);

int main()
{
    char nome[81];
    int q;
    scanf(" %80[^\n]", nome);
    scanf(" %d", &q);
    transforma(nome, q);
    return 0;
}


void transforma(char *str, int qt)
{
    int y = strlen(str),x;
    srand( (unsigned)time(NULL) );
    while(qt--)
    {
        int r = rand()%(y+1),a = rand()%2;
        if(a)
        {
           str[r] = toupper(str[r]);
        }
        else
            str[r] = tolower(str[r]);
    }
    printf("%s\n", str);
}
