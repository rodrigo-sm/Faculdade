#include <stdio.h>
#include <stdlib.h>

#include "problemaTransporteHelper.h"
#include "infoProblemaTransporte.h"
#include "rotasOrdenadas.h"

void criaRotasReaisOrdenados(infoProblemaTransporte problema, int quantidadeDeRotas, rota * rotas) {
    inicializaRotasOrdenadas(rotas, problema);
    ordenaRotas(rotas, quantidadeDeRotas);
}

void inicializaRotasOrdenadas(rota * rotas, infoProblemaTransporte info) {
    int origem, destino, rota = 0;

    for(origem = 0; origem < info.ultimaOrigemReal; origem++)
        for(destino = 0; destino < info.ultimoDestinoReal; destino++)
            rotas[rota++] = criaRota(info.custos[origem][destino], origem, destino);

}

void ordenaRotas (rota rotas[], int quantidadeDeRotas) {
    int k, j;
    rota aux;

    for (k = 1; k < quantidadeDeRotas; k++) {
        for (j = 0; j < quantidadeDeRotas - 1; j++) {
            if (rotas[j].custo > rotas[j + 1].custo) {
                aux          = rotas[j];
                rotas[j]     = rotas[j + 1];
                rotas[j + 1] = aux;
            }
        }
    }
}
