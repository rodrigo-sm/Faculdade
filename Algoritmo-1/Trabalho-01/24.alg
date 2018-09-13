algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
codigo : inteiro
preco_novo,preco_antigo,soma_antigo,soma_novo : real
k : inteiro
inicio
// Seção de Comandos
codigo <- 1
enquanto codigo >= 0 faca
   escreval("Informe o codigo do produto")
   leia(codigo)
   se codigo > 0 entao
      escreval("Informe o preço antigo do produto")
      leia(preco_antigo)
      preco_novo <- (preco_antigo * 0.2) + preco_antigo)
      escreval("O preço novo do produto é",preco_novo," reais")
      soma_antigo <- soma_antigo + preco_antigo
      soma_novo <- soma_novo + preco_novo
      k <- k + 1
   fimse
fimenquanto
se soma_antigo > 0 entao
   escreval("A media dos preços antigo dos produtos ",soma_antigo / k," reais")
   escreval("A media dos preços novo dos produtos ",soma_novo / k," reais")
fimse
fimalgoritmo

