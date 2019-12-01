#ifndef OTIMIZACAO_H_INCLUDED
#define OTIMIZACAO_H_INCLUDED

#include "infoProblemaTransporte.h"

void otimizacao(infoProblemaTransporte);

infoProblemaTransporte encontraSolucaoInicial(infoProblemaTransporte);


void executaEconomiaEDivisaoDeCustos(infoProblemaTransporte *);

#endif // OTIMIZACAO_H_INCLUDED
