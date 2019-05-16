algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
num,soma : inteiro
inicio
// Seção de Comandos
escreval("Para encerrar o programa digite '0'")
escreval("===================================")
escreval("Informe o(s) numero(s): ")
escreval("===================================")
repita
   leia(num)
   se num < 0 entao
      soma <- soma + num
   fimse
ate num = 0
escreval("===================================")
escreval("A somatoria de numeros negativos é: ",soma)

fimalgoritmo
