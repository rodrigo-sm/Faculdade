#ifndef INFOPROBLEMATRANSPORTE_H_INCLUDED
#define INFOPROBLEMATRANSPORTE_H_INCLUDED

#define INVALIDO -1
#define VAZIO 0

#define TXT 1
#define PROMPT 0

#define ORIGEM_INICIAL 0
#define DESTINO_INICIAL 0

typedef struct {
    char nome[50];
    double valor;
    int indice;
} infoNo;

typedef struct {
    double custo;
    infoNo origem;
    infoNo destino;
} rota;

typedef struct {
    double ** custos;
    double ** valores;
    double ** economia;
    double * divisaoCustoOrigem;
    double * divisaoCustoDestino;
    int quantidadeOrigem;
    int quantidadeDestino;
    int ultimaOrigemReal;
    int ultimoDestinoReal;
    int origemFicticia;
    int destinoFicticia;
    infoNo * origens;
    infoNo * destinos;
    double demandaTotal;
    double ofertaTotal;
    double custoTotal;
} infoProblemaTransporte;

rota criaRota(double, int, int);

double ** criaTabela (int, int);

double * criaVetor (int);

infoNo * criaNos (int);

double ** criaValoresVazios(infoProblemaTransporte);

#endif // INFOPROBLEMATRANSPORTE_H_INCLUDED
