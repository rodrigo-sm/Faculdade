#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "infoProblemaTransporte.h"

rota criaRota(double custo, int origem, int destino) {
    rota retorno;
    retorno.custo = custo;
    retorno.origem.indice = origem;
    retorno.destino.indice = destino;
    return retorno;
}

double **criaTabela (int linhas, int colunas) {
  double **tabela;
  int   linhaAtual;

  // Aloca as linhas da tabela
  tabela = (double **) calloc (linhas, sizeof(double *));

  // Aloca as colunas da matriz
  for (linhaAtual = 0; linhaAtual < linhas; linhaAtual++ )
      tabela[linhaAtual] = (double*) calloc (colunas, sizeof(double));

  return (tabela);
}

double *criaVetor (int colunas) {
  double *vetor;

  // Aloca o vetor
  vetor = (double *) calloc (colunas+1, sizeof(double));

  return (vetor);
}

infoNo *criaNos (int colunas) {
  infoNo * vetor;

  // Aloca o vetor
  vetor = (infoNo *) calloc (colunas+1, sizeof(infoNo));

  return (vetor);
}

double ** criaValoresVazios(infoProblemaTransporte origem) {
    double ** retorno;
    int origemAtual, destinoAtual;

    retorno = criaTabela(origem.quantidadeOrigem, origem.quantidadeDestino);

    for(origemAtual = 0; origemAtual < origem.quantidadeOrigem; origemAtual++)
        for(destinoAtual = 0; destinoAtual < origem.quantidadeDestino; destinoAtual++)
            retorno[origemAtual][destinoAtual] = VAZIO;

    return retorno;
}
