import random

n = 3
rango_inferior = 0
rango_superior = 1000

numeros = random.sample(range(rango_inferior, rango_superior + 1), n)
print(*numeros, sep=' ', end='')
