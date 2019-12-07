#include "infoProblemaTransporte.h"
#include "cantoNoroeste.h"
#include "problemaTransporteHelper.h"
#include "problemaTransporteInterface.h"

infoProblemaTransporte achaCantoNoroeste(infoProblemaTransporte solucao) {
    infoProblemaTransporte problema;

    copiaProblema(&problema, solucao);

    solucao.valores = calculaSolucaoCantoNoroeste(problema, ORIGEM_INICIAL, DESTINO_INICIAL);

    calculaCustoTotal(&solucao);

    imprimeCantoNoroeste(solucao);

    return solucao;
}

double ** calculaSolucaoCantoNoroeste(infoProblemaTransporte solucao, int origemAtual, int destinoAtual) {

    if(origemAtual < solucao.quantidadeOrigem && destinoAtual < solucao.quantidadeDestino) {

        if(solucao.origens[origemAtual].valor < solucao.destinos[destinoAtual].valor) { // OFERTA < DEMANDA
            solucao.valores[origemAtual][destinoAtual] = solucao.origens[origemAtual].valor;
            solucao.destinos[destinoAtual].valor -= solucao.origens[origemAtual].valor;
            solucao.origens[origemAtual].valor = VAZIO;
            return calculaSolucaoCantoNoroeste(solucao, ++origemAtual, destinoAtual); // VAI PARA PROXIMA ORIGEM
        }
        else {                                                                          // OFERTA > DEMANDA
            solucao.valores[origemAtual][destinoAtual] = solucao.destinos[destinoAtual].valor;
            solucao.origens[origemAtual].valor -= solucao.destinos[destinoAtual].valor;
            solucao.destinos[destinoAtual].valor = VAZIO;
            return calculaSolucaoCantoNoroeste(solucao, origemAtual, ++destinoAtual); // VAI PARA O PROXIMO DESTINO
        }
    }
    return solucao.valores;
}
