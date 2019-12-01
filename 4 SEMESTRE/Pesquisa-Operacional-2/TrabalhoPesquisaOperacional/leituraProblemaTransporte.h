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

int leRotasPrompt(infoProblemaTransporte *, hash_map, hash_map);

void gravaRotaFILE(FILE *, rota *);

bool leRotaFILE(FILE *, rota *);

rota leRotaPrompt();

void leOrigem(char *);

void leDestino(char *);

void transformaEmMaiusculo(char *);

int leCusto();

void leQuadroCustoUnitario(infoProblemaTransporte *);

int insereSeNaoExisteOrigem(infoProblemaTransporte *, char *);

int insereSeNaoExisteDestino(infoProblemaTransporte *, char *);

bool leUsuarioQuerMaisRotas();

int leOfertasPrompt(infoProblemaTransporte *);

int leOferta(infoNo *);

int leDemandasPrompt(infoProblemaTransporte *);

int leDemanda(infoNo *);

bool isOrigemTransbordo(infoProblemaTransporte *, infoNo);

bool isDestinoTransbordo(infoProblemaTransporte *, infoNo);

#endif // LEITURAPROBLEMATRANSPORTE_H_INCLUDED
