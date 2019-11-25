#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "tabelaNormal.h"

double f(double x){
	return exp(-pow(x / sqrt(2), 2)) / sqrt(2 * M_PI);
}

double regraDosTrapezio(double limiteInicial, double limiteFinal, int n) {

  double altura,
         soma = 0;

  int ponto;

  altura = fabs(limiteFinal-limiteInicial) / n;

  for(ponto = 1; ponto < n; ponto++)
    soma = soma + f(limiteInicial+ponto*altura);

  return (altura/2) * ( f(limiteInicial) + f(limiteFinal) + 2*soma );
}


double funcaoDistribuicaoNormal(float z, infoTabela info) {

    int intervalo = 2;

    double  limiteInicial = 0,
            limiteFinal = z,
            precisao = pow(0.1, info.precisao),
            integralVelha,
            integralAtual;

    integralAtual = regraDosTrapezio(limiteInicial,limiteFinal,intervalo++);

    do{
        integralVelha = integralAtual;
        integralAtual = regraDosTrapezio(limiteInicial,limiteFinal,intervalo++);
    } while(fabs(integralAtual - integralVelha) >= precisao);

    return integralAtual;
}

double executaFuncaoTipoTabela(float z, infoTabela info) {
    switch(info.tipoTabela) {
        case CUMULATIVA_APARTIR_DA_MEDIA:
            return funcaoDistribuicaoNormal(z, info);
        case CUMULATIVA:
            return funcaoDistribuicaoNormal(z, info) + 0.5;
        case CUMULATIVA_COMPLEMENTAR:
            return 0.5 - funcaoDistribuicaoNormal(z, info);
        default:
            return z;
    }
}

bool criaTabela (infoTabela * info) {

    info->qtd_linha = info->sigma*10;

    info->tabela = (double **) calloc (info->qtd_linha, sizeof(double *));

    if(info->tabela == NULL)
        return false;

    int linha;

    for(linha = 0; linha < info->qtd_linha; linha++) {
        info->tabela[linha] = (double*) calloc (QTD_COLUNA, sizeof(double));
        if (info->tabela[linha] == NULL) return false;
    }

    inicializaTabela(info);

    return true;
}

void inicializaTabela(infoTabela * info) {
    int linha, coluna;
    for(linha = 0; linha < info->qtd_linha; linha++) {
        printf("Gerando linha %d de %d da tabela\n", linha+1, info->qtd_linha);
        for(coluna = 0; coluna < QTD_COLUNA; coluna++)
            info->tabela[linha][coluna] = executaFuncaoTipoTabela(linha*0.1+coluna*0.01, *info);
    }
}

void apagaTabela (infoTabela info) {
    int  linha;
    if(info.tabela != NULL) {
        for(linha=0; linha<info.qtd_linha; linha++)
            free (info.tabela[linha]);
        free(info.tabela);
        info.tabela = (NULL);
    }
}

infoTabela criaInfoTabela(int tipoTabela, int precisao, int sigma) {
    infoTabela retorno;
    retorno.tipoTabela = tipoTabela;
    retorno.precisao = precisao;
    retorno.sigma = sigma;
    return retorno;
}

bool isTipoTabelaValido(int tipo) {
    return tipo == CUMULATIVA_APARTIR_DA_MEDIA || tipo == CUMULATIVA || tipo == CUMULATIVA_COMPLEMENTAR;
}

char * getNomeTipoTabela(int tipo) {
    switch(tipo) {
        case CUMULATIVA_APARTIR_DA_MEDIA:
            return "Cumulativa a partir da media - P(0 <= Z <= Zo)";
        case CUMULATIVA:
            return "Cumulativa P(Z <= Zo)";
        case CUMULATIVA_COMPLEMENTAR:
            return "Cumulativa complementar - P(Z >= Zo)";
        default:
            return "";
    }
}
