#include <stdio.h>
#include <stdlib.h>

#include "../headers/matrizDinamica.h"
#include "../headers/lecturaDeEntrada.h"

float **reservar_memoria_matriz(int filas, int columnas)
{
    float **matriz;

    // RESERVANDO MEMORIA PARA LA MATRIZ
    matriz = (float **)calloc(filas, sizeof(float *)); // reservando memoria para el No. de filas
    if (matriz == NULL)
    {
        puts("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < filas; i++)
    {

        matriz[i] = (float *)calloc(columnas, sizeof(float)); // por cada fila, reservando memoria para columnas
        if (matriz[i] == NULL)
        {
            puts("Error al asignar memoria");
            exit(EXIT_FAILURE);
        }
    }
    return matriz;
}
void liberar_memoria_matriz(float **matriz, int filas)
{
    // liberando memoria de las columnas por cada fila
    for (int i = 0; i < filas; i++)
    {
        free(matriz[i]);
    }
    // liberando memoria de la matriz en si
    free(matriz);
}
void validarDimension(int *dimension)
{
    while (*dimension > 4 || *dimension < 1)
    {
        puts("[!] Ha ingresado un valor mayor a 4 o menor a 1, inténtelo de nuevo.");
        printf("Ingrese el valor correspondiente [1-4]: ");
        // scanf("%d", dimension);
        *dimension = leerEntero();
    }
}
void leer_dimensiones(int *filas, int *columnas)
{
    printf("Ingrese el número de filas de la matriz [1-4]: ");
    // scanf("%d", filas);
    *filas = leerEntero();
    validarDimension(filas);

    printf("Ingrese el número de columnas de la matriz [1-4]: ");
    // scanf("%d", columnas);
    *columnas = leerEntero();
    validarDimension(columnas);
}

float **leer_matriz(int filas, int columnas)
{
    float **matriz;

    // reservando memoria
    matriz = reservar_memoria_matriz(filas, columnas);

    // leyendo datos
    int total = filas * columnas;
    int t = 1;

    for (int i = 0; i < (filas); i++)
    {
        for (int j = 0; j < (columnas); j++)
        {

            imprimir_matriz(matriz, filas, columnas);
            printf("(%d/%d) Ingrese para [%d][%d]: ", t, total, i, j);
            // scanf("%f", &matriz[i][j]);
            matriz[i][j] = leerFlotante();

            system("cls");

            t++;
        }
    }
    imprimir_matriz(matriz, filas, columnas);
    system("pause");
    system("cls");

    return matriz;
}
void imprimir_matriz(float **matriz, int filas, int columnas)
{
    printf("/   ");
    for (int l = 0; l < columnas; l++)
    {
        printf("       ");
    }
    puts(" \\");

    for (int f = 0; f < filas; f++)
    {
        printf("| ");
        for (int c = 0; c < columnas; c++)
        {

            if (matriz[f][c] < 10 && matriz[f][c] >= 0)
            {
                printf("   ");
            }
            else if (matriz[f][c] < 100 && matriz[f][c] >= 0)
            {
                printf("  ");
            }
            else if (matriz[f][c] < 1000 && matriz[f][c] >= 0)
            {
                printf(" ");
            }

            printf("%.2f ", matriz[f][c]);
        }
        puts("|");
    }
    putchar('\\');
    for (int l = 0; l < columnas; l++)
    {
        printf("       ");
    }
    puts("    /");
}