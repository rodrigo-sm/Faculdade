#ifndef TABELACSV_H_INCLUDED
#define TABELACSV_H_INCLUDED

#include "tabelaNormal.h"

void imprimeTabelaCsv(FILE * , infoTabela);

void imprimeInfoTabelaCsv(FILE *, infoTabela);

void imprimeCabecalhoTabelaCsv(FILE *);

void imprimeLinhasCsv(FILE *, infoTabela);

void imprimeLinhaCsv(FILE *, int, infoTabela);

void imprimeIndiceLinhaCsv(FILE *, int);

void imprimeCelulasCsv(FILE *, int, infoTabela);

void imprimeCelulaCsv(FILE *, int, int, infoTabela);


#endif // TABELACSV_H_INCLUDED
