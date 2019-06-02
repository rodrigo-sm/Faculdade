class Conjunto(object):
    __nums = []

    def __init__(self, lista):
        self.__nums = lista

    def mediaPonderada(self):
        size = len(lista)
        soma_num = 0
        soma_div = 0
        if(size >= 5):
            for i in range(2):
                soma_num = soma_num + self.__nums[i] * 0.3
                soma_div = soma_div + 0.3
            for i in range(2,size-2):
                soma_num = soma_num + self.__nums[i] * 0.1
                soma_div = soma_div + 0.1
            for i in range(size-2,size):
                soma_num = soma_num + self.__nums[i] * 0.3
                soma_div = soma_div + 0.3
        return soma_num / soma_div

lista = [0.1, 0.2, 0.3, 0.4, 0.5]
objeto = Conjunto(lista)
print(objeto.mediaPonderada())
