# Lectura del archivo
archivo = File.open('../../texto_prueba.txt', 'r')
texto_sucio = archivo.read
archivo.close

# Se limpian los signos de puntuación para hacer el conteo de palabras
# mediante una expresión regular
texto_limpio = texto_sucio.gsub(/[[:punct:]]/, '').downcase

conteo_palabras = {}

# Separar el texto en palabras y contar cuántas veces aparece cada una
# slit por defecto separa por espacios
texto_limpio.split.each do |palabra|
    if conteo_palabras[palabra]
        conteo_palabras[palabra] += 1
    else
        conteo_palabras[palabra] = 1
    end
end

# Ordenamos el diccionario por la cantidad de veces que aparece cada palabra
conteo_palabras_sort = conteo_palabras.sort_by { |palabra, conteo| - conteo }

# Imprimir el resultado
# Los primeros 10
# Para imprimir con el indice se debe usar each_with_index
conteo_palabras_sort.first(10).each_with_index do |(palabra, cantidad), index|
    puts "#{index + 1}: #{palabra} #{cantidad} veces"
end