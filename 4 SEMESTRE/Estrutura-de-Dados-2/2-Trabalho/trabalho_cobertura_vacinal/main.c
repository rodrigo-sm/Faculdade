#include <stdio.h>
#include <stdlib.h>

#include "cobertura_vacinal.h"
#include "hashmap.h"
#include "avl.h"

#define SAIR 0
#define CONTINUAR 1

int executa_opcao(int, hash_map, avl_tree *);
void print_menu();
void print_logo();
void print_opcoes();
void print_logo_resultado();
int le_opcao();
int le_quantidade_de_municipios();
int le_codigo_municipio();
void exibe_n_municipios_com_maior_cobertura_vacinal(avl_tree, int);
void exibe_n_municipios_com_menor_cobertura_vacinal(avl_tree, int);

int main()
{
    hash_map map;
    avl_tree tree = NULL;

    load_dados_cobertura_vacinal(map, &tree);
    while(executa_opcao(le_opcao(), map, &tree));
    return 0;
}

int executa_opcao(int opcao, hash_map map, avl_tree * tree) {
    switch(opcao) {
        case 0:
            printf("Sessao encerrada\n");
            return SAIR;
        case 1:
            exibe_dados_cobertura_vacinal_pelo_codigo_municipio(map, le_codigo_municipio());
            break;
        case 2:
            exibe_n_municipios_com_maior_cobertura_vacinal(*tree, le_quantidade_de_municipios());
            break;
        case 3:
            exibe_n_municipios_com_menor_cobertura_vacinal(*tree, le_quantidade_de_municipios());
            break;
        default:
            printf("\nOpcao inexistente\n");
    }
    return CONTINUAR;
}

void print_menu() {
    print_logo();
    print_opcoes();
}

void print_logo() {
    printf("Bem vindo ao 2 Trabalho Pratico de Estrutura de Dados 2\n");
    printf("Pesquise dados sobre a cobertura vacinal de 5570 municipios brasileiros\n");
}

void print_opcoes() {
    printf("Opcoes:\n");
    printf("\t0 -> Sair\n");
    printf("\t1 -> Pesquisar a cobertura vacinal de um municipio atraves do seu respectivo codigo\n");
    printf("\t2 -> Exibir uma quantidade informada de cidades (codigo, nome e cobertura vacinal) com maior cobertura vacinal\n");
    printf("\t3 -> Exibir uma quantidade informada de cidades (codigo, nome e cobertura vacinal) com menor cobertura vacinal\n");
}

void print_logo_resultado() {
    printf("\n==============RESULTADO==============\n");
}

int le_opcao() {
    int retorno;
    printf("\n");
    print_menu();
    printf("Informe a opcao desejada: ");
    scanf(" %d", &retorno);
    printf("\n");
    return retorno;
}

int le_quantidade_de_municipios() {
    int retorno;
    printf("Informe a quantidade de municipios: ");
    scanf(" %d", &retorno);
    return retorno;
}

int le_codigo_municipio() {
    int retorno;
    printf("Informe o codigo do municipio: ");
    scanf(" %d", &retorno);
    return retorno;
}

void exibe_n_municipios_com_maior_cobertura_vacinal(avl_tree tree, int qtdMunicipios) {
    if(valida_quantidade_de_cidades(qtdMunicipios)) {
        print_logo_resultado();
        print_n_dados_ordenado_decrescente(tree, qtdMunicipios);
    }
}

void exibe_n_municipios_com_menor_cobertura_vacinal(avl_tree tree, int qtdMunicipios) {
    if(valida_quantidade_de_cidades(qtdMunicipios)) {
        print_logo_resultado();
        print_n_dados_ordenado_ascendente(tree, qtdMunicipios);
    }
}
