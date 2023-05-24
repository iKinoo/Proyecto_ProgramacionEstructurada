#ifndef MATRIZ_DINAMICA_H
#define MATRIZ_DINAMICA_H

float **reservar_memoria_matriz(int filas, int columnas);
void liberar_memoria_matriz(float **matriz, int filas);
void leer_dimensiones(int *filas, int *columnas);
float **leer_matriz(int filas, int columnas);
void validarDimension(int *dimension);
void imprimir_matriz(float **matriz, int filas, int columnas);
float **copiarMatriz(float **matrizOriginal, int filas, int columnas);

#endif
