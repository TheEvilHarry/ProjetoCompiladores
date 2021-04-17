#include "ilocfunctions.h"
#include <string.h>


int currentLabel;
int currentRegister;

char* generateLabelName(){

    char newLabel[50]="L";
    char index[] = itoa(currentLabel);
     strcat(newLabel,index);
     return newLabel;
}

char* generateRegisterName(){

    char newRegister[50]="R";
    char index[] = itoa(currentRegister);
     strcat(newRegister,index);
     return newRegister;
}