#ifndef PROBLEMATRANSPORTEINTERFACE_H_INCLUDED
#define PROBLEMATRANSPORTEINTERFACE_H_INCLUDED

#include "infoProblemaTransporte.h"

void imprimeCustos(infoProblemaTransporte);

void imprimeInteracao(int interacao, infoProblemaTransporte);

void imprimeCustoInteracao(infoProblemaTransporte);

void imprimeMenorCusto(infoProblemaTransporte);

void imprimeCantoNoroeste(infoProblemaTransporte);

void imprimeSolucaoInicial(infoProblemaTransporte);

void imprimeTabela(infoProblemaTransporte, double **);

void imprimeTracadoTabela(int, int);

int getTamanhoMaiorElemento(infoProblemaTransporte, double **);

void procuraMaiorTamanhoEmOrigens(int * maiorTamanho, infoProblemaTransporte dados);

void procuraMaiorTamanhoEmDestinos(int * maiorTamanho, infoProblemaTransporte dados);

void procuraMaiorTamanhoNaTabela(int * maiorTamanho, infoProblemaTransporte dados, double ** tabela);

int determinaQuantidadeDeCasasDecimais(double);

void imprimeTracadoTabela(int, int);

void imprimeLinhaDestino(int, int);

void imprimeCabecalhoTabela(infoProblemaTransporte, int);

void imprimeDestinosTabela (infoProblemaTransporte, int);

void imprimeConteudoTabela(infoProblemaTransporte, double **, int, int);

void imprimeLinhaConteudoTabela(infoProblemaTransporte, double **, int, int, int);

void imprimeNomeOrigem(int, char *);

void imprimeValoresLinhaTabela(infoProblemaTransporte, double **, int, int);

void imprimeOfertaOrigem(int, double);

void imprimeDemandaTabela(infoProblemaTransporte, int);

#endif // PROBLEMATRANSPORTEINTERFACE_H_INCLUDED
