lista = ['Oi', 'Ola', 'Bom dia']
print(lista)
lista = list(map(lambda x: x.upper(), lista))
print(lista)
max  = max(lista, key = len)

print(max)
