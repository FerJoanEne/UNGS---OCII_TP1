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

void printSeparator(const char* separator){
    printf("\n%s \n", separator);
}

int calcularOperacion(int Operando1, char Operador, int Operando2){
    int resultado = recibir_Operacion(Operando1, Operador, Operando2);
    printResult(RESULT, resultado);
    return resultado;
}

int validateOperator(char Operador){
    if(Operador == '*' || Operador == '/' || Operador == '+' || Operador == '-'){
        return 1;
    }
    return 0;
}

int validateQuestion(const char* question) {
    char *questionCopy = (char *)malloc(sizeof(question));
    strcpy(questionCopy, question);

    int limit = strlen(question);
    if (limit >= LIMIT_CHARACTERS || limit == 0) {
        free(questionCopy);
        printMessage(LIMIT_ERROR);
        exit(-1);
    }
    //primer control para el operando 1
    char *token = strtok(questionCopy, " ");
    if (token == NULL) {
        printMessage(NOT_VALID_VALUE);
        free(questionCopy);
        return 0;
    }
    //segundo control para el operador
    token = strtok(NULL, " ");
    if (token == NULL) {
        free(questionCopy);
        return 0;
    }
    char operador = *token;
    int isValidOperator = validateOperator(operador);
    if(isValidOperator == 0){
        printMessage(NOT_VALID_OPERATOR);
        free(questionCopy);
        return 0;
    }
    //tercer control para el operando 2
    token = strtok(NULL, " ");
    if (token == NULL) {
        printMessage(NOT_VALID_VALUE);
        free(questionCopy);
        return 0;
    }
    char operando2 = *token;
    if(operador == '/' && operando2 == '0'){
        return -1;
    }
    free(questionCopy);
    return 1;
}

void processOperation(const char* question){
    char *questionCopy = (char *)malloc(sizeof(question));
    strcpy(questionCopy, question);
    char *token = strtok(questionCopy, " ");
    int operando1 = atoi(token);
    token = strtok(NULL, " ");
    char operador = *token;
    token = strtok(NULL, " ");
    int operando2 = atoi(token);
    int resultado = calcularOperacion(operando1, operador, operando2);
    free(questionCopy);
}

void leerPregunta() {
    char question [LIMIT_CHARACTERS];
    fgets(question, LIMIT_CHARACTERS, stdin);

    // Eliminar el carácter de nueva línea al final
    question[strcspn(question, "\n")] = '\0';

    if(question[0] == '$'){
        printMessage(END);
        exit(0);
    }
    
    int isValid = validateQuestion(question);
    if(isValid == 0){
        printMessage(ERROR_NOT_VALID_QUESTION);
    }
    if(isValid == -1){
        printMessage(ERROR_DIVIDE_BY_ZERO);
    }
    if(isValid == 1){
        processOperation(question);
    }

}
