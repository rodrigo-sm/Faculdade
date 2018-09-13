algoritmo "Exercicio 1"
// Função :
// Autor :
// Data : 26/04/2018
// Seção de Declarações
var
m : vetor[1..5,1..5] de inteiro
i,j,c: inteiro
inicio
// Seção de Comandos
aleatorio 1,5
para c de 1 ate 5 faca
     leia(i,j)
     enquanto m[i,j] = 1 faca
          leia(i,j)
     fimenquanto
     m[i,j] <- 1
fimpara
aleatorio off
limpatela
c <- 0
enquanto c < 10 faca
escreval("Informe a coordenada do alvo (i,j): ")
leia(i,j)
se m[i,j] = 2 entao
   escreval("Coordenada ja verificada")
fimse
se m[i,j] = 0 entao
   m[i,j] <- 2
   c <- c + 1
fimse
se m[i,j] = 1 entao
   m[i,j] <- -1
   escreval("BOMBA, VOCE PERDEU")
   interrompa
fimse
escreval()
escreval("--------------------------")
escreval()
fimenquanto
se c >= 10 entao
   escreval("VOCE VENCEU")
fimse
escreval()
escreval("--------------------------")
escreval()
escreval("Campo minado")
para i de 1 ate 5 faca
     para j de 1 ate 5 faca
          escreva(m[i,j])
     fimpara
     escreval()
fimpara
fimalgoritmo
