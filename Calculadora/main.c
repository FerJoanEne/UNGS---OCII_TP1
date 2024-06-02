#include "functions.h"

int main(){
    
    printMessage(WELCOME);

    int active = 1;
    while (active == 1)
    {
        if(active == 1){
            printSeparator(SEPARATOR);
            printMessage(INPUT_QUESTION);
            leerPregunta();
        }
    }
    
    return 0;

}