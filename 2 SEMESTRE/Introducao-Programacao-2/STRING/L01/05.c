/*
5. Escreva um programa que dadas duas strings (A e B), construa e exiba uma terceira string
(C) formada pelos caracteres de A e B intercalados. Por exemplo: A = “Quarta” e B =
“Segunda”, a resposta deve ser C = “QSueagrutnada”
*/
#include <stdio.h>
#include <string.h>

int main()
{
    char a[81],b[81],c[161];
    printf("Informe a string A:\n");
    scanf("%s", a);
    printf("Informe a string B:\n");
    scanf(" %s", b);
    int ta,tb,i,x,y;
    ta = strlen(a);
    tb = strlen(b);
    for(i = 0,x = 0, y = 0;x < ta || y < tb ;i++)
    {
        if(i % 2 == 0)
        {
            if(y < ta)
            {
                c[i] = a[x];
                x++;
            }
            else
            {
                c[i] = b[y];
                y++;
            }
        }
        else
        {
            if(x < tb)
            {
                c[i] = b[y];
                y++;
            }
            else
            {
                c[i] = a[x];
                x++;
            }
        }
    }
    c[i] = '\0';
    printf("String C:\n");
    printf("%s\n", c);
    return 0;
}
