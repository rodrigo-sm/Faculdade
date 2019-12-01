#include "analiseEconomica.h"
#include "infoProblemaTransporte.h"
#include "problemaTransporteHelper.h"

rota getMaiorEconomiaPositivaMaiorQue0(infoProblemaTransporte solucao) {
    int origemAtual, destinoAtual;

    rota maior;
    maior.custo = 0;

    for(origemAtual = 0; origemAtual < solucao.quantidadeOrigem; origemAtual++)
        for(destinoAtual = 0; destinoAtual < solucao.quantidadeDestino; destinoAtual++)
            if(maior.custo < solucao.economia[origemAtual][destinoAtual])
                maior = criaRota(solucao.economia[origemAtual][destinoAtual], origemAtual, destinoAtual);

    return maior;
}

void analiseEconomica(infoProblemaTransporte * solucao) {
    int origem, destino;

    for(origem = 0; origem < solucao->quantidadeOrigem; origem++)
        for(destino = 0; destino < solucao->quantidadeDestino; destino++)
            solucao->economia[origem][destino] = solucao->divisaoCustoOrigem[origem] + solucao->divisaoCustoDestino[destino] - solucao->custos[origem][destino];
}
