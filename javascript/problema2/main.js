import readline from "readline";
import fs from "node:fs";

// Como estamos usando node.js para correr el entorno de javascript
// Es necesario que usemos el módulo readline para poder leer la entrada
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

// Función que nos permitirá leer la entrada del usuario
// y retornarla como una promesa ya que la lectura del input 
// debe detener el flujo del programa hasta que el usuario ingrese
// un valor
function input(textoPregunta) {
  return new Promise((resolve) => {
    rl.question(textoPregunta, (respuesta) => {
      resolve(parseInt(respuesta, 10));
    });
  });
}

function generarMatriz(filas, columnas) {
  // Rellenar la matriz con filas y columnas con número aleatorios del 1 al 10

  const matriz = [];

  for (let i = 0; i < filas; i++) {
    const fila = [];

    for (let j = 0; j < columnas; j++) {
      fila.push(Math.floor(Math.random() * 10) + 1);
    }

    matriz.push(fila);
  }
  return matriz;
}

function printMatriz(matriz) {
  for (let i = 0; i < matriz.length; i++) {
    console.log(matriz[i]);
  }
}

// Ahora sí realizaremos la lectura normal de las entradas
let filaMatriz1 = await input("Ingrese el número de filas de la matriz 1: ");
let columnaMatriz1 = await input("Ingrese el número de columnas de la matriz 1: ");

let filaMatriz2 = await input("Ingrese el número de filas de la matriz 2: ");
let columnaMatriz2 = await input("Ingrese el número de columnas de la matriz 2: ");

while (columnaMatriz1 !== filaMatriz2) {
  console.log("El número de columnas de la matriz 1 debe ser igual al número de filas de la matriz 2")

  filaMatriz1 = await input("Ingrese el número de filas de la matriz 1: ");
  columnaMatriz1 = await input("Ingrese el número de columnas de la matriz 1: ");

  filaMatriz2 = await input("Ingrese el número de filas de la matriz 2: ");
  columnaMatriz2 = await input("Ingrese el número de columnas de la matriz 2: ");
}

// Debemos cerrar la interfaz de lectura para que el programa no se quede esperando
// y podamos continuar con la ejecución
rl.close()

// Generamos las matrices
const matriz1 = generarMatriz(filaMatriz1, columnaMatriz1);
const matriz2 = generarMatriz(filaMatriz2, columnaMatriz2);

console.log("Matriz 1")
printMatriz(matriz1);
console.log("Matriz 2");
printMatriz(matriz2);

console.time("tiempo");
// Multiplicación de matrices
const resultado = [];
for (let i = 0; i < filaMatriz1; i++) {
  const fila = [];

  for (let j = 0; j < columnaMatriz2; j++) {
    let suma = 0;

    for (let k = 0; k < columnaMatriz1; k++) {
      suma += matriz1[i][k] * matriz2[k][j];
    }

    fila.push(suma);
  }

  resultado.push(fila);
}

console.timeEnd("tiempo");

console.log("resultado");
printMatriz(resultado);

const resultadoContenido = resultado.map(fila => fila.join(",")).join("\n");
// Escribir el resultado en un archivo
fs.writeFileSync("../resultado.txt", resultadoContenido, err => {
  if (err) {
    console.error(err)
  }
});