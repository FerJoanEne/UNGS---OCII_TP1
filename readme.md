- Ejecutar programa de ensamblador

nasm -f elf64 nombre-de-mi-archivo.asm 
#crea el archivo nombre-de-mi-archivo.o
ld -o nombre-final nombre-final.o
#crea el archivo ejecutable hola_mundo
./nombre-final


- Ejecutar programa c
gcc -o nombre_final nombre_del_programa.c
./nombre_final
