#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float **matriz_a,
      **matriz_b;

int filas_a, columnas_a,
    filas_b, columnas_b;

int escalar = 0;
int nVariables = 0;

// esenciales
float** reservar_memoria_matriz(int filas, int columnas);
void liberar_memoria_matriz(float** matriz, int filas);
void leer_dimensiones(int* filas, int* columnas);
float** leer_matriz(int filas, int columnas);
void validarDimension(int* dimension);
void imprimir_matriz(float** matriz, int filas, int columnas);
// auxiliares
int leer_escalar(); // <-- realmente es necesario? solo si se va a utilizar en las demas funciones.
// funciones principales
void sumar_matrices(float** matriz_a, float** matriz_b);
void mult_matriz_escalar(float** matriz, int escalar);
void transpuesta_matriz(float** matriz);
void multiplicar_matrices(float** matriz_a, float** matriz_b);

// Conjunto de funciones para calcular la determinante 
float determinante_sarrus_matriz(float** matriz);
void determinante_matriz(float** matriz);
float tomar_fila(float** matriz, int filas, int columnas);
float disminuir_matriz(float** matriz,int filas,int columnas, int limite, float escalar);

int main()
{
    do {
        int opcion = 0;

        puts("|| Calculadora de matrices ||\n");
        puts("Seleccione la operacion a realizar:\n");
        puts("[1] = Suma de matrices");
        puts("[2] = Multiplicacion de matrices por una escalar");
        puts("[3] = Multiplicacion de matrices");
        puts("[4] = Transpuesta de una matriz");
        puts("[5] = Inversa de una matriz (Gauss-Jordan)");
        puts("[6] = Sistema de ecuaciones (Gauss-Jordan)");
        puts("[7] = Determinante de una matriz");
        puts("[8] = Sistema de ecuaciones (Cramer)\n");

        scanf("%i", &opcion);

        switch (opcion) {

        case 1: // sumar matrices
            leer_dimensiones(&filas_a, &columnas_a);
            matriz_a = leer_matriz(filas_a, columnas_a);

            leer_dimensiones(&filas_b, &columnas_b);
            matriz_b = leer_matriz(filas_b, columnas_b);

            sumar_matrices(matriz_a, matriz_b);

            liberar_memoria_matriz(matriz_a, filas_a);
            liberar_memoria_matriz(matriz_b, filas_b);

            getch();
            break;
        case 2: // multiplicar matriz por un escalar
            leer_dimensiones(&filas_a, &columnas_a);
            matriz_a = leer_matriz(filas_a, columnas_a);

            escalar = leer_escalar();

            mult_matriz_escalar(matriz_a, escalar);

            liberar_memoria_matriz(matriz_a, filas_a);

            getch();
            break;
        case 3: // multiplicaicion de matrices
            leer_dimensiones(&filas_a, &columnas_a);
            matriz_a = leer_matriz(filas_a, columnas_a);

            leer_dimensiones(&filas_b, &columnas_b);
            matriz_b = leer_matriz(filas_b, columnas_b);

            multiplicar_matrices(matriz_a, matriz_b);

            liberar_memoria_matriz(matriz_a, filas_a);
            liberar_memoria_matriz(matriz_b, filas_b);

            getch();
            break;

        case 4:
            leer_dimensiones(&filas_a, &columnas_a);
            matriz_a = leer_matriz(filas_a, columnas_a);

            transpuesta_matriz(matriz_a);

            liberar_memoria_matriz(matriz_a, filas_a);

            getch();
            break;

        case 6:
            puts("Ingrese el numero de variables del sistema: ");
            scanf("%d", &nVariables);
            validarDimension(&nVariables);

            matriz_a = leer_matriz(nVariables, nVariables + 1);

            liberar_memoria_matriz(matriz_a, nVariables);
            getch();
            break;
        case 7:
            leer_dimensiones(&filas_a, &columnas_a);
            matriz_a = leer_matriz(filas_a, columnas_a);

            determinante_matriz(matriz_a);

            liberar_memoria_matriz(matriz_a, filas_a);
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
float** reservar_memoria_matriz(int filas, int columnas)
{
    float** matriz;

    // RESERVANDO MEMORIA PARA LA MATRIZ
    matriz = (float**)calloc(filas, sizeof(float*)); // reservando memoria para el No. de filas
    if (matriz == NULL) {
        puts("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < filas; i++) {

        matriz[i] = (float*)calloc(columnas, sizeof(float)); // por cada fila, reservando memoria para columnas
        if (matriz[i] == NULL) {
            puts("Error al asignar memoria");
            exit(EXIT_FAILURE);
        }
    }
    return matriz;
}
void liberar_memoria_matriz(float** matriz, int filas)
{
    // liberando memoria de las columnas por cada fila
    for (int i = 0; i < filas; i++) {
        free(matriz[i]);
    }
    // liberando memoria de la matriz en si
    free(matriz);
}
void validarDimension(int* dimension)
{
    while (*dimension > 4 || *dimension < 1) {
        puts("[!] Ha ingresado un valor mayor a 4 o menor a 1, intentelo de nuevo.");
        printf("Ingrese el valor correspondiente [1-4]: ");
        scanf("%d", dimension);
    }
}
void leer_dimensiones(int* filas, int* columnas)
{
    printf("Ingrese el numero de filas de la matriz [1-4]: ");
    scanf("%d", filas);
    validarDimension(filas);

    printf("Ingrese el numero de columnas de la matriz [1-4]: ");
    scanf("%d", columnas);
    validarDimension(columnas);
}

float** leer_matriz(int filas, int columnas)
{
    float** matriz;

    // reservando memoria
    matriz = reservar_memoria_matriz(filas, columnas);

    // leyendo datos
    int total = filas * columnas;
    int t = 1;

    for (int i = 0; i < (filas); i++) {
        for (int j = 0; j < (columnas); j++) {

            imprimir_matriz(matriz, filas, columnas);
            printf("(%d/%d) Ingrese para [%d][%d]: ", t, total, i, j);
            scanf("%f", &matriz[i][j]);

            t++;
        }
    }
    imprimir_matriz(matriz, filas, columnas);

    return matriz;
}
void imprimir_matriz(float** matriz, int filas, int columnas)
{
    printf("/   ");
    for (int l = 0; l < columnas; l++) {
        printf("       ");
    }
    puts(" \\");

    for (int f = 0; f < filas; f++) {
        printf("| ");
        for (int c = 0; c < columnas; c++) {

            if (matriz[f][c] < 10 && matriz[f][c] >= 0) {
                printf("   ");
            } else if (matriz[f][c] < 100 && matriz[f][c] >= 0) {
                printf("  ");
            } else if (matriz[f][c] < 1000 && matriz[f][c] >= 0) {
                printf(" ");
            }

            printf("%.2f ", matriz[f][c]);
        }
        puts("|");
    }
    putchar('\\');
    for (int l = 0; l < columnas; l++) {
        printf("       ");
    }
    puts("    /");
}
// ----------------------------------------
// FUNCIONES AUXILIARES

int leer_escalar()
{
    puts("Ingrese el numero a escalar: ");
    scanf("%i", &escalar);
    return escalar;
}

// ----------------------------------------
// FUNCIONES PRINCIPALES

void sumar_matrices(float** matriz_a, float** matriz_b)
{
    float** matriz_suma;

    if ((filas_a != filas_b) || (columnas_a != columnas_b)) {
        puts("No se pueden sumar las matrices, dimensiones diferentes");

    } else {
        // reservando memoria para la matriz suma
        matriz_suma = reservar_memoria_matriz(filas_a, columnas_a);

        for (int i = 0; i < filas_a; i++) {
            for (int j = 0; j < columnas_a; j++) {
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

void mult_matriz_escalar(float** matriz, int escalar)
{
    float** matriz_escalada = reservar_memoria_matriz(filas_a, columnas_a);

    for (int c = 0; c < filas_a; c++) {
        for (int f = 0; f < columnas_a; f++) {
            matriz_escalada[c][f] = escalar * matriz[c][f];
        }
    }
    puts("La matriz escalada es:\n");
    imprimir_matriz(matriz_escalada, filas_a, columnas_a);
    liberar_memoria_matriz(matriz_escalada, filas_a);
}

void multiplicar_matrices(float** matriz_a, float** matriz_b)
{
    if (columnas_a != filas_b) {
        puts("No se pueden multiplicar las matrices, dimensiones diferentes");
        return;
    }
    float** matriz_producto = reservar_memoria_matriz(filas_a, columnas_b);

    for (int c = 0; c < filas_a; c++) {
        for (int f = 0; f < columnas_b; f++) {
            for (int k = 0; k < columnas_a; k++) {
                matriz_producto[c][f] += matriz_a[c][k] * matriz_b[k][f];
            }
        }
    }
    puts("Matriz producto: ");
    imprimir_matriz(matriz_producto, filas_a, columnas_b);
    liberar_memoria_matriz(matriz_producto, filas_a);
}
void transpuesta_matriz(float** matriz)
{
    float** matriz_transpuesta = reservar_memoria_matriz(columnas_a, filas_a);

    for (int c = 0; c < filas_a; c++) {
        for (int f = 0; f < columnas_a; f++) {
            matriz_transpuesta[f][c] = matriz[c][f];
        }
    }
    puts("La transpuesta de la matriz ingresada es:\n");
    imprimir_matriz(matriz_transpuesta, columnas_a, filas_a);
    liberar_memoria_matriz(matriz_transpuesta, columnas_a);
}


float determinante_sarrus_matriz(float** matriz){
    float dp = matriz[0][0] * matriz[1][1] * matriz[2][2] +
             matriz[1][0] * matriz[2][1] * matriz[0][2] +
             matriz[2][0] * matriz[0][1] * matriz[1][2];

    float ds = matriz[0][2] * matriz[1][1] * matriz[2][0] +
             matriz[1][2] * matriz[2][1] * matriz[0][0] +
             matriz[2][2] * matriz[0][1] * matriz[1][0];
    return dp-ds;
}

float disminuir_matriz(float** matriz,int filas,int columnas,int limite, float escalar){
    int band=0;
    float cofactor=0;
    float** submatriz = reservar_memoria_matriz(filas, columnas);
    for(int f = 0, i=0; f < filas_a && i < filas; f++, i++){ 

        (f == limite && band == 0) ? (f++, band = 1) : 0;

        for (int c = 1, j=0; c < columnas_a && j < columnas; c++, j++){
            submatriz [i][j] = matriz [f][c];
        }
    }
    if (filas == 3 && columnas == 3){
        cofactor = pow(-1 , limite) * escalar * determinante_sarrus_matriz(submatriz);
        liberar_memoria_matriz(submatriz, filas);
        return cofactor;
    }else{
        return tomar_fila(submatriz, filas, columnas);
    }
}

float tomar_fila(float** matriz, int filas, int columnas){
    float det_final=0;
    //Enviamos un valor de la fila elegida
    for (int f = 0; f < filas_a; f++){
        det_final += disminuir_matriz(matriz, (filas-1), (columnas-1), f, matriz[f][0]); //llamada a la funcion para obtener su submatriz
    }
    return det_final;
}


void determinante_matriz(float** matriz){
    //Metodo para matrices 2x2
    float determinante=0;
    if (filas_a == 2 && columnas_a == 2){
        float dp = matriz[0][0] * matriz[1][1];
        float ds = matriz[1][0] * matriz[0][1];
        determinante = dp-ds;
     //Metodo para matrices 3x3 metodo por cofactores
    }else if(filas_a == 3 && columnas_a == 3){
        determinante = determinante_sarrus_matriz(matriz);
     //Metodo para dimensiones mayores a 3x3
    }else{
        determinante = tomar_fila(matriz, filas_a, columnas_a);
    }
    printf("El determinante de la matriz es: [%.2f]\n", determinante);
    return;
}

	
