#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "tabelaNormal.h"
#include "tabelaCsv.h"
#include "tabelaFormatada.h"
#include "interfaceHelper.h"

#define ERRO false
#define SUCESSO true

#define TXT 0
#define CSV 1
#define AMBOS 2

#define GRAVAR 1
#define NAO_GRAVAR 0

bool executaOpcao(int);
int leOpcao();
void imprimeOpcoes();

int lePrecisao();
int leSigma();

void geraTabela(infoTabela info);

bool leSeUsuarioQuerSalvarTabela();
bool validaOpcaoGravarTabela(int);

int leFormato();

void salvaTabela(int, infoTabela);

void salvaTabelaTxt(char *, infoTabela );
char * leNomeArquivoTxt();

void salvaTabelaCsv(char *, infoTabela);
char * leNomeArquivoCsv();

int leTipoTabela();
bool validaTipoTabela(int);

int main() {
    imprimeAlertaSimples("Bem vindo ao Trabalho de Probabilidade e Estatisca 2");
    while(executaOpcao(leOpcao()));
    return 0;
}

int leOpcao() {
    imprimeOpcoes();
    return leInteiro();
}

void imprimeOpcoes() {
    printf("+======================+\n");
    printf("| Opcoes:              |\n");
    printf("+----------------------+\n");
    printf("|   <0> - SAIR         |\n");
    printf("|   <1> - GERAR TABELA |\n");
    printf("+======================+\n");
}

bool executaOpcao(int entrada) {
    switch(entrada) {
        case 0:
            imprimeMensagemSimples("Aviso: Programa encerrado");
            return ERRO;
        case 1:
            geraTabela(criaInfoTabela(leTipoTabela(), fabs(lePrecisao()), fabs(leSigma())));
            break;
        default:
            imprimeMensagemSimples("Erro: Opcao invalida");
    }
    pausaTela();
    limpaTela();
    return SUCESSO;
}

int leTipoTabela() {
    int tipo;
    do {
        printf("+=======================================================+\n");
        printf("| Tipos de Tabela:                                      |\n");
        printf("+=======================================================+\n");
        printf("|   <0> Cumulativa a partir da media -> P(0 <= Z <= Zo) |\n");
        printf("|   <1> Cumulativa                   -> P(Z <= Zo)      |\n");
        printf("|   <2> Cumulativa complementar      -> P(Z >= Zo)      |\n");
        printf("+=======================================================+\n");
        tipo = leInteiro();
    } while(!validaTipoTabela(tipo));
    return tipo;
}

bool validaTipoTabela(int tipo) {
    if(isTipoTabelaValido(tipo))
        return true;
    imprimeAlertaSimples("Erro: Tipo de tabela invalido");
    return false;
}

int lePrecisao() {
    imprimeMensagemSimples("Informe a precisao");
    return leInteiro();
}

int leSigma() {
    imprimeMensagemSimples("Informe o sigma");
    return leInteiro();
}

void geraTabela(infoTabela info) {
    criaTabela(&info);
    limpaTela();
    if(leSeUsuarioQuerSalvarTabela())
        salvaTabela(leFormato(), info);
    imprimeTabela(stdout, info);
    apagaTabela(info);
}

bool leSeUsuarioQuerSalvarTabela() {
    int opcao;
    do {
        printf("+==========================+\n");
        printf("| Deseja salvar a tabela ? |\n");
        printf("+--------------------------+\n");
        printf("|   <0> NAO                |\n");
        printf("|   <1> SIM                |\n");
        printf("+==========================+\n");
        opcao = leInteiro();
    } while(!validaOpcaoGravarTabela(opcao));
    return opcao == GRAVAR ? true : false;
}

bool validaOpcaoGravarTabela(int opcao) {
    if(opcao == GRAVAR || opcao == NAO_GRAVAR)
        return true;
    imprimeAlertaSimples("Erro: Opcao invalida");
    return false;
}

int leFormato() {
    printf("+=============+\n");
    printf("| Formatos:   |\n");
    printf("+-------------+\n");
    printf("|   <0> TXT   |\n");
    printf("|   <1> CSV   |\n");
    printf("|   <2> AMBOS |\n");
    printf("+=============|\n");
    return leInteiro();
}

void salvaTabela(int formato, infoTabela info) {
    switch(formato) {
        case TXT:
            salvaTabelaTxt(leNomeArquivoTxt(), info);
            break;
        case CSV:
            salvaTabelaCsv(leNomeArquivoCsv(), info);
            break;
        case AMBOS:
            salvaTabelaTxt(leNomeArquivoTxt(), info);
            salvaTabelaCsv(leNomeArquivoCsv(), info);
            break;
        default:
            imprimeAlertaSimples("Erro: Formato invalido");
    }
}

void salvaTabelaTxt(char * nomeArquivo, infoTabela info) {
    strcat(nomeArquivo, ".txt");
    FILE * saida;
    saida = fopen(nomeArquivo, "w");
    if(saida == NULL) {
        imprimeAlertaSimples("Erro: Na abertura do arquivo com formato TXT");
        return;
    }
    imprimeTabela(saida, info);
    fclose(saida);
    imprimeAlertaSimples("Tabela salva com sucesso no formato TXT");
}

void salvaTabelaCsv(char * nomeArquivo, infoTabela info) {
    strcat(nomeArquivo, ".csv");
    FILE * saida;
    saida = fopen(nomeArquivo, "w");
    if(saida == NULL) {
        imprimeAlertaSimples("Erro: Na abertura do arquivo com formato CSV");
        return;
    }
    imprimeTabelaCsv(saida, info);
    fclose(saida);
    imprimeAlertaSimples("Tabela salva com sucesso no formato CSV");
}

char * leNomeArquivoCsv() {
    imprimeMensagemSimples("Informe o nome do arquivo CSV");
    return leNome();
}

char * leNomeArquivoTxt() {
    imprimeMensagemSimples("Informe o nome do arquivo TXT");
    return leNome();
}

char * leNome() {
    printf(">>> ");
    char * entrada = malloc(sizeof (char) * 50);
    scanf(" %50[^\n]", entrada);
    limpaTela();
    return entrada;
}
