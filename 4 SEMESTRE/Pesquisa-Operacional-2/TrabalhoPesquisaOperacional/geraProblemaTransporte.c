#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "infoProblemaTransporte.h"
#include "geraProblemaTransporte.h"
#include "leituraProblemaTransporte.h"
#include "problemaTransporteHelper.h"
#include "hashmap.h"

void ajustaProblema(infoProblemaTransporte * problema, int ofertaTotal, int demandaTotal) {

    preencheOfertaDemandaNoTransbordoSeExistir(problema, ofertaTotal > demandaTotal ? ofertaTotal : demandaTotal);

    criaRotaFicticiaSePrecisar(problema, demandaTotal, ofertaTotal);

}

void preencheOfertaDemandaNoTransbordoSeExistir(infoProblemaTransporte * entrada, int valor) {
    int origem, destino;

    for(origem = 0; origem < entrada->quantidadeOrigem; origem++)
        for(destino = 0; destino < entrada->quantidadeDestino; destino++)
            if(strcmp(entrada->origens[origem].nome, entrada->destinos[destino].nome) == 0) { // E TRANSBORDO
                entrada->origens[origem].valor = valor;
                entrada->destinos[destino].valor = valor;
            }
}

void criaRotaFicticiaSePrecisar(infoProblemaTransporte * entrada, int demandaTotal, int ofertaTotal) {
    if(demandaTotal < ofertaTotal)
        criaDestinoFicticio(entrada, ofertaTotal-demandaTotal);
    else if(demandaTotal > ofertaTotal)
        criaOrigemFicticia(entrada, demandaTotal-ofertaTotal);

}

void criaDestinoFicticio(infoProblemaTransporte * entrada, int demanda) {
    int origem;

    entrada->destinoFicticia = entrada->quantidadeDestino;

    for(origem = 0; origem < entrada->ultimaOrigemReal; origem++) // Preenche as rotas do destino ficticio com VAZIO
        entrada->custos[origem][entrada->destinoFicticia] = VAZIO;

    entrada->destinos[entrada->destinoFicticia].valor = demanda;

    strcpy(entrada->destinos[entrada->destinoFicticia].nome, "OUTROS");

    entrada->quantidadeDestino++;
}

void criaOrigemFicticia(infoProblemaTransporte * entrada, int oferta) {
    int destino;

    entrada->origemFicticia = entrada->quantidadeOrigem;

    for(destino = 0; destino < entrada->ultimoDestinoReal; destino++) // Preenche as rotas do origem ficticia com VAZIO
        entrada->custos[entrada->origemFicticia][destino] = VAZIO;

    entrada->origens[entrada->origemFicticia].valor = oferta;

    strcpy(entrada->origens[entrada->origemFicticia].nome, "OUTROS");

    entrada->quantidadeOrigem++;
}

void geraProblema(hash_map origens, hash_map destinos, infoProblemaTransporte * entrada, int custoProibitivo) {
    entrada->quantidadeOrigem = map_size(origens);
    entrada->quantidadeDestino = map_size(destinos);

    int quantidadeMaximaOrigem = entrada->quantidadeOrigem+ 1;
    int quantidadeMaximaDestino = entrada->quantidadeDestino+ 1;

    entrada->destinoFicticia = INVALIDO;
    entrada->origemFicticia = INVALIDO;

    entrada->custos = criaTabela(quantidadeMaximaOrigem, quantidadeMaximaDestino);

    entrada->valores = criaTabela(quantidadeMaximaOrigem, quantidadeMaximaDestino);

    entrada->origens = criaNos(quantidadeMaximaOrigem);
    entrada->destinos = criaNos(quantidadeMaximaDestino);

    entrada->divisaoCustoDestino = criaVetor(quantidadeMaximaDestino);
    entrada->divisaoCustoOrigem = criaVetor(quantidadeMaximaOrigem);

    entrada->economia = criaTabela(quantidadeMaximaOrigem, quantidadeMaximaDestino);

    inicializaCustos(entrada);

    inicializaValores(entrada);

    leQuadroCustoUnitario(entrada);

    criaRotasTransbordo(entrada);

    criaRotasProibidas(entrada, custoProibitivo);
}

void criaRotasTransbordo(infoProblemaTransporte * entrada) {
    int origem, destino;

    for(origem = 0; origem < entrada->ultimaOrigemReal; origem++)
        for(destino = 0; destino < entrada->ultimoDestinoReal; destino++)
            if(strcmp(entrada->origens[origem].nome, entrada->destinos[destino].nome) == 0) // E TRANSBORDO
                entrada->custos[origem][destino] = VAZIO;
}

void criaRotasProibidas(infoProblemaTransporte * entrada, int custoProibitivo) {
    int origem, destino;

    for(origem = 0; origem < entrada->ultimaOrigemReal; origem++)
        for(destino = 0; destino < entrada->ultimoDestinoReal; destino++)
            if(entrada->custos[origem][destino] == INVALIDO) // ROTA INEXISTENTE
                entrada->custos[origem][destino] = custoProibitivo;
}
