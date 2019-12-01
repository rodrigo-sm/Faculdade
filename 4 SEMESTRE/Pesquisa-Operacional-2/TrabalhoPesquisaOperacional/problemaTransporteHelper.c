#include <stdio.h>
#include <stdlib.h>

#include "problemaTransporteHelper.h"
#include "infoProblemaTransporte.h"

void inicializaValores(infoProblemaTransporte * info) {
    int linha, coluna;

    for(linha = 0; linha < info->quantidadeOrigem; linha++)
        for(coluna = 0; coluna < info->quantidadeDestino; coluna++)
            info->valores[linha][coluna] = VAZIO;
}

void inicializaCustos(infoProblemaTransporte * entrada) {
    int linha, coluna;

    for(linha = 0; linha < entrada->quantidadeOrigem; linha++)
        for(coluna = 0; coluna < entrada->quantidadeDestino; coluna++)
            entrada->custos[linha][coluna] = INVALIDO;
}

void copiaProblema(infoProblemaTransporte * destino, infoProblemaTransporte origem) {
    *destino = origem;
    destino->origens = copiaOrigens(origem);
    destino->destinos = copiaDestinos(origem);
    destino->valores = criaValoresVazios(origem);
}

infoNo * copiaOrigens(infoProblemaTransporte origem) {
    infoNo * retorno;

    int origemAtual;

    retorno = criaNos(origem.quantidadeOrigem);

    for(origemAtual = 0; origemAtual < origem.quantidadeOrigem; origemAtual++)
        retorno[origemAtual] = origem.origens[origemAtual];

    return retorno;
}

infoNo * copiaDestinos(infoProblemaTransporte origem) {
    infoNo * retorno;

    int destinoAtual;

    retorno = criaNos(origem.quantidadeDestino);

    for(destinoAtual = 0; destinoAtual < origem.quantidadeDestino; destinoAtual++)
        retorno[destinoAtual] = origem.destinos[destinoAtual];

    return retorno;
}

void calculaCustoTotal(infoProblemaTransporte * info) {
    int origem, destino;

    info->custoTotal = 0;

    for(origem = 0; origem < info->quantidadeOrigem; origem++)
        for(destino = 0; destino < info->quantidadeDestino; destino++)
            info->custoTotal += info->valores[origem][destino] * info->custos[origem][destino];
}
