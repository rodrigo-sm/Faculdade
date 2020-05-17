/*
*   Algoritmo para Identificação e Remoção de
*   Variáveis Inúteis
*
*   Disciplina: Linguagens Formais e Autômatos I
*   Professor: Jefferson Perez Rodrigues Costa
*
*   Membros:
*   Rodrigo Moreira
*   Victor Gabriel
*   Vitor Oliveira
*   Universidade Católica de Santos - 13/05/2020
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANHO 20

void achar_variaveis_geradoras(char[TAMANHO][TAMANHO], char[TAMANHO], char[TAMANHO]);
void achar_variaveis_nao_geradoras(char P[TAMANHO][TAMANHO], char Vn[TAMANHO], char [TAMANHO]);
void achar_variaveis_alcancaveis(char, char[TAMANHO][TAMANHO], char[TAMANHO], char[TAMANHO]);
void achar_variaveis_nao_alcancaveis(char, char[TAMANHO][TAMANHO], char[TAMANHO], char[TAMANHO]);
void achar_variaveis_uteis(char, char[TAMANHO][TAMANHO], char[TAMANHO], char[TAMANHO]);
void achar_variaveis_inuteis(char, char[TAMANHO][TAMANHO], char[TAMANHO], char[TAMANHO]);
void remover_variaveis_inuteis(char, char[TAMANHO][TAMANHO], char[TAMANHO], char[TAMANHO]);
int imprimir_menu();
bool isTerminal(char*);
bool isNaoTerminal(char );
bool contemLadoDireito(char *, char *);
bool isStringContemAlgumCharDaSubstring(char*, char*);
void imprimirCabecalho(char*, char*, char, char[TAMANHO][TAMANHO]);
int zeraVetor(int*);

int main()
{
    char Vn[] = "SABC";
    char Vt[] = "ab";
    char S = 'S';
    char P[TAMANHO][TAMANHO] = { "SaS", "SA", "SC", "Aa", "Baa", "CaCb"};

    imprimirCabecalho(Vn, Vt, S, P);

    int op;

    while(1) {
        char entrada[TAMANHO];
        op = imprimir_menu();

        switch (op) {

            case 1:
                achar_variaveis_geradoras(P, Vn, entrada);
                printf("Variaveis geradoras: %s\n", entrada);
                break;
            case 2:
                achar_variaveis_nao_geradoras(P, Vn, entrada);
                printf("Variaveis nao geradoras: %s\n", entrada);
                break;
            case 3:
                achar_variaveis_alcancaveis(S, P, Vn, entrada);
                printf("Variaveis alcancaveis: %s\n", entrada);
                break;
            case 4:
                achar_variaveis_nao_alcancaveis(S, P, Vn, entrada);
                printf("Variaveis nao alcancaveis: %s\n", entrada);
                break;
            case 5:
                achar_variaveis_uteis(S, P, Vn, entrada);
                printf("Variaveis uteis: %s\n", entrada);
                break;
            case 6:
                achar_variaveis_inuteis(S, P, Vn, entrada);
                printf("Variaveis inuteis: %s\n", entrada);
                break;
            case 7:
                remover_variaveis_inuteis(S, P, Vn, Vt);
                break;
            default:
                printf("Xau :)\n");
                return 0;
        }

    }
    return 0;
}

void imprimirCabecalho(char * Vn, char * Vt, char S, char P[TAMANHO][TAMANHO]) {
    printf("Participantes:\n");
    printf("Rodrigo Suarez\n");
    printf("Victor Gabriel\n");
    printf("Vitor Oliveira\n");

    printf("\nProblema:\n");
    printf("Vn = %s\n", Vn);
    printf("Vt = %s\n", Vt);
    printf("S = %c\n", S);
    int x;
    printf("P = {%s", P[0]);
    for(x = 1; x < 6; x++) {
        printf(",%s", P[x]);
    }
    printf("}\n");
}


int imprimir_menu()
{
    int op;

    printf("\nEscolha uma opcao:\n\n");
    printf("1 - Identificar variaveis geradoras;\n");
    printf("2 - Identificar variaveis nao geradoras;\n");
    printf("3 - Identificar variaveis alcancaveis;\n");
    printf("4 - Identificar variaveis nao alcancaveis;\n");
    printf("5 - Identificar variaveis uteis;\n");
    printf("6 - Identificar variaveis inuteis;\n");
    printf("7 - Remover variaveis inuteis;\n");
    printf("8 - Encerrar programa.\n");
    printf("\nEscolha: ");
    scanf("%d", &op);
    printf("\n");
    return op;
}

bool isTerminal(char * palavra) {
    int x;
    for(x = 1; x < strlen(palavra); x++) {
        if(isNaoTerminal(palavra[x]))
            return false;
    }
    return true;
}

bool isNaoTerminal(char caractere) {
    return caractere >= 'A' && caractere <= 'Z';
}

void achar_variaveis_geradoras(char P[TAMANHO][TAMANHO], char Vn[TAMANHO], char Ug[TAMANHO]) {
    int x,y,p = 0;
    bool adicionou = false;
    int flags[TAMANHO];
    zeraVetor(flags);

    for(int x = 0; x < TAMANHO; x++) {
        char primeiroCaractere = P[x][0];
        if(isTerminal(P[x]) && strchr(Ug, primeiroCaractere) == NULL) {
            Ug[p++] = primeiroCaractere;
            flags[x] = 1;
        }
    }

    do {
        adicionou = false;
        for(int x = 0; x < TAMANHO; x++) {
            char primeiroCaractere = P[x][0];
            if(flags[x] == 0 && contemLadoDireito(P[x], Ug) && strchr(Ug, primeiroCaractere) == NULL) {
                Ug[p++] = primeiroCaractere;
                adicionou = true;
            }
        }

    }while(adicionou);
    Ug[p] = '\0';
}

int zeraVetor(int * vetor) {
    int i;
    for(i = 0; i < TAMANHO; i++)  {
        vetor[i] = 0;
    }
}

bool contemLadoDireito(char * ladoDireito, char * unidades) {
    int i;
    for(int i = 1; i < strlen(ladoDireito); i++) {
        if(strchr(unidades, ladoDireito[i]) != NULL) {
            return true;
        }
    }
    return false;

}

void achar_variaveis_nao_geradoras(char P[TAMANHO][TAMANHO], char Vn[TAMANHO], char Ung[TAMANHO]) {
    char Ug[TAMANHO];
    achar_variaveis_geradoras(P, Vn, Ug);
    int x, y = 0;
    for(int x = 0; x < TAMANHO; x++) {
        char ladoEsquerdo = P[x][0];
        if(strchr(Ug, ladoEsquerdo) == NULL && strchr(Ung, ladoEsquerdo) == NULL) {
            Ung[y++] = ladoEsquerdo;
        }
    }
    Ung[y] = '\0';
}

void achar_variaveis_alcancaveis(char S, char P[TAMANHO][TAMANHO], char Vn[TAMANHO], char Ua[TAMANHO])
{
    Ua[0] = S;
    int flags[TAMANHO], x, y, p = 1;
    for(int x = 0; x < TAMANHO; x++) {
        flags[x] = 0;
    }
    bool adicionou;

    do {
        adicionou = false;

        for(x = 0; x < TAMANHO; x++) {
            int ladoEsquerdo = P[x][0];
            if(flags[x] == 0 && strchr(Ua, ladoEsquerdo) != NULL) {
                flags[x] = 1;
                adicionou = true;
                for(y = 1; y < strlen(P[x]); y++) {
                    if(isNaoTerminal(P[x][y]) && strchr(Ua, P[x][y]) == NULL) {
                        Ua[p++] = P[x][y];
                    }
                }
            }
        }
    }while(adicionou);

    Ua[p] = '\0';
}

void achar_variaveis_nao_alcancaveis(char S, char P[TAMANHO][TAMANHO], char Vn[TAMANHO], char Una[TAMANHO]) {
    char Ua[TAMANHO];
    achar_variaveis_alcancaveis(S, P, Vn, Ua);
    int x, y = 0;

    for(x = 0; x < TAMANHO; x++) {
        char ladoEsquerdo = P[x][0];
        if(strchr(Ua, ladoEsquerdo) == NULL && strchr(Una, ladoEsquerdo) == NULL) {
            Una[y++] = ladoEsquerdo;
        }
    }
    Una[y] = '\0';
}



void achar_variaveis_uteis(char S, char P[TAMANHO][TAMANHO], char Vn[TAMANHO], char Uu[TAMANHO]) {
    char Ua[TAMANHO];
    achar_variaveis_alcancaveis(S, P, Vn, Ua);
    char Ug[TAMANHO];
    achar_variaveis_geradoras(P, Vn, Ug);
    int x, y = 0;

    for(x = 0; x < TAMANHO; x++) {
        char ladoEsquerdo = P[x][0];
        if(strchr(Ua, ladoEsquerdo) != NULL && strchr(Ug, ladoEsquerdo) != NULL && strchr(Uu, ladoEsquerdo) == NULL) {
            Uu[y++] = ladoEsquerdo;
        }
    }
    Uu[y] = '\0';

}

void achar_variaveis_inuteis(char S, char P[TAMANHO][TAMANHO], char Vn[TAMANHO], char Ui[TAMANHO]) {
    char Uu[TAMANHO];
    achar_variaveis_uteis(S, P, Vn, Uu);
    int x, y = 0;

    for( x = 0; x < TAMANHO; x++) {
        char ladoEsquerdo = P[x][0];
        if(strchr(Uu, ladoEsquerdo) == NULL && strchr(Ui, ladoEsquerdo) == NULL) {
            Ui[y++] = ladoEsquerdo;
        }
    }
    Ui[y] = '\0';
}

bool isStringContemAlgumCharDaSubstring(char * string, char * substring) {
    int i;
    for(i = 0; i < strlen(substring); i++) {
        if(strchr(string, substring[i]) != NULL) {
            return true;
        }
    }
    return false;
}

void remover_variaveis_inuteis(char S, char P[TAMANHO][TAMANHO], char Vn[TAMANHO], char Vt[TAMANHO]) {
    char Ung[TAMANHO];
    achar_variaveis_nao_geradoras(P, Vn, Ung);

    int x, y = 0;
    char PSemGeradoras[TAMANHO][TAMANHO];

    for(x = 0; x < TAMANHO; x++) {
        char ladoEsquerdo = P[x][0];
        if(strlen(P[x]) > 0 && !isStringContemAlgumCharDaSubstring(P[x], Ung)) {
            strcpy(PSemGeradoras[y++], P[x]);
        }

    }

    char Una[TAMANHO];
    achar_variaveis_nao_alcancaveis(S, PSemGeradoras, Vn, Una);

    char PSemInuteis[TAMANHO][TAMANHO];
    y=0;

    for(x = 0; x < TAMANHO; x++) {
        char ladoEsquerdo = PSemGeradoras[x][0];
        if(strchr(Una, ladoEsquerdo) == NULL) {
            strcpy(PSemInuteis[y], PSemGeradoras[x]);
            PSemInuteis[y][strlen(PSemInuteis[y])] = '\0';
            y++;
        }

    }

    printf("Gramatica sem variaveis inuteis:  {%s", PSemInuteis[0]);
    for(x = 1; x < y; x++) {
        printf(",%s", PSemInuteis[x]);
    }
    printf("}\n");
}



