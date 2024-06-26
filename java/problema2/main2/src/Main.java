import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;
import java.util.Scanner;

public class Main {
    static int[][] generarMatriz(int filas, int columnas) {
        int matriz[][] = new int[filas][columnas];
        Random random = new Random();

        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < filas; j++) {
                matriz[i][j] = random.nextInt(10) + 1;
            }
        }

        return matriz;
    }

    static void printMatriz(int [][] matriz) {
        for (int i = 0; i < matriz.length; i++) {
            for (int j = 0; j < matriz[i].length; j++) {
                System.out.print(matriz[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Ingrese el número de filas de la matriz 1: ");
        int filaMatriz1 = sc.nextInt();

        System.out.println("Ingrese el número de columnas de la matriz 1: ");
        int columnaMatriz1 = sc.nextInt();

        System.out.println("Ingrese el número de filas de la matriz 2: ");
        int filaMatriz2 = sc.nextInt();

        System.out.println("Ingrese el número de columnas de la matriz 2: ");
        int columnaMatriz2 = sc.nextInt();

        while (columnaMatriz1 != filaMatriz2) {
            System.out.println("Ingrese el número de filas de la matriz 1: ");
            filaMatriz1 = sc.nextInt();

            System.out.println("Ingrese el número de columnas de la matriz 1: ");
            columnaMatriz1 = sc.nextInt();

            System.out.println("Ingrese el número de filas de la matriz 2: ");
            filaMatriz2 = sc.nextInt();

            System.out.println("Ingrese el número de columnas de la matriz 2: ");
            columnaMatriz2 = sc.nextInt();
        }

        int[][] matriz1 = generarMatriz(filaMatriz1, columnaMatriz1);
        int[][] matriz2 = generarMatriz(filaMatriz2, columnaMatriz2);

        System.out.println("Matriz 1");
        printMatriz(matriz1);

        System.out.println("Matriz 2");
        printMatriz(matriz2);

        int[][] resultado = new int[filaMatriz1][columnaMatriz2];

        long startTime = System.nanoTime();
        for (int i = 0; i < filaMatriz1; i++) {
            for (int j = 0; j < columnaMatriz2; j++) {
                resultado[i][j] = 0;

                for (int k = 0; k < columnaMatriz1; k++) {
                    resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                }
            }
        }
        long endTime = System.nanoTime();
        System.out.println((endTime - startTime) / 1000000.0);

        System.out.println("Resultado");
        printMatriz(resultado);
        try {
            FileWriter fw = new FileWriter("resultado.txt");
            BufferedWriter archivoResultado = new BufferedWriter(fw);

            for (int i = 0; i < resultado.length; i++) {
                for (int j = 0; j < resultado[i].length; j++) {
                    if (j == columnaMatriz2 - 1) {
                        archivoResultado.write(Integer.toString(resultado[i][j]));
                    } else {
                        archivoResultado.write((Integer.toString(resultado[i][j]) + ","));
                    }
                }
                archivoResultado.newLine();
            }
            archivoResultado.close();
        } catch (IOException e) {
            System.err.println("Error al abrir el archivo: " + e.getMessage());
            e.printStackTrace();
        }

    }
}