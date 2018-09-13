algoritmo "semnome"
// Função : Faça um programa que converta um valor monetário de REAL para DÓLAR.
// Autor : Rodrigo Suarez Moreira
// Data : 21/02/2018
// Seção de Declarações 
var
    rea,cotacao,dolar : real
inicio
// Seção de Comandos
//recebe o valor em real
escreva("Informe a quantidade em real:")
leia(rea)
//recebe a cotaçao do dia
escreva("A cotaçao do dia é:")
leia(cotacao)
//Converte o valor em real para dolar
dolar <- rea * cotacao
//apresenta o valor em dolar
escreva ("A quantidade em dolar é:",dolar)
fimalgoritmo
