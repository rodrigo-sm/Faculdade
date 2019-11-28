#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "tabelaNormal.h"

bool criaTabela (infoTabela * info) {

    info->qtd_linha = info->sigma*10;
    if(alocaTabela(info) == ERRO)
        return ERRO;
    inicializaTabela(info);
    return SUCESSO;
}

bool alocaTabela(infoTabela * info) {
    return alocaLinhas(info) && alocaColunas(info);
}

bool alocaLinhas(infoTabela * info) {
    info->tabela = (double **) calloc (info->qtd_linha, sizeof(double *));
    return info->tabela != NULL;
}

bool alocaColunas(infoTabela * info) {
    int linha;
    for(linha = 0; linha < info->qtd_linha; linha++)
        if(!alocaColuna(info, linha))
            return ERRO;
    return SUCESSO;
}

bool alocaColuna(infoTabela * info, int linha) {
    info->tabela[linha] = (double*) calloc (QTD_COLUNA, sizeof(double));
    return info->tabela[linha] != NULL;
}

void inicializaTabela(infoTabela * info) {
    int linha, coluna;
    for(linha = 0; linha < info->qtd_linha; linha++) {
        printf("Gerando linha %d de %d da tabela...\n", linha+1, info->qtd_linha);
        for(coluna = 0; coluna < QTD_COLUNA; coluna++)
            info->tabela[linha][coluna] = executaFuncaoTipoTabela(linha*0.1+coluna*0.01, *info);
    }
}

double executaFuncaoTipoTabela(float z, infoTabela info) {
    double retorno;

    switch(info.tipoTabela) {

        case CUMULATIVA_APARTIR_DA_MEDIA:
            retorno = distribuicaoNormal(z);
            break;

        case CUMULATIVA:
            retorno = distribuicaoNormal(z) + 0.5;
            break;

        case CUMULATIVA_COMPLEMENTAR:
            retorno = 0.5 - distribuicaoNormal(z);
            break;

        default:
            retorno = z;
    }

    return arredonda(retorno, info.qtdCasasDecimais);
}

double distribuicaoNormal(double var)
{
    long n = 10000;
    double a = 0;
    double b = var;
    double h = (b - a) / n;
    int k;


    long double result;


    long double res_even = 0, res_odd = 0;


    // Somatorio dos indices impares

    for (k = 1; k <= (n / 2); k++){
        res_odd += function(a + h *(2 * k - 1));
    }

    // Somatorio dos indices pares

    for (k = 1; k <= (n / 2 - 1); k++){
        res_even += function(a + h * (2 * k));
    }

    result = 4 * res_odd + 2 * res_even;
    result += function(a);
    result += function(b);


    return result * (h / 3);

}

double function(double x)
{
    return exp( pow( x / sqrt(2), 2) * (-1)) / sqrt(2 * M_PI);
    /* Simplificacao da funcao original resulta na equacao acima.
    */

}

double arredonda(double numero, double qtdCasasDecimais) {
    return round(pow(10,qtdCasasDecimais)*numero)/pow(10,qtdCasasDecimais);
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

infoTabela criaInfoTabela(int tipoTabela, int qtdCasasDecimais, int sigma) {
    infoTabela retorno;
    retorno.tipoTabela = tipoTabela;
    retorno.qtdCasasDecimais = qtdCasasDecimais;
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
