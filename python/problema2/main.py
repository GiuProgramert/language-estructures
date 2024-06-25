import random

def generar_matriz(filas, columnas):
    # Rellenar la matriz con filas y columnas con número aleatorios del 1 al 10

    matriz = []
    
    for i in range(filas):
        fila = []
        for j in range(columnas):
            fila.append(random.randint(0, 10))
        matriz.append(fila)

    return matriz

def print_matriz(matriz):
    for fila in matriz:
        print(fila)

filas_matriz1 = int(input("Ingrese el número de filas de la matriz 1: "))
columnas_matriz1 = int(input("Ingrese el número de columnas de la matriz 1: "))

filas_matriz2 = int(input("Ingrese el número de filas de la matriz 2: "))
columnas_matriz2 = int(input("Ingrese el número de columnas de la matriz 2: "))

while columnas_matriz1 != filas_matriz2:
    print("El número de columnas de la matriz 1 debe ser igual al número de filas de la matriz 2")
    filas_matriz1 = int(input("Ingrese el número de filas de la matriz 1: "))
    columnas_matriz1 = int(input("Ingrese el número de columnas de la matriz 1: "))

    filas_matriz2 = int(input("Ingrese el número de filas de la matriz 2: "))
    columnas_matriz2 = int(input("Ingrese el número de columnas de la matriz 2: "))

matriz1 = generar_matriz(filas_matriz1, columnas_matriz1)
matriz2 = generar_matriz(filas_matriz2, columnas_matriz2)

print("Matriz 1")
print_matriz(matriz1)

print("Matriz 2")
print_matriz(matriz2)

# Multiplicar las matrices
resultado = []
for i in range(filas_matriz1):
    fila = []
    for j in range(columnas_matriz2):
        suma = 0
        for k in range(columnas_matriz1):
            suma += matriz1[i][k] * matriz2[k][j]
        fila.append(suma)
    resultado.append(fila)

print("Resultado")
print_matriz(resultado)