algoritmo "semnome"
// Função :
// Autor :
// Data : 02/03/2018
// Seção de Declarações 
var
fatorial,num,i : inteiro
inicio
// Seção de Comandos 
fatorial <- 1
leia(num)
se num > 0 entao
para i de 1 ate num faca
fatorial <- fatorial * i
fimpara
fimse
escreval(fatorial)
fimalgoritmo
