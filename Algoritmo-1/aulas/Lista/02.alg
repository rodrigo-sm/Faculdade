algoritmo "semnome"
// Função :
// Autor :
// Data : 23/02/2018
// Seção de Declarações
var
r,s,A,B,C,D : real
inicio
// Seção de Comandos
escreva("Informe A,B e C")
leia(A)
leia(B)
leia(C)
r <- (A+B)^2
s <- (B+C)^2
D <- r + s / 2
se (A > 0) e (B > 0) e (C > 0) entao
   escreval("A distancia é ,",D)
senao
   escreval("nao foi possivel realizar a conta")
fimse
fimalgoritmo
