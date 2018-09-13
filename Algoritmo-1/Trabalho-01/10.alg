algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
num : vetor[1..3] de inteiro
cod,x,i,j : inteiro
media : real
inicio
// Seção de Comandos
enquanto (cod >= 0) faca
   escreval("Informe o numero do codigo do aluno")
   leia(cod)
   se cod >= 0 entao
      para i de 1 ate 3 faca
         leia(num[i])
      fimpara
      para i de 1 ate 3 faca
         para j de (i+1) ate 2 faca
            se num[i] < num[j] entao
               x <- num[i]
               num[i] <- num[j]
               num[j] <- x
            fimse
         fimpara
      fimpara
      media <- (num[1]*4 + num[2]*3 + num[3]*3) / 10
      se media >= 5 entao
         escreval("Aprovado")
      senao
         escreval("Reprovado")
      fimse
   fimse
fimenquanto

fimalgoritmo

