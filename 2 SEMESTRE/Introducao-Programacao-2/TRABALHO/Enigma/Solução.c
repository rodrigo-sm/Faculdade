/* Programa que determina a quantidade de possibilidades que crib pode ser colocado na mensagem cifrada
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 * Arthur Silveira Chaves (Sistemas de Informação)
 * Nicholas Meirinho Perez (Sistemas de Informação)
 *
 * Disciplina: Introdução à Computação-II
 *
 * 18/09/2018
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/* A função recebe um inteiro index e dois vetores mensagem e crib
 * e verifica se crib pode ser colocada a partir da posiçao index na mensagem
 * Obs: nenhuma palavra da crib pode repetir na cifra */
bool eh_possivel(int index, const char * mensagem, const char * crib);

int main()
{
    bool r;
    char cifra[10001];
    scanf("%[A-Z]", cifra);
    int tcifra = strlen(cifra), s = 0,i;
    char crib[tcifra];
    scanf(" %[A-Z]", crib);
    // tf e a ultima posição a ser comparada do vetor cifra
    int tcrib = strlen(crib), tf = (tcifra - tcrib);
    for(i = 0; i <= tf; i++)
    {
        r = eh_possivel (i, cifra,crib);
        if(r) s++;
    }
    printf("%d\n",s);
    return 0;
}

bool eh_possivel(int index, const char * mensagem, const char * crib)
{
    int i,j;
    /* j e a posiçao do vetor mensagem que varia de [index..i-1] */
    for(i = 0,j = index; crib[i] != '\0'; i++,j++)
    {
        if (crib[i] == mensagem[j])
            return 0;
    }
    return 1;
}
