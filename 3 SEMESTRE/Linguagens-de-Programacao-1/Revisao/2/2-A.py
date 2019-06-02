lista = [1,2,3,4,5,6]
print(list(filter(lambda x: x%2 == 0, lista)))
print(list(filter(lambda x: x%2 != 0, lista)))
