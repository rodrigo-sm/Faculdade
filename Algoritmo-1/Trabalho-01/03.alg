algoritmo "semnome"
// Função :
// Autor :
// Data : 08/03/2018
// Seção de Declarações
var
salario,soma_salario,soma_filho,media_salario,media_filho,percentual100,maior_salario : real
pessoas,pessoas100,filho,divisores_salario,divisores_filho : inteiro
inicio
// Seção de Comandos
divisores_salario <- 0
divisores_filho <- 0
pessoas <- 0
pessoas100 <- 0
salario <- 1
enquanto salario > 0 faca
   escreval("Para encerrar o programa digite salario negativo")
   escreval("Informe o seu salario e quantidade de filhos")
   leia(salario)
   se salario < 0 entao
      interrompa
   fimse
   leia(filho)
   pessoas <- pessoas + 1
   soma_salario <- soma_salario + salario
   divisores_salario <- divisores_salario + 1
   soma_filho <- soma_filho + filho
   divisores_filho <- divisores_filho + 1
   se maior_salario < salario entao
      maior_salario <- salario
   fimse
   se salario <= 100 entao
      pessoas100 <- pessoas100 + 1
   fimse
fimenquanto
media_salario <- soma_salario / divisores_salario
media_filho <- soma_filho / divisores_filho
percentual100 <- 100 * pessoas100 / pessoas
escreval("A media salarial é: ",media_salario)
escreval("A media de filhos é: ", media_filho)
escreval("o maior salario é: ",maior_salario)
escreval("O percentual de pessoas com salario ate 100$ é: ",percentual100)
fimalgoritmo
