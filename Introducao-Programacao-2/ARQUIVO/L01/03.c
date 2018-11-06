 /*
 * Programa que recebe uma string e um arquivo, e imprime todas as linhas do arquivo que contem a string
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Introdução a Computação-II
 *
 * 05/1/2018
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char * argv[])
{
    if(argc != 3) {
        fprintf(stderr, "Erro: Uso incorreto\nDigite: %s <string> <arquivo>\n", argv[0]);
        return 1;
    }
    FILE *p;
    if((p = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo %s\n", argv[2]);
        return 2;
    }
    char str[30];
    while(fscanf(p, "%[^\n]", str) > 0)
        if(strstr(str, argv[1]) != NULL)
            fprintf(stderr, "%s\n", str);
    fclose(p);
    return 0;
}
