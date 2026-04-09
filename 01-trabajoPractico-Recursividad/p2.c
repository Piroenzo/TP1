#include <stdio.h>
#include <stdlib.h>
#include "tp_1_recursividad.h"
#include "Ejercicio.h"

int producto (int m, int n){
    if(n < 0){return -m + producto(m, n + 1);}
    else if(n > 0){return m + producto(m, n - 1);}
    else if(n == 0){return 0;}
}

void Ejercicio2()
{   
    int eleccion;
    do
    {
        limpiar_consola();
        printf("---- Ejercicio 2: Multiplicacion ----\n");
        int num = leer_entero("\nIngrese el multiplicando: ", -1000, 1000);
        int cant = leer_entero("Ingrese el multiplicador: ", -1000, 1000);
        printf("\n-> El producto de %i y %i es %i \n", num, cant, producto(num,cant));
        eleccion = leer_entero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (eleccion == 1);
}
