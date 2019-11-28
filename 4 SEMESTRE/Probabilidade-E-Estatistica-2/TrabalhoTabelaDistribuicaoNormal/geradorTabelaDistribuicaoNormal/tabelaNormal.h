#ifndef TABELANORMAL_H_INCLUDED
#define TABELANORMAL_H_INCLUDED

#include <stdbool.h>

#define QTD_COLUNA 10

#define CUMULATIVA_APARTIR_DA_MEDIA 0
#define CUMULATIVA                  1
#define CUMULATIVA_COMPLEMENTAR     2

#define ERRO false
#define SUCESSO true

#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

typedef struct {
    double ** tabela;
    int qtdCasasDecimais;
    int sigma;
    int tipoTabela;
    int qtd_linha;
} infoTabela;

double executaFuncaoTipoTabela(float, infoTabela);

/* Utilizacao do metodo de simpson 1/3 segundo o que foi estudado na disciplina
*  de Calculo Numerico.
*/
double distribuicaoNormal(double);

double function(double);

double arredonda(double, double);

bool isTipoTabelaValido(int);

char * getNomeTipoTabela(int);

double f(double x);

bool criaTabela (infoTabela *);

void apagaTabela (infoTabela);

bool alocaTabela(infoTabela *);

bool alocaLinhas(infoTabela *);

bool alocaColunas(infoTabela *);

bool alocaColuna(infoTabela *, int);

void inicializaTabela(infoTabela *);

infoTabela criaInfoTabela(int, int, int);

#endif // TABELANORMAL_H_INCLUDED
