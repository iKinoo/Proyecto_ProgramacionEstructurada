/*
INTEGRANTES:
    - Gutiérrez Cohuo José Luis
    - Méndez Villanueva Luis Gerardo
    - Pacab Canul Rodrigo Joaquín
*/

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#include "headers/lecturaDeEntrada.h"
#include "headers/matrizDinamica.h"
#include "headers/primeraEntrega.h"
#include "headers/segundaEntrega.h"

float **matriz_a,
    **matriz_b;

int filas_a, columnas_a,
    filas_b, columnas_b;

float leerFlotante();

int main()
{
    int nVariables = 0;
    float escalar = 0;

    int opcion = 1;

    do
    {
        puts("|| Calculadora de matrices ||\n");
        puts("Seleccione la operación a realizar:\n");
        puts("[1] = Suma de matrices");
        puts("[2] = Multiplicación de matrices por una escalar");
        puts("[3] = Multiplicación de matrices");
        puts("[4] = Transpuesta de una matriz");
        puts("[5] = Inversa de una matriz (Gauss-Jordan)");
        puts("[6] = Sistema de ecuaciones (Gauss-Jordan)");
        puts("[7] = Determinante de una matriz");
        puts("[8] = Sistema de ecuaciones (Cramer)\n");

        printf("Ingrese una opción: ");
        opcion = leerEntero();

        switch (opcion)
        {

        case 1: // sumar matrices

            puts(">\tIngrese las dimensiones para la primera matriz");
            leer_dimensiones(&filas_a, &columnas_a);
            puts(">\tIngrese las dimensiones para la segunda matriz");
            leer_dimensiones(&filas_b, &columnas_b);

            if ((filas_a != filas_b) || (columnas_a != columnas_b))
            {
                puts("\nNo se pueden sumar las matrices, dimensiones diferentes\n");
                getch();
                break;
            }

            puts(">\tleyendo la primera matriz");
            matriz_a = leer_matriz(filas_a, columnas_a);
            puts(">\tleyendo la segunda matriz");
            matriz_b = leer_matriz(filas_b, columnas_b);

            sumar_matrices(matriz_a, matriz_b);

            liberar_memoria_matriz(matriz_a, filas_a);
            liberar_memoria_matriz(matriz_b, filas_b);

            system("pause");
            system("cls");

            break;

        case 2: // multiplicar matriz por un escalar

            leer_dimensiones(&filas_a, &columnas_a);
            matriz_a = leer_matriz(filas_a, columnas_a);

            leer_escalar(&escalar);

            mult_matriz_escalar(matriz_a, escalar);

            liberar_memoria_matriz(matriz_a, filas_a);

            system("pause");
            system("cls");
            break;
        case 3: // multiplicación de matrices

            puts(">\tIngrese las dimensiones para la primera matriz");
            leer_dimensiones(&filas_a, &columnas_a);
            puts(">\tIngrese las dimensiones para la segunda matriz");
            leer_dimensiones(&filas_b, &columnas_b);

            if (columnas_a != filas_b)
            {
                puts("\nNo se pueden multiplicar las matrices, dimensiones diferentes\n");
            }
            else
            {

                puts(">\tleyendo la primera matriz");
                matriz_a = leer_matriz(filas_a, columnas_a);
                puts(">\tleyendo la segunda matriz");
                matriz_b = leer_matriz(filas_b, columnas_b);

                multiplicar_matrices(matriz_a, matriz_b);

                liberar_memoria_matriz(matriz_a, filas_a);
                liberar_memoria_matriz(matriz_b, filas_b);
            }

            system("pause");
            system("cls");
            break;

        case 4: // matriz transpuesta
            leer_dimensiones(&filas_a, &columnas_a);
            matriz_a = leer_matriz(filas_a, columnas_a);

            transpuesta_matriz(matriz_a);

            liberar_memoria_matriz(matriz_a, filas_a);

            system("pause");
            system("cls");
            break;

        case 5:
            leer_dimensiones(&filas_a, &columnas_a);
            matriz_a = leer_matriz(filas_a, columnas_a);

            inversaGaussJordan(matriz_a);

            liberar_memoria_matriz(matriz_a, filas_a);

            system("pause");
            system("cls");
            break;

        case 6:
            puts("Ingrese el número de variables del sistema: ");
            nVariables = leerEntero();
            validarDimension(&nVariables);

            matriz_a = leer_matriz(nVariables, nVariables + 1);
            resolverGaussJordan(matriz_a, nVariables);

            liberar_memoria_matriz(matriz_a, nVariables);

            system("pause");
            system("cls");
            break;
        case 7:
            leer_dimensiones(&filas_a, &columnas_a);
            if (filas_a != columnas_a)
            {
                puts("\nDimensiones no válidas, ingrese una matriz cuadrada\n");
            }
            else
            {
                matriz_a = leer_matriz(filas_a, columnas_a);
                determinante_matriz(matriz_a);
                liberar_memoria_matriz(matriz_a, filas_a);
            }

            system("pause");
            system("cls");
            break;
        case 8:
            leer_dimensiones(&filas_a, &columnas_a);
            matriz_a = leer_matriz(filas_a, columnas_a);

            metodocramer(matriz_a);

            liberar_memoria_matriz(matriz_a, filas_a);

            system("pause");
            system("cls");
            break;
        default:

            if (opcion == 0)
            {
                puts("saliendo...");
            }
            else
            {
                puts("Operación no válida");
            }

            system("pause");
            system("cls");
            break;
        }
    } while (opcion != 0);

    return 0;
}
