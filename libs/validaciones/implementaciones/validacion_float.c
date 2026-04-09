#include "../headers/validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float leer_float(const char* mensaje, float min, float max) {
    char buffer[100];
    char* endptr;
    float numero;
    // while (getchar() != '\n');
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            printf("Error al leer entrada.\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0;  
        numero = strtof(buffer, &endptr);  
        if (endptr != buffer && *endptr == '\0') {
            if (numero >= min && numero <= max) {
                return numero;  
            } else {
                printf("Número fuera de rango [%.2f - %.2f].\n", min, max);
            }
        } else {
            printf("Entrada inválida. Ingrese un número flotante.\n");
        }
    }
}

