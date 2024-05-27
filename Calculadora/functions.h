#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "const.h"

extern int recibir_Operacion(int Operando1, char Operador, int Operando2);

void printMessage(const char* message){
    printf("%s\n", message);
}

void printResult(const char* message, int result){
    printf("%s %d\n", message, result);
}

void printSeparator(){
    printf("\n%s \n", SEPARATOR);
}

int calcularOperacion(int Operando1, char Operador, int Operando2){
    //aca iria la llamada a ASM
    int resultado = 0;
    switch (Operador) {
        case '*':
            resultado = recibir_Operacion(Operando1,Operador, Operando2);
            //resultado = Operando1 * Operando2;
            break;
        case '/':
            resultado = recibir_Operacion(Operando1,Operador, Operando2);
            //resultado = Operando1 / Operando2;
            break;
        case '-':
            resultado = recibir_Operacion(Operando1,Operador, Operando2);
            //resultado = Operando1 - Operando2;
            break;
        case '+':
            resultado = recibir_Operacion(Operando1,Operador, Operando2);
            //resultado = Operando1 + Operando2;
            break;
        default:
            printMessage(NOT_VALID_OPERATOR);
            return resultado;
    }
    printResult(RESULT, resultado);
    return resultado;
}

int validateQuestion(const char* question) {

    char questionCopy[LIMIT_CHARACTERS];
    strncpy(questionCopy, question, sizeof(questionCopy));
    questionCopy[sizeof(questionCopy) - 1] = '\0';
    
    char *token = strtok(questionCopy, " ");
    if (token == NULL) {
        return 0;
    }
    token = strtok(NULL, " ");
    if (token == NULL) {
        return 0;
    }
    token = strtok(NULL, " ");
    if (token == NULL) {
        return 0;
    }
    return 1;
}

void processOperation(const char* question){
    char questionCopy[LIMIT_CHARACTERS];
    strncpy(questionCopy, question, sizeof(questionCopy));
    questionCopy[sizeof(questionCopy) - 1] = '\0';

    char *token = strtok(questionCopy, " ");
    int operando1 = atoi(token);
    token = strtok(NULL, " ");
    char operador = *token;
    token = strtok(NULL, " ");
    int operando2 = atoi(token);
    
    calcularOperacion(operando1, operador, operando2);
}

void leerPregunta() {
    char question [LIMIT_CHARACTERS];

    fgets(question, LIMIT_CHARACTERS, stdin);
    
    // Eliminar el carácter de nueva línea al final
    question[strcspn(question, "\n")] = '\0';

    int limit = strlen(question);
    if (limit >= LIMIT_CHARACTERS || limit == 0) {
        printMessage(LIMIT_ERROR);
        exit(-1);
    }
    if(question[0] == '$'){
        printMessage(END);
        exit(0);
    }
    
    int isValid = validateQuestion(question);
    if(isValid == 0){
        printMessage(ERROR_NOT_VALID_QUESTION);
    }else{
        processOperation(question);
    }
    printSeparator();

}
