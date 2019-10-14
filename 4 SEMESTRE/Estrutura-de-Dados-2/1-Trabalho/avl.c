#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "avl.h"
#include "listaord.h"

/*Função que imprimirá na tela uma lista ordenada, recebendo como parametro uma arvore avl
* Esta parte da função é responsável pela recursão (fazendo o percurso ERD - Em ordem).
*/
void print_tree(avl_tree t) {
    if (t != NULL) {
        print_tree(t->esq);
        print_info(t);
        print_tree(t->dir);
    }
}
/* Função que imprimirá na tela uma lista ordenada, recebendo como parametro uma arvore avl
*  Esta parte será responsável pela impressão de fato.
*/
void print_info(avl_tree t) {
    printf("\nUsuario: %s\n", t->dado.usuario);
    printf("Nome completo: %s\n", t->dado.nome_completo);
    printf("Sexo: %c\n", t->dado.sexo);
    /* OBS.: Caso neccessário imprimir os amigos descomentar as linhas abaixo
    * printf("Amigos: ");
    * lst_print(t->dado.amigos);
    */
}

/* A função abaixo é responsável pelo armazenamento dos dados em arquivo, recebendo como
*  parametros uma arvore avl e um ponteiro de arquivo
*  
*/
void save_tree(avl_tree t, FILE * arq) {
    if (t != NULL) {
        save_tree(t->esq, arq);
        fprintf(arq, "%s;%s;%c\n", t->dado.usuario, t->dado.nome_completo, t->dado.sexo);
        if(t->dado.amigos != NULL)
            lst_save(t->dado.amigos, arq);
        else
            fprintf(arq, "\n");
        save_tree(t->dir, arq);
    }
}

/* Recebendo como parâmetros uma árvore avl e uma string (vetor de char), ela
*  verificará se a chave(usuário) pertence a estrutura, retornando um ponteiro 
*  com o nó correspondente caso encontre a chave. Se isto não ocorrer, ela
*  será chamada recursivamente para verificação em subarvores e caso encontre 
*  um nó folha e a função seja chamada (fazendo t == NULL), ela também retornará
*  NULL
*/
avl_tree avl_find(avl_tree t, char * chave) {
    // Nao encontrou no correspondente a chave
    if (t == NULL) return NULL;
    // Procura na subArvore Esquerda
    else if (strcasecmp(chave,t->dado.usuario) < 0) return avl_find(t->esq, chave);
    // Procura na subArvore direita
    else if (strcasecmp(chave,t->dado.usuario) > 0) return avl_find(t->dir, chave);
    // Encontrou no correspondente a chave
    else return t;
}
/* A função a seguir tem como parametros a árvore avl (sofrerá modificações), uma
*  estrutura com a informação do nó e um variável booleana que indica o crescimento 
*  de um ramo da árvore. O valor de retorno, será booleano e indicará se o nó foi encontrado
*  (true) ou não (false), e para ajustar a recursividade da função foi criada a
*  variável 'retorno'. Ela realizará na árvore uma busca do usuário solicitado, 
*  caso não encontre, este usuário será inserido na estrutura e retornará true,
*  -caso encontre(usuário já existente), ela retornará falso.
*/
bool avl_search(avl_tree * t, avl_info x, bool * h) {
    bool retorno;
    // Nao encontrou no correspondente ao avl_info entao insere
    if (*t == NULL) {
        if ((*t = (avl_tree) malloc(sizeof(struct avl_no))) == NULL) {
            fprintf(stderr, "Erro de alocacao de memoria!\n");
            exit(1);
        }
        *h = true;
        strcpy((*t)->dado.usuario,x.usuario);
        strcpy((*t)->dado.nome_completo,x.nome_completo);
        (*t)->dado.sexo = x.sexo;
        (*t)->dado.amigos = x.amigos;
        (*t)->esq = (*t)->dir = NULL;
        (*t)->bal = 0;
        return true;
    }
    else if (strcasecmp(x.usuario,(*t)->dado.usuario) < 0) { // Inserir a esquerda
        retorno = avl_search(&(*t)->esq, x, h);
        if (*h) { // O ramo esquerdo cresceu
            switch ((*t)->bal) {
                case 1: (*t)->bal = 0;
                        *h = false;
                        break;
                case 0: (*t)->bal = -1;
                        break;
                case -1:
                    // Rebalanceamento
                    if ((*t)->esq->bal == -1) { //Rotação simples p/ direita
                        rotacao_dir(t);
                        (*t)->dir->bal = 0; //Ajusta o fator de balanceamento
                    }
                    else { // Rotação dupla para direita
                        rotacao_esq(&(*t)->esq);
                        rotacao_dir(t);
                        // Ajusta o fator de balanceamento
                        if ((*t)->bal == -1) (*t)->dir->bal = 1;
                        else (*t)->dir->bal = 0;
                        if ((*t)->bal == 1) (*t)->esq->bal = -1;
                        else (*t)->esq->bal = 0;
                    }
                    *h = false;
                    (*t)->bal = 0;
                    break;
            } // fim do switch
        }
    } // fim do if
    else if (strcasecmp(x.usuario,(*t)->dado.usuario) > 0) { // Inserir a direita
        retorno = avl_search(&(*t)->dir, x, h);
        if (*h) { // O ramo direito cresceu
            switch ((*t)->bal) {
                case -1: (*t)->bal = 0;
                         *h = false;
                         break;
                case 0 : (*t)->bal = 1;
                         break;
                case 1: // Rebalanceamento
                    if ((*t)->dir->bal == 1) { // Rotação simples p/ esquerda
                        rotacao_esq(t);
                        // Ajusta o fator de balanceamento
                        (*t)->esq->bal = 0;
                    }
                    else { // Rotação dupla para esquerda
                        rotacao_dir(&(*t)->dir);
                        rotacao_esq(t);
                        // Ajusta o fator de balanceamento
                        if ((*t)->bal == 1) (*t)->esq->bal = -1;
                        else (*t)->esq->bal = 0;
                        if ((*t)->bal == -1) (*t)->dir->bal = 1;
                        else (*t)->dir->bal = 0;
                    } // fim do else
                    *h = false;
                    (*t)->bal = 0;
                    break;
            } // fim do switch
        }
    } // fim do if
    else // avl_info ja esta na arvore
        retorno = false;
    return retorno;
} // fim de avl_search

// Rotaçao para a esquerda
void rotacao_esq(avl_tree * t) {
    avl_tree p;
    p = (*t)->dir;
    (*t)->dir = p->esq;
    p->esq = *t;
    *t = p;
}

// Rotação para a direita
void rotacao_dir(avl_tree * t) {
    avl_tree p;
    p = (*t)->esq;
    (*t)->esq = p->dir;
    p->dir = *t;
    *t = p;
}

/* Recebe a árvore para modificação, a estrutura representando um nó, e uma variável
*  booleana sinalizando se a árvore fica pendendo para um lado. Esta função é responsável
*  por deletar um usuário (nó) solicitado e devolve o sucesso(true) ou fracasso(false).
*/
bool delete_avl_no(avl_tree * t, avl_info * x, bool * h) {
    avl_tree p;
    bool result;
    if (*t == NULL) // A chave não se encontra na árvore
        return false;
    else if (strcasecmp(x->usuario,(*t)->dado.usuario) == 0) { // a chave está neste nó
        p = *t;
        if ((*t)->esq == NULL) { // nó folha ou somente com subárvore direita
            *t = p->dir;
            *h = true;
        }
        else if ((*t)->dir == NULL) { // nó com uma única subárvore esquerda
            *t = p->esq;
            *h = true;
        }
        else { // nó com duas subávores
            p = get_min(&(*t)->dir, h);
            (*t)->dado = p->dado;
            if(*h) balance_dir(t, h);
        }

        x->amigos = p->dado.amigos;
        free(p);
        return true;
    }
    else if (strcasecmp(x->usuario,(*t)->dado.usuario) < 0) {
        result = delete_avl_no(&(*t)->esq, x, h);
        if (*h) balance_esq(t, h);
        return result;
    }
    else {
        result = delete_avl_no(&(*t)->dir, x, h);
        if (*h) balance_dir(t, h);
        return result;
    }
} // fim do delete

void balance_dir(avl_tree * t, bool * h) {
    avl_tree p1, p2;
    int b1, b2;

    switch ((*t)->bal) {
        case 1: (*t)->bal = 0;
                break;
        case 0: (*t)->bal = -1;
                *h = false;
                break;
        case -1: // rebalanceamento
                p1 = (*t)->esq;
                b1 = p1->bal;
                if (b1 <= 0) { // rotação simples
                    (*t)->esq = p1->dir;
                    p1->dir = *t;
                    if (b1 == 0) {
                        (*t)->bal = -1;
                        p1->bal = 1;
                        *h = false;
                    }
                    else {
                        (*t)->bal = 0;
                        p1->bal = 0;
                    }
                    *t = p1;
                }
                else { // rotação dupla
                    p2 = p1->dir;
                    b2 = p2->bal;
                    p1->dir = p2->esq;
                    p2->esq = p1;
                    p1->esq = p2->dir;
                    p2->dir = *t;
                    if(b2 == -1) (*t)->bal = 1;
                    else (*t)->bal = 0;
                    if(b2 == 1) p1->bal = -1;
                    else p1->bal = 0;
                    *t = p2;
                    p2->bal = 0;
                }
    } // fim do switch
}

void balance_esq(avl_tree * t, bool * h) {
    avl_tree p1, p2;
    int b1, b2;

    switch ((*t)->bal) {
        case -1: (*t)->bal = 0;
                 break;
        case 0: (*t)->bal = 1;
                *h = false;
                break;
        case 1: // rebalanceamento
                p1 = (*t)->dir;
                b1 = p1->bal;
                if (b1 >= 0) { // rotação simples
                    (*t)->dir = p1->esq;
                    p1->esq = *t;
                    if (b1 == 0) {
                        (*t)->bal = 1;
                        p1->bal = -1;
                        *h = false;
                    }
                    else {
                        (*t)->bal = 0;
                        p1->bal = 0;
                    }
                    *t = p1;
                }
                else { // rotação dupla
                    p2 = p1->esq;
                    b2 = p2->bal;
                    p1->esq = p2->dir;
                    p2->dir = p1;
                    p1->dir = p2->esq;
                    p2->esq = *t;
                    if (b2 == 1) (*t)->bal = -1;
                    else (*t)->bal = 0;
                    if (b2 == -1) p1->bal = 1;
                    else p1->bal = 0;
                    *t = p2;
                    p2->bal = 0;
                }
    } // fim do switch
}

avl_tree get_min(avl_tree * t, bool * h) {
    avl_tree q;
    if ((*t)->esq != NULL) {
        q = get_min(&((*t)->esq),h);
        if (*h) balance_esq(t, h);
        return q;
    }
    else {
        *h = true;
        q = *t;
        *t = (*t)->dir;
        return q;
    }
}
