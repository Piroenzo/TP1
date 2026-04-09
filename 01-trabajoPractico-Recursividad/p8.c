#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp_1_recursividad.h"
#define MAX_SUBCONJUNTO 100
#define MAX_CONJUNTO 100
#define MAX_OUTPUT 1000

void buscarSubconjuntos(int conjunto[], int tamano, int n, int indiceActual, int *subconjuntoActual, int tamSub, int sumaActual, char *output)
{
    if (indiceActual == tamano)
    {
        if (sumaActual == n && tamSub > 0)
        {
            strcat(output, "{");
            for (int i = 0; i < tamSub; i++)
            {
                char num[12];
                sprintf(num, "%d", subconjuntoActual[i]);
                strcat(output, num);
                if (i < tamSub - 1) strcat(output, ", ");
            }
            strcat(output, "}\n");
        }
        return;
    }
    subconjuntoActual[tamSub] = conjunto[indiceActual];
    buscarSubconjuntos(conjunto, tamano, n, indiceActual + 1, subconjuntoActual, tamSub + 1, sumaActual + conjunto[indiceActual], output);
}

void subconjuntosQueSumanN(int conjunto[], int tamano, int n, char **output)
{
    *output = (char *)malloc(MAX_OUTPUT * sizeof(char));
    (*output)[0] = '\0';
    int subconjuntoActual[MAX_SUBCONJUNTO];
    buscarSubconjuntos(conjunto, tamano, n, 0, subconjuntoActual, 0, 0, *output);
}

int Ejercicio8() 
{
    char *output;
    int eleccion;
    do
    {
        limpiar_consola();
        printf("---- Ejercicio 8: Subconjuntos que suman N ----\n");
        int tamanio = leer_entero("\n\nIngrese la cantidad de elementos del conjunto: ", 0, 100);
        int conjunto[tamanio];
        char mensaje[50];
        for (int i = 0; i < tamanio; i++)
        {
            sprintf(mensaje, "\nElemento %d: ", i + 1);
            conjunto[i] = leer_entero(mensaje, -1000, 1000);
        }
        int objetivo = leer_entero("\n\nIngresar la suma objetivo: ", -1000, 1000);
        subconjuntosQueSumanN(conjunto, tamanio, objetivo, &output);
        printf("\nSubconjuntos cuya suma es %d:\n%s", objetivo, output);
        free(output);

        eleccion = leer_entero("\n\nSalir (0) | Continuar (1): ", 0, 1);
    } while (eleccion == 1);
    return 0;
}

