#include "infoProblemaTransporte.h"
#include "problemaTransporteHelper.h"
#include "roteamento.h"

void roteamento(infoProblemaTransporte * solucao, rota k) {
    encontraSolucaoNovaRoteamento(solucao, k, encontraMaiorSomaK(solucao, k));
    calculaCustoTotal(solucao);
}

rota encontraMaiorSomaK(infoProblemaTransporte * solucao, rota k) {
    int origem, destino;

    rota retorno, rotaAtual;
    retorno.custo = INVALIDO;

    for(origem = 0; origem < solucao->quantidadeOrigem; origem++) {
        for(destino = 0; destino < solucao->quantidadeDestino; destino++) {
            rotaAtual = criaRota(solucao->valores[origem][destino], origem, destino);
            if(isDiferenteRota(k, rotaAtual) && isSomaK(solucao, k, rotaAtual) && rotaAtual.custo > retorno.custo) {
                retorno = rotaAtual;
            }
        }
    }
    return retorno;
}

void encontraSolucaoNovaRoteamento(infoProblemaTransporte * solucao, rota k, rota somaK) {
    rota menosK1, menosK2;

    menosK1 = criaRota(solucao->valores[somaK.origem.indice][k.destino.indice], somaK.origem.indice, k.destino.indice);
    menosK2 = criaRota(solucao->valores[k.origem.indice][somaK.destino.indice], k.origem.indice, somaK.destino.indice);

    k.custo = menosK1.custo < menosK2.custo ? menosK1.custo : menosK2.custo;

    solucao->valores[k.origem.indice][k.destino.indice] = k.custo;

    solucao->valores[somaK.origem.indice][somaK.destino.indice] += k.custo;

    solucao->valores[menosK1.origem.indice][menosK1.destino.indice] -= k.custo;
    solucao->valores[menosK2.origem.indice][menosK2.destino.indice] -= k.custo;
}

bool isSomaK(infoProblemaTransporte * solucao, rota k, rota soma) {
    return solucao->valores[k.origem.indice][soma.destino.indice] > 0 && solucao->valores[soma.origem.indice][k.destino.indice] > 0;
}

bool isDiferenteRota(rota r1, rota r2) {
    return r1.destino.indice != r2.destino.indice && r1.origem.indice != r2.origem.indice;
}
