#ifndef TABELAFORMATADA_H_INCLUDED
#define TABELAFORMATADA_H_INCLUDED

#include "tabelaNormal.h"

void imprimeTabela(FILE *, infoTabela info);

void imprimeInfoTabela(FILE *, infoTabela);

void imprimeLinhaTracada(FILE *,int, infoTabela);
void imprimeTracadoLinha(FILE *,infoTabela);
void imprimeTracadoIndiceLinha(FILE *,int);
void imprimeTracadoCelula(FILE *,int);

void imprimeCabecalhoTabela(FILE *,infoTabela, int);
void imprimeZ(FILE *,int);
void imprimeIndicesColuna(FILE *,infoTabela);
void imprimeIndiceColuna(FILE *,int, infoTabela);

void imprimeLinhas(FILE *,int, infoTabela);
void imprimeLinha(FILE *,int, int, infoTabela);
void imprimeIndiceLinha(FILE *,int, int);
void imprimeCelulas(FILE *,int, infoTabela);
void imprimeCelula(FILE *, int, int, infoTabela);

int determinaQuantidadeDeCasasDecimais(int);
int calculaTamanhoIndiceLinha(int);

#endif // TABELAFORMATADA_H_INCLUDED
