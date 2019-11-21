#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define QTD_COLUNA 10

#define SAIR false
#define CONTINUAR true

#define TXT 0
#define CSV 1
#define AMBOS 2

#define CUMULATIVA_APARTIR_DA_MEDIA 0
#define CUMULATIVA                  1
#define CUMULATIVA_COMPLEMENTAR     2

typedef struct {
    int precisao;
    int sigma;
    int tipoTabela;
} infoTabela;

long double cdf(float);
long double arredonda(double, double);

long double cumulativaApartirDaMedia(float);
long double cumulativa(float);
long double cumulativaComplementar(float);

void imprimeBoasVindas();

bool executaOpcao(int);
int leOpcao();
void imprimeOpcoes();

void imprimeErroOpcaoInvalida();

void imprimeAvisoProgramaEncerrado();

int lePrecisao();
int leSigma();

void geraTabela(infoTabela info);

void imprimeTabela(FILE *, infoTabela info);

void imprimeInfoTabela(FILE *, infoTabela);

void imprimeLinhaTracada(FILE *,int, infoTabela);
void imprimeTracadoIndicesColuna(FILE *,infoTabela);
void imprimeTracadoIndiceLinha(FILE *,int);
void imprimeTracadoCelula(FILE *,int);

void imprimeCabecalhoTabela(FILE *,infoTabela, int);
void imprimeZ(FILE *,int);
void imprimeIndicesColuna(FILE *,infoTabela);
void imprimeIndiceColuna(FILE *,int, infoTabela);

void imprimeLinhas(FILE *,int, infoTabela);
void imprimeLinha(FILE *,float, int, infoTabela);
void imprimeIndiceLinha(FILE *,int, float);
void imprimeProbabilidades(FILE *,float, infoTabela);
void imprimeProbabilidade(FILE *, float, infoTabela);

int determinaQuantidadeDeCasasDecimais(int);
int calculaTamanhoIndiceLinha(int);

void imprimeTabelaCsv(FILE * , infoTabela);

void imprimeInfoTabelaCsv(FILE *, infoTabela);

void imprimeCabecalhoTabelaCsv(FILE *);

void imprimeLinhasCsv(FILE *, infoTabela);
void imprimeLinhaCsv(FILE *, float, infoTabela);
void imprimeIndiceLinhaCsv(FILE *, float);
void imprimeProbabilidadesLinhaCsv(FILE *, float, infoTabela);
void imprimeProbabilidadeCsv(FILE *, float, infoTabela);

bool leSeUsuarioQuerSalvarTabela();

int leFormato();
void imprimeErroFormatoInvalido();

void salvaTabela(int, infoTabela);

void salvaTabelaTxt(char *, infoTabela );
char * leNomeArquivoTxt();
void imprimeSalvouTabelaFormatoTxt();
void imprimeErroAberturaArquivoTxt();

void salvaTabelaCsv(char *, infoTabela);
char * leNomeArquivoCsv();
void imprimeSalvouTabelaFormatoCsv();
void imprimeErroAberturaArquivoCsv();

void limpaTela();
void pausaTela();

bool eIgual(float, float);

int leInteiro();
char * leNome();

long double executaFuncaoTipoTabela(int, float);
char * getNomeTipoTabela(int);
int leTipoTabela();
bool validaTipoTabela(int);
bool isTipoTabelaValido(int);
void imprimeErroTipoTabelaInvalido();

infoTabela criaInfoTabela(int, int, int);

int main() {
    imprimeBoasVindas();
    while(executaOpcao(leOpcao()));
    return 0;
}

long double cdf(float z) {
    return 0.5 * (1.0 + erfl(z / sqrtl(2.0)));
}

long double arredonda(double numero, double precisao) {
    int dezElevadoAPrecisao = pow(10, precisao);
    return round(dezElevadoAPrecisao*numero) / dezElevadoAPrecisao;
}

long double cumulativaApartirDaMedia(float z) {
    return cdf(z) - 0.5;
}

long double cumulativa(float z) {
    return cdf(z);
}

long double cumulativaComplementar(float z) {
    return 1.0 - cdf(z);
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
    printf("| Opcoes:              |\n");
    printf("+----------------------+\n");
    printf("|   <0> - SAIR         |\n");
    printf("|   <1> - GERAR TABELA |\n");
    printf("+======================+\n");
}

bool executaOpcao(int entrada) {
    switch(entrada) {
        case 0:
            imprimeAvisoProgramaEncerrado();
            return SAIR;
        case 1:
            geraTabela(criaInfoTabela(leTipoTabela(), fabs(lePrecisao()), fabs(leSigma())));
            break;
        default:
            imprimeErroOpcaoInvalida();
    }
    pausaTela();
    limpaTela();
    return CONTINUAR;
}

infoTabela criaInfoTabela(int tipoTabela, int precisao, int sigma) {
    infoTabela retorno;
    retorno.tipoTabela = tipoTabela;
    retorno.precisao = precisao;
    retorno.sigma = sigma;
    return retorno;
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

long double executaFuncaoTipoTabela(int tipo, float z) {
    switch(tipo) {
        case CUMULATIVA_APARTIR_DA_MEDIA:
            return cumulativaApartirDaMedia(z);
        case CUMULATIVA:
            return cumulativa(z);
        case CUMULATIVA_COMPLEMENTAR:
            return cumulativaComplementar(z);
        default:
            return cdf(z);
    }
}

char * getNomeTipoTabela(int tipo) {
    char * nome = malloc(sizeof (char) * 70);
    switch(tipo) {
        case CUMULATIVA_APARTIR_DA_MEDIA:
            strcpy(nome, "Cumulativa a partir da media");
            break;
        case CUMULATIVA:
            strcpy(nome,"Cumulativa");
            break;
        case CUMULATIVA_COMPLEMENTAR:
            strcpy(nome,"Cumulativa complementar");            break;
        default:
            strcpy(nome,"Cumulativa");
    }
    return nome;
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
    imprimeErroTipoTabelaInvalido();
    return false;
}

bool isTipoTabelaValido(int tipo) {
    return tipo == CUMULATIVA_APARTIR_DA_MEDIA || tipo == CUMULATIVA || tipo == CUMULATIVA_COMPLEMENTAR;
}

void imprimeErroTipoTabelaInvalido() {
    printf("+===============================+\n");
    printf("| Erro: Tipo de tabela invalido |\n");
    printf("+===============================+\n");
    pausaTela();
    limpaTela();
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


void geraTabela(infoTabela info) {
    if(leSeUsuarioQuerSalvarTabela())
        salvaTabela(leFormato(), info);
    imprimeTabela(stdout, info);
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
            imprimeErroFormatoInvalido();
    }
}

void imprimeErroFormatoInvalido() {
    printf("+========================+\n");
    printf("| Erro: formato invalido |\n");
    printf("+========================+\n");
    pausaTela();
    limpaTela();
}

void salvaTabelaTxt(char * nomeArquivo, infoTabela info) {
    strcat(nomeArquivo, ".txt");
    FILE * saida;
    saida = fopen(nomeArquivo, "w");
    if(saida == NULL) {
        imprimeErroAberturaArquivoTxt();
        return;
    }
    imprimeTabela(saida, info);
    fclose(saida);
    imprimeSalvouTabelaFormatoTxt();
}

void imprimeSalvouTabelaFormatoTxt() {
    printf("+=========================================+\n");
    printf("| Tabela salva com sucesso no formato TXT |\n");
    printf("+=========================================+\n");
    pausaTela();
    limpaTela();
}

void imprimeErroAberturaArquivoTxt() {
    fprintf(stderr, "+==============================================+\n");
    fprintf(stderr, "| Erro: Na abertura do arquivo com formato TXT |\n");
    fprintf(stderr, "+==============================================+\n");
    pausaTela();
    limpaTela();
}

void salvaTabelaCsv(char * nomeArquivo, infoTabela info) {
    strcat(nomeArquivo, ".csv");
    FILE * saida;
    saida = fopen(nomeArquivo, "w");
    if(saida == NULL) {
        imprimeErroAberturaArquivoCsv();
        return;
    }
    imprimeTabelaCsv(saida, info);
    fclose(saida);
    imprimeSalvouTabelaFormatoCsv();
}

void imprimeSalvouTabelaFormatoCsv() {
    printf("+=========================================+\n");
    printf("| Tabela salva com sucesso no formato CSV |\n");
    printf("+=========================================+\n");
    pausaTela();
    limpaTela();
}

void imprimeErroAberturaArquivoCsv() {
    fprintf(stderr, "+==============================================+\n");
    fprintf(stderr, "| Erro: Na abertura do arquivo com formato CSV |\n");
    fprintf(stderr, "+==============================================+\n");
    pausaTela();
    limpaTela();
}

void imprimeTabelaCsv(FILE * saida, infoTabela info) {
    imprimeInfoTabelaCsv(saida, info);
    imprimeCabecalhoTabelaCsv(saida);
    imprimeLinhasCsv(saida, info);
}

void imprimeInfoTabelaCsv(FILE * saida, infoTabela info) {
    fprintf(saida, "Tabela Normal Padronizada %s\n", getNomeTipoTabela(info.tipoTabela));
    fprintf(saida, "Sigma;%d\n", info.sigma);
    fprintf(saida, "Precisao;%d\n\n", info.precisao);
}

void imprimeCabecalhoTabelaCsv(FILE * saida) {
    fprintf(saida, "z;0;1;2;3;4;5;6;7;8;9\n");
}

void imprimeLinhasCsv(FILE * saida, infoTabela info) {
    float linha;
    for(linha = 0.0; !eIgual(info.sigma, linha); linha+=0.1)
        imprimeLinhaCsv(saida, linha, info);
}

void imprimeLinhaCsv(FILE * saida, float linha, infoTabela info) {
    imprimeIndiceLinhaCsv(saida, linha);
    imprimeProbabilidadesLinhaCsv(saida, linha, info);
    fprintf(saida, "\n");
}

void imprimeIndiceLinhaCsv(FILE * saida, float linha) {
    fprintf(saida, "%.1f", linha);
}

void imprimeProbabilidadesLinhaCsv(FILE * saida, float linha, infoTabela info) {
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeProbabilidadeCsv(saida, linha+coluna*0.01, info);
}

void imprimeProbabilidadeCsv(FILE * saida, float z, infoTabela info) {
    fprintf(saida, ";%.*Lf", info.precisao, arredonda(executaFuncaoTipoTabela(info.tipoTabela, z), info.precisao));
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

void imprimeTabela(FILE * saida, infoTabela info) {
    int ultimaLinha = info.sigma-1;
    int tamanhoIndiceLinha = determinaQuantidadeDeCasasDecimais(ultimaLinha)+2;
    int tamanhoCelula = tamanhoIndiceLinha+2;

    imprimeInfoTabela(saida, info);

    imprimeLinhaTracada(saida, tamanhoCelula, info);

    imprimeCabecalhoTabela(saida, info, tamanhoIndiceLinha);

    imprimeLinhaTracada(saida, tamanhoCelula, info);

    imprimeLinhas(saida, tamanhoIndiceLinha, info);

    imprimeLinhaTracada(saida, tamanhoCelula, info);
}

void imprimeInfoTabela(FILE * saida, infoTabela info) {
    fprintf(saida, "+========================================================+\n");
    fprintf(saida, "| Tabela Normal Padronizada %-28s |\n", getNomeTipoTabela(info.tipoTabela));
    fprintf(saida, "+--------------------------------------------------------+\n");
    fprintf(saida, "| Sigma    = %-44d|\n", info.sigma);
    fprintf(saida, "| Precisao = %-44d|\n", info.precisao);
    fprintf(saida, "+========================================================+\n");
}

void imprimeLinhas(FILE * saida, int tamanhoIndice, infoTabela info) {
    float linha;
    for(linha = 0.0; !eIgual(info.sigma, linha); linha += 0.1)
        imprimeLinha(saida, linha, tamanhoIndice, info);
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

void imprimeLinhaTracada(FILE * saida, int tamanhoCelula, infoTabela info) {
    imprimeTracadoIndiceLinha(saida, tamanhoCelula);

    imprimeTracadoIndicesColuna(saida, info);

    fprintf(saida, "\n");
}

void imprimeTracadoIndicesColuna(FILE * saida, infoTabela info) {
    int celula;
    for(celula = 0; celula < QTD_COLUNA; celula++)
        imprimeTracadoCelula(saida, info.precisao+4);
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

void imprimeCabecalhoTabela(FILE * saida, infoTabela info, int tamanhoIndice) {
    imprimeZ(saida, tamanhoIndice);

    imprimeIndicesColuna(saida, info);

    fprintf(saida, "\n");
}

void imprimeZ(FILE * saida, int tamanhoIndice) {
    fprintf(saida, "| %*s |", tamanhoIndice, "Z");
}

void imprimeIndicesColuna(FILE * saida, infoTabela info) {
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeIndiceColuna(saida, coluna, info);
}

void imprimeIndiceColuna(FILE * saida, int coluna, infoTabela info) {
    fprintf(saida, " %*d |", info.precisao+2, coluna);
}

void imprimeLinha(FILE * saida, float linha, int tamanhoIndice, infoTabela info) {
    imprimeIndiceLinha(saida, tamanhoIndice, linha);

    imprimeProbabilidades(saida, linha, info);

    fprintf(saida, "\n");
}

void imprimeProbabilidades(FILE * saida, float linha, infoTabela info) {
    int coluna;
    for(coluna = 0; coluna < QTD_COLUNA; coluna++)
        imprimeProbabilidade(saida, linha+coluna*0.01, info);
}

void imprimeIndiceLinha(FILE * saida, int tamanhoIndice, float indice) {
    fprintf(saida, "| %*.1f |", tamanhoIndice, indice);
}

void imprimeProbabilidade(FILE * saida, float z, infoTabela info) {
    fprintf(saida, " %.*Lf |", info.precisao, arredonda(executaFuncaoTipoTabela(info.tipoTabela, z), info.precisao));
}
