/* redeSocial.c
 * Implementação das funções da Rede Social
 *
 * Rodrigo Suarez Moreira
 * Vitor Oliveira Kuribara
 * Victor Gabriel Martins e Souza
 * 09/10/2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "redeSocial.h"
#include "avl.h"
#include "listaord.h"

// As funções abaixo seguem suas definições solicitadas no trabalho   
void load_users(avl_tree * t, char * filename) {
    FILE * arq; // Arquivo lógico
    bool h;
    // Abertura do arquivo
    if ((arq = fopen(filename, "r")) == NULL) {
        fprintf(stderr, "Erro na abertura do arquivo %s\n", filename);
        exit(1);
    }

    char linha[1000], *token;
    const char separador[2] = ";";
    avl_info entrada;

    // leitura do arquivo
    while (fscanf(arq, " %[^\n]", linha) != EOF) {
        // Le nome do usuario
        token = strtok(linha, separador);
        strcpy(entrada.usuario, token);

        // Le nome completo
        token = strtok(NULL, separador);
        strcpy(entrada.nome_completo, token);

        // Le sexo
        token = strtok(NULL, separador);
        entrada.sexo = toupper(token[0]);

        lst_init(&entrada.amigos);
        lst_info entradaLista;

        char verificaSeListaAmigosEstaVazio = fgetc(arq);
        verificaSeListaAmigosEstaVazio = fgetc(arq);
        // Se ler  um caractere de final de linha quer dizer que nao tem nenhum amigo
        if(verificaSeListaAmigosEstaVazio != '\n') {
            fseek(arq, -1, SEEK_CUR);
            // Le lista de amigos
            if(fscanf(arq, " %[^\n]", linha) != EOF) {
                token = strtok(linha, separador);
                while(token != NULL) {
                    strcpy(entradaLista.usuario, token);
                    lst_ins(&entrada.amigos, entradaLista);

                    token = strtok(NULL, separador);
                }
            }
        }
        avl_search(t, entrada, &h);
    }
    fclose(arq);
}

bool add_new_user(avl_tree * t, avl_info x) {
    bool h;
    return x.amigos == NULL ? avl_search(t, x, &h) : false;
}

bool add_friend(avl_tree t, char * username, char * friendname) {
    bool existeAmigo = avl_find(t, friendname) != NULL ? true : false;
    t = avl_find(t, username);
    // Verifica se o nome do usuario e amigo sao diferente
    // E se o amigo existe
    // E se o usuario existe
    if(strcasecmp(username, friendname) != 0 && existeAmigo && t != NULL) {
        // Insere amigo na lista de amigos do usuario
        lst_info entrada;
        strcpy(entrada.usuario, friendname);
        lst_ins(&t->dado.amigos, entrada);
        return true;
    }
    return false;
}

void list_users(avl_tree t) {
    printf("\tUsuarios da rede social\n");
    print_tree(t);
}

bool list_friends(avl_tree t, char * username) {
    bool retorno = false;
    // Encontra no do usuario
    avl_tree usuario = avl_find(t, username);
    if(usuario != NULL) {
        if(usuario->dado.amigos != NULL) {
            printf("\n\tLista de amigos:\n");
            avl_tree amigo;
            // Itera lista ordenada encadeada
            while (usuario->dado.amigos != NULL) {
                // Encontra no do amigo
                amigo = avl_find(t, usuario->dado.amigos->dado.usuario);
                //Imprime informacoes do amigo
                print_info(amigo);

                usuario->dado.amigos = usuario->dado.amigos->prox;
            }
        }
        else
            printf("\nO usuario nao tem nenhum amigo");
        retorno = true;
    }
    // Nao encontrou o usuario
    return retorno;
}

bool remove_user(avl_tree * t, char * username) {
    avl_info usuario;
    strcpy(usuario.usuario, username);
    bool h;
    // Deletou usuario com sucesso
    if(delete_avl_no(t, &usuario, &h)) {
        lst_info entrada;
        strcpy(entrada.usuario, username);
        removeUsuarioDaListaDeAmigosDosUsuarios(*t, entrada);
        return true;
    }
    // Usuario nao existe
    return false;
}

void removeUsuarioDaListaDeAmigosDosUsuarios(avl_tree t, lst_info usuario) {
    if (t != NULL) {
        removeUsuarioDaListaDeAmigosDosUsuarios(t->esq, usuario);
        lst_rem(&t->dado.amigos, usuario);
        removeUsuarioDaListaDeAmigosDosUsuarios(t->dir, usuario);
    }
}

void save_users(avl_tree t) {
    FILE * arq; // Arquivo lógico
    // Abertura do arquivo
    if ((arq = fopen("database.txt", "w")) == NULL) {
        fprintf(stderr, "Erro na abertura do arquivo database.txt\n");
        exit(1);
    }
    save_tree(t, arq);
    fclose(arq);
}

