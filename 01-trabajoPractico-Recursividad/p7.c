#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "tp_1_recursividad.h"


char *ondaRecursiva(char* ondaNueva, char onda[], char anterior, int contador, int contadorNuevoArray) {
    int tamanioOnda = strlen(onda);
    if (tamanioOnda == contador) {
        ondaNueva[contadorNuevoArray] = '\0';
        return ondaNueva;
    }
    if (anterior != onda[contador] && contador != 0) {
        ondaNueva = realloc(ondaNueva, (contadorNuevoArray + 2) * sizeof(char));
        if (!ondaNueva) {  
            return NULL;
        }
        ondaNueva[contadorNuevoArray] = '|';
        contadorNuevoArray++;
    }
    if (onda[contador] == 'h') {
        ondaNueva[contadorNuevoArray] = '-';
    } else {
        ondaNueva[contadorNuevoArray] = '_';
    }
    return ondaRecursiva(ondaNueva, onda, onda[contador], contador + 1, contadorNuevoArray + 1);
}

char* ondaDigital(char onda[]) {
    int largo = strlen(onda);
    char* nuevaOnda = (char*)malloc(sizeof(char) * (largo + 1));
    if (!nuevaOnda) {
        return NULL;
    }

    for (int i = 0; i < largo; i++) {
        onda[i] = tolower(onda[i]);
    }

    nuevaOnda = ondaRecursiva(nuevaOnda, onda, onda[0], 0, 0);
    return nuevaOnda;
}

bool validarEntrada(const char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] != 'H' && entrada[i] != 'L' && entrada[i] != 'h' && entrada[i] != 'l') {
            return false;
        }
    }
    return true;
}

int Ejercicio7() {
    int eleccion;
    do
    {
        limpiar_consola();
        printf("------ Ejercicio 7: Onda Digital ------\n");
        char* letras;
        do
        {
            letras = leer_alphabetico("Ingrese la onda (solo caracteres 'H' y 'L'): ", 1, 100);
        } while (!validarEntrada(letras));
        printf("\nOnda original: %s\nOnda digital: %s\n", letras, ondaDigital(letras));
        
        eleccion = leer_entero("\n\nSalir (0) | Continuar (1): ", 0, 1);
    } while (eleccion == 1);
    return 0;
}
