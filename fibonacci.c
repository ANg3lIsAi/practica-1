#include <stdio.h>
#include <stdlib.h>
#include "./presentacion.h"
#include "./fibonacci.h"

int a,b;


void datos(void){
    BorrarPantalla();
    MoverCursor((32-9)/2,0);
    printf("Fibonacci\n");
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
}

void encontrarDivisores(int a, int b, int divisor){
    if(divisor ==0) return;
    if(a % divisor ==0 && b % divisor ==0){
        printf("%d", divisor);
    }
    encontrarDivisores(a ,b, divisor -1);
}

int fibonacci(){
    datos();
    int menor = (a<b)? a:b;
    printf("Los divisores comunes de %d y %d son: ",a,b);
    printf("\n%d\n",menor);
    encontrarDivisores(a,b,menor);
    printf("\n");
    EsperarMiliSeg(5000);

    return 0;
}