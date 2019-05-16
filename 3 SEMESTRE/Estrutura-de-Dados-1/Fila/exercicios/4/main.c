#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fpa.h"

typedef struct {
    char nome[50];
    char telefone[50];
} paciente;

void cadastrar(paciente *, fpa *);

int main()
{
    int op, id;
    paciente p[FPA_MAX];
    fpa fp;
    fp_init(&fp);
    do{
        printf("\nOpcoes:\n1 - Cadastrar\n2 - Consultar proximo paciente\n3 - Consultar quantidade de pacientes cadastrados\n0 - Sair\n");
        scanf(" %d", &op);
        switch (op) {
            case 1:
                cadastrar(p, &fp);
                break;
            case 2:
                id = fp_informa_min(fp);
                printf("Paciente:\nNome: %s\nTelefone: %s\nUrgencia: %d\n", p[id].nome, p[id].telefone, fp.itens[id]);
                break;
            case 3:
                printf("Tem %d paciente(s) cadastrado(s)\n", fp.tamanho);
                break;
            case 0:
                printf("Xau\n");
                return 0;
            default:
                fprintf(stderr, "Opcao nao informada\n");
        }
    } while (op != 0);
}

void cadastrar(paciente * p, fpa * fp)
{
    int id;
    fpa_info grau;
    printf("Informe o grau de urgencia:\n>>>> ");
    scanf(" %d", &grau);
    id = fp_inserir(fp, grau);
    printf("Informe o nome:\n>>>> ");
    scanf(" %[^\n]", p[id].nome);
    printf("Informe o telefone:\n>>>> ");
    scanf(" %[^\n]", p[id].telefone);
}
