global recibir_Operacion

section .data

section .text

recibir_Operacion:
    push ebp
    mov ebp, esp

    xor eax, 0
    xor ecx, 0
    xor edx, 0
    ; Obtener valores de los registros
    mov eax, [ebp + 8] ; valor primer operando
    mov ecx, [ebp + 12] ; valor operador
    mov edx, [ebp + 16] ; valor segundo operando

    jmp obtenerOperacion

    jmp finalizar

obtenerOperacion:
    cmp ecx, 42 ;multiplicacion
    JE multiplicar

    cmp ecx, 43 ;suma
    JE sumar

    cmp ecx, 45 ; resta
    JE restar

    cmp ecx, 47 ; division
    JE dividir

    jmp finalizar

multiplicar:
    imul eax, edx
    jmp finalizar

sumar:
    add eax, edx
    jmp finalizar

restar:
    sub eax, edx
    jmp finalizar

dividir:
    cmp edx, 0       ; Verificar división por cero
    je error_division
    ;ajuste para la division
    xor eax, eax
    xor edx, edx

    mov ax, [ebp + 8]  ; muevo el dividendo
    mov bx, [ebp + 16] ; muevo el divisor
    idiv bx

    jmp finalizar

error_division:
    mov eax, 0
    jmp finalizar


finalizar:
    mov esp, ebp
    pop ebp
    ret