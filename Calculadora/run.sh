#!/bin/bash
echo '1º Paso - compilar (En progreso)'
#FALTA hacer las funciones de ensamblador

echo '2º Paso - linkear .asm y .c (En progreso)'
#FALTA el paso 1 - se usa para pruebas las siguiente instrucciones
gcc -o main main.c
chmod 777 main

echo '3º Paso - ejecutar (./main solo pruebas)'
./main
