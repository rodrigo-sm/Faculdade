#ifndef PROBLEMATRANSPORTEINTERFACE_H_INCLUDED
#define PROBLEMATRANSPORTEINTERFACE_H_INCLUDED

#include "infoProblemaTransporte.h"

void imprimeCustos(infoProblemaTransporte);

void imprimeInteracao(int interacao, infoProblemaTransporte);

void imprimeCustoInteracao(infoProblemaTransporte);

void imprimeMenorCusto(infoProblemaTransporte);

void imprimeCantoNoroeste(infoProblemaTransporte);

void imprimeSolucaoInicial(infoProblemaTransporte);

void imprimeTabela(infoProblemaTransporte, int **);

void imprimeTracadoTabela(int, int);

int getTamanhoCelula(infoProblemaTransporte, int **);

void procuraMaiorTamanhoEmOrigens(int * maiorTamanho, infoProblemaTransporte dados);

void procuraMaiorTamanhoEmDestinos(int * maiorTamanho, infoProblemaTransporte dados);

void procuraMaiorTamanhoNaTabela(int * maiorTamanho, infoProblemaTransporte dados, int ** tabela);

int determinaQuantidadeDeCasasDecimais(int);

void imprimeTracadoTabela(int, int);

void imprimeLinhaDestino(int, int);

void imprimeCabecalhoTabela(infoProblemaTransporte, int);

void imprimeDestinosTabela (infoProblemaTransporte, int);

void imprimeConteudoTabela(infoProblemaTransporte, int **, int, int);

void imprimeLinhaConteudoTabela(infoProblemaTransporte, int **, int, int, int);

void imprimeNomeOrigem(int, char *);

void imprimeValoresLinhaTabela(infoProblemaTransporte, int **, int, int);

void imprimeOfertaOrigem(int, int);

void imprimeDemandaTabela(infoProblemaTransporte, int);

#endif // PROBLEMATRANSPORTEINTERFACE_H_INCLUDED
