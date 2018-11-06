#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id; // identificador do amigo
    char nome[40];
    char fone[14];
    char email[30];
} amigo;

void cadastrar(void);
void listar(void);
void alterar(void);
void consultar(void);
int main(int argc, char *argv[])
{
    int n;
    while(1)
    {
        fprintf(stdout, "Escolha uma opcao:\n 0 - Sair\n 1 - Cadastrar um novo amigo\n 2 - Listar todos os amigos\n 3 - Alterar Telefone ou Email\n 4 - Consultar amigo\n>>>> ");
        fscanf(stdin, "%d", &n);
        switch(n)
        {
        case 0:
            return 0;
        case 1:
            cadastrar();
            break;
        case 2:
            listar();
            break;
        case 3:
            alterar();
            break;
        case 4:
            consultar();
            break;
        default:
            fprintf(stderr, "Erro: Opcao invalida\n");
            system("pause");
        }
        system("cls");
    }
}

void cadastrar()
{
    FILE *p;
    if((p = fopen("database.dat", "ab")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo database\n");
        exit(1);
    }
    amigo cadastro;
    fseek(p, 0, SEEK_END);
    cadastro.id = ftell(p) / sizeof(amigo);
    system("cls");
    fprintf(stdout, "Informe o nome:\n>>>> ");
    fscanf(stdin, " %s", cadastro.nome);
    fprintf(stdout, "Informe o email:\n>>>> ");
    fscanf(stdin, " %s", cadastro.fone);
    fprintf(stdout, "Informe o telefone:\n>>>> ");
    fscanf(stdin, " %s", cadastro.email);
    fwrite(&cadastro, sizeof(amigo), 1, p);
    fprintf(stdout, "Amigo cadastrado com sucesso\n");
    system("pause");
    fclose(p);
}

void listar()
{
    FILE *p;
    if((p = fopen("database.dat", "rb")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo database\n");
        exit(2);
    }
    amigo cadastro;
    system("cls");
    fprintf(stdout, "\n\t\tAmigos cadastrados\n");
    fprintf(stdout, "----------------------------------------------------------\n");
    while(fread(&cadastro, sizeof(amigo), 1, p) > 0)
        fprintf(stdout, "Id: %d | Nome: %s | Telefone: %s | Email: %s\n", cadastro.id, cadastro.nome, cadastro.fone, cadastro.email);
    fprintf(stdout, "----------------------------------------------------------\n");
    system("pause");
    fclose(p);
}

void alterar()
{
    int n, e = 0, f = 0;
    char fone[14], email[30];
    FILE *p;
    amigo cadastro;
    system("cls");
    fprintf(stdout, "Alterar Telefone?\n 1 - Sim\n 2 - Nao\n>>>> ");
    fscanf(stdin, " %d", &n);
    if (n == 1)
    {
        fprintf(stdout, "Informe o novo telefone:\n>>>> ");
        fscanf(stdin, " %s", fone);
        f = 1;
    }
    system("cls");
    fprintf(stdout, "Alterar Email?\n 1 - Sim\n 2 - Nao\n>>>> ");
    fscanf(stdin, " %d", &n);
    if (n == 1)
    {
        fprintf(stdout, "Informe o novo email:\n>>>> ");
        fscanf(stdin, " %s", email);
        e = 1;
    }
    if(e || f)
    {
        if((p = fopen("database.dat", "r+b")) == NULL)
        {
            fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo database\n");
            exit(1);
        }
        system("cls");
        fprintf(stdout, "Escolha uma opcao de busca:\n 1 - ID\n 2 - Nome\n>>>> ");
        fscanf(stdin, " %d", &n);
        if (n == 1)
        {
            int id;
            fprintf(stdout, "Informe o ID:\n>>>> ");
            fscanf(stdin, " %d", &id);
            fseek(p, id*sizeof(amigo), SEEK_SET);
            fread(&cadastro, sizeof(amigo), 1, p);
            if(cadastro.id == id)
            {
                if(e)
                    strcpy(cadastro.email, email);
                if(f)
                    strcpy(cadastro.fone, fone);
                fseek(p, -sizeof(amigo), SEEK_CUR);
                fwrite(&cadastro, sizeof(amigo), 1, p);
                system("cls");
                fprintf(stdout, "\n\t\tAmigo Modificado Com Sucesso\n");
                fprintf(stdout, "----------------------------------------------------------\n");
                fprintf(stdout, "Id: %d | Nome: %s | Telefone: %s | Email: %s\n", cadastro.id, cadastro.nome, cadastro.fone, cadastro.email);
                fprintf(stdout, "----------------------------------------------------------\n");
            }
            else
                fprintf(stdout, "Nao foi encontrado um amigo com o ID igual a %d\n", id);
        }
        else if (n == 2)
        {
            char nome[40];
            fprintf(stdout, "Informe o nome:\n>>>> ");
            fscanf(stdin, " %s", nome);
            while (fread(&cadastro, sizeof(amigo), 1, p) > 0)
            {
                if (!strcmp(cadastro.nome, nome))
                {
                    if(e)
                        strcpy(cadastro.email, email);
                    if(f)
                        strcpy(cadastro.fone, fone);
                    fseek(p, -1*sizeof(amigo), SEEK_CUR);
                    fwrite(&cadastro, sizeof(amigo), 1, p);
                    system("cls");
                    fprintf(stdout, "\n\t\tAmigo Modificado Com Sucesso\n");
                    fprintf(stdout, "----------------------------------------------------------\n");
                    fprintf(stdout, "Id: %d | Nome: %s | Telefone: %s | Email: %s\n", cadastro.id, cadastro.nome, cadastro.fone, cadastro.email);
                    fprintf(stdout, "----------------------------------------------------------\n");
                    n = 3;
                    break;
                }
            }
            if(n == 2)
                fprintf(stdout, "Nao foi encontrado um amigo com o Nome igual a %s\n", nome);
        }
        else
            fprintf(stderr, "Erro: Opcao invalida\n");
    }
    system("pause");
    fclose(p);
}

void consultar()
{
    int n;
    FILE *p;
    amigo cadastro;
    system("cls");
    fprintf(stdout, "Escolha uma opcao de busca:\n 1 - ID\n 2 - Nome\n>>>> ");
    fscanf(stdin, " %d", &n);
    if ((p = fopen("database.dat", "rb")) == NULL)
    {
        fprintf(stderr, "Erro: Nao foi possivel abrir o arquivo database\n");
        exit(3);
    }
    if (n == 1)
    {
        int id;
        system("cls");
        fprintf(stdout, "Informe o ID:\n>>>> ");
        fscanf(stdin, " %d", &id);
        fseek(p, id*sizeof(amigo), SEEK_SET);
        fread(&cadastro, sizeof(amigo), 1, p);
        if(cadastro.id == id)
        {
            system("cls");
            fprintf(stdout, "\n\t\tAmigo Encontrado\n");
            fprintf(stdout, "----------------------------------------------------------\n");
            fprintf(stdout, "Id: %d | Nome: %s | Telefone: %s | Email: %s\n", cadastro.id, cadastro.nome, cadastro.fone, cadastro.email);
            fprintf(stdout, "----------------------------------------------------------\n");
        }
        else
            fprintf(stdout, "Nao foi encontrado um amigo com o ID igual a %d\n", id);
    }
    else if (n == 2)
    {
        char nome[40];
        system("cls");
        fprintf(stdout, "Informe o nome:\n>>>> ");
        fscanf(stdin, " %s", nome);
        while (fread(&cadastro, sizeof(amigo), 1, p) > 0)
        {
            if (!strcmp(cadastro.nome, nome))
            {
                system("cls");
                fprintf(stdout, "\n\t\tAmigo Encontrado\n");
                fprintf(stdout, "----------------------------------------------------------\n");
                fprintf(stdout, "Id: %d | Nome: %s | Telefone: %s | Email: %s\n", cadastro.id, cadastro.nome, cadastro.fone, cadastro.email);
                fprintf(stdout, "----------------------------------------------------------\n");
                n = 3;
                break;
            }
        }
        if(n == 2)
            fprintf(stdout, "Nao foi encontrado um amigo com o Nome igual a %s\n", nome);
    }
    else
        fprintf(stderr, "Erro: Opcao invalida\n");
    system("pause");
    fclose(p);
}
