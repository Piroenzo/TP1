#ifndef VALIDACIONES_H
#define VALIDACIONES_H

// imprime "mensaje" y valida la entrada de un string alfabetico con un largo minimo y maximo
char* leer_alphabetico(const char* mensaje, int min, int max);
// imprime "mensaje" y valida la entrada de un entero en el rango "min" - "max" inclusive ambos
int leer_entero(const char* mensaje, int min, int max);
// imprime "mensaje" y valida la entrada de un float en el rango "min" - "max" inclusive ambos
float leer_float(const char* mensaje, float min, float max);
// Limpia la consola y el buffer stdin
void limpiar_consola();

#endif // VALIDACIONES_H                                   