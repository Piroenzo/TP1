#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "tp_1_recursividad.h"
#define MAX_CHARACTERS 30

// Ejercicio 1
/*1.	Construir una función recursiva que retorne verdadero si una cadena de caracteres pasada 
como parámetro es un palíndromo.  Ej. “neuquen” ya que se lee igual de atrás hacia adelante.
bool palindromo (char * cadena);*/

bool palindromo(char *cadena)
{
    int largocadena = strlen(cadena);
    if (largocadena <= 1) return true;
    if (cadena[0] == cadena[largocadena - 1])
    {

        char tempcadena[largocadena - 1];
        for (int i = 1; i < largocadena; i++)
        {
            if (i != largocadena - 1)
            {
                tempcadena[i - 1] = cadena[i];
            }
        }
        tempcadena[largocadena - 2] = '\0';
        return palindromo(tempcadena);
    }
    return false;
}

void Ejercicio1()
{
    int eleccion;
    do
    {
        limpiar_consola();
        printf("---- Ejercicio 1: Palindromo ------\n");
        char* palabra = leer_alphabetico("Ingrese la palabra a evaluar: ",1 ,50);
        if(palindromo(palabra)){
            printf("\nLa palabra %s es palindroma\n", palabra);
        } else {
            printf("\nLa palabra %s NO es palindroma\n", palabra);
        }
        eleccion = leer_entero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (eleccion != 0);
    printf("Saliendo....\n");
}