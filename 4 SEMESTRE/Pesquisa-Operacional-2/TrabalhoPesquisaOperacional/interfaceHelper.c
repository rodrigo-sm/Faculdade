#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#include "interfaceHelper.h"

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

int leInteiro() {
    int retorno;
    scanf(" %d", &retorno);
    return retorno;
}

void imprimeMensagemSimples(char * mensagem) {
    int tamanho = strlen(mensagem)+2;
    imprimeTracadoMensagemSimples(tamanho);
    printf("| %s |\n", mensagem);
    imprimeTracadoMensagemSimples(tamanho);
}

void imprimeAlertaSimples(char * mensagem) {
    imprimeMensagemSimples(mensagem);
    pausaTela();
    limpaTela();
}

void imprimeTracadoMensagemSimples(int tamanho) {
    printf("+");
    while(tamanho--)
        printf("=");
    printf("+\n");
}

void imprimeTracadoSimples(int tamanhoLinha) {
    printf("+");
    while(tamanhoLinha--)
        printf("-");
    printf("+\n");
}

void pulaLinha() {
    printf("\n");
}

bool leSimOuNao() {
    char opcao;
    scanf(" %c", &opcao);
    return tolower(opcao) == 's';
}
