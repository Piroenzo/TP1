#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>
#include "../libs/validaciones/headers/validaciones.h"
#include "tp_1_recursividad.h"
#include "Ejercicio.h"

int main()
{
    
    int eleccion;
    do
    {
        limpiar_consola();
        printf("------------ Trabajo Practico: Recursividad ------------\n");
        eleccion = leer_entero("Seleccione el ejercicio a ejecutar(1-10, 0 para salir): ", 0, 10);
        switch (eleccion)
        {
        case 1:
            Ejercicio1();
            break;
        case 2:
            Ejercicio2();
            break;
        case 3:
            Ejercicio3();
            break;
        case 4:
            Ejercicio4();
            break;
        case 5:
            Ejercicio5();
            break;
        case 6:
            Ejercicio6();
            break;
        case 7:
            Ejercicio7();
            break;
        case 8:
            Ejercicio8();
            break;
        case 9:
            Ejercicio9();
            break;
        case 10:
            Ejercicio10();
            break;
        }
    } while (eleccion != 0);
    printf("\nSaliendo.......\n\n\n");
    return 0;
}
