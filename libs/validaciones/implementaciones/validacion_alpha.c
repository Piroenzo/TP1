#include "../headers/validaciones.h"
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char* leer_alphabetico(const char* mensaje, int min, int max) {
    // imprime "mensaje" y valida la entrada de una cadena alfabetica en el rango "min" - "max" inclusive ambos
    char buffer[100];
    while (1) {
        printf("%s", mensaje);        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // copia en buffer la entrada del teclado (stdin) con el tamanio "sizeof(buffer)"
            printf("Error al leer entrada.\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0; 
        bool es_alfabetico = true;
        for (int i = 0; i < strlen(buffer); i++) {
            if (!isalpha(buffer[i])) {
                es_alfabetico = false;
                break;
            }
        }
        if (!es_alfabetico) {
            printf("La entrada debe contener solo caracteres alfabeticos.\n");
            continue;
        }
        int longitud = strlen(buffer);
        if (longitud < min || longitud > max) {
            printf("La entrada debe tener entre %d y %d caracteres.\n", min, max);
            continue;
        }
        char* resultado = malloc((longitud + 1) * sizeof(char));
        if (resultado == NULL) {
            printf("Error al asignar memoria.\n");
            continue;
        }
        strcpy(resultado, buffer);
        return resultado;
    }
}