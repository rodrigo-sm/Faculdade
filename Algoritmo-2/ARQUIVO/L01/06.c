/*
6.	Faça um programa com uma função void criar(void) que crie uma matriz 2 x 2 de inteiros e armazene em um arquivo binário chamado matriz.dat.
A função deve ainda receber uma senha de no mínimo 6 caracteres e no máximo 8 que deve ser guardada em um arquivo binário chamado pwd.bin.

O programa deve ter ainda uma função void girar(void) para recuperar a matriz e girar a mesma no sentido horário.
Contudo a matriz só pode ser girada se a senha for idêntica à guardada no arquivo pwd.bin.
*/
#include <stdio.h>

void criar(void);

void girar(void);

int main()
{
    int n;
    while(1)
    {
        printf("\n*---------------------*\n");
        printf("*Escolha a sua opcao: *\n");
        printf("* 1- Criar a matriz   *\n");
        printf("* 2- Girar a matriz   *\n");
        printf("* 3- Sair             *\n");
        printf("*---------------------*\n");
        scanf("%d", &n);
        //VAI SELECIONAR  COMANDO ESCOLHIDO
        switch(n)
        {
        case 1:
            criar();
            break;
        case 2:
            girar();
            break;
        case 3:
            return 0;
        default:
            printf("Opcao nao e valida\n\n");
        }
    }
}

void criar(void)
{
    int i,j;
    FILE *ps,*pm;
    //ABRE O ARQUIVO DA MATRIZ
    if((pm = fopen("matriz.dat","w")) == NULL)
    {
        printf("O arquivo da matriz(matriz.dat) nao pode ser criado\n");
    }
    else
    {
        //ABRE O ARQUIVO DA SENHA
        if((ps = fopen("pwd.bin","wb")) == NULL)
        {
            printf("O arquivo da senha(pwd.bin) nao pode ser criado\n");
        }
        else
        {

            printf("Informe a matriz 2x2:\n");
            int m[2][2];
            //LE A MATRIZ E COLOCA NO ARQUIVO MATRIZ.DAT
            for(i = 0; i < 2; i++)
            {
                for(j = 0; j < 2; j++)
                {
                    scanf(" %d", &m[i][j]);
                    fprintf(pm,"%d ", m[i][j]);
                }
                fputc('\n',pm);
            }
            int senha;
            printf("Informe a senha(6 a 8 caracteres): ");
            scanf(" %d", &senha);
            //LE A SENHA E VERIFICA SE TEM ENTRE 6 E 8 CARACTERES
            while(senha >= 100000000 || senha <= 10000)
            {
                printf("Informe a senha com 6 a 8 caracteres: ");
                scanf(" %d", &senha);
            }
            fprintf(ps,"%d",senha);
            fclose(ps);
            fclose(pm);
        }
    }
}

void girar(void)
{
    FILE *ps,*pm;
    if((ps = fopen("pwd.bin","rb")) == NULL)
    {
        printf("O arquivo da senha(pwd.bin) nao pode ser aberto\n");
    }
    else
    {
        int sr,sa;
        printf("Informe a senha do arquivo: ");
        //LE A SENHA RECEBICA(sr) E A SENHA DO ARQUIVO(sa)
        scanf(" %d", &sr);
        fscanf(ps,"%d", &sa);
        //VERIFICA SE AS SENHAS SAO IGUAIS
        while(sr != sa && sr != 0)
        {
            printf("Senha errada, tente de novo ou digite zero para sair: ");
            scanf(" %d", &sr);
        }
        if(sr == sa)
        {
            fclose(ps);
            if((pm = fopen("matriz.dat","r")) == NULL)
            {
                printf("O arquivo da matriz(matriz.dat) nao pode ser aberto\n");
            }
            else
            {
                char ch;
                int i = 0,j = 0,m[2][2],ch1,ch2;
                //VAI LER A MATRIZ
                while((fscanf(pm,"%d %d \n", &m[i][0], &m[i][1])) != EOF)
                    i++;
                fclose(pm);
                pm = fopen("matriz.dat","w");
                //VAI GIRAR A MATRIZ HORIZONTALMENTE
                ch1 = m[0][1];
                m[0][1] = m[0][0];
                ch2 = m[1][1];
                m[1][1] = ch1;
                ch1 = m[1][0];
                m[1][0] = ch2;
                ch2 = m[0][0];
                m[0][0] = ch1;
                //VAI COLOCAR O PONTEIRO PM NO INICIO DO ARQUIVO DA MATRIZ
                rewind(pm);
                //VAI COLOCAR A MATRIZ GIRADA NO ARQUIVO
                for(i = 0; i < 2; i++)
                {
                    for(j = 0; j < 2; j++)
                    {
                        fprintf(pm,"%d ", m[i][j]);
                    }
                    fputc('\n', pm);
                }
                fclose(pm);
            }
        }

    }
}
