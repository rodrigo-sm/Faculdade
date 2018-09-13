algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
n1,n2,controle,i,gp : inteiro
inicio
// Seção de Comandos
gp <- 1
controle <- 1
repita
   escreval("Grupo ",gp)
   escreval()
   escreval("Escreva dois valores")
   leia(n1)
   leia(n2)
   se n1 < n2 entao
      escreval()
      escreval("Numeros pares entre ",n1," e ",n2)
      para i de n1 ate n2 faca
         se i mod 2 = 0 entao
            escreval(i)
         fimse
      fimpara
   fimse
   controle <- controle + 1
   gp <-gp + 1
   escreval("======================================")
ate controle > 5
fimalgoritmo
