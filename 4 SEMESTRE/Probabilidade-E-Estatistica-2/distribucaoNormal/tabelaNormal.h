#ifndef TABELANORMAL_H_INCLUDED
#define TABELANORMAL_H_INCLUDED

#include <stdbool.h>

#define QTD_COLUNA 10

#define CUMULATIVA_APARTIR_DA_MEDIA 0
#define CUMULATIVA                  1
#define CUMULATIVA_COMPLEMENTAR     2

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

typedef struct {
    double ** tabela;
    int precisao;
    int sigma;
    int tipoTabela;
    int qtd_linha;
} infoTabela;

double executaFuncaoTipoTabela(float, infoTabela);

bool isTipoTabelaValido(int);

char * getNomeTipoTabela(int);

double f(double x);

double regraDosTrapezio(double, double, int);

bool criaTabela (infoTabela * info);

void apagaTabela (infoTabela info);

double funcaoDistribuicaoNormal(float, infoTabela);

void inicializaTabela(infoTabela * info);

infoTabela criaInfoTabela(int, int, int);

#endif // TABELANORMAL_H_INCLUDED
