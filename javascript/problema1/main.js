import fs from "node:fs";

// Lectura del archivo
const textoSucio = fs.readFileSync("../texto_prueba.txt", "utf8");

// Se limpian los signos de puntuación para hacer el conteo de palabras
// mediante una expresión regular
const textoLimpio = textoSucio
  .replace(/[!"#$%&'()*+,-./:;<=>?@[\]^_`{|}~]/g, "")
  .toLowerCase();

// Diccionario que almacenará la cantidad de veces que se repite cada palabra
const conteoPalabras = {};

// Separar el texto en palabras y contar cuántas veces aparece cada una
textoLimpio.split(" ").forEach((palabra) => {
  if (conteoPalabras[palabra]) {
    conteoPalabras[palabra] += 1;
  } else {
    conteoPalabras[palabra] = 1;
  }
});

// Ordenamos el diccionario por la cantidad de veces que aparece cada palabra
const conteoPalabrasSort = Object.entries(conteoPalabras).sort(
  ([, a], [, b]) => b - a
);

// Imprimir el resultado
for (let i = 0; i < 10; i++) {
  console.log(
    `${i + 1}: ${conteoPalabrasSort[i][0]} ${conteoPalabrasSort[i][1]} veces`
  );
}
