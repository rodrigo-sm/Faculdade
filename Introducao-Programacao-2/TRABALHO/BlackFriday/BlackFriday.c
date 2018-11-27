/*
 * BlackFriday.c
 *
 * Sistema que armazena cadastros de produtos,lojas e preços de determinado produto em uma determinada loja
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 * Beatriz Jonas Justino (Sistema da Informação)
 * Arthur Silveira Chaves (Sistema da Informação)
 *
 * Disciplina: Introdução a Computação-II
 *
 * 27/11/2018
 */

#include <stdio.h>
#include <string.h>

// Definição dos Nomes dos Arquivos
#define ARQ_PROD "produtos.bin"
#define ARQ_LOJA "lojas.bin"
#define ARQ_PRECO "precos.bin"

// Definição das Estruturas
typedef struct
{
    int cod;
    char descricao[51];
} tproduto;

typedef struct
{
    int cod;
    char nome[41];
    char site[81];
} tloja;

typedef struct
{
    int cod_produto;
    int cod_loja;
    float preco;
} tpreco;

// Definição das funções
void ordena_prod(tproduto *, int);
void cadastrar_prod(void);
void alterar_prod(void);
void lista_prod(void);
void ordena_loja(tloja *, int);
void cadastrar_loja(void);
void lista_loja(void);
void cadastrar_preco(void);
void ordena_preco(tpreco *, int, tloja *);
void cadastrar_preco(void);
void lista_preco(void);
void consulta_prod(void);

int main()
{
    int n;
    while(1)
    {
        fprintf(stdout, "Menu:\n 1 - Cadastrar produto\n 2 - Alterar produto\n 3 - Listar todos os produtos\n 4 - Cadastrar loja\n 5 - Lista todas as lojas\n 6 - Cadastrar preco\n 7 - Listar todos os precos\n 8 - Consultar todos os precos de um produto\n 0 - Sair\n>>>> ");
        fscanf(stdin, " %d", &n);
        switch(n)
        {
        case 0:
            fprintf(stdout, "\nBye :)\n");
            return 0;
        case 1:
            cadastrar_prod();
            break;
        case 2:
            alterar_prod();
            break;
        case 3:
            lista_prod();
            break;
        case 4:
            cadastrar_loja();
            break;
        case 5:
            lista_loja();
            break;
        case 6:
            cadastrar_preco();
            break;
        case 7:
            lista_preco();
            break;
        case 8:
            consulta_prod();
            break;

        default:
            fprintf(stderr, "Erro: Opcao invalida\n");
        }
        fprintf(stdout, "\n");
    }
}

/* Função ordena um vetor da struct tproduto usando o algoritmo de ordenação bubblesort */
void ordena_prod(tproduto * prod, int tam)
{
    int i, j;
    tproduto aux;
    for(i = 0; i < tam; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            // A função strcmp devolve um numero > 0, caso encontre um caractere na string1 maior que na string2, assim ordenando de forma alfabetica
            if(strcmp(prod[i].descricao, prod[j].descricao) > 0)
            {
                aux = prod[i];
                prod[i] = prod[j];
                prod[j] = aux;
            }
        }
    }
}

/* Função que cadastra um ou mais produto no arquivo "produtos.bin" */
void cadastrar_prod()
{
    char ch;
    FILE *p;
    tproduto prod;
    if((p = fopen(ARQ_PROD, "ab")) == NULL)
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo %s\n", ARQ_PROD);
    else
    {
        do
        {
            // Coloca o ponteiro p no final do arquivo
            fseek(p, 0, SEEK_END);
            // Determina  o codigo do produto de forma sequencial, dividindo o valor atual do ponteiro pelo tamanho da struct tproduto + 1
            prod.cod = ftell(p) / sizeof(tproduto) + 1;
            fprintf(stdout, "\nInforme o produto:\n>>>> ");
            fscanf(stdin, " %[^\n]", prod.descricao);
            fwrite(&prod, sizeof(tproduto), 1, p);
            fprintf(stdout, "\nDeseja cadastrar outro produto? (s | n)\n>>>> ");
            fscanf(stdin, " %c", &ch);
        } while(ch == 's');
        fclose(p);
    }
}

/* Função altera um ou mais produto(s) cadastrado(s) no arquivo "produtos.bin" */
void alterar_prod()
{
    FILE *p;
    if((p = fopen(ARQ_PROD, "r+b")) == NULL)
        fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_PROD);
    else
    {
        // Coloca o ponteiro p no final do arquivo
        fseek(p, 0, SEEK_END);
        // Determina o ultimo codigo do produto de forma sequencial, dividindo o valor atual do ponteiro pelo tamanho da struct tproduto + 1
        int id_max = ftell(p) / sizeof(tproduto) + 1;
        char ch;
        tproduto prod;
        do
        {
            fprintf(stdout, "\nInforme o codigo do produto a ser alterado:\n>>>> ");
            fscanf(stdin, " %d", &prod.cod);
            // Caso o codigo informado seja menor ou igual que o id_max que armazena o ultimo codigo do produto, ele é valido
            if(prod.cod > id_max)
                fprintf(stderr, "\nErro: Nao existe produto com o codigo %d\n", prod.cod);
            else
            {
                fprintf(stdout, "\nInforme o novo produto:\n>>>> ");
                fscanf(stdin, " %[^\n]", prod.descricao);
                /* Coloca o ponteiro p aonde a estrutura do codigo está armazenado */
                fseek(p, (prod.cod - 1) * sizeof(tproduto), SEEK_SET);
                fwrite(&prod, sizeof(tproduto), 1, p);
            }
            fprintf(stdout, "\nDeseja fazer outra alteracao? (s | n)\n>>>> ");
            fscanf(stdin," %c", &ch);
        } while(ch == 's');
        fclose(p);
    }
}

/* Função que lista todos os produtos cadastrados do arquivo "produtos.bin" */
void lista_prod()
{
    FILE *p;
    if((p = fopen(ARQ_PROD, "rb")) == NULL)
        fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_PROD);
    else
    {
        // Coloca o ponteiro p no final do arquivo
        fseek(p, 0, SEEK_END);
        // Determina o tamanho do vetor a ser criado com base no ultimo codigo do produto de forma sequencial, dividindo o valor atual do ponteiro pelo tamanho da struct tproduto + 1
        int i, tam = (ftell(p) / sizeof(tproduto) + 1) - 1;
        // Cria um vetor de struct tproduto com a quantidade de elementos igual a quantidade de structs no arquivo
        tproduto prod[tam];
        // Coloca o ponteiro no inicio
        fseek(p, 0, SEEK_SET);
        // Lê as structs do tproduto do arquivo
        fread(prod, sizeof(tproduto), tam, p);
        fclose(p);
        // Ordena o vetor utilizando bubblesort
        ordena_prod(prod, tam);
        fprintf(stdout, "\n======================================\n");
        fprintf(stdout, "             Produtos\n");
        fprintf(stdout, "======================================\n");
        for(i = 0; i < tam; i++)
            fprintf(stdout, "Cod: %d | Prod: %s\n", prod[i].cod, prod[i].descricao);
        fprintf(stdout, "======================================\n");
    }
}

/* Função ordena um vetor da struct tproduto usando o algoritmo de ordenação bubblesort */
void ordena_loja(tloja *loja, int tam)
{
    int i, j;
    tloja aux;
    for(i = 1; i < tam; i++)
    {
        for(j = i + 1; j < tam; j++)
        {
            // A função strcmp devolve um numero > 0, caso encontre um caractere na string1 maior que na string2, assim ordenando de forma alfabetica
            if(strcmp(loja[i].nome, loja[j].nome) > 0)
            {
                aux = loja[i];
                loja[i] = loja[j];
                loja[j] = aux;
            }
        }
    }
}

/* Função que cadastra uma ou mais lojas no arquivo "lojas.bin" */
void cadastrar_loja()
{
    FILE *p;
    if((p = fopen(ARQ_LOJA, "ab")) == NULL)
        fprintf(stderr, "\nErro: Nao possivel abrir o arquivo %s\n", ARQ_LOJA);
    else
    {
        tloja loja;
        char ch;
        do
        {
            // Coloca o ponteiro p no final do arquivo
            fseek(p, 0, SEEK_END);
            // Determina o ultimo codigo da loja de forma sequencial, dividindo o valor atual do ponteiro pelo tamanho da struct tloja + 1
            loja.cod = ftell(p) / sizeof(tloja) + 1;
            fprintf(stdout, "\nInforme o nome da loja:\n>>>> ");
            fscanf(stdin, " %[^\n]", loja.nome);
            fprintf(stdout, "Informe o nome do site:\n>>>> ");
            fscanf(stdin, " %[^\n]", loja.site);
            fwrite(&loja, sizeof(tloja), 1, p);
            fprintf(stdout, "\nDeseja cadastrar outra loja? (s | n)\n>>>> ");
            fscanf(stdin, " %c", &ch);
        } while(ch == 's');
        fclose(p);
    }
}

/* Função que lista todas as lojas cadastradas no arquivo "lojas.bin" */
void lista_loja()
{
    FILE *p;
    if((p = fopen(ARQ_LOJA, "rb")) == NULL)
        fprintf(stderr, "\nErro: Nao possivel abrir o arquivo %s\n", ARQ_LOJA);
    else
    {
        // Coloca o ponteiro p no final do arquivo
        fseek(p, 0, SEEK_END);
        // Determina o tamanho do vetor a ser criado com base no ultimo codigo da loja de forma sequencial, dividindo o valor atual do ponteiro pelo tamanho da struct tloja + 1
        int tam = (ftell(p) / sizeof(tloja) + 1) - 1, i;
        // Coloca o ponteiro p no inicio do arquivo
        fseek(p, 0, SEEK_SET);
        // Cria o vetor struct com a quantidade de elemntos igual a quantidade de structs tloja no arquivo "lojas.bin"
        tloja loja[tam];
        // Lê todas as structs armazenadas no arquivo "lojas.bin"
        fread(&loja, sizeof(tloja), tam, p);
        fclose(p);
        // Ordena o vetor de struct tloja utilizando BubbleSort
        ordena_loja(loja, tam);
        fprintf(stdout, "\n\n======================================\n");
        fprintf(stdout, "             Lojas\n");
        fprintf(stdout, "======================================\n");
        for(i = 0; i < tam; i++)
            fprintf(stdout, "Cod: %d | Loja: %s | Site: %s\n", loja[i].cod, loja[i].nome, loja[i].site);
        fprintf(stdout, "======================================\n");
    }
}

/* Função que cadastra preço de um produto em uma determinada loja no arquivo "precos.bin", nao aceitando preços repetidos de produtos em uma mesma loja */
void cadastrar_preco()
{
    tpreco preco;
    char ch;
    int cod_max;
    FILE *p;
    do {
        fprintf(stdout, "\nInforme o codigo do produto:\n>>>> ");
        fscanf(stdin, " %d", &preco.cod_produto);
        if((p = fopen(ARQ_PROD, "rb")) == NULL)
            fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_PROD);
        else
        {
            // Coloca o ponteiro p no final do arquivo "produtos.bin"
            fseek(p, 0, SEEK_END);
            // Determina o ultimo codigo sequencial do arquivo "produtos.bin", dividindo o atual valor do ponteiro p pelo tamanho da struct tproduto + 1
            cod_max = ftell(p) / sizeof(tproduto) + 1;
            // Caso  o codigo do produto informado seja menor ou igual ao ultimo codigo do produto, o codigo informado é valido
            if(preco.cod_produto > cod_max)
                fprintf(stderr, "\nErro: Nao existe nenhuma produto com o codigo %d\n", preco.cod_produto);
            else
            {
                fclose(p);
                fprintf(stdout, "\nInforme o codigo da loja:\n>>>> ");
                fscanf(stdin, " %d", &preco.cod_loja);
                if((p = fopen(ARQ_LOJA, "rb")) == NULL)
                    fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_LOJA);
                else
                {
                    // Coloca o ponteiro p no final do arquivo "lojas.bin"
                    fseek(p, 0, SEEK_END);
                    // Determina o ultimo codigo sequencial do arquivo "lojas.bin", dividindo o atual valor do ponteiro p pelo tamanho da struct tloja + 1
                    cod_max = ftell(p) / sizeof(tloja) + 1;
                    // Caso  o codigo da loja informado seja menor ou igual ao ultimo codigo da loja, o codigo informado é valido
                    if(preco.cod_loja > cod_max)
                        fprintf(stderr, "\nErro: Nao existe nenhuma loja com o codigo %d\n", preco.cod_loja);
                    else
                    {
                        fclose(p);
                        if((p = fopen(ARQ_PRECO, "a+b")) == NULL)
                            fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_PRECO);
                        else
                        {
                            int r = 0;
                            tpreco verifica;
                            // Verifica se ja existe um preço para o produto informado na loja informada
                            while(fread(&verifica, sizeof(tpreco), 1, p) > 0)
                            {
                                if(verifica.cod_produto == preco.cod_produto && verifica.cod_loja == preco.cod_loja)
                                    r = 1;
                            }
                            if(r)
                            {
                                fprintf(stderr, "\nErro: Preco ja foi cadastrado\n");
                                fclose(p);
                            }
                            else
                            {
                                fprintf(stdout, "\nInforme o preco do produto:\n>>>> ");
                                fscanf(stdin, " %f", &preco.preco);
                                fwrite(&preco, sizeof(tpreco), 1, p);
                                fclose(p);
                            }
                        }
                    }
                }
            }
        }
        fprintf(stdout, "\nQuer cadastrar outro preco? (s | n)\n>>>> ");
        fscanf(stdin, " %c", &ch);
    } while(ch == 's');
}

/* Função que lista todos os preços do arquivo "preços.bin" */
void lista_preco()
{
    FILE *p;
    if((p = fopen(ARQ_PROD, "rb")) == NULL)
        fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_PROD);
    else
    {
        // Coloca o ponteiro p no final do arquivo "produtos.bin"
        fseek(p, 0, SEEK_END);
        // Determina o tamanho do vetor prod a ser criado com base no ultimo codigo do produto de forma sequencial, dividindo o valor atual do ponteiro pelo tamanho da struct tproduto + 1
        int tam_prod = (ftell(p) / sizeof(tproduto) + 1) - 1;
        // Cria um vetor prod de struct tproduto com a quantidade de elementos igual a quantidade de structs no arquivo
        tproduto prod[tam_prod];
        // Coloca o ponteiro p no inicio do arquivo
        fseek(p, 0, SEEK_SET);
        // Lê todos as structs tproduto armazenado no arquivo "produtos.bin"
        fread(prod, sizeof(tproduto), tam_prod, p);
        fclose(p);
        if((p = fopen(ARQ_LOJA, "rb")) == NULL)
            fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_LOJA);
        else
        {
            // Coloca o ponteiro p no final do arquivo "lojas.bin"
            fseek(p, 0, SEEK_END);
            // Determina o tamanho do vetor loja a ser criado com base no ultimo codigo da loja de forma sequencial, dividindo o valor atual do ponteiro pelo tamanho da struct tloja + 1
            int tam_loja = (ftell(p) / sizeof(tloja) + 1) - 1;
            // Cria um vetor loja de struct tloja com a quantidade de elementos igual a quantidade de structs no arquivo
            tloja loja[tam_loja];
            // Coloca o ponteiro p no inicio do arquivo
            fseek(p, 0, SEEK_SET);
            // Lê todos as structs tloja armazenado no arquivo "lojas.bin"
            fread(loja, sizeof(tloja), tam_prod, p);
            fclose(p);
            if((p = fopen(ARQ_PRECO, "rb")) == NULL)
                fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_PRECO);
            else
            {
                // Coloca o ponteiro p no final do arquivo "precos.bin"
                fseek(p, 0, SEEK_END);
                // Determina o tamanho do vetor preco a ser criado com base no ultimo codigo do preco de forma sequencial, dividindo o valor atual do ponteiro pelo tamanho da struct tpreco + 1
                int i, tam_preco = (ftell(p) / sizeof(tpreco) + 1) - 1;
                // Cria um vetor preco de struct tpreco com a quantidade de elementos igual a quantidade de structs no arquivo
                tpreco preco[tam_preco];
                // Coloca o ponteiro p no inicio do arquivo "precos.bin"
                fseek(p, 0, SEEK_SET);
                // Lê todos as structs tpreco armazenado no arquivo "preco.bin"
                fread(preco, sizeof(tpreco), tam_preco, p);
                fclose(p);
                // Ordena o vetor preco de struct tpreco utilizando BubbleSort, ordenando pelo nome da loja de forma ascendente e pelo preço de forma descendente
                ordena_preco(preco, tam_preco, loja);
                fprintf(stdout, "\n\n======================================\n");
                fprintf(stdout, "             Precos\n");
                fprintf(stdout, "======================================\n");
                for(i = 0; i < tam_preco; i++)
                    fprintf(stdout, "Produto: %s | Loja: %s | Preco: %.2f R$\n", prod[preco[i].cod_produto-1].descricao, loja[preco[i].cod_loja-1].nome, preco[i].preco);
                fprintf(stdout, "======================================\n");
            }
        }
    }

}

/* Função que ordena o vetor preco de struct tpreco utilizando BubbleSort,  ordenando pelo nome da loja de forma ascendente e pelo preco de forma descendente */
void ordena_preco(tpreco *preco, int tam_preco, tloja *loja)
{
    int i, j;
    tpreco aux;
    // Ordena pelo nome da loja de forma ascedente
    for(i = 1; i < tam_preco; i++)
    {
        for(j = i + 1; j < tam_preco; j++)
        {
            if(strcmp(loja[preco[i].cod_loja-1].nome, loja[preco[j].cod_loja-1].nome) > 0)
            {
                aux = preco[i];
                preco[i] = preco[j];
                preco[j] = aux;
            }
        }
    }
    // Ordena o vetor pelo preco de forma descendente mas os precos sao ordenados sendo da mesma loja
    for(i = 0; i < tam_preco; i++)
    {
        for(j = i + 1; j < tam_preco; j++)
        {
            // Caso os dois precos sejam da mesma loja, ele é ordenado
            if(preco[i].cod_loja == preco[j].cod_loja && preco[i].preco < preco[j].preco)
            {
                aux = preco[i];
                preco[i] = preco[j];
                preco[j] = aux;
            }
        }
    }

}

/* Função que consulta os precos de um determinado produtos em todas as lojas */
void consulta_prod()
{
    FILE *p_preco, *p_loja, *p_prod;
    if((p_prod = fopen(ARQ_PROD, "rb")) == NULL)
        fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_PROD);
    else
    {

        if((p_preco = fopen(ARQ_PRECO, "rb")) == NULL)
        {

            fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_PRECO);
            fclose(p_prod);
        }
        else
        {
            if((p_loja = fopen(ARQ_LOJA, "rb")) == NULL)
            {
                fprintf(stderr, "\nErro: Nao foi possivel abrir o arquivo %s\n", ARQ_LOJA);
                fclose(p_preco);
                fclose(p_prod);
            }
            else
            {
                int id_cod, id_max;
                fprintf(stdout, "\nInforme o codigo do produto:\n>>>> ");
                fscanf(stdin, " %d", &id_cod);
                tproduto prod;
                // Coloca o ponteiro p no final do arquivo "produtos.bin"
                fseek(p_prod, 0, SEEK_END);
                // Determina o ultimo codigo sequencial do arquivo "produtos.bin", dividindo o atual valor do ponteiro p pelo tamanho da struct tproduto + 1
                id_max = ftell(p_prod) / sizeof(tproduto) + 1;
                // Caso  o codigo do produto informado seja menor ou igual ao ultimo codigo do produto, o codigo informado é valido
                if(id_cod > id_max)
                {
                    fprintf(stderr, "\nErro: Nao existe nenhum produto com o codigo %d\n", id_cod);
                    fclose(p_preco);
                    fclose(p_prod);
                    fclose(p_loja);
                }
                else
                {
                    // Coloca o ponteiro aonde esta armazena a struct tproduto, do codigo informado
                    fseek(p_prod, (id_cod - 1) * sizeof(tproduto), SEEK_SET);
                    fread(&prod, sizeof(tproduto), 1, p_prod);
                    fclose(p_prod);
                    tpreco preco;
                    tloja loja;
                    fprintf(stdout, "\n\n======================================\n");
                    fprintf(stdout, "             Produto %s\n", prod.descricao);
                    fprintf(stdout, "======================================\n");
                    // Lê todos os precos do arquivo "precos.bin" um por um
                    while(fread(&preco, sizeof(tpreco), 1, p_preco) > 0)
                    {
                        // Caso o produto lido seja o mesmo que o informado, ele vai imprimir a loja e o preco do produto na tela
                        if(preco.cod_produto == id_cod)
                        {
                            fseek(p_loja, (preco.cod_loja - 1) * sizeof(tloja), SEEK_SET);
                            fread(&loja, sizeof(loja), 1, p_loja);
                            fprintf(stdout, "Loja: %s | Preco: %.2f R$\n", loja.nome, preco.preco);
                        }
                    }
                    fprintf(stdout, "======================================\n");
                }
            }
        }
    }
}
