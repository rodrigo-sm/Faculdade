class Quadrilatero(object):
    __base = 0.0
    __altura = 0.0

    def __init__(self, b, a):
        self.__base = b
        self.__altura = a

    def calcular_area(self):
        return b*a

    def calcular_perimetro(self):
        return b+b+a+a

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
        return Quadrilatero.calcular_area() / 2

