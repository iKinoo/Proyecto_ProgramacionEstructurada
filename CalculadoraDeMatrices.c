#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

int **matriz_a,
    **matriz_b;
int filas_a, columnas_a,
    filas_b, columnas_b;

#define M 2
#define N 2

// int matriz_a[M][N] = { { 0 } };
// int matriz_b[M][N] = { { 0 } };

int escalar = 0;

int leer_escalar();
int** leer_matriz(int* filas, int* columnas);
void imprimir_matriz(int** matriz, int filas, int columnas);
void sumar_matrices(int** matriz_a, int** matriz_b);
void liberar_memoria_matriz(int** matriz, int filas);
// por usar
void transpuesta_matriz(int[][N]);

// void mult_matriz_escalar(int matriz[][N], int escalar)
// {
//     int matriz_escalada[M][N] = { { 0 } };
//     for (int c = 0; c < M; c++) {
//         for (int f = 0; f < N; f++) {
//             matriz_escalada[c][f] = escalar * matriz[c][f];
//         }
//     }
//     puts("La matriz escalada es:\n");
//     imprimir_matriz(matriz_escalada);
// }

// void mult_matrices(int matriz_a[][N], int matriz_b[][N])
// {
//     if (M != N) {
//         puts("Las matrices no son compatibles");
//         return;
//     }
//     int matriz_mul[M][N] = { { 0 } };
//     for (int c = 0; c < M; c++) {
//         for (int f = 0; f < N; f++) {
//         }
//     }
// }

// por usar

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
        // case 2: // multiplicar matriz por un escalar
        //     leer_matriz(matriz_a);
        //     escalar = leer_escalar();
        //     mult_matriz_escalar(matriz_a, escalar);
        //     getch();
        //     break;
        // case 3: // multiplicaicion de matrices
        //     leer_matriz(matriz_a);
        //     leer_matriz(matriz_b);
        //     mult_matrices(matriz_a, matriz_b);
        //     getch();
        //     break;
        default:
            puts("Operacion no valida\n");
            getch();
            break;
        }
    } while (1); // what the fuck does this mean

    return 0;
}
int leer_escalar()
{
    puts("Ingrese el numero a escalar: ");
    scanf("%i", &escalar);
    return escalar;
}

int** leer_matriz(int* filas, int* columnas)
{
    int** matriz;

    puts("Ingrese el numero de filas de la matriz: ");
    scanf("%d", filas);

    puts("Ingrese el numero de columnas de la matriz: ");
    scanf("%d", columnas);

    // reservando memoria
    matriz = (int**)malloc((*filas) * sizeof(int*)); // reservando memoria para las filas
    if (matriz == NULL) {
        puts("Error al asignar memoria");
    }
    for (int i = 0; i < (*filas); i++) {
        matriz[i] = (int*)malloc((*columnas) * sizeof(int)); // reservando memoria para columnas por cada fila
        if (matriz[i] == NULL) {
            puts("Error al asignar memoria");
        }
    }

    // leyendo datos
    int t = 0;
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
void imprimir_matriz(int** matriz, int filas, int columnas)
{
    for (int f = 0; f < filas; f++) {
        for (int c = 0; c < columnas; c++) {
            printf("%i ", matriz[f][c]);
        }
        printf("\n");
    }
}

void sumar_matrices(int** matriz_a, int** matriz_b)
{
    int** matriz_suma;

    if ((filas_a != filas_b) || (columnas_a != columnas_b)) {
        puts("No se puden sumar las matrices, dimensiones diferentes");

    } else {
        // RESERVANDO MEMORIA PARA LA MATRIZ SUMA
        matriz_suma = (int**)malloc(filas_a * sizeof(int*)); // reservando memoria para el No. de filas
        if (matriz_suma == NULL) {

            puts("Error al asignar memoria");
        }
        for (int i = 0; i < filas_a; i++) {

            matriz_suma[i] = (int*)malloc(columnas_b * sizeof(int)); // por cada fila, reservando memoria para columnas
        }
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
void liberar_memoria_matriz(int** matriz, int filas)
{
    // liberando memoria de las columnas por cada fila
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    // liberando memoria de la matriz en si
    free(matriz);
}