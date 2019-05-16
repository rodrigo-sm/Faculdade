algoritmo "Exercicio 9"
// Função :
// Autor :
// Data : 26/04/2018
// Seção de Declarações
var
m : vetor[0..3,0..3] de inteiro
x,y,op,i,j,aux: inteiro
inicio
// Seção de Comandos
escreval("Informe a matriz")
para x de 0 ate 3 faca
     para y de 0 ate 3 faca
          leia(m[x,y])
     fimpara
fimpara
escreval()
escreval("Informe op, i e j: ")
leia(op,i,j)
escreval()
escreval("A matriz modificada:")
se op mod 2 = 0 entao
   para x de 0 ate 3 faca
        aux    <- m[x,i]
        m[x,i] <- m[x,j]
        m[x,j] <- aux
   fimpara
senao
   para x de 0 ate 3 faca
        aux <- m[i,x]
        m[i,x] <- m[j,x]
        m[j,x] <- aux
   fimpara
fimse
para x de 0 ate 3 faca
     para y de 0 ate 3 faca
          escreva(m[x,y])
     fimpara
     escreval()
fimpara
fimalgoritmo
