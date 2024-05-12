#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int valor;
    struct Nodo* izq;
    struct Nodo* der;
};

// Prototipos de las funciones en ensamblador
extern struct Nodo* crearArbolB(int valor);
extern struct Nodo* crearArbolB_conHijos(int valor, struct Nodo* izq, struct Nodo* der);

int main() {
    // Crear un nodo simple
    struct Nodo* nodo1 = crearArbolB(10);
    if (!nodo1) {
        printf("Error al crear nodo 1\n");
        return 1;
    }

    // Crear un nodo con hijos
    struct Nodo* nodo2 = crearArbolB_conHijos(20, NULL, nodo1);
    if (!nodo2) {
        printf("Error al crear nodo 2\n");
        return 1;
    }

    // Imprimir el valor del nodo 1
    printf("Valor nodo 1: %d\n", nodo1->valor);

    // Imprimir el valor del nodo 2
    printf("Valor nodo 2: %d\n", nodo2->valor);

    // Imprimir el valor del nodo 1 a partir del nodo 2
    printf("Valor nodo 1 desde nodo 2: %d\n", nodo2->der->valor);


    // Liberar memoria de los nodos
    free(nodo1);
    free(nodo2);

    return 0;
}