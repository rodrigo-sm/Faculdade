/* 01.c
 *
 * Programa cria uma banco de dados de bandas
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Algoritmo-II
 *
 * 13/11/2018
 */
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char tipo[20];
    int qntd;
    int rank;
} banda;

void cadastrar(void);
void buscaRank(void);
void exibeTipo(void);
void verificaFavorita(void);
void lista(void);
void transfMinusculo(char *s);
void ordena(void);

int main()
{
    int n;
    while(1)
    {
        printf("Menu:\n 1 - Cadastrar banda\n 2 - Buscar banda por rank\n 3 - Exibir as bandas por um determinado tipo\n 4 - Verificar se a banda esta entre as 5 favoritas\n 5 - Listar bandas\n 0 - Sair\n>>>> ");
        scanf(" %d", &n);
        switch(n)
        {
        case 0:
            return 0;
        case 1:
            cadastrar();
            break;
        case 2:
            buscaRank();
            break;
        case 3:
            exibeTipo();
            break;
        case 4:
            verificaFavorita();
            break;
        case 5:
            lista();
            break;
        default:
            fprintf(stderr, "Erro: Opcao invalida!\n");
        }
    }
}

void transfMinusculo(char *s)
{
    int c = 0;

    while (s[c] != '\0')
    {
        if (s[c] >= 'A' && s[c] <= 'Z')
        {
            s[c] += 32;
        }
        c++;
    }
}

void cadastrar()
{
    FILE *p;
    if((p = fopen("db_banda.dat", "ab")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo db_banda.dat(banco de dados)\n");
    }
    else
    {
        banda cadastro;
        fprintf(stdout, "Informe o nome da banda:\n>>>> ");
        fscanf(stdin, " %[^\n]", cadastro.nome);
        transfMinusculo(cadastro.nome);
        fprintf(stdout, "Informe o tipo da banda:\n>>>> ");
        fscanf(stdin, " %[^\n]", cadastro.tipo);
        transfMinusculo(cadastro.tipo);
        fprintf(stdout, "Informe a quantidade de membros da banda:\n>>>> ");
        fscanf(stdin, " %d", &cadastro.qntd);
        fprintf(stdout, "Informe o rank da banda:\n>>>> ");
        fscanf(stdin, " %d", &cadastro.rank);
        fwrite(&cadastro, sizeof(banda), 1, p);
        fclose(p);
        fprintf(stdout, "Cadastro bem sucedido!\n");
    }
}

void buscaRank()
{
    FILE *p;
    int rank, r = 1;
    fprintf(stdout, "===============================================\n");
    if((p = fopen("db_banda.dat", "rb")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo db_banda.dat(banco de dados)\n");
    }
    else
    {
        fprintf(stdout, "Informe o rank da banda a ser buscada:\n>>>> ");
        fscanf(stdin, " %d", &rank);
        banda cadastro;
        fprintf(stdout, "\t\tBusca\n===============================================\n");
        while(fread(&cadastro, sizeof(banda), 1, p) > 0)
        {
            if(cadastro.rank == rank)
            {
                fprintf(stdout, "| Nome: %s | Tipo: %s | Rank: %d | Quantidade de membros: %d |\n", cadastro.nome, cadastro.tipo, cadastro.rank, cadastro.qntd);
                r = 0;
            }
        }
        if(r)
            fprintf(stdout, "Nao foi encontrada banda com %d posicao no rank\n", rank);
        fclose(p);
    }
    fprintf(stdout, "===============================================\n");
}

void exibeTipo()
{
    FILE *p;
    int r = 1;
    char tipo[20];
    fprintf(stdout, "===============================================\n");
    if((p = fopen("db_banda.dat", "rb")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo db_banda.dat(banco de dados)\n");
    }
    else
    {
        fprintf(stdout, "Informe o tipo de banda a ser exibido:\n>>>> ");
        fscanf(stdin, " %[^\n]", tipo);
        transfMinusculo(tipo);
        banda cadastro;
        fprintf(stdout, "\t\tBusca\n===============================================\n");
        while(fread(&cadastro, sizeof(banda), 1, p) > 0)
        {
            if(!strcmp(cadastro.tipo, tipo))
            {
                fprintf(stdout, "| Nome: %s | Tipo: %s | Rank: %d | Quantidade de membros: %d |\n", cadastro.nome, cadastro.tipo, cadastro.rank, cadastro.qntd);
                r = 0;
            }
        }
        if(r)
            fprintf(stdout, "Nao foi encontrada nenhuma banda do tipo %s\n", tipo);
        fclose(p);
    }
    fprintf(stdout, "===============================================\n");
}

void verificaFavorita()
{
    FILE *p;
    int r = 1;
    char nome[20];
    fprintf(stdout, "===============================================\n");
    if((p = fopen("db_banda.dat", "rb")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo db_banda.dat(banco de dados)\n");
    }
    else
    {
        fprintf(stdout, "Informe o nome da banda:\n>>>> ");
        fscanf(stdin, " %[^\n]", nome);
        transfMinusculo(nome);
        banda cadastro;
        fprintf(stdout, "\t\tBusca\n===============================================\n");
        while(fread(&cadastro, sizeof(banda), 1, p) > 0)
        {
            if(!strcmp(cadastro.nome, nome) && cadastro.rank >= 1 && cadastro.rank <= 5)
            {
                fprintf(stdout, "A banda %s esta dentre as suas 5 favoritas\n", nome);
                r = 0;
            }
        }
        if(r)
            fprintf(stdout, "A banda %s nao esta dentre as suas 5 favoritas\n", nome);
        fclose(p);
    }
    fprintf(stdout, "===============================================\n");
}

void lista()
{
    FILE *p;
    int r = 1;
    fprintf(stdout, "===============================================\n");
    if((p = fopen("db_banda.dat", "rb")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo db_banda.dat(banco de dados)\n");
    }
    else
    {
        ordena();
        banda cadastro;
        fprintf(stdout, "\t\tBusca\n===============================================\n");
        while(fread(&cadastro, sizeof(banda), 1, p) > 0)
        {
                fprintf(stdout, "| Nome: %s | Tipo: %s | Rank: %d | Quantidade de membros: %d |\n", cadastro.nome, cadastro.tipo, cadastro.rank, cadastro.qntd);
                r = 0;
        }
        if(r)
            fprintf(stdout, "Nao existe nenhuma banda cadastrada\n");
        fclose(p);
    }
    fprintf(stdout, "===============================================\n");
}

void ordena()
{
    FILE *p;
    int r = 1;
    char nome[20];
    if((p = fopen("db_banda.dat", "r+b")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo db_banda.dat(banco de dados)\n");
    }
    else
    {
        banda b1, b2;
        int i = 0, j, tam = sizeof(banda), qntd;
        fseek(p, 0, SEEK_END);
        qntd = ftell(p);
        fseek(p, 0, SEEK_SET);
        for(i = 0; i < qntd; i+=tam)
        {
            fseek(p, i, SEEK_SET);
            fread(&b1, tam, 1, p);
            for(j = i + tam; j < qntd; j+=tam)
            {
                fseek(p, j, SEEK_SET);
                fread(&b2, tam, 1, p);
                if(b1.rank > b2.rank)
                {
                    fseek(p, j, SEEK_SET);
                    fwrite(&b1, tam, 1, p);
                    fseek(p, i, SEEK_SET);
                    fwrite(&b2, tam, 1, p);
                }
            }
        }
        fclose(p);
    }
}
