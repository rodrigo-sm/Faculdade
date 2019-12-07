#ifndef MENORCUSTO_H_INCLUDED
#define MENORCUSTO_H_INCLUDED

#include "infoProblemaTransporte.h"

infoProblemaTransporte achaMenorCusto(infoProblemaTransporte);

double ** calculaSolucaoMenorCusto(infoProblemaTransporte);

void calculaSolucaComRotasReais(infoProblemaTransporte *);

void calculaSolucaoComRotasFicticias(infoProblemaTransporte *);

void supreOfertaComDestinoFicticio(infoProblemaTransporte *);

void supreDemandaComOrigemFicticio(infoProblemaTransporte *);

#endif // MENORCUSTO_H_INCLUDED
