#ifndef ROTEAMENTO_H_INCLUDED
#define ROTEAMENTO_H_INCLUDED

#include <stdbool.h>

#include "infoProblemaTransporte.h"

void roteamento(infoProblemaTransporte *, rota);

rota encontraMaiorSomaK(infoProblemaTransporte *, rota);

void encontraSolucaoNovaRoteamento(infoProblemaTransporte *, rota, rota);

bool isSomaK(infoProblemaTransporte *, rota, rota);

bool isDiferenteRota(rota, rota);

#endif // ROTEAMENTO_H_INCLUDED
