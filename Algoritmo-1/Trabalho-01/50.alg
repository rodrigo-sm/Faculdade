algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
d1,m1,a1,d2,m2,a2,soma1,soma2,diferenca : inteiro
inicio
// Seção de Comandos
Escreval("Informe o dia,mes e o ano da 1° data: ")
leia(d1)
leia(m1)
leia(a1)
escreval("===============================================")
escreval("Informe o dia,mes e o ano da 2° data: ")
leia(d2)
leia(m2)
leia(a2)
escreval("===============================================")
soma1 <- d1 + m1 * 30 + a1 * 365
soma2 <- d2 + m2 * 30 + a2 * 365
diferenca <- soma1 - soma2
se diferenca < 0 entao
   diferenca <- -(diferenca)
fimse
escreval("A diferença entre as duas datas em dias é: ",diferenca)
fimalgoritmo
