algoritmo "Exercicio 3"
// Função :
// Autor :
// Data : 26/04/2018
// Seção de Declarações
var
m : vetor[1..4,1..4] de inteiro
i,j,x,aux: inteiro
inicio
// Seção de Comandos
escreval("Informe a matriz:")
para i de 1 ate 4 faca
     para j de 1 ate 4 faca
          leia(m[i,j])
     fimpara
fimpara
escreval()
para x de 1 ate 4 faca
     aux    <- m[x,4]
     m[x,4] <-  m[1,x]
     m[1,x] <- aux
fimpara
escreval("O resultado da troca da 1 linha pelo da 4 coluna:")
para i de 1 ate 4 faca
     para j de 1 ate 4 faca
          escreva(m[i,j])
     fimpara
     escreval()
fimpara
fimalgoritmo
