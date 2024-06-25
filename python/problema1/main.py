import string

# Lectura del archivo
archivo = open("texto_prueba.txt", "r")
texto_sucio = archivo.read()
archivo.close()

# string.punctuation contiene todos los signos de puntuación
texto_limpio = ''.join([c for c in texto_sucio if c not in string.punctuation]).lower()

# Diccionario que almacenará la cantidad de veces que aparece cada palabra
conteo_palabras = {}

# Separar el texto en palabras y contar cuántas veces aparece cada una
for palabra in texto_limpio.split(" "):
    if palabra in conteo_palabras:
        conteo_palabras[palabra] += 1
    else:
        conteo_palabras[palabra] = 1

# Ordenamos el diccionario por la cantidad de veces que aparece cada palabra
conteo_palabras_sort = list(
    sorted(conteo_palabras.items(), key=lambda item: item[1], reverse=True)
)

# Imprimir el resultado
print("Conteo de palabras")
for i in range(10):
    print(f"{i + 1}: {conteo_palabras_sort[i][0]} - {conteo_palabras_sort[i][1]} veces")
