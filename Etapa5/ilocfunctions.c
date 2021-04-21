// TODO:
// Functions signed with the TO DO sign;
// Treatment of new variable Local in Node object


#include "ilocfunctions.h"
#include "symbolTable.h"
#include <string.h>



int currentLabel=1;
int currentRegister=0;

char* generateLabelName(){

    char newLabel[MAXLABELSIZE]="L";
    char index[] = itoa(currentLabel);
     strcat(newLabel,index);
     return newLabel;
}

char* generateRegisterName(int flag){
    char newRegister[MAXREGISTERSIZE]="R";
    char index[] = itoa(currentRegister);
     strcat(newRegister,index);
     return newRegister;
}

Code *createCode(Operation op, char* arg1, char* arg2, char* arg3, char* dest1, char* dest2){

    Code *code = (Code*) malloc(sizeof(Code));
    code->opCode = op;
    code->arg1 =  arg1;
    code->arg2 =  arg2;
    code->arg3 =  arg3;
    code->dest1 = dest1;
    code->dest2 = dest2;
    code->dest3 = dest3;
    code->next = NULL;
    code->prev= NULL;

    code->label = generateLabelName();
    currentLabel++;    }                //CHECK WITH PEDRO IF THIS IS RIGHT?!

    return code;
}

Code *joinCodes(Code* code1, Code* code2){
    if(code1== NULL)
        return code2;
    else if(code2== NULL)
        return code1;


    Code *point - code2;
    while(point->next){
        point = point->next;}

    point->next = code1;
}

Code *generatesAttributionCode(Node *attr, Node* exp){
    int offset, scope;
    offset = offset(attr->data->value.valueString, &scope);
    return createCode(STOREAI,expr->local, NULL, NULL, getsDestForLOADAI(), offset, NULL );

   }

int offset(char *symbol, int *scope){
    //TODO;
    //NOT DONE BECAUSE I DIDNT KNOW HOW TO TEST THE SCOPE AND I'M TOO SLEEPY TO TRY.
    return 0;
}

char* getsDestForLOADAI(){
    //TODO:
    //IF SCOPE IS GLOBAL THEN RETURN RBSS ELSE RFB
    //NOT DONE BECAUSE I DIDNT KNOW HOW TO TEST THE SCOPE AND I'M TOO SLEEPY TO TRY.
    }

Code *generatesInitializationCode(Node *start){
     if(init==NULL){
        return NULL;}
     Code *code = generatesAttributionCode(start->children[0],start->children[1]);
     return joinCodes(start->children[1]->code, generatesInitializationCode(start->next));

 }

 Code *generatesBinaryExp(Operation op, Node * child1, Node* child2, char* dest){
        Code *code = createCode(op, child1->local, child2->local, NULL, dest, NULL);
        return joinCodes(joinCodes(child1->code, child2->code), code);
  }

Operation getOperationFromData(TokenData data){
    //TODO
    }

Code * generatesUnaryOperator(Operation operation, Code *op ){
    Code* code = createCode(operation, NULL, NULL,NULL, NULL, NULL, NULL );
    return joinCodes(code, op);

}



