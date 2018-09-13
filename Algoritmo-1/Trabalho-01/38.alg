algoritmo "semnome"
// Função :
// Autor :
// Data : 09/03/2018
// Seção de Declarações
var
nome : caractere
i,dvn1,dvn2,dvn3 : inteiro
n1,n2,n3,soman1,soman2,soman3,mp_geral,mp : real
inicio
// Seção de Comandos
para i de 1 ate 50 faca
   Escreval("Informe o nome do aluno e suas tres notas: ")
   leia(nome,n1,n2,n3)
   mp <- (n1*2+n2*4+n3*3)/9
   se (mp >= 7) entao
      escreval("O aluno ",nome," conseguiu media ",mp," entao foi aprovado")
   senao
      escreval("O aluno ",nome," conseguiu media ",mp," entao foi reprovado")
   fimse
   soman1 <- soman1 + n1
   dvn1 <- dvn1 + 1
   soman2 <- soman2 + n2
   dvn2 <- dvn2 + 1
   soman3 <- soman3 + n3
   dvn3 <- dvn3 + 1
fimpara
mp_geral <- (((soman1/dvn1)*2)+((soman2/dvn2)*4)+((soman3/dvn3)*3))/9
escreval("A media geral da turma foi: ",mp_geral)
fimalgoritmo
