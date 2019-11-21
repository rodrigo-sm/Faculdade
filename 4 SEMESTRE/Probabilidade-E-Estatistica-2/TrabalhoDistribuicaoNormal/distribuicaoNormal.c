#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define QTD_COLUNA 10
#define SAIR 0
#define CONTINUAR 1
#define TXT 0
#define CSV 1
#define AMBOS 2

int executaOpcao(int);
int leOpcao();
int lePrecisao();
int leSigma();
int leInteiro();
int leFormato();
char * leNomeArquivoCsv();
char * leNomeArquivoTxt();
char * leNome();
bool leSeUsuarioQuerSalvarTabela();
void imprimeBoasVindas();
void imprimeOpcoes();
void imprimeLinha(FILE *,float, int, int);
void imprimeCabecalhoTabela(FILE *,int, int);
void imprimeLinhaTracada(FILE *,int, int);
void imprimeTracadoIndiceLinha(FILE *,int);
void imprimeTracadoCelula(FILE *,int);
void imprimeProbabilidade(FILE *,int, float);
void imprimeIndiceLinha(FILE *,int, float);
void imprimeIndicesColuna(FILE *,int);
void imprimeIndiceColuna(FILE *,int, int);
void imprimeZ(FILE *,int);
void imprimeAvisoProgramaEncerrado();
void imprimeErroOpcaoInvalida();
void imprimeTabela(FILE *,int, int);
void imprimeLinhas(FILE *,int, int, int);
void imprimeProbabilidades(FILE *,float, int);
void imprimeTracadoIndicesColuna(FILE *,int);
void imprimeTabelaCsv(FILE * , int, int);
void imprimeCabecalhoTabelaCsv(FILE *);
void imprimeLinhasCsv(FILE *, int, int);
void imprimeLinhaCsv(FILE *, float, int);
void imprimeIndiceLinhaCsv(FILE *, float);
void imprimeProbabilidadesLinhaCsv(FILE *, float, int);
void imprimeProbabilidadeCsv(FILE *, float, int);
void geraTabela(int, int);
void limpaTela();
void pausaTela();
int determinaQuantidadeDeCasasDecimais(int);
int calculaTamanhoIndiceLinha(int);
long double cdf(float);
long double delimitaPrecisao(double, double);
bool eIgual(float, float);
void salvaTabela(int, int, int);
void salvaTabelaTxt(char *, int, int);
void salvaTabelaCsv(char *, int, int);
void salvaTabelaAmbosFormato(char *, char *, int, int);

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
    printf("+======================+\n");
    printf("| OPCOES:              |\n");
    printf("+----------------------+\n");
    printf("|   <0> - SAIR         |\n");
    printf("|   <1> - GERAR TABELA |\n");
    printf("+======================+\n");
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
    printf("+====================+\n");
    printf("| Informe a precisao |\n");
    printf("+====================+\n");
    return leInteiro();
}

int leSigma() {
    printf("+=================+\n");
    printf("| Informe o sigma |\n");
    printf("+=================+\n");
    return leInteiro();
}

int leInteiro() {
    printf(">>> ");
    int retorno;
    scanf(" %d", &retorno);
    limpaTela();
    return retorno;
}


void geraTabela(int precisao, int sigma) {
    if(leSeUsuarioQuerSalvarTabela())
        salvaTabela(leFormato(), precisao, sigma);
    imprimeTabela(stdout, precisao, sigma);
}

bool leSeUsuarioQuerSalvarTabela() {
    printf("+==========================+\n");
    printf("| Deseja salvar a tabela ? |\n");
    printf("+--------------------------+\n");
    printf("|   <0> NAO                |\n");
    printf("|   <1> SIM                |\n");
    printf("+==========================+\n");
    return leInteiro() == 1 ? true : false;
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

void salvaTabela(int formato, int precisao, int sigma) {
    switch(formato) {
        case TXT:
            salvaTabelaTxt(leNomeArquivoTxt(), precisao, sigma);
            break;
        case CSV:
            salvaTabelaCsv(leNomeArquivoCsv(), precisao, sigma);
            break;
        case AMBOS:
            salvaTabelaAmbosFormato(leNomeArquivoTxt(), leNomeArquivoCsv(), precisao, sigma);
            break;
        default:
            printf("Erro formato invalido\n");
    }
}

void salvaTabelaAmbosFormato(char * nomeArquivoTxt, char * nomeArquivoCsv, int precisao, int sigma) {
    salvaTabelaTxt(nomeArquivoTxt, precisao, sigma);
    salvaTabelaCsv(nomeArquivoCsv, precisao, sigma);
}

void salvaTabelaTxt(char * nomeArquivo, int precisao, int sigma) {
    strcat(nomeArquivo, ".txt");
    FILE * saida;
    saida = fopen(nomeArquivo, "w");
    if(saida == NULL) {
        fprintf(stderr, "Erro na abertura do arquivo database.txt\n");
        return;
    }
    imprimeTabela(saida, precisao, sigma);
    fclose(saida);
    printf("Tabela salva com sucesso no arquivo %s !\n", nomeArquivo);
}

void salvaTabelaCsv(char * nomeArquivo, int precisao, int sigma) {
    strcat(nomeArquivo, ".csv");
    FILE * saida;
    saida = fopen(nomeArquivo, "w");
    if(saida == NULL) {
        fprintf(stderr, "Erro na abertura do arquivo database.txt\n");
        return;
    }
    imprimeTabelaCsv(saida, precisao, sigma);
    fclose(saida);
    printf("Tabela salva com sucesso no arquivo %s !\n", nomeArquivo);
}

void imprimeTabelaCsv(FILE * saida, int precisao, int sigma) {
    imprimeCabecalhoTabelaCsv(saida);
    imprimeLinhasCsv(saida, precisao, sigma);
}

void imprimeCabecalhoTabelaCsv(FILE * saida) {
    fprintf(saida, "z;0;1;2;3;4;5;6;7;8;9\n");
}

void imprimeLinhasCsv(FILE * saida, int precisao, int sigma) {
    float linha;
    for(linha = 0.0; !eIgual(sigma, linha); linha+=0.1)
        imprimeLinhaCsv(saida, linha, precisao);
}

void imprimeLinhaCsv(FILE * saida, float linha, int precisao) {
    imprimeIndiceLinhaCsv(saida, linha);
    imprimeProbabilidadesLinhaCsv(saida, linha, precisao);
    fprintf(saida, "\n");
}

void imprimeIndiceLinhaCsv(FILE * saida, float linha) {
    fprintf(saida, "%.1f", linha);
}

void imprimeProbabilidadesLinhaCsv(FILE * saida, float linha, int precisao) {
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeProbabilidadeCsv(saida, linha+coluna*0.01, precisao);
}

void imprimeProbabilidadeCsv(FILE * saida, float z, int precisao) {
    fprintf(saida, ";%.*Lf", precisao, delimitaPrecisao(cdf(z), precisao));
}

char * leNomeArquivoCsv() {
    printf("+===============================+\n");
    printf("| Informe o nome do arquivo CSV |\n");
    printf("+===============================+\n");
    return leNome();
}

char * leNomeArquivoTxt() {
    printf("+===============================+\n");
    printf("| Informe o nome do arquivo TXT |\n");
    printf("+===============================+\n");
    return leNome();
}

char * leNome() {
    printf(">>> ");
    char * entrada = malloc(sizeof (char) * 50);
    scanf(" %50[^\n]", entrada);
    limpaTela();
    return entrada;
}

void imprimeTabela(FILE * saida, int precisao, int sigma) {
    int ultimaLinha = sigma-1;
    int tamanhoIndiceLinha = determinaQuantidadeDeCasasDecimais(ultimaLinha)+2;
    int tamanhoCelula = tamanhoIndiceLinha+2;

    imprimeLinhaTracada(saida, tamanhoCelula, precisao);

    imprimeCabecalhoTabela(saida, precisao, tamanhoIndiceLinha);

    imprimeLinhaTracada(saida, tamanhoCelula, precisao);

    imprimeLinhas(saida, tamanhoIndiceLinha, precisao, sigma);

    imprimeLinhaTracada(saida, tamanhoCelula, precisao);
}

void imprimeLinhas(FILE * saida, int tamanhoIndice, int precisao, int limite) {
    float linha;
    for(linha = 0.0; !eIgual(limite, linha); linha += 0.1)
        imprimeLinha(saida, linha, precisao, tamanhoIndice);
}

bool eIgual(float n1, float n2) {
    return fabs(n1 - n2) < 0.01 ? true : false;
}

int determinaQuantidadeDeCasasDecimais(int numero) {
    int casas = 1;
	while(numero > 9){
		casas++;
		numero /= 10;
	}
	return casas;
}

void imprimeLinhaTracada(FILE * saida, int tamanhoCelula, int precisao) {
    imprimeTracadoIndiceLinha(saida, tamanhoCelula);

    imprimeTracadoIndicesColuna(saida, precisao);

    fprintf(saida, "\n");
}

void imprimeTracadoIndicesColuna(FILE * saida, int precisao) {
    int celula;
    for(celula = 0; celula < QTD_COLUNA; celula++)
        imprimeTracadoCelula(saida, precisao+4);
}

void imprimeTracadoIndiceLinha(FILE * saida, int tamanhoIndice) {
    fprintf(saida, "+");
    while(tamanhoIndice--)
        fprintf(saida, "-");
    fprintf(saida, "+");
}

void imprimeTracadoCelula(FILE * saida, int tamanhoCelula) {
    while(tamanhoCelula--)
        fprintf(saida, "-");
    fprintf(saida, "+");
}

void imprimeCabecalhoTabela(FILE * saida, int precisao, int tamanhoIndice) {
    imprimeZ(saida, tamanhoIndice);

    imprimeIndicesColuna(saida, precisao);

    fprintf(saida, "\n");
}

void imprimeZ(FILE * saida, int tamanhoIndice) {
    fprintf(saida, "| %*s |", tamanhoIndice, "Z ");
}

void imprimeIndicesColuna(FILE * saida,int precisao) {
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeIndiceColuna(saida, precisao, coluna);
}

void imprimeIndiceColuna(FILE * saida, int precisao, int coluna) {
    fprintf(saida, " %*d |", precisao+2, coluna);
}

void imprimeLinha(FILE * saida, float linha, int precisao, int tamanhoIndice) {
    imprimeIndiceLinha(saida, tamanhoIndice, linha);

    imprimeProbabilidades(saida, linha, precisao);

    fprintf(saida, "\n");
}

void imprimeProbabilidades(FILE * saida, float linha, int precisao) {
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeProbabilidade(saida, precisao, linha+coluna*0.01);
}

void imprimeIndiceLinha(FILE * saida, int tamanhoIndice, float indice) {
    fprintf(saida, "| %*.1f |", tamanhoIndice, indice);
}

void imprimeProbabilidade(FILE * saida, int precisao, float z) {
    fprintf(saida, " %.*Lf |", precisao, delimitaPrecisao(cdf(z), precisao));
}

long double cdf(float z) {
    return 0.5*erfc(-z* (1.0/sqrt(2.0))) - 0.5;
}

long double delimitaPrecisao(double probabilidade, double precisao) {
    return round( pow(10, precisao)*probabilidade ) / pow(10, precisao);
}
