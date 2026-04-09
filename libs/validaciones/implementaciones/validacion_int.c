#include "../headers/validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leer_entero(const char* mensaje, int min, int max) {
    // imprime "mensaje" y valida la entrada de un entero en el rango "min" - "max" inclusive ambos
    char buffer[100];
    char* endptr;
    int numero;
    // while (getchar() != '\n');
    while (1) {
        printf("%s", mensaje);
        // impreime el mensaje de la funcion        
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            // copia en buffer la entrada del teclado (stdin) con el tamanio "sizeof(buffer)"
            printf("Error al leer entrada.\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0;
        // Eliminar el salto de línea. 
        // strcspn: Cuenta caracteres de (str1 -> buffer) hasta encontrar cualquier carácter de (str2 -> "\n")
        // strcspn devuelve el indice en donde se encuentra "\n"
        // entonces reemplaza el salto ed line con fin de string "\0"
        numero = (int)strtol(buffer, &endptr, 10);
        // Convertir a entero. strol prototipo -> long int strtol(const char *nptr, char **endptr, int base).
        // str to long convierte buffer en long y lo guarda en la var numero. 
        // Luego guarda un puntero a el primer caracter no numerico
        if (endptr != buffer && *endptr == '\0') {
        // Verificar si la conversión fue válida y está en el rango
        // si endptr == buffer significa que el primer caracter fue no numerico (puede ser entrada vacio)
        // si *endptr == '\0' asegura que todo fue convertido hasta el enter del usuario 
        // (no hay cosas raras que hayan roto la conversion antes de tiempo ej: "30 fa", "40xx", etc).
            if (numero >= min && numero <= max) {
                // verifica el rango
                return numero;
            } else {
                printf("Numero fuera de rango [%d - %d].\n", min, max);
            }
        } else {
            printf("Entrada invalida. Ingrese un numero entero.\n");
        }
    }
}
