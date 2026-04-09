#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp_1_recursividad.h"

int terminoSeridFibonacci(int k){
    if(k == 0 || k == 1){return 1;}
    else{return terminoSeridFibonacci(k-1)+terminoSeridFibonacci(k-2);}
}

int Ejercicio3(){
    int eleccion;
    do
    {
        limpiar_consola();
        printf("------ Ejercicio 3: Fibonacci ------\n");
        int elemento = leer_entero("ingrese la posicion de la sucesion de Fibonacci: ", 0, 100);
        printf("El elemento en la posicion %i de la serie Fibonacci es %d\n", elemento, terminoSeridFibonacci(elemento));
        eleccion = leer_entero("\nSalir (0) | Continuar (1): ", 0, 1);
    } while (eleccion == 1);    
}


