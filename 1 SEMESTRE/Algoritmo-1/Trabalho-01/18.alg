algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
controle : caractere
num,divisores,fatorial,soma,i : inteiro
inicio
// Seção de Comandos
repita
   escreva("Informe um numero: ")
   fatorial <- 1
   divisores <- 0
   soma <- 0
   leia(num)
   escreval("===================")
   se num mod 2 = 0 entao
      para i de 1 ate num faca
         se num mod i = 0 entao
            divisores <- divisores + 1
         fimse
      fimpara
      escreval("O numero possui ",divisores," divisores")
   senao
      se num < 10 entao
         para i de 1 ate num faca
            fatorial <- fatorial * i
         fimpara
         escreval("O fatorial do numero é ",fatorial)
      senao
         para i de 1 ate num faca
            soma <- soma + i
         fimpara
         escreval("A soma dos inteiros de 1 ate ",num," é: ",soma)
      fimse
   fimse
   escreval("===================")
   escreval("Se quiser encerrar o programa digite 'n', se nao digite qualquer letra")
   leia(controle)
   escreval("===================")
ate controle = "n"
fimalgoritmo
