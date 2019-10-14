/*  Universidade Católica de Santos
*  1º Trabalho Prático - Rede Social
*  Estrutura de Dados II
*  Profº Ciro Cirne Trindade
*
*  Rodrigo Suarez Moreira
*  Vitor Oliveira Kuribara
*  Victor Gabriel Martins e Souza
*  09/10/2019
* 
* Implementação da interface (main)
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "redeSocial.h"
#include "avl.h"
#include "listaord.h"

/* As funções a seguir buscam implementar o que foi feito em redeSocial.h e redeSocial.c
*  por meio de uma interface para o usuário. Grande parte delas apenas exibem um menu, enquanto
*  outras leem a entrada do usuário (tentando evitar erros de digitação) para executar comandos ou apenas
*  como entradas de dados. O restante trata o retorno das funções de redeSocial.c (indicando falha
*  ou sucesso da operação) 
*/
void imprimeMenu();
void imprimeBorda();
void imprimeLogo();
void imprimeOpcoes();
void pulaLinha();
int leComando();
bool executaComando(int comando, avl_tree * banco);
char * leArquivo();
avl_info leUsuarioDoInput();
char * leUsuario();
char * leAmigo();
char leSexo();
void trataRetornoAdicionarNovoUSuario(bool retorno);
void trataRetornoAdicionarAmigo(bool retorno);
void trataRetornoListarAmigos(bool retorno);
void trataRetornoRemoverUsuario(bool retorno);

int main()
{
    avl_tree banco = NULL;
    load_users(&banco, "database.txt");
    while(executaComando(leComando(), &banco));
    return 0;
}

void imprimeMenu() {
    imprimeBorda();
    imprimeLogo();
    imprimeBorda();
    imprimeOpcoes();
    imprimeBorda();
}

void imprimeBorda() {
    printf("--------------------------------------------------------------\n");
}

void imprimeLogo() {
    printf("Bem vindo a Rede Social do Trabalho de Estrutura de Dados 2\n");
}

void imprimeOpcoes() {
    printf("Digite o comando desejado:\n");
    printf("\t0 -> Carregar usuarios\n");
    printf("\t1 -> Adicionar um novo usuario\n");
    printf("\t2 -> Adicionar um amigo\n");
    printf("\t3 -> Listar usuarios\n");
    printf("\t4 -> Listar amigos\n");
    printf("\t5 -> Remover usuario\n");
    printf("\t6 -> Finalizar o programa\n");
}

void pulaLinha() {
    printf("\n");
}

int leComando() {
    imprimeMenu();
    int comando;
    scanf("%d", &comando);
    imprimeBorda();
    pulaLinha();
    return comando;
}

bool executaComando(int comando, avl_tree * banco) {
        switch(comando) {
            case 0:
                load_users(banco, leArquivo());
                break;
            case 1:
                trataRetornoAdicionarNovoUSuario(add_new_user(banco, leUsuarioDoInput()));
                break;
            case 2:
                trataRetornoAdicionarAmigo(add_friend(*banco, leUsuario(), leAmigo()));
                break;
            case 3:
                list_users(*banco);
                break;
            case 4:
                trataRetornoListarAmigos(list_friends(*banco, leUsuario()));
                break;
            case 5:
                trataRetornoRemoverUsuario(remove_user(banco, leUsuario()));
                break;
            case 6:
                save_users(*banco);
                printf("Sessao encerrada!\n");
                return false;
            default:
                printf("Comando invalido\n");
        }
        pulaLinha();
        return true;
}

char * leArquivo() {
    char * entrada = malloc(sizeof (char) * 50);
    printf("Informe o nome do arquivo: ");
    scanf(" %[^\n]", entrada);
    return entrada;
}

avl_info leUsuarioDoInput() {
    avl_info entrada;
    printf("Informe o nome do usuario: ");
    scanf(" %[^\n]", entrada.usuario);
    printf("Informe o nome completo: ");
    scanf(" %[^\n]", entrada.nome_completo);
    entrada.sexo = leSexo();
    lst_init(&entrada.amigos);
    return entrada;
}


char leSexo() {
    char sexo;
    printf("Informe o sexo (M|F): ");
    scanf(" %c", &sexo);
    sexo = toupper(sexo);
    while(sexo != 'M' && sexo != 'F') {
        printf("Erro!\nInforme o sexo (M|F): ");
        scanf(" %c", &sexo);
        sexo = toupper(sexo);
    }
    return sexo;
}

void trataRetornoAdicionarNovoUSuario(bool retorno) {
    pulaLinha();
    if(retorno)
       printf("Usuario cadastrado com sucesso!\n");
    else
        printf("Erro ao cadastrar novo usuario!\n");
}

void trataRetornoAdicionarAmigo(bool retorno) {
    pulaLinha();
    if(retorno)
        printf("Amigo adicionado com sucesso!\n");
    else
        printf("Erro ao adicionar amigo!\n");
}

char * leUsuario() {
    char * entrada = malloc(sizeof (char) * 21);
    printf("Informe o nome do usuario: ");
    scanf(" %[^\n]", entrada);
    return entrada;
}

char * leAmigo() {
    char * entrada = malloc(sizeof (char) * 21);
    printf("Informe o nome do amigo: ");
    scanf(" %[^\n]", entrada);
    return entrada;
}

void trataRetornoListarAmigos(bool retorno) {
    pulaLinha();
    if(!retorno)
        printf("Erro ao listar amigos\n");
}

void trataRetornoRemoverUsuario(bool retorno) {
    pulaLinha();
    if(retorno)
        printf("Usuario removido com sucesso\n");
    else
        printf("Erro ao remover usuario\n");
}
