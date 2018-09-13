algoritmo "semnome"
// Função :
// Autor :
// Data : 08/03/2018
// Seção de Declarações 
var
a : vetor[1..5] de real
positivo,negativo : inteiro
i : inteiro
inicio
// Seção de Comandos
positivo <- 0
negativo <- 0
para i de 1 ate 5 faca
leia(a[i])
se a[i] > 0 entao
positivo <- positivo + 1
senao
negativo <- negativo + 1
fimse
fimpara
escreval("A quantidade de numeros negativos é: ",negativo)
escreval("A quantidade de numeros positivos é: ",positivo)
fimalgoritmo
