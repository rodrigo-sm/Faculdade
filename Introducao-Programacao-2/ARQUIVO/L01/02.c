/* 02.c
 *
 * Programa que criptografa e descriptografa arquivo usando a cifra de cesar
 * para utilizar digite via linha de comando "<arquivo> <-c|-d> <chave>"
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
    if(argc != 4)
    {
        fprintf(stderr,"Erro: Uso incorreto\nDigite: %s <arquivo> <-c|-d> <chave>\n", argv[0]);
        return 1;
    }
    FILE *in, *out;
    char ch;
    int chave;
    if((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr,"Erro: Nao foi possivel abrir o arquivo %s\n", argv[1]);
        return 2;
    }
    chave = atoi(argv[3]);
    if(strcmp(argv[2], "-c") == 0)
    {
        if((out = fopen("criptografado.txt", "w")) == NULL)
        {
            fprintf(stderr,"Erro: Nao foi possivel criar o arquivo criptografado\n");
            fclose(in);
            return 3;
        }
        while((ch = fgetc(in)) != EOF)
            fputc(ch + chave, out);
        fprintf(stderr,"O arquivo %s foi criptografado com sucesso!\n", argv[1]);
    }
    else if(strcmp(argv[2], "-d") == 0)
    {
        if((out = fopen("descriptografado.txt", "w")) == NULL)
        {
            fprintf(stderr,"Erro: Nao foi possivel criar o arquivo descriptografado\n");
            fclose(in);
            return 4;
        }
        while((ch = fgetc(in)) != EOF)
            fputc(ch - chave, out);
        fprintf(stderr,"O arquivo %s foi descriptografado com sucesso!\n", argv[1]);
    }
    else
    {
        fprintf(stderr, "Erro: uso incorreto!\nDigite: %s <arquivo> <-c|-d> <chave>\n", argv[0]);
		fclose(in);
		return 5;
    }
    fclose(in);
    return 0;
}
