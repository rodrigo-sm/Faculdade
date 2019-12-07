#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "infoProblemaTransporte.h"
#include "leituraProblemaTransporte.h"
#include "interfaceHelper.h"
#include "problemaTransporteInterface.h"
#include "problemaTransporteHelper.h"
#include "geraProblemaTransporte.h"

infoProblemaTransporte leInfoProblemaTransporte() {
    infoProblemaTransporte problema;

    problema = leEntradaPrompt();

    imprimeCustos(problema);

    return problema;
}

infoProblemaTransporte leEntradaPrompt() {
    infoProblemaTransporte problema;

    double ofertaTotal, demandaTotal, maiorCusto;

    hash_map origens, destinos;
    map_init(origens);
    map_init(destinos);

    maiorCusto = leRotasPrompt(&problema, origens, destinos);

    geraProblema(origens, destinos, &problema, maiorCusto*10);

    ofertaTotal = leOfertasPrompt(&problema);
    demandaTotal = leDemandasPrompt(&problema);

    ajustaProblema(&problema, ofertaTotal, demandaTotal);

    return problema;
}

double leRotasPrompt(infoProblemaTransporte * entrada, hash_map origens, hash_map destinos) {
    map_value no;

    FILE * rotasArq;
    rotasArq = fopen(ROTAFILE, "w");

    double maiorCusto = -1;
    rota rotaAtual;

    do {
        rotaAtual = leRotaPrompt(entrada);

        gravaRotaFILE(rotasArq, &rotaAtual);

        strcpy(no.nome, rotaAtual.origem.nome);
        map_put(origens, no.nome, no);

        strcpy(no.nome, rotaAtual.destino.nome);
        map_put(destinos, no.nome, no);

        if(maiorCusto < rotaAtual.custo)
            maiorCusto = rotaAtual.custo;

    } while(leUsuarioQuerMaisRotas());

    fclose(rotasArq);

    return maiorCusto;
}

void gravaRotaFILE(FILE * rotasArq, rota * entrada) {
    fwrite(entrada, sizeof(rota), 1, rotasArq);
}

rota leRotaPrompt() {
    rota retorno;

    pulaLinha();
    leOrigem(retorno.origem.nome);
    leDestino(retorno.destino.nome);
    retorno.custo = leCusto();

    return retorno;

}

void leOrigem(char * nome) {
    printf("origem: ");
    scanf(" %s", nome);
    transformaEmMaiusculo(nome);
}

void leDestino(char * nome) {
    printf("destino: ");
    scanf(" %s", nome);
    transformaEmMaiusculo(nome);
}

void transformaEmMaiusculo(char * palavra) {
    int letra;

    for(letra = 0; palavra[letra]; letra++)
      palavra[letra] = toupper(palavra[letra]);
}

double leCusto() {
    printf("custo: ");
    return leDouble();
}

void leQuadroCustoUnitario(infoProblemaTransporte * entrada) {
    FILE * rotasArq = fopen(ROTAFILE, "r");

    rota rotaAtual;

    entrada->ultimaOrigemReal = 0;
    entrada->ultimoDestinoReal = 0;

    while(leRotaFILE(rotasArq, &rotaAtual)) {
        rotaAtual.origem.indice = insereSeNaoExisteOrigem(entrada, rotaAtual.origem.nome);
        rotaAtual.destino.indice = insereSeNaoExisteDestino(entrada, rotaAtual.destino.nome);
        entrada->custos[rotaAtual.origem.indice][rotaAtual.destino.indice] = rotaAtual.custo;
    }

    fclose(rotasArq);
}

bool leRotaFILE(FILE * rotasArq, rota * saida) {
    return fread(saida, sizeof(rota), 1, rotasArq) == 1;
}

int insereSeNaoExisteOrigem(infoProblemaTransporte * entrada, char * nomeOrigemAtual) {
    int origem;

    for(origem = 0; origem < entrada->ultimaOrigemReal; origem++)
        if(strcmp(entrada->origens[origem].nome, nomeOrigemAtual) == 0)
            return origem; // Existe origem

    // Insere origem
    infoNo origemAtual;
    strcpy(origemAtual.nome, nomeOrigemAtual);
    entrada->origens[entrada->ultimaOrigemReal] = origemAtual;

    return entrada->ultimaOrigemReal++;
}

int insereSeNaoExisteDestino(infoProblemaTransporte * entrada, char * nomeDestinoAtual) {
    int destino;

    for(destino = 0; destino < entrada->ultimoDestinoReal; destino++)
        if(strcmp(entrada->destinos[destino].nome, nomeDestinoAtual) == 0)
            return destino; // Existe destino

    // Insere destino
    infoNo destinoAtual;
    strcpy(destinoAtual.nome, nomeDestinoAtual);
    entrada->destinos[entrada->ultimoDestinoReal] = destinoAtual;

    return entrada->ultimoDestinoReal++;
}

bool leUsuarioQuerMaisRotas() {
    printf("mais rotas? (S/N): ");
    return leSimOuNao();
}

double leOfertasPrompt(infoProblemaTransporte * entrada) {
    double ofertaTotal = 0;
    int origem;

    printf("\nOrigens\n");

    for(origem = 0; origem < entrada->ultimaOrigemReal; origem++)
        if(!isOrigemTransbordo(entrada, entrada->origens[origem]))
            ofertaTotal += leOferta(&entrada->origens[origem]);
    return ofertaTotal;
}

double leOferta(infoNo * entrada) {
    printf("Oferta %s: ", entrada->nome);
    scanf(" %lf", &entrada->valor);
    return entrada->valor;
}

double leDemandasPrompt(infoProblemaTransporte * entrada) {
    double demandaTotal = 0;
    int destino;

    printf("\nDestinos\n");

    for(destino = 0; destino < entrada->ultimoDestinoReal; destino++)
        if(!isDestinoTransbordo(entrada, entrada->destinos[destino]))
            demandaTotal += leDemanda(&entrada->destinos[destino]);
    return demandaTotal;
}

double leDemanda(infoNo * entrada) {
    printf("Demanda %s: ", entrada->nome);
    scanf(" %lf", &entrada->valor);
    return entrada->valor;
}

bool isOrigemTransbordo(infoProblemaTransporte * info, infoNo origem) {
    int destino;

    for(destino = 0; destino < info->ultimoDestinoReal;  destino++)
        if(strcmp(info->destinos[destino].nome, origem.nome) == 0)
            return true;

    return false;
}

bool isDestinoTransbordo(infoProblemaTransporte * info, infoNo destino) {
    int origem;

    for(origem = 0; origem < info->ultimaOrigemReal;  origem++)
        if(strcmp(info->origens[origem].nome, destino.nome) == 0)
            return true;

    return false;
}
