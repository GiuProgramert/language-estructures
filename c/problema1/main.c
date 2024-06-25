#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

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
	char copia_str[4000];
	strcpy(copia_str, str);

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

	// Es necesario saber el tamaño del texto para poder leerlo
	long tamanoTexto = 4000;

	// Lectura del archivo
	archivo = fopen("../../texto_prueba.txt", "r");
	if (archivo == NULL)
	{
		perror("Error al abrir el archivo");
		return 1;
	}

	textoSucio = (char *)malloc(tamanoTexto * sizeof(char));

	if (textoSucio == NULL)
	{
		perror("No se pudo asignar memoria");
		fclose(archivo);
		return 1;
	}

	textoLimpio = (char *)malloc(tamanoTexto * sizeof(char));
	if (textoLimpio == NULL)
	{
		perror("No se pudo asignar memoria");
		fclose(archivo);
		free(textoSucio);
		return 1;
	}

	fscanf(archivo, "%[^\n]s", textoSucio);
	fclose(archivo);

	// Limpieza del texto sacando los signos y convirtiendo a minúsculas
	limpiarTexto(textoSucio, textoLimpio);

	contar_palabras(textoLimpio);

	return 0;
}