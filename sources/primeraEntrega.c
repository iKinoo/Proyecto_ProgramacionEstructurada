#include <stdio.h>

#include "../headers/primeraEntrega.h"
#include "../headers/matrizDinamica.h"


void sumar_matrices(float **matriz_a, float **matriz_b)
{
    float **matriz_suma;

    if ((filas_a != filas_b) || (columnas_a != columnas_b))
    {
        puts("No se pueden sumar las matrices, dimensiones diferentes");
    }
    else
    {
        // reservando memoria para la matriz suma
        matriz_suma = reservar_memoria_matriz(filas_a, columnas_a);

        for (int i = 0; i < filas_a; i++)
        {
            for (int j = 0; j < columnas_a; j++)
            {
                matriz_suma[i][j] = matriz_a[i][j] + matriz_b[i][j];
            }
        }
        puts("Matriz A:");
        imprimir_matriz(matriz_a, filas_a, columnas_a);
        puts("Matriz B:");
        imprimir_matriz(matriz_b, filas_b, columnas_b);

        puts("El resultado de la suma es: \n");
        imprimir_matriz(matriz_suma, filas_a, columnas_a);

        liberar_memoria_matriz(matriz_suma, filas_a);
    }
}

void mult_matriz_escalar(float **matriz, float escalar)
{
    float **matriz_escalada = reservar_memoria_matriz(filas_a, columnas_a);

    for (int c = 0; c < filas_a; c++)
    {
        for (int f = 0; f < columnas_a; f++)
        {
            matriz_escalada[c][f] = escalar * matriz[c][f];
        }
    }
    puts("Matriz Ingresada: \n");
    imprimir_matriz(matriz, filas_a, columnas_a);
    printf("Escalar: %.2f\n", escalar);
    puts("La matriz escalada es:\n");
    imprimir_matriz(matriz_escalada, filas_a, columnas_a);
    liberar_memoria_matriz(matriz_escalada, filas_a);
}

void multiplicar_matrices(float **matriz_a, float **matriz_b)
{
    float **matriz_producto = reservar_memoria_matriz(filas_a, columnas_b);
    printf("\n");
    for (int c = 0; c < filas_a; c++)
    {
        for (int f = 0; f < columnas_b; f++)
        {
            printf("[%i, %i] = ",c , f);
            for (int k = 0; k < columnas_a; k++)
            {
                matriz_producto[c][f] += matriz_a[c][k] * matriz_b[k][f];
                printf(" %.2f * %.2f +", matriz_a[c][k], matriz_b[k][f] );
                if(k == (columnas_a-1)){
                    printf(" %.2f * %.2f ", matriz_a[c][k], matriz_b[k][f] );
                }
            }
            printf("\n");
        }
    }
    puts("Matriz producto: ");
    imprimir_matriz(matriz_producto, filas_a, columnas_b);
    liberar_memoria_matriz(matriz_producto, filas_a);

}
void transpuesta_matriz(float **matriz)
{
    float **matriz_transpuesta = reservar_memoria_matriz(columnas_a, filas_a);

    for (int c = 0; c < filas_a; c++)
    {
        for (int f = 0; f < columnas_a; f++)
        {
            matriz_transpuesta[f][c] = matriz[c][f];
        }
    }
    puts("Matriz ingresada: ");
    imprimir_matriz(matriz, filas_a, columnas_a);
    puts("La transpuesta de la matriz ingresada es:\n");
    imprimir_matriz(matriz_transpuesta, columnas_a, filas_a);
    liberar_memoria_matriz(matriz_transpuesta, columnas_a);
}
