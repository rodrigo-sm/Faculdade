#include <stdio.h>
#include <stdlib.h>

#include "infoProblemaTransporte.h"
#include "ajustaProblema.h"
#include "leituraProblemaTransporte.h"
#include "problemaTransporteHelper.h"

void ajustaProblema(infoProblemaTransporte * problema, int ofertaTotal, int demandaTotal) {

    preencheOfertaDemandaNoTransbordoSeExistir(&problema, ofertaTotal > demandaTotal ? ofertaTotal : demandaTotal);

    criaRotaFicticiaSePrecisar(&problema, demandaTotal, ofertaTotal);

    inicializaValores(&problema);
}

void geraTabela(FILE * rotasArq, hash_map origens, hash_map destinos, infoProblemaTransporte * entrada, int custoProibitivo) {
    entrada->quantidadeOrigem = map_size(origens)+1;
    entrada->quantidadeDestino = map_size(destinos)+1;

    entrada->destinoFicticia = INVALIDO;
    entrada->origemFicticia = INVALIDO;

    entrada->custos = criaTabela(entrada->quantidadeOrigem, entrada->quantidadeDestino);

    entrada->valores = criaTabela(entrada->quantidadeOrigem, entrada->quantidadeDestino);

    entrada->origens = criaNos(entrada->quantidadeOrigem);
    entrada->destinos = criaNos(entrada->quantidadeDestino);

    entrada->divisaoCustoDestino = criaVetor(entrada->quantidadeDestino);
    entrada->divisaoCustoOrigem = criaVetor(entrada->quantidadeOrigem);

    entrada->economia = criaTabela(entrada->quantidadeOrigem, entrada->quantidadeDestino);

    inicializaCustos(entrada);

    leRotas(rotasArq, origens, destinos, entrada);

    criaRotasTransbordo(entrada);

    criaRotasProibidas(entrada, custoProibitivo);
}
