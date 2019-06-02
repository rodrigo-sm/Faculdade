class Conjunto(object):
    __nums = []

    def __init__(self, lista):
        self.__nums = lista

    def maior(self):
        maior = self.__nums[0]
        for n in self.__nums:
            if(maior < n):
                maior = n
        return maior

    def menor(self):
        menor = self.__nums[0]
        for n in self.__nums:
            if(menor > n):
                menor = n
        return menor

lista = [1,2,3,4,5,6,7]
n = Conjunto(lista)
print("Menor: ", n.menor())
print("Maior: ", n.maior())
