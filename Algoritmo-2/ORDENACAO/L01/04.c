#include  <stdio.h>

typedef struct
{
    char nome[20];
    int nota;
} alunos;

int main()
{
    int max, i, j;
    fprintf(stdout, "Informe a quantidade de alunos:\n>>>> ");
    fscanf(stdin , " %d", &max);
    alunos aluno[max], aux;
    fprintf(stdout, "\n");
    // Le a estrutura
    for(i = 0; i < max; i++)
    {
        fprintf(stdout, "Informe o nome do aluno:\n>>>> ");
        fscanf(stdin, " %[^\n]", aluno[i].nome);
        fprintf(stdout, "Informe a nota do aluno %s:\n>>>> ", aluno[i].nome);
        fscanf(stdin, " %d", &aluno[i].nota);
        fprintf(stdout, "\n");
    }
    // Ordena a estrutura decrescente
    for(i = 0; i < max; i++)
    {
        for(j = i+1; j < max; j++)
        {
            if(aluno[i].nota < aluno[j].nota)
            {
                aux = aluno[i];
                aluno[i] = aluno[j];
                aluno[j] = aux;
            }
        }
    }
    // Imprime a estrutura
    for(i = 0; i < max; i++)
    {
        fprintf(stdout, "Nome: %s -> Nota: %d\n", aluno[i].nome, aluno[i].nota);
    }
    return 0;
}
