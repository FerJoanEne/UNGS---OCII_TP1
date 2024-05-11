#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo {
    struct Nodo *izq;
    struct Nodo *der;
    int valor;
} Nodo;

extern struct Nodo* CMAIN(Nodo *izq, Nodo *der, int valor);

int main()
{
    printf("funcion main - Reservo memoria para la raiz\n");
    struct Nodo *nodoIzq = (struct Nodo *)malloc(sizeof(struct Nodo));
    struct Nodo *nodoDer = (struct Nodo *)malloc(sizeof(struct Nodo));

    printf("funcion main - La dirección de memoria de nodoIzq es: %p\n", (void *)nodoIzq);
    printf("La dirección de memoria de nodoDer es: %p\n", (void *)nodoDer);

    printf("funcion main - Creo la raiz\n");
    struct Nodo *rIzq = CMAIN((void *)nodoIzq, (void *)nodoDer, 5);
    struct Nodo *rDer = CMAIN((void *)nodoIzq, (void *)nodoDer, 7);
    struct Nodo *raiz = CMAIN((void *)rIzq, (void *)rDer, 10);


    printf("se ejecuto correctamente funcion main en c\n");
    return 0;
}