#ifndef GERAPROBLEMATRANSPORTE_H_INCLUDED
#define GERAPROBLEMATRANSPORTE_H_INCLUDED

#include "infoProblemaTransporte.h"
#include "hashmap.h"

void ajustaProblema(infoProblemaTransporte *, int, int);

void preencheOfertaDemandaNoTransbordoSeExistir(infoProblemaTransporte *, int);

void criaRotaFicticiaSePrecisar(infoProblemaTransporte *, int, int);

void criaDestinoFicticio(infoProblemaTransporte *, int);

void criaOrigemFicticia(infoProblemaTransporte *, int);

void geraProblema(hash_map, hash_map, infoProblemaTransporte *, int);

void criaRotasTransbordo(infoProblemaTransporte *);

void criaRotasProibidas(infoProblemaTransporte *, int);

void ajustaNomeTransbordo(infoProblemaTransporte *, int, int);

#endif // GERAPROBLEMATRANSPORTE_H_INCLUDED
