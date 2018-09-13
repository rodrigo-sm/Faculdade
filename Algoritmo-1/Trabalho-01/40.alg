algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
n :vetor[1..4] de inteiro
i,j,aux,num : inteiro
inicio
// Seção de Comandos
repita
   escreval("=================")
   Escreval("Informe 4 valores")
   para i de 1 ate 4 faca
      leia(n[i])
   fimpara
   para i de 1 ate 4 faca
      para j de (i+1) ate 3 faca
         se n[i] < n[j] entao
            aux <- n[i]
            n[i] <- n[j]
            n[j] <- aux
         fimse
      fimpara
   fimpara
   escreval("======================")
   escreval("Em ordem decrescente")
   para i de 4 ate 1 passo -1 faca
      escreval(n[i])
   fimpara
   num <- num + 1
ate num > 5
fimalgoritmo
