algoritmo "semnome"
// Função :
// Autor :                         n1 ate n2  - div * 2 / n2 - div * 2 ate n2 - div / n2-div ate n2
// Data : 16/03/2018               1  ate 9 - 3 * 2 / 9-3*2 ate 9-3 / 9-3 ate 9
// Seção de Declarações            1 ate 3/ 3 ate 6/ 6 ate 9
var
i,n1,n2,soma,d,d1,d2 : inteiro
inicio
// Seção de Comandos
escreval("digite dois numeros")
leia(n1)
leia(n2)
para i de n1 ate n2 faca
soma <- soma + 1
fimpara
d <- soma div 3
d1 <- n2 - d * 2
d2 <- n2 - d
escreval("============================")
escreval("Intervalo de ",n1+1," ate ",d1-1)
para i de n1+1 ate d1-1 faca
escreval(i)
fimpara
escreval("============================")
escreval("Intervalo de ",d1," ate ",d2-1)
para i de d1 ate d2-1 faca
escreval(i)
fimpara
escreval("============================")
escreval("Intervalo de ",d2," ate ",n2-1)
para i de d2 ate n2-1 faca
escreval(i)
fimpara
fimalgoritmo
