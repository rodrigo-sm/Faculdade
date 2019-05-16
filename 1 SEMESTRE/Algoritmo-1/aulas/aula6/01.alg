algoritmo "semnome"
// Função :Crie um programa que receba a média final de 5 alunos e calcule a média geral da turma

// Autor :
// Data : 05/03/2018
// Seção de Declarações 
var
x : vetor[1..5] de real
num1,num2,soma,media_geral : real
i,divisores : inteiro
inicio
// Seção de Comandos 
para i de 1 ate 5 faca
leia(num1)
leia(num2)
x[i] <- num1+num2/2
escreval(x[i])
soma <- soma + x[i]
divisores <- divisores + 1
fimpara
media_geral <- soma / divisores
escreval(media_geral)

fimalgoritmo
