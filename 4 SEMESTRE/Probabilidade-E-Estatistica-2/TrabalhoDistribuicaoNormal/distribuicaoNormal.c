#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define QTD_COLUNA 10
#define SAIR 0
#define CONTINUAR 1

int executaOpcao(int);
int leOpcao();
int lePrecisao();
int leSigma();
int leInteiro();
void imprimeBoasVindas();
void imprimeOpcoes();
void imprimeLinha(float, int, int);
void imprimeCabecalhoTabela(int, int);
void imprimeLinhaTracada(int, int);
void imprimeTracadoIndiceLinha(int);
void imprimeTracadoCelula(int);
void imprimeProbabilidade(int, float);
void imprimeIndiceLinha(int, float);
void imprimeIndicesColuna(int);
void imprimeIndiceColuna(int, int);
void imprimeZ(int);
void imprimeAvisoProgramaEncerrado();
void imprimeErroOpcaoInvalida();
void geraTabela(int, int);
void limpaTela();
void pausaTela();
int determinaQuantidadeDeCasasDecimais(int);
int calculaEspacamentoIndiceLinha(int);
long double cdf(float, int);
long double delimitaPrecisao(double, double);

int main() {
    imprimeBoasVindas();
    while(executaOpcao(leOpcao()));
    return 0;
}

void imprimeBoasVindas() {
    printf("+======================================================+\n");
    printf("| Bem vindo ao Trabalho de Probabilidade e Estatisca 2 |\n");
    printf("+======================================================+\n");
    pausaTela();
    limpaTela();
}

int leOpcao() {
    imprimeOpcoes();
    return leInteiro();
}

void imprimeOpcoes() {
    printf("+======= OPCOES =======+\n");
    printf("| <0> - SAIR           |\n");
    printf("| <1> - GERAR TABELA   |\n");
    printf("+----------------------+\n");
    printf(">>> ");
}

int executaOpcao(int entrada) {
    switch(entrada) {
        case 0:
            imprimeAvisoProgramaEncerrado();
            return SAIR;
        case 1:
            geraTabela(lePrecisao(), leSigma());
            break;
        default:
            imprimeErroOpcaoInvalida();
    }
    pausaTela();
    limpaTela();
    return CONTINUAR;
}

void imprimeAvisoProgramaEncerrado() {
    printf("+===========================+\n");
    printf("| Aviso: Programa encerrado |\n");
    printf("+===========================+\n");
}

void imprimeErroOpcaoInvalida() {
    printf("+======================+\n");
    printf("| Erro: Opcao invalida |\n");
    printf("+======================+\n");
}

void pausaTela() {
    printf("Pressione enter para continuar...\n");
    getchar();
    scanf("c\n");
}

void limpaTela() {
    #ifdef _WIN32
        system("cls");
    #elif defined(unix) || defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))
        system("clear");
    #else
    #error "OS not supported."
    #endif
}

int lePrecisao() {
    printf("Informe a precisao:\n>>> ");
    return leInteiro();
}

int leSigma() {
    printf("Informe o sigma:\n>>> ");
    return leInteiro();
}

int leInteiro() {
    int retorno;
    scanf(" %d", &retorno);
    limpaTela();
    return retorno;
}


void geraTabela(int precisao, int sigma) {
    int indiceMaximo = sigma-1;
    int tamanhoIndiceLinha = calculaEspacamentoIndiceLinha(indiceMaximo),
        tamanhoCelula = determinaQuantidadeDeCasasDecimais(indiceMaximo)+4;

    imprimeLinhaTracada(tamanhoCelula, precisao);
    imprimeCabecalhoTabela(precisao, tamanhoIndiceLinha);
    imprimeLinhaTracada(tamanhoCelula, precisao);

    float linha;
    for(linha = 0.0; linha <= sigma-0.1; linha += 0.1)
        imprimeLinha(linha, precisao, tamanhoIndiceLinha);

    imprimeLinhaTracada(tamanhoCelula, precisao);
}

int calculaEspacamentoIndiceLinha(int indiceMaximo) {
    return determinaQuantidadeDeCasasDecimais(indiceMaximo)+2;
}

int determinaQuantidadeDeCasasDecimais(int numero) {
    int casas = 1;

	while(numero > 9){
		casas++;
		numero /= 10;
	}

	return casas;
}

void imprimeLinhaTracada(int tamanhoCelula, int precisao) {
    imprimeTracadoIndiceLinha(tamanhoCelula);

    int celula;
    for(celula = 0; celula < QTD_COLUNA; celula++)
        imprimeTracadoCelula(precisao+4);
    printf("\n");
}

void imprimeTracadoIndiceLinha(int tamanhoIndice) {
    printf("+");
    while(tamanhoIndice--)
        printf("-");
    printf("+");
}

void imprimeTracadoCelula(int tamanhoCelula) {
    while(tamanhoCelula--)
        printf("-");
    printf("+");
}

void imprimeCabecalhoTabela(int precisao, int tamanhoIndice) {
    imprimeZ(tamanhoIndice);
    imprimeIndicesColuna(precisao);
    int coluna;
}

void imprimeZ(int tamanhoIndice) {
    printf("| %*s |", tamanhoIndice, "Z ");
}

void imprimeIndicesColuna(int precisao) {
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeIndiceColuna(precisao, coluna);
    printf("\n");
}

void imprimeIndiceColuna(int precisao, int coluna) {
    printf(" %*d |", precisao+2, coluna);
}

void imprimeLinha(float linha, int precisao, int tamanhoIndice) {
    imprimeIndiceLinha(tamanhoIndice, linha);
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeProbabilidade(precisao, linha+coluna*0.01);
    printf("\n");
}

void imprimeIndiceLinha(int tamanhoIndice, float indice) {
    printf("| %*.1f |", tamanhoIndice, indice);
}

void imprimeProbabilidade(int precisao, float z) {
    printf(" %.*Lf |", precisao, cdf(z, precisao));
}

long double cdf(float z, int precisao) {
    long double probabilidade = 0.5*erfc(-z* (1.0/sqrt(2.0))) - 0.5;
    return delimitaPrecisao(probabilidade, precisao);
}

long double delimitaPrecisao(double probabilidade, double precisao) {
    return round( pow(10, precisao)*probabilidade ) / pow(10, precisao);
}
