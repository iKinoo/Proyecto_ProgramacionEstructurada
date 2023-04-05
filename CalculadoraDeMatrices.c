#include <stdio.h>
#define M 2
#define N 2

int matriz_a[M][N];
int matriz_b[M][N];
int escalar = 0;

void leer_matriz(int[][N]);
int leer_escalar();
void sumar_matrices(int[][N], int[][N]);
void mult_matriz_escalar(int[][N], int);
void mult_matrices(int[][N], int[][N]);
void transpuesta_matriz(int[][N]);
void imprimir_matriz(int[][N]);

void imprimir_matriz(int matriz[][N])
{
    for (int c = 0; c < M; c++) {
        for (int f = 0; f < N; f++) {
            printf("%i ", matriz[c][f]);
        }
        printf("\n");
    }
}

int main()
{
    do {
        int op = 0;
        puts("||Calculadora de matrices||\n");
        puts("Seleccione la operacion a realizar:\n");
        puts("[1] = Suma de matrices\n[2] = Multiplicacion de matrices por una escalar\n");
        puts("[3] = Multiplicacion de matrices\n[4] = Transpuesta de una matriz\n");
        puts("[5] = Inversa de una matriz (Gauss-Jordan)\n[6] = Sistema de ecuaciones (Gauss-Jordan)\n");
        puts("[7] = Determinante de una matriz\n[8] = Sistema de ecuaciones (Cramer)\n");
        scanf("%i", &op);
        switch (op) {
        case 1:
            leer_matriz(matriz_a);
            leer_matriz(matriz_b);
            sumar_matrices(matriz_a, matriz_b);
            break;
        case 2:
            leer_matriz(matriz_a);
            escalar = leer_escalar();
            mult_matriz_escalar(matriz_a, escalar);
            break;
        case 3:
            leer_matriz(matriz_a);
            leer_matriz(matriz_b);
            mult_matrices(matriz_a, matriz_b);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        default:
            puts("Operacion no valida\n");
            break;
        }
    } while (1);
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
    imprimir_matriz(matriz);
    for (int c = 0; c < M; c++) {
        for (int f = 0; f < N; f++) {
            printf("Ingrese el valor en la posicion [%i, %i]: ", c, f);
            scanf("%i", &matriz[c][f]);
        }
    }
    puts("Matriz leida:\n");
    imprimir_matriz(matriz);
}

void sumar_matrices(int matriz[][N], int matriz_b[][N])
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
