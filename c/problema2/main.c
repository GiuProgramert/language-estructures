#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_matriz(int fila, int columna, int matriz[][columna])
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void generar_matriz(int fila, int columna, int matriz[][columna])
{
    for (int i = 0; i < fila; i++)
    {
        for (int j = 0; j < columna; j++)
        {
            matriz[i][j] = (rand() % 10) + 1;
        }
    }
}

int main()
{
    FILE *archivoResultado;

    // Inicialización de la semilla para números aleatorios
    srand(time(NULL));

    int fila_matriz1, columna_matriz1, fila_matriz2, columna_matriz2;

    printf("Ingrese el número de filas de la matriz 1: ");
    scanf("%d", &fila_matriz1);

    printf("Ingrese el número de columnas de la matriz 1: ");
    scanf("%d", &columna_matriz1);

    printf("Ingrese el número de filas de la matriz 2: ");
    scanf("%d", &fila_matriz2);

    printf("Ingrese el número de columnas de la matriz 2: ");
    scanf("%d", &columna_matriz2);

    while (columna_matriz1 != fila_matriz2)
    {
        printf("El número de columnas de la matriz 1 debe ser igual al número de filas de la matriz 2\n");

        printf("Ingrese el número de filas de la matriz 1: ");
        scanf("%d", &fila_matriz1);

        printf("Ingrese el número de columnas de la matriz 1: ");
        scanf("%d", &columna_matriz1);

        printf("Ingrese el número de filas de la matriz 2: ");
        scanf("%d", &fila_matriz2);

        printf("Ingrese el número de columnas de la matriz 2: ");
        scanf("%d", &columna_matriz2);
    }

    int matriz1[fila_matriz1][columna_matriz1];
    int matriz2[fila_matriz2][columna_matriz2];

    generar_matriz(fila_matriz1, columna_matriz1, matriz1);
    generar_matriz(fila_matriz2, columna_matriz2, matriz2);

    printf("Matriz 1:\n");
    print_matriz(fila_matriz1, columna_matriz1, matriz1);

    printf("Matriz 2:\n");
    print_matriz(fila_matriz2, columna_matriz2, matriz2);

    int resultado[fila_matriz1][columna_matriz2];

	clock_t start_time = clock();

    for (int i = 0; i < fila_matriz1; i++)
    {
        for (int j = 0; j < columna_matriz2; j++)
        {
            resultado[i][j] = 0;
            for (int k = 0; k < columna_matriz1; k++)
            {
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

	clock_t end_time = clock();
    double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", execution_time);

    printf("Resultado\n");
    print_matriz(fila_matriz1, columna_matriz2, resultado);

    archivoResultado = fopen("../../resultado.txt", "w");
    if (archivoResultado == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    for (int i = 0; i < fila_matriz1; i++)
    {
        for (int j = 0; j < columna_matriz2; j++)
        {
            if (j == columna_matriz2 - 1)
            {
                fprintf(archivoResultado, "%d", resultado[i][j]);
            }
            else
            {
                fprintf(archivoResultado, "%d,", resultado[i][j]);
            }
        }
        fprintf(archivoResultado, "\n");
    }
}