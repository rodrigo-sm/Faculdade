algoritmo "semnome"
// Função : Escreva um algoritmo que calcule a média dos números digitados pelo usuário, se eles forem pares. Termine a leitura se o usuário digitar zero (0).
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
media : real
divisores,num,soma : inteiro
inicio
// Seção de Comandos
divisores <- 0
repita
   leia(num)
   se (num mod 2 = 0) entao
      soma <- soma + num
      se nao (num = 0) entao
         divisores <- divisores + 1
      fimse
   fimse
ate num = 0
media <- soma/divisores
escreval(media)
fimalgoritmo
