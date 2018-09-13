algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
 idade,qntd100,dv,maior,menor : inteiro
 soma,salario,media : real
 sexo : caractere
inicio
// Seção de Comandos
escreval("Para encerrar o programa digite uma idade negativa")

escreval("Informe sua idade,sexo(f/m) e salario")
leia(idade)
se idade > 0 entao
   leia(sexo)
   leia(salario)
   se (sexo = "f") e (salario <= 100) entao
      qntd100 <- qntd100 + 1
   fimse
   soma <- soma + salario
   dv <- dv + 1
   maior <- idade
   menor <- idade
   enquanto idade > 0 faca
      leia(idade)
      se idade > 0 entao
         leia(sexo)
         leia(salario)
         se maior < idade entao
            maior <- idade
         fimse
         se menor > idade entao
            menor <- idade
         fimse
         se (sexo = "f") e (salario <= 100) entao
            qntd100 <- qntd100 + 1
         fimse
         soma <- soma + salario
         dv <- dv + 1
      fimse
   fimenquanto
fimse
se soma > 0 entao
   media <- soma/dv
   escreval("A maior idade é ",maior," e a menor idade é ",menor)
   escreval("A media salarial é ",salario)
   escreval("A quantidade de mulheres que recebem ate 100$ é ",qntd100)
fimse


fimalgoritmo
