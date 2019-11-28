#include <stdio.h>
#include <stdlib.h>

#include "tabelaNormal.h"
#include "tabelaCsv.h"

void imprimeTabelaCsv(FILE * saida, infoTabela info) {
    imprimeInfoTabelaCsv(saida, info);
    imprimeCabecalhoTabelaCsv(saida);
    imprimeLinhasCsv(saida, info);
}

void imprimeInfoTabelaCsv(FILE * saida, infoTabela info) {
    fprintf(saida, "Tabela Normal Padronizada %s\n", getNomeTipoTabela(info.tipoTabela));
    fprintf(saida, "Sigma;%d\n", info.sigma);
    fprintf(saida, "Casas decimais;%d\n\n", info.qtdCasasDecimais);
}

void imprimeCabecalhoTabelaCsv(FILE * saida) {
    fprintf(saida, "z;0;1;2;3;4;5;6;7;8;9\n");
}

void imprimeLinhasCsv(FILE * saida, infoTabela info) {
    int linha;
    for(linha = 0; linha < info.qtd_linha; linha++)
        imprimeLinhaCsv(saida, linha, info);
}

void imprimeLinhaCsv(FILE * saida, int linha, infoTabela info) {
    imprimeIndiceLinhaCsv(saida, linha);
    imprimeCelulasCsv(saida, linha, info);
    fprintf(saida, "\n");
}

void imprimeIndiceLinhaCsv(FILE * saida, int linha) {
    fprintf(saida, "%.1f", linha*0.1);
}

void imprimeCelulasCsv(FILE * saida, int linha, infoTabela info) {
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeCelulaCsv(saida, linha, coluna, info);
}

void imprimeCelulaCsv(FILE * saida, int linha, int coluna, infoTabela info) {
    fprintf(saida, ";%.*lf", info.qtdCasasDecimais, info.tabela[linha][coluna]);
}
