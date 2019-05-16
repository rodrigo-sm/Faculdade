algoritmo "semnome"
// Função :
// Autor :
// Data : 08/03/2018
// Seção de Declarações
var
num,dilma,temer,macedo,rodrigo,nulo,branco : inteiro
inicio
// Seção de Comandos
escreval("0 - Saia do programa")
escreval("1 - Dilma")
escreval("2 - Temer")
escreval("3 - Fernando Macedo")
escreval("4 - Rodrigo Suarez")
escreval("5 - Voto Nulo")
escreval("6 - Voto em branco")
repita
   leia(num)
   escolha num
   caso 1
      dilma <- dilma + 1
   caso 2
      temer <- temer + 1
   caso 3
      macedo <- macedo + 1
   caso 4
      rodrigo <- rodrigo + 1
   caso 5
      nulo <- nulo + 1
   caso 6
      branco <- branco + 1
   fimescolha
ate num = 0
escreval("A quantidade de votos para Dilma foi: ",dilma)
escreval("A quantidade de votos para o Temer foi: ",temer)
escreval("A quantidade de votos para o Fernando Macedo foi: ",macedo)
escreval("A quantidade de votos para o Rodrigo Suarez foi : ",rodrigo)
escreval("A quantidade de votos nulo foi: ",nulo)
escreval("A quantidade de votos em branco foi: ",branco)
fimalgoritmo
