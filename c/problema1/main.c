#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#define MAX 3000

struct PalabrasFrecuencia
{
	char palabra[50];
	int freq;
};

// Función de comparación para qsort (orden descendente por frecuencia)
int comparar_palabras(const void *a, const void *b)
{
	const struct PalabrasFrecuencia *palabraA = (const struct PalabrasFrecuencia *)a;
	const struct PalabrasFrecuencia *palabraB = (const struct PalabrasFrecuencia *)b;

	// Ordenar en orden descendente por frecuencia
	return palabraB->freq - palabraA->freq;
}

void contar_palabras(const char *str)
{
	// Se inicializa un arreglo de estructuras de tipo PalabrasFrecuencia
	struct PalabrasFrecuencia palabras[MAX] = {{"", 0}};

	// Se realiza una copia del string para no modificar el original
	char copia_str[6000];
	strncpy(copia_str, str, sizeof(copia_str) - 1);
	copia_str[sizeof(copia_str) - 1] = '\0';

	char *token = strtok(copia_str, " ");

	while (token != NULL)
	{
		int encontrado = 0;

		for (int i = 0; i < MAX; i++)
		{
			// Si la palabra ya está en el arreglo, se incrementa su frecuencia
			if (strcmp(palabras[i].palabra, token) == 0)
			{
				palabras[i].freq++;
				encontrado = 1;
				break;
			}
			// Si la palabra no está en el arreglo, se agrega
			else if (palabras[i].palabra[0] == '\0')
			{
				strcpy(palabras[i].palabra, token);
				palabras[i].freq++;
				encontrado = 1;
				break;
			}
		}

		token = strtok(NULL, " ");
	}

	qsort(palabras, MAX, sizeof(struct PalabrasFrecuencia), comparar_palabras);

	// Imprimir resultados
	printf("Conteo de palabras\n");
	// Imprimir resultados ordenados
	for (int i = 0; i < 10; i++)
	{
		if (palabras[i].palabra[0] == '\0' || palabras[i].freq == 0)
			break;

		printf("%d: %s - %d veces\n", i + 1, palabras[i].palabra, palabras[i].freq);
	}
}

void limpiarTexto(char *textoSucio, char *textoLimpio)
{
	while (*textoSucio)
	{
		// Si el carácter no es un signo de puntuación, se agregará al texto limpio
		if (!ispunct((unsigned char)*textoSucio))
		{
			*textoLimpio = tolower((unsigned char)*textoSucio);
			textoLimpio++;
		}
		textoSucio++;
	}
	// Termina la cadena limpia con un carácter nulo
	*textoLimpio = '\0';
}

int main()
{
    FILE *archivo;
    char *textoSucio;
    char *textoLimpio;

    // Abrir archivo
    archivo = fopen("../../texto_prueba.txt", "r");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    // Determinar el tamaño del archivo
    fseek(archivo, 0, SEEK_END);
    long tamanoTexto = ftell(archivo);
    rewind(archivo);

    // Asignar memoria
    textoSucio = (char *)malloc((tamanoTexto + 1) * sizeof(char));
    if (textoSucio == NULL)
    {
        perror("No se pudo asignar memoria");
        fclose(archivo);
        return 1;
    }

    textoLimpio = (char *)malloc((tamanoTexto + 1) * sizeof(char));
    if (textoLimpio == NULL)
    {
        perror("No se pudo asignar memoria");
        fclose(archivo);
        free(textoSucio);
        return 1;
    }

    // Leer archivo
    fread(textoSucio, 1, tamanoTexto, archivo);
    fclose(archivo);
    textoSucio[tamanoTexto] = '\0'; // Asegurar que la cadena está terminada en null

	clock_t start_time = clock();
    // Limpiar texto
    limpiarTexto(textoSucio, textoLimpio);

    // Contar palabras
    contar_palabras(textoLimpio);

	clock_t end_time = clock();
	double execution_time = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Tiempo de ejecución: %f segundos\n", execution_time);

    // Liberar memoria
    free(textoSucio);
    free(textoLimpio);

    return 0;
}
