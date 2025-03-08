#include <stdio.h>
#include <stdlib.h>
#include "./presentacion.h"
#include "./pares.h"
#include <time.h>

int n, a, total = 0;
int* lista = NULL;

// Estructura para guardar los pares encontrados
typedef struct listaaux {
    int numero, posicion1, posicion2;
} listaaux;

void liberarmemoria(){
    if (lista!= NULL){
        free(lista);
        lista = NULL;
    }
}

void parametros() {
    BorrarPantalla();
    MoverCursor(27,0);
    printf("Parametros\n");
    printf("Ingrese el tamanio de la lista a usar: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Tamanio no valido, saliendo...\n");
        exit(1);
    }

    lista = (int*)realloc(lista, n * sizeof(int));
    if (lista == NULL) {
        printf("Error al asignar memoria para la lista\n");
        exit(1);
    }
}

int pares() {
    srand(time(NULL));
    listaaux** aux = NULL;
    liberarmemoria();
    total =0;
    parametros();

    // Llenar la lista con numeros aleatorios
    for (int i = 0; i < n; i++) {
        lista[i] = rand() % ((3 * n) + 1);
        printf("posicion %d, numero %d\n", i, lista[i]);
    }

    EsperarMiliSeg(5000);
    // Buscar pares en la lista
    for (int i = 0; i < n; i++) {
        a = lista[i];
        for (int k = i + 1; k < n; k++) {
            if (a == lista[k]) {
                aux = (listaaux**)realloc(aux, (total + 1) * sizeof(listaaux*));
                if (aux == NULL) {
                    printf("Error al aumentar lista de numeros encontrados\n");
                    exit(1);
                }

                aux[total] = (listaaux*)malloc(sizeof(listaaux));
                if (aux[total] == NULL) {
                    printf("Error al asignar memoria para struct\n");
                    exit(1);
                }

                aux[total]->numero = a;
                aux[total]->posicion1 = i;
                aux[total]->posicion2 = k;
                total++;
            }
        }
    }

    // Mostrar resultados
    printf("\nResultados\n");
    if (total == 0) {
        printf("Ningun numero resulto repetido.\n");
    } else {
        for (int i = 0; i < total; i++) {
            printf("[%d] [%d] [%d]\n", aux[i]->numero, aux[i]->posicion1, aux[i]->posicion2);
        }
    printf("Pares encontrados: %d\n",total);
    printf("Presiona Enter para continuar...\n");
    while (getchar() != '\n'); // Limpia el búfer
    getchar(); // Espera la tecla Enter
    }

    // Liberar memoria
    for (int i = 0; i < total; i++) {
        free(aux[i]);
    }
    free(aux);
    free(lista);

    return 0;
}