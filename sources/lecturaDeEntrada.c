#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/lecturaDeEntrada.h"

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

        // Comprobar si no hubo caracteres invÃ¡lidos despuÃ©s del nÃºmero
        if (strlen(entrada) != 0 && *valorNoNumerico == '\0')
        {
            break;
        }

        printf("Entrada inválida. Por favor, ingrese un entero válido.\n");
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

        // Comprobar si no hubo caracteres inválidos después del número
        if (strlen(entrada) != 0 && *valorNoNumerico == '\0')
        {
            break;
        }

        printf("Entrada inválida. Por favor, ingrese un número válido.\n");
    }

    return flotante;
}
void leer_escalar(float *escalar)
{
    puts("Ingrese el número a escalar: ");
    *escalar = leerFlotante();
}
