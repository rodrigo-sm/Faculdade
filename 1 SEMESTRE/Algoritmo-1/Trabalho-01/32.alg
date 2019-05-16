algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
altura,mediaf,maior,menor,somaf,somap : real
i,sexo,totalf,totalp : inteiro
inicio
// Seção de Comandos
escreva("Informe a altura: ")
leia(altura)
escreva("Informe o sexo(1 - masculino e 2 - feminino): ")
leia(sexo)
escreval()
maior <- altura
menor <- altura
se sexo = 2 entao
   somaf <- somaf + altura
   totalf <- totalf + 1
fimse
totalp <- 1
somap <- somap + altura
para i de 1 ate 2 faca
   escreva("Informe a altura: ")
   leia(altura)
   escreva("Informe o sexo(1 - masculino e 2 - feminino): ")
   leia(sexo)
   escreval()
   maior <- altura
   menor <- altura
   se sexo = 2 entao
      somaf <- somaf + altura
      totalf <- totalf + 1
   fimse
   totalp <- totalp + 1
   somap <- somap + altura
   se altura > maior entao
      maior <- altura
   fimse
   se menor > altura entao
      menor <- altura
   fimse
fimpara
se totalf > 0 entao
   mediaf <- somaf / totalf
fimse
escreval("A maior altura da turma é ",maior)
escreval("A menor altura da turma é ",menor)
escreval("A media das alturas das mulheres é ",mediaf)
escreval("A media da altura da turma é ",somap / totalp)
fimalgoritmo
