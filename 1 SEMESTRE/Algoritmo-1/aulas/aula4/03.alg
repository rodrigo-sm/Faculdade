algoritmo "semnome"
// Função : Escrever um programa que solicite dois números e o símbolo de operação aritmética(+ - * /). O programa deve imprimir o resultado da operação.
// Autor :
// Data : 01/03/2018
// Seção de Declarações 
var
num1,num2,conta : inteiro
simbolo : caractere
inicio
// Seção de Comandos 
Escreval("Informe dois numeros e o simbolo da operaçao aritmetica:")
leia(num1)
leia(num2)
leia(simbolo)
escolha simbolo
caso "+"
     conta <- num1 + num2
     escreval("O resultado é:",conta)
caso "-"
     conta <- num1 - num2
     escreval("O resultado é:",conta)
caso "*"
     conta <- num1 * num2
     escreval("O resultado é:",conta)
caso "/"
     conta <- num1 / num2
     escreval("O resultado é:",conta)
outrocaso
     escreval("simbolo informado nao pode ser operado")
fimescolha

fimalgoritmo
