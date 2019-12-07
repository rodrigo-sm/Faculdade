
#include <stdio.h>

#include "problemaTransporteHelper.h"
#include "problemaTransporteInterface.h"
#include "infoProblemaTransporte.h"
#include "roteamento.h"
#include "divisaoCustos.h"
#include "analiseEconomica.h"
#include "cantoNoroeste.h"
#include "menorCusto.h"
#include "otimizacao.h"

void otimizacao(infoProblemaTransporte solucao) {
    int interacao = 1;

    solucao = encontraSolucaoInicial(solucao);

    executaEconomiaEDivisaoDeCustos(&solucao);

    rota maiorEconomia;
    maiorEconomia = getMaiorEconomiaPositivaMaiorQue0(solucao);

    while(maiorEconomia.custo > 0.0) {

        roteamento(&solucao, maiorEconomia);

        imprimeInteracao(interacao++, solucao);

        executaEconomiaEDivisaoDeCustos(&solucao);

        maiorEconomia = getMaiorEconomiaPositivaMaiorQue0(solucao);
    }
    printf("\nA otimizacao terminou.\n");
}

infoProblemaTransporte encontraSolucaoInicial(infoProblemaTransporte problema) {
    infoProblemaTransporte cantoNoroeste, menorCusto;

    cantoNoroeste = achaCantoNoroeste(problema);

    menorCusto = achaMenorCusto(problema);

    return menorCusto.custoTotal < cantoNoroeste.custoTotal ? menorCusto : cantoNoroeste;
}


void executaEconomiaEDivisaoDeCustos(infoProblemaTransporte * solucao) {
    divisaoCusto(solucao);
    analiseEconomica(solucao);
}
