#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int valor;
    struct Nodo* izq;
    struct Nodo* der;
};

// Prototipos de las funciones en ensamblador
extern struct Nodo* crearArbolB(int valor);
extern struct Nodo* crearArbolB_conHijos(
    int valor, 
    struct Nodo* izq, 
    struct Nodo* der);

extern struct Nodo* buscarMinimo(struct Nodo* raiz);

int main() {
    // Crear un nodo simple
    struct Nodo* nodo1 = crearArbolB(6);
    //struct Nodo* nodo2 = crearArbolB(9);
    struct Nodo* nodo3 = crearArbolB(13);
    //struct Nodo* nodo4 = crearArbolB(14);
    //struct Nodo* nodo5 = crearArbolB(15);
    struct Nodo* nodo6 = crearArbolB(17);
    //struct Nodo* nodo7 = crearArbolB(20);
    struct Nodo* nodo8 = crearArbolB(26);
    //struct Nodo* nodo9 = crearArbolB(64);
    struct Nodo* nodo10 = crearArbolB(72);

    if (!nodo1 || !nodo3 || !nodo10 || !nodo8 || !nodo6) {
        printf("Error al crear nodo\n");
        return -1;
    }

    struct Nodo* subarbol0 = crearArbolB_conHijos(14, nodo3, NULL);

    struct Nodo* subarbol1 = crearArbolB_conHijos(9, nodo1, subarbol0);
    
    struct Nodo* subarbol2 = crearArbolB_conHijos(64, nodo8, nodo10);

    struct Nodo* subarbol3 = crearArbolB_conHijos(20, nodo6, subarbol2);

    // Crear raiz
    struct Nodo* raiz = crearArbolB_conHijos(15, subarbol1, subarbol3);
    if (!raiz) {
        printf("Error al crear arbol con hijos\n");
        return -1;
    }

    // Imprimir arbol
    printf("Valor raiz : %d\n", raiz->valor);
    printf("raiz -> valor subarbol izquierdo : %d\n", raiz->izq->valor);
    printf("raiz -> valor subarbol derecho : %d\n", raiz->der->valor);

    //printf("minimo desde raiz : %d\n", raiz->izq->izq->valor);

    struct Nodo* minimo = buscarMinimo(raiz);

    printf("valor minimo : %d\n", minimo->valor);
    
    // Liberar memoria de los nodos
    free(nodo1);
    //free(nodo2);
    free(nodo3);
    //free(nodo4);
    free(nodo6);
    //free(nodo7);
    free(nodo8);
    //free(nodo9);
    free(nodo10);

    free(subarbol0);
    free(subarbol1);
    free(subarbol2);
    free(subarbol3);

    free(minimo);
    free(raiz);

    return 0;
}