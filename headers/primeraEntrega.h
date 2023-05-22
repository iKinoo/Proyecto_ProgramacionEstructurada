#ifndef PRIMERA_ENTREGA_H

#define PRIMERA_ENTREGA_H

extern float **matriz_a,
    **matriz_b;

extern int filas_a, columnas_a,
    filas_b, columnas_b;


void sumar_matrices(float **matriz_a, float **matriz_b);
void mult_matriz_escalar(float **matriz, int escalar);
void transpuesta_matriz(float **matriz);
void multiplicar_matrices(float **matriz_a, float **matriz_b);

#endif
