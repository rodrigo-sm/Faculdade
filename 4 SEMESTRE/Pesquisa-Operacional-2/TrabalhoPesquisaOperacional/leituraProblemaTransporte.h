#ifndef LEITURAPROBLEMATRANSPORTE_H_INCLUDED
#define LEITURAPROBLEMATRANSPORTE_H_INCLUDED

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "infoProblemaTransporte.h"
#include "hashmap.h"

#define ROTAFILE "rotas.dat"

infoProblemaTransporte leInfoProblemaTransporte();

infoProblemaTransporte leEntradaPrompt();

double leRotasPrompt(infoProblemaTransporte *, hash_map, hash_map);

void gravaRotaFILE(FILE *, rota *);

bool leRotaFILE(FILE *, rota *);

rota leRotaPrompt();

void leOrigem(char *);

void leDestino(char *);

void transformaEmMaiusculo(char *);

double leCusto();

void leQuadroCustoUnitario(infoProblemaTransporte *);

int insereSeNaoExisteOrigem(infoProblemaTransporte *, char *);

int insereSeNaoExisteDestino(infoProblemaTransporte *, char *);

bool leUsuarioQuerMaisRotas();

double leOfertasPrompt(infoProblemaTransporte *);

double leOferta(infoNo *);

double leDemandasPrompt(infoProblemaTransporte *);

double leDemanda(infoNo *);

bool isOrigemTransbordo(infoProblemaTransporte *, infoNo);

bool isDestinoTransbordo(infoProblemaTransporte *, infoNo);

#endif // LEITURAPROBLEMATRANSPORTE_H_INCLUDED
