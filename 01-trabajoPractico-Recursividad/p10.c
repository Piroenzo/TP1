#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "tp_1_recursividad.h"

int* explosion_auxiliar(int n, int b, int **posicion, int *arreglo_exp) {
  if (n <= b) { //si el número ya no se puede dividir más
    arreglo_exp = realloc(arreglo_exp, (**posicion + 1) * sizeof(int)); //Agranda el arreglo para agregar un nuevo elemento
    if (arreglo_exp == NULL) return NULL; // Se asegura de que no haya ocurrido algun error.

    arreglo_exp[**posicion] = n; // Agrega el número al arreglo
    (**posicion)++; // Avanza la posición
    return arreglo_exp; // Retorna el arreglo actualizado
  }

  //Explota el numero deacuerdo al enunciado 
  int n1 = n / b;
  int n2 = n - n1;

  if (n1 <= b) {  // Si N1 ya no se puede dividir más, se guarda el N1.
    arreglo_exp = realloc(arreglo_exp, (**posicion + 1) * sizeof(int));
    if (arreglo_exp == NULL) return NULL;

    arreglo_exp[**posicion] = n1;
    (**posicion)++;
  } else { // Si N1 puede seguir explotando, se llama recursivamente
    arreglo_exp = explosion_auxiliar(n1, b, posicion, arreglo_exp);
  }

  if (n2 <= b) {// Aca se hace lo mismo que en N1, solo que aca es N2.
    arreglo_exp = realloc(arreglo_exp, (**posicion + 1) * sizeof(int));
    if (arreglo_exp == NULL) return NULL;

    arreglo_exp[**posicion] = n2;
    (**posicion)++;
  } else {
    arreglo_exp = explosion_auxiliar(n2, b, posicion, arreglo_exp);
  }
  return arreglo_exp; // Retorna el arreglo con los nuevos fragmentos
}

int *explosion(int n, int b) {
  int *arreglo_exp = malloc(sizeof(int)); // Reserva memoria.
  if (arreglo_exp == NULL) return NULL;

  int *posicion = malloc(sizeof(int)); // Reserva memoria para llevar el control de la posición actual en el arreglo
  if (posicion == NULL) {
    free(arreglo_exp);
    return NULL;
  }

  *posicion = 0; //la posición empieza desde el 0
  int *arreglo_exp_nuevo = explosion_auxiliar(n, b, &posicion, arreglo_exp); // Llama a la función auxiliar para empezar la explosión
  if (arreglo_exp_nuevo == NULL) {
    free(posicion);
    return NULL;
  }
  
  arreglo_exp_nuevo = realloc(arreglo_exp_nuevo, (*posicion + 1) * sizeof(int));//Se agrega un espacio mas en el arreglo para poder poner el -1 que marca el final del arreglo.
  if (arreglo_exp_nuevo == NULL) {
    free(posicion);
    return NULL;
  }

  arreglo_exp_nuevo[*posicion] = -1; //Se agrega el final del arreglo 
  free(posicion); // Libera memoria de la posición
  posicion = NULL;
  return arreglo_exp_nuevo; // Devuelve el arreglo con los fragmentos
}

bool validarEntradasBomba(int* numero, int* bomba) {
    printf("Introduce un numero mayor que 0: ");
    if (scanf("%d", numero) != 1 || *numero <= 0) {
        printf("Error: El numero debe ser mayor que 0 y no contener caracteres no numericos.\n");
        while (getchar() != '\n');
        return false;
    }
    printf("Introduce una bomba (entero positivo) menor que el numero: ");
    if (scanf("%d", bomba) != 1 || *bomba <= 1 || *bomba >= *numero) {
        printf("Error: La bomba debe ser un numero mayor que 1 y menor que el numero.\n");
        while (getchar() != '\n');
        return false;
    }

    return true;
}

void Ejercicio10(){
    printf("---- Ejercicio 10: Explocion ---- \n");
    
    int n = 10; // Número a explotar
    int b = 3; // Base de explosión

    validarEntradasBomba(&n, &b); // Valida las entradas de la bomba
    printf("Numero a explotar: %d\n", n);
    printf("Bomba: %d\n", b);
    int *resultado = explosion(n, b); // Llama a la función explosion
    
    if (resultado != NULL) { // Si no hubo error en la explosión
        printf("Resultado de la explosion: ");
        for (int i = 0; resultado[i] != -1; i++) { // Imprime el resultado
        printf("%d ", resultado[i]);
        }
        printf("\n");
        free(resultado); // Libera memoria del resultado
    } else {
        printf("Error en la explosion\n");
    }
}


