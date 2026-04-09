#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "tp_1_recursividad.h"


char *chinosRecursivo(char *grupo, int contador,int largo){
    if (contador>=largo){
        grupo[contador]='\0';
        return grupo;
    }
    if (contador<(largo/2)){
        strncat(grupo, "(-",3);
    }
    else{
        strncat(grupo, "-)",3);
    }
    if(contador+3<largo){
        strncat(grupo, ".",2);
    }
    return chinosRecursivo(grupo,contador+3,largo);
}

char *reunionMafia(int n){
    int largo=(6*n);
    char *grupo=(char*)malloc(largo+1);
    if (!grupo){
        return NULL;}
    grupo[0] = '\0';
    grupo=chinosRecursivo(grupo,0,largo);
    return grupo;
}

int Ejercicio6(){
    int eleccion;
    do
    {
        limpiar_consola();
        printf("----- Ejercicio 6: Mafia China ----\n");
        
        int nivel = leer_entero("\nIngrese el nivel de la reunion: ", 1,15);
        char* chinos = reunionMafia(nivel);
        printf("\n\nReunion de mafia china nivel %i:\n%s\n\n", nivel, chinos);
        free(chinos);

        eleccion = leer_entero("\n\nSalir (0) | Continuar (1): ", 0, 1);
    } while (eleccion == 1);
    return 0;
}
