#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./presentacion.h"
#include "./fibonacci.h"
#include "./pares.h"

//compilacion   gcc pares.c fibonacci.c main.c -c
//              gcc main.o pares.o fibonacci.o presentacionWin.o -o main

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
    do{
        menu();
        switch (seleccion){
        case 1:
            pares();
            break;
        case 2:
            fibonacci();
            break;
        
        case 3:
        BorrarPantalla();
        break;

        default:
            printf("Opcion no valida. Presione Enter para continuar...\n");
            getchar();
            getchar();
            break;
        }
    }while(seleccion != 3);
    return 0;
}