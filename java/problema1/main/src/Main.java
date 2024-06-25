import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        String textoSucio;
        String textoLimpio;
        Map<String, Integer> conteoPalabras = new HashMap<String, Integer>();
        List<Map.Entry<String, Integer>> conteoPalabrasSort;

        try {
            // Lectura del archivo
            FileReader fr = new FileReader("texto_prueba.txt");
            BufferedReader archivo = new BufferedReader(fr);

            textoSucio = archivo.readLine();

            // Se limpian los signos de puntuación para hacer el conteo de palabras
            // mediante una expresión regular
            textoLimpio = textoSucio
                    .replaceAll("[!\"#$%&'()*+,-./:;<=>?@\\[\\]^_`{|}~]", "")
                    .toLowerCase();

            for (String palabra: textoLimpio.split(" ")) {
                if (conteoPalabras.containsKey(palabra)) {
                    conteoPalabras.put(
                            palabra,
                            conteoPalabras.get(palabra) + 1
                    );
                } else {
                    conteoPalabras.put(palabra, 1);
                }
            }

            // Diccionario que almacenará la cantidad de veces que se repite cada palabra
            conteoPalabrasSort = new ArrayList<>(conteoPalabras.entrySet());

            // Ordenamos el diccionario por la cantidad de veces que aparece cada palabra
            Collections.sort(conteoPalabrasSort, (entrada1, entrada2) -> entrada2.getValue().compareTo(entrada1.getValue()));

            // Imprimir el resultado
            for (int i = 0; i < 10; i++) {
                String palabra = conteoPalabrasSort.get(i).getKey();
                Integer numero = conteoPalabrasSort.get(i).getValue();

                System.out.println(i + 1 + ": " + palabra + " - " + numero + " veces");
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}