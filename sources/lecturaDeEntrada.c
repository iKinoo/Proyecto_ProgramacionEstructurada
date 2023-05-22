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

        // Comprobar si no hubo caracteres inválidos después del número
        if (strlen(entrada) != 0 && *valorNoNumerico == '\0')
        {
            break;
        }

        printf("Entrada inv�lida. Por favor, ingrese un entero v�lido.\n");
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

        // Comprobar si no hubo caracteres inv�lidos despu�s del n�mero
        if (strlen(entrada) != 0 && *valorNoNumerico == '\0')
        {
            break;
        }

        printf("Entrada inv�lida. Por favor, ingrese un n�mero v�lido.\n");
    }

    return flotante;
}
void leer_escalar(float *escalar)
{
    puts("Ingrese el n�mero a escalar: ");
    *escalar = leerFlotante();
}

