# Proyecto_ProgramacionEstructurada
Proyecto final de la materia Programación Estructurada del segundo semestre de la carrera Licenciatura en Ingeniería de Software.

## Cómo crear una matriz dinámica
> Nota: Esta documentación se limita a explicar el funcionamiento de las funciones del programa, no el proceso de asignación de memoria dinámica.
>

Funciones disponibles: 

- `reservar_memoria_matriz(int**, int, int)`
- `liberar_memoria_matriz()`
- `leer_matriz(int**, int*, int*)`

### 1. Creando la matriz
```c
int **matriz;
```
### 2. Leer la matriz
> Nota: `leer_matriz()` automaticamente reserva memoria para poder leer la matriz.
```c
matriz = leer_matriz(matriz, &filas, &columnas);
// El valor de las filas y columnas se pasa como referencia para poder ser usadas en funciones como imprimir matriz
```
### 3. Reservar memoria
> Nota: esta función se usa en caso de que no se tenga de manera inmediata los valores de filas y columnas, o que no se necesite leer la matriz, como en el caso de la matriz producto.

```c
matriz = reservar_memoria(matriz, filas, columnas);
```
### 4. Liberar memoria
> Nota: Usar cuando se tenga certeza que la matriz no se va a usar más.
```c
liberar_memoria(matriz, filas);
```
----
## Ilustración de la lógica de la matriz por punteros

| `**matriz`     |                  |                  |                  |                  |
| -------------- | ---------------- | ---------------- | ---------------- | ---------------- |
| `*matriz[0]`   | `matriz[0][0]`   | `matriz[0][j]`   | `matriz[0][...]`   | `matriz[0][N]`   |
| `*matriz[1]`   | `matriz[1][0]`   | `matriz[1][j]`   | `matriz[1][...]`   | `matriz[1][N]`   |
| `*matriz[i]`   | `matriz[i][0]`   | `matriz[i][j]`   | `matriz[i][...]`   | `matriz[i][N]`   |
| `*matriz[...]` | `matriz[...][0]` | `matriz[...][j]` | `matriz[...][...]` | `matriz[...][N]` |
| `*matriz[M]`   | `matriz[M][0]`   | `matriz[M][j]`   | `matriz[M][...]`   | `matriz[M][N]`   |