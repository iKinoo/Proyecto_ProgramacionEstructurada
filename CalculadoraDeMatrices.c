#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int **matriz_a,
    **matriz_b;
int filas_a, columnas_a,
    filas_b, columnas_b;
int escalar = 0;

// esenciales
int** reservar_memoria_matriz(int filas, int columnas);
void liberar_memoria_matriz(int** matriz, int filas);
int** leer_matriz(int* filas, int* columnas);
// auxiliares
int leer_escalar();
void imprimir_matriz(int** matriz, int filas, int columnas);
// funciones principales
void sumar_matrices(int** matriz_a, int** matriz_b);
void mult_matriz_escalar(int** matriz, int escalar);
void multiplicar_matrices(int** matriz_a, int** matriz_b);

// por usar
// void transpuesta_matriz(int[][N]);

int main()
{
    do {
        int opcion = 0;

        puts("||Calculadora de matrices||\n");
        puts("Seleccione la operacion a realizar:\n");
        puts("[1] = Suma de matrices\n[2] = Multiplicacion de matrices por una escalar\n");
        puts("[3] = Multiplicacion de matrices\n[4] = Transpuesta de una matriz\n");
        puts("[5] = Inversa de una matriz (Gauss-Jordan)\n[6] = Sistema de ecuaciones (Gauss-Jordan)\n");
        puts("[7] = Determinante de una matriz\n[8] = Sistema de ecuaciones (Cramer)\n");

        scanf("%i", &opcion);

        switch (opcion) {
        case 1: // sumar matrices

            matriz_a = leer_matriz(&filas_a, &columnas_a);
            matriz_b = leer_matriz(&filas_b, &columnas_b);

            sumar_matrices(matriz_a, matriz_b);

            liberar_memoria_matriz(matriz_a, filas_a);
            liberar_memoria_matriz(matriz_b, filas_b);

            getch();
            break;
        case 2: // multiplicar matriz por un escalar

            matriz_a = leer_matriz(&filas_a, &columnas_a);
            escalar = leer_escalar();

            mult_matriz_escalar(matriz_a, escalar);

            liberar_memoria_matriz(matriz_a, filas_a);

            getch();
            break;
        case 3: // multiplicaicion de matrices
            matriz_a = leer_matriz(&filas_a, &columnas_a);
            matriz_b = leer_matriz(&filas_b, &columnas_b);

            multiplicar_matrices(matriz_a, matriz_b);

            liberar_memoria_matriz(matriz_a, filas_a);
            liberar_memoria_matriz(matriz_b, filas_b);

            getch();
            break;
        default:
            puts("Operacion no valida\n");
            getch();
            break;
        }
    } while (1); // what the fuck does this mean

    return 0;
}
// ------------------------------
// FUNCIONES ESENCIALES
int** reservar_memoria_matriz(int filas, int columnas)
{
    int** matriz;

    // RESERVANDO MEMORIA PARA LA MATRIZ
    matriz = (int**)malloc(filas * sizeof(int*)); // reservando memoria para el No. de filas
    if (matriz == NULL) {
        puts("Error al asignar memoria");
    }
    for (int i = 0; i < filas; i++) {

        matriz[i] = (int*)malloc(columnas * sizeof(int)); // por cada fila, reservando memoria para columnas
    }
    return matriz;
}
void liberar_memoria_matriz(int** matriz, int filas)
{
    // liberando memoria de las columnas por cada fila
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    // liberando memoria de la matriz en si
    free(matriz);
}
int** leer_matriz(int* filas, int* columnas)
{
    int** matriz;

    puts("Ingrese el numero de filas de la matriz: ");
    scanf("%d", filas);

    puts("Ingrese el numero de columnas de la matriz: ");
    scanf("%d", columnas);

    // reservando memoria
    matriz = reservar_memoria_matriz(*filas, *columnas);

    // leyendo datos
    int t = 1;
    for (int i = 0; i < (*filas); i++) {
        int total = (*filas) * (*columnas);

        for (int j = 0; j < (*columnas); j++) {
            printf("(%d/%d) Ingrese para [%d][%d]: ", t, total, i, j);
            scanf("%d", &matriz[i][j]);

            t++;
        }
    }
    imprimir_matriz(matriz, *filas, *columnas);

    return matriz;
}
// ----------------------------------------
// FUNCIONES AUXILIARES

int leer_escalar()
{
    puts("Ingrese el numero a escalar: ");
    scanf("%i", &escalar);
    return escalar;
}
void imprimir_matriz(int** matriz, int filas, int columnas)
{
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            printf("%i ", matriz[f][c]);
        }
        putchar('\n');
    }
}

// ----------------------------------------
// FUNCIONES PRINCIPALES

void sumar_matrices(int** matriz_a, int** matriz_b)
{
    int** matriz_suma;

    if ((filas_a != filas_b) || (columnas_a != columnas_b)) {
        puts("No se puden sumar las matrices, dimensiones diferentes");

    } else {
        // reservando memoria para la matriz suma
        matriz_suma = reservar_memoria_matriz(filas_a, columnas_a);

        // REALIZANDO LA SUMA

        for (int i = 0; i < filas_a; i++) {
            for (int j = 0; j < columnas_a; j++) {
                matriz_suma[i][j] = matriz_a[i][j] + matriz_b[i][j];
            }
        }

        puts("El resultado de la suma es: \n");
        imprimir_matriz(matriz_suma, filas_a, columnas_a);

        liberar_memoria_matriz(matriz_suma, filas_a);
    }
}

void mult_matriz_escalar(int** matriz, int escalar)
{
    int** matriz_escalada = reservar_memoria_matriz(filas_a, columnas_a);

    for (int c = 0; c < filas_a; c++) {
        for (int f = 0; f < columnas_a; f++) {
            matriz_escalada[c][f] = escalar * matriz[c][f];
        }
    }
    puts("La matriz escalada es:\n");
    imprimir_matriz(matriz_escalada, filas_a, columnas_a);
    liberar_memoria_matriz(matriz_escalada, filas_a);
}
void multiplicar_matrices(int** matriz_a, int** matriz_b)
{
    int** matriz_multiplicacion;
    /* A = filas_a × columnas_a         B = filas_b × columnas_b
    DEBE:       columas_a == filas_b
    ENTONCES:   M = filas_a × columnas_b
    */
    int filas_m = filas_a;
    int columnas_m = columnas_b;

    if (columnas_a != filas_b) {
        puts("Las matrices no son compatibles");
    } else {

        matriz_multiplicacion = reservar_memoria_matriz(filas_m, columnas_m);

        // inicializando matriz en 0
        for (int i = 0; i < filas_m; i++) {
            for (int j = 0; j < columnas_m; j++) {
                matriz_multiplicacion[i][j] = 0;
            }
        }

        for (int i = 0; i < filas_a; i++) {
            for (int j = 0; j < columnas_b; j++) {
                for (int k = 0; k < columnas_a; k++) {
                    matriz_multiplicacion[i][j] += (matriz_a[i][k] * matriz_b[k][j]);
                }
            }
        }
        puts("RESULTADO DE MULTIPLICACION: ");
        imprimir_matriz(matriz_multiplicacion, filas_m, columnas_m);
        liberar_memoria_matriz(matriz_multiplicacion, filas_m);
    }
}
