algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
n :vetor[1..150] de real
bonus : real
i : inteiro
inicio
// Seção de Comandos
para i de 1 ate 150 faca
leia(n[i])
se n[i] < 500000 entao
   bonus <- 0.1 * n[i]
senao
   bonus <- 0.15 * n[i]
fimse
escreval("O bonus do cliente é: ",n[i]+bonus)
fimpara
fimalgoritmo
