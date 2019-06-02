class Quadrilatero(object):
    __base = 0.0
    __altura = 0.0

    def __init__(self, b, a):
        self.__base = b
        self.__altura = a

    def calcular_area(self):
        return self.__base*self.__altura

    def calcular_perimetro(self):
        return self.__base*2 + 2*self.__altura

class Quadrado(Quadrilatero):
    __lado = 0.0

    def __init__(self, l):
        self.__lado = l
        Quadrilatero.__init__(self, l, l)

class Trapezio(Quadrilatero):
    __base_menor = 0.0
    __base_maior = 0.0
    __altura = 0.0

    def __init__(self, bmenor, bmaior, alt):
        self.__base_menor = bmenor
        self.__base_maior = bmaior
        self.__altura = alt
        Quadrilatero.__init__(self, bmenor+bmaior, alt)

    def calcular_area(self):
        return Quadrilatero.calcular_area(self) / 2

thislist = [Quadrilatero(1,2), Quadrado(4), Trapezio(2,3,4)]
sumArea = 0
sumPerimetro = 0
for i in thislist:
    sumArea = sumArea + i.calcular_area()
    sumPerimetro = sumPerimetro + i.calcular_perimetro()
print("Soma da area: {}".format(sumArea))
print("Soma do perimetro: {}".format(sumPerimetro))
