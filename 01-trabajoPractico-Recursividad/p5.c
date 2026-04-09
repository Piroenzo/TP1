#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "tp_1_recursividad.h"

char* agregarSeparadorMiles(char *numeros) {
    int length = strlen(numeros);
    bool esNegativo = (numeros[0] == '-');

    if ((!esNegativo && length <= 3) || (esNegativo && length <= 4)) {
        char *copia = malloc(length + 1);
        strcpy(copia, numeros);
        return copia;
    }

    int pos_corte = length - 3;
    char izquierda[pos_corte + 1];
    strncpy(izquierda, numeros, pos_corte);
    izquierda[pos_corte] = '\0';

    char *resultado_recursivo = agregarSeparadorMiles(izquierda);
    char *final = malloc(strlen(resultado_recursivo) + 6);
    
    sprintf(final, "%s.%s", resultado_recursivo, numeros + pos_corte);
    free(resultado_recursivo);
    return final;
}

bool validar_cadena(char *s) {
    if (s == NULL || *s == '\0') return false;    
    int i = 0;
    if (s[0] == '-') {
        i = 1;
        if (s[i] == '\0') return false; 
    }
    for (; s[i] != '\0'; i++) {
        if (!isdigit((unsigned char)s[i])) return false;
    }
    return true;
}

void Ejercicio5()
{
    char buffer[128];
    int eleccion;
    do {
        limpiar_consola();
        printf("---- Ejercicio 5: Separador de miles ----\n");
    
        do
        {
            printf("\nIngrese un string de numeros: ");
            if (fgets(buffer, sizeof(buffer), stdin) == NULL) continue;
            buffer[strcspn(buffer, "\n")] = 0; 
        } while (!validar_cadena(buffer));
    
        char *separado = agregarSeparadorMiles(buffer);
        printf("\nOriginal:   %s", buffer);
        printf("\nFormateado: %s\n", separado);
        free(separado); 

        eleccion = leer_entero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (eleccion == 1);
}
