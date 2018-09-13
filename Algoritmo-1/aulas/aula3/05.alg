algoritmo "semnome"
// Função :
// Autor :
// Data : 21/02/2018
// Seção de Declarações
var
    velocidade,tempo,distancia,combustivel : real

inicio
// Seção de Comandos
//Recebe a velocidade media e tempo gasto
escreva("Informe a velocidade média:")
leia(velocidade)
escreva("Informe o tempo gasto:")
leia(tempo)
//Calcula a distancia e o combustivel consumido
distancia <- tempo * velocidade
combustivel <- distancia / 12
//Apresenta a velocidade media,tempo,distancia e combustivel
escreva("A velocidade media é:",velocidade)
escreval()
escreva("O tempo gasto é:",tempo)
escreval()
escreva("A distancia percorrida é:",distancia)
escreval()
escreva("A quantidade de litros de combustivel usado na viagem é:",combustivel)

fimalgoritmo
