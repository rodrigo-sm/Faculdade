algoritmo "semnome"
// Função :
// Autor :
// Data : 10/03/2018
// Seção de Declarações
var
sexo,idade,z,x,total_idadem,total_idade : inteiro
altura,k,j,total_alturaf,media_alturaf,media_idadem,percentual : real
inicio
// Seção de Comandos
repita
   escreva("Informe seu sexo(0-feminino e 1 - masculino): ")
   leia(sexo)
   escreva("Informe sua idade: ")
   leia(idade)
   escreva("Informe sua altura: ")
   leia(altura)
   escreval()
   k <- k + 1
   total_idade <- total_idade + idade
   se sexo = 0 entao
      total_alturaf <- total_alturaf + altura
      z <- z + 1
   fimse
   se sexo = 1 entao
      total_idadem <- total_idadem + idade
      x <- x + 1
   fimse
   se (idade >= 18) e (idade <= 35) entao
      j <- j + 1
   fimse
ate k => 1000
escreval("A media da idade do grupo é: ",total_idade / k)
se z > 0 entao
   media_alturaf <- total_alturaf  / z
fimse
escreval("A media da altura das mulheres é: ",media_alturaf)
se x > 0 entao
   media_idadem <- total_idadem / x
fimse
escreval("A media  da idade dos homens é: ",media_idadem)
se j > 0 entao
   percentual <- (100 * j)/k):2:1
fimse
escreval("O percentual de pessoas com idade entre 18 e 35 anos é: ",percentual,"%")

fimalgoritmo
