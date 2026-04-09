#include "../headers/validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpiar_consola(){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}