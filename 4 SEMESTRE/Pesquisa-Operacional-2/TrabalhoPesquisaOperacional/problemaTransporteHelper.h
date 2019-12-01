#ifndef PROBLEMATRANSPORTEHELPER_H_INCLUDED
#define PROBLEMATRANSPORTEHELPER_H_INCLUDED

#include "infoProblemaTransporte.h"

void inicializaValores(infoProblemaTransporte *);

void inicializaCustos(infoProblemaTransporte *);

void copiaProblema(infoProblemaTransporte *, infoProblemaTransporte);

infoNo * copiaOrigens(infoProblemaTransporte);

infoNo * copiaDestinos(infoProblemaTransporte);

void calculaCustoTotal(infoProblemaTransporte *);

#endif // PROBLEMATRANSPORTEHELPER_H_INCLUDED
