#include "infoProblemaTransporte.h"
#include "problemaTransporteHelper.h"
#include "menorCusto.h"
#include "rotasOrdenadas.h"
#include "problemaTransporteInterface.h"

infoProblemaTransporte achaMenorCusto(infoProblemaTransporte solucao) {
    infoProblemaTransporte problema;

    copiaProblema(&problema, solucao);

    solucao.valores = calculaSolucaoMenorCusto(problema);

    calculaCustoTotal(&solucao);

    imprimeMenorCusto(solucao);

    return solucao;
}

double ** calculaSolucaoMenorCusto(infoProblemaTransporte problema) {
    calculaSolucaComRotasReais(&problema);
    calculaSolucaoComRotasFicticias(&problema);
    return problema.valores;

}

void calculaSolucaComRotasReais(infoProblemaTransporte * problema) {
    int quantidadeDeRotasReais = problema->ultimaOrigemReal*problema->ultimoDestinoReal;

    rota rotasReaisOrdenado[quantidadeDeRotasReais];
    criaRotasReaisOrdenados(*problema, quantidadeDeRotasReais, rotasReaisOrdenado);

    int rota, origem, destino;

    for(rota = 0; rota < quantidadeDeRotasReais; rota++) {
        origem = rotasReaisOrdenado[rota].origem.indice;
        destino = rotasReaisOrdenado[rota].destino.indice;
        if(problema->origens[origem].valor < problema->destinos[destino].valor) {
            problema->valores[origem][destino] = problema->origens[origem].valor;
            problema->destinos[destino].valor -= problema->origens[origem].valor;
            problema->origens[origem].valor = VAZIO;
        }
        else {
            problema->valores[origem][destino] = problema->destinos[destino].valor;
            problema->origens[origem].valor -= problema->destinos[destino].valor;
            problema->destinos[destino].valor = VAZIO;
        }

    }

}

void calculaSolucaoComRotasFicticias(infoProblemaTransporte * problema) {
    if(problema->origemFicticia == INVALIDO && problema->destinoFicticia != INVALIDO)
        supreOfertaComDestinoFicticio(problema);
    else if(problema->origemFicticia != INVALIDO && problema->destinoFicticia == INVALIDO)
        supreDemandaComOrigemFicticio(problema);
}

void supreOfertaComDestinoFicticio(infoProblemaTransporte * problema) {
    int origemAtual;
    for(origemAtual = 0; origemAtual < problema->quantidadeOrigem; origemAtual++) {
        problema->valores[origemAtual][problema->destinoFicticia] = problema->origens[origemAtual].valor;
        problema->origens[origemAtual].valor = VAZIO;
    }
}

void supreDemandaComOrigemFicticio(infoProblemaTransporte * problema) {
    int destinoAtual;
    for(destinoAtual = 0; destinoAtual < problema->quantidadeDestino; destinoAtual++) {
        problema->valores[problema->origemFicticia][destinoAtual] = problema->destinos[destinoAtual].valor;
        problema->destinos[destinoAtual].valor = VAZIO;
    }
}
