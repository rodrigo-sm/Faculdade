algoritmo "Matriz Inca"
// Função : Verificar se uma matriz é inca
// Autor : Rodrigo Suarez Moreira
// Data : 27/04/2018
// Seção de Declarações 
var
m : vetor [1..10,1..10] de inteiro
n,cf,ci,li,lf,i,j,x : inteiro
 b : logico
inicio
// Seção de Comandos
b <- verdadeiro
escreva("Informe a ordem da matriz: ")
leia(n)
escreval("---------------------------------")
escreval("Informe a matriz:")
para i de 1 ate n faca
     para j de 1 ate n faca
          leia(m[i,j])
     fimpara
fimpara
escreval("---------------------------------")
li <- 1
lf <- n
ci <- 1
cf <- n
x <- m[1,1]
enquanto (b) e (ci < cf) e (li < lf) faca
    para i de ci ate cf faca
         se (m[li,i] <> x) entao
            b <- falso
         fimse
         x <- x + 1
    fimpara
    li <- li + 1
    para i de li ate lf faca
         se (m[i,cf] <> x ) entao
            b <- falso
         fimse
         x <- x + 1
    fimpara
    cf <- cf - 1
    para i de cf ate ci passo -1 faca
         se (m[lf,i] <> x ) entao
            b <- falso
         fimse
         x <- x + 1
    fimpara
    lf <- lf - 1
    para i de lf ate li passo -1 faca
         se (m[i,ci] = x) entao
            b <> falso
         fimse
         x <- x + 1
    fimpara
    ci <- ci + 1
fimenquanto
se b entao
   escreval("A matriz e inca")
senao
   escreval("A matriz nao e inca")
fimse
fimalgoritmo
