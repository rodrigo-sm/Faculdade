/* redeSocial.h
 * Definicao dos metodos da Rede Social
 *
 * Rodrigo Suarez Moreira
 * Vitor Oliveira Kuribara
 * Victor Gabriel Martins e Souza
 * 09/10/2019
 */

#ifndef REDESOCIAL_H_INCLUDED
#define REDESOCIAL_H_INCLUDED

#include "avl.h"

/*
 * Carrega usuarios salvos em um arquivo .txt para a rede social
 * Parametros:

 * - Arvore avl onde esta salva os dados da rede social
 * - Nome do arquivo .txt onde esta salvo os usuarios
 */
void load_users(avl_tree * t, char * filename);



/*
 * Adiciona um usuario á rede social
 * Parametros:
 * -  Arvore AVL onde esta salva os dados da rede social
 * -  Dados do usuario a ser inserido
 */
bool add_new_user(avl_tree * t, avl_info x);

/*
 * Adiciona um amigo no usuario
 * Parametros:
 * - Arvore onde esta salva os dados da rede social
 * - Nome de usuario do amigo
 * - Nome de usuario do usuario
 */
bool add_friend(avl_tree t, char * username, char * friendname);


void removeUsuarioDaListaDeAmigosDosUsuarios(avl_tree t, lst_info usuario);

/*
 * Exibe os usuarios da rede social e suas respectivas informacoes
 * Parametros:
 * - Arvore AVL onde esta salva os dados da rede social
 */
void list_users(avl_tree t);

/*
 * Lista os amigos de um usuario e suas respectivas informacoes
 * Parametros:
 * - Arvore onde esta salva os dados da rede social
 * - Nome do usuario
 */
bool list_friends(avl_tree t, char * username);

/*
 * Remover usuario da rede social
 * Parametros:
 * - Arvore AVL onde esta salva os dados da rede social
 * - Nome do usuario
 */
bool remove_user(avl_tree * t, char * username);

/*
 * Salva os usuarios da rede social em arquivo .txt
 * Parametros:
 * - Arvore AVL onde esta salvo os dados da rede social
 */
void save_users(avl_tree t);


#endif // REDESOCIAL_H_INCLUDED
