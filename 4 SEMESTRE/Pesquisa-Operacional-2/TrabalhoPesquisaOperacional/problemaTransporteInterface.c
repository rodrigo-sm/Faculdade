#include <stdio.h>
#include <string.h>

#include "problemaTransporteInterface.h"
#include "infoProblemaTransporte.h"

void imprimeCustos(infoProblemaTransporte dados) {
    printf("\nQuadro de Custos Unitarios\n");
    imprimeTabela(dados, dados.custos);
}

void imprimeInteracao(int interacao, infoProblemaTransporte solucao) {
    printf("\nInteracao %d\n", interacao);
    imprimeCustoInteracao(solucao);
}

void imprimeCustoInteracao(infoProblemaTransporte solucao) {
    imprimeTabela(solucao, solucao.valores);
    printf("Custo: %.2lf\n", solucao.custoTotal);
}

void imprimeMenorCusto(infoProblemaTransporte solucao) {
    printf("\nSolucao Inicial Menor Custo\n");
    imprimeSolucaoInicial(solucao);
}

void imprimeCantoNoroeste(infoProblemaTransporte solucao) {
    printf("\nSolucao Inicial Canto Noroeste\n");
    imprimeSolucaoInicial(solucao);
}

void imprimeSolucaoInicial(infoProblemaTransporte solucao) {
    imprimeTabela(solucao, solucao.valores);
    printf("Custo Inicial: %.2lf\n", solucao.custoTotal);
}

void imprimeTabela(infoProblemaTransporte dados, double ** tabela) {
    int quantidadeColuna = dados.quantidadeDestino+2,
        tamanhoMaiorElemento = getTamanhoMaiorElemento(dados, tabela);
    int tamanhoCelula = tamanhoMaiorElemento+2;

    imprimeTracadoTabela(tamanhoCelula, quantidadeColuna);
    imprimeLinhaDestino(quantidadeColuna, tamanhoMaiorElemento);
    imprimeTracadoTabela(tamanhoCelula, quantidadeColuna);
    imprimeCabecalhoTabela(dados, tamanhoMaiorElemento);
    imprimeTracadoTabela(tamanhoCelula, quantidadeColuna);
    imprimeConteudoTabela(dados, tabela, tamanhoMaiorElemento, quantidadeColuna);
    imprimeDemandaTabela(dados, tamanhoMaiorElemento);
    imprimeTracadoTabela(tamanhoCelula, quantidadeColuna);
}

int getTamanhoMaiorElemento(infoProblemaTransporte dados, double ** tabela) {
    int maiorTamanho = strlen("DESTINO");

    procuraMaiorTamanhoEmOrigens(&maiorTamanho, dados);
    procuraMaiorTamanhoEmDestinos(&maiorTamanho, dados);
    procuraMaiorTamanhoNaTabela(&maiorTamanho, dados, tabela);

    return maiorTamanho;
}

void procuraMaiorTamanhoEmOrigens(int * maiorTamanho, infoProblemaTransporte dados) {
    int origemAtual, tamanhoAtual;

    for(origemAtual = 0; origemAtual < dados.quantidadeOrigem; origemAtual++) {
        tamanhoAtual = strlen(dados.origens[origemAtual].nome);
        if(tamanhoAtual > *maiorTamanho)
            *maiorTamanho = tamanhoAtual;
    }
}

void procuraMaiorTamanhoEmDestinos(int * maiorTamanho, infoProblemaTransporte dados) {
    int destinoAtual, tamanhoAtual;

    for(destinoAtual = 0; destinoAtual < dados.quantidadeDestino; destinoAtual++) {
        tamanhoAtual = strlen(dados.destinos[destinoAtual].nome);
        if(tamanhoAtual > *maiorTamanho)
            *maiorTamanho = tamanhoAtual;
    }
}

void procuraMaiorTamanhoNaTabela(int * maiorTamanho, infoProblemaTransporte dados, double ** tabela){
    int origemAtual, destinoAtual, tamanhoAtual;

    for(origemAtual = 0; origemAtual < dados.quantidadeOrigem; origemAtual++) {
        for(destinoAtual = 0; destinoAtual < dados.quantidadeDestino; destinoAtual++) {
            tamanhoAtual = determinaQuantidadeDeCasasDecimais(tabela[origemAtual][destinoAtual]);
            if(tamanhoAtual > *maiorTamanho)
                *maiorTamanho = tamanhoAtual;
        }
    }
}

int determinaQuantidadeDeCasasDecimais(double numero) {
    int casas = 1;
	while(numero > 0.09){
		casas++;
		numero /= 10;
	}
	return casas;
}

void imprimeTracadoTabela(int tamanhoCelula, int quantidadeDeColunas) {
    int coluna, indice;

    for(coluna = 0, indice = tamanhoCelula; coluna < quantidadeDeColunas; coluna++, indice = tamanhoCelula) {
        printf("+");
        while(indice--)
            printf("-");
    }
    printf("+\n");
}

void imprimeLinhaDestino(int quantidadeDeColuna, int tamanhoCelula) {
    int meio = quantidadeDeColuna / 2, destinoAtual;

    for(destinoAtual = 0; destinoAtual < quantidadeDeColuna; destinoAtual++)
        if(destinoAtual == meio)
            printf("| %*s ", tamanhoCelula, "DESTINO");
        else
            printf("| %*s ", tamanhoCelula, " ");
    printf("|\n");
}

void imprimeCabecalhoTabela(infoProblemaTransporte dados, int tamanhoCelula) {
    printf("| %*s ", tamanhoCelula, "ORIGEM");
    imprimeDestinosTabela(dados, tamanhoCelula);
    printf("| %*s |\n", tamanhoCelula, "OFERTA");
}

void imprimeDestinosTabela (infoProblemaTransporte dados, int tamanhoCelula) {
    int destinoAtual;

    for(destinoAtual = 0; destinoAtual < dados.quantidadeDestino; destinoAtual++)
        printf("| %*s ", tamanhoCelula, dados.destinos[destinoAtual].nome);
}

void imprimeConteudoTabela(infoProblemaTransporte dados, double ** tabela, int tamanhoCelula, int quantidadeColuna) {
    int origemAtual;
    for(origemAtual = 0; origemAtual < dados.quantidadeOrigem; origemAtual++)
        imprimeLinhaConteudoTabela(dados, tabela, tamanhoCelula, origemAtual, quantidadeColuna);
}

void imprimeLinhaConteudoTabela(infoProblemaTransporte dados, double ** tabela, int tamanhoCelula, int origemAtual, int quantidadeColuna) {
    imprimeNomeOrigem(tamanhoCelula, dados.origens[origemAtual].nome);

    imprimeValoresLinhaTabela(dados, tabela, tamanhoCelula, origemAtual);

    imprimeOfertaOrigem(tamanhoCelula, dados.origens[origemAtual].valor);

    imprimeTracadoTabela(tamanhoCelula+2, quantidadeColuna);
}

void imprimeNomeOrigem(int tamanhoCelula, char * origem) {
    printf("| %*s ", tamanhoCelula, origem);
}

void imprimeValoresLinhaTabela(infoProblemaTransporte dados, double ** tabela, int tamanhoCelula, int origemAtual) {
    int destinoAtual;
    for(destinoAtual = 0; destinoAtual < dados.quantidadeDestino; destinoAtual++)
            printf("| %*.2lf ", tamanhoCelula, tabela[origemAtual][destinoAtual]);
}

void imprimeOfertaOrigem(int tamanhoCelula, double oferta) {
    printf("| %*.2lf |\n", tamanhoCelula, oferta);
}

void imprimeDemandaTabela(infoProblemaTransporte dados, int tamanhoCelula) {
    printf("| %*s ", tamanhoCelula, "DEMANDA");

    int destinoAtual;
    for(destinoAtual = 0; destinoAtual < dados.quantidadeDestino; destinoAtual++)
        printf("| %*.2lf ", tamanhoCelula, dados.destinos[destinoAtual].valor);

    printf("| %*s |\n", tamanhoCelula, " ");
}
