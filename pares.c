#include <stdio.h>
#include <stdlib.h>
#include "./presentacion.h"
#include "./pares.h"
#include <time.h>


int* arreglo = NULL;
int n;

//lista de numeros consultados con su par
typedef struct listaaux
{
    int numero, posicion1, posicion2;
}listaaux;

void parametros(){
    BorrarPantalla();
    printf("Ingrese el tamaño del la lista a usar: ");
    scanf("%d", &n);
    // lista de tamaño n
    arreglo = (int*)realloc(arreglo, n * sizeof(int));
    if (arreglo == NULL){
        printf("Error al asignar memoria.\n");
        exit(1);
    }
}

int blineal(int aux, listaaux **lista, int n, int y){
    for (int i =0; i<n;i++){
        if (lista[i] && aux==lista[i]->numero){
            return 0;//ya fue procesado
        }
    }
    for(int i = y;i<n;i++){
        if (aux == arreglo[i] && i != y){
            lista[y] = (listaaux*)malloc(sizeof(listaaux));
            lista[y]->numero = aux;
            lista[y]->posicion1 = y;
            lista[y]->posicion2 = i;
            return 1; //par encontrado y agregado a la lista de procesados
        }
    }
    return 0;   
}

void resultados(listaaux **lista){
    EsperarMiliSeg(5000);
    BorrarPantalla();
    MoverCursor(11, 0);
    printf("Resultads/n");
    for(int i =0; i<n; i++){
        if (lista[i]){
            printf("\n[%d] [%d] [%d]", lista[i]->numero, lista[i]->posicion1, lista[i]->posicion2);
        }
    }
}

int pares(){
    parametros();
    int aux;
    listaaux **lista = (listaaux**)malloc(n * sizeof(listaaux*));
    if (lista == NULL){
        printf("Error al asignar memoria.\n");
        return 1;
    }
    // asignacion de numeros aleatorias dentro de la lista de tamaño n
    for (int i=0; i<n; i++){
        arreglo[i] = (rand()%(3 * n +1));
        printf("%d\n",arreglo[i]);
    }
    // busqueda de pares de numeros de la lista
    for (int y=0; y<n; y++){
        aux = arreglo[y];
        blineal(aux, lista, n, y);
    }
    resultados(lista);
    for (int i=0; i<n; i++){
        free(lista[i]);
    }
    free (lista);
    return 0;
}