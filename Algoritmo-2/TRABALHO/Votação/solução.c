/* solução.c
 *
 * Programa que gera uma votacao aleatoria e exibe o resultado
 *
 * Rodrigo Suarez Moreira (Ciência da Computação)
 *
 * Disciplina: Algoritmo-II
 *
 * 23/09/2018
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/* MAX_EL -> Quantidade de eleitores */
#define MAX_EL 9999
/* MAX_CD -> Quantidade de candidato */
#define MAX_CD 15

void Gera_Urna(void);
void Apura_Urna(long * qtd, int *cod);
void Ordena_Urna(long * qtd, int * cod, char nome[MAX_CD][150]);
void Exibe_Urna(long * qtd, int *cod, char nome[MAX_CD][150]);
int geraUrna();

int main()
{
    while(1)
    {
        printf("\n*---------------------*\n");
        printf("*Escolha a sua opcao: *\n");
        printf("* 1- Gerar urna       *\n");
        printf("* 2- Exibir votacao   *\n");
        printf("* 3- Sair             *\n");
        printf("*---------------------*\n");
        int i;
        scanf("%d", &i);
        system("cls");
        if(i == 1)
        {
            srand(time(NULL));
            Gera_Urna();
            system("pause");
        }
        if(i == 3)
            return 0;
        if(i == 2)
        {
            int cod[MAX_CD];
            long int qtd[MAX_CD] = {0};
            char nome[MAX_CD][150];
            cod[0] = 19;  strcpy(nome[0],  "Alvaro Dias (Podemos)     ");
            cod[1] = 51;  strcpy(nome[1],  "Cabo Daciolo (Patriota)   ");
            cod[2] = 12;  strcpy(nome[2],  "Ciro Gomes (PDT)          ");
            cod[3] = 27;  strcpy(nome[3],  "Eymael (DC)               ");
            cod[4] = 13;  strcpy(nome[4],  "Fernando Haddad (PT)      ");
            cod[5] = 45;  strcpy(nome[5],  "Geraldo Alckmin (PSDB)    ");
            cod[6] = 50;  strcpy(nome[6],  "Guilherme Boulos (PSol)   ");
            cod[7] = 15;  strcpy(nome[7],  "Henrique Meirelles (MDB)  ");
            cod[8] = 17;  strcpy(nome[8],  "Jair Bolsonaro (PSL)      ");
            cod[9] = 30;  strcpy(nome[9],  "Joao Amoedo (Novo)        ");
            cod[10] = 54; strcpy(nome[10], "Joao Vicente Goulart (PPL)");
            cod[11] = 18; strcpy(nome[11], "Marina Silva (Rede)       ");
            cod[12] = 16; strcpy(nome[12], "Vera Lucia (PSTU)         ");
            cod[13] = 1;  strcpy(nome[13], "Brancos                   ");
            cod[14] = 2;  strcpy(nome[14], "Nulos                     ");
            Apura_Urna(qtd, cod);
            Ordena_Urna(qtd, cod, nome);
            Exibe_Urna(qtd, cod, nome);
            system("pause");
            system("cls");
        }
    }
    return 0;
}

void Gera_Urna()
{
    FILE *p;
    char nome[] = "urna", arquivo[15] = "urna", numero[3];
    int i, k = 0, v, cod[MAX_CD];
    cod[0] = 19;
    cod[1] = 51;
    cod[2] = 12;
    cod[3] = 27;
    cod[4] = 13;
    cod[5] = 45;
    cod[6] = 50;
    cod[7] = 15;
    cod[8] = 17;
    cod[9] = 30;
    cod[10] = 54;
    cod[11] = 18;
    cod[12] = 16;
    cod[13] = 1;
    cod[14] = 2 ;
    long int urna[MAX_EL];
    for(i = 1; i < 25; i++)
    {
        /* Gera o proximo arquivo a ser aberto */
        itoa(i, numero, 10);
        strcat(arquivo, numero);
        strcat(arquivo, ".bin");
        if((p = fopen(arquivo, "wb")) == NULL)
        {
            printf("O arquivo %s nao pode ser criado\n", arquivo);
            exit(1);
        }
        /* Gera os votos e verifica se eles sao validos */
        while(k < MAX_EL)
        {
            v = rand() % 15;
            switch(v)
            {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
            case 10:
            case 11:
            case 12:
            case 13:
            case 14:
                urna[k++] = cod[v];
            }
        }
        fwrite(urna, MAX_EL, sizeof(int), p);
        fclose(p);
        strcpy(arquivo, nome);
    }
    printf("Urna gerada com sucesso\n");
}

void Apura_Urna(long * qtd, int * cod)
{
    FILE *p;
    char nome[] = "urna", arquivo[15] = "urna", numero[3];
    int i, k = 0, v, x, y, c = 0;
    long int urna[MAX_EL];
    for(i = 1; i <= 24; i++)
    {
        /* Gera o proximo arquivo a ser aberto */
        itoa(i, numero, 10);
        strcat(arquivo, numero);
        strcat(arquivo, ".bin");
        if((p = fopen(arquivo, "rb")) == NULL)
        {
            printf("O arquivo %s nao pode ser aberto\n", arquivo);
            exit(2);
        }
        fread(urna, MAX_EL, sizeof(int), p);
        fclose(p);
        strcpy(arquivo, nome);
        /* Apura os votos */
        for(x = 0; x < MAX_EL; x++)
            for(y = 0; y < MAX_CD; y++)
                if(urna[x] == cod[y])
                    qtd[y]++;
    }
}

void Ordena_Urna(long * qtd, int * cod, char nome[MAX_CD][150])
{
    int i, j, aux_cod;
    long aux_qtd;
    char aux_nome[150];
    /* Ordena do mais votado para o menor */
    for(i = 0; i < MAX_CD - 2; i++)
    {
        for(j = i + 1; j < MAX_CD - 2; j++)
        {
            if(qtd[i] < qtd[j])
            {
                aux_qtd = qtd[i];
                qtd[i] = qtd[j];
                qtd[j] = aux_qtd;

                aux_cod = cod[i];
                cod[i] = cod[j];
                cod[j] = aux_cod;

                strcpy(aux_nome, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], aux_nome);
            }
        }
    }
}

void Exibe_Urna(long * qtd, int *cod, char nome[MAX_CD][150])
{
    int i;
    long  c = MAX_EL * 24;
    printf("Codigo\tCandidato\t\t\tVotos\n");
    for(i = 0; i < MAX_CD; i++)
        printf("%d\t%s\t%ld\n", cod[i], nome[i], qtd[i]);
    printf("\n============================================\n\n");
    printf("Candidato\t\t\tVotos\n");
    for(i = 0; i < MAX_CD; i++)
        printf("%s\t%ld%%\n", nome[i], (qtd[i] * 100) / c);
}
