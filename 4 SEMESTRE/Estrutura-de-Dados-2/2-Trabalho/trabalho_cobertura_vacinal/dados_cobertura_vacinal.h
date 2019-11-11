#ifndef DADOS_COBERTURA_VACINAL_H_INCLUDED
#define DADOS_COBERTURA_VACINAL_H_INCLUDED

#define MAX_NOME 250
#define FILENAME_DADOS "cobertura_vacinal.csv"
#define SEPARADOR ";"
#define MAX_LINE 1000
#define VAZIO 0
#define LIMITE_MAXIMO 5570
#define LIMITE_MINIMO 1

typedef struct {
    int codigo_munipicio;
    char nome_municipio[MAX_NOME];
    float cobertura_vacinal;
} cobertura_vacinal_info;

#endif // DADOS_COBERTURA_VACINAL_H_INCLUDED
