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
    int valor;
    int indice;
} infoNo;

typedef struct {
    int custo;
    infoNo origem;
    infoNo destino;
} rota;

typedef struct {
    int ** custos;
    int ** valores;
    int ** economia;
    int * divisaoCustoOrigem;
    int * divisaoCustoDestino;
    int quantidadeOrigem;
    int quantidadeDestino;
    int ultimaOrigemReal;
    int ultimoDestinoReal;
    int origemFicticia;
    int destinoFicticia;
    infoNo * origens;
    infoNo * destinos;
    int demandaTotal;
    int ofertaTotal;
    int custoTotal;
} infoProblemaTransporte;

rota criaRota(int, int, int);

int ** criaTabela (int, int);

int * criaVetor (int);

infoNo * criaNos (int);

int ** criaValoresVazios(infoProblemaTransporte);

#endif // INFOPROBLEMATRANSPORTE_H_INCLUDED
