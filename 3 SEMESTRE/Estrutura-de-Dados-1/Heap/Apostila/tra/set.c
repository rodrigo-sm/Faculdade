/*
 * set.c
 * Implementação das operações realizadas sobre um set (Conjunto)
 * de números inteiros.
 *
 * Arthur Silveira Chaves (Sistemas de Informação)
 *
 * Disciplina: Estrutura de Dados-I
 *
 * 02/04/2019
 */
#include "set.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void set_init(set * c)
{
    c->n=-1;
}

bool set_isempty(set c)
{
    return (c.n==-1);
}

bool set_isfull(set c)
{
    return (c.n==SET_MAX-1);
}

bool set_member(set c, set_info val)
{
    int i;
    for(i=0; i <= c.n; i++)//Percorre o Set todo para ver se tem elemento igual.
    {
        if (val == c.itens[i])//Caso tenha devolve true, caso contrário false.
            return true;
    }
    return false;
}

bool set_insert(set * c, set_info val)
{
    if(!set_isfull(*c))//Verifica se o Set está cheio.
    {
        if(!set_member(*c,val))//Verifica se o valor a ser inserido já está dentro do set.
        {
            c->itens[++c->n]=val;//Coloca o valor no Set, Aumenta o tamanho do Set e devolve true.
            return true;
        }
        else
            return false;
    }
    else
        return false;
}

bool set_remove(set * c, set_info val)
{
    if(set_member(*c,val))
    {
        int i,j;
        for(i=0;i<c->n;i++)//Percorre o Set até achar o elemento desejado.
        {
            if(c->itens[i]==val)
                break;
        }
        for(j=i+1;j<c->n;j++)//Usa o indice de i e vai pegando tudo que tenha na frente e jogando para trás.
        {
            c->itens[j-1]=c->itens[j];
        }
        c->n--;//Decrementa o tamanho do Set.
        return true;
    }
    return false;
}

bool set_union(set c, set c2, set * c3)
{
    if (c.n+c2.n<=SET_MAX)
    {
        set_init(c3);//Inicializa o 3º Set.
        int i,j,k;
        for(i=0;i<c.n;i++)//Joga todos os itens do primeiro Set para o terceiro e aumentando o tamanho.
        {
            c3->itens[i]=c.itens[i];
            c3->n++;
        }
        for(j=i,k=0;k<c2.n;k++,j++)
        {
            c3->itens[j]=c2.itens[k];
            c3->n++;
        }
        return true;
    }
    else
        return false;
}
void set_intersection(set c, set c2, set * c3)
{
    set_init(c3);//Inicializa o 3º Set.
    int i;
    for(i=0;i<c.n;i++)//Percorre o Set todo para ver se o item está contido.
    {
        if(set_member(c2,c.itens[i])){   //Caso o item do primeiro Set esteja contido no segundo Set
            c3->itens[i]=c.itens[i];     //irá passar este item para o terceiro Set e aumentar o tamanho
            c3->n++;                     //do Set.
        }
    }
}
bool set_difference(set c, set c2, set * c3)
{
    set_init(c3);//Inicializa o 3º Set.
    int i,j,k;
    for(i=0;i<c.n;i++)//Percorre o primeiro Set todo ver se o item está contido.
    {
        if(!set_member(c2,c.itens[i])){//Caso o item do primeiro Set não esteja contido no segundo
            c3->itens[i]=c.itens[i];   //ele é passado para o terceiro Set
            c3->n++;
        }
    }
    for(j=i,k=0;k<c2.n;j++,k++)//Percorre o segundo Set todo para ver se o item está contido.
    {
        if(!set_member(c,c2.itens[k])){
            c3->itens[j]=c2.itens[k];//Caso o item do segundo Set não esteja contido no primeiro
            c3->n++;                 //ele é passado para o terceiro Set
        }
    }
}
void set_print(set c)
{
    int i;
    printf("[ ");
    for(i=0; i<c.n; i++)
        printf("%d, ",c.itens[i]);//Imprime todo o Set percorrido.
    printf("\b ]\n");
}
