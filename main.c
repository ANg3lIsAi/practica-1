#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./presentacion.h"
#include "./fibonacci.h"
#include "./pares.h"

int seleccion;
//posicion dentro del arreglo en la que se esta
int posicion =0;
int fila = 32;
int columna = 64;


void menu(){
    BorrarPantalla();
    MoverCursor((fila-4)/2, 0);
    printf("Menu");
    MoverCursor(0,2);
    printf("Seleccione una opcion\n");
    printf("\n1) Busqueda de coincidencias\n");
    printf("2) Fibonacci\n");
    printf("3) Salir\n");
    scanf("%d",&seleccion);
}



int main(){
    srand(time(NULL));
    menu();
    switch (seleccion)
    {
    case 1:
        printf("1");
        EsperarMiliSeg(5000);
        pares();
        menu();
        break;
    case 2:
        fibonacci();
        menu();
        break;
    
    case 3:
    return 0;
    BorrarPantalla();
    break;

    default:
        menu();
        break;
    }
    return 0;
}