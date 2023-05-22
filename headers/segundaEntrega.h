#ifndef SEGUNDA_ENTREGA

#define SEGUNDA_ENTREGA

extern float **matriz_a,
    **matriz_b;

extern int filas_a, columnas_a,
    filas_b, columnas_b;


void inversaGaussJordan(float **matriz_a);
void resolverGaussJordan(float **matriz_a, int nVariables);
void metodocramer(float **matriz_a);
// Conjunto de funciones para calcular la determinante
float determinante_sarrus_matriz(float **matriz);
void determinante_matriz(float **matriz);
float tomar_fila(float **matriz, int filas, int columnas);
float disminuir_matriz(float **matriz, int filas, int columnas, int limite, float escalar);

#endif
