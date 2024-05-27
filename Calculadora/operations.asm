global recibir_Operacion

extern malloc

section .data


section .text

recibir_Operacion:
    push ebp
    mov ebp, esp

    ; Obtener valores de los registros
    mov ebx, [ebp + 8] ; valor primer operando
    mov ecx, [ebp + 12] ; valor operador
    mov edx, [ebp + 16] ; valor segundo operando

    jmp obtenerOperador

    jmp finalizar


obtenerOperador:
    cmp ecx, 42 ;multiplicacion
    JE finalizar

    cmp ecx, 43 ;suma
    JE finalizar

    cmp ecx, 45 ; resta
    JE finalizar

    cmp ecx, 47 ; division
    JE finalizar

    JE finalizar

finalizar:
    mov eax, ecx
    mov esp, ebp
    pop ebp
    ret


