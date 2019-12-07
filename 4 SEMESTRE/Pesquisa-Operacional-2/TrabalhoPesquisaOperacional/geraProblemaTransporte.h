#ifndef GERAPROBLEMATRANSPORTE_H_INCLUDED
#define GERAPROBLEMATRANSPORTE_H_INCLUDED

#include "infoProblemaTransporte.h"
#include "hashmap.h"

void ajustaProblema(infoProblemaTransporte *, double, double);

void preencheOfertaDemandaNoTransbordoSeExistir(infoProblemaTransporte *, double);

void criaRotaFicticiaSePrecisar(infoProblemaTransporte *, double, double);

void criaDestinoFicticio(infoProblemaTransporte *, double);

void criaOrigemFicticia(infoProblemaTransporte *, double);

void geraProblema(hash_map, hash_map, infoProblemaTransporte *, double);

void criaRotasTransbordo(infoProblemaTransporte *);

void criaRotasProibidas(infoProblemaTransporte *, double);

#endif // GERAPROBLEMATRANSPORTE_H_INCLUDED
