/*
INTEGRANTES:

    - Guti�rrez Cohuo Jos� Luis
    - M�ndez Villanueva Luis Gerardo
    - Pacab Canul Rodrigo Joaqu�n

*/

#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float **matriz_a,
    **matriz_b;

int filas_a, columnas_a,
    filas_b, columnas_b;

// esenciales
float **reservar_memoria_matriz(int filas, int columnas);
void liberar_memoria_matriz(float **matriz, int filas);
void leer_dimensiones(int *filas, int *columnas);
float **leer_matriz(int filas, int columnas);
void validarDimension(int *dimension);
void imprimir_matriz(float **matriz, int filas, int columnas);
// auxiliares
void leer_escalar(float *escalar);
int leerEntero();
float leerFlotante();
// funciones principales
void sumar_matrices(float **matriz_a, float **matriz_b);
void mult_matriz_escalar(float **matriz, int escalar);
void transpuesta_matriz(float **matriz);
void multiplicar_matrices(float **matriz_a, float **matriz_b);
void inversaGaussJordan(float **matriz_a);
void resolverGaussJordan(float **matriz_a, int nVariables);
void metodocramer(float **matriz_a);

// Conjunto de funciones para calcular la determinante
float determinante_sarrus_matriz(float **matriz);
void determinante_matriz(float **matriz);
float tomar_fila(float **matriz, int filas, int columnas);
float disminuir_matriz(float **matriz, int filas, int columnas, int limite, float escalar);

int main()
{
    int nVariables = 0;
    float escalar = 0;

    int opcion = 1;

    do
    {

        puts("|| Calculadora de matrices ||\n");
        puts("Seleccione la operaci�n a realizar:\n");
        puts("[1] = Suma de matrices");
        puts("[2] = Multiplicaci�n de matrices por una escalar");
        puts("[3] = Multiplicaci�n de matrices");
        puts("[4] = Transpuesta de una matriz");
        //-------- funcionalidades de la segunda entrega
        puts("[5] = Inversa de una matriz (Gauss-Jordan)");
        puts("[6] = Sistema de ecuaciones (Gauss-Jordan)");
        puts("[7] = Determinante de una matriz");
        puts("[8] = Sistema de ecuaciones (Cramer)\n");

        // scanf("%i", &opcion);
        printf("Ingrese una opci�n: ");
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
        case 3: // multiplicaci�n de matrices

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
            puts("Ingrese el n�mero de variables del sistema: ");
            // scanf("%d", &nVariables);
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
                puts("\nDimensiones no v�lidas, ingrese una matriz cuadrada\n");
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
                puts("Operaci�n no v�lida");
            }

            system("pause");
            system("cls");
            break;
        }
    } while (opcion != 0);

    return 0;
}
// ------------------------------
// FUNCIONES ESENCIALES
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
        puts("[!] Ha ingresado un valor mayor a 4 o menor a 1, int�ntelo de nuevo.");
        printf("Ingrese el valor correspondiente [1-4]: ");
        // scanf("%d", dimension);
        *dimension = leerEntero();
    }
}
void leer_dimensiones(int *filas, int *columnas)
{
    printf("Ingrese el n�mero de filas de la matriz [1-4]: ");
    // scanf("%d", filas);
    *filas = leerEntero();
    validarDimension(filas);

    printf("Ingrese el n�mero de columnas de la matriz [1-4]: ");
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
// ----------------------------------------
// FUNCIONES AUXILIARES

void leer_escalar(float *escalar)
{
    puts("Ingrese el n�mero a escalar: ");
    // scanf("%i", escalar);
    *escalar = leerFlotante();
}

int leerEntero()
{
    char entrada[100];
    int entero;

    while (1)
    {
        fflush(stdin);
        fgets(entrada, sizeof(entrada), stdin);
        fflush(stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        // Validar si la entrada es un entero
        char *valorNoNumerico;
        entero = strtol(entrada, &valorNoNumerico, 10);

        // Comprobar si no hubo caracteres inválidos después del número
        if (strlen(entrada) != 0 && *valorNoNumerico == '\0')
        {
            break;
        }

        printf("Entrada inv�lida. Por favor, ingrese un entero v�lido.\n");
    }

    return entero;
}
float leerFlotante()
{
    char entrada[100];
    float flotante;

    while (1)
    {
        fflush(stdin);
        fgets(entrada, sizeof(entrada), stdin);
        fflush(stdin);
        entrada[strcspn(entrada, "\n")] = '\0';

        // Validar si la entrada es un flotante
        char *valorNoNumerico;
        flotante = strtof(entrada, &valorNoNumerico);

        // Comprobar si no hubo caracteres inv�lidos despu�s del n�mero
        if (strlen(entrada) != 0 && *valorNoNumerico == '\0')
        {
            break;
        }

        printf("Entrada inv�lida. Por favor, ingrese un n�mero v�lido.\n");
    }

    return flotante;
}

// ----------------------------------------
// FUNCIONES PRINCIPALES

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

void mult_matriz_escalar(float **matriz, int escalar)
{
    float **matriz_escalada = reservar_memoria_matriz(filas_a, columnas_a);

    for (int c = 0; c < filas_a; c++)
    {
        for (int f = 0; f < columnas_a; f++)
        {
            matriz_escalada[c][f] = escalar * matriz[c][f];
        }
    }
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
    puts("La transpuesta de la matriz ingresada es:\n");
    imprimir_matriz(matriz_transpuesta, columnas_a, filas_a);
    liberar_memoria_matriz(matriz_transpuesta, columnas_a);
}
void resolverGaussJordan(float **matriz_a, int nVariables)
{
    int coeficientePivote = 0, coeficienteACero = 0;

    for (int i = 0; i < nVariables; i++)
    {
        printf("\n\nPivote %d: %f\n", i + 1, matriz_a[i][i]);

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
                matriz_a[j][k] = (coeficientePivote * matriz_a[j][k]) + (coeficienteACero * matriz_a[i][k] * (-1));
            }
            puts("");
        }
    }

    for (int i = 0; i < nVariables; i++)
    {

        int pivote = matriz_a[i][i];

        for (int j = 0; j < nVariables + 1; j++)
        {
            matriz_a[i][j] /= pivote;
        }
    }
    imprimir_matriz(matriz_a, nVariables, nVariables + 1);
}

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
    // Env�amos un valor de la fila elegida
    for (int f = 0; f < filas_a; f++)
    {
        float det_sub = disminuir_matriz(matriz, (filas - 1), (columnas - 1), f, matriz[f][0]);
        printf("      Determinante de la submatriz = %.2f\n", det_sub);
        printf("        Suma Det(A) = %.2f + %.2f\n", det_final, det_sub);
        printf("\n");
        det_final += det_sub; // llamada a la funci�n para obtener su submatriz
    }
    return det_final;
}

void determinante_matriz(float **matriz)
{
    // M�todo para matrices 1x1
    float determinante = 0;
    if (filas_a == 1 && columnas_a == 1)
    {
        determinante = matriz[0][0];
        // M�todo para matrices 2x2
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
        // M�todo para matrices 3x3 metodo por cofactores{
        determinante = determinante_sarrus_matriz(matriz);
    }
    else
    {
        // M�todo para dimensiones mayores a 3x3
        determinante = tomar_fila(matriz, filas_a, columnas_a);
    }
    printf("\n");
    printf("El determinante de la matriz es: [%.2f]\n", determinante);
    return;
}

void inversaGaussJordan(float **matriz_a)
{
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

        // se realiza la eliminaci�n hacia adelante
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

    // se realiza la eliminaci�n hacia atr�s
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

    // se imprime la matriz inversa
    printf("\nMatriz inversa:\n");
    imprimir_matriz(matriz_b, n, m);

    // se libera la memoria
    liberar_memoria_matriz(matriz_b, n);
}
void metodocramer(float **matriz_a)
{
    // obtener la dimensi�n de la matriz
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
        printf("El sistema de ecuaciones no tiene soluci�n �nica.\n");
        return;
    }

    printf("Soluci�n del sistema de ecuaciones:\n");
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

        // Imprimir la soluci�n de la variable x_i
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

    // Imprimir la soluci�n de y
    printf("y = %.2f\n", det_temp / det);

    // Liberar la memoria de la matriz temporal
    liberar_memoria_matriz(temp, n);

    // Liberar la memoria de las matrices de coeficientes y resultados
    liberar_memoria_matriz(coeficientes, n);
}

