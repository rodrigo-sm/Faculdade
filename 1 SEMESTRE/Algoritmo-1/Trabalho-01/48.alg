algoritmo "semnome"
// Função :
// Autor :
// Data : 02/03/2018
// Seção de Declarações
var
num,i,divisores,primo : inteiro
ehprimo : logico
inicio
// Seção de Comandos
escreval("==================================================")
escreval("Os 20 primeiros numeros primos sem o 1,2 e 3 são: ")
num <- 4
enquanto primo <= 20 faca
ehprimo <- verdadeiro
   para i de 2 ate num-1 faca
      se num mod i = 0 entao
         ehprimo <- falso
      fimse
   fimpara
   se (ehprimo = verdadeiro) ou (num = 1) entao
      escreval(num)
      primo <- primo + 1
      fimse
   num <- num + 1
fimenquanto
escreval("==================================================")
fimalgoritmo
