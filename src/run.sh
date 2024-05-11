#!/bin/bash
echo '1º Paso - compilar'
nasm -f elf32 crearArbolB.asm -o ejercicio1.o

echo '2º Paso - linkear .asm y .c'
gcc -m32 -o ejercicio1 ejercicio1.o main.c
chmod 777 ejercicio1

echo '3º Paso - ejecutar'
./ejercicio1
