;include 'io.inc'
global crearArbolB_conHijos
global crearArbolB

extern free
extern malloc

section .data

SizeofNodo equ 12

section .text

crearArbolB_conHijos:
    push ebp
    mov ebp, esp
    push SizeofNodo
    call malloc

    ; Obtener valores de los registros
    mov ebx, [ebp + 8] ; Valor del nodo
    mov ecx, [ebp + 12] ; Puntero al nodo izquierdo
    mov edx, [ebp + 16] ; Puntero al nodo derecho

    ; Asignar valores a los campos del nodo
    mov [eax], ebx ; Asignar valor del nodo
    mov [eax + 4], ecx ; Asignar puntero al nodo izquierdo
    mov [eax + 8], edx ; Asignar puntero al nodo derecho

    jmp finalizar


crearArbolB:
    push ebp
    mov ebp, esp
    push SizeofNodo
    call malloc

    mov ebx, [ebp + 8] ; Valor del nodo
    
    mov [eax], ebx
    mov ebx, 0
    mov [eax + 4], ebx ;seteo 0 puntero nodo izquierdo
    mov [eax + 8], ebx ;seteo 0 puntero nodo derecho

    jmp finalizar


finalizar:
    mov esp, ebp
    pop ebp
    ret
