algoritmo "semnome"
// Função :
// Autor :
// Data : 05/03/2018
// Seção de Declarações
var
i,num,d : inteiro
prod : real
ehprimo : logico
inicio
// Seção de Comandos
prod <- 1
num <- 92
enquanto num < 1478 faca
ehprimo <- verdadeiro
   para i de 2 ate num-1 faca
      se num mod i = 0 entao
         ehprimo <- falso
      fimse
   fimpara
   se (ehprimo = verdadeiro)  entao
      escreval(num)
      prod <- prod * num
      fimse
   num <- num + 1
fimenquanto
escreval(prod)
fimalgoritmo
