#include "divisaoCustos.h"
#include "problemaTransporteHelper.h"
#include "infoProblemaTransporte.h"

void divisaoCusto(infoProblemaTransporte * solucao) {

    inicializaDivisaoCusto(solucao);

    solucao->divisaoCustoOrigem[0] = 0;

    calculaDivisaoCustoDestino(solucao, 0);

    preencheValoresInvalidosComVazio(solucao);
}

void inicializaDivisaoCusto(infoProblemaTransporte * solucao) {

    inicializaDivisaoCustoOrigem(solucao);

    inicializaDivisaoCustoDestino(solucao);
}

void inicializaDivisaoCustoOrigem(infoProblemaTransporte * solucao) {
    int origem;

    for(origem = 0; origem < solucao->quantidadeOrigem; origem++)
        solucao->divisaoCustoOrigem[origem] = INVALIDO;
}

void inicializaDivisaoCustoDestino(infoProblemaTransporte * solucao) {
    int destino;

    for(destino = 0; destino < solucao->quantidadeDestino; destino++)
        solucao->divisaoCustoDestino[destino] = INVALIDO;
}

void calculaDivisaoCustoDestino(infoProblemaTransporte * solucao, int origem) {
    int destino;

    for(destino = 0; destino < solucao->quantidadeDestino; destino++) {
        // O destino nao foi calculado e o valor da origem e destino e valido
        if(solucao->divisaoCustoDestino[destino] == INVALIDO && solucao->valores[origem][destino] > 0) {
            solucao->divisaoCustoDestino[destino] = solucao->custos[origem][destino] - solucao->divisaoCustoOrigem[origem];
            calculaDivisaoCustoOrigem(solucao, destino);
        }
    }
}

void calculaDivisaoCustoOrigem(infoProblemaTransporte * solucao, int destino) {
    int origem;

    for(origem = 0; origem < solucao->quantidadeOrigem; origem++) {
        // A origem nao foi calculado e o valor da origem e destino e valido
        if(solucao->divisaoCustoOrigem[origem] == INVALIDO && solucao->valores[origem][destino] > 0) {
            solucao->divisaoCustoOrigem[origem] = solucao->custos[origem][destino] - solucao->divisaoCustoDestino[destino];
            calculaDivisaoCustoDestino(solucao, origem);
        }
    }
}

void preencheValoresInvalidosComVazio(infoProblemaTransporte * solucao) {
    preencheOrigensInvalidosComVazio(solucao);
    preencheDestinosInvalidosComVazio(solucao);
}

void preencheOrigensInvalidosComVazio(infoProblemaTransporte * solucao) {
    int origem;

    for(origem = 0; origem < solucao->quantidadeOrigem; origem++)
        if(solucao->divisaoCustoOrigem[origem] == INVALIDO)
            solucao->divisaoCustoOrigem[origem] = VAZIO;
}

void preencheDestinosInvalidosComVazio(infoProblemaTransporte * solucao) {
    int destino;
    for(destino = 0; destino < solucao->quantidadeDestino; destino++)
        if(solucao->divisaoCustoDestino[destino] == INVALIDO)
            solucao->divisaoCustoDestino[destino] = VAZIO;
}
