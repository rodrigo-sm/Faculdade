from functools import reduce

def fat(x):
    return reduce(lambda y, z: y*z, range(1,x), 1)

lista = [1,2,3,4,5,6,7,8,9,10]
print(lista)
fatorial = list(map(lambda x: fat(x), lista))
print(fatorial)
