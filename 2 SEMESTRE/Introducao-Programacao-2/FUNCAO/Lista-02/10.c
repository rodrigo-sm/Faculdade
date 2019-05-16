/*
10. Escreva uma função de protótipo int * new_integer(void); que declara e
inicializa um inteiro dentro da função e retorna o endereço deste inteiro. Imprima o valor
inteiro associado a esse endereço de memória na função main(). Isto é possível em C?
Seu compilador exibe alguma advertência? Esta operação é segura?
*/

#include <stdio.h>

int * new_integer(void);

int main()
{
    int *e;
    e = new_integer();
    printf("%d\n", *e);
    return 0;
}

int * new_integer(void)
{
    int i;
    scanf("%d", &i);
    return &i;
}
