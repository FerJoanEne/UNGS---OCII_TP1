#include <stdio.h>
#include <stdlib.h>
extern void CMAIN();

typedef struct Nodo
{
    struct Nodo* izq;
    struct Nodo* der;
    int valor; 
} Nodo;

extern struct Nodo* crearArbolB(Nodo* izq, Nodo* der, int valor);

int main() {
    struct Nodo* nodoIzq = (struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo* nodoDer = (struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo* rIzq = crearArbolB(nodoIzq, nodoDer, 5);
    struct Nodo* rDer = crearArbolB(nodoIzq, nodoDer, 7);
    struct Nodo* raiz = crearArbolB(rIzq, rDer, 10);

    return 0;
}
)