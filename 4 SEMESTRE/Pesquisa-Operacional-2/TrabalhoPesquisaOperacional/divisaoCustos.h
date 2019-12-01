#ifndef DIVISAOCUSTOS_H_INCLUDED
#define DIVISAOCUSTOS_H_INCLUDED

#include "infoProblemaTransporte.h"

void divisaoCusto(infoProblemaTransporte *);

void inicializaDivisaoCusto(infoProblemaTransporte *);

void inicializaDivisaoCustoOrigem(infoProblemaTransporte *);

void inicializaDivisaoCustoDestino(infoProblemaTransporte *);

void calculaDivisaoCustoDestino(infoProblemaTransporte *, int);

void calculaDivisaoCustoOrigem(infoProblemaTransporte *, int);

void preencheValoresInvalidosComVazio(infoProblemaTransporte *);

void preencheOrigensInvalidosComVazio(infoProblemaTransporte *);

void preencheDestinosInvalidosComVazio(infoProblemaTransporte *);

#endif // DIVISAOCUSTOS_H_INCLUDED
