/* 01.c
 *
 * Programa que recebe dois arquivos na função main e copia um arquivo de entrada para outro de saida
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Introdução a Computação-II
 *
 * 05/1/2018
 */
#include <stdio.h>

int main(int argc, char * argv[])
{
    FILE * in, * out;
	char ch;
	if (argc != 3) {
		fprintf(stderr, "Erro: uso incorreto!\nDigite: %s <origem> <destino>\n",
		        argv[0]);
		return 1;
	}
	if ((in = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Erro: nao foi possível abrir o arquivo %s!\n",
		        argv[1]);
		return 2;
	}
	if ((out = fopen(argv[2], "w")) == NULL) {
		fprintf(stderr, "Erro: nao foi possível criar o arquivo %s!\n",
		        argv[2]);
		fclose(in);
		return 3;
	}
	while((ch = fgetc(in)) != EOF)
        fputc(ch, out);
    fclose(in);
    fclose(out);
    printf("O arquivo %s foi copiado com sucesso para o arquivo %s\n", argv[1], argv[2]);
    return 0;
}
