#ifndef INTERFACEHELPER_H_INCLUDED
#define INTERFACEHELPER_H_INCLUDED

#include <stdbool.h>

#define ERRO false
#define SUCESSO true

void limpaTela();

void pausaTela();

int leInteiro();

double leDouble();

char * leNome();

void imprimeAlertaSimples(char *);

void imprimeMensagemSimples(char *);

void imprimeTracadoMensagemSimples(int);

void imprimeTracadoSimples(int);

void pulaLinha();

bool leSimOuNao();

#endif // INTERFACEHELPER_H_INCLUDED
