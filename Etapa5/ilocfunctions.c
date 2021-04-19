#include "ilocfunctions.h"
#include <string.h>


int currentLabel=1;
int currentRegister=0;

char* generateLabelName(){

    char newLabel[MAXLABELSIZE]="L";
    char index[] = itoa(currentLabel);
     strcat(newLabel,index);
     return newLabel;
}

char* generateRegisterName(){

    char newRegister[MAXREGISTERSIZE]="R";
    char index[] = itoa(currentRegister);
     strcat(newRegister,index);
     return newRegister;
}

Code *createCode(Operation op, char* arg1, char* arg2, char* arg3, char* dest1, char* dest2){

    Code *code = (Code*) malloc(sizeof(Code));
    code->label = generateLabelName();
    code->opCode = op;
    code->arg1 =  arg1;
    code->arg2 =  arg2;
    code->arg3 =  arg3;
    code->dest1 = dest1;
    code->dest2 = dest2;
    code->dest3 = dest3;

}