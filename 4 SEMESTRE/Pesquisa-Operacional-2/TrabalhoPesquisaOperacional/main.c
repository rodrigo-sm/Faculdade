/*
*  Autores:
*
*  Vitor Kuribara
*  Rodrigo Moreira
*  Victor Gabriel
*
*  Pesquisa Operacional II - Prof. Jose Fontebasso Neto
*
*  Universidade Catolica de Santos - 21/11/2019
*
*/

#include "infoProblemaTransporte.h"
#include "leituraProblemaTransporte.h"
#include "otimizacao.h"

int main()
{
    otimizacao(leInfoProblemaTransporte());
    return 0;
}
