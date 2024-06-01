global recibir_Operacion

extern malloc

section .data


section .text

recibir_Operacion:
    push ebp
    mov ebp, esp

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

    JE finalizar

multiplicar:
    imul eax, edx
    jmp finalizar

finalizar:
    mov esp, ebp
    pop ebp
    ret

sumar:
    add eax, edx
    jmp finalizar

restar:
    sub eax, edx
    jmp finalizar

dividir:
    cmp edx, 0       ; Verificar división por cero
    je error_division
    cdq              ; Sign-extend EAX into EDX:EAX
    idiv edx         ; Dividir EAX por ED
    jmp finalizar

error_division:
    xor eax, eax
    jmp finalizar