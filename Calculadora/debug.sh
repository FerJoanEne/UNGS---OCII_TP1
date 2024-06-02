#!/bin/bash
echo '1º Paso - compilar'
nasm -g -f elf32 operations.asm -o operations.o

echo '2º Paso - linkear .asm y .c'
gcc -g -m32 -o runBot operations.o main.c
chmod 777 runBot

echo '3º Paso - ejecutar ./runBot'
gdb ./runBot
