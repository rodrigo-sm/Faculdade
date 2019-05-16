/*
7)	Fazer um programa que inverte um string. “Parabens a voce'' vira “ecov a snebaraP''.
*/
#include <stdio.h>
#include <strings.h>

int main(){

    char str[200],str_aux[200];
    int i=0,len;

    gets(str);

    len = strlen(str);

    puts(strrev(str));

    strcpy(str_aux,str);

    //RE - INVERTE
    while(str[i]!='\0'){

        str[i] = str_aux[len-1];
        len--;
        i++;

    }
    puts(str);
    return 0;
}
