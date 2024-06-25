def generar_matriz(filas, columnas)
    matriz = []
    
    for i in 0..filas-1
        fila = []
        for j in 0..columnas-1
            fila.push(rand(1..10))
        end

        matriz.push(fila)
    end
    
    return matriz
end

def print_matriz(matriz)
    for i in 0..matriz.length-1
        for j in 0..matriz[i].length-1
            print "#{matriz[i][j]} "
        end
        puts
    end
end

puts "Ingrese el número de filas de la matriz 1:"
fila_matriz1 = gets.chomp.to_i

puts "Ingrese el número de columnas de la matriz 1:"
columna_matriz1 = gets.chomp.to_i

puts "Ingrese el número de filas de la matriz 2:"
fila_matriz2 = gets.chomp.to_i

puts "Ingrese el número de columnas de la matriz 2:"
columna_matriz2 = gets.chomp.to_i

while columna_matriz1 != fila_matriz2
    puts "El número de columnas de la matriz 1 debe ser igual al número de filas de la matriz 2"
    
    puts "Ingrese el número de filas de la matriz 1:"
    fila_matriz1 = gets.chomp.to_i

    puts "Ingrese el número de columnas de la matriz 1:"
    columna_matriz1 = gets.chomp.to_i

    puts "Ingrese el número de filas de la matriz 2:"
    fila_matriz2 = gets.chomp.to_i

    puts "Ingrese el número de columnas de la matriz 2:"
    columna_matriz2 = gets.chomp.to_i
end

matriz1 = generar_matriz(fila_matriz1, columna_matriz1)
matriz2 = generar_matriz(fila_matriz2, columna_matriz2)

puts "Matriz 1:"
print_matriz(matriz1)

puts "Matriz 2:"
print_matriz(matriz2)

resultado = []
for i in 0..fila_matriz1-1
    fila = []

    for j in 0..columna_matriz2-1
        suma = 0
        for k in 0..columna_matriz1-1
            suma += matriz1[i][k] * matriz2[k][j]
        end

        fila.push(suma)
    end

    resultado.push(fila)
end

puts "resultado"
print_matriz(resultado)