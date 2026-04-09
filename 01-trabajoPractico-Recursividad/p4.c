#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tp_1_recursividad.h"

double divisionAux(int dividendo, int divisor, int contador, double factor, int precision)
{
    double resta = dividendo - divisor;
    double exceso = 0;
    if (contador > precision)
    {
        return exceso;
    }
    else if (resta < 0)
    {
        exceso += divisionAux(dividendo * 10, divisor, contador + 1, factor / 10, precision);
        return exceso;
    }
    else
    {
        return factor + divisionAux(resta, divisor, contador, factor, precision);
    }
}

double division(int m, int n, int precision)
{
    int contador = 0;
    if ((m < 0 && n < 0) || (m > 0 && n > 0))
    {
        return divisionAux(abs(m), abs(n), contador, 1.0, precision);
    }
    else
    {
        return -divisionAux(abs(m), abs(n), contador, 1.0, precision);
    }
}

int Ejercicio4()
{
    int eleccion;
    do
    {   
        limpiar_consola();
        printf("---- Ejercicio 4: Division ----\n");
        int dividendo = leer_entero("\nIngrese el dividendo: ", -10000, 10000);
        int divisor;
        do
        {
            divisor = leer_entero("\nIngrese el divisor (diferente de 0): ", -10000, 10000);
        } while (divisor == 0);
        int precision = leer_entero("\nIngrese la cantidad de decimales (1 - 10): ", 1, 10);
        printf("\n\n%i dividido entre %i es igual a %.*f", dividendo, divisor, precision, division(dividendo, divisor, precision));
        eleccion = leer_entero("\n\nSalir (0) | Continuar (1): ", 0, 1);
    } while (eleccion == 1);
    return 0;
}
