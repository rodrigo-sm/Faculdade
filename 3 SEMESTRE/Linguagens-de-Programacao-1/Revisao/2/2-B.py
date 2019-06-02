from functools import reduce

lista = [1,2,3,4]
par = list(filter(lambda x: x%2 == 0, lista))
print(par)
soma = reduce(lambda x, y: x+y, par)
print(soma)
