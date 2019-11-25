#include <stdio.h>
#include <stdlib.h>

#include "tabelaNormal.h"
#include "tabelaFormatada.h"

void imprimeTabela(FILE * saida, infoTabela info) {
    int ultimaLinha = info.sigma-1;
    int tamanhoIndiceLinha = determinaQuantidadeDeCasasDecimais(ultimaLinha)+2;
    int tamanhoCelula = tamanhoIndiceLinha+2;

    imprimeInfoTabela(saida, info);

    imprimeLinhaTracada(saida, tamanhoCelula, info);

    imprimeCabecalhoTabela(saida, info, tamanhoIndiceLinha);

    imprimeLinhaTracada(saida, tamanhoCelula, info);

    imprimeLinhas(saida, tamanhoIndiceLinha, info);

    imprimeLinhaTracada(saida, tamanhoCelula, info);
}

void imprimeInfoTabela(FILE * saida, infoTabela info) {
    fprintf(saida, "+==========================================================================+\n");
    fprintf(saida, "| Tabela Normal Padronizada %-46s |\n", getNomeTipoTabela(info.tipoTabela));
    fprintf(saida, "+==========================================================================+\n");
    fprintf(saida, "| Sigma    = %-62d|\n", info.sigma);
    fprintf(saida, "| Precisao = %-62d|\n", info.precisao);
    fprintf(saida, "+==========================================================================+\n");
}

void imprimeLinhaTracada(FILE * saida, int tamanhoCelula, infoTabela info) {
    imprimeTracadoIndiceLinha(saida, tamanhoCelula);

    imprimeTracadoLinha(saida, info);

    fprintf(saida, "\n");
}

void imprimeTracadoIndiceLinha(FILE * saida, int tamanhoIndice) {
    fprintf(saida, "+");
    while(tamanhoIndice--)
        fprintf(saida, "-");
    fprintf(saida, "+");
}

void imprimeTracadoLinha(FILE * saida, infoTabela info) {
    int celula;
    for(celula = 0; celula < QTD_COLUNA; celula++)
        imprimeTracadoCelula(saida, info.precisao+4);
}

void imprimeTracadoCelula(FILE * saida, int tamanhoCelula) {
    while(tamanhoCelula--)
        fprintf(saida, "-");
    fprintf(saida, "+");
}

void imprimeCabecalhoTabela(FILE * saida, infoTabela info, int tamanhoIndice) {
    imprimeZ(saida, tamanhoIndice);

    imprimeIndicesColuna(saida, info);

    fprintf(saida, "\n");
}

void imprimeZ(FILE * saida, int tamanhoIndice) {
    fprintf(saida, "| %*s |", tamanhoIndice, "Z");
}

void imprimeIndicesColuna(FILE * saida, infoTabela info) {
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeIndiceColuna(saida, coluna, info);
}

void imprimeIndiceColuna(FILE * saida, int coluna, infoTabela info) {
    fprintf(saida, " %*d |", info.precisao+2, coluna);
}

void imprimeLinhas(FILE * saida, int tamanhoIndice, infoTabela info) {
    int linha;
    for(linha = 0; linha < info.qtd_linha; linha++)
        imprimeLinha(saida, linha, tamanhoIndice, info);
}

void imprimeLinha(FILE * saida, int linha, int tamanhoIndice, infoTabela info) {
    imprimeIndiceLinha(saida, tamanhoIndice, linha);

    imprimeCelulas(saida, linha, info);

    fprintf(saida, "\n");
}

void imprimeIndiceLinha(FILE * saida, int tamanhoIndice, int indice) {
    fprintf(saida, "| %*.1f |", tamanhoIndice, indice*0.1);
}

void imprimeCelulas(FILE * saida, int linha, infoTabela info) {
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeCelula(saida, linha, coluna, info);
}

void imprimeCelula(FILE * saida, int linha, int coluna, infoTabela info) {
    fprintf(saida, " %.*lf |", info.precisao, info.tabela[linha][coluna]);
}

int determinaQuantidadeDeCasasDecimais(int numero) {
    int casas = 1;
	while(numero > 9){
		casas++;
		numero /= 10;
	}
	return casas;
}
