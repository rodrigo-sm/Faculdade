algoritmo "semnome"
// Função :
// Autor :
// Data : 23/02/2018
// Seção de Declarações 
var
anos,meses,dias,dia : inteiro

inicio
// Seção de Comandos 
escreval("Informe sua idade em anos,meses e dias:")
leia(anos)
leia(meses)
leia(dias)
dia <- anos * 365 + meses * 30 + dias
escreval("Sua idade em dias é:",dia)
fimalgoritmo
