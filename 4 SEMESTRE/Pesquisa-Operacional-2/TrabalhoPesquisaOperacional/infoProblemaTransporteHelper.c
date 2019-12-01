#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "infoProblemaTransporte.h"

rota criaRota(int custo, int origem, int destino) {
    rota retorno;
    retorno.custo = custo;
    retorno.origem.indice = origem;
    retorno.destino.indice = destino;
    return retorno;
}

int **criaTabela (int linhas, int colunas) {
  int **tabela;
  int   linhaAtual;

  // Aloca as linhas da tabela
  tabela = (int **) calloc (linhas, sizeof(int *));

  // Aloca as colunas da matriz
  for (linhaAtual = 0; linhaAtual < linhas; linhaAtual++ )
      tabela[linhaAtual] = (int*) calloc (colunas, sizeof(int));

  return (tabela);
}

int *criaVetor (int colunas) {
  int *vetor;

  // Aloca o vetor
  vetor = (int *) calloc (colunas+1, sizeof(int));

  return (vetor);
}

infoNo *criaNos (int colunas) {
  infoNo * vetor;

  // Aloca o vetor
  vetor = (infoNo *) calloc (colunas+1, sizeof(infoNo));

  return (vetor);
}

int ** criaValoresVazios(infoProblemaTransporte origem) {
    int ** retorno, origemAtual, destinoAtual;

    retorno = criaTabela(origem.quantidadeOrigem, origem.quantidadeDestino);

    for(origemAtual = 0; origemAtual < origem.quantidadeOrigem; origemAtual++)
        for(destinoAtual = 0; destinoAtual < origem.quantidadeDestino; destinoAtual++)
            retorno[origemAtual][destinoAtual] = VAZIO;

    return retorno;
}
