#include <stdio.h>
#include <math.h>
#include "stdlib.h"

#include "../headers/segundaEntrega.h"
#include "../headers/matrizDinamica.h"

float determinante_sarrus_matriz(float **matriz)
{
    float dp = matriz[0][0] * matriz[1][1] * matriz[2][2] + matriz[1][0] * matriz[2][1] * matriz[0][2] + matriz[2][0] * matriz[0][1] * matriz[1][2];

    float ds = matriz[0][2] * matriz[1][1] * matriz[2][0] + matriz[1][2] * matriz[2][1] * matriz[0][0] + matriz[2][2] * matriz[0][1] * matriz[1][0];

    printf("Det(A) = (%.2f * %.2f * %.2f + %.2f * %.2f * %.2f + %.2f * %.2f * %.2f) - ", matriz[0][0], matriz[1][1], matriz[2][2], matriz[1][0], matriz[2][1], matriz[0][2], matriz[2][0], matriz[0][1], matriz[1][2]);
    printf("(%.2f * %.2f * %.2f + %.2f * %.2f * %.2f + %.2f * %.2f * %.2f)\n", matriz[0][2], matriz[1][1], matriz[2][0], matriz[1][2], matriz[2][1], matriz[0][0], matriz[2][2], matriz[0][1], matriz[1][0]);

    printf("  Det(A) = (%.2f - %.2f)\n", dp, ds);
    printf("    Det(A) = %.2f", dp - ds);
    printf("\n");
    return dp - ds;
}

float disminuir_matriz(float **matriz, int filas, int columnas, int limite, float escalar)
{
    int band = 0;
    float cofactor = 0;
    float **submatriz = reservar_memoria_matriz(filas, columnas);
    for (int f = 0, i = 0; f < filas_a && i < filas; f++, i++)
    {

        (f == limite && band == 0) ? (f++, band = 1) : 0;

        for (int c = 1, j = 0; c < columnas_a && j < columnas; c++, j++)
        {
            submatriz[i][j] = matriz[f][c];
        }
    }
    printf("Submatriz: \n");
    imprimir_matriz(submatriz, filas, columnas);
    if (filas == 3 && columnas == 3)
    {
        cofactor = pow(-1, limite) * escalar * determinante_sarrus_matriz(submatriz);
        liberar_memoria_matriz(submatriz, filas);
        return cofactor;
    }
    else
    {
        return tomar_fila(submatriz, filas, columnas);
    }
}

float tomar_fila(float **matriz, int filas, int columnas)
{
    float det_final = 0;
    // Envíamos un valor de la fila elegida
    for (int f = 0; f < filas_a; f++)
    {
        float det_sub = disminuir_matriz(matriz, (filas - 1), (columnas - 1), f, matriz[f][0]);
        printf("      Determinante de la submatriz = %.2f\n", det_sub);
        printf("        Suma Det(A) = %.2f + %.2f\n", det_final, det_sub);
        printf("\n");
        det_final += det_sub; // llamada a la función para obtener su submatriz
    }
    return det_final;
}

void determinante_matriz(float **matriz)
{
    // Método para matrices 1x1
    float determinante = 0;
    if (filas_a == 1 && columnas_a == 1)
    {
        determinante = matriz[0][0];
        // Método para matrices 2x2
    }
    else if (filas_a == 2 && columnas_a == 2)
    {
        float dp = matriz[0][0] * matriz[1][1];
        float ds = matriz[1][0] * matriz[0][1];
        determinante = dp - ds;
        printf("Determinante = (%.2f * %.2f) - (%.2f * %.2f)\n", matriz[0][0], matriz[1][1], matriz[1][0], matriz[0][1]);
        printf("Determinante = %.2f - %.2f\n", dp, ds);
    }
    else if (filas_a == 3 && columnas_a == 3)
    {
        // Método para matrices 3x3 metodo por cofactores{
        determinante = determinante_sarrus_matriz(matriz);
    }
    else
    {
        // Método para dimensiones mayores a 3x3
        determinante = tomar_fila(matriz, filas_a, columnas_a);
    }
    printf("\n");
    printf("El determinante de la matriz es: [%.2f]\n", determinante);
    return;
}

void resolverGaussJordan(float **matriz_a, int nVariables)
{
    int coeficientePivote = 0, coeficienteACero = 0;

    for (int i = 0; i < nVariables; i++)
    {
        for (int j = 0; j < nVariables; j++)
        {
            if (j == i)
            {
                continue;
            }
            coeficientePivote = matriz_a[i][i]; // coeficiente del pivote
            coeficienteACero = matriz_a[j][i];  // coeficiente al que tenemos que convertir en 0

            for (int k = 0; k < nVariables + 1; k++)
            {
                imprimir_matriz(matriz_a, nVariables, nVariables + 1);
                matriz_a[j][k] = (coeficientePivote * matriz_a[j][k]) + (coeficienteACero * matriz_a[i][k] * (-1));
                system("pause");
                system("cls");
            }
            puts("");
        }
    }

    for (int i = 0; i < nVariables; i++)
    {
        int pivote = matriz_a[i][i];

        for (int j = 0; j < nVariables + 1; j++)
        {
            imprimir_matriz(matriz_a, nVariables, nVariables + 1);
            matriz_a[i][j] /= pivote;
            system("pause");
            system("cls");
        }
    }
    imprimir_matriz(matriz_a, nVariables, nVariables + 1);

    puts("solución: ");
    for (int i = 0; i < nVariables; i++)
    {
        switch (i)
        {
        case 0:
            printf("x = %.2f\n", matriz_a[i][nVariables]);
            break;
        case 1:
            printf("y = %.2f\n", matriz_a[i][nVariables]);
            break;
        case 2:
            printf("z = %.2f\n", matriz_a[i][nVariables]);
            break;
        case 3:
            printf("w = %.2f\n", matriz_a[i][nVariables]);
            break;
        default:
            break;
        }
    }
    system("pause");
    system("cls");
}

float **copiarMatriz(float **matrizOriginal, int filas, int columnas)
{
    float **matrizCopiada = reservar_memoria_matriz(filas, columnas);

    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            matrizCopiada[i][j] = matrizOriginal[i][j];
        }
    }
    return matrizCopiada;
}

void inversaGaussJordan(float **matriz_a)
{
    float **matrizIngresada = copiarMatriz(matriz_a, filas_a, filas_a);
    // dimensiones de la matriz
    int n = filas_a;
    int m = columnas_a;

    if (filas_a != columnas_a)
    {
        printf("La matriz no es cuadrada, no se puede obtener su inversa.\n");
        return;
    }

    // se crea una matriz identidad de la misma dimension que la matriz a
    float **matriz_b = reservar_memoria_matriz(n, m);
    for (int i = 0; i < n; i++)
    {
        matriz_b[i][i] = 1;
    }

    // se realiza el proceso de Gauss-Jordan
    for (int i = 0; i < n; i++)
    {
        // se busca el valor mayor en la columna
        int max_fila = i;
        for (int j = i; j < n; j++)
        {
            if (fabs(matriz_a[j][i]) > fabs(matriz_a[max_fila][i]))
            {
                max_fila = j;
            }
        }

        // se intercambian filas para que el valor mayor quede en la diagonal
        if (max_fila != i)
        {
            for (int j = 0; j < m; j++)
            {
                float temp = matriz_a[i][j];
                matriz_a[i][j] = matriz_a[max_fila][j];
                matriz_a[max_fila][j] = temp;

                temp = matriz_b[i][j];
                matriz_b[i][j] = matriz_b[max_fila][j];
                matriz_b[max_fila][j] = temp;
            }
        }

        // se divide la fila i por el valor de la diagonal para que tenga un 1 en la diagonal
        float pivot = matriz_a[i][i];
        for (int j = 0; j < m; j++)
        {
            matriz_a[i][j] /= pivot;
            matriz_b[i][j] /= pivot;
        }

        // se realiza la eliminación hacia adelante
        for (int j = i + 1; j < n; j++)
        {
            float factor = matriz_a[j][i];
            for (int k = 0; k < m; k++)
            {
                matriz_a[j][k] -= factor * matriz_a[i][k];
                matriz_b[j][k] -= factor * matriz_b[i][k];
            }
        }
    }

    // se realiza la eliminación hacia atrás
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            float factor = matriz_a[j][i];
            for (int k = 0; k < m; k++)
            {
                matriz_a[j][k] -= factor * matriz_a[i][k];
                matriz_b[j][k] -= factor * matriz_b[i][k];
            }
        }
    }
    printf("Matriz ingresada:\n");
    imprimir_matriz(matrizIngresada, filas_a, columnas_a);
    // se imprime la matriz inversa
    printf("\nMatriz inversa:\n");
    imprimir_matriz(matriz_b, n, m);

    // se libera la memoria
    liberar_memoria_matriz(matrizIngresada, filas_a);
    liberar_memoria_matriz(matriz_b, n);
}
void metodocramer(float **matriz_a)
{
    // obtener la dimensión de la matriz
    int n = filas_a;

    // matriz de coeficientes
    float **coeficientes = reservar_memoria_matriz(n, n);
    // matriz de resultados
    float **resultados = reservar_memoria_matriz(n, 1);

    // Extraer coeficientes y resultados de la matriz_a
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            coeficientes[i][j] = matriz_a[i][j];
        }
        resultados[i][0] = matriz_a[i][n];
    }

    // Calcular el determinante de la matriz de coeficientes
    float det = 0;
    if (n == 2)
    {
        det = coeficientes[0][0] * coeficientes[1][1] - coeficientes[0][1] * coeficientes[1][0];
    }
    else
    {
        det = determinante_sarrus_matriz(coeficientes);
    }

    if (det == 0)
    {
        printf("El sistema de ecuaciones no tiene solución única.\n");
        return;
    }

    printf("Solución del sistema de ecuaciones:\n");
    for (int i = 0; i < n - 1; i++)
    {
        float **temp = reservar_memoria_matriz(n, n);
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (k == i)
                {
                    temp[j][k] = resultados[j][0];
                }
                else if (k == n - 1)
                {
                    temp[j][k] = coeficientes[j][n - 1];
                }
                else
                {
                    temp[j][k] = coeficientes[j][k];
                }
            }
        }

        // Calcular el determinante de la nueva matriz
        float det_temp = 0;
        if (n == 2)
        {
            det_temp = temp[0][0] * temp[1][1] - temp[0][1] * temp[1][0];
        }
        else
        {
            det_temp = determinante_sarrus_matriz(temp);
        }

        // Imprimir la solución de la variable x_i
        printf("x%d = %.2f\n", i + 1, det_temp / det);

        // Liberar la memoria de la matriz temporal
        liberar_memoria_matriz(temp, n);
    }

    float **temp = reservar_memoria_matriz(n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n - 1)
            {
                temp[i][j] = resultados[i][0];
            }
            else
            {
                temp[i][j] = coeficientes[i][j];
            }
        }
    }

    float det_temp = 0;
    if (n == 2)
    {
        det_temp = temp[0][0] * temp[1][1] - temp[0][1] * temp[1][0];
    }
    else
    {
        det_temp = determinante_sarrus_matriz(temp);
    }

    // Imprimir la solución de y
    printf("y = %.2f\n", det_temp / det);

    // Liberar la memoria de la matriz temporal
    liberar_memoria_matriz(temp, n);

    // Liberar la memoria de las matrices de coeficientes y resultados
    liberar_memoria_matriz(coeficientes, n);
}
