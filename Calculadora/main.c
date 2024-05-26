#include <stdlib.h>
#include "functions.h"

int main(){
    
    printSeparator();
    printMessage(WELCOME);

    int active = 1;
    while (active == 1)
    {
        if(active == 1){
            printMessage(INPUT_QUESTION);
            leerPregunta();
        }
    }

    printMessage(END);
    
    return 0;

}