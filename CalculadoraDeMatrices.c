#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define M 2
#define N 2

int matriz_a[M][N] = { { 0 } };
int matriz_b[M][N] = { { 0 } };
int escalar = 0;

void leer_matriz(int[][N]);
int leer_escalar();
void imprimir_matriz(int[][N]);
void sumar_matrices(int[][N], int[][N]);
void mult_matriz_escalar(int[][N], int);
void mult_matrices(int[][N], int[][N]);

// por usar
void transpuesta_matriz(int[][N]);

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
            leer_matriz(matriz_a);
            leer_matriz(matriz_b);
            sumar_matrices(matriz_a, matriz_b);
            getch();
            break;
        case 2: // multiplicar matriz por un escalar
            leer_matriz(matriz_a);
            escalar = leer_escalar();
            mult_matriz_escalar(matriz_a, escalar);
            getch();
            break;
        case 3: // multiplicaicion de matrices
            leer_matriz(matriz_a);
            leer_matriz(matriz_b);
            mult_matrices(matriz_a, matriz_b);
            getch();
            break;
        default:
            puts("Operacion no valida\n");
            getch();
            break;
        }
    } while (1); // what the fuck does this mean
}

int leer_escalar()
{
    puts("Ingrese el numero a escalar: ");
    scanf("%i", &escalar);
    return escalar;
}
void leer_matriz(int matriz[][N])
{
    puts("Matriz inicializada en cero:\n");

    for (int c = 0; c < M; c++) {
        for (int f = 0; f < N; f++) {
            imprimir_matriz(matriz);
            printf("Ingrese el valor en la posicion [%i, %i]: ", c, f);
            scanf("%i", &matriz[c][f]);
        }
    }
    puts("Matriz leida:\n");
    imprimir_matriz(matriz);
}
void imprimir_matriz(int matriz[][N])
{
    for (int c = 0; c < M; c++) {
        for (int f = 0; f < N; f++) {
            printf("%i ", matriz[c][f]);
        }
        printf("\n");
    }
}

void sumar_matrices(int matriz_a[][N], int matriz_b[][N])
{
    int matriz_suma[M][N] = { { 0 } };
    for (int c = 0; c < M; c++) {
        for (int f = 0; f < N; f++) {

            matriz_suma[c][f] = matriz_a[c][f] + matriz_b[c][f];
        }
    }
    puts("El resultado de la suma es: \n");

    imprimir_matriz(matriz_suma);
}

void mult_matriz_escalar(int matriz[][N], int escalar)
{
    int matriz_escalada[M][N] = { { 0 } };
    for (int c = 0; c < M; c++) {
        for (int f = 0; f < N; f++) {
            matriz_escalada[c][f] = escalar * matriz[c][f];
        }
    }
    puts("La matriz escalada es:\n");
    imprimir_matriz(matriz_escalada);
}

void mult_matrices(int matriz_a[][N], int matriz_b[][N])
{
    if (M != N) {
        puts("Las matrices no son compatibles");
        return;
    }
    int matriz_mul[M][N] = { { 0 } };
    for (int c = 0; c < M; c++) {
        for (int f = 0; f < N; f++) {
        }
    }
}
