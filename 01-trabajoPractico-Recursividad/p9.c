#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp_1_recursividad.h"

bool divisiblePor7(int numero)
{
    if(numero < 70)
    {
        return numero % 7 == 0;
    }
    int primeraCifra = numero % 10;
    int resto = numero / 10;
    printf("%d -> %d x 2 = %d\n", numero, primeraCifra, primeraCifra*2);
    printf("%d - %d = \n", resto, primeraCifra*2);
    if(resto - primeraCifra*2 < 70)
    {

        printf((resto - primeraCifra*2) % 7 == 0 ? "%d -> Multiplo de 7\n" : "%d -> No multiplo de 7\n", resto - primeraCifra*2);
    }

    return divisiblePor7(resto - primeraCifra*2);
}

void Ejercicio9()
{
    int eleccion;
    do
    {
        limpiar_consola();
        printf("---- Ejercicio 9: Divisibilidad por 7 ---- \n");
        int numero = leer_entero("\n\nIngrese un numero entero: ", -1000000, 1000000);
        if(divisiblePor7(numero))
            printf("\n--> %d es divisible entre 7\n", numero);
        else
            printf("\n--> %d NO es divisible entre 7\n", numero);

        eleccion = leer_entero("\n\nSalir (0) | Continuar (1): ", 0, 1);
    } while (eleccion == 1);
}

